#include "types.h"

typedef struct {
    u16 unk0;
    u16 unk2;
    u16 unk4;
    u16 unk6;
} InputInfo_0; // size = 0x8

typedef struct {
    /* 0x00 */ u8 unk0;
    /* 0x01 */ u8 unk1; // isPadReady ?
    /* 0x02 */ u8 unk2;
    /* 0x03 */ u8 unk3;
    /* 0x04 */ u8 unk4;
    /* 0x05 */ u8 unk5;
    /* 0x06 */ u8 padNumber;
    /* 0x07 */ u8 unk7; // an enum with values 0, 1, 2
    /* 0x08 */ void* unk8;
    /* 0x0C */ u32 unkC;
    /* 0x10 */ u32 unk10;
    /* 0x14 */ u32 unk14;
} InputInfo_1; // size = 0x18

typedef struct {
    /* 0x0 */ u8 unk0;
    /* 0x1 */ u8 unk1;
    /* 0x2 */ u16 unk2;
    /* 0x4 */ u8 unk4;
    /* 0x5 */ u8 unk5;
    /* 0x6 */ char pad6[0x2e];
} InputInfo_2; /* size = 0x34 */

typedef struct {
    /* 0x00 */ u8 unk0;
    /* 0x01 */ u8 unk1;
    /* 0x02 */ u16 unk2;
    /* 0x04 */ u8 rJoyH;
    /* 0x05 */ u8 rJoyV;
    /* 0x06 */ u8 lJoyH;
    /* 0x07 */ u8 lJoyV;
    /* 0x08 */ u8 rightP;
    /* 0x09 */ u8 leftP;
    /* 0x0A */ u8 upP;
    /* 0x0B */ u8 downP;
    /* 0x0C */ u8 triangleP;
    /* 0x0D */ u8 circleP;
    /* 0x0E */ u8 crossP;
    /* 0x0F */ u8 squareP;
    /* 0x10 */ u8 l1P;
    /* 0x11 */ u8 r1P;
    /* 0x12 */ u8 l2P;
    /* 0x13 */ u8 r2P;
    /* 0x14 */ u8 unkn14[12];
} PadButtonState; // size = 0x20
