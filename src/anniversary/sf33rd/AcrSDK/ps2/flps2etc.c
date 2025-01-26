#include "sf33rd/AcrSDK/ps2/flps2etc.h"
#include "common.h"
#include "sf33rd/AcrSDK/common/fbms.h"
#include "sf33rd/AcrSDK/common/memfound.h"
#include "sf33rd/AcrSDK/ps2/flps2d3d.h"
#include "sf33rd/AcrSDK/ps2/flps2debug.h"
#include "sf33rd/AcrSDK/ps2/flps2dma.h"
#include "unknown.h"
#include <cri_mw.h>
#include <sifdev.h>
#include <stdio.h>
#include <string.h>

void flCompact();

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

s32 flFileRead(s8 *filename, void *buf, s32 len) {
    s32 fd;
    s8 temp[2048];
    s8 *p;

    strcpy(temp, "cdrom0:\\THIRD\\");
    p = strlen(temp) + temp;
    strcat(temp, filename);
    strupr(p);
    strcat(temp, ";1");

    ADXM_Lock();
    fd = sceOpen(temp, SCE_RDONLY);
    printf("flFileRead: \"%s\" (fd = %d)\n", &temp, fd);

    if (fd < 0) {
        ADXM_Unlock();
        return 0;
    }

    sceRead(fd, buf, len);
    sceClose(fd);
    ADXM_Unlock();
    return 1;
}

s32 flFileWrite(s8 *filename, void *buf, s32 len) {
    s32 fd;
    s8 temp[2048];
    s8 *p;

    strcpy(temp, "cdrom0:\\THIRD\\");
    p = strlen(temp) + temp;
    strcat(temp, filename);
    strupr(p);
    strcat(temp, ";1");
    ADXM_Lock();

    if ((fd = sceOpen(temp, SCE_WRONLY | SCE_CREAT | SCE_TRUNC)) < 0) {
        ADXM_Unlock();
        return 0;
    }

    sceWrite(fd, buf, len);
    sceClose(fd);
    ADXM_Unlock();
    return 1;
}

s32 flFileAppend(s8 *filename, void *buf, s32 len) {
    s32 fd;
    s8 temp[2048];
    s8 *p;

    strcpy(temp, "cdrom0:\\THIRD\\");
    p = strlen(temp) + temp;
    strcat(temp, filename);
    strupr(p);
    strcat(temp, ";1");
    ADXM_Lock();

    if ((fd = sceOpen(temp, SCE_WRONLY)) < 0) {
        ADXM_Unlock();
        return 0;
    }

    sceLseek(fd, 0, 2);
    sceWrite(fd, buf, len);
    sceClose(fd);
    ADXM_Unlock();
    return 1;
}

s32 flFileLength(s8 *filename) {
    s32 fd;
    s8 temp[2048];
    s8 *p;
    s32 length;

    strcpy(temp, "cdrom0:\\THIRD\\");
    p = strlen(temp) + temp;
    strcat(temp, filename);
    strupr(p);
    strcat(temp, ";1");
    ADXM_Lock();

    if ((fd = sceOpen(temp, SCE_RDONLY)) < 0) {
        ADXM_Unlock();
        return 0;
    }

    length = sceLseek(fd, 0, 2);
    sceClose(fd);
    ADXM_Unlock();
    return length;
}

void flMemset(void *dst, u32 pat, s32 size) {
    s32 i;
    u8 *now = dst;

    for (i = 0; i < size; i++) {
        *now++ = pat;
    }
}

void flMemcpy(void *dst, void *src, s32 size) {
    s32 i;
    s8 *now[2];

    now[0] = dst;
    now[1] = src;

    for (i = 0; i < size; i++) {
        *now[0]++ = *now[1]++;
    }
}

void *flAllocMemory(s32 size) {
    return fmsAllocMemory(&flFMS, size, 0);
}

s32 flGetFrame(FMS_FRAME *frame) {
    return fmsGetFrame(&flFMS, 0, frame);
}

s32 flGetSpace() {
    return fmsCalcSpace(&flFMS);
}

void *flAllocMemoryS(s32 size) {
    return fmsAllocMemory(&flFMS, size, 1);
}

u32 flPS2GetSystemMemoryHandle(s32 len, s32 type) {
    u32 handle = mflRegisterS(len);

    if (handle == 0) {
        flCompact();
        handle = mflRegister(len);

        if (handle == 0) {
            flPS2SystemError(0, "ERROR flPS2GetSystemMemoryHandle flps2etc.c");
            while (1) {}
        }
    }

    flDebugSysMem[handle - 1] = type;
    flDebugSysMemHandleNum += 1;

    switch (type) {
    case 1:
        flDebugSysMemEtc += len;
        break;

    case 2:
        flDebugSysMemTexture += len;
        break;

    case 3:
        flDebugSysMemClay += len;
        break;

    case 4:
        flDebugSysMemMotion += len;
        break;
    }

    return handle;
}

void flPS2ReleaseSystemMemory(u32 handle) {
    s32 type;
    u32 len;

    type = flDebugSysMem[handle - 1];
    flDebugSysMem[handle - 1] = 0;
    flDebugSysMemHandleNum -= 1;
    len = sysmemblock[handle - 1].len;

    switch (type) {
    case 1:
        flDebugSysMemEtc -= len;
        break;

    case 2:
        flDebugSysMemTexture -= len;
        break;

    case 3:
        flDebugSysMemClay -= len;
        break;

    case 4:
        flDebugSysMemMotion -= len;
        break;
    }

    mflRelease(handle);
}

void *flPS2GetSystemBuffAdrs(u32 handle) {
    return mflRetrieve(handle);
}

void flCompact() {
    flPS2DmaTerminate();
    mflCompact();
    flPS2ClayRetouchMaterialTag();
}

void flPS2SystemTmpBuffInit() {
    s32 lp0;

    for (lp0 = 0; lp0 < 2; lp0++) {
        flPs2State.SystemTmpBuffHandle[lp0] = flPS2GetSystemMemoryHandle(0x80000, 1);
    }

    flPS2SystemTmpBuffFlush();
}

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
