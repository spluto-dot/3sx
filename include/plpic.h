#ifndef PLPIC_H
#define PLPIC_H

#include "plcommon.h"
#include "types.h"

s32 plPICSetContextFromImage(plContext *dst, void *lpbas);
u8 *plPICGetPixelAddressFromImage(void *lpbas);

#endif
