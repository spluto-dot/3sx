# Notes

## Useful links

- Syscall reference – https://psi-rockin.github.io/ps2tek/#bioseesyscalls

## Binary exploration

### Compiler

According to the `.comment` section of the main binary the compiler used to build the game is `MW MIPS C Compiler (2.4.1.01).PlayStation2`.

```bash
objdump -s -j .comment SLPM_656.21
```

### Functions

#### crt0

`crt0` starts by zeroing out all registers. Then it zeros out all data between 0x004F8510 and 0x00665D80 (see loop at 0x00100158).

Then it fills registers a0-a3 and t0 with various offsets and does `InitMainThread` syscall.
- `gp` (through a0) = 0x004F9B70
- `a0` = 0x00100220 which is a function (an error handler? doesn't get called)
- `a1` = 0xFFFFFFFFFFFFFFFF
- `a2` = 0x00010000 which is an address __before__ the game code (a library, perhaps?)
- `a3` = 0x0065DCC0 which is somewhere inside the writable memory

Then it sets stack pointer (`$sp`) to 0x01FFED60 (return value of `InitMainThread`).

Then it does another syscall – `InitHeap`:
- `a0` = 0x00665D80 (seems to be the start of the heap)
- `a1` = 0xFFFFFFFFFFFFFFFF (heap size)

#### Sound options BGM TEST strings

Looks like `func_001DB440` draws labels for music tracks. There's a loop iterating over bytes of text. 

Whenever it encounters a space (ASCII 32) it just manipulates some numbers and proceeds to the next character. Maybe it increments the position of the next character?

Right before returning it does `sh $a2, 0x396($a0)`. Is that the return value?

For track labels (e.g. `4. Necro & Twelve Stage -SNOWLAND mix1-`) it gets called on every frame, possibly due to the fact that track names have a "breathing" animation.

There's a similar function for other strings on the screen, but it behaves differently.
