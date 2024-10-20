#include "common.h"
#include "unknown.h"

static u32 plmemPullHandle(MEM_MGR *memmgr);                // Range: 0x116F60 -> 0x116FFC
static void plmemAppendBlockList(MEM_MGR *memmgr, u32 han); // Range: 0x117000 -> 0x1171F8
