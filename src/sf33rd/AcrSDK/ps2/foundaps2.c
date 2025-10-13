#include "sf33rd/AcrSDK/ps2/foundaps2.h"
#include "common.h"
#include "sf33rd/AcrSDK/MiddleWare/PS2/acrmw.h"
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

#include <eekernel.h>
#include <libcdvd.h>
#include <libdma.h>
#include <libgraph.h>
#include <libvu0.h>
#include <sifdev.h>
#include <sifprc.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#if defined(TARGET_PS2)
#include "mw_stdarg.h"
#else
#include <stdarg.h>
#endif

// FIXME: Remove unused variables

// bss
FLPS2State flPs2State;
FLPS2DB flPs2Db[2];
FLPS2DrawStart flPs2DrawStart;
LPVram flVramControl[VRAM_CONTROL_SIZE];
FLTexture flTexture[256];
FLTexture flPalette[1088];
MTX flMATRIX[36];
s32 flDebugSysMem[4096];

// sbss
u32 flCTH;
s32 flCTNum;
s32 flWidth;
s32 flHeight;
s32 flFrame;
f64 flLoadAmount;
f32 flLoadReserve;
u32 flLoadCount;
f64 flLoadNow;
u32 flSystemRenderState;
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
s32 flPTNum;
VRAMBlockHeader flVramStatic[3];
s32 flVramStaticNum;
u32 flMipmapL;
u32 flMipmapK;
u32 flTextureStage[1];
f32 flPS2Ambient[4];
f32 flPS2FadeColor[4];
MTX flPS2INITMATRIX;
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
s32 flClayNum;
u32 flPs2FBA;
f32 flPS2FrameTexScaleX;
f32 flPS2FrameTexScaleY;
s32 flPS2FlipCancelFlag;
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
static void flPS2VramFullClear();
static void flPS2InitRenderBuff(u32 fbdepth, u32 zbdepth, u32 inter_mode, u32 video_mode, u32 dispw);
static void flPS2DrawPreparation();

s32 flInitialize(s32 /* unused */, s32 /* unused */) {
    if (system_work_init() == 0) {
        return 0;
    }

    flPS2SystemTmpBuffInit();
    flPs2State.FrameCount = 0;
    flPs2State.FrameCountNext = 0;
    flPs2State.Irq_count = 0;
    flPS2VramFullClear();
    flPS2InitRenderBuff(4, 2, 1, 0, 1);
    flPADInitialize();

    DPUT_T1_MODE(0x80);
    DPUT_T1_COUNT(0);

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

    plmalloc = flAllocMemory;
    plfree = free;
    flLoadCount = 100;
    flPs2State.NowVu1Code = -1;
    flPs2State.NowVu1Size = 0;
    flSystemRenderState = 0x202;
    flSystemRenderOperation = 0x0138B032;
    flCTNum = 0;
    flPTNum = 0;
    flClayNum = 0;
    flPS2FlipCancelFlag = 0;

    return 1;
}

u32 flPS2CheckDbChangeFlag() {
    return flPs2State.Db_change_enable != 0;
}

s32 flFlip(u32 flag) {
    flPS2DmaWait();
    flmwFlip(flag);
    DPUT_T0_MODE(0x83);
    DPUT_T0_COUNT(0);
    flPs2State.Irq_count = 0;
    flFrame += 1;
    flPS2DmaSend();
    flPS2SystemTmpBuffFlush();
    flPS2DrawPreparation();
    flPs2State.NowVu1Code = -1;
    flPs2State.NowVu1Size = 0;

    return 1;
}

void flPS2VramFullClear() {
#if !defined(TARGET_PS2)
    // We don't need to clear VRAM on non-PS2 systems
    return;
#endif

    u32 handle;
    u8* lpBuff;
    u32 i;
    sceGsLoadImage Loadimage;

    i = 0;
    handle = flPS2GetSystemMemoryHandle(0x40000, 0);
    lpBuff = flPS2GetSystemBuffAdrs(handle);
    flPS2_Clear_Mem16_16A(lpBuff, 0x4000);

    do {
        sceGsSetDefLoadImage(&Loadimage, 0, 16, 0, 0, i * 64, 0x400, 0x40);

        FlushCache(WRITEBACK_DCACHE);
        sceGsExecLoadImage(&Loadimage, (u32*)lpBuff);
        sceGsSyncPath(0, 0);

        i += 1;
    } while (i < 16);

    flPS2ReleaseSystemMemory(handle);
}

void flPS2InitRenderBuff(u32 fbdepth, u32 zbdepth, u32 inter_mode, u32 video_mode, u32 dispw) {
    FLPS2DrawStart* ds;
    u32 size;
    s32 width;
    s32 height;
    s32 disp_height;

    flPs2State.VideoMode = video_mode;
    flPs2State.InterlaceMode = inter_mode;
    flPs2State.FrameBitDepth = fbdepth;
    flPs2State.ScreenAdjustX = 0;
    flPs2State.ScreenAdjustY = 0;

    switch (dispw) {
    default:
    case 0:
        width = 640;
        flPs2State.MAGH = 3;
        break;

    case 1:
        // This is the taken branch
        width = 512;
        flPs2State.MAGH = 4;
        break;

    case 2:
        width = 384;
        flPs2State.MAGH = 6;
        break;
    }

    if (inter_mode == 0) {
        switch (video_mode) {
        default:
        case 0:
            sceGsResetGraph(0, 1, 2, 1);
            height = 224;
            disp_height = 448;
            flPs2State.ScreenDispX = 636;
            flPs2State.ScreenDispY = 50;
            break;

        case 1:
            sceGsResetGraph(0, 1, 3, 1);
            height = 224;
            disp_height = 448;
            flPs2State.ScreenDispX = 656;
            flPs2State.ScreenDispY = 98;
            break;

        case 2:
            sceGsResetGraph(0, 1, 3, 1);
            height = 256;
            disp_height = 512;
            flPs2State.ScreenDispX = 656;
            flPs2State.ScreenDispY = 72;
            break;
        }
    } else {
        switch (video_mode) {
        default:
        case 0:
            // This is the taken branch
            sceGsResetGraph(0, 1, 2, 0);
            height = 448;
            disp_height = 448;
            flPs2State.ScreenDispX = 636;
            flPs2State.ScreenDispY = 50;
            break;

        case 1:
            sceGsResetGraph(0, 1, 3, 0);
            height = 448;
            disp_height = 448;
            flPs2State.ScreenDispX = 656;
            flPs2State.ScreenDispY = 98;
            break;

        case 2:
            sceGsResetGraph(0, 1, 3, 0);
            height = 512;
            disp_height = 512;
            flPs2State.ScreenDispX = 656;
            flPs2State.ScreenDispY = 72;
            break;
        }
    }

    flWidth = width;
    flHeight = height;
    flPs2State.DispWidth = width;
    flPs2State.DispHeight = disp_height;

    switch (flPs2State.FrameBitDepth) {
    case 2:
        flPs2State.FrameBuffForm = 2;
        flPs2State.FrameBuffPageX = 0x40;
        flPs2State.FrameBuffPageY = 0x40;
        break;

    case 3:
        flPs2State.FrameBuffForm = 1;
        flPs2State.FrameBuffPageX = 0x40;
        flPs2State.FrameBuffPageY = 0x20;
        break;

    default:
    case 4:
        // This is the taken branch
        flPs2State.FrameBuffForm = 0;
        flPs2State.FrameBuffPageX = 0x40;
        flPs2State.FrameBuffPageY = 0x20;
        break;
    }

    size = fbdepth *
           (flPs2State.FrameBuffPageY *
            ((((height + flPs2State.FrameBuffPageY) - 1) / flPs2State.FrameBuffPageY) *
             (flPs2State.FrameBuffPageX * (((width + flPs2State.FrameBuffPageX) - 1) / flPs2State.FrameBuffPageX))));

    flPs2State.ZBuffMax = (f32)65535;

    size = zbdepth * (flPs2State.ZBuffPageX * (((width + flPs2State.ZBuffPageX) - 1) / flPs2State.ZBuffPageX) *
                      (flPs2State.ZBuffPageY * (((height + flPs2State.ZBuffPageY) - 1) / flPs2State.ZBuffPageY)));
    flPs2State.ZBuffAdrs = flPS2GetStaticVramArea(size);
    flPs2State.D2dOffsetX = (4096 / 2) - (width >> 1);
    flPs2State.D2dOffsetY = (4096 / 2) - (height >> 1);
    flPs2State.ScreenOffsetX = 0;
    flPs2State.ScreenOffsetY = 0;
}

void flPS2DrawPreparation() {
    FLPS2DrawStart* ds;
    u32* dst;

    ds = &flPs2DrawStart;

    ds->clr_scissor.I64[0] = SCE_GS_SET_SCISSOR(0, flWidth - 1, 0, flHeight - 1);
    ds->clr_rgbaq.I64[0] = SCE_GS_SET_RGBAQ((flPs2State.FrameClearColor >> 16) & 0xFF,
                                            (flPs2State.FrameClearColor >> 8) & 0xFF,
                                            flPs2State.FrameClearColor & 0xFF,
                                            (flPs2State.FrameClearColor >> 24) & 0xFF,
                                            1);
    ds->clr_xyz2_0.I64[0] = SCE_GS_SET_XYZ(flPs2State.D2dOffsetX << 4, flPs2State.D2dOffsetY << 4, 0);
    ds->clr_xyz2_1.I64[0] =
        SCE_GS_SET_XYZ((flPs2State.D2dOffsetX + flWidth) << 4, (flPs2State.D2dOffsetY + flHeight) << 4, 0);
    ds->acr_scissor_1.I64[0] = flPs2State.RenderSCISSORStatus1;
    ds->acr_scissor_2.I64[0] = flPs2State.RenderSCISSORStatus2;
    ds->acr_test_1.I64[0] = flPs2State.RenderTESTStatus1;
    ds->acr_test_2.I64[0] = flPs2State.RenderTESTStatus2;
    ds->acr_zbuf_1.I64[0] = flPs2State.RenderZBUFStatus1;
    ds->acr_zbuf_2.I64[0] = flPs2State.RenderZBUFStatus2;
    ds->acr_fba_1.I64[0] = flPs2FBA;
    ds->acr_fba_2.I64[0] = flPs2FBA;

    dst = (u32*)flPS2GetSystemTmpBuff(sizeof(FLPS2DrawStart), 0x10);
    flPS2_Mem_move16_16A(ds, dst, sizeof(FLPS2DrawStart) / 16);
    flPS2DmaAddQueue2(0, (uintptr_t)dst & 0xFFFFFFF, (uintptr_t)dst, &flPs2VIF1Control);
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

#if !defined(TARGET_PS2)
    fatal_error(str);
#endif

    return 1;
}

void flInitPhaseStarted() {
    flPs2State.SystemStatus = 0;
}

void flInitPhaseFinished() {
    flPs2State.SystemStatus = 2;
}
