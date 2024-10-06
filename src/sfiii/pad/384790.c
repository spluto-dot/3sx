#include "common.h"

#include "libpad2.h"

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
    /* 0x2 */ u8 unk2;
    /* 0x3 */ char pad3[0x31];
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

s32 func_00371C88(u8, u32*);
void func_00384610(s32, s32, s32);

extern PadButtonState g_padButtonStates1[2];
extern PadButtonState g_padButtonStates2[2];

extern InputInfo_1 g_inputInfo1[];
extern InputInfo_2 g_inputInfo2[];

extern char k_004F3FC0[128]; // these are in rodata
extern char k_004F4040[128];

extern char g_0065DBC0[2][128]; // this is in bss

void func_00384790(s32 index) {
    g_padButtonStates2[index] = g_padButtonStates1[index];

    s32 padState = scePad2GetState(g_inputInfo1[index].padNumber);

    switch (padState) {
    case scePad2StateStable:
        g_inputInfo1[index].unk0 = 2;

        if (g_inputInfo1[index].unk1 == 0) {
            scePad2ButtonProfile buttonProfile;

            if (scePad2GetButtonProfile(g_inputInfo1[index].padNumber, &buttonProfile) < 0) {
                return;
            }

            g_inputInfo1[index].unkC =
                buttonProfile.unk0 |
                ((buttonProfile.unk1 << 8) | ((buttonProfile.unk3 << 0x18) | (buttonProfile.unk2 << 0x10)));

            u32 sp48;

            if (func_00371C88(g_inputInfo1[index].padNumber, &sp48) >= 0) {
                g_inputInfo1[index].unk10 = sp48;
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
                g_0065DBC0[index] = k_004F4040;

                break;

            case 1:
                g_inputInfo2[index].unk2 = 1;
                g_inputInfo2[index].unk1 = 0x60;
                g_0065DBC0[index] = k_004F3FC0;

                break;

            case 2:
                g_inputInfo2[index].unk2 = 1;
                g_inputInfo2[index].unk1 = 0x73;
                g_0065DBC0[index] = k_004F3FC0;

                break;
            }

            if (!(g_inputInfo1[index].unk10 & 3)) {
                g_inputInfo1[index].unk5 = 0;
            } else {
                g_inputInfo1[index].unk5 = 1;
            }

            g_inputInfo1[index].unk1 += 1;
            goto block_29;
        }

        scePad2ButtonState padReadResult;

        if (scePad2Read(g_inputInfo1[index].padNumber, &padReadResult) >= 0) {
            g_inputInfo1[index].unk0 = 1;
            g_padButtonStates2[index].unk0 = 0;
            g_padButtonStates2[index].unk1 = 0;
            g_padButtonStates2[index].unk2 = (padReadResult.unk0 << 8) | padReadResult.unk1;

            switch (g_inputInfo1[index].unk7) {
            case 0:
                break;

            case 1:
                g_padButtonStates2[index].rJoyH = padReadResult.rJoyH;
                g_padButtonStates2[index].rJoyV = padReadResult.rJoyV;
                g_padButtonStates2[index].lJoyH = padReadResult.lJoyH;
                g_padButtonStates2[index].lJoyV = padReadResult.lJoyV;

                break;

            case 2:
                g_padButtonStates2[index].rJoyH = padReadResult.rJoyH;
                g_padButtonStates2[index].rJoyV = padReadResult.rJoyV;
                g_padButtonStates2[index].lJoyH = padReadResult.lJoyH;
                g_padButtonStates2[index].lJoyV = padReadResult.lJoyV;
                g_padButtonStates2[index].rightP = padReadResult.rightP;
                g_padButtonStates2[index].leftP = padReadResult.leftP;
                g_padButtonStates2[index].upP = padReadResult.upP;
                g_padButtonStates2[index].downP = padReadResult.downP;
                g_padButtonStates2[index].triangleP = padReadResult.triangleP;
                g_padButtonStates2[index].circleP = padReadResult.circleP;
                g_padButtonStates2[index].crossP = padReadResult.crossP;
                g_padButtonStates2[index].squareP = padReadResult.squareP;
                g_padButtonStates2[index].l1P = padReadResult.l1P;
                g_padButtonStates2[index].r1P = padReadResult.r1P;
                g_padButtonStates2[index].l2P = padReadResult.l2P;
                g_padButtonStates2[index].r2P = padReadResult.r2P;

                break;

            default:
                g_padButtonStates2[index] = g_padButtonStates1[0];

                break;
            }

            if (g_inputInfo1[index].unk14 != 0) {
                u32 *p_unk14 = &g_inputInfo1[index].unk14;
                u32 temp = *p_unk14 - 1;
                *p_unk14 = temp;

                if (temp == 0) {
                    func_00384610(index, 0, 0);
                }
            }

        block_29:
            g_inputInfo2[index].unk0 = g_inputInfo1[index].unk0;
            return;
        }

        return;

    case scePad2StateNoLink:
        g_inputInfo1[index].unk0 = 1;
        g_inputInfo1[index].unk1 = 0;
        g_inputInfo1[index].unk4 = 0;
        g_inputInfo1[index].unk5 = 0;
        g_inputInfo1[index].unkC = 0;
        g_inputInfo1[index].unk10 = 0;

        g_padButtonStates2[index] = g_padButtonStates1[0];

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

        g_padButtonStates2[index] = g_padButtonStates1[0];

        g_inputInfo2[index].unk2 = 0;
        g_inputInfo2[index].unk1 = 0;
        g_inputInfo2[index].unk0 = g_inputInfo1[index].unk0;

        return;
    }
}
