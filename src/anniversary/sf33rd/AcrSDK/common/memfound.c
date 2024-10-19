#include "common.h"
#include "unknown.h"

MEM_MGR sysmemmgr; // size: 0x28, address: 0x578980

void mflInit(void* mem_ptr, int memsize, int memalign) {
    plmemInit(
        &sysmemmgr, 
        sysmemblock,
        0x1000,
        mem_ptr,
        memsize,
        memalign,
        1
    );
}

void mflGetSpace() {
    plmemGetSpace(&sysmemmgr);
}

void mflGetFreeSpace() {
    plmemGetFreeSpace(&sysmemmgr);
}

unsigned int mflRegisterS(int len) {
    return plmemRegisterS(&sysmemmgr, len);
}

unsigned int mflRegister(int len) {
    return plmemRegister(&sysmemmgr, len);
}

void* mflTemporaryUse(int len) {
    return plmemTemporaryUse(&sysmemmgr, len);
}

void* mflRetrieve(unsigned int handle) {
    return plmemRetrieve(&sysmemmgr, handle);
}

int mflRelease(unsigned int handle) {
    return plmemRelease(&sysmemmgr, handle);
}

void* mflCompact() {
    return plmemCompact(&sysmemmgr);
}
