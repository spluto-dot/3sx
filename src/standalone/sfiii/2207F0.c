#include "types.h"
#include "cri_mw.h"

void func_0035C548();
void sceGsSyncV(s32);

extern s8 D_004F8C08;
extern s8 D_004F8C09;
extern s8 D_004F8C0A;
extern s8 D_004F8C0B;
extern s16 D_004F8C0C;
extern u16 D_004F8C10;
extern s16 D_004F8C14;

extern char k_resourceArchivePath[];
extern char g_resourcePartitionInfo[];

// const char k_resourceArchivePath[] = "SF33RD.AFS";

// 1535 is the number of files in the AFS archive
// static char g_resourcePartitionInfo[ADXF_CALC_PTINFO_SIZE(1535)];

s32 func_002207F0() {
    D_004F8C14 = 0;
    D_004F8C10 = 0xFFFF;
    D_004F8C0C = 0;

    ADXF_LoadPartitionNw(0, k_resourceArchivePath, 0, &g_resourcePartitionInfo);

    while (1) {
        if (ADXF_GetPtStat(0) == ADXF_STAT_READEND) {
            break;
        }

        sceGsSyncV(0);
        ADXM_ExecMain();
    }

    D_004F8C08 = 0x40;
    D_004F8C09 = 1;
    D_004F8C0A = 0;
    D_004F8C0B = 0;
    return 1;
}
