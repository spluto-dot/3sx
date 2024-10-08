#include "types.h"

void func_00358F00(s32, const char[], s32, s32*);
s32 func_00359358(s32);
void func_0035C548();
void sceGsSyncV(s32);

extern s8 D_004F8C08;
extern s8 D_004F8C09;
extern s8 D_004F8C0A;
extern s8 D_004F8C0B;
extern s16 D_004F8C0C;
extern u16 D_004F8C10;
extern s16 D_004F8C14;

extern const char D_004A0D50[];
extern s32 D_005610D0;

// const char D_004A0D50[] = "SF33RD.AFS";
// s32 D_005610D0 = 0;

s32 func_002207F0() {
    D_004F8C14 = 0;
    D_004F8C10 = 0xFFFF;
    D_004F8C0C = 0;
    
    func_00358F00(0, D_004A0D50, 0, &D_005610D0);

loop:
    if (func_00359358(0) != 3) {
        sceGsSyncV(0);
        func_0035C548();
        goto loop;
    }

    D_004F8C08 = 0x40;
    D_004F8C09 = 1;
    D_004F8C0A = 0;
    D_004F8C0B = 0;
    return 1;
}
