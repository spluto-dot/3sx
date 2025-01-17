#include "common.h"

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
char adxb_obj[3840] = { 0 };

INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/adx_bsc", skg_prim_tbl);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_bsc", SKG_NopFunc);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_bsc", SKG_EntryErrFunc);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_bsc", SKG_CallErrFunc);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_bsc", SKG_Init);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_bsc", SKG_Finish);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_bsc", SKG_GenerateKey);

INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/adx_bsc", D_0055A170);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_bsc", SKG_GetDefKey);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_bsc", SKG_GetNextKey);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_bsc", ADXB_Init);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_bsc", ADXB_Finish);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_bsc", adxb_DefGetWr);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_bsc", adxb_DefAddWr);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_bsc", ADXB_Create);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_bsc", ADXB_Destroy);

INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/adx_bsc", D_0055A178);

INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/adx_bsc", D_0055A198);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_bsc", ADXB_DecodeHeaderAdx);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_bsc", ADXB_DecodeHeader);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_bsc", ADXB_EntryGetWrFunc);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_bsc", ADXB_EntryAddWrFunc);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_bsc", ADXB_GetPcmBuf);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_bsc", ADXB_GetFormat);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_bsc", ADXB_GetSfreq);

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
