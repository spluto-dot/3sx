#ifndef _EEREGS_H_
#define _EEREGS_H_

typedef struct {
    unsigned DIR : 1; /* Direction */
    unsigned p0 : 1;
    unsigned MOD : 2; /* Mode */
    unsigned ASP : 2; /* Address stack pointer */
    unsigned TTE : 1; /* Tag trasfer enable */
    unsigned TIE : 1; /* Tag interrupt enable */
    unsigned STR : 1; /* start */
    unsigned p1 : 7;
    unsigned TAG : 16; /* DMAtag */
} tD_CHCR;

typedef struct {
    unsigned EN1 : 1;   /* */
    unsigned EN2 : 1;   /* */
    unsigned CRTMD : 3; /* CRT mode */
    unsigned MMOD : 1;  /* */
    unsigned AMOD : 1;  /* */
    unsigned SLBG : 1;  /* */
    unsigned ALP : 8;   /* */
    unsigned p0 : 16;   /* */
    unsigned int p1;
} tGS_PMODE;

typedef struct {
    unsigned INT : 1;  /* Interlace mode */
    unsigned FFMD : 1; /* */
    unsigned DPMS : 2; /* VESA DPMS mode */
    unsigned p0 : 28;  /* */
    unsigned int p1;
} tGS_SMODE2;

typedef struct {
    unsigned FBP : 9; /* Base pointer */
    unsigned FBW : 6; /* Buffer width */
    unsigned PSM : 5; /* Pixel store mode */
    unsigned p0 : 12;
    unsigned DBX : 11; /* */
    unsigned DBY : 11; /* */
    unsigned p1 : 10;
} tGS_DISPFB2;

typedef struct {
    unsigned DX : 12;  /* */
    unsigned DY : 11;  /* */
    unsigned MAGH : 4; /* */
    unsigned MAGV : 2; /* */
    unsigned p0 : 3;
    unsigned DW : 12; /* */
    unsigned DH : 11; /* */
    unsigned p1 : 9;
} tGS_DISPLAY2;

typedef struct {
    unsigned R : 8; /* Background color Blue */
    unsigned G : 8; /* Background color Green */
    unsigned B : 8; /* Background color Red */
    unsigned p0 : 8;
    unsigned int p1;
} tGS_BGCOLOR;

#endif
