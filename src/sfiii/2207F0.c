#include "types.h"

s32 ADXF_LoadPartitionNw(s32 ptid, const char *fname, void *dir, void *ptinfo);
s32 ADXF_GetPtStat(s32 ptid);
void func_0035C548();
void sceGsSyncV(s32);

extern s8 D_004F8C08;
extern s8 D_004F8C09;
extern s8 D_004F8C0A;
extern s8 D_004F8C0B;
extern s16 D_004F8C0C;
extern u16 D_004F8C10;
extern s16 D_004F8C14;

extern const char k_resourceArchivePath[];
extern s32 D_005610D0;

// const char k_resourceArchivePath[] = "SF33RD.AFS";
// s32 D_005610D0 = 0;

s32 func_002207F0() {
    D_004F8C14 = 0;
    D_004F8C10 = 0xFFFF;
    D_004F8C0C = 0;

    ADXF_LoadPartitionNw(0, k_resourceArchivePath, 0, &D_005610D0);

    while (1) {
        if (ADXF_GetPtStat(0) == 3) { // 3 is most likely ADXF_STAT_READEND
            break;
        }

        sceGsSyncV(0);
        func_0035C548();
    }

    D_004F8C08 = 0x40;
    D_004F8C09 = 1;
    D_004F8C0A = 0;
    D_004F8C0B = 0;
    return 1;
}
