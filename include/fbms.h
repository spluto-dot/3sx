#ifndef FBMS_H
#define FBMS_H

#include "unknown.h"

int fmsCalcSpace(FMS_FL *lp);                                               // Range: 0x115D60 -> 0x115D88
int fmsInitialize(FMS_FL *lp, void *memory_ptr, int memsize, int memalign); // Range: 0x115D90 -> 0x115E80
void *fmsAllocMemory(FMS_FL *lp, int bytes, int heapnum);                   // Range: 0x115E80 -> 0x115F58
int fmsGetFrame(FMS_FL *lp, int heapnum, FMS_FRAME *frame);                 // Range: 0x115F60 -> 0x115FA8

#endif
