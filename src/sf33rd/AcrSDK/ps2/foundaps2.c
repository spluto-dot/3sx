#include "sf33rd/AcrSDK/ps2/foundaps2.h"
#include "common.h"
#include "sf33rd/AcrSDK/MiddleWare/PS2/CapSndEng/cse.h"
#include "sf33rd/AcrSDK/common/fbms.h"
#include "sf33rd/AcrSDK/common/memfound.h"
#include "sf33rd/AcrSDK/common/mlPAD.h"
#include "sf33rd/AcrSDK/common/prilay.h"
#include "sf33rd/AcrSDK/ps2/flps2asm.h"
#include "sf33rd/AcrSDK/ps2/flps2debug.h"
#include "sf33rd/AcrSDK/ps2/flps2dma.h"
#include "sf33rd/AcrSDK/ps2/flps2etc.h"
#include "sf33rd/AcrSDK/ps2/flps2render.h"
#include "sf33rd/AcrSDK/ps2/flps2vram.h"
#include "sf33rd/AcrSDK/ps2/ps2PAD.h"
#include "structs.h"

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// FIXME: Remove unused variables

FLPS2State flPs2State;
LPVram flVramControl[VRAM_CONTROL_SIZE];
FLTexture flTexture[256];
FLTexture flPalette[1088];
s32 flDebugSysMem[4096];
s32 flWidth;
s32 flHeight;
f64 flLoadAmount;
f32 flLoadReserve;
f64 flLoadNow;
u32 flSystemRenderOperation;
FL_FMS flFMS;
f32 flFogStart;
f32 flFogEnd;
u32 flFogColor;
u32 flAmbient;
u32 flFadeColor;
u32 flAlphaRefValue;
u32 flDebugFlag;
FLPS2VIF1Control flPs2VIF1Control;
s32 flPs2GsHandler;
LPVram* flVramList;
s32 flVramNum;
VRAMBlockHeader flVramStatic[3];
s32 flVramStaticNum;
u32 flMipmapL;
u32 flMipmapK;
u32 flTextureStage[1];
f32 flPS2Ambient[4];
f32 flPS2FadeColor[4];
MTX flACRVIEWPORT;
MTX flACRVIEWPROJ;
MTX flPS2VIEWPROJ;
MTX flPS2CLIPPROJ;
MTX flPS2VIEWPORT;
FLMaterial flMATERIAL[1];
FLLight flLIGHT[1];
f32 flPS2ATTENUATION1[1];
f32 flViewportDX;
f32 flViewportDY;
f32 flViewportDW;
f32 flViewportDH;
f32 flViewportCX;
f32 flViewportCY;
f32 flViewportLX;
f32 flViewportLY;
u32 flPs2FBA;
f32 flPS2FrameTexScaleX;
f32 flPS2FrameTexScaleY;
u32 flhDebugStr;
u32 flDebugStrHan;
s32 flDebugStrX;
s32 flDebugStrY;
u32 flDebugStrCol;
u32 flDebugStrCtr;
u32 flDebugTrueTime[DEBUG_TRUE_TIME_SIZE];
u32 flDebugEndRenderTime;
s32 flDebugECNum;
s32 flDebugErrECNum;
s32 flDebugUTNum;
s32 flDebugRTNum;
s32 flDebugMCNum;
s32 flDebugAQNum;
s32 flDebugDINum;
s32 flDebugVERTNum;
s32 flDebugPOLYNum;
s32 flDebugMATERIALNum;
u32 flDebugSysMemHandleNum;
u32 flDebugSysMemEtc;
u32 flDebugSysMemTexture;
u32 flDebugSysMemClay;
u32 flDebugSysMemMotion;
u32 flDebugTrueTimeFree[DEBUG_TRUE_TIME_SIZE];
s32 flLoadCheckCtr;
s32 flLoadCheckTimeOld;
u32 flLoadCheckTime[LOAD_CHECK_TIME_SIZE];
u32 flLoadCheckColor[20];

// forward decls
static s32 system_work_init();
static void flPS2InitRenderBuff(u32 fbdepth, u32 zbdepth, u32 inter_mode, u32 video_mode, u32 dispw);

s32 flInitialize(s32 /* unused */, s32 /* unused */) {
    if (system_work_init() == 0) {
        return 0;
    }

    flPS2SystemTmpBuffInit();
    flPS2InitRenderBuff(4, 2, 1, 0, 1);
    flPADInitialize();

    return 1;
}

s32 system_work_init() {
    void* temp;

    flMemset(&flPs2State, 0, sizeof(FLPS2State));
    flPS2VramInit();
    temp = malloc(0x01800000);

    if (temp == NULL) {
        return 0;
    }

    fmsInitialize(&flFMS, temp, 0x01800000, 0x40);
    flPs2State.system_memory_size = 0xA00000;
    temp = flAllocMemoryS(flPs2State.system_memory_size);
    flPs2State.system_memory_start = (uintptr_t)temp;
    mflInit(temp, flPs2State.system_memory_size, 0x40);

    return 1;
}

s32 flFlip(u32 flag) {
    flPS2SystemTmpBuffFlush();
    cseExecServer(); // FIXME: This shouldn't be called from multiple places
    return 1;
}

void flPS2InitRenderBuff(u32 fbdepth, u32 zbdepth, u32 inter_mode, u32 video_mode, u32 dispw) {
    s32 width;
    s32 height;
    s32 disp_height;

    width = 512;
    height = 448;
    disp_height = 448;
    flWidth = width;
    flHeight = height;
    flPs2State.DispWidth = width;
    flPs2State.DispHeight = disp_height;
    flPs2State.ZBuffMax = (f32)65535;
}

s32 flLogOut(s8* format, ...) {
    s8* va_ptr;
    s8 str[2048];
    s8* lp;
    static s32 bflLogOutFirst = 1;

    va_list args;
    va_start(args, format);

    vsprintf(str, format, args);
    lp = strlen(str) + str;
    *(lp++) = '\r';
    *(lp++) = '\n';
    *lp = '\0';

    if (bflLogOutFirst != 0) {
        flFileWrite("../acrout.txt", "Debug Message Output for PS2\r\n", strlen("Debug Message Output for PS2\r\n"));
        bflLogOutFirst = 0;
    }

    flFileAppend("../acrout.txt", str, strlen(str));
    va_end(args);

    fatal_error(str);
    return 1;
}
