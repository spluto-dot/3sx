#include "common.h"

#include "sdk/libpad2.h"

// There should be another array at 4FA860.
// Most likely 2 structs of size 0x5.

typedef struct {
    /* 0x00 */ u8 unk0;
    /* 0x01 */ u8 unk1; // isPadReady ?
    /* 0x02 */ char pad2[2];
    /* 0x04 */ u8 unk4;
    /* 0x05 */ u8 unk5;
    /* 0x06 */ u8 padNumber;
    /* 0x07 */ u8 unk7; // an enum with values 0, 1, 2
    /* 0x08 */ char pad8[4];
    /* 0x0C */ u32 unkC;
    /* 0x10 */ u32 unk10;
    /* 0x14 */ u32 unk14;
} InputInfo_1; // size = 0x18

typedef struct {
    /* 0x0 */ u8 unk0;
    /* 0x1 */ u8 unk1;
    /* 0x2 */ u16 unk2;
    /* 0x4 */ char pad4[0x30];
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

s32 func_00371C88(u8, u8*);
void func_00384610(s32, s32, s32);

extern PadButtonState g_padButtonState0;
extern PadButtonState g_padButtonStates1[2];
extern PadButtonState g_padButtonStates2[2];

extern InputInfo_1 g_inputInfo1[2];
extern InputInfo_2 g_inputInfo2[2];

extern s32 k_004F3FC0[32]; // these are in rodata
extern s32 k_004F4040[32];

extern s32 g_0065DBC0[2][32]; // this is in bss

typedef struct {
    scePad2ButtonState padReadResult;
    char pad0[0x16];
    u8 sp48;
    char pad1[0x3];
    scePad2ButtonProfile buttonProfile;
} StackData;

void func_00384790(s32 index) {
    StackData stack;
    s32 i;

    g_padButtonStates2[index] = g_padButtonStates1[index];

    switch (scePad2GetState(g_inputInfo1[index].padNumber)) {
    case scePad2StateStable:
        g_inputInfo1[index].unk0 = 2;

        break;

    case scePad2StateNoLink:
        g_inputInfo1[index].unk0 = 1;
        g_inputInfo1[index].unk1 = 0;
        g_inputInfo1[index].unk4 = 0;
        g_inputInfo1[index].unk5 = 0;
        g_inputInfo1[index].unkC = 0;
        g_inputInfo1[index].unk10 = 0;

        g_padButtonStates2[index] = g_padButtonState0;

        g_inputInfo2[index].unk2 = 0;
        g_inputInfo2[index].unk1 = 0;
        g_inputInfo2[index].unk0 = g_inputInfo1[index].unk0;

        return;

    case scePad2StateExecCmd:
    case scePad2StateError:
    default:
        g_inputInfo1[index].unk0 = 2;
        g_inputInfo1[index].unk1 = 0;
        g_inputInfo1[index].unk4 = 0;
        g_inputInfo1[index].unk5 = 0;
        g_inputInfo1[index].unkC = 0;
        g_inputInfo1[index].unk10 = 0;

        g_padButtonStates2[index] = g_padButtonState0;

        g_inputInfo2[index].unk2 = 0;
        g_inputInfo2[index].unk1 = 0;
        g_inputInfo2[index].unk0 = g_inputInfo1[index].unk0;

        return;
    }

    if (g_inputInfo1[index].unk1 == 0) {
        if (scePad2GetButtonProfile(g_inputInfo1[index].padNumber, &stack.buttonProfile) < 0) {
            return;
        }

        g_inputInfo1[index].unkC = stack.buttonProfile.unk0 | ((stack.buttonProfile.unk1 << 8) | ((stack.buttonProfile.unk3 << 0x18) | (stack.buttonProfile.unk2 << 0x10)));

        if (func_00371C88(g_inputInfo1[index].padNumber, &stack.sp48) >= 0) {
            g_inputInfo1[index].unk10 = stack.sp48;
        }

        if (g_inputInfo1[index].unkC & 0xFFFF0000) {
            if (g_inputInfo1[index].unkC & 0xFFF00000) {
                g_inputInfo1[index].unk7 = 2;
            } else {
                g_inputInfo1[index].unk7 = 1;
            }
        } else {
            g_inputInfo1[index].unk7 = 0;
        }

        switch (g_inputInfo1[index].unk7) {
        case 0:
            g_inputInfo2[index].unk2 = 1;
            g_inputInfo2[index].unk1 = 0;
            
            for (i = 0; i < 0x10; i++) {
                g_0065DBC0[index][2 * i] = k_004F4040[2 * i];
                g_0065DBC0[index][2 * i + 1] = k_004F4040[2 * i + 1];
            }

            break;

        case 1:
            g_inputInfo2[index].unk2 = 1;
            g_inputInfo2[index].unk1 = 0x60;

            for (i = 0; i < 0x10; i++) {
                g_0065DBC0[index][2 * i] = k_004F3FC0[2 * i];
                g_0065DBC0[index][2 * i + 1] = k_004F3FC0[2 * i + 1];
            }

            break;

        case 2:
            g_inputInfo2[index].unk2 = 1;
            g_inputInfo2[index].unk1 = 0x73;

            for (i = 0; i < 0x10; i++) {
                g_0065DBC0[index][2 * i] = k_004F3FC0[2 * i];
                g_0065DBC0[index][2 * i + 1] = k_004F3FC0[2 * i + 1];
            }

            break;
        }

        if (!(g_inputInfo1[index].unk10 & 3)) {
            g_inputInfo1[index].unk5 = 0;
        } else {
            g_inputInfo1[index].unk5 = 1;
        }

        g_inputInfo1[index].unk1 += 1;

    } else {

        if (scePad2Read(g_inputInfo1[index].padNumber, &stack.padReadResult) < 0) {
            return;
        }
    
        g_inputInfo1[index].unk0 = 1;
        g_padButtonStates2[index].unk0 = 0;
        g_padButtonStates2[index].unk1 = 0;
        g_padButtonStates2[index].unk2 = (stack.padReadResult.unk0 << 8) | stack.padReadResult.unk1;
    
        switch (g_inputInfo1[index].unk7) {
        case 0:
            break;
    
        case 1:
            g_padButtonStates2[index].rJoyH = stack.padReadResult.rJoyH;
            g_padButtonStates2[index].rJoyV = stack.padReadResult.rJoyV;
            g_padButtonStates2[index].lJoyH = stack.padReadResult.lJoyH;
            g_padButtonStates2[index].lJoyV = stack.padReadResult.lJoyV;
    
            break;
    
        case 2:
            g_padButtonStates2[index].rJoyH = stack.padReadResult.rJoyH;
            g_padButtonStates2[index].rJoyV = stack.padReadResult.rJoyV;
            g_padButtonStates2[index].lJoyH = stack.padReadResult.lJoyH;
            g_padButtonStates2[index].lJoyV = stack.padReadResult.lJoyV;
            g_padButtonStates2[index].rightP = stack.padReadResult.rightP;
            g_padButtonStates2[index].leftP = stack.padReadResult.leftP;
            g_padButtonStates2[index].upP = stack.padReadResult.upP;
            g_padButtonStates2[index].downP = stack.padReadResult.downP;
            g_padButtonStates2[index].triangleP = stack.padReadResult.triangleP;
            g_padButtonStates2[index].circleP = stack.padReadResult.circleP;
            g_padButtonStates2[index].crossP = stack.padReadResult.crossP;
            g_padButtonStates2[index].squareP = stack.padReadResult.squareP;
            g_padButtonStates2[index].l1P = stack.padReadResult.l1P;
            g_padButtonStates2[index].r1P = stack.padReadResult.r1P;
            g_padButtonStates2[index].l2P = stack.padReadResult.l2P;
            g_padButtonStates2[index].r2P = stack.padReadResult.r2P;
    
            break;
    
        default:
            g_padButtonStates2[index] = g_padButtonState0;
    
            break;
        }
    
        if (g_inputInfo1[index].unk14 != 0) {
            if (--g_inputInfo1[index].unk14 == 0) {
                func_00384610(index, 0, 0);
            }
        }
    }

    g_inputInfo2[index].unk0 = g_inputInfo1[index].unk0;
}
