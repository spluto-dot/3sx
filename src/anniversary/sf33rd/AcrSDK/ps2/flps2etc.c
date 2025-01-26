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
u32 flCreateTextureFromApx(s8 *apx_file, u32 flag);
u32 flCreateTextureFromBMP(s8 *bmp_file, u32 flag);
u32 flCreateTextureFromPIC(s8 *pic_file, u32 flag);
u32 flCreateTextureFromTim2(s8 *tim2_file, u32 flag);

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

void flPS2SystemTmpBuffFlush() {
    u32 len;

    switch (flPs2State.SystemStatus) {
    case 0:
    case 2:
    case 1:
        len = 0x80000;
        flPs2State.SystemTmpBuffStartAdrs =
            (u32)flPS2GetSystemBuffAdrs(flPs2State.SystemTmpBuffHandle[flPs2State.SystemIndex]);
        flPs2State.SystemTmpBuffNow = flPs2State.SystemTmpBuffStartAdrs;
        flPs2State.SystemTmpBuffEndAdrs = flPs2State.SystemTmpBuffStartAdrs + len;

        break;

    default:
        break;
    }
}

u32 flPS2GetSystemTmpBuff(s32 len, s32 align) {
    u32 now;
    u32 new_now;

    now = flPs2State.SystemTmpBuffNow;
    now = ~(align - 1) & (now + align - 1);
    new_now = now + len;

    if (flPs2State.SystemTmpBuffEndAdrs < new_now) {
        flPS2DmaWait();
        flPS2SystemError(0, "ERROR flPS2GetSystemTmpBuff flps2etc.c");
        now = flPs2State.SystemTmpBuffStartAdrs;
        new_now = now + len;
    }

    flPs2State.SystemTmpBuffNow = new_now;
    return now;
}

u32 flCreateTextureFromFile(s8 *file, u32 flag) {
    s8 *tmp = file;

    while (*tmp != 0) {
        tmp++;
    }

    do {
        tmp--;
    } while (*tmp != '.');

    tmp++;

    if (((tmp[0] == 'A') || (tmp[0] == 'a')) && ((tmp[1] == 'P') || (tmp[1] == 'p')) &&
        ((tmp[2] == 'X') || (tmp[2] == 'x'))) {
        return flCreateTextureFromApx(file, flag);
    }

    if (((tmp[0] == 'T') || (tmp[0] == 't')) && ((tmp[1] == 'M') || (tmp[1] == 'm')) &&
        ((tmp[2] == '2') || (tmp[2] == '2'))) {
        return flCreateTextureFromTim2(file, flag);
    }

    if (((tmp[0] == 'B') || (tmp[0] == 'b')) && ((tmp[1] == 'M') || (tmp[1] == 'm')) &&
        ((tmp[2] == 'P') || (tmp[2] == 'p'))) {
        return flCreateTextureFromBMP(file, flag);
    }

    if (((tmp[0] == 'P') || (tmp[0] == 'p')) && ((tmp[1] == 'I') || (tmp[1] == 'i')) &&
        ((tmp[2] == 'C') || (tmp[2] == 'c'))) {
        return flCreateTextureFromPIC(file, flag);
    }

    return 0;
}

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/AcrSDK/ps2/flps2etc", flCreateTextureFromApx);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/AcrSDK/ps2/flps2etc", flCreateTextureFromApx_mem);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/AcrSDK/ps2/flps2etc", flCreateTextureFromTim2);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/AcrSDK/ps2/flps2etc", flCreateTextureFromTim2_mem);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/AcrSDK/ps2/flps2etc", flPS2ConvertAlpha);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/AcrSDK/ps2/flps2etc", flCreateTextureFromBMP);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/AcrSDK/ps2/flps2etc", flCreateTextureFromBMP_mem);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/AcrSDK/ps2/flps2etc", flCreateTextureFromPIC);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/AcrSDK/ps2/flps2etc", flCreateTextureFromPIC_mem);
