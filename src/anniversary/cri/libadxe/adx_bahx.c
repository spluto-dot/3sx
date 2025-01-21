#include "common.h"
#include <cri/private/libadxe/adx_bsc.h>

void (*ac3setsjifunc)(s32) = NULL;
s32 ac3termsupplyfunc = 0;
s32 ac3execfunc = 0;

void ADXB_SetAc3InSj(ADXB adxb) {
    s32 unkBC = adxb->unkBC;

    if (unkBC != 0) {
        ac3setsjifunc(unkBC);
    }
}

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_bahx", ADXB_SetAc3DecSmpl);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_bahx", ADXB_Ac3TermSupply);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_bahx", ADXB_ExecOneAc3);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_bahx", ADXB_DecodeHeaderAc3);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_bahx", ADXB_CheckAc3);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_bahx", ADXB_SetAhxInSj);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_bahx", ADXB_SetAhxDecSmpl);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_bahx", ADXB_ExecOneAhx);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_bahx", ADXB_AhxTermSupply);
