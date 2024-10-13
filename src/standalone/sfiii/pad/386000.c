#include "common.h"
#include "pad.h"
#include "sdk/libpad2.h"

extern s32 D_004F3FB4;
extern InputInfo_0 D_004F40D0; // used in a struct copy
extern s32 D_004FA7AC;

extern u8 D_004FA7B0[4]; // should be u16 arrays of size 2, but we'll see
extern u8 D_004FA7B4[4];

extern InputInfo_0 g_inputInfo0[2]; // size = 2 x 8
extern void* D_0065D9C0[2][64]; // size = 2 x 256

extern PadButtonState g_padButtonState0;
extern PadButtonState g_padButtonStates1[2];
extern PadButtonState g_padButtonStates2[2];

extern InputInfo_1 g_inputInfo1[2];
extern InputInfo_2 g_inputInfo2[2];

s32 func_00386000(void) {
    s32 temp_s0;
    s32 i; // declaration order can affect register allocation (s0 / s1 in this case)
    s32 temp_s0_2;
    s32 success;
    s32 temp_v0_2;
    s32 temp_v0_3;
    s32 temp_v0_4;
    s32 temp_v0_5;

    scePad2SocketParam socketParam2;
    scePad2SocketParam socketParam3;
    scePad2SocketParam socketParam0;
    scePad2SocketParam socketParam1;

    if (sceDbcInit() != 1) {
        success = 0;
    } else if (scePad2Init(0) != 1) {
        success = 0;
    } else {
        success = 1;
    }

    if (success == 0) {
        return 0;
    }
    
    MemsetZero(g_inputInfo2, sizeof(g_inputInfo2));
    MemsetZero(g_padButtonStates2, sizeof(g_padButtonStates2));
    MemsetZero(g_padButtonStates1, sizeof(g_padButtonStates1));
    MemsetZero(&g_padButtonState0, sizeof(g_padButtonState0));
    
    g_padButtonState0.unk0 = 0xFF;
    g_padButtonState0.unk2 = 0xFFFF;

    for (i = 0; i < 2; i++) {
        g_padButtonStates1[i] = g_padButtonState0;

        g_inputInfo1[i].unk0 = 0;
        g_inputInfo1[i].unk1 = 0;
        g_inputInfo1[i].unk2 = 0;
        g_inputInfo1[i].unk3 = 0;
        g_inputInfo1[i].unk5 = 0;
        g_inputInfo1[i].unk8 = D_0065D9C0[i];
    }

    if (D_004F3FB4 != -1) {
        for (i = 0; i < D_004FA7AC; i++) {
            temp_s0 = D_004F3FB4;
            socketParam0.option = 2;
            socketParam0.port = temp_s0;
            socketParam0.slot = i;
            socketParam0.number = 0;

            // chain assignment
            g_inputInfo1[i].padNumber = temp_v0_2 = (u8)scePad2CreateSocket(&socketParam0, g_inputInfo1[i].unk8);
            
            if (temp_v0_2 >= 0) {
                g_inputInfo1[i].unk0 = 1;
                g_inputInfo1[i].unk1 = 0;
                g_inputInfo1[i].unk2 = temp_s0;
                g_inputInfo1[i].unk3 = i;
            }
        }
        
        if (D_004FA7AC < 2) {
            temp_s0_2 = (D_004F3FB4 + 1) & 1;
            socketParam1.option = 2;
            socketParam1.port = temp_s0_2;
            socketParam1.slot = 0;
            socketParam1.number = 0;

            g_inputInfo1[i].padNumber = temp_v0_3 = (u8)scePad2CreateSocket(&socketParam1, g_inputInfo1[i].unk8);

            if (temp_v0_3 >= 0) {
                g_inputInfo1[i].unk0 = 1;
                g_inputInfo1[i].unk1 = 0;
                g_inputInfo1[i].unk2 = (s8) temp_s0_2;
                g_inputInfo1[i].unk3 = 0;
            }
        }
    } else {
        socketParam2.option = 2;
        socketParam2.port = 0;
        socketParam2.slot = 0;
        socketParam2.number = 0;

        g_inputInfo1[0].padNumber = temp_v0_4 = (u8)scePad2CreateSocket(&socketParam2, g_inputInfo1[0].unk8);
        
        if (temp_v0_4 >= 0) {
            g_inputInfo1[0].unk0 = 1;
            g_inputInfo1[0].unk1 = 0;
            g_inputInfo1[0].unk2 = 0;
            g_inputInfo1[0].unk3 = 0;
        }

        socketParam3.option = 2;
        socketParam3.port = 1;
        socketParam3.slot = 0;
        socketParam3.number = 0;
        
        g_inputInfo1[1].padNumber = temp_v0_5 =(u8)scePad2CreateSocket(&socketParam3, g_inputInfo1[1].unk8);

        if (temp_v0_5 >= 0) {
            g_inputInfo1[1].unk0 = 1;
            g_inputInfo1[1].unk1 = 0;
            g_inputInfo1[1].unk2 = 1;
            g_inputInfo1[1].unk3 = 0;
        }
    }

    for (i = 0; i < 2; i++) {
        g_inputInfo0[i] = D_004F40D0; // struct copy
        g_inputInfo2[i].unk4 = g_inputInfo1[i].unk2;
        g_inputInfo2[i].unk5 = g_inputInfo1[i].unk3;
        // 2 u8 arrays
        D_004FA7B0[i] = 0;
        D_004FA7B4[i] = 0;
    }
    
    return 1;
}
