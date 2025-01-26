#include "sf33rd/AcrSDK/ps2/flps2etc.h"
#include "common.h"
#include <cri_mw.h>
#include <sifdev.h>
#include <stdio.h>
#include <string.h>

void flPS2IopModuleLoad(s8 *fname, s32 args, s8 *argp, s32 type) {
    s32 lp0;

    if (type == 0) {
        do {

        } while (sceSifLoadModule(fname, args, argp) < 0);

        return;
    }

    for (lp0 = 0; lp0 < type; lp0++) {
        if (sceSifLoadModule(fname, args, argp) > 0) {
            return;
        }
    }

    printf("Can't load module %s", fname);
}

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/AcrSDK/ps2/flps2etc", literal_264_0055F498);
INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/AcrSDK/ps2/flps2etc", literal_265_0055F4A8);
INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/AcrSDK/ps2/flps2etc", literal_266_0055F4B0);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/AcrSDK/ps2/flps2etc", flFileRead);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/AcrSDK/ps2/flps2etc", flFileWrite);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/AcrSDK/ps2/flps2etc", flFileAppend);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/AcrSDK/ps2/flps2etc", flFileLength);

void flMemset(void *dst, u32 pat, s32 size) {
    s32 i;
    u8 *now = dst;

    for (i = 0; i < size; i++) {
        *now++ = pat;
    }
}

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/AcrSDK/ps2/flps2etc", flMemcpy);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/AcrSDK/ps2/flps2etc", flAllocMemory);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/AcrSDK/ps2/flps2etc", flGetFrame);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/AcrSDK/ps2/flps2etc", flGetSpace);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/AcrSDK/ps2/flps2etc", flAllocMemoryS);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/AcrSDK/ps2/flps2etc", literal_380_0055F4D0);
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/AcrSDK/ps2/flps2etc", flPS2GetSystemMemoryHandle);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/AcrSDK/ps2/flps2etc", flPS2ReleaseSystemMemory);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/AcrSDK/ps2/flps2etc", flPS2GetSystemBuffAdrs);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/AcrSDK/ps2/flps2etc", flCompact);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/AcrSDK/ps2/flps2etc", flPS2SystemTmpBuffInit);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/AcrSDK/ps2/flps2etc", flPS2SystemTmpBuffFlush);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/AcrSDK/ps2/flps2etc", literal_431_0055F500);
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/AcrSDK/ps2/flps2etc", flPS2GetSystemTmpBuff);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/AcrSDK/ps2/flps2etc", flCreateTextureFromFile);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/AcrSDK/ps2/flps2etc", flCreateTextureFromApx);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/AcrSDK/ps2/flps2etc", flCreateTextureFromApx_mem);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/AcrSDK/ps2/flps2etc", flCreateTextureFromTim2);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/AcrSDK/ps2/flps2etc", flCreateTextureFromTim2_mem);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/AcrSDK/ps2/flps2etc", flPS2ConvertAlpha);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/AcrSDK/ps2/flps2etc", flCreateTextureFromBMP);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/AcrSDK/ps2/flps2etc", flCreateTextureFromBMP_mem);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/AcrSDK/ps2/flps2etc", flCreateTextureFromPIC);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/AcrSDK/ps2/flps2etc", flCreateTextureFromPIC_mem);
