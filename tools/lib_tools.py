from pathlib import Path
import subprocess
import tempfile
import re
from tqdm import tqdm
import argparse
import shutil
from dataclasses import dataclass
from difflib import Differ

BINUTILS = Path('/opt/homebrew/opt/binutils/bin')
OBJDUMP = BINUTILS / 'gobjdump'
AR = BINUTILS / 'ar'
TEMP = Path(tempfile.gettempdir()) / 'sfiii-decomp' / 'lib-tools'
OBJECTS = TEMP / 'objects'

JUMP_INSTRUCTIONS = {
    'beq',
    'bne',
    'bltz',
    'bgez',
    'j',
    'jal'
}


@dataclass
class BinaryFunction:
    label: str
    file_offset: int
    vram_offset: int
    instructions: list[str]

def run_command(args: list[str]) -> str:
    process = subprocess.run(args, capture_output=True, text=True)
    return process.stdout

def create_or_clear(dir: Path):
    if dir.exists():
        shutil.rmtree(dir)

    dir.mkdir(parents=True, exist_ok=True)

def extract_object_files(path: Path):
    for file in tqdm(path.glob('*.a'), 'Extracting object files'):
        filename = file.name
        lib_objects_path = OBJECTS / filename
        lib_objects_path.mkdir(parents=True, exist_ok=True)

        run_command([AR, '-x', f"--output={lib_objects_path}", file])

def generate_function_list(object_file: Path, stop_address: int | None = None) -> list[BinaryFunction]:
    args = [OBJDUMP, '-d', '-z', '--file-offsets']

    if stop_address != None:
        args.append(f"--stop-address={stop_address}")

    args.append(object_file)

    dump = run_command(args)
    func_header_matches = [x for x in re.finditer(r'([0-9a-f]{8}) <(\w*)> \(File Offset: 0x([0-9a-f]+)\):', dump)]
    instruction_matches = [x for x in re.finditer(r'\s*[0-9a-f]+:\s+([0-9a-f]{8})\s+(\w+)', dump)]

    mapping = []
    header_index = 0
    instruction_index = 0

    # This code just groups instructions by functions

    for header_index, header_match in enumerate(func_header_matches):
        next_header = None

        if header_index < len(func_header_matches) - 1:
            next_header = func_header_matches[header_index + 1]

        instructions = []

        while instruction_index < len(instruction_matches) and \
            ((next_header == None) or instruction_matches[instruction_index].span()[0] < next_header.span()[0]):

            match = instruction_matches[instruction_index]
            instruction_hex = match.groups()[0]
            instruction_string = match.groups()[1]

            if instruction_string in JUMP_INSTRUCTIONS:
                instructions.append('????????')
            else:
                instructions.append(instruction_hex)

            instruction_index += 1

        vram_offset = int(header_match.groups()[0], 16)
        label = header_match.groups()[1]
        file_offset = int(header_match.groups()[2], 16)

        mapping.append(
            BinaryFunction(label, file_offset, vram_offset, instructions)
        )

    return mapping

def dump_instructions(object_file: Path, destination: Path):
    function_list = generate_function_list(object_file)

    for function in function_list:
        path = destination / f"{function.vram_offset}_{function.label}.txt"

        with open(path, 'w') as f:
            for instruction in function.instructions:
                f.write(instruction)
                f.write('\n')

def dump_instructions_for_extracted_objects(destination: Path):
    for object_file in tqdm(OBJECTS.rglob('*.o'), 'Dumping instructions'):
        dump_destination = destination / '/'.join(object_file.parts[-2:])
        dump_destination.mkdir(parents=True, exist_ok=True)

        dump_instructions(object_file, dump_destination)

def dump_libs(args):
    create_or_clear(OBJECTS)
    extract_object_files(args.libs)

    create_or_clear(args.destination)
    dump_instructions_for_extracted_objects(args.destination)

def dump_executable(args):
    destination: Path = args.destination
    create_or_clear(destination)

    function = generate_function_list(args.exe, stop_address=args.stop_address)[0]

    start = 0
    end = 0
    i = 0
    file_index = 0

    while i < len(function.instructions):
        instruction = function.instructions[i]

        # 0x03e00008 is the code for 'jr $ra' which is return from function.
        #
        # We increment i by 2 instead of 1 because the next instruction
        # after jr gets executed before returning and is pretty much a part
        # of the return statement.

        if instruction == '03e00008':
            i += 2
            end = i

            file_offset = function.file_offset + start * 4
            vram_offset = function.vram_offset + start * 4
            path = destination / f"{file_index}_{vram_offset:X}_{file_offset:X}.txt"

            with open(path, 'w') as f:
                for instruction in function.instructions[start:end]:
                    f.write(instruction)
                    f.write('\n')

            start = end
            file_index += 1

        else:
            i += 1

            if instruction == '00000000' and (end - start == 0):
                start = i

            end = i

def find_libs(args):
    libs_path: Path = args.libs_dump
    exe_path: Path = args.exe_dump

    exe_files = list(sorted(exe_path.iterdir(), key=exe_func_offset))

    for lib_path in libs_path.iterdir():
        library = lib_path.parts[-1]

        if args.library and args.library != library:
            continue

        print(library)

        for obj_file_path in lib_path.iterdir():
            obj_file = obj_file_path.parts[-1]
            exe_files_start = 0

            if args.object and obj_file != args.object:
                continue

            print(f"\t{obj_file}")

            matches: list[tuple[str, ExeFuncDescription | None]] = list()

            for lib_func_path in sorted(obj_file_path.iterdir(), key=lib_func_offset):
                best_match = None
                best_matching_lines = 0
                best_matching_index = None
                _, lib_func_name = lib_func_name_components(lib_func_path)

                with open(lib_func_path) as f:
                    lib_func_lines = f.read().rstrip().split('\n')

                for i in range(exe_files_start, len(exe_files)):
                    exe_func_path = exe_files[i]

                    with open(exe_func_path) as f:
                        lines = f.read().rstrip().split('\n')

                    if abs(len(lines) - len(lib_func_lines)) > 1:
                        continue

                    match_count = 0

                    for (line_a, line_b) in zip(lib_func_lines, lines):
                        if line_a == line_b:
                            match_count += 1

                    if match_count > best_matching_lines:
                        best_match = exe_func_path
                        best_matching_lines = match_count
                        best_matching_index = i

                if best_match != None and (best_matching_lines / len(lib_func_lines)) >= 0.5:
                    matches.append((lib_func_name, ExeFuncDescription(best_match)))
                    exe_files_start = best_matching_index + 1
                else:
                    matches.append((lib_func_name, None))

            # Print matches

            for lib_func_name, exe_func_desc in matches:
                if exe_func_desc:
                    print(f"\t\t{lib_func_name} -> {exe_func_desc.file_offset} {exe_func_desc.vram_offset:X} ({exe_func_desc.index})")
                else:
                    print(f"\t\t{lib_func_name} -> ❌")

            # Print symbol addresses (for symbol_addrs.txt)

            print()

            for lib_func_name, exe_func_desc in matches:
                if exe_func_desc:
                    print(f"\t\t{lib_func_name} = 0x{exe_func_desc.vram_offset:08X}; // type:func")

def lib_func_name_components(path: Path) -> tuple[int, str]:
    base = path.stem
    sep_index = base.find('_')
    return (int(base[:sep_index]), base[(sep_index + 1):])

def lib_func_offset(path: Path) -> int:
    return lib_func_name_components(path)[0]

def exe_func_offset(path: Path) -> int:
    return ExeFuncDescription(path).index

@dataclass
class ExeFuncDescription:
    index: int
    vram_offset: int
    file_offset: str

    def __init__(self, path: Path):
        components = path.stem.split('_')
        self.index = int(components[0])
        self.vram_offset = int(components[1], 16)
        self.file_offset = components[2]

def main():
    parser = argparse.ArgumentParser(
        'lib-tools',
        description='A suite of tools that help you find library functions in the compiled binary.'
    )

    subparsers = parser.add_subparsers(required=True)

    dump_libs_parser = subparsers.add_parser(
        'dump-libs', 
        help='Dump library functions.'
    )

    dump_libs_parser.add_argument(
        'libs', 
        type=Path, 
        help="Path to the directory containing '.a' libraries."
    )

    dump_libs_parser.add_argument(
        'destination',
        type=Path,
        default=Path(),
        help='Path to the directory where function dumps will be stored.'
    )

    dump_libs_parser.set_defaults(func=dump_libs)

    dump_executable_parser = subparsers.add_parser(
        'dump-exe',
        help='Dump executable file.'
    )

    dump_executable_parser.add_argument(
        'exe', 
        type=Path, 
        help="Path to the executable."
    )

    dump_executable_parser.add_argument(
        'destination',
        type=Path,
        default=Path(),
        help='Path to the directory where function dumps will be stored.'
    )

    dump_executable_parser.add_argument(
        '--stop-address',
        type=str
    )

    dump_executable_parser.set_defaults(func=dump_executable)

    find_libs_parser = subparsers.add_parser(
        'find-libs',
        help='Find instances of library code in a dumped executable and print their configuration segments.'
    )

    find_libs_parser.add_argument(
        'exe_dump',
        type=Path,
        help='Path to the executable dump generated by dump-exe command.'
    )

    find_libs_parser.add_argument(
        'libs_dump',
        type=Path,
        help='Path to the libs dump generated by dump-libs command.'
    )

    find_libs_parser.add_argument(
        '--library',
        type=str,
        help='Set to process only the provided library.'
    )

    find_libs_parser.add_argument(
        '--object',
        type=str,
        help='Set to process only the provided object file.'
    )

    find_libs_parser.set_defaults(func=find_libs)

    args = parser.parse_args()
    args.func(args)

if __name__ == '__main__':
    main()
