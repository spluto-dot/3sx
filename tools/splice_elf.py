#!/usr/bin/env python3

def main():
    bin_path = 'build/SLPM_656.21'

    with open(bin_path, 'rb') as f:
        bin = f.read()

    with open('elf/header', 'rb') as f:
        header = f.read()

    with open('elf/footer', 'rb') as f:
        footer = f.read()

    with open(bin_path, 'wb') as f:
        f.write(header)
        f.write(bin[0x10000:-0xDF])
        f.write(footer)

if __name__ == '__main__':
    main()
