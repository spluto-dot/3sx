from pycparser import c_ast, parse_file
from pathlib import Path
from colorama import init, Fore
import re

class FuncDefVisitor(c_ast.NodeVisitor):
    def __init__(self) -> None:
        self.counter: int = 0
        super().__init__()

    def visit_FuncDef(self, node):
        self.counter += 1

def main():
    init(autoreset=True)

    # Calculate C funcs

    src_path = Path("src/anniversary/sf33rd")
    v = FuncDefVisitor()
    c_file_count = 0

    for src in src_path.rglob("*.c"):
        c_file_count += 1
        ast = parse_file(src, use_cpp=True, cpp_args=r'-Iinclude')
        v.visit(ast)

    # Calculate asm funcs

    asm_path = Path("asm/anniversary/sf33rd")
    asm_file_count = 0
    asm_func_count = 0
    asm_func_regex = re.compile(f"glabel")

    for asm in asm_path.rglob("*.s"):
        asm_file_count += 1
        asm_func_count += len(asm_func_regex.findall(asm.read_text()))

    print(Fore.GREEN + f"{v.counter} functions in {c_file_count} files decompiled")
    print(Fore.YELLOW + f"{asm_func_count} functions in {asm_file_count} files to go")

if __name__ == "__main__":
    main()
