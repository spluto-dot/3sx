#ifndef FLPS2ETC_H
#define FLPS2ETC_H

#include "types.h"

void flPS2IopModuleLoad(s8 *fname, s32 args, s8 *argp, s32 type);
s32 flFileRead(s8 *filename, void *buf, s32 len);
void flMemset(void *dst, u32 pat, s32 size);

#endif // FLPS2ETC_H
