# Notes

## Binary exploration

### Compiler

According to the `.comment` section of the main binary the compiler used to build the game is `MW MIPS C Compiler (2.4.1.01).PlayStation2`.

```bash
objdump -s -j .comment SLPM_656.21
```
