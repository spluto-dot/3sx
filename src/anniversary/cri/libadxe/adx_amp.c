#include "common.h"
#include <cri/private/libadxe/adx_amp.h>
#include <cri/private/libadxe/adx_crs.h>
#include <memory.h>

s32 adxsmp_init_cnt = 0;
ADXAMP adxamp_obj[16] = { 0 };

void ADXAMP_Init() {
    if (adxsmp_init_cnt == 0) {
        memset(&adxamp_obj, 0, sizeof(adxamp_obj));
    }

    adxsmp_init_cnt += 1;
}

void ADXAMP_Finish() {
    if (--adxsmp_init_cnt == 0) {
        memset(&adxamp_obj, 0, sizeof(adxamp_obj));
    }
}

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_amp", ADXAMP_Create);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_amp", ADXAMP_Destroy);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_amp", ADXAMP_GetStat);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_amp", ADXAMP_Start);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_amp", ADXAMP_Stop);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_amp", adxamp_extract);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_amp", ADXAMP_ExecHndl);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_amp", ADXAMP_ExecServer);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_amp", ADXAMP_GetExtractNumSmpl);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_amp", ADXAMP_SetSfreq);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_amp", ADXAMP_GetSfreq);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_amp", ADXAMP_SetFrmLen);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_amp", ADXAMP_GetFrmLen);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_amp", ADXAMP_SetFrmPrd);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_amp", ADXAMP_GetFrmPrd);
