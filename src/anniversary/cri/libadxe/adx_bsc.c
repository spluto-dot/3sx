#include "common.h"
#include <cri/private/libadxe/adx_bsc.h>
#include <cri/private/libadxe/adx_xpnd.h>

#define ADXB_MAX_OBJ 0x10

s8 *skg_build = "\nSKG/PS2EE Ver.0.64 Build:Sep 18 2003 09:59:56\n";
s32 skg_init_count = 0;
s32 skg_err_func = 0;
s32 skg_err_obj = 0;
s32 ahxsetextfunc = 0;
s32 pl2encodefunc = 0;
s32 pl2resetfunc = 0;
s16 adxb_def_k0 = 0;
s16 adxb_def_km = 0;
s16 adxb_def_ka = 0;
ADXB_OBJ adxb_obj[ADXB_MAX_OBJ] = { 0 };

void ADXB_Destroy(ADXB);

INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/adx_bsc", skg_prim_tbl);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_bsc", SKG_NopFunc);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_bsc", SKG_EntryErrFunc);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_bsc", SKG_CallErrFunc);

s32 SKG_Init() {
    skg_init_count += 1;
    return 0;
}

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_bsc", SKG_Finish);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_bsc", SKG_GenerateKey);

INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/adx_bsc", D_0055A170);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_bsc", SKG_GetDefKey);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_bsc", SKG_GetNextKey);

void ADXB_Init() {
    ADXPD_Init();
    SKG_Init();
    memset(&adxb_obj, 0, sizeof(adxb_obj));
}

void ADXB_Finish() {
    ADXPD_Finish();
    SKG_Finish();
    memset(&adxb_obj, 0, sizeof(adxb_obj));
}

s32 adxb_DefGetWr(ADXB_UNK_0 *arg0, s32 *arg1, s32 *arg2, s32 *arg3);
INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_bsc", adxb_DefGetWr);

void adxb_DefAddWr(ADXB_UNK_0 *arg0, s32 arg1, s32 arg2);
INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_bsc", adxb_DefAddWr);

ADXB ADXB_Create(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    ADXB adxb;
    ADXB chk_adxb;
    ADXPD adxpd;
    s32 i;

    chk_adxb = &adxb_obj[0];

    for (i = 0; i < ADXB_MAX_OBJ; i++, chk_adxb++) {
        if (chk_adxb->unk0 == 0) {
            break;
        }
    }

    if (i == ADXB_MAX_OBJ) {
        return NULL;
    }

    adxb = &adxb_obj[i];
    memset(adxb, 0, sizeof(ADXB_OBJ));
    adxb->unk0 = 1;
    adxpd = ADXPD_Create();
    adxb->adxpd = adxpd;

    if (adxpd == NULL) {
        ADXB_Destroy(adxb);
        return NULL;
    }

    adxb->unk38 = arg0;
    adxb->unk3C = arg1;
    adxb->unk40 = arg2;
    adxb->unk44 = arg3;
    adxb->unk78 = &adxb_DefGetWr;
    adxb->unk80 = &adxb_DefAddWr;
    adxb->unk7C = adxb;
    adxb->unk84 = adxb;
    adxb->unkC8 = 0;
    adxb->unkDC = 0;
    adxb->unkDE = -0x80;
    adxb->unkE0 = -0x80;
    memset(&adxb->adxb_unk_1, 0, sizeof(ADXB_UNK_1));
    return adxb;
}

void ADXB_Destroy(ADXB adxb) {
    ADXPD adxpd;

    if (adxb != NULL) {
        adxpd = adxb->adxpd;
        adxb->adxpd = 0;
        ADXPD_Destroy(adxpd);
        memset(adxb, 0, sizeof(ADXB_OBJ));
        adxb->unk0 = 0;
    }
}

INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/adx_bsc", D_0055A178);

INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/adx_bsc", D_0055A198);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_bsc", ADXB_DecodeHeaderAdx);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_bsc", ADXB_DecodeHeader);

void ADXB_EntryGetWrFunc(ADXB arg0, s32 arg1, s32 arg2) {
    arg0->unk78 = arg1;
    arg0->unk7C = arg2;
}

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_bsc", ADXB_EntryAddWrFunc);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_bsc", ADXB_GetPcmBuf);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_bsc", ADXB_GetFormat);

s32 ADXB_GetSfreq(ADXB adxb) {
    return adxb->unk14;
}

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_bsc", ADXB_GetNumChan);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_bsc", ADXB_GetFmtBps);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_bsc", ADXB_GetOutBps);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_bsc", ADXB_GetBlkSmpl);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_bsc", ADXB_GetBlkLen);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_bsc", ADXB_GetTotalNumSmpl);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_bsc", ADXB_GetCof);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_bsc", ADXB_GetLpInsNsmpl);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_bsc", ADXB_GetNumLoop);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_bsc", ADXB_GetLpStartPos);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_bsc", ADXB_GetLpStartOfst);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_bsc", ADXB_GetLpEndPos);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_bsc", ADXB_GetLpEndOfst);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_bsc", ADXB_GetAinfLen);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_bsc", ADXB_GetDefOutVol);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_bsc", ADXB_GetDefPan);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_bsc", ADXB_GetDataId);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_bsc", ADXB_TakeSnapshot);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_bsc", ADXB_RestoreSnapshot);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_bsc", ADXB_SetExtString);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_bsc", ADXB_SetDefExtString);

INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/adx_bsc", D_0055A1C0);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_bsc", adxb_get_key);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_bsc", ADXB_GetStat);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_bsc", ADXB_EntryData);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_bsc", ADXB_Start);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_bsc", ADXB_Stop);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_bsc", ADXB_Reset);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_bsc", ADXB_GetDecDtLen);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_bsc", ADXB_GetDecNumSmpl);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_bsc", ADXB_GetAdxpd);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_bsc", ADXB_EvokeExpandMono);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_bsc", ADXB_EvokeExpandSte);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_bsc", ADXB_EvokeExpandPl2);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_bsc", ADXB_EvokeDecode);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_bsc", memcpy2);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_bsc", ADXB_CopyExtraBufSte);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_bsc", ADXB_CopyExtraBufMono);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_bsc", ADXB_EndDecode);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_bsc", ADXB_ExecOneAdx);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_bsc", ADXB_ExecHndl);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_bsc", ADXB_ExecServer);
