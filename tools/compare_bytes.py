#!/usr/bin/env python3

import os

def main():
    version = os.environ["VERSION"]
    target = os.environ["MAIN"]

    path_a = target
    path_b = f"build/{version}/{target}"

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
        print(f"Files diverge at offset 0x{i_a:X}❌")

if __name__ == '__main__':
    main()
