#include "common.h"
#include "unknown.h"

static u32 plmemPullHandle(MEM_MGR *memmgr);                // Range: 0x116F60 -> 0x116FFC
static void plmemAppendBlockList(MEM_MGR *memmgr, u32 han); // Range: 0x117000 -> 0x1171F8

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/AcrSDK/common/memmgr", plmemInit);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/AcrSDK/common/memmgr", plmemRegister);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/AcrSDK/common/memmgr", plmemRegisterAlign);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/AcrSDK/common/memmgr", plmemRegisterS);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/AcrSDK/common/memmgr", plmemTemporaryUse);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/AcrSDK/common/memmgr", plmemRetrieve);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/AcrSDK/common/memmgr", plmemRelease);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/AcrSDK/common/memmgr", plmemCompact);

#if 1
u32 plmemGetSpace(MEM_MGR *memmgr) {
    return memmgr->memsize - memmgr->used_size;
}
#else
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/AcrSDK/common/memmgr", plmemGetSpace);
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/AcrSDK/common/memmgr", plmemGetFreeSpace);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/AcrSDK/common/memmgr", plmemPullHandle);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/AcrSDK/common/memmgr", plmemAppendBlockList);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/AcrSDK/common/memmgr", plmemDeleteBlockList);
