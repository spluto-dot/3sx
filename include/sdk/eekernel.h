#ifndef _eekernel_h_
#define _eekernel_h_

#define ExitHandler() asm("sync.l; ei")

/*
 * COP0
 */

void FlushCache(int);
void iFlushCache(int);
void SyncDCache(void *, void *);
void iSyncDCache(void *, void *);
void InvalidDCache(void *, void *);
void iInvalidDCache(void *, void *);
unsigned int GetCop0(int);
unsigned int iGetCop0(int);

#endif
