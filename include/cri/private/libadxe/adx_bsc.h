#ifndef ADX_BSC_H
#define ADX_BSC_H

#include <cri/private/libadxe/adx_xpnd.h>
#include "types.h"

typedef struct {
    char pad0[0x18];
    s32 unk18;
    char pad1C[0x20];
    s32 unk3C;
    s32 unk40;
    char pad44[0x44];
    s32 unk88;
    s32 unk8C;
} ADXB_UNK_0;

typedef struct {
    char pad0[0x10];
} ADXB_UNK_1;

typedef struct {
    s16 unk0;
    char pad2[6];
    ADXPD adxpd;
    char padC[8];
    s32 unk14;
    char pad18[0x20];
    s32 unk38;
    s32 unk3C;
    s32 unk40;
    s32 unk44;
    char pad48[0x30];
    s32 unk78;
    s32 unk7C;
    s32 unk80;
    s32 unk84;
    char pad88[0x40];
    s32 unkC8;
    ADXB_UNK_1 adxb_unk_1;
    s16 unkDC;
    s16 unkDE;
    s16 unkE0;
    char padE2[0xE];
} ADXB_OBJ;

typedef ADXB_OBJ *ADXB;

#endif // ADX_BSC_H
