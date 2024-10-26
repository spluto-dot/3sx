#ifndef __eestruct__
#define __eestruct__

typedef struct {
    unsigned long long NLOOP : 15;
    unsigned long long EOP : 1;
    unsigned long long pad16 : 16;
    unsigned long long id : 14;
    unsigned long long PRE : 1;
    unsigned long long PRIM : 11;
    unsigned long long FLG : 2;
    unsigned long long NREG : 4;
    unsigned long long REGS0 : 4;
    unsigned long long REGS1 : 4;
    unsigned long long REGS2 : 4;
    unsigned long long REGS3 : 4;
    unsigned long long REGS4 : 4;
    unsigned long long REGS5 : 4;
    unsigned long long REGS6 : 4;
    unsigned long long REGS7 : 4;
    unsigned long long REGS8 : 4;
    unsigned long long REGS9 : 4;
    unsigned long long REGS10 : 4;
    unsigned long long REGS11 : 4;
    unsigned long long REGS12 : 4;
    unsigned long long REGS13 : 4;
    unsigned long long REGS14 : 4;
    unsigned long long REGS15 : 4;
} sceGifTag;

typedef struct {
    unsigned long long FBP : 9;
    unsigned long long pad09 : 7;
    unsigned long long FBW : 6;
    unsigned long long pad22 : 2;
    unsigned long long PSM : 6;
    unsigned long long pad30 : 2;
    unsigned long long FBMSK : 32;
} sceGsFrame;

typedef struct {
    unsigned long long ZBP : 9;
    unsigned long long pad09 : 15;
    unsigned long long PSM : 4;
    unsigned long long pad28 : 4;
    unsigned long long ZMSK : 1;
    unsigned long long pad33 : 31;
} sceGsZbuf;

typedef struct {
    unsigned long long OFX : 16;
    unsigned long long pad16 : 16;
    unsigned long long OFY : 16;
    unsigned long long pad48 : 16;
} sceGsXyoffset;

typedef struct {
    unsigned long long SCAX0 : 11;
    unsigned long long pad11 : 5;
    unsigned long long SCAX1 : 11;
    unsigned long long pad27 : 5;
    unsigned long long SCAY0 : 11;
    unsigned long long pad43 : 5;
    unsigned long long SCAY1 : 11;
    unsigned long long pad59 : 5;
} sceGsScissor;

typedef struct {
    unsigned long long AC : 1;
    unsigned long long pad01 : 63;
} sceGsPrmodecont;

typedef struct {
    unsigned long long CLAMP : 1;
    unsigned long long pad01 : 63;
} sceGsColclamp;

typedef struct {
    unsigned long long DTHE : 1;
    unsigned long long pad01 : 63;
} sceGsDthe;

typedef struct {
    unsigned long long ATE : 1;
    unsigned long long ATST : 3;
    unsigned long long AREF : 8;
    unsigned long long AFAIL : 2;
    unsigned long long DATE : 1;
    unsigned long long DATM : 1;
    unsigned long long ZTE : 1;
    unsigned long long ZTST : 2;
    unsigned long long pad19 : 45;
} sceGsTest;

typedef struct {
    unsigned long long PRIM : 3;
    unsigned long long IIP : 1;
    unsigned long long TME : 1;
    unsigned long long FGE : 1;
    unsigned long long ABE : 1;
    unsigned long long AA1 : 1;
    unsigned long long FST : 1;
    unsigned long long CTXT : 1;
    unsigned long long FIX : 1;
    unsigned long long pad11 : 53;
} sceGsPrim;

typedef struct {
    unsigned int R : 8;
    unsigned int G : 8;
    unsigned int B : 8;
    unsigned int A : 8;
    float Q;
} sceGsRgbaq;

typedef struct {
    unsigned long long X : 16;
    unsigned long long Y : 16;
    unsigned long long Z : 32;
} sceGsXyz;

#endif
