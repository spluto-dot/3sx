#ifndef _SIFDEV_H_DEFS
#define _SIFDEV_H_DEFS

int sceSifInitIopHeap();
int sceSifRebootIop(const char *img);
int sceSifSyncIop();

int sceFsReset();

#endif
