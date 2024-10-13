#include "common.h"
#include "pad.h"
#include "sdk/libpad2.h"

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
