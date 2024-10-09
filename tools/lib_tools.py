from pathlib import Path
import subprocess
import tempfile
import re
from tqdm import tqdm
import argparse
import shutil
from dataclasses import dataclass
from pprint import pprint

OBJDUMP = Path('/usr/bin/mipsel-linux-gnu-objdump')
AR = Path('/usr/bin/mipsel-linux-gnu-ar')
TEMP = Path(tempfile.gettempdir()) / 'sfiii-decomp' / 'lib-tools'
OBJECTS = TEMP / 'objects'

JUMP_INSTRUCTIONS = {
    # 'beq',
    # 'bne',
    # 'bltz',
    # 'bgez',
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

@dataclass
class Instruction:
    file_offset: int
    vram_offset: int
    code: int
    label: str
    operands: str | None

    @property
    def signature(self) -> int:
        if self.label in JUMP_INSTRUCTIONS:
            return -1

        if self.operands != None and (r"%hi" in self.operands or r"%lo" in self.operands):
            return -1

        return self.code

@dataclass
class Func:
    label: str
    instructions: list[Instruction]

    @property
    def file_offset(self) -> int:
        return self.instructions[0].file_offset
    
    @property
    def vram_offset(self) -> int:
        return self.instructions[0].vram_offset        
    
@dataclass
class Object:
    name: str
    funcs: list[Func]

def funcs_are_equal(func_a: Func, func_b: Func) -> bool:
    i_a = 0
    i_b = 0
    ins_a = func_a.instructions
    ins_b = func_b.instructions

    while i_a < len(ins_a) and i_b < len(ins_b):
        if ins_a[i_a].signature != -1 \
            and ins_b[i_b].signature != -1 \
            and ins_a[i_a].signature != ins_b[i_b].signature:

            return False

        i_a += 1
        i_b += 1

    a_nops_left = all(x.code == 0 for x in ins_a[i_a:])
    b_nops_left = all(x.code == 0 for x in ins_b[i_b:])

    return a_nops_left and b_nops_left

def revert_bytes(n: int) -> int:
    return (n >> 24) | ((n >> 8) & 0xFF00) | ((n << 8) & 0xFF0000) | ((n << 24) & 0xFF000000)

def longest_consecutive_range(arr: list[int]) -> tuple[int, int]:
    if len(arr) == 0:
        return (0, 0)
    
    best_range = (0, 1)
    best_len = 1
    current_range = [0, 1]
    current_len = 1

    for i in range(1, len(arr)):
        if arr[i] - arr[i - 1] == 1:
            current_len += 1
            current_range[1] = i + 1

            if current_len > best_len:
                best_len = current_len
                best_range = tuple(current_range)

        else:
            current_range = [i, i + 1]
            current_len = 1

    return best_range

def extract_funcs_from_asm(path: Path) -> list[Func]:
    with open(path) as f:
        file_str = f.read()

    func_pattern = r"glabel (\w+)\n((?:.|\n)+?)\.size"
    instruction_pattern = r"/\* (\w+)\s+(\w+)\s+(\w+) \*/\s+((?:\w|\.)+) *(.+)?\n"

    funcs: list[Func] = list()

    for func_match in re.finditer(func_pattern, file_str):
        func_label, body = func_match.groups()
        instructions: list[Instruction] = list()

        for instruction_match in re.finditer(instruction_pattern, body):
            file_offset_str, vram_offset_str, code_str, label, operands = instruction_match.groups()

            instructions.append(
                Instruction(
                    file_offset=int(file_offset_str, 16),
                    vram_offset=int(vram_offset_str, 16),
                    code=int(code_str, 16),
                    label=label,
                    operands=operands
                )
            )

        funcs.append(Func(func_label, instructions))

    return funcs

def extract_funcs_from_archive(path: Path) -> list[Object]:
    args = [
        OBJDUMP, 
        '--disassemble', 
        '--disassemble-zeroes', 
        '--file-offsets', 
        path
    ]

    dump_lines = run_command(args).splitlines()

    object_header_regex = re.compile(r"^(\w+)\.o:\s+file format")
    function_header_regex = re.compile(r"(\w+) <(\w+)> \(File Offset: 0x(\w+)\):")
    instruction_regex = re.compile(r"^\s*(\w+):\s+(\w+)\s+(\w+)\s*(.*)?$")

    objects: list[Object] = list()

    for line in dump_lines:
        obj_header_match = object_header_regex.search(line)
        func_header_match = function_header_regex.search(line)
        instruction_match = instruction_regex.search(line)

        if obj_header_match:
            object_name = obj_header_match.groups()[0]
            objects.append(Object(object_name, list()))

        elif func_header_match:
            label = func_header_match.groups()[1]
            objects[-1].funcs.append(Func(label, list()))

        elif instruction_match:
            offset_str, code_str, label, operands = instruction_match.groups()
            offset = int(offset_str, 16)

            instruction = Instruction(
                file_offset=offset,
                vram_offset=offset,
                code=revert_bytes(int(code_str, 16)),
                label=label,
                operands=operands
            )

            objects[-1].funcs[-1].instructions.append(instruction)

    return objects

def find_lib_syms(
    lib: Path, 
    asm: Path, 
    obj: str | None = None, 
    asm_range: tuple[int | None, int | None] = (None, None)
):
    objects = extract_funcs_from_archive(lib)
    
    if obj:
        objects = [x for x in objects if x.name == obj]

    asm_funcs = extract_funcs_from_asm(asm)
    asm_lower, asm_upper = asm_range

    if asm_lower:
        asm_funcs = [x for x in asm_funcs if x.file_offset >= asm_lower]

    if asm_upper:
        asm_funcs = [x for x in asm_funcs if x.file_offset < asm_upper]

    global_start_offset = 0
    funcs_found = 0

    for object in objects:
        print(f"Looking for {object.name}.o ...\n")

        # Gather matches

        local_start_offset = global_start_offset
        matches: list[tuple[int, int]] = list()

        for obj_func_index, obj_func in enumerate(object.funcs):
            for asm_func_index in range(local_start_offset, len(asm_funcs)):
                asm_func = asm_funcs[asm_func_index]

                if funcs_are_equal(obj_func, asm_func):
                    matches.append((obj_func_index, asm_func_index))
                    local_start_offset = asm_func_index + 1
                    break
        
        # Analyze matches

        if len(matches) == 0:
            print("No matches at all ❌")
        else:
            base_range = longest_consecutive_range([x[1] for x in matches])
            base_len = base_range[1] - base_range[0]

            # This is a heuristic.
            # If there are less than 3 consecutive functions matched
            # then that's probably not the place where this object
            # is in the file.
            required_base_len = min(len(object.funcs), 3)

            if base_len < required_base_len:
                print("Too few matches ⚠️")
            else:
                for i in range(*base_range):
                    obj_func_index, asm_func_index = matches[i]
                    obj_func = object.funcs[obj_func_index]
                    asm_func = asm_funcs[asm_func_index]

                    print(f"{obj_func.label} = 0x{asm_func.vram_offset:08X}; // type:func")

                    global_start_offset = max(global_start_offset, asm_func_index + 1)
                    funcs_found += 1

                missed_before = matches[base_range[0]][0]
                missed_after = len(object.funcs) - matches[base_range[1] - 1][0] - 1

                if missed_before > 0:
                    print()
                    print(f"Missed {missed_before} functions before:")

                    for func in object.funcs[:missed_before]:
                        print(f"\t{func.label}")

                if missed_after > 0:
                    print()
                    print(f"Missed {missed_after} functions after:")
                    
                    for func in object.funcs[-missed_after:]:
                        print(f"\t{func.label}")

        print("\n\n")

    print(f"Found {funcs_found} functions")

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
