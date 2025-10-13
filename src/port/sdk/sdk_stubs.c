#include "common.h"
#include "port/resources.h"
#include "types.h"

#include <eekernel.h>
#include <libcdvd.h>
#include <libdma.h>
#include <libgraph.h>
#include <libmc.h>
#include <libpad2.h>
#include <libvu0.h>
#include <sif.h>
#include <sifrpc.h>

#include <SDL3/SDL.h>

#include <fcntl.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

// sifdev

static int sce_to_unix_flags(int flags) {
    int result = 0;

    switch (flags & 0xF) {
    case SCE_RDONLY:
        result = O_RDONLY;
        break;

    case SCE_WRONLY:
        result = O_WRONLY;
        break;

    case SCE_RDWR:
        result = O_RDWR;
        break;
    }

    if (flags & SCE_APPEND) {
        result |= O_APPEND;
    }

    if (flags & SCE_CREAT) {
        result |= O_CREAT;
    }

    if (flags & SCE_TRUNC) {
        result |= O_TRUNC;
    }

    return result;
}

int sceOpen(const char* filename, int flag, ...) {
    const char expected_path[] = "cdrom0:\\THIRD\\IOP\\FONT8_8.TM2;1";

    if (strcmp(filename, expected_path) != 0) {
        fatal_error("Unexpected path: %s", filename);
    }

    char* font_path = Resources_GetPath("FONT8_8.TM2");
    const int flags = sce_to_unix_flags(flag);
    const int result = open(font_path, flags, 0644);
    SDL_free(font_path);
    return result;
}

int sceClose(int fd) {
    return close(fd);
}

int sceRead(int fd, void* buf, int nbyte) {
    return read(fd, buf, nbyte);
}

int sceWrite(int fd, const void* buf, int nbyte) {
    return write(fd, buf, nbyte);
}

int sceLseek(int fd, int offset, int whence) {
    return lseek(fd, offset, whence);
}

int sceSifLoadModule(const char* filename, int args, const char* argp) {
    not_implemented(__func__);
}

// libdma

void sceDmaSend(sceDmaChan* d, void* tag) {
    // printf("[SDK] sceDmaSend(d: %X, tag: %X)\n", d, tag);
}

int sceDmaSync(sceDmaChan* d, int mode, int timeout) {
    // printf("[SDK] sceDmaSync(d: %X, mode: %d, timeout: %d)\n", d, mode, timeout);
    return 0;
}

// libgraph

int sceGsExecLoadImage(sceGsLoadImage* lp, unsigned int* srcaddr) {
    not_implemented(__func__);
}

void sceGsResetGraph(short mode, short inter, short omode, short ffmode) {
    // printf("[SDK] sceGsResetGraph(mode: %d, inter: %d, omode: %d, ffmode: %d)\n", mode, inter, omode, ffmode);
}

int sceGsSetDefLoadImage(sceGsLoadImage* lp, short dbp, short dbw, short dpsm, short x, short y, short w, short h) {
    not_implemented(__func__);
}

int sceGsSyncPath(int mode, unsigned short timeout) {
    not_implemented(__func__);
}

int sceGsSyncV(int mode) {
    fatal_error("sceGsSyncV should never be called in ports");
}

// libvu0

void sceVu0UnitMatrix(sceVu0FMATRIX m) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            m[i][j] = (i == j);
        }
    }
}

// libdbc

int sceDbcInit() {
    // Do nothing
    return 1;
}

void sceDbcEnd() {
    not_implemented(__func__);
}

// eekernel

void FlushCache(int operation) {
    // printf("[SDK] FlushCache called (operation: %d)\n", operation);
}

void iFlushCache(int operation) {
    // printf("[SDK] iFlushCache called (operation: %d)\n", operation);
}

int EnableIntc(int) {
    not_implemented(__func__);
}

int iEnableIntc(int) {
    not_implemented(__func__);
}

int iDisableIntc(int) {
    not_implemented(__func__);
}

int EnableDmac(int) {
    not_implemented(__func__);
}

int AddIntcHandler(int, int (*)(int), int) {
    not_implemented(__func__);
}

int AddDmacHandler(int, int (*)(int), int) {
    not_implemented(__func__);
}

void ExitHandler() {
    not_implemented(__func__);
}

// libdma

void sceDmaRecvN(sceDmaChan* d, void* addr, int size) {
    not_implemented(__func__);
}
