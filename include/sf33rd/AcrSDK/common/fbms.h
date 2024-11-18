#ifndef FBMS_H
#define FBMS_H

#include "unknown.h"

int fmsCalcSpace(FL_FMS *lp);                                               // Range: 0x115D60 -> 0x115D88
int fmsInitialize(FL_FMS *lp, void *memory_ptr, int memsize, int memalign); // Range: 0x115D90 -> 0x115E80
void *fmsAllocMemory(FL_FMS *lp, int bytes, int heapnum);                   // Range: 0x115E80 -> 0x115F58
int fmsGetFrame(FL_FMS *lp, int heapnum, FMS_FRAME *frame);                 // Range: 0x115F60 -> 0x115FA8

#endif
