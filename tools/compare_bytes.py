from pathlib import Path

def compare_bytes(path_a: Path, path_b: Path):
    with open(path_a, 'rb') as f:
        bytes_a = f.read()

    with open(path_b, 'rb') as f:
        bytes_b = f.read()

    i_a = 0x80
    i_b = 0x10000

    while i_a < len(bytes_a) and i_b < len(bytes_b):
        if bytes_a[i_a] != bytes_b[i_b]:
            print(f"files {path_a} and {path_b} diverge at offsets 0x{i_a:X} and 0x{i_b:X}")
            return

        i_a += 1
        i_b += 1

if __name__ == '__main__':
    compare_bytes(Path('SLPM_656.21'), Path('build/SLPM_656.21'))
