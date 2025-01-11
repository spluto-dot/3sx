#ifndef _SIFDEV_H_DEFS
#define _SIFDEV_H_DEFS

int sceSifInitIopHeap();
int sceSifRebootIop(const char *img);
int sceSifSyncIop();

int sceSifLoadModule(const char *filename, int args, const char *argp);

int sceFsReset();

#endif
