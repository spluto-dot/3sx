#ifndef TEXGROUP_H
#define TEXGROUP_H

#include "types.h"
#include "unknown.h"

void q_ldreq_texture_group(REQ *curr);
void Init_texgrplds_work();
void checkSelObjFileLoaded();
s32 load_any_texture_patnum(u16 patnum, u8 kokey, u8 _unused);

#endif
