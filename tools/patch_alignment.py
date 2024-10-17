from elftools.elf.elffile import ELFFile
from pathlib import Path
import sys

def alignment_offsets(path: Path) -> list[int]:
    with open(path, 'rb') as f:
        elf_file = ELFFile(f)
        elf_header = elf_file.header

        offsets: list[int] = list()

        for section in (".text", ".data", ".rodata"):
            section_index = elf_file.get_section_index(section)

            if section_index is None:
                continue

            header_offset = elf_header["e_shoff"] + section_index * elf_header["e_shentsize"]
            align_offset = header_offset + 8 * 4 # 8 is the index of alignment value
            offsets.append(align_offset)

        return offsets

def main():
    path = Path(sys.argv[1])
    new_value = bytes([4, 0, 0, 0])
    offsets = alignment_offsets(path)

    if not offsets:
        return

    with open(path, "r+b") as f:
        for offset in offsets:
            f.seek(offset)
            f.write(new_value)

if __name__ == "__main__":
    main()
