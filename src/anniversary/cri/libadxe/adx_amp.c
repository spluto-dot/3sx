#include "common.h"
#include <cri/private/libadxe/adx_amp.h>
#include <cri/private/libadxe/adx_crs.h>
#include <cri/sj.h>
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

void ADXAMP_Start(ADXAMP *amp) {
    s32 i = 0;
    SJ sj;
    SJ *sj_ptr;
    SJCK ck;

    s32 var_v0;
    s32 *var_v1;

    if (amp->unk2 > 0) {
        var_v1 = amp->unk14;

        do {
            *var_v1 = 0;
            var_v1 += 1;
            i += 1;
        } while (i < amp->unk2);
    }

    var_v0 = amp->unk2 << 0x18;
    amp->unk2C = 0;
    i = 0;

    if (var_v0 > 0) {
        sj_ptr = amp->unk4;

        do {
            sj = sj_ptr[i];
            SJ_Reset(sj);
            SJ_GetChunk(sj, 0, SJ_GetNumData(sj, 0), &ck);
            memset(ck.data, 0, ck.len);
            SJ_UngetChunk(sj, 0, &ck);
            i += 1;
        } while (i < amp->unk2);
    }

    var_v0 = amp->unk2 << 0x18;
    i = 0;

    if (var_v0 > 0) {
        sj_ptr = amp->unkC;

        do {
            sj = sj_ptr[i];
            SJ_Reset(sj);
            SJ_GetChunk(sj, 0, SJ_GetNumData(sj, 0), &ck);
            memset(ck.data, 0, ck.len);
            SJ_UngetChunk(sj, 0, &ck);
            i += 1;
        } while (i < amp->unk2);
    }

    amp->unk1 = 2;
}

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
