void mflInit(void *mem_ptr, int memsize, int memalign); // Range: 0x115FB0 -> 0x115FFC
unsigned int mflGetSpace();                             // Range: 0x116000 -> 0x116024
unsigned int mflGetFreeSpace();                         // Range: 0x116030 -> 0x116054
unsigned int mflRegisterS(int len);                     // Range: 0x116060 -> 0x11608C
unsigned int mflRegister(int len);                      // Range: 0x116090 -> 0x1160BC
void *mflTemporaryUse(int len);                         // Range: 0x1160C0 -> 0x1160EC
void *mflRetrieve(unsigned int handle);                 // Range: 0x1160F0 -> 0x11611C
int mflRelease(unsigned int handle);                    // Range: 0x116120 -> 0x11614C
void *mflCompact();                                     // Range: 0x116150 -> 0x116174
