#ifndef _LIBGRAPH_H
#define _LIBGRAPH_H

#include <eeregs.h>
#include <eestruct.h>

typedef struct {
    tGS_PMODE pmode;
    tGS_SMODE2 smode2;
    tGS_DISPFB2 dispfb;
    tGS_DISPLAY2 display;
    tGS_BGCOLOR bgcolor;
} sceGsDispEnv;

typedef struct {
    sceGsFrame frame1;
    unsigned long frame1addr;
    sceGsZbuf zbuf1;
    long zbuf1addr;
    sceGsXyoffset xyoffset1;
    long xyoffset1addr;
    sceGsScissor scissor1;
    long scissor1addr;
    sceGsPrmodecont prmodecont;
    long prmodecontaddr;
    sceGsColclamp colclamp;
    long colclampaddr;
    sceGsDthe dthe;
    long dtheaddr;
    sceGsTest test1;
    long test1addr;
} sceGsDrawEnv1;

typedef struct {
    sceGsFrame frame2;
    unsigned long frame2addr;
    sceGsZbuf zbuf2;
    long zbuf2addr;
    sceGsXyoffset xyoffset2;
    long xyoffset2addr;
    sceGsScissor scissor2;
    long scissor2addr;
    sceGsPrmodecont prmodecont;
    long prmodecontaddr;
    sceGsColclamp colclamp;
    long colclampaddr;
    sceGsDthe dthe;
    long dtheaddr;
    sceGsTest test2;
    long test2addr;
} sceGsDrawEnv2;

typedef struct {
    sceGsTest testa;
    long testaaddr;
    sceGsPrim prim;
    long primaddr;
    sceGsRgbaq rgbaq;
    long rgbaqaddr;
    sceGsXyz xyz2a;
    long xyz2aaddr;
    sceGsXyz xyz2b;
    long xyz2baddr;
    sceGsTest testb;
    long testbaddr;
} sceGsClear;

typedef struct {
    sceGsDispEnv disp[2];
    sceGifTag giftag0;
    sceGsDrawEnv1 draw01;
    sceGsDrawEnv2 draw02;
    sceGsClear clear0;
    sceGifTag giftag1;
    sceGsDrawEnv1 draw11;
    sceGsDrawEnv2 draw12;
    sceGsClear clear1;
} sceGsDBuffDc;

typedef struct {
    sceGifTag giftag0;
    sceGsBitbltbuf bitbltbuf;
    long bitbltbufaddr;
    sceGsTrxpos trxpos;
    long trxposaddr;
    sceGsTrxreg trxreg;
    long trxregaddr;
    sceGsTrxdir trxdir;
    long trxdiraddr;
    sceGifTag giftag1;
} sceGsLoadImage;

int sceGsSyncV(int mode);
int *sceGsSyncVCallback(int (*func)(int));
void sceGsResetPath();
void sceGsResetGraph(short mode, short inter, short omode, short ffmode);
int sceGsSyncPath(int mode, unsigned short timeout);
int sceGsSetDefLoadImage(sceGsLoadImage *lp, short dbp, short dbw, short dpsm, short x, short y, short w, short h);
int sceGsExecLoadImage(sceGsLoadImage *lp, unsigned int *srcaddr); // The address should be u_int128

#endif
