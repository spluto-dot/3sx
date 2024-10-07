import sys

def main():
    addr = int(sys.argv[1], 0)
    power = 1

    while True:
        if addr % 2**power != 0:
            print(f"biggest alignment is {2**(power - 1)} (2**{power - 1})")
            return
        
        power += 1

if __name__ == '__main__':
    main()
