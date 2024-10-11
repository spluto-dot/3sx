#ifndef _LIBPAD2_H_
#define _LIBPAD2_H_

#include "types.h"

#define SCE_PAD2_DMA_BUFFER_SIZE (256)
#define SCE_PAD2_BUTTON_PROFILE_SIZE (4)
#define SCE_PAD2_BUTTON_DATA_SIZE (18)
#define SCE_PAD2_STATESTR_SIZE (16)

#define SCE_PAD2_DMA_BUFFER_MAX (16)
#define SCE_PAD2_MAX_DEVICE_NAME (16)

#define SCE_PAD2_PORT_1C (0)
#define SCE_PAD2_PORT_2C (1)
#define SCE_PAD2_PORT_USB (99)

#define SCE_PAD2_SPECIFIC_PORT (1 << 1)
#define SCE_PAD2_SPECIFIC_DRIVER_NUMBER (1 << 2)
#define SCE_PAD2_SPECIFIC_DEVICE_NAME (1 << 3)

#define scePad2StateNoLink (0)
#define scePad2StateStable (1)
#define scePad2StateExecCmd (2)
#define scePad2StateError (3)

#define SCE_PAD2_SELECT (0)
#define SCE_PAD2_L3 (1)
#define SCE_PAD2_R3 (2)
#define SCE_PAD2_START (3)
#define SCE_PAD2_UP (4)
#define SCE_PAD2_RIGHT (5)
#define SCE_PAD2_DOWN (6)
#define SCE_PAD2_LEFT (7)

#define SCE_PAD2_L2 (8)
#define SCE_PAD2_R2 (9)
#define SCE_PAD2_L1 (10)
#define SCE_PAD2_R1 (11)
#define SCE_PAD2_TRIANGLE (12)
#define SCE_PAD2_CIRCLE (13)
#define SCE_PAD2_CROSS (14)
#define SCE_PAD2_SQUARE (15)

#define SCE_PAD2_STICK_RX (16)
#define SCE_PAD2_STICK_RY (17)
#define SCE_PAD2_STICK_LX (18)
#define SCE_PAD2_STICK_LY (19)
#define SCE_PAD2_ANALOG_RIGHT (20)
#define SCE_PAD2_ANALOG_LEFT (21)
#define SCE_PAD2_ANALOG_UP (22)
#define SCE_PAD2_ANALOG_DOWN (23)

#define SCE_PAD2_ANALOG_TRIANGLE (24)
#define SCE_PAD2_ANALOG_CIRCLE (25)
#define SCE_PAD2_ANALOG_CROSS (26)
#define SCE_PAD2_ANALOG_SQUARE (27)
#define SCE_PAD2_ANALOG_L1 (28)
#define SCE_PAD2_ANALOG_R1 (29)
#define SCE_PAD2_ANALOG_L2 (30)
#define SCE_PAD2_ANALOG_R2 (31)

typedef struct {
    u32 option;
    s32 port;
    s32 slot;
    s32 number;
    u8 name[SCE_PAD2_MAX_DEVICE_NAME];
} scePad2SocketParam;

typedef struct {
    u8 unk0;
    u8 unk1;

    u8 rJoyH;
    u8 rJoyV;
    u8 lJoyH;
    u8 lJoyV;

    u8 rightP;
    u8 leftP;
    u8 upP;
    u8 downP;
    u8 triangleP;
    u8 circleP;
    u8 crossP;
    u8 squareP;
    u8 l1P;
    u8 r1P;
    u8 l2P;
    u8 r2P;
} scePad2ButtonState;

typedef struct {
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 unk3;
} scePad2ButtonProfile;

s32 scePad2Init(s32);
s32 scePad2End(void);
s32 scePad2CreateSocket(scePad2SocketParam *, void *);
s32 scePad2DeleteSocket(s32);
s32 scePad2Read(s32, scePad2ButtonState *);
s32 scePad2GetButtonProfile(s32, scePad2ButtonProfile *);
s32 scePad2GetState(s32);
s32 scePad2GetButtonInfo(s32, u8 *, s32);
void scePad2StateIntToStr(s32, u8 *);
void *scePad2GetErxEntries(void);

#endif /* _LIBPAD2_H_ */
