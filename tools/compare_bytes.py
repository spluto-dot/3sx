#!/usr/bin/env python3

import sys
from pathlib import Path

EXPECTED_ERRORS = {
    0x2A5174: 0x1000FFF9,
    0x302580: 0x14C0FFFA,
    0x3025B8: 0x14C0FFF4,
    0x3025E0: 0x14C0FFF8,
    0x302600: 0x14C0FFFA,
    0x302658: 0x14C0FFEC,
    0x302690: 0x14C0FFF4,
    0x3026B8: 0x14C0FFF8,
    0x3026F0: 0x14C0FFF4,
    0x302708: 0x14A0FFFC,
    0x302720: 0x14A0FFFC,
    0x302738: 0x14A0FFFC,
    0x302750: 0x14A0FFFC,
}

def read_word(b: bytes, offset: int) -> int:
    word = 0

    for i in range(4):
        word |= b[offset + i] << i * 8

    return word

def align_down(n: int, alignment: int) -> int:
    return n // alignment * alignment

def main():
    path_a = Path(sys.argv[1])
    path_b = Path(sys.argv[2])
    start = 0
    end = sys.maxsize

    if len(sys.argv) >= 4:
        start = align_down(int(sys.argv[3], 16), 4)

    if len(sys.argv) >= 5:
        end = align_down(int(sys.argv[4], 16), 4)

    if start != 0 or end != sys.maxsize:
        print(f"Comparing range [0x{start:X}, 0x{end:X})")

    with open(path_a, 'rb') as f:
        bytes_a = f.read()

    with open(path_b, 'rb') as f:
        bytes_b = f.read()

    # Compare bytes

    bad_offsets: list[int] = list()
    unexpected_error = False
    misalign_offset: int | None = None

    range_end = min(
        len(bytes_a), 
        len(bytes_b),
        end
    )

    for offset in range(start, range_end, 4):
        word_a = read_word(bytes_a, offset)
        word_b = read_word(bytes_b, offset)

        if word_a != word_b:
            bad_offsets.append(offset)

            if offset not in EXPECTED_ERRORS or EXPECTED_ERRORS[offset] != word_b:
                unexpected_error = True

            if (word_a == 0 or word_b == 0) and misalign_offset == None:
                misalign_offset = offset

    if not bad_offsets:
        print("Files match ✅")
    elif not unexpected_error:
        print("Files match ✅ (except for expected errors)")
    else:
        max_printed_offsets = 20
        print(f"Files diverge at {len(bad_offsets)} offsets ❌.")

        if len(bad_offsets) > max_printed_offsets:
            print(f"First {max_printed_offsets} diverging offsets:")
        else:
            print("Diverging offsets:")

        for offset in bad_offsets[:max_printed_offsets]:
            print(f"    0x{offset:X}")
        
    if misalign_offset != None:
        print(f"Misalignment at 0x{misalign_offset:X}")

if __name__ == '__main__':
    main()
