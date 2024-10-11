#!/usr/bin/env python3

from pathlib import Path

def main():
    path_a = Path('SLPM_656.21')
    path_b = Path('build/SLPM_656.21')

    with open(path_a, 'rb') as f:
        bytes_a = f.read()

    with open(path_b, 'rb') as f:
        bytes_b = f.read()

    i_a = 0
    i_b = 0

    while i_a < len(bytes_a) and i_b < len(bytes_b):
        if bytes_a[i_a] != bytes_b[i_b]:
            break

        i_a += 1
        i_b += 1

    if i_a == len(bytes_a) and i_b == len(bytes_b):
        print("Files match ✅")
    else:
        print(f"Files diverge at offsets 0x{i_a:X} and 0x{i_b:X} ❌")

if __name__ == '__main__':
    main()
