#ifndef _EEREGS_H_
#define _EEREGS_H_

/*
 * Bitfield Structure
 */
typedef struct {
    unsigned DIR : 1; /* Direction */
    unsigned p0 : 1;
    unsigned MOD : 2; /* Mode */
    unsigned ASP : 2; /* Address stack pointer */
    unsigned TTE : 1; /* Tag trasfer enable */
    unsigned TIE : 1; /* Tag interrupt enable */
    unsigned STR : 1; /* start */
    unsigned p1 : 7;
    unsigned TAG : 16; /* DMAtag */
} tD_CHCR;

#endif
