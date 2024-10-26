#ifndef _LIBCDVD_H
#define _LIBCDVD_H

// CdInit Mode
#define SCECdINIT 0 // disk chk
#define SCECdINoD 1 // disk no chk
#define SCECdEXIT 5 // cdvd exit

// Media mode
#define SCECdCD 1
#define SCECdDVD 2

int sceCdInit(int init_mode);
int sceCdMmode(int media);

#endif
