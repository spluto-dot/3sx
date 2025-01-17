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

void ADXAMP_Destroy(ADXAMP *amp) {
    if (amp != NULL) {
        ADXCRS_Lock();
        memset(amp, 0, sizeof(ADXAMP));
        ADXCRS_Unlock();
    }
}

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_amp", ADXAMP_GetStat);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_amp", ADXAMP_Start);

void ADXAMP_Stop(ADXAMP *amp) {
    amp->unk1 = 0;
}

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
