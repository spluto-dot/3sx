#include "unknown.h"
#include "common.h"

int fmsCalcSpace(FMS_FL* lp) {
    return lp->frame[1] - lp->frame[0];
}

int fmsInitialize(FMS_FL* lp, void* memory_ptr, int memsize, int memalign) {
    memsize = ~(memalign - 1) & (memsize + memalign - 1);
    lp->memoryblock = (unsigned char*) memory_ptr;
    lp->align = memalign;
    lp->baseandcap[0] = (unsigned char*) ((unsigned int)lp->memoryblock + lp->align - 1 & ~(lp->align - 1));
    lp->baseandcap[1] = (unsigned char*) (((unsigned int)lp->memoryblock + memsize + lp->align - 1) & ~(lp->align - 1));
    lp->frame[0] = lp->baseandcap[0];
    lp->frame[1] = lp->baseandcap[1];
    return 1;
}

void* fmsAllocMemory(FMS_FL* lp, int bytes, int heapnum) {
    void* pMem;
    bytes = ~(lp->align - 1) & ((unsigned int)bytes + lp->align - 1);

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

int fmsGetFrame(FMS_FL* lp, int heapnum, FMS_FRAME* frame) {
    frame->pFrame = lp->frame[heapnum];
    frame->heapnum = heapnum;
    return 1;
}
