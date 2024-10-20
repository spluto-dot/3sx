#include "unknown.h"
#include "common.h"

s32 fmsCalcSpace(FMS_FL* lp) {
    return lp->frame[1] - lp->frame[0];
}

s32 fmsInitialize(FMS_FL* lp, void* memory_ptr, s32 memsize, s32 memalign) {
    memsize = ~(memalign - 1) & (memsize + memalign - 1);
    lp->memoryblock = (u8*) memory_ptr;
    lp->align = memalign;
    lp->baseandcap[0] = (u8*) ((u32)lp->memoryblock + lp->align - 1 & ~(lp->align - 1));
    lp->baseandcap[1] = (u8*) (((u32)lp->memoryblock + memsize + lp->align - 1) & ~(lp->align - 1));
    lp->frame[0] = lp->baseandcap[0];
    lp->frame[1] = lp->baseandcap[1];
    return 1;
}

void* fmsAllocMemory(FMS_FL* lp, s32 bytes, s32 heapnum) {
    void* pMem;
    bytes = ~(lp->align - 1) & ((u32)bytes + lp->align - 1);

    if (lp->frame[0] + bytes > lp->frame[1]) {
        return NULL;
    }
    
    if (heapnum != 0) {
        lp->frame[1] -= bytes;
        pMem = lp->frame[1];
    } else {
        pMem = lp->frame[0];
        lp->frame[0] += bytes;
    }

    return pMem;
}

s32 fmsGetFrame(FMS_FL* lp, s32 heapnum, FMS_FRAME* frame) {
    frame->pFrame = lp->frame[heapnum];
    frame->heapnum = heapnum;
    return 1;
}
