#ifndef COMMON_H
#define COMMON_H

#include "types.h"

#define NULL 0

// Compilation with GNU C Compilier means we are compiling CRI
#ifdef __GNUC__
#define INCLUDE_ASM(FOLDER, NAME)                                                                                      \
    __asm__(".pushsection .text\n"                                                                                     \
            "\t.align\t3\n"                                                                                            \
            "\t.globl\t" #NAME "\n"                                                                                    \
            "\t.ent\t" #NAME "\n" #NAME ":\n"                                                                          \
            ".include \"" FOLDER "/" #NAME ".s\"\n"                                                                    \
            "\t.set reorder\n"                                                                                         \
            "\t.set at\n"                                                                                              \
            "\t.end\t" #NAME "\n"                                                                                      \
            ".popsection")

__asm__(".include \"include/cri_macro.inc\"\n");
#else
#define INCLUDE_ASM(FOLDER, NAME)
#define INCLUDE_RODATA(FOLDER, NAME)
#endif

#endif
