#ifndef FOUNDAPS2_H
#define FOUNDAPS2_H

#include "types.h"

s32 flInitialize();
u32 flPS2CheckDbChangeFlag();
s32 flFlip(u32 flag);
s32 flLogOut(s8 *format, ...);
void flInitPhaseStarted();
void flInitPhaseFinished();

#endif
