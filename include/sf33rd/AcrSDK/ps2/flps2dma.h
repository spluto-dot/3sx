#ifndef FLPS2DMA_H
#define FLPS2DMA_H

#include "types.h"

u32 flPS2DmaAddEndTag(u32 tag, s32 qwc, s32 irq, s32 /* unused */);
void flPS2DmaInitControl(FLPS2VIF1Control *dma_ptr, u32 queue_size, void *handler);
s32 flPS2DmaAddQueue2(s32 type, u32 data_adrs, u32 endtag_adrs, FLPS2VIF1Control *dma_ptr);
s32 flPS2DmaInterrupt(s32 ch);
void flPS2DmaSend();
s32 flPS2DmaWait();
s32 flPS2DmaTerminate();

#endif
