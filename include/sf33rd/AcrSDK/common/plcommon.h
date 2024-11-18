#ifndef PLCOMMON_H
#define PLCOMMON_H

#include "types.h"

typedef struct {
    // total size: 0x48
    u32 desc;     // offset 0x0, size 0x4
    s32 width;    // offset 0x4, size 0x4
    s32 height;   // offset 0x8, size 0x4
    s32 pitch;    // offset 0xC, size 0x4
    void *ptr;    // offset 0x10, size 0x4
    s32 bitdepth; // offset 0x14, size 0x4
    struct /* @anon3 */ {
        // total size: 0x30
        s32 rl;    // offset 0x0, size 0x4
        s32 rs;    // offset 0x4, size 0x4
        s32 rm;    // offset 0x8, size 0x4
        s32 gl;    // offset 0xC, size 0x4
        s32 gs;    // offset 0x10, size 0x4
        s32 gm;    // offset 0x14, size 0x4
        s32 bl;    // offset 0x18, size 0x4
        s32 bs;    // offset 0x1C, size 0x4
        s32 bm;    // offset 0x20, size 0x4
        s32 al;    // offset 0x24, size 0x4
        s32 as;    // offset 0x28, size 0x4
        s32 am;    // offset 0x2C, size 0x4
    } pixelformat; // offset 0x18, size 0x30
} plContext;

#endif
