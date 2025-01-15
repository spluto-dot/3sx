#include "common.h"
#include <cri/private/libadxe/adx_amp.h>
#include <cri/private/libadxe/adx_crs.h>
#include <memory.h>

typedef struct {
    char pad[0x300];
} ADXAMP;

ADXAMP adxamp_obj;
s32 adxsmp_init_cnt = 0;

void ADXAMP_Init() {
    if (adxsmp_init_cnt == 0) {
        memset(&adxamp_obj, 0, sizeof(ADXAMP));
    }

    adxsmp_init_cnt += 1;
}

void ADXAMP_Finish() {
    if (--adxsmp_init_cnt == 0) {
        memset(&adxamp_obj, 0, sizeof(ADXAMP));
    }
}
