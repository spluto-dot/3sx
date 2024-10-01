from pathlib import Path
import subprocess
import tempfile
import re
from tqdm import tqdm
import argparse
import shutil
from dataclasses import dataclass

BINUTILS = Path('/opt/homebrew/opt/binutils/bin')
OBJDUMP = BINUTILS / 'gobjdump'
AR = BINUTILS / 'ar'
TEMP = Path(tempfile.gettempdir()) / 'sfiii-decomp' / 'lib-tools'
OBJECTS = TEMP / 'objects'


@dataclass
class BinaryFunction:
    label: str
    file_offset: int
    vram_offset: int
    instructions: list[str]

def run_command(args: list[str]) -> str:
    process = subprocess.run(args, capture_output=True, text=True)
    return process.stdout

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
    instruction_matches = [x for x in re.finditer(r'\s*[0-9a-f]+:\s+([0-9a-f]{8})', dump)]

    mapping = []
    header_index = 0
    instruction_index = 0

    for header_index, header_match in enumerate(func_header_matches):
        next_header = None

        if header_index < len(func_header_matches) - 1:
            next_header = func_header_matches[header_index + 1]

        instructions = []

        while instruction_index < len(instruction_matches) and \
            ((next_header == None) or instruction_matches[instruction_index].span()[0] < next_header.span()[0]):
            instructions.append(instruction_matches[instruction_index].groups()[0])
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
    if OBJECTS.exists():
        shutil.rmtree(OBJECTS)

    OBJECTS.mkdir(parents=True, exist_ok=True)

    extract_object_files(args.libs)
    dump_instructions_for_extracted_objects(args.destination)

def dump_executable(args):
    destination: Path = args.destination
    destination.mkdir(parents=True, exist_ok=True)

    function = generate_function_list(args.exe, stop_address=args.stop_address)[0]

    start = 0
    end = 0
    i = 0
    file_index = 0

    while i < len(function.instructions):
        instruction = function.instructions[i]

        if instruction == '03e00008':
            i += 2
            end = i

            offset = function.file_offset + start * 4
            path = destination / f"{file_index}_{offset:X}.txt"

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

    args = parser.parse_args()
    args.func(args)

if __name__ == '__main__':
    main()
