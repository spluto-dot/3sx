#ifndef UNKNOWN_H
#define UNKNOWN_H

#include "sdk/libdma.h"
#include "sdk/libgraph.h"
#include "sf33rd/AcrSDK/common/plcommon.h"
#include "types.h"

// MARK: - Types

typedef struct {
    // total size: 0x18
    f32 x0; // offset 0x0, size 0x4
    f32 y0; // offset 0x4, size 0x4
    f32 x1; // offset 0x8, size 0x4
    f32 y1; // offset 0xC, size 0x4
    f32 ne; // offset 0x10, size 0x4
    f32 fa; // offset 0x14, size 0x4
} VPRM;

typedef struct {
    // total size: 0x8
    u8 *pFrame;  // offset 0x0, size 0x4
    s32 heapnum; // offset 0x4, size 0x4
} FMS_FRAME;

typedef struct {
    // total size: 0x4C
    FMS_FRAME fmsFrame;    // offset 0x0, size 0x8
    u8 *ramcntBuff;        // offset 0x8, size 0x4
    VPRM vprm;             // offset 0xC, size 0x18
    s8 ds_h[2];            // offset 0x24, size 0x2
    s8 ds_v[2];            // offset 0x26, size 0x2
    s8 sysStop;            // offset 0x28, size 0x1
    s8 initTrainingData;   // offset 0x29, size 0x1
    s8 inGame;             // offset 0x2A, size 0x1
    s8 ctrDemo;            // offset 0x2B, size 0x1
    s8 language;           // offset 0x2C, size 0x1
    s8 langload;           // offset 0x2D, size 0x1
    s8 cutAnalogStickData; // offset 0x2E, size 0x1
    s8 useAnalogStickData; // offset 0x2F, size 0x1
    s8 pal50Hz;            // offset 0x30, size 0x1
    u32 hanFbTex;          // offset 0x34, size 0x4
    u8 useChar[20];        // offset 0x38, size 0x14
} MPP;                     // size: 0x4C

typedef struct {
    // total size: 0xC
    s16 x;   // offset 0x0, size 0x2
    s16 y;   // offset 0x2, size 0x2
    s16 pow; // offset 0x4, size 0x2
    s16 ang; // offset 0x6, size 0x2
    f32 rad; // offset 0x8, size 0x4
} PAD_STICK;

typedef struct {
    // total size: 0x6C
    struct /* @anon26 */ {
        // total size: 0x34
        u8 state;           // offset 0x0, size 0x1
        u8 anstate;         // offset 0x1, size 0x1
        u16 kind;           // offset 0x2, size 0x2
        u32 sw;             // offset 0x4, size 0x4
        u32 sw_old;         // offset 0x8, size 0x4
        u32 sw_new;         // offset 0xC, size 0x4
        u32 sw_off;         // offset 0x10, size 0x4
        u32 sw_chg;         // offset 0x14, size 0x4
        u32 sw_repeat;      // offset 0x18, size 0x4
        PAD_STICK stick[2]; // offset 0x1C, size 0x18
    } data[2];              // offset 0x0, size 0x68
    u16 sw[2];              // offset 0x68, size 0x4
} IO;                       // size: 0x6C

struct _TASK {
    // total size: 0x14
    void (*func_adrs)();     // offset 0x0, size 0x4
    void (*callback_adrs)(); // offset 0x4, size 0x4
    u8 r_no[4];              // offset 0x8, size 0x4
    u16 condition;           // offset 0xC, size 0x2
    s16 timer;               // offset 0xE, size 0x2
    u8 free[4];              // offset 0x10, size 0x4
};

typedef struct {
    // total size: 0xD08
    s32 x16;            // offset 0x0, size 0x4
    s32 x32;            // offset 0x4, size 0x4
    u16 x16_used[1024]; // offset 0x8, size 0x800
    u16 x32_used[640];  // offset 0x808, size 0x500
} TPU;

struct _disp {
    // total size: 0xC
    u16 size_x; // offset 0x0, size 0x2
    u16 size_y; // offset 0x2, size 0x2
    u16 now;    // offset 0x4, size 0x2
    u16 new;    // offset 0x6, size 0x2
    s32 cable;  // offset 0x8, size 0x4
};

struct _SYSTEM_W {
    // total size: 0x1C
    struct _disp disp; // offset 0x0, size 0xC
    s32 pause;         // offset 0xC, size 0x4
    s32 gd_error;      // offset 0x10, size 0x4
    s32 reset;         // offset 0x14, size 0x4
    u8 sound_mode;     // offset 0x18, size 0x1
    u8 screen_mode;    // offset 0x19, size 0x1
    u8 bgm_type;       // offset 0x1A, size 0x1
    u8 dummy;          // offset 0x1B, size 0x1
};

typedef struct {
    // total size: 0x46C
    struct /* @anon46 */ {
        // total size: 0x388
        s8 be_flag;        // offset 0x0, size 0x1
        s8 disp_flag;      // offset 0x1, size 0x1
        u8 blink_timing;   // offset 0x2, size 0x1
        u8 operator;       // offset 0x3, size 0x1
        u8 type;           // offset 0x4, size 0x1
        u8 charset_id;     // offset 0x5, size 0x1
        s16 work_id;       // offset 0x6, size 0x2
        s16 id;            // offset 0x8, size 0x2
        s8 rl_flag;        // offset 0xA, size 0x1
        s8 rl_waza;        // offset 0xB, size 0x1
        u32 *target_adrs;  // offset 0xC, size 0x4
        u32 *hit_adrs;     // offset 0x10, size 0x4
        u32 *dmg_adrs;     // offset 0x14, size 0x4
        s16 before;        // offset 0x18, size 0x2
        s16 myself;        // offset 0x1A, size 0x2
        s16 behind;        // offset 0x1C, size 0x2
        s16 listix;        // offset 0x1E, size 0x2
        s16 dead_f;        // offset 0x20, size 0x2
        s16 timing;        // offset 0x22, size 0x2
        s16 routine_no[8]; // offset 0x24, size 0x10
        s16 old_rno[8];    // offset 0x34, size 0x10
        s16 hit_stop;      // offset 0x44, size 0x2
        s16 hit_quake;     // offset 0x46, size 0x2
        s8 cgromtype;      // offset 0x48, size 0x1
        u8 kage_flag;      // offset 0x49, size 0x1
        s16 kage_hx;       // offset 0x4A, size 0x2
        s16 kage_hy;       // offset 0x4C, size 0x2
        s16 kage_prio;     // offset 0x4E, size 0x2
        s16 kage_width;    // offset 0x50, size 0x2
        s16 kage_char;     // offset 0x52, size 0x2
        s16 position_x;    // offset 0x54, size 0x2
        s16 position_y;    // offset 0x56, size 0x2
        s16 position_z;    // offset 0x58, size 0x2
        s16 next_x;        // offset 0x5A, size 0x2
        s16 next_y;        // offset 0x5C, size 0x2
        s16 next_z;        // offset 0x5E, size 0x2
        s16 scr_mv_x;      // offset 0x60, size 0x2
        s16 scr_mv_y;      // offset 0x62, size 0x2
        union /* @anon29 */ {
            s32 cal; // offset 0x0, size 0x4
            struct /* @anon31 */ {
                // total size: 0x4
                s16 low;  // offset 0x0, size 0x2
                s16 pos;  // offset 0x2, size 0x2
            } disp;       // offset 0x0, size 0x4
        } xyz[3];         // offset 0x64, size 0xC
        s16 old_pos[3];   // offset 0x70, size 0x6
        s16 sync_suzi;    // offset 0x76, size 0x2
        u16 *suzi_offset; // offset 0x78, size 0x4
        struct /* @anon4 */ {
            // total size: 0x18
            union /* @anon5 */ {
                s32 sp; // offset 0x0, size 0x4
                struct /* @anon7 */ {
                    // total size: 0x4
                    s16 l; // offset 0x0, size 0x2
                    s16 h; // offset 0x2, size 0x2
                } real;    // offset 0x0, size 0x4
            } a[2];        // offset 0x0, size 0x8
            union /* @anon11 */ {
                s32 sp; // offset 0x0, size 0x4
                struct /* @anon13 */ {
                    // total size: 0x4
                    s16 l; // offset 0x0, size 0x2
                    s16 h; // offset 0x2, size 0x2
                } real;    // offset 0x0, size 0x4
            } d[2];        // offset 0x8, size 0x8
            s16 kop[2];    // offset 0x10, size 0x4
            u16 index;     // offset 0x14, size 0x2
        } mvxy;            // offset 0x7C, size 0x18
        s16 direction;     // offset 0x94, size 0x2
        s16 dir_old;       // offset 0x96, size 0x2
        s16 dir_step;      // offset 0x98, size 0x2
        s16 dir_timer;     // offset 0x9A, size 0x2
        s16 vitality;      // offset 0x9C, size 0x2
        s16 vital_new;     // offset 0x9E, size 0x2
        s16 vital_old;     // offset 0xA0, size 0x2
        s16 dm_vital;      // offset 0xA2, size 0x2
        s16 dmcal_m;       // offset 0xA4, size 0x2
        s16 dmcal_d;       // offset 0xA6, size 0x2
        s8 weight_level;   // offset 0xA8, size 0x1
        struct /* @anon21 */ {
            // total size: 0x8
            u16 code; // offset 0x0, size 0x2
            s16 koc;  // offset 0x2, size 0x2
            s16 ix;   // offset 0x4, size 0x2
            s16 pat;  // offset 0x6, size 0x2
        } cmoa;       // offset 0xAA, size 0x8
        struct /* @anon21 */ {
            // total size: 0x8
            u16 code; // offset 0x0, size 0x2
            s16 koc;  // offset 0x2, size 0x2
            s16 ix;   // offset 0x4, size 0x2
            s16 pat;  // offset 0x6, size 0x2
        } cmsw;       // offset 0xB2, size 0x8
        struct /* @anon21 */ {
            // total size: 0x8
            u16 code; // offset 0x0, size 0x2
            s16 koc;  // offset 0x2, size 0x2
            s16 ix;   // offset 0x4, size 0x2
            s16 pat;  // offset 0x6, size 0x2
        } cmlp;       // offset 0xBA, size 0x8
        struct /* @anon21 */ {
            // total size: 0x8
            u16 code; // offset 0x0, size 0x2
            s16 koc;  // offset 0x2, size 0x2
            s16 ix;   // offset 0x4, size 0x2
            s16 pat;  // offset 0x6, size 0x2
        } cml2;       // offset 0xC2, size 0x8
        struct /* @anon21 */ {
            // total size: 0x8
            u16 code; // offset 0x0, size 0x2
            s16 koc;  // offset 0x2, size 0x2
            s16 ix;   // offset 0x4, size 0x2
            s16 pat;  // offset 0x6, size 0x2
        } cmja;       // offset 0xCA, size 0x8
        struct /* @anon21 */ {
            // total size: 0x8
            u16 code; // offset 0x0, size 0x2
            s16 koc;  // offset 0x2, size 0x2
            s16 ix;   // offset 0x4, size 0x2
            s16 pat;  // offset 0x6, size 0x2
        } cmj2;       // offset 0xD2, size 0x8
        struct /* @anon21 */ {
            // total size: 0x8
            u16 code; // offset 0x0, size 0x2
            s16 koc;  // offset 0x2, size 0x2
            s16 ix;   // offset 0x4, size 0x2
            s16 pat;  // offset 0x6, size 0x2
        } cmj3;       // offset 0xDA, size 0x8
        struct /* @anon21 */ {
            // total size: 0x8
            u16 code; // offset 0x0, size 0x2
            s16 koc;  // offset 0x2, size 0x2
            s16 ix;   // offset 0x4, size 0x2
            s16 pat;  // offset 0x6, size 0x2
        } cmj4;       // offset 0xE2, size 0x8
        struct /* @anon21 */ {
            // total size: 0x8
            u16 code; // offset 0x0, size 0x2
            s16 koc;  // offset 0x2, size 0x2
            s16 ix;   // offset 0x4, size 0x2
            s16 pat;  // offset 0x6, size 0x2
        } cmj5;       // offset 0xEA, size 0x8
        struct /* @anon21 */ {
            // total size: 0x8
            u16 code; // offset 0x0, size 0x2
            s16 koc;  // offset 0x2, size 0x2
            s16 ix;   // offset 0x4, size 0x2
            s16 pat;  // offset 0x6, size 0x2
        } cmj6;       // offset 0xF2, size 0x8
        struct /* @anon21 */ {
            // total size: 0x8
            u16 code; // offset 0x0, size 0x2
            s16 koc;  // offset 0x2, size 0x2
            s16 ix;   // offset 0x4, size 0x2
            s16 pat;  // offset 0x6, size 0x2
        } cmj7;       // offset 0xFA, size 0x8
        struct /* @anon21 */ {
            // total size: 0x8
            u16 code; // offset 0x0, size 0x2
            s16 koc;  // offset 0x2, size 0x2
            s16 ix;   // offset 0x4, size 0x2
            s16 pat;  // offset 0x6, size 0x2
        } cmms;       // offset 0x102, size 0x8
        struct /* @anon21 */ {
            // total size: 0x8
            u16 code; // offset 0x0, size 0x2
            s16 koc;  // offset 0x2, size 0x2
            s16 ix;   // offset 0x4, size 0x2
            s16 pat;  // offset 0x6, size 0x2
        } cmmd;       // offset 0x10A, size 0x8
        struct /* @anon21 */ {
            // total size: 0x8
            u16 code; // offset 0x0, size 0x2
            s16 koc;  // offset 0x2, size 0x2
            s16 ix;   // offset 0x4, size 0x2
            s16 pat;  // offset 0x6, size 0x2
        } cmyd;       // offset 0x112, size 0x8
        struct /* @anon21 */ {
            // total size: 0x8
            u16 code; // offset 0x0, size 0x2
            s16 koc;  // offset 0x2, size 0x2
            s16 ix;   // offset 0x4, size 0x2
            s16 pat;  // offset 0x6, size 0x2
        } cmcf;       // offset 0x11A, size 0x8
        struct /* @anon21 */ {
            // total size: 0x8
            u16 code; // offset 0x0, size 0x2
            s16 koc;  // offset 0x2, size 0x2
            s16 ix;   // offset 0x4, size 0x2
            s16 pat;  // offset 0x6, size 0x2
        } cmcr;       // offset 0x122, size 0x8
        struct /* @anon21 */ {
            // total size: 0x8
            u16 code; // offset 0x0, size 0x2
            s16 koc;  // offset 0x2, size 0x2
            s16 ix;   // offset 0x4, size 0x2
            s16 pat;  // offset 0x6, size 0x2
        } cmbk;       // offset 0x12A, size 0x8
        struct /* @anon21 */ {
            // total size: 0x8
            u16 code; // offset 0x0, size 0x2
            s16 koc;  // offset 0x2, size 0x2
            s16 ix;   // offset 0x4, size 0x2
            s16 pat;  // offset 0x6, size 0x2
        } cmb2;       // offset 0x132, size 0x8
        struct /* @anon21 */ {
            // total size: 0x8
            u16 code; // offset 0x0, size 0x2
            s16 koc;  // offset 0x2, size 0x2
            s16 ix;   // offset 0x4, size 0x2
            s16 pat;  // offset 0x6, size 0x2
        } cmb3;       // offset 0x13A, size 0x8
        struct /* @anon21 */ {
            // total size: 0x8
            u16 code; // offset 0x0, size 0x2
            s16 koc;  // offset 0x2, size 0x2
            s16 ix;   // offset 0x4, size 0x2
            s16 pat;  // offset 0x6, size 0x2
        } cmhs;       // offset 0x142, size 0x8
        struct /* @anon21 */ {
            // total size: 0x8
            u16 code; // offset 0x0, size 0x2
            s16 koc;  // offset 0x2, size 0x2
            s16 ix;   // offset 0x4, size 0x2
            s16 pat;  // offset 0x6, size 0x2
        } cmr0;       // offset 0x14A, size 0x8
        struct /* @anon21 */ {
            // total size: 0x8
            u16 code; // offset 0x0, size 0x2
            s16 koc;  // offset 0x2, size 0x2
            s16 ix;   // offset 0x4, size 0x2
            s16 pat;  // offset 0x6, size 0x2
        } cmr1;       // offset 0x152, size 0x8
        struct /* @anon21 */ {
            // total size: 0x8
            u16 code; // offset 0x0, size 0x2
            s16 koc;  // offset 0x2, size 0x2
            s16 ix;   // offset 0x4, size 0x2
            s16 pat;  // offset 0x6, size 0x2
        } cmr2;       // offset 0x15A, size 0x8
        struct /* @anon21 */ {
            // total size: 0x8
            u16 code;         // offset 0x0, size 0x2
            s16 koc;          // offset 0x2, size 0x2
            s16 ix;           // offset 0x4, size 0x2
            s16 pat;          // offset 0x6, size 0x2
        } cmr3;               // offset 0x162, size 0x8
        s16 cmwk[32];         // offset 0x16A, size 0x40
        u32 *char_table[12];  // offset 0x1AC, size 0x30
        u32 *se_random_table; // offset 0x1DC, size 0x4
        s16 *step_xy_table;   // offset 0x1E0, size 0x4
        s16 *move_xy_table;   // offset 0x1E4, size 0x4
        struct /* @anon49 */ {
            // total size: 0x10
            s16 parts_hos_x; // offset 0x0, size 0x2
            s16 parts_hos_y; // offset 0x2, size 0x2
            u8 parts_colmd;  // offset 0x4, size 0x1
            u8 parts_colcd;  // offset 0x5, size 0x1
            u8 parts_prio;   // offset 0x6, size 0x1
            u8 parts_flip;   // offset 0x7, size 0x1
            u8 parts_timer;  // offset 0x8, size 0x1
            u8 parts_disp;   // offset 0x9, size 0x1
            s16 parts_mts;   // offset 0xA, size 0x2
            u16 parts_nix;   // offset 0xC, size 0x2
            u16 parts_char;  // offset 0xE, size 0x2
        } *overlap_char_tbl; // offset 0x1E8, size 0x4
        struct /* @anon43 */ {
            // total size: 0x8
            s16 olc_ix[4]; // offset 0x0, size 0x8
        } *olc_ix_table;   // offset 0x1EC, size 0x4
        struct /* @anon43 */ {
            // total size: 0x8
            s16 olc_ix[4]; // offset 0x0, size 0x8
        } cg_olc;          // offset 0x1F0, size 0x8
        struct /* @anon58 */ {
            // total size: 0x8
            s16 catch_hos_x; // offset 0x0, size 0x2
            s16 catch_hos_y; // offset 0x2, size 0x2
            u8 catch_prio;   // offset 0x4, size 0x1
            u8 catch_flip;   // offset 0x5, size 0x1
            s16 catch_nix;   // offset 0x6, size 0x2
        } *rival_catch_tbl;  // offset 0x1F8, size 0x4
        struct /* @anon58 */ {
            // total size: 0x8
            s16 catch_hos_x; // offset 0x0, size 0x2
            s16 catch_hos_y; // offset 0x2, size 0x2
            u8 catch_prio;   // offset 0x4, size 0x1
            u8 catch_flip;   // offset 0x5, size 0x1
            s16 catch_nix;   // offset 0x6, size 0x2
        } *curr_rca;         // offset 0x1FC, size 0x4
        u32 *set_char_ad;    // offset 0x200, size 0x4
        s16 cg_ix;           // offset 0x204, size 0x2
        s16 now_koc;         // offset 0x206, size 0x2
        s16 char_index;      // offset 0x208, size 0x2
        s16 current_colcd;   // offset 0x20A, size 0x2
        s16 cgd_type;        // offset 0x20C, size 0x2
        u8 pat_status;       // offset 0x20E, size 0x1
        u8 kind_of_waza;     // offset 0x20F, size 0x1
        u8 hit_range;        // offset 0x210, size 0x1
        u8 total_paring;     // offset 0x211, size 0x1
        u8 total_att_set;    // offset 0x212, size 0x1
        u8 sp_tech_id;       // offset 0x213, size 0x1
        u8 cg_type;          // offset 0x214, size 0x1
        u8 cg_ctr;           // offset 0x215, size 0x1
        u16 cg_se;           // offset 0x216, size 0x2
        u16 cg_olc_ix;       // offset 0x218, size 0x2
        u16 cg_number;       // offset 0x21A, size 0x2
        u16 cg_hit_ix;       // offset 0x21C, size 0x2
        s16 cg_att_ix;       // offset 0x21E, size 0x2
        u8 cg_extdat;        // offset 0x220, size 0x1
        u8 cg_cancel;        // offset 0x221, size 0x1
        u8 cg_effect;        // offset 0x222, size 0x1
        u8 cg_eftype;        // offset 0x223, size 0x1
        u16 cg_zoom;         // offset 0x224, size 0x2
        u16 cg_rival;        // offset 0x226, size 0x2
        u16 cg_add_xy;       // offset 0x228, size 0x2
        u8 cg_next_ix;       // offset 0x22A, size 0x1
        u8 cg_status;        // offset 0x22B, size 0x1
        s16 cg_wca_ix;       // offset 0x22C, size 0x2
        s16 cg_jphos;        // offset 0x22E, size 0x2
        u16 cg_meoshi;       // offset 0x230, size 0x2
        u8 cg_prio;          // offset 0x232, size 0x1
        u8 cg_flip;          // offset 0x233, size 0x1
        u16 old_cgnum;       // offset 0x234, size 0x2
        s16 floor;           // offset 0x236, size 0x2
        u16 ccoff;           // offset 0x238, size 0x2
        s16 colcd;           // offset 0x23A, size 0x2
        s16 my_col_mode;     // offset 0x23C, size 0x2
        s16 my_col_code;     // offset 0x23E, size 0x2
        s16 my_priority;     // offset 0x240, size 0x2
        s16 my_family;       // offset 0x242, size 0x2
        s16 my_ext_pri;      // offset 0x244, size 0x2
        s16 my_bright_type;  // offset 0x246, size 0x2
        s16 my_bright_level; // offset 0x248, size 0x2
        s16 my_clear_level;  // offset 0x24A, size 0x2
        s16 my_mts;          // offset 0x24C, size 0x2
        s16 my_mr_flag;      // offset 0x24E, size 0x2
        struct /* @anon47 */ {
            // total size: 0x4
            struct /* @anon48 */ {
                // total size: 0x4
                s16 x;     // offset 0x0, size 0x2
                s16 y;     // offset 0x2, size 0x2
            } size;        // offset 0x0, size 0x4
        } my_mr;           // offset 0x250, size 0x4
        s16 my_trans_mode; // offset 0x254, size 0x2
        s16 my_roll_flag;  // offset 0x256, size 0x2
        struct /* @anon52 */ {
            // total size: 0x8
            s16 now;         // offset 0x0, size 0x2
            s16 add;         // offset 0x2, size 0x2
            s16 free;        // offset 0x4, size 0x2
            s16 old;         // offset 0x6, size 0x2
        } my_roll;           // offset 0x258, size 0x8
        s16 waku_work_index; // offset 0x260, size 0x2
        s16 olc_work_ix[4];  // offset 0x262, size 0x8
        struct /* @anon6 */ {
            // total size: 0x10
            u16 boix; // offset 0x0, size 0x2
            u16 bhix; // offset 0x2, size 0x2
            u16 haix; // offset 0x4, size 0x2
            union /* @anon10 */ {
                u16 full; // offset 0x0, size 0x2
                struct /* @anon12 */ {
                    // total size: 0x2
                    u8 bx; // offset 0x0, size 0x1
                    u8 mv; // offset 0x1, size 0x1
                } half;    // offset 0x0, size 0x2
            } mf;          // offset 0x6, size 0x2
            u16 caix;      // offset 0x8, size 0x2
            u16 cuix;      // offset 0xA, size 0x2
            u16 atix;      // offset 0xC, size 0x2
            u16 hoix;      // offset 0xE, size 0x2
        } *hit_ix_table;   // offset 0x26C, size 0x4
        struct /* @anon6 */ {
            // total size: 0x10
            u16 boix; // offset 0x0, size 0x2
            u16 bhix; // offset 0x2, size 0x2
            u16 haix; // offset 0x4, size 0x2
            union /* @anon10 */ {
                u16 full; // offset 0x0, size 0x2
                struct /* @anon12 */ {
                    // total size: 0x2
                    u8 bx; // offset 0x0, size 0x1
                    u8 mv; // offset 0x1, size 0x1
                } half;    // offset 0x0, size 0x2
            } mf;          // offset 0x6, size 0x2
            u16 caix;      // offset 0x8, size 0x2
            u16 cuix;      // offset 0xA, size 0x2
            u16 atix;      // offset 0xC, size 0x2
            u16 hoix;      // offset 0xE, size 0x2
        } cg_ja;           // offset 0x270, size 0x10
        struct /* @anon22 */ {
            // total size: 0x20
            s16 body_dm[4][4]; // offset 0x0, size 0x20
        } *body_adrs;          // offset 0x280, size 0x4
        struct /* @anon22 */ {
            // total size: 0x20
            s16 body_dm[4][4]; // offset 0x0, size 0x20
        } *h_bod;              // offset 0x284, size 0x4
        struct /* @anon26 */ {
            // total size: 0x20
            s16 hand_dm[4][4]; // offset 0x0, size 0x20
        } *hand_adrs;          // offset 0x288, size 0x4
        struct /* @anon26 */ {
            // total size: 0x20
            s16 hand_dm[4][4]; // offset 0x0, size 0x20
        } *h_han;              // offset 0x28C, size 0x4
        struct /* @anon26 */ {
            // total size: 0x20
            s16 hand_dm[4][4]; // offset 0x0, size 0x20
        } *dumm_adrs;          // offset 0x290, size 0x4
        struct /* @anon26 */ {
            // total size: 0x20
            s16 hand_dm[4][4]; // offset 0x0, size 0x20
        } *h_dumm;             // offset 0x294, size 0x4
        struct /* @anon36 */ {
            // total size: 0x8
            s16 cat_box[4]; // offset 0x0, size 0x8
        } *catch_adrs;      // offset 0x298, size 0x4
        struct /* @anon36 */ {
            // total size: 0x8
            s16 cat_box[4]; // offset 0x0, size 0x8
        } *h_cat;           // offset 0x29C, size 0x4
        struct /* @anon39 */ {
            // total size: 0x8
            s16 cau_box[4]; // offset 0x0, size 0x8
        } *caught_adrs;     // offset 0x2A0, size 0x4
        struct /* @anon39 */ {
            // total size: 0x8
            s16 cau_box[4]; // offset 0x0, size 0x8
        } *h_cau;           // offset 0x2A4, size 0x4
        struct /* @anon32 */ {
            // total size: 0x20
            s16 att_box[4][4]; // offset 0x0, size 0x20
        } *attack_adrs;        // offset 0x2A8, size 0x4
        struct /* @anon32 */ {
            // total size: 0x20
            s16 att_box[4][4]; // offset 0x0, size 0x20
        } *h_att;              // offset 0x2AC, size 0x4
        struct /* @anon32 */ {
            // total size: 0x20
            s16 att_box[4][4]; // offset 0x0, size 0x20
        } *h_eat;              // offset 0x2B0, size 0x4
        struct /* @anon42 */ {
            // total size: 0x8
            s16 hos_box[4]; // offset 0x0, size 0x8
        } *hosei_adrs;      // offset 0x2B4, size 0x4
        struct /* @anon42 */ {
            // total size: 0x8
            s16 hos_box[4]; // offset 0x0, size 0x8
        } *h_hos;           // offset 0x2B8, size 0x4
        struct /* @anon60 */ {
            // total size: 0x10
            u8 reaction; // offset 0x0, size 0x1
            u8 level;    // offset 0x1, size 0x1
            u8 mkh_ix;   // offset 0x2, size 0x1
            u8 but_ix;   // offset 0x3, size 0x1
            u8 dipsw;    // offset 0x4, size 0x1
            u8 guard;    // offset 0x5, size 0x1
            u8 dir;      // offset 0x6, size 0x1
            u8 free;     // offset 0x7, size 0x1
            u8 pow;      // offset 0x8, size 0x1
            u8 impact;   // offset 0x9, size 0x1
            u8 piyo;     // offset 0xA, size 0x1
            u8 ng_type;  // offset 0xB, size 0x1
            s8 hs_me;    // offset 0xC, size 0x1
            s8 hs_you;   // offset 0xD, size 0x1
            u8 hit_mark; // offset 0xE, size 0x1
            u8 dmg_mark; // offset 0xF, size 0x1
        } *att_ix_table; // offset 0x2BC, size 0x4
        struct /* @anon60 */ {
            // total size: 0x10
            u8 reaction;       // offset 0x0, size 0x1
            u8 level;          // offset 0x1, size 0x1
            u8 mkh_ix;         // offset 0x2, size 0x1
            u8 but_ix;         // offset 0x3, size 0x1
            u8 dipsw;          // offset 0x4, size 0x1
            u8 guard;          // offset 0x5, size 0x1
            u8 dir;            // offset 0x6, size 0x1
            u8 free;           // offset 0x7, size 0x1
            u8 pow;            // offset 0x8, size 0x1
            u8 impact;         // offset 0x9, size 0x1
            u8 piyo;           // offset 0xA, size 0x1
            u8 ng_type;        // offset 0xB, size 0x1
            s8 hs_me;          // offset 0xC, size 0x1
            s8 hs_you;         // offset 0xD, size 0x1
            u8 hit_mark;       // offset 0xE, size 0x1
            u8 dmg_mark;       // offset 0xF, size 0x1
        } att;                 // offset 0x2C0, size 0x10
        u16 zu_flag;           // offset 0x2D0, size 0x2
        u16 at_attribute;      // offset 0x2D2, size 0x2
        s16 kezuri_pow;        // offset 0x2D4, size 0x2
        u16 add_arts_point;    // offset 0x2D6, size 0x2
        u16 buttobi_type;      // offset 0x2D8, size 0x2
        u16 att_zuru;          // offset 0x2DA, size 0x2
        u16 at_ten_ix;         // offset 0x2DC, size 0x2
        s16 dir_atthit;        // offset 0x2DE, size 0x2
        s16 vs_id;             // offset 0x2E0, size 0x2
        u8 att_hit_ok;         // offset 0x2E2, size 0x1
        u8 meoshi_hit_flag;    // offset 0x2E3, size 0x1
        u16 at_koa;            // offset 0x2E4, size 0x2
        u8 paring_attack_flag; // offset 0x2E6, size 0x1
        s8 no_death_attack;    // offset 0x2E7, size 0x1
        u8 jump_att_flag;      // offset 0x2E8, size 0x1
        s8 shell_vs_refrect;   // offset 0x2E9, size 0x1
        s16 renew_attack;      // offset 0x2EA, size 0x2
        u16 attack_num;        // offset 0x2EC, size 0x2
        u16 uketa_att[4];      // offset 0x2EE, size 0x8
        union /* @anon16 */ {
            struct /* @anon18 */ {
                // total size: 0x2
                u8 player;     // offset 0x0, size 0x1
                u8 effect;     // offset 0x1, size 0x1
            } hit;             // offset 0x0, size 0x2
            u16 hit_flag;      // offset 0x0, size 0x2
        } hf;                  // offset 0x2F6, size 0x2
        s16 hit_mark_x;        // offset 0x2F8, size 0x2
        s16 hit_mark_y;        // offset 0x2FA, size 0x2
        s16 hit_mark_z;        // offset 0x2FC, size 0x2
        s16 kohm;              // offset 0x2FE, size 0x2
        u8 dm_fushin;          // offset 0x300, size 0x1
        s8 dm_weight;          // offset 0x301, size 0x1
        u16 dm_butt_type;      // offset 0x302, size 0x2
        u16 dm_zuru;           // offset 0x304, size 0x2
        u16 dm_attribute;      // offset 0x306, size 0x2
        s16 dm_guard_success;  // offset 0x308, size 0x2
        s16 dm_plnum;          // offset 0x30A, size 0x2
        s16 dm_attlv;          // offset 0x30C, size 0x2
        s16 dm_dir;            // offset 0x30E, size 0x2
        s8 dm_rl;              // offset 0x310, size 0x1
        u8 dm_impact;          // offset 0x311, size 0x1
        s16 dm_stop;           // offset 0x312, size 0x2
        s16 dm_quake;          // offset 0x314, size 0x2
        u16 dm_piyo;           // offset 0x316, size 0x2
        u16 dm_ten_ix;         // offset 0x318, size 0x2
        u16 dm_koa;            // offset 0x31A, size 0x2
        s16 dm_work_id;        // offset 0x31C, size 0x2
        u16 dm_arts_point;     // offset 0x31E, size 0x2
        u8 dm_jump_att_flag;   // offset 0x320, size 0x1
        u8 dm_free;            // offset 0x321, size 0x1
        s16 dm_count_up;       // offset 0x322, size 0x2
        s8 dm_nodeathattack;   // offset 0x324, size 0x1
        u8 dm_exdm_ix;         // offset 0x325, size 0x1
        u8 dm_dip;             // offset 0x326, size 0x1
        u8 dm_kind_of_waza;    // offset 0x327, size 0x1
        s16 attpow;            // offset 0x328, size 0x2
        s16 defpow;            // offset 0x32A, size 0x2
        u32 *my_effadrs;       // offset 0x32C, size 0x4
        s16 shell_ix[8];       // offset 0x330, size 0x10
        s16 hm_dm_side;        // offset 0x340, size 0x2
        s16 extra_col;         // offset 0x342, size 0x2
        s16 extra_col_2;       // offset 0x344, size 0x2
        s16 original_vitality; // offset 0x346, size 0x2
        u8 hit_work_id;        // offset 0x348, size 0x1
        u8 dmg_work_id;        // offset 0x349, size 0x1
        s8 K5_init_flag;       // offset 0x34A, size 0x1
        s8 K5_exec_ok;         // offset 0x34B, size 0x1
        u8 kow;                // offset 0x34C, size 0x1
        u8 swallow_no_effect;  // offset 0x34D, size 0x1
        s16 E3_work_index;     // offset 0x34E, size 0x2
        s16 E4_work_index;     // offset 0x350, size 0x2
        u8 kezurare_flag;      // offset 0x352, size 0x1
        u8 wrd_free[53];       // offset 0x353, size 0x35
    } wu;                      // offset 0x0, size 0x388
    struct /* @anon65 */ {
        // total size: 0x406
        u16 sw_lvbt;       // offset 0x0, size 0x2
        u16 sw_new;        // offset 0x2, size 0x2
        u16 sw_old;        // offset 0x4, size 0x2
        u16 sw_now;        // offset 0x6, size 0x2
        u16 sw_off;        // offset 0x8, size 0x2
        u16 sw_chg;        // offset 0xA, size 0x2
        u16 old_now;       // offset 0xC, size 0x2
        s16 lgp;           // offset 0xE, size 0x2
        u8 ca14;           // offset 0x10, size 0x1
        u8 ca25;           // offset 0x11, size 0x1
        u8 ca36;           // offset 0x12, size 0x1
        u8 calf;           // offset 0x13, size 0x1
        u8 calr;           // offset 0x14, size 0x1
        u8 lever_dir;      // offset 0x15, size 0x1
        s16 waza_flag[56]; // offset 0x16, size 0x70
        s16 reset[56];     // offset 0x86, size 0x70
        u8 waza_r[56][4];  // offset 0xF6, size 0xE0
        u16 btix[56];      // offset 0x1D6, size 0x70
        u16 exdt[56][4];   // offset 0x246, size 0x1C0
    } *cp;                 // offset 0x388, size 0x4
    u32 spmv_ng_flag;      // offset 0x38C, size 0x4
    u32 spmv_ng_flag2;     // offset 0x390, size 0x4
    s16 player_number;     // offset 0x394, size 0x2
    s16 zuru_timer;        // offset 0x396, size 0x2
    u16 zuru_ix_counter;   // offset 0x398, size 0x2
    u8 zuru_flag;          // offset 0x39A, size 0x1
    s8 tsukamarenai_flag;  // offset 0x39B, size 0x1
    u8 kizetsu_kow;        // offset 0x39C, size 0x1
    u8 micchaku_flag;      // offset 0x39D, size 0x1
    u8 hos_fi_flag;        // offset 0x39E, size 0x1
    u8 hos_em_flag;        // offset 0x39F, size 0x1
    s16 tsukami_num;       // offset 0x3A0, size 0x2
    s8 tsukami_f;          // offset 0x3A2, size 0x1
    s8 tsukamare_f;        // offset 0x3A3, size 0x1
    s8 kind_of_catch;      // offset 0x3A4, size 0x1
    u8 old_gdflag;         // offset 0x3A5, size 0x1
    u8 guard_flag;         // offset 0x3A6, size 0x1
    u8 guard_chuu;         // offset 0x3A7, size 0x1
    s16 dm_ix;             // offset 0x3A8, size 0x2
    s16 hosei_amari;       // offset 0x3AA, size 0x2
    s8 dm_hos_flag;        // offset 0x3AC, size 0x1
    u8 dm_point;           // offset 0x3AD, size 0x1
    s16 muriyari_ugoku;    // offset 0x3AE, size 0x2
    s8 scr_pos_set_flag;   // offset 0x3B0, size 0x1
    s8 hoshi_flag;         // offset 0x3B1, size 0x1
    s8 the_same_players;   // offset 0x3B2, size 0x1
    s8 *dm_step_tbl;       // offset 0x3B4, size 0x4
    s8 running_f;          // offset 0x3B8, size 0x1
    s8 cancel_timer;       // offset 0x3B9, size 0x1
    s8 jpdir;              // offset 0x3BA, size 0x1
    s8 jptim;              // offset 0x3BB, size 0x1
    s16 current_attack;    // offset 0x3BC, size 0x2
    struct /* @anon17 */ {
        // total size: 0x6
        s16 r_no;    // offset 0x0, size 0x2
        s16 char_ix; // offset 0x2, size 0x2
        s16 data_ix; // offset 0x4, size 0x2
    } *as;           // offset 0x3C0, size 0x4
    struct /* @anon25 */ {
        // total size: 0x2C
        s16 kind_of_arts; // offset 0x0, size 0x2
        u8 nmsa_g_ix;     // offset 0x2, size 0x1
        u8 exsa_g_ix;     // offset 0x3, size 0x1
        u8 exs2_g_ix;     // offset 0x4, size 0x1
        u8 nmsa_a_ix;     // offset 0x5, size 0x1
        u8 exsa_a_ix;     // offset 0x6, size 0x1
        u8 exs2_a_ix;     // offset 0x7, size 0x1
        s8 gauge_type;    // offset 0x8, size 0x1
        s8 mp;            // offset 0x9, size 0x1
        s8 ok;            // offset 0xA, size 0x1
        s8 ex;            // offset 0xB, size 0x1
        s8 ba;            // offset 0xC, size 0x1
        s8 dtm_mul;       // offset 0xD, size 0x1
        s8 mp_rno;        // offset 0xE, size 0x1
        s8 mp_rno2;       // offset 0xF, size 0x1
        s8 sa_rno;        // offset 0x10, size 0x1
        s8 sa_rno2;       // offset 0x11, size 0x1
        s8 ex_rno;        // offset 0x12, size 0x1
        s8 gt2;           // offset 0x13, size 0x1
        s8 saeff_ok;      // offset 0x14, size 0x1
        s8 saeff_mp;      // offset 0x15, size 0x1
        s16 gauge_len;    // offset 0x16, size 0x2
        union /* @anon63 */ {
            s32 i; // offset 0x0, size 0x4
            struct /* @anon64 */ {
                // total size: 0x4
                s16 l;   // offset 0x0, size 0x2
                s16 h;   // offset 0x2, size 0x2
            } s;         // offset 0x0, size 0x4
        } gauge;         // offset 0x18, size 0x4
        s32 dtm;         // offset 0x1C, size 0x4
        s16 store_max;   // offset 0x20, size 0x2
        s16 store;       // offset 0x22, size 0x2
        s16 id_arts;     // offset 0x24, size 0x2
        u8 ex4th_full;   // offset 0x26, size 0x1
        u8 ex4th_exec;   // offset 0x27, size 0x1
        s16 total_gauge; // offset 0x28, size 0x2
        s16 bacckup_g_h; // offset 0x2A, size 0x2
    } *sa;               // offset 0x3C4, size 0x4
    struct /* @anon27 */ {
        // total size: 0xA8
        s16 total;             // offset 0x0, size 0x2
        s16 new_dm;            // offset 0x2, size 0x2
        s16 req_f;             // offset 0x4, size 0x2
        s16 old_r;             // offset 0x6, size 0x2
        s16 kind_of[10][4][2]; // offset 0x8, size 0xA0
    } *cb;                     // offset 0x3C8, size 0x4
    struct /* @anon28 */ {
        // total size: 0x14
        s8 flag;    // offset 0x0, size 0x1
        s16 genkai; // offset 0x2, size 0x2
        s16 time;   // offset 0x4, size 0x2
        union /* @anon40 */ {
            s32 timer; // offset 0x0, size 0x4
            struct /* @anon41 */ {
                // total size: 0x4
                s16 l;   // offset 0x0, size 0x2
                s16 h;   // offset 0x2, size 0x2
            } quantity;  // offset 0x0, size 0x4
        } now;           // offset 0x8, size 0x4
        s32 recover;     // offset 0xC, size 0x4
        s16 store;       // offset 0x10, size 0x2
        s16 again;       // offset 0x12, size 0x2
    } *py;               // offset 0x3CC, size 0x4
    s8 wkey_flag;        // offset 0x3D0, size 0x1
    s8 dead_flag;        // offset 0x3D1, size 0x1
    s16 ukemi_ok_timer;  // offset 0x3D2, size 0x2
    s16 backup_ok_timer; // offset 0x3D4, size 0x2
    s8 uot_cd_ok_flag;   // offset 0x3D6, size 0x1
    s8 ukemi_success;    // offset 0x3D7, size 0x1
    s16 old_pos_data[8]; // offset 0x3D8, size 0x10
    s16 move_distance;   // offset 0x3E8, size 0x2
    s16 move_power;      // offset 0x3EA, size 0x2
    s16 sa_stop_sai;     // offset 0x3EC, size 0x2
    u8 saishin_lvdir;    // offset 0x3EE, size 0x1
    u8 sa_stop_lvdir;    // offset 0x3EF, size 0x1
    u8 sa_stop_flag;     // offset 0x3F0, size 0x1
    u8 kezurijini_flag;  // offset 0x3F1, size 0x1
    struct /* @anon46 */ {
        // total size: 0x388
        s8 be_flag;        // offset 0x0, size 0x1
        s8 disp_flag;      // offset 0x1, size 0x1
        u8 blink_timing;   // offset 0x2, size 0x1
        u8 operator;       // offset 0x3, size 0x1
        u8 type;           // offset 0x4, size 0x1
        u8 charset_id;     // offset 0x5, size 0x1
        s16 work_id;       // offset 0x6, size 0x2
        s16 id;            // offset 0x8, size 0x2
        s8 rl_flag;        // offset 0xA, size 0x1
        s8 rl_waza;        // offset 0xB, size 0x1
        u32 *target_adrs;  // offset 0xC, size 0x4
        u32 *hit_adrs;     // offset 0x10, size 0x4
        u32 *dmg_adrs;     // offset 0x14, size 0x4
        s16 before;        // offset 0x18, size 0x2
        s16 myself;        // offset 0x1A, size 0x2
        s16 behind;        // offset 0x1C, size 0x2
        s16 listix;        // offset 0x1E, size 0x2
        s16 dead_f;        // offset 0x20, size 0x2
        s16 timing;        // offset 0x22, size 0x2
        s16 routine_no[8]; // offset 0x24, size 0x10
        s16 old_rno[8];    // offset 0x34, size 0x10
        s16 hit_stop;      // offset 0x44, size 0x2
        s16 hit_quake;     // offset 0x46, size 0x2
        s8 cgromtype;      // offset 0x48, size 0x1
        u8 kage_flag;      // offset 0x49, size 0x1
        s16 kage_hx;       // offset 0x4A, size 0x2
        s16 kage_hy;       // offset 0x4C, size 0x2
        s16 kage_prio;     // offset 0x4E, size 0x2
        s16 kage_width;    // offset 0x50, size 0x2
        s16 kage_char;     // offset 0x52, size 0x2
        s16 position_x;    // offset 0x54, size 0x2
        s16 position_y;    // offset 0x56, size 0x2
        s16 position_z;    // offset 0x58, size 0x2
        s16 next_x;        // offset 0x5A, size 0x2
        s16 next_y;        // offset 0x5C, size 0x2
        s16 next_z;        // offset 0x5E, size 0x2
        s16 scr_mv_x;      // offset 0x60, size 0x2
        s16 scr_mv_y;      // offset 0x62, size 0x2
        union /* @anon29 */ {
            s32 cal; // offset 0x0, size 0x4
            struct /* @anon31 */ {
                // total size: 0x4
                s16 low;  // offset 0x0, size 0x2
                s16 pos;  // offset 0x2, size 0x2
            } disp;       // offset 0x0, size 0x4
        } xyz[3];         // offset 0x64, size 0xC
        s16 old_pos[3];   // offset 0x70, size 0x6
        s16 sync_suzi;    // offset 0x76, size 0x2
        u16 *suzi_offset; // offset 0x78, size 0x4
        struct /* @anon4 */ {
            // total size: 0x18
            union /* @anon5 */ {
                s32 sp; // offset 0x0, size 0x4
                struct /* @anon7 */ {
                    // total size: 0x4
                    s16 l; // offset 0x0, size 0x2
                    s16 h; // offset 0x2, size 0x2
                } real;    // offset 0x0, size 0x4
            } a[2];        // offset 0x0, size 0x8
            union /* @anon11 */ {
                s32 sp; // offset 0x0, size 0x4
                struct /* @anon13 */ {
                    // total size: 0x4
                    s16 l; // offset 0x0, size 0x2
                    s16 h; // offset 0x2, size 0x2
                } real;    // offset 0x0, size 0x4
            } d[2];        // offset 0x8, size 0x8
            s16 kop[2];    // offset 0x10, size 0x4
            u16 index;     // offset 0x14, size 0x2
        } mvxy;            // offset 0x7C, size 0x18
        s16 direction;     // offset 0x94, size 0x2
        s16 dir_old;       // offset 0x96, size 0x2
        s16 dir_step;      // offset 0x98, size 0x2
        s16 dir_timer;     // offset 0x9A, size 0x2
        s16 vitality;      // offset 0x9C, size 0x2
        s16 vital_new;     // offset 0x9E, size 0x2
        s16 vital_old;     // offset 0xA0, size 0x2
        s16 dm_vital;      // offset 0xA2, size 0x2
        s16 dmcal_m;       // offset 0xA4, size 0x2
        s16 dmcal_d;       // offset 0xA6, size 0x2
        s8 weight_level;   // offset 0xA8, size 0x1
        struct /* @anon21 */ {
            // total size: 0x8
            u16 code; // offset 0x0, size 0x2
            s16 koc;  // offset 0x2, size 0x2
            s16 ix;   // offset 0x4, size 0x2
            s16 pat;  // offset 0x6, size 0x2
        } cmoa;       // offset 0xAA, size 0x8
        struct /* @anon21 */ {
            // total size: 0x8
            u16 code; // offset 0x0, size 0x2
            s16 koc;  // offset 0x2, size 0x2
            s16 ix;   // offset 0x4, size 0x2
            s16 pat;  // offset 0x6, size 0x2
        } cmsw;       // offset 0xB2, size 0x8
        struct /* @anon21 */ {
            // total size: 0x8
            u16 code; // offset 0x0, size 0x2
            s16 koc;  // offset 0x2, size 0x2
            s16 ix;   // offset 0x4, size 0x2
            s16 pat;  // offset 0x6, size 0x2
        } cmlp;       // offset 0xBA, size 0x8
        struct /* @anon21 */ {
            // total size: 0x8
            u16 code; // offset 0x0, size 0x2
            s16 koc;  // offset 0x2, size 0x2
            s16 ix;   // offset 0x4, size 0x2
            s16 pat;  // offset 0x6, size 0x2
        } cml2;       // offset 0xC2, size 0x8
        struct /* @anon21 */ {
            // total size: 0x8
            u16 code; // offset 0x0, size 0x2
            s16 koc;  // offset 0x2, size 0x2
            s16 ix;   // offset 0x4, size 0x2
            s16 pat;  // offset 0x6, size 0x2
        } cmja;       // offset 0xCA, size 0x8
        struct /* @anon21 */ {
            // total size: 0x8
            u16 code; // offset 0x0, size 0x2
            s16 koc;  // offset 0x2, size 0x2
            s16 ix;   // offset 0x4, size 0x2
            s16 pat;  // offset 0x6, size 0x2
        } cmj2;       // offset 0xD2, size 0x8
        struct /* @anon21 */ {
            // total size: 0x8
            u16 code; // offset 0x0, size 0x2
            s16 koc;  // offset 0x2, size 0x2
            s16 ix;   // offset 0x4, size 0x2
            s16 pat;  // offset 0x6, size 0x2
        } cmj3;       // offset 0xDA, size 0x8
        struct /* @anon21 */ {
            // total size: 0x8
            u16 code; // offset 0x0, size 0x2
            s16 koc;  // offset 0x2, size 0x2
            s16 ix;   // offset 0x4, size 0x2
            s16 pat;  // offset 0x6, size 0x2
        } cmj4;       // offset 0xE2, size 0x8
        struct /* @anon21 */ {
            // total size: 0x8
            u16 code; // offset 0x0, size 0x2
            s16 koc;  // offset 0x2, size 0x2
            s16 ix;   // offset 0x4, size 0x2
            s16 pat;  // offset 0x6, size 0x2
        } cmj5;       // offset 0xEA, size 0x8
        struct /* @anon21 */ {
            // total size: 0x8
            u16 code; // offset 0x0, size 0x2
            s16 koc;  // offset 0x2, size 0x2
            s16 ix;   // offset 0x4, size 0x2
            s16 pat;  // offset 0x6, size 0x2
        } cmj6;       // offset 0xF2, size 0x8
        struct /* @anon21 */ {
            // total size: 0x8
            u16 code; // offset 0x0, size 0x2
            s16 koc;  // offset 0x2, size 0x2
            s16 ix;   // offset 0x4, size 0x2
            s16 pat;  // offset 0x6, size 0x2
        } cmj7;       // offset 0xFA, size 0x8
        struct /* @anon21 */ {
            // total size: 0x8
            u16 code; // offset 0x0, size 0x2
            s16 koc;  // offset 0x2, size 0x2
            s16 ix;   // offset 0x4, size 0x2
            s16 pat;  // offset 0x6, size 0x2
        } cmms;       // offset 0x102, size 0x8
        struct /* @anon21 */ {
            // total size: 0x8
            u16 code; // offset 0x0, size 0x2
            s16 koc;  // offset 0x2, size 0x2
            s16 ix;   // offset 0x4, size 0x2
            s16 pat;  // offset 0x6, size 0x2
        } cmmd;       // offset 0x10A, size 0x8
        struct /* @anon21 */ {
            // total size: 0x8
            u16 code; // offset 0x0, size 0x2
            s16 koc;  // offset 0x2, size 0x2
            s16 ix;   // offset 0x4, size 0x2
            s16 pat;  // offset 0x6, size 0x2
        } cmyd;       // offset 0x112, size 0x8
        struct /* @anon21 */ {
            // total size: 0x8
            u16 code; // offset 0x0, size 0x2
            s16 koc;  // offset 0x2, size 0x2
            s16 ix;   // offset 0x4, size 0x2
            s16 pat;  // offset 0x6, size 0x2
        } cmcf;       // offset 0x11A, size 0x8
        struct /* @anon21 */ {
            // total size: 0x8
            u16 code; // offset 0x0, size 0x2
            s16 koc;  // offset 0x2, size 0x2
            s16 ix;   // offset 0x4, size 0x2
            s16 pat;  // offset 0x6, size 0x2
        } cmcr;       // offset 0x122, size 0x8
        struct /* @anon21 */ {
            // total size: 0x8
            u16 code; // offset 0x0, size 0x2
            s16 koc;  // offset 0x2, size 0x2
            s16 ix;   // offset 0x4, size 0x2
            s16 pat;  // offset 0x6, size 0x2
        } cmbk;       // offset 0x12A, size 0x8
        struct /* @anon21 */ {
            // total size: 0x8
            u16 code; // offset 0x0, size 0x2
            s16 koc;  // offset 0x2, size 0x2
            s16 ix;   // offset 0x4, size 0x2
            s16 pat;  // offset 0x6, size 0x2
        } cmb2;       // offset 0x132, size 0x8
        struct /* @anon21 */ {
            // total size: 0x8
            u16 code; // offset 0x0, size 0x2
            s16 koc;  // offset 0x2, size 0x2
            s16 ix;   // offset 0x4, size 0x2
            s16 pat;  // offset 0x6, size 0x2
        } cmb3;       // offset 0x13A, size 0x8
        struct /* @anon21 */ {
            // total size: 0x8
            u16 code; // offset 0x0, size 0x2
            s16 koc;  // offset 0x2, size 0x2
            s16 ix;   // offset 0x4, size 0x2
            s16 pat;  // offset 0x6, size 0x2
        } cmhs;       // offset 0x142, size 0x8
        struct /* @anon21 */ {
            // total size: 0x8
            u16 code; // offset 0x0, size 0x2
            s16 koc;  // offset 0x2, size 0x2
            s16 ix;   // offset 0x4, size 0x2
            s16 pat;  // offset 0x6, size 0x2
        } cmr0;       // offset 0x14A, size 0x8
        struct /* @anon21 */ {
            // total size: 0x8
            u16 code; // offset 0x0, size 0x2
            s16 koc;  // offset 0x2, size 0x2
            s16 ix;   // offset 0x4, size 0x2
            s16 pat;  // offset 0x6, size 0x2
        } cmr1;       // offset 0x152, size 0x8
        struct /* @anon21 */ {
            // total size: 0x8
            u16 code; // offset 0x0, size 0x2
            s16 koc;  // offset 0x2, size 0x2
            s16 ix;   // offset 0x4, size 0x2
            s16 pat;  // offset 0x6, size 0x2
        } cmr2;       // offset 0x15A, size 0x8
        struct /* @anon21 */ {
            // total size: 0x8
            u16 code;         // offset 0x0, size 0x2
            s16 koc;          // offset 0x2, size 0x2
            s16 ix;           // offset 0x4, size 0x2
            s16 pat;          // offset 0x6, size 0x2
        } cmr3;               // offset 0x162, size 0x8
        s16 cmwk[32];         // offset 0x16A, size 0x40
        u32 *char_table[12];  // offset 0x1AC, size 0x30
        u32 *se_random_table; // offset 0x1DC, size 0x4
        s16 *step_xy_table;   // offset 0x1E0, size 0x4
        s16 *move_xy_table;   // offset 0x1E4, size 0x4
        struct /* @anon49 */ {
            // total size: 0x10
            s16 parts_hos_x; // offset 0x0, size 0x2
            s16 parts_hos_y; // offset 0x2, size 0x2
            u8 parts_colmd;  // offset 0x4, size 0x1
            u8 parts_colcd;  // offset 0x5, size 0x1
            u8 parts_prio;   // offset 0x6, size 0x1
            u8 parts_flip;   // offset 0x7, size 0x1
            u8 parts_timer;  // offset 0x8, size 0x1
            u8 parts_disp;   // offset 0x9, size 0x1
            s16 parts_mts;   // offset 0xA, size 0x2
            u16 parts_nix;   // offset 0xC, size 0x2
            u16 parts_char;  // offset 0xE, size 0x2
        } *overlap_char_tbl; // offset 0x1E8, size 0x4
        struct /* @anon43 */ {
            // total size: 0x8
            s16 olc_ix[4]; // offset 0x0, size 0x8
        } *olc_ix_table;   // offset 0x1EC, size 0x4
        struct /* @anon43 */ {
            // total size: 0x8
            s16 olc_ix[4]; // offset 0x0, size 0x8
        } cg_olc;          // offset 0x1F0, size 0x8
        struct /* @anon58 */ {
            // total size: 0x8
            s16 catch_hos_x; // offset 0x0, size 0x2
            s16 catch_hos_y; // offset 0x2, size 0x2
            u8 catch_prio;   // offset 0x4, size 0x1
            u8 catch_flip;   // offset 0x5, size 0x1
            s16 catch_nix;   // offset 0x6, size 0x2
        } *rival_catch_tbl;  // offset 0x1F8, size 0x4
        struct /* @anon58 */ {
            // total size: 0x8
            s16 catch_hos_x; // offset 0x0, size 0x2
            s16 catch_hos_y; // offset 0x2, size 0x2
            u8 catch_prio;   // offset 0x4, size 0x1
            u8 catch_flip;   // offset 0x5, size 0x1
            s16 catch_nix;   // offset 0x6, size 0x2
        } *curr_rca;         // offset 0x1FC, size 0x4
        u32 *set_char_ad;    // offset 0x200, size 0x4
        s16 cg_ix;           // offset 0x204, size 0x2
        s16 now_koc;         // offset 0x206, size 0x2
        s16 char_index;      // offset 0x208, size 0x2
        s16 current_colcd;   // offset 0x20A, size 0x2
        s16 cgd_type;        // offset 0x20C, size 0x2
        u8 pat_status;       // offset 0x20E, size 0x1
        u8 kind_of_waza;     // offset 0x20F, size 0x1
        u8 hit_range;        // offset 0x210, size 0x1
        u8 total_paring;     // offset 0x211, size 0x1
        u8 total_att_set;    // offset 0x212, size 0x1
        u8 sp_tech_id;       // offset 0x213, size 0x1
        u8 cg_type;          // offset 0x214, size 0x1
        u8 cg_ctr;           // offset 0x215, size 0x1
        u16 cg_se;           // offset 0x216, size 0x2
        u16 cg_olc_ix;       // offset 0x218, size 0x2
        u16 cg_number;       // offset 0x21A, size 0x2
        u16 cg_hit_ix;       // offset 0x21C, size 0x2
        s16 cg_att_ix;       // offset 0x21E, size 0x2
        u8 cg_extdat;        // offset 0x220, size 0x1
        u8 cg_cancel;        // offset 0x221, size 0x1
        u8 cg_effect;        // offset 0x222, size 0x1
        u8 cg_eftype;        // offset 0x223, size 0x1
        u16 cg_zoom;         // offset 0x224, size 0x2
        u16 cg_rival;        // offset 0x226, size 0x2
        u16 cg_add_xy;       // offset 0x228, size 0x2
        u8 cg_next_ix;       // offset 0x22A, size 0x1
        u8 cg_status;        // offset 0x22B, size 0x1
        s16 cg_wca_ix;       // offset 0x22C, size 0x2
        s16 cg_jphos;        // offset 0x22E, size 0x2
        u16 cg_meoshi;       // offset 0x230, size 0x2
        u8 cg_prio;          // offset 0x232, size 0x1
        u8 cg_flip;          // offset 0x233, size 0x1
        u16 old_cgnum;       // offset 0x234, size 0x2
        s16 floor;           // offset 0x236, size 0x2
        u16 ccoff;           // offset 0x238, size 0x2
        s16 colcd;           // offset 0x23A, size 0x2
        s16 my_col_mode;     // offset 0x23C, size 0x2
        s16 my_col_code;     // offset 0x23E, size 0x2
        s16 my_priority;     // offset 0x240, size 0x2
        s16 my_family;       // offset 0x242, size 0x2
        s16 my_ext_pri;      // offset 0x244, size 0x2
        s16 my_bright_type;  // offset 0x246, size 0x2
        s16 my_bright_level; // offset 0x248, size 0x2
        s16 my_clear_level;  // offset 0x24A, size 0x2
        s16 my_mts;          // offset 0x24C, size 0x2
        s16 my_mr_flag;      // offset 0x24E, size 0x2
        struct /* @anon47 */ {
            // total size: 0x4
            struct /* @anon48 */ {
                // total size: 0x4
                s16 x;     // offset 0x0, size 0x2
                s16 y;     // offset 0x2, size 0x2
            } size;        // offset 0x0, size 0x4
        } my_mr;           // offset 0x250, size 0x4
        s16 my_trans_mode; // offset 0x254, size 0x2
        s16 my_roll_flag;  // offset 0x256, size 0x2
        struct /* @anon52 */ {
            // total size: 0x8
            s16 now;         // offset 0x0, size 0x2
            s16 add;         // offset 0x2, size 0x2
            s16 free;        // offset 0x4, size 0x2
            s16 old;         // offset 0x6, size 0x2
        } my_roll;           // offset 0x258, size 0x8
        s16 waku_work_index; // offset 0x260, size 0x2
        s16 olc_work_ix[4];  // offset 0x262, size 0x8
        struct /* @anon6 */ {
            // total size: 0x10
            u16 boix; // offset 0x0, size 0x2
            u16 bhix; // offset 0x2, size 0x2
            u16 haix; // offset 0x4, size 0x2
            union /* @anon10 */ {
                u16 full; // offset 0x0, size 0x2
                struct /* @anon12 */ {
                    // total size: 0x2
                    u8 bx; // offset 0x0, size 0x1
                    u8 mv; // offset 0x1, size 0x1
                } half;    // offset 0x0, size 0x2
            } mf;          // offset 0x6, size 0x2
            u16 caix;      // offset 0x8, size 0x2
            u16 cuix;      // offset 0xA, size 0x2
            u16 atix;      // offset 0xC, size 0x2
            u16 hoix;      // offset 0xE, size 0x2
        } *hit_ix_table;   // offset 0x26C, size 0x4
        struct /* @anon6 */ {
            // total size: 0x10
            u16 boix; // offset 0x0, size 0x2
            u16 bhix; // offset 0x2, size 0x2
            u16 haix; // offset 0x4, size 0x2
            union /* @anon10 */ {
                u16 full; // offset 0x0, size 0x2
                struct /* @anon12 */ {
                    // total size: 0x2
                    u8 bx; // offset 0x0, size 0x1
                    u8 mv; // offset 0x1, size 0x1
                } half;    // offset 0x0, size 0x2
            } mf;          // offset 0x6, size 0x2
            u16 caix;      // offset 0x8, size 0x2
            u16 cuix;      // offset 0xA, size 0x2
            u16 atix;      // offset 0xC, size 0x2
            u16 hoix;      // offset 0xE, size 0x2
        } cg_ja;           // offset 0x270, size 0x10
        struct /* @anon22 */ {
            // total size: 0x20
            s16 body_dm[4][4]; // offset 0x0, size 0x20
        } *body_adrs;          // offset 0x280, size 0x4
        struct /* @anon22 */ {
            // total size: 0x20
            s16 body_dm[4][4]; // offset 0x0, size 0x20
        } *h_bod;              // offset 0x284, size 0x4
        struct /* @anon26 */ {
            // total size: 0x20
            s16 hand_dm[4][4]; // offset 0x0, size 0x20
        } *hand_adrs;          // offset 0x288, size 0x4
        struct /* @anon26 */ {
            // total size: 0x20
            s16 hand_dm[4][4]; // offset 0x0, size 0x20
        } *h_han;              // offset 0x28C, size 0x4
        struct /* @anon26 */ {
            // total size: 0x20
            s16 hand_dm[4][4]; // offset 0x0, size 0x20
        } *dumm_adrs;          // offset 0x290, size 0x4
        struct /* @anon26 */ {
            // total size: 0x20
            s16 hand_dm[4][4]; // offset 0x0, size 0x20
        } *h_dumm;             // offset 0x294, size 0x4
        struct /* @anon36 */ {
            // total size: 0x8
            s16 cat_box[4]; // offset 0x0, size 0x8
        } *catch_adrs;      // offset 0x298, size 0x4
        struct /* @anon36 */ {
            // total size: 0x8
            s16 cat_box[4]; // offset 0x0, size 0x8
        } *h_cat;           // offset 0x29C, size 0x4
        struct /* @anon39 */ {
            // total size: 0x8
            s16 cau_box[4]; // offset 0x0, size 0x8
        } *caught_adrs;     // offset 0x2A0, size 0x4
        struct /* @anon39 */ {
            // total size: 0x8
            s16 cau_box[4]; // offset 0x0, size 0x8
        } *h_cau;           // offset 0x2A4, size 0x4
        struct /* @anon32 */ {
            // total size: 0x20
            s16 att_box[4][4]; // offset 0x0, size 0x20
        } *attack_adrs;        // offset 0x2A8, size 0x4
        struct /* @anon32 */ {
            // total size: 0x20
            s16 att_box[4][4]; // offset 0x0, size 0x20
        } *h_att;              // offset 0x2AC, size 0x4
        struct /* @anon32 */ {
            // total size: 0x20
            s16 att_box[4][4]; // offset 0x0, size 0x20
        } *h_eat;              // offset 0x2B0, size 0x4
        struct /* @anon42 */ {
            // total size: 0x8
            s16 hos_box[4]; // offset 0x0, size 0x8
        } *hosei_adrs;      // offset 0x2B4, size 0x4
        struct /* @anon42 */ {
            // total size: 0x8
            s16 hos_box[4]; // offset 0x0, size 0x8
        } *h_hos;           // offset 0x2B8, size 0x4
        struct /* @anon60 */ {
            // total size: 0x10
            u8 reaction; // offset 0x0, size 0x1
            u8 level;    // offset 0x1, size 0x1
            u8 mkh_ix;   // offset 0x2, size 0x1
            u8 but_ix;   // offset 0x3, size 0x1
            u8 dipsw;    // offset 0x4, size 0x1
            u8 guard;    // offset 0x5, size 0x1
            u8 dir;      // offset 0x6, size 0x1
            u8 free;     // offset 0x7, size 0x1
            u8 pow;      // offset 0x8, size 0x1
            u8 impact;   // offset 0x9, size 0x1
            u8 piyo;     // offset 0xA, size 0x1
            u8 ng_type;  // offset 0xB, size 0x1
            s8 hs_me;    // offset 0xC, size 0x1
            s8 hs_you;   // offset 0xD, size 0x1
            u8 hit_mark; // offset 0xE, size 0x1
            u8 dmg_mark; // offset 0xF, size 0x1
        } *att_ix_table; // offset 0x2BC, size 0x4
        struct /* @anon60 */ {
            // total size: 0x10
            u8 reaction;       // offset 0x0, size 0x1
            u8 level;          // offset 0x1, size 0x1
            u8 mkh_ix;         // offset 0x2, size 0x1
            u8 but_ix;         // offset 0x3, size 0x1
            u8 dipsw;          // offset 0x4, size 0x1
            u8 guard;          // offset 0x5, size 0x1
            u8 dir;            // offset 0x6, size 0x1
            u8 free;           // offset 0x7, size 0x1
            u8 pow;            // offset 0x8, size 0x1
            u8 impact;         // offset 0x9, size 0x1
            u8 piyo;           // offset 0xA, size 0x1
            u8 ng_type;        // offset 0xB, size 0x1
            s8 hs_me;          // offset 0xC, size 0x1
            s8 hs_you;         // offset 0xD, size 0x1
            u8 hit_mark;       // offset 0xE, size 0x1
            u8 dmg_mark;       // offset 0xF, size 0x1
        } att;                 // offset 0x2C0, size 0x10
        u16 zu_flag;           // offset 0x2D0, size 0x2
        u16 at_attribute;      // offset 0x2D2, size 0x2
        s16 kezuri_pow;        // offset 0x2D4, size 0x2
        u16 add_arts_point;    // offset 0x2D6, size 0x2
        u16 buttobi_type;      // offset 0x2D8, size 0x2
        u16 att_zuru;          // offset 0x2DA, size 0x2
        u16 at_ten_ix;         // offset 0x2DC, size 0x2
        s16 dir_atthit;        // offset 0x2DE, size 0x2
        s16 vs_id;             // offset 0x2E0, size 0x2
        u8 att_hit_ok;         // offset 0x2E2, size 0x1
        u8 meoshi_hit_flag;    // offset 0x2E3, size 0x1
        u16 at_koa;            // offset 0x2E4, size 0x2
        u8 paring_attack_flag; // offset 0x2E6, size 0x1
        s8 no_death_attack;    // offset 0x2E7, size 0x1
        u8 jump_att_flag;      // offset 0x2E8, size 0x1
        s8 shell_vs_refrect;   // offset 0x2E9, size 0x1
        s16 renew_attack;      // offset 0x2EA, size 0x2
        u16 attack_num;        // offset 0x2EC, size 0x2
        u16 uketa_att[4];      // offset 0x2EE, size 0x8
        union /* @anon16 */ {
            struct /* @anon18 */ {
                // total size: 0x2
                u8 player;     // offset 0x0, size 0x1
                u8 effect;     // offset 0x1, size 0x1
            } hit;             // offset 0x0, size 0x2
            u16 hit_flag;      // offset 0x0, size 0x2
        } hf;                  // offset 0x2F6, size 0x2
        s16 hit_mark_x;        // offset 0x2F8, size 0x2
        s16 hit_mark_y;        // offset 0x2FA, size 0x2
        s16 hit_mark_z;        // offset 0x2FC, size 0x2
        s16 kohm;              // offset 0x2FE, size 0x2
        u8 dm_fushin;          // offset 0x300, size 0x1
        s8 dm_weight;          // offset 0x301, size 0x1
        u16 dm_butt_type;      // offset 0x302, size 0x2
        u16 dm_zuru;           // offset 0x304, size 0x2
        u16 dm_attribute;      // offset 0x306, size 0x2
        s16 dm_guard_success;  // offset 0x308, size 0x2
        s16 dm_plnum;          // offset 0x30A, size 0x2
        s16 dm_attlv;          // offset 0x30C, size 0x2
        s16 dm_dir;            // offset 0x30E, size 0x2
        s8 dm_rl;              // offset 0x310, size 0x1
        u8 dm_impact;          // offset 0x311, size 0x1
        s16 dm_stop;           // offset 0x312, size 0x2
        s16 dm_quake;          // offset 0x314, size 0x2
        u16 dm_piyo;           // offset 0x316, size 0x2
        u16 dm_ten_ix;         // offset 0x318, size 0x2
        u16 dm_koa;            // offset 0x31A, size 0x2
        s16 dm_work_id;        // offset 0x31C, size 0x2
        u16 dm_arts_point;     // offset 0x31E, size 0x2
        u8 dm_jump_att_flag;   // offset 0x320, size 0x1
        u8 dm_free;            // offset 0x321, size 0x1
        s16 dm_count_up;       // offset 0x322, size 0x2
        s8 dm_nodeathattack;   // offset 0x324, size 0x1
        u8 dm_exdm_ix;         // offset 0x325, size 0x1
        u8 dm_dip;             // offset 0x326, size 0x1
        u8 dm_kind_of_waza;    // offset 0x327, size 0x1
        s16 attpow;            // offset 0x328, size 0x2
        s16 defpow;            // offset 0x32A, size 0x2
        u32 *my_effadrs;       // offset 0x32C, size 0x4
        s16 shell_ix[8];       // offset 0x330, size 0x10
        s16 hm_dm_side;        // offset 0x340, size 0x2
        s16 extra_col;         // offset 0x342, size 0x2
        s16 extra_col_2;       // offset 0x344, size 0x2
        s16 original_vitality; // offset 0x346, size 0x2
        u8 hit_work_id;        // offset 0x348, size 0x1
        u8 dmg_work_id;        // offset 0x349, size 0x1
        s8 K5_init_flag;       // offset 0x34A, size 0x1
        s8 K5_exec_ok;         // offset 0x34B, size 0x1
        u8 kow;                // offset 0x34C, size 0x1
        u8 swallow_no_effect;  // offset 0x34D, size 0x1
        s16 E3_work_index;     // offset 0x34E, size 0x2
        s16 E4_work_index;     // offset 0x350, size 0x2
        u8 kezurare_flag;      // offset 0x352, size 0x1
        u8 wrd_free[53];       // offset 0x353, size 0x35
    } *illusion_work;          // offset 0x3F4, size 0x4
    s16 image_setup_flag;      // offset 0x3F8, size 0x2
    s16 image_data_index;      // offset 0x3FA, size 0x2
    u8 caution_flag;           // offset 0x3FC, size 0x1
    u8 tc_1st_flag;            // offset 0x3FD, size 0x1
    struct /* @anon27 */ {
        // total size: 0xA8
        s16 total;             // offset 0x0, size 0x2
        s16 new_dm;            // offset 0x2, size 0x2
        s16 req_f;             // offset 0x4, size 0x2
        s16 old_r;             // offset 0x6, size 0x2
        s16 kind_of[10][4][2]; // offset 0x8, size 0xA0
    } *rp;                     // offset 0x400, size 0x4
    s16 bullet_hcnt;           // offset 0x404, size 0x2
    s16 bhcnt_timer;           // offset 0x406, size 0x2
    s8 cat_break_ok_timer;     // offset 0x408, size 0x1
    s8 cat_break_reserve;      // offset 0x409, size 0x1
    s8 hazusenai_flag;         // offset 0x40A, size 0x1
    s8 hurimukenai_flag;       // offset 0x40B, size 0x1
    u8 tk_success;             // offset 0x40C, size 0x1
    u8 resurrection_resv;      // offset 0x40D, size 0x1
    s16 tk_dageki;             // offset 0x40E, size 0x2
    s16 tk_nage;               // offset 0x410, size 0x2
    s16 tk_kizetsu;            // offset 0x412, size 0x2
    s16 tk_konjyou;            // offset 0x414, size 0x2
    s16 utk_dageki;            // offset 0x416, size 0x2
    s16 utk_nage;              // offset 0x418, size 0x2
    s16 utk_kizetsu;           // offset 0x41A, size 0x2
    u8 atemi_flag;             // offset 0x41C, size 0x1
    u8 atemi_point;            // offset 0x41D, size 0x1
    s16 dm_vital_backup;       // offset 0x41E, size 0x2
    u8 dm_refrect;             // offset 0x420, size 0x1
    u8 dm_vital_use;           // offset 0x421, size 0x1
    u8 exdm_ix;                // offset 0x422, size 0x1
    u8 meoshi_jump_flag;       // offset 0x423, size 0x1
    s16 cmd_request;           // offset 0x424, size 0x2
    s16 rl_save;               // offset 0x426, size 0x2
    u8 zettai_muteki_flag;     // offset 0x428, size 0x1
    u8 do_not_move;            // offset 0x429, size 0x1
    u16 just_sa_stop_timer;    // offset 0x42A, size 0x2
    s16 total_att_hit_ok;      // offset 0x42C, size 0x2
    u8 sa_healing;             // offset 0x42E, size 0x1
    u8 auto_guard;             // offset 0x42F, size 0x1
    u8 hsjp_ok;                // offset 0x430, size 0x1
    u8 high_jump_flag;         // offset 0x431, size 0x1
    s16 att_plus;              // offset 0x432, size 0x2
    s16 def_plus;              // offset 0x434, size 0x2
    s8 bs2_on_car;             // offset 0x436, size 0x1
    s8 bs2_area_car;           // offset 0x437, size 0x1
    s8 bs2_over_car;           // offset 0x438, size 0x1
    s8 bs2_area_car2;          // offset 0x439, size 0x1
    s8 bs2_over_car2;          // offset 0x43A, size 0x1
    u8 micchaku_wall_time;     // offset 0x43B, size 0x1
    u8 extra_jump;             // offset 0x43C, size 0x1
    u8 air_jump_ok_time;       // offset 0x43D, size 0x1
    s16 waku_ram_index;        // offset 0x43E, size 0x2
    u16 permited_koa;          // offset 0x440, size 0x2
    u8 ja_nmj_rno;             // offset 0x442, size 0x1
    u8 ja_nmj_cnt;             // offset 0x443, size 0x1
    u8 kind_of_blocking;       // offset 0x444, size 0x1
    u8 metamorphose;           // offset 0x445, size 0x1
    s16 metamor_index;         // offset 0x446, size 0x2
    u8 metamor_over;           // offset 0x448, size 0x1
    u8 gill_ccch_go;           // offset 0x449, size 0x1
    u8 renew_attchar;          // offset 0x44A, size 0x1
    s16 omop_vital_timer;      // offset 0x44C, size 0x2
    s16 sfwing_pos;            // offset 0x44E, size 0x2
    u8 init_E3_flag;           // offset 0x450, size 0x1
    u8 init_E4_flag;           // offset 0x451, size 0x1
    u16 pl09_dat_index;        // offset 0x452, size 0x2
    s16 reserv_add_y;          // offset 0x454, size 0x2
    u8 pt_free[20];            // offset 0x456, size 0x14
} PLW;

typedef struct {
    // total size: 0x470
    u32 VideoMode;              // offset 0x0, size 0x4
    u32 InterlaceMode;          // offset 0x4, size 0x4
    u32 DisplayMode;            // offset 0x8, size 0x4
    s32 DispWidth;              // offset 0xC, size 0x4
    s32 DispHeight;             // offset 0x10, size 0x4
    u32 MAGH;                   // offset 0x14, size 0x4
    u32 FrameBitDepth;          // offset 0x18, size 0x4
    u32 FrameBuffForm;          // offset 0x1C, size 0x4
    u32 FrameBuffPageX;         // offset 0x20, size 0x4
    u32 FrameBuffPageY;         // offset 0x24, size 0x4
    u32 FrameBuffAdrs0;         // offset 0x28, size 0x4
    u32 FrameBuffAdrs1;         // offset 0x2C, size 0x4
    u32 ZBuffBitDepth;          // offset 0x30, size 0x4
    u32 ZBuffForm;              // offset 0x34, size 0x4
    u32 ZBuffPageX;             // offset 0x38, size 0x4
    u32 ZBuffPageY;             // offset 0x3C, size 0x4
    u32 ZBuffAdrs;              // offset 0x40, size 0x4
    f32 ZBuffMax;               // offset 0x44, size 0x4
    u32 TextureStartAdrs;       // offset 0x48, size 0x4
    s32 Oddeven;                // offset 0x4C, size 0x4
    s32 Dbi;                    // offset 0x50, size 0x4
    s32 FrameCount;             // offset 0x54, size 0x4
    s32 FrameCountNext;         // offset 0x58, size 0x4
    s32 Irq_count;              // offset 0x5C, size 0x4
    s32 Db_change_enable;       // offset 0x60, size 0x4
    s8 pad64[0xC];              // offset 0x64, size 0xC
    sceGsDBuffDc Db;            // offset 0x70, size 0x330
    u32 FrameClearColor;        // offset 0x3A0, size 0x4
    s32 D2dOffsetX;             // offset 0x3A4, size 0x4
    s32 D2dOffsetY;             // offset 0x3A8, size 0x4
    s32 ScreenOffsetX;          // offset 0x3AC, size 0x4
    s32 ScreenOffsetY;          // offset 0x3B0, size 0x4
    s32 ScreenDispX;            // offset 0x3B4, size 0x4
    s32 ScreenDispY;            // offset 0x3B8, size 0x4
    s32 ScreenAdjustX;          // offset 0x3BC, size 0x4
    s32 ScreenAdjustY;          // offset 0x3C0, size 0x4
    sceDmaChan *DmaChan[10];    // offset 0x3C4, size 0x28
    s32 NowVu1Code;             // offset 0x3EC, size 0x4
    s32 NowVu1Size;             // offset 0x3F0, size 0x4
    s32 DrawDisable;            // offset 0x3F4, size 0x4
    u32 system_memory_start;    // offset 0x3F8, size 0x4
    s32 system_memory_size;     // offset 0x3FC, size 0x4
    u32 SystemStatus;           // offset 0x400, size 0x4
    s32 SystemIndex;            // offset 0x404, size 0x4
    u32 SystemTmpBuffStartAdrs; // offset 0x408, size 0x4
    u32 SystemTmpBuffEndAdrs;   // offset 0x40C, size 0x4
    u32 SystemTmpBuffNow;       // offset 0x410, size 0x4
    u32 SystemTmpBuffHandle[2]; // offset 0x414, size 0x8
    u64 RenderTESTStatus1;      // offset 0x420, size 0x4
    u64 RenderTESTStatus2;      // offset 0x428, size 0x4
    u64 RenderZBUFStatus1;      // offset 0x430, size 0x4
    u64 RenderZBUFStatus2;      // offset 0x438, size 0x4
    u64 RenderSCISSORStatus1;   // offset 0x440, size 0x4
    s32 RenderSCISSORValue1[4]; // offset 0x448, size 0x10
    u64 RenderSCISSORStatus2;   // offset 0x458, size 0x4
    s32 RenderSCISSORValue2[4]; // offset 0x460, size 0x10
} FLPS2State;

typedef struct {
    // total size: 0x3C
    u32 channel_id;             // offset 0x0, size 0x4
    u32 queue_size;             // offset 0x4, size 0x4
    s32 handleID;               // offset 0x8, size 0x4
    u32 dma_queue_handle[2];    // offset 0xC, size 0x8
    u32 queue_ctr[2];           // offset 0x14, size 0x8
    u32 queue_ptr0[2];          // offset 0x1C, size 0x8
    u32 queue_ptr1[2];          // offset 0x24, size 0x8
    u32 now_adrs;               // offset 0x2C, size 0x4
    u32 dma_normal_mode_status; // offset 0x30, size 0x4
    u32 old_queue_data;         // offset 0x34, size 0x4
    u32 old_endtag;             // offset 0x38, size 0x4
} FLPS2VIF1Control;

typedef union {
    __int128 I128;  // offset 0x0, size 0x10
    s64 I64[2];     // offset 0x0, size 0x10
    s32 I32[4];     // offset 0x0, size 0x10
    s16 I16[8];     // offset 0x0, size 0x10
    s8 I8[16];      // offset 0x0, size 0x10
    __int128 UI128; // offset 0x0, size 0x10
    u64 UI64[2];    // offset 0x0, size 0x10
    u32 UI32[4];    // offset 0x0, size 0x10
    u16 UI16[8];    // offset 0x0, size 0x10
    u8 UI8[16];     // offset 0x0, size 0x10
    f32 F32[4];     // offset 0x0, size 0x10
    f64 F64[2];     // offset 0x0, size 0x10
} Numeric;

typedef struct {
    // total size: 0xA0
    Numeric dmatag;     // offset 0x0, size 0x10
    Numeric giftag;     // offset 0x10, size 0x10
    Numeric frame_1;    // offset 0x20, size 0x10
    Numeric frame_2;    // offset 0x30, size 0x10
    Numeric zbuf_1;     // offset 0x40, size 0x10
    Numeric zbuf_2;     // offset 0x50, size 0x10
    Numeric xyoffset_1; // offset 0x60, size 0x10
    Numeric xyoffset_2; // offset 0x70, size 0x10
    Numeric dthe;       // offset 0x80, size 0x10
    Numeric colclamp;   // offset 0x90, size 0x10
} FLPS2DB;

typedef struct {
    // total size: 0x140
    Numeric dmatag;         // offset 0x0, size 0x10
    Numeric giftag;         // offset 0x10, size 0x10
    Numeric clr_fba;        // offset 0x20, size 0x10
    Numeric clr_scissor;    // offset 0x30, size 0x10
    Numeric clr_test;       // offset 0x40, size 0x10
    Numeric clr_prim;       // offset 0x50, size 0x10
    Numeric clr_rgbaq;      // offset 0x60, size 0x10
    Numeric clr_xyz2_0;     // offset 0x70, size 0x10
    Numeric clr_xyz2_1;     // offset 0x80, size 0x10
    Numeric acr_scissor_1;  // offset 0x90, size 0x10
    Numeric acr_scissor_2;  // offset 0xA0, size 0x10
    Numeric acr_test_1;     // offset 0xB0, size 0x10
    Numeric acr_test_2;     // offset 0xC0, size 0x10
    Numeric acr_zbuf_1;     // offset 0xD0, size 0x10
    Numeric acr_zbuf_2;     // offset 0xE0, size 0x10
    Numeric acr_fba_1;      // offset 0xF0, size 0x10
    Numeric acr_fba_2;      // offset 0x100, size 0x10
    Numeric acr_pabe;       // offset 0x110, size 0x10
    Numeric acr_prmodecont; // offset 0x120, size 0x10
    Numeric acr_dimx;       // offset 0x130, size 0x10
} FLPS2DrawStart;

enum _FLSETRENDERSTATE {
    FLRENDER_CULL = 0,
    FLRENDER_LIGHTING = 1,
    FLRENDER_SPECULAR = 2,
    FLRENDER_WRAP = 3,
    FLRENDER_TEXSTAGE0 = 4,
    FLRENDER_TEXSTAGE1 = 5,
    FLRENDER_TEXSTAGE2 = 6,
    FLRENDER_TEXSTAGE3 = 7,
    FLRENDER_TEXOPE0 = 8,
    FLRENDER_TEXOPE1 = 9,
    FLRENDER_TEXOPE2 = 10,
    FLRENDER_TEXOPE3 = 11,
    FLRENDER_SCISSOR = 12,
    FLRENDER_BLENDOPE = 13,
    FLRENDER_AMBIENT = 14,
    FLRENDER_FOGCOLOR = 15,
    FLRENDER_FOGSTART = 16,
    FLRENDER_FOGEND = 17,
    FLRENDER_FOGENABLE = 18,
    FLRENDER_FLIP = 19,
    FLRENDER_BACKCOLOR = 20,
    FLRENDER_MATERIAL = 21,
    FLRENDER_VIEW = 22,
    FLRENDER_PROJ = 23,
    FLRENDER_VIEWPORT = 24,
    FLRENDER_UVSCRMATRIX = 25,
    FLRENDER_WORLD0 = 26,
    FLRENDER_WORLD1 = 27,
    FLRENDER_WORLD2 = 28,
    FLRENDER_WORLD3 = 29,
    FLRENDER_WORLD4 = 30,
    FLRENDER_WORLD5 = 31,
    FLRENDER_WORLD6 = 32,
    FLRENDER_WORLD7 = 33,
    FLRENDER_WORLD8 = 34,
    FLRENDER_WORLD9 = 35,
    FLRENDER_WORLD10 = 36,
    FLRENDER_WORLD11 = 37,
    FLRENDER_WORLD12 = 38,
    FLRENDER_WORLD13 = 39,
    FLRENDER_WORLD14 = 40,
    FLRENDER_WORLD15 = 41,
    FLRENDER_WORLD16 = 42,
    FLRENDER_WORLD17 = 43,
    FLRENDER_WORLD18 = 44,
    FLRENDER_WORLD19 = 45,
    FLRENDER_WORLD20 = 46,
    FLRENDER_WORLD21 = 47,
    FLRENDER_WORLD22 = 48,
    FLRENDER_WORLD23 = 49,
    FLRENDER_WORLD24 = 50,
    FLRENDER_WORLD25 = 51,
    FLRENDER_WORLD26 = 52,
    FLRENDER_WORLD27 = 53,
    FLRENDER_WORLD28 = 54,
    FLRENDER_WORLD29 = 55,
    FLRENDER_WORLD30 = 56,
    FLRENDER_WORLD31 = 57,
    FLRENDER_MATERIAL0 = 58,
    FLRENDER_MATERIAL1 = 59,
    FLRENDER_MATERIAL2 = 60,
    FLRENDER_MATERIAL3 = 61,
    FLRENDER_MATERIAL4 = 62,
    FLRENDER_MATERIAL5 = 63,
    FLRENDER_MATERIAL6 = 64,
    FLRENDER_MATERIAL7 = 65,
    FLRENDER_MATERIAL8 = 66,
    FLRENDER_MATERIAL9 = 67,
    FLRENDER_MATERIAL10 = 68,
    FLRENDER_MATERIAL11 = 69,
    FLRENDER_MATERIAL12 = 70,
    FLRENDER_MATERIAL13 = 71,
    FLRENDER_MATERIAL14 = 72,
    FLRENDER_MATERIAL15 = 73,
    FLRENDER_MATERIAL16 = 74,
    FLRENDER_MATERIAL17 = 75,
    FLRENDER_MATERIAL18 = 76,
    FLRENDER_MATERIAL19 = 77,
    FLRENDER_MATERIAL20 = 78,
    FLRENDER_MATERIAL21 = 79,
    FLRENDER_MATERIAL22 = 80,
    FLRENDER_MATERIAL23 = 81,
    FLRENDER_MATERIAL24 = 82,
    FLRENDER_MATERIAL25 = 83,
    FLRENDER_MATERIAL26 = 84,
    FLRENDER_MATERIAL27 = 85,
    FLRENDER_MATERIAL28 = 86,
    FLRENDER_MATERIAL29 = 87,
    FLRENDER_MATERIAL30 = 88,
    FLRENDER_MATERIAL31 = 89,
    FLRENDER_LIGHT0 = 90,
    FLRENDER_LIGHT1 = 91,
    FLRENDER_LIGHT2 = 92,
    FLRENDER_SHADER = 93,
    FLRENDER_ALPHABLENDMODE = 94,
    FLRENDER_ALPHATEST = 95,
    FLRENDER_ALPHAREF = 96,
    FLRENDER_ALPHABLENDENABLE = 97,
    FLRENDER_UVSCROLL = 98,
    FLRENDER_TEXTUREFILTER = 99,
    FLRENDER_TEXTUREADDRESSING = 100,
    FLRENDER_RENDERTARGET = 101,
    FLRENDER_FADECOLORENABLE = 102,
    FLRENDER_FADECOLOR = 103,
    FLRENDER_MIPMAPBIAS = 104,
    FLRENDER_MIPMAPARG1 = 105,
    FLRENDER_MIPMAPARG2 = 106,
    FLRENDER_MIPMAPFILTER = 107,
    FLRENDER_ZWRITE = 108,
    FLRENDER_ZOPE = 109,
};

struct _MEMMAN_CELL {
    // total size: 0xC
    struct _MEMMAN_CELL *prev; // offset 0x0, size 0x4
    struct _MEMMAN_CELL *next; // offset 0x4, size 0x4
    s32 size;                  // offset 0x8, size 0x4
};

typedef struct {
    // total size: 0x2C
    u8 *memHead;                   // offset 0x0, size 0x4
    s32 memSize;                   // offset 0x4, size 0x4
    u32 ownNumber;                 // offset 0x8, size 0x4
    s32 ownUnit;                   // offset 0xC, size 0x4
    s32 remainder;                 // offset 0x10, size 0x4
    s32 remainderMin;              // offset 0x14, size 0x4
    struct _MEMMAN_CELL *cell_1st; // offset 0x18, size 0x4
    struct _MEMMAN_CELL *cell_fin; // offset 0x1C, size 0x4
    u8 *oriHead;                   // offset 0x20, size 0x4
    s32 oriSize;                   // offset 0x24, size 0x4
    s32 debIndex;                  // offset 0x28, size 0x4
} _MEMMAN_OBJ;

typedef union {
    s32 cal; // offset 0x0, size 0x4
    struct {
        // total size: 0x4
        s16 low; // offset 0x0, size 0x2
        s16 pos; // offset 0x2, size 0x2
    } disp;      // offset 0x0, size 0x4
} XY;

typedef struct {
    // total size: 0x90
    s8 be_flag;        // offset 0x0, size 0x1
    s8 disp_flag;      // offset 0x1, size 0x1
    s16 fam_no;        // offset 0x2, size 0x2
    s16 r_no_0;        // offset 0x4, size 0x2
    s16 r_no_1;        // offset 0x6, size 0x2
    s16 r_no_2;        // offset 0x8, size 0x2
    s16 position_x;    // offset 0xA, size 0x2
    s16 position_y;    // offset 0xC, size 0x2
    s32 speed_x;       // offset 0x10, size 0x4
    s32 speed_y;       // offset 0x14, size 0x4
    XY xy[2];          // offset 0x18, size 0x8
    XY wxy[2];         // offset 0x20, size 0x8
    u16 *bg_address;   // offset 0x28, size 0x4
    u16 *suzi_adrs;    // offset 0x2C, size 0x4
    s16 old_pos_x;     // offset 0x30, size 0x2
    s32 zuubun;        // offset 0x34, size 0x4
    s16 no_suzi_line;  // offset 0x38, size 0x2
    u16 *start_suzi;   // offset 0x3C, size 0x4
    s16 u_line;        // offset 0x40, size 0x2
    s16 d_line;        // offset 0x42, size 0x2
    s16 bg_adrs_c_no;  // offset 0x44, size 0x2
    s16 suzi_c_no;     // offset 0x46, size 0x2
    s16 pos_x_work;    // offset 0x48, size 0x2
    s16 pos_y_work;    // offset 0x4A, size 0x2
    s8 rewrite_flag;   // offset 0x4C, size 0x1
    s8 suzi_base_flag; // offset 0x4D, size 0x1
    XY hos_xy[2];      // offset 0x50, size 0x8
    XY chase_xy[2];    // offset 0x58, size 0x8
    s16 free;          // offset 0x60, size 0x2
    s16 frame_deff;    // offset 0x62, size 0x2
    s16 r_limit;       // offset 0x64, size 0x2
    s16 r_limit2;      // offset 0x66, size 0x2
    s16 l_limit;       // offset 0x68, size 0x2
    s16 l_limit2;      // offset 0x6A, size 0x2
    s16 y_limit;       // offset 0x6C, size 0x2
    s16 y_limit2;      // offset 0x6E, size 0x2
    u16 *suzi_adrs2;   // offset 0x70, size 0x4
    u16 *start_suzi2;  // offset 0x74, size 0x4
    s16 suzi_c_no2;    // offset 0x78, size 0x2
    s32 max_x_limit;   // offset 0x7C, size 0x4
    s16 *deff_rl;      // offset 0x80, size 0x4
    s16 *deff_plus;    // offset 0x84, size 0x4
    s16 *deff_minus;   // offset 0x88, size 0x4
    s16 abs_x;         // offset 0x8C, size 0x2
    s16 abs_y;         // offset 0x8E, size 0x2
} BGW;

typedef struct {
    // total size: 0x428
    s8 bg_routine;     // offset 0x0, size 0x1
    s8 bg_r_1;         // offset 0x1, size 0x1
    s8 bg_r_2;         // offset 0x2, size 0x1
    s8 stage;          // offset 0x3, size 0x1
    s8 area;           // offset 0x4, size 0x1
    s8 compel_flag;    // offset 0x5, size 0x1
    s32 scroll_cg_adr; // offset 0x8, size 0x4
    s32 ake_cg_adr;    // offset 0xC, size 0x4
    u8 scno;           // offset 0x10, size 0x1
    u8 scrno;          // offset 0x11, size 0x1
    s16 bg2_sp_x;      // offset 0x12, size 0x2
    s16 bg2_sp_y;      // offset 0x14, size 0x2
    s16 scr_stop;      // offset 0x16, size 0x2
    s8 frame_flag;     // offset 0x18, size 0x1
    s8 chase_flag;     // offset 0x19, size 0x1
    s8 old_chase_flag; // offset 0x1A, size 0x1
    s8 old_frame_flag; // offset 0x1B, size 0x1
    s16 pos_offset;    // offset 0x1C, size 0x2
    s16 quake_x_index; // offset 0x1E, size 0x2
    s16 quake_y_index; // offset 0x20, size 0x2
    s16 bg_f_x;        // offset 0x22, size 0x2
    s16 bg_f_y;        // offset 0x24, size 0x2
    s16 bg2_sp_x2;     // offset 0x26, size 0x2
    s16 bg2_sp_y2;     // offset 0x28, size 0x2
    s16 frame_deff;    // offset 0x2A, size 0x2
    s16 center_x;      // offset 0x2C, size 0x2
    s16 center_y;      // offset 0x2E, size 0x2
    s16 bg_index;      // offset 0x30, size 0x2
    s8 frame_vol;      // offset 0x32, size 0x1
    s16 max_x;         // offset 0x34, size 0x2
    u8 bg_opaque;      // offset 0x36, size 0x1
    BGW bgw[7];        // offset 0x38, size 0x3F0
} BG;

typedef union {
    s32 sp; // offset 0x0, size 0x4
    struct /* @anon17 */ {
        // total size: 0x4
        s16 l; // offset 0x0, size 0x2
        s16 h; // offset 0x2, size 0x2
    } real;    // offset 0x0, size 0x4
} BG_MVXY_UNK;

typedef struct {
    // total size: 0x18
    BG_MVXY_UNK a[2]; // offset 0x0, size 0x8
    BG_MVXY_UNK d[2]; // offset 0x8, size 0x8
    s16 kop[2];       // offset 0x10, size 0x4
    u16 index;        // offset 0x14, size 0x2
} BG_MVXY;

typedef struct {
    // total size: 0x18
    u8 *memoryblock;   // offset 0x0, size 0x4
    u8 *baseandcap[2]; // offset 0x4, size 0x8
    u8 *frame[2];      // offset 0xC, size 0x8
    s32 align;         // offset 0x14, size 0x4
} FL_FMS;

typedef struct {
    // total size: 0x10
    u8 *ptr;   // offset 0x0, size 0x4
    u32 len;   // offset 0x4, size 0x4
    u16 align; // offset 0x8, size 0x2
    u16 id;    // offset 0xA, size 0x2
    u16 prev;  // offset 0xC, size 0x2
    u16 next;  // offset 0xE, size 0x2
} MEM_BLOCK;

typedef struct {
    // total size: 0x28
    s32 cnt;          // offset 0x0, size 0x4
    s32 memsize;      // offset 0x4, size 0x4
    MEM_BLOCK *block; // offset 0x8, size 0x4
    s32 direction;    // offset 0xC, size 0x4
    u8 *memnow;       // offset 0x10, size 0x4
    u8 *memptr;       // offset 0x14, size 0x4
    s32 memalign;     // offset 0x18, size 0x4
    s32 used_size;    // offset 0x1C, size 0x4
    s32 tmemsize;     // offset 0x20, size 0x4
    u32 blocklist;    // offset 0x24, size 0x4
} MEM_MGR;

typedef union /* @anon0 */ {
    u32 etc; // offset 0x0, size 0x4
    struct /* @anon1 */ {
        // total size: 0x4
        u8 vib;  // offset 0x0, size 0x1
        u8 etc0; // offset 0x1, size 0x1
        u8 etc1; // offset 0x2, size 0x1
        u8 etc2; // offset 0x3, size 0x1
    } gc;        // offset 0x0, size 0x4
    struct /* @anon4 */ {
        // total size: 0x4
        u8 port; // offset 0x0, size 0x1
        u8 slot; // offset 0x1, size 0x1
        u8 vib;  // offset 0x2, size 0x1
        u8 etc;  // offset 0x3, size 0x1
    } ps;        // offset 0x0, size 0x4
    struct /* @anon6 */ {
        // total size: 0x4
        u8 socket1; // offset 0x0, size 0x1
        u8 socket2; // offset 0x1, size 0x1
        u16 etc;    // offset 0x2, size 0x2
    } dc;           // offset 0x0, size 0x4
    struct /* @anon8 */ {
        // total size: 0x4
        void *handle; // offset 0x0, size 0x4
    } xbox;           // offset 0x0, size 0x4
} PAD_CONN;

typedef struct {
    // total size: 0x10
    u8 pow[16]; // offset 0x0, size 0x10
} PAD_ANSHOT;

typedef struct {
    // total size: 0x88
    u8 state;           // offset 0x0, size 0x1
    u8 anstate;         // offset 0x1, size 0x1
    u16 kind;           // offset 0x2, size 0x2
    PAD_CONN conn;      // offset 0x4, size 0x4
    u32 sw;             // offset 0x8, size 0x4
    u32 sw_old;         // offset 0xC, size 0x4
    u32 sw_new;         // offset 0x10, size 0x4
    u32 sw_off;         // offset 0x14, size 0x4
    u32 sw_chg;         // offset 0x18, size 0x4
    PAD_ANSHOT anshot;  // offset 0x1C, size 0x10
    PAD_STICK stick[2]; // offset 0x2C, size 0x18
    u32 sw_repeat;      // offset 0x44, size 0x4
    union /* @anon9 */ {
        u16 work; // offset 0x0, size 0x2
        struct /* @anon10 */ {
            // total size: 0x2
            u8 press; // offset 0x0, size 0x1
            u8 sw_up; // offset 0x1, size 0x1
        } ctr;        // offset 0x0, size 0x2
    } rpsw[32];       // offset 0x48, size 0x40
} FLPAD;

typedef struct {
    // total size: 0x34
    u8 state;           // offset 0x0, size 0x1
    u8 anstate;         // offset 0x1, size 0x1
    u16 kind;           // offset 0x2, size 0x2
    PAD_CONN conn;      // offset 0x4, size 0x4
    u32 sw;             // offset 0x8, size 0x4
    PAD_ANSHOT anshot;  // offset 0xC, size 0x10
    PAD_STICK stick[2]; // offset 0x1C, size 0x18
} TARPAD;

typedef struct {
    // total size: 0x2C
    u8 conf_sw[32]; // offset 0x0, size 0x20
    u8 flip_lever;  // offset 0x20, size 0x1
    u8 flip_ast1;   // offset 0x21, size 0x1
    u8 flip_ast2;   // offset 0x22, size 0x1
    u8 free;        // offset 0x23, size 0x1
    s16 abut_on;    // offset 0x24, size 0x2
    s16 ast1_on;    // offset 0x26, size 0x2
    s16 ast2_on;    // offset 0x28, size 0x2
    u16 free2;      // offset 0x2A, size 0x2
} FLPAD_CONFIG;

typedef struct {
    // total size: 0xC
    u8 order;    // offset 0x0, size 0x1
    u8 kind_req; // offset 0x1, size 0x1
    u8 kind_cnt; // offset 0x2, size 0x1
    u8 request;  // offset 0x3, size 0x1
    u8 contents; // offset 0x4, size 0x1
    u8 timer;    // offset 0x5, size 0x1
    s16 pos_x;   // offset 0x6, size 0x2
    s16 pos_y;   // offset 0x8, size 0x2
    s16 pos_z;   // offset 0xA, size 0x2
} MessageData;

typedef struct {
    // total size: 0x48
    s8 contents[10][7]; // offset 0x0, size 0x46
    u16 sum;            // offset 0x46, size 0x2
} SystemDir;

struct _SAVE_W {
    // total size: 0x208
    struct {
        // total size: 0xC
        u8 Shot[8];      // offset 0x0, size 0x8
        u8 Vibration;    // offset 0x8, size 0x1
        u8 free[3];      // offset 0x9, size 0x3
    } Pad_Infor[2];      // offset 0x0, size 0x18
    u8 Difficulty;       // offset 0x18, size 0x1
    s8 Time_Limit;       // offset 0x19, size 0x1
    u8 Battle_Number[2]; // offset 0x1A, size 0x2
    u8 Damage_Level;     // offset 0x1C, size 0x1
    u8 Handicap;         // offset 0x1D, size 0x1
    u8 Partner_Type[2];  // offset 0x1E, size 0x2
    s8 Adjust_X;         // offset 0x20, size 0x1
    s8 Adjust_Y;         // offset 0x21, size 0x1
    u8 Screen_Size;      // offset 0x22, size 0x1
    u8 Screen_Mode;      // offset 0x23, size 0x1
    u8 GuardCheck;       // offset 0x24, size 0x1
    u8 Auto_Save;        // offset 0x25, size 0x1
    u8 AnalogStick;      // offset 0x26, size 0x1
    u8 BgmType;          // offset 0x27, size 0x1
    u8 SoundMode;        // offset 0x28, size 0x1
    u8 BGM_Level;        // offset 0x29, size 0x1
    u8 SE_Level;         // offset 0x2A, size 0x1
    u8 Extra_Option;     // offset 0x2B, size 0x1
    u8 PL_Color[2][20];  // offset 0x2C, size 0x28
    struct {
        // total size: 0x20
        s8 contents[4][8]; // offset 0x0, size 0x20
    } extra_option;        // offset 0x54, size 0x20
    struct {
        // total size: 0x14
        u8 name[3];      // offset 0x0, size 0x3
        u16 player;      // offset 0x4, size 0x2
        u32 score;       // offset 0x8, size 0x4
        s8 cpu_grade;    // offset 0xC, size 0x1
        s8 grade;        // offset 0xD, size 0x1
        u16 wins;        // offset 0xE, size 0x2
        u8 player_color; // offset 0x10, size 0x1
        u8 all_clear;    // offset 0x11, size 0x1
    } Ranking[20];       // offset 0x74, size 0x190
    u32 sum;             // offset 0x204, size 0x4
};

typedef struct {
    // total size: 0x8
    u8 ***msgAdr; // offset 0x0, size 0x4
    s8 *msgNum;   // offset 0x4, size 0x4
} MessageTable;

// .text

void mflInit(void *mem_ptr, s32 memsize, s32 memalign);                     // Range: 0x115FB0 -> 0x115FFC
int fmsInitialize(FL_FMS *lp, void *memory_ptr, s32 memsize, s32 memalign); // Range: 0x115D90 -> 0x115E80

void plmemInit(MEM_MGR *memmgr, MEM_BLOCK *block, s32 count, void *mem_ptr, s32 memsize, s32 memalign,
               s32 direction);                               // Range: 0x116180 -> 0x11629C
u32 plmemRegister(MEM_MGR *memmgr, s32 len);                 // Range: 0x1162A0 -> 0x1162D8
u32 plmemRegisterAlign(MEM_MGR *memmgr, s32 len, s32 align); // Range: 0x1162E0 -> 0x1164B4
u32 plmemRegisterS(MEM_MGR *memmgr, s32 len);                // Range: 0x1164C0 -> 0x116980
void *plmemTemporaryUse(MEM_MGR *memmgr, s32 len);           // Range: 0x116980 -> 0x116AAC
void *plmemRetrieve(MEM_MGR *memmgr, u32 handle);            // Range: 0x116AB0 -> 0x116B20
s32 plmemRelease(MEM_MGR *memmgr, u32 handle);               // Range: 0x116B20 -> 0x116BFC
void *plmemCompact(MEM_MGR *memmgr);                         // Range: 0x116C00 -> 0x116E9C
u32 plmemGetSpace(MEM_MGR *memmgr);                          // Range: 0x116EA0 -> 0x116EC8
u32 plmemGetFreeSpace(MEM_MGR *memmgr);                      // Range: 0x116ED0 -> 0x116F5C

s32 plReport(char *format);                  // Range: 0x11B310 -> 0x11B3AC
void plMemset(void *dst, u32 pat, s32 size); // Range: 0x11B3B0 -> 0x11B41C

void setup_pos_remake_key();        // Range: 0x11C0C0 -> 0x11C0D0
void appViewSetItems(VPRM *prm);    // Range: 0x11C0D0 -> 0x11C118
void appViewGetItems(VPRM *prm);    // Range: 0x11C120 -> 0x11C168
void appViewMatrix();               // Range: 0x11C170 -> 0x11C1CC
void render_start();                // Range: 0x11C1D0 -> 0x11C1F0
void render_end();                  // Range: 0x11C1F0 -> 0x11C210
void initRenderState(s32 flag);     // Range: 0x11C210 -> 0x11C328
void setBackGroundColor(u32 color); // Range: 0x11C4D0 -> 0x11C4FC
void Setup_Disp_Size();             // Range: 0x11BFF0 -> 0x11C0B4

void Scrn_Renew(); // Range: 0x170BE0 -> 0x170BF0
void Irl_Family(); // Range: 0x170BF0 -> 0x170CD0
void Irl_Scrn();   // Range: 0x170CD0 -> 0x170E9C

void bg_etc_write(s16 type); // Range: 0x175920 -> 0x175FC0

void palCreateGhost();                                  // Range: 0x19F8D0 -> 0x19FB50
void njdp2d_init();                                     // Range: 0x1C0330 -> 0x1C034C
void njdp2d_draw();                                     // Range: 0x1C0350 -> 0x1C0568
void njdp2d_sort(f32 *pos, f32 pri, u32 col, s32 flag); // Range: 0x1C0570 -> 0x1C0A0C

s32 effect_04_init(s16 Death_Type, s16 cg_type, s16 sync_bg, s16 priority);      // Range: 0x1C56A0 -> 0x1C5818
s32 effect_45_init(u8 id, s16 sync_bg, s16 master_player);                       // Range: 0x1E30D0 -> 0x1E3228
s32 effect_49_init(s16 vital_new);                                               // Range: 0x1E52B0 -> 0x1E54D8
s32 effect_57_init(s16 dir_old, s16 ID, s16 Target_BG, s16 char_ix, s16 option); // Range: 0x1E85B0 -> 0x1E8740
s32 effect_58_init(s16 id, s16 time0, s16 option);                               // Range: 0x1E97D0 -> 0x1E98A0
s32 effect_61_init(s16 master, u8 dir_old, s16 sync_bg, s16 master_player, s16 char_ix, s16 cursor_index,
                   u16 letter_type); // Range: 0x1EB350 -> 0x1EB68C
s32 effect_64_init(u8 dir_old, s16 sync_bg, s16 master_player, s16 letter_type, s16 cursor_index, u16 char_offset,
                   s16 pos_index, s16 convert_id, s16 convert_id2); // Range: 0x1EC830 -> 0x1EC990
s32 effect_66_init(s16 order_index, s16 id, s16 master_player, s16 target_bg, s16 char_ix, s16 char_ix2,
                   s16 option);                                             // Range: 0x1EDB60 -> 0x1EDEA4
s32 effect_76_init(s16 dir_old);                                            // Range: 0x1F2670 -> 0x1F27A0
s32 effect_95_init(s16 vital_new);                                          // Range: 0x1FCFD0 -> 0x1FD218
s32 effect_A9_init(s16 Char_Index, s16 Option, s16 Pos_Index, s16 Option2); // Range: 0x201A80 -> 0x201C78
// DWARF says WIN_PL_NO is s8, but decompilation suggests it's at least s16
s32 effect_B8_init(s16 WIN_PL_NO, s16 timer); // Range: 0x205500 -> 0x2056B8
void disp_effect_work();                      // Range: 0x21AD30 -> 0x21AED8
s32 effect_L1_init(s16 flag);                 // Range: 0x232820 -> 0x2328E8

void Entry_Task();                               // Range: 0x24B5C0 -> 0x24B708
s32 Setup_Directory_Record_Data();               // Range: 0x254330 -> 0x2543CC
void Push_LDREQ_Queue_Player(s16 id, s16 ix);    // Range: 0x254CC0 -> 0x254EB0
void grade_check_work_1st_init(s16 ix, s16 ix2); // Range: 0x255B90 -> 0x255D78
void Init_Task(struct _TASK *task_ptr);          // Range: 0x266080 -> 0x2660D4
void keyConvert();                               // Range: 0x266A90 -> 0x267118
void Purge_mmtm_area(s16 ix);                    // Range: 0x280BE0 -> 0x280C24
void Make_texcash_of_list(s16 ix);               // Range: 0x280D90 -> 0x280E48
void appSetupBasePriority();                     // Range: 0x286180 -> 0x2861F4
void appSetupTempPriority();                     // Range: 0x286200 -> 0x286264
void seqsInitialize(void *adrs);                 // Range: 0x286300 -> 0x286350
void seqsBeforeProcess();                        // Range: 0x286370 -> 0x2863B4
void seqsAfterProcess();                         // Range: 0x2863C0 -> 0x2865E4
void pulpul_stop();                              // Range: 0x37A760 -> 0x37A790
void disp_ramcnt_free_area();                    // Range: 0x37BB90 -> 0x37BC58
void Init_ram_control_work(u8 *adrs, s32 size);  // Range: 0x37BC60 -> 0x37BDF8

u8 nowSoftReset(); // Range: 0x37EC90 -> 0x37ECA8

void Saver_Task(struct _TASK *task_ptr); // Range: 0x37F1B0 -> 0x37F210

void FadeInit();                            // Range: 0x3834D0 -> 0x3834E0
s32 FadeOut(u8 type, u8 step, u8 priority); // Range: 0x3834E0 -> 0x3836D4
s32 FadeIn(u8 type, u8 step, u8 priority);  // Range: 0x3836E0 -> 0x3838DC

// sc_sub.c
void dispButtonImage2(s32 px, s32 py, s32 pz, s32 sx, s32 sy, s32 cl, s32 ix); // Range: 0x388AA0 -> 0x388D94

// SE.c
void BGM_Request(s16 Code); // Range: 0x3891A0 -> 0x3891CC

// Sound3rd.c
void Init_sound_system();    // Range: 0x3963A0 -> 0x396438
void sndInitialLoad();       // Range: 0x3964D0 -> 0x396524
void checkAdxFileLoaded();   // Range: 0x396560 -> 0x396654
void Exit_sound_system();    // Range: 0x396660 -> 0x3966D8
void Init_bgm_work();        // Range: 0x3966E0 -> 0x396718
void sound_all_off();        // Range: 0x396720 -> 0x396748
void BGM_Server();           // Range: 0x396B30 -> 0x3977D8
void SsBgmFadeOut(u16 time); // Range: 0x398290 -> 0x398304
void SE_cursor_move();       // Range: 0x3983F0 -> 0x398414
void SE_selected();          // Range: 0x398420 -> 0x398444
void SE_dir_cursor_move();   // Range: 0x398450 -> 0x398474
void SE_dir_selected();      // Range: 0x398480 -> 0x3984A4

// SYS_sub.c
void Switch_Screen_Init();                         // Range: 0x3A1C50 -> 0x3A1C98
s32 Switch_Screen(u8 Wipe_Type);                   // Range: 0x3A1CA0 -> 0x3A1D08
s32 Switch_Screen_Revival(u8 Wipe_Type);           // Range: 0x3A1D10 -> 0x3A1D78
void Clear_Personal_Data(s16 PL_id);               // Range: 0x3A21C0 -> 0x3A2744
void Clear_Flash_No();                             // Range: 0x3A2910 -> 0x3A2954
s32 Cut_Cut_Cut();                                 // Range: 0x3A2960 -> 0x3A29F0
void Copy_Check_w();                               // Range: 0x3A3E40 -> 0x3A3FA8
s32 Check_Change_Contents();                       // Range: 0x3A4080 -> 0x3A4410
void Setup_Training_Difficulty();                  // Range: 0x3A4620 -> 0x3A4720
void Setup_BG(s16 BG_INDEX, s16 X, s16 Y);         // Range: 0x3A4720 -> 0x3A48C4
void Setup_Virtual_BG(s16 BG_INDEX, s16 X, s16 Y); // Range: 0x3A48D0 -> 0x3A4A58
void System_all_clear_Level_B();                   // Range: 0x3A4F20 -> 0x3A4F48
s32 Cut_Cut_Loser();                               // Range: 0x3A5070 -> 0x3A50E0
void Check_Replay_Status(s16 PL_id, u8 Status);    // Range: 0x3A58D0 -> 0x3A5A30
s16 Check_SysDir_Page();                           // Range: 0x3A6060 -> 0x3A6174
void All_Clear_Suicide();                          // Range: 0x3A85C0 -> 0x3A865C

// texgroup.c
void checkSelObjFileLoaded();                                  // Range: 0x3B1000 -> 0x3B10F8
int load_any_texture_patnum(u16 patnum, u8 kokey, u8 _unused); // Range: 0x3B1320 -> 0x3B136C

// zlibApp.c
void zlib_Initialize(void *tempAdrs, s32 tempSize); // Range: 0x3B76E0 -> 0x3B776C

// Debug.c
s32 Check_Exit_Check(); // Range: 0x3BF690 -> 0x3BF6E0

// MemMan.c
void mmSystemInitialize(); // Range: 0x3C0080 -> 0x3C008C
void mmHeapInitialize(_MEMMAN_OBJ *mmobj, u8 *adrs, s32 size, s32 unit,
                      s8 *format);                   // Range: 0x3C0090 -> 0x3C020C
u8 *mmAlloc(_MEMMAN_OBJ *mmobj, s32 size, s32 flag); // Range: 0x3C02D0 -> 0x3C037C
void mmFree(_MEMMAN_OBJ *mmobj, u8 *adrs);           // Range: 0x3C0560 -> 0x3C05D8

// PPGFile.c
void ppg_Initialize(void *lcmAdrs, s32 lcmSize); // Range: 0x3C05E0 -> 0x3C0650
void ppgMakeConvTableTexDC();                    // Range: 0x3C3620 -> 0x3C3768

void CP3toPS2Draw();      // Range: 0x3C64D0 -> 0x3C6D8C
void flmwVSyncCallback(); // Range: 0x3C6D90 -> 0x3C6DB4
void flmwFlip();          // Range: 0x3C6E00 -> 0x3C6ED8
void flAdxModuleInit();   // Range: 0x3E51D0 -> 0x3E521C
void njUserInit();        // Range: 0x3E5BA0 -> 0x3E5E64

s32 flPS2InitRenderState();                                                         // Range: 0x3EEA20 -> 0x3EEC4C
s32 flSetRenderState(enum _FLSETRENDERSTATE func, u32 value);                       // Range: 0x3EEC50 -> 0x3EFDD8
void flAdjustScreen(s32 x, s32 y);                                                  // Range: 0x3F2230 -> 0x3F2268
s32 flSetDebugMode(u32 flag);                                                       // Range: 0x3F2280 -> 0x3F22A0
void flPS2DebugInit();                                                              // Range: 0x3F2340 -> 0x3F242C
void flPS2DebugStrDisp();                                                           // Range: 0x3F2450 -> 0x3F2B40
s32 flPrintL(s32 posi_x, s32 posi_y, s8 *format);                                   // Range: 0x3F2B40 -> 0x3F2D08
s32 flPrintColor(u32 col);                                                          // Range: 0x3F2D10 -> 0x3F2E04
void flPS2DispSystemInfo(s32 x, s32 y);                                             // Range: 0x3F2E10 -> 0x3F34B8
u32 flPS2DmaAddEndTag(u32 tag, s32 qwc, s32 irq, s32 /* unused */);                 // Range: 0x3F3F20 -> 0x3F3F88
void flPS2DmaInitControl(FLPS2VIF1Control *dma_ptr, u32 queue_size, void *handler); // Range: 0x3F4DD0 -> 0x3F4ECC
s32 flPS2DmaAddQueue2(s32 type, u32 data_adrs, u32 endtag_adrs,
                      FLPS2VIF1Control *dma_ptr);                 // Range: 0x3F4ED0 -> 0x3F5200
s32 flPS2DmaInterrupt(s32 ch);                                    // Range: 0x3F5200 -> 0x3F55F0
void flPS2DmaSend();                                              // Range: 0x3F55F0 -> 0x3F5838
s32 flPS2DmaWait();                                               // Range: 0x3F5840 -> 0x3F58B0
void flPS2IopModuleLoad(s8 *fname, s32 args, s8 *argp, s32 type); // Range: 0x3F5960 -> 0x3F5A1C
s32 flFileWrite(s8 *filename, void *buf, s32 len);                // Range: 0x3F5B30 -> 0x3F5C28
s32 flFileAppend(s8 *filename, void *buf, s32 len);               // Range: 0x3F5C30 -> 0x3F5D38
void flMemset(void *dst, u32 pat, s32 size);                      // Range: 0x3F5E40 -> 0x3F5EA4
void *flAllocMemory(s32 size);                                    // Range: 0x3F5F30 -> 0x3F5F60
s32 flGetFrame(FMS_FRAME *frame);                                 // Range: 0x3F5F60 -> 0x3F5F90
s32 flGetSpace();                                                 // Range: 0x3F5F90 -> 0x3F5FB4
void *flAllocMemoryS(s32 size);                                   // Range: 0x3F5FC0 -> 0x3F5FF0
u32 flPS2GetSystemMemoryHandle(s32 len, s32 type);                // Range: 0x3F5FF0 -> 0x3F6148
void flPS2ReleaseSystemMemory(u32 handle);                        // Range: 0x3F6150 -> 0x3F627C
void *flPS2GetSystemBuffAdrs(u32 handle);                         // Range: 0x3F6280 -> 0x3F62A8
void flPS2SystemTmpBuffInit();                                    // Range: 0x3F62E0 -> 0x3F6348
void flPS2SystemTmpBuffFlush();                                   // Range: 0x3F6350 -> 0x3F63FC
u32 flPS2GetSystemTmpBuff(s32 len, s32 align);                    // Range: 0x3F6400 -> 0x3F64AC
u16 flPS2GetStaticVramArea(u32 size);                             // Range: 0x3F8450 -> 0x3F8564
void flPS2VramInit();                                             // Range: 0x3FCFB0 -> 0x3FD068
s32 flInitialize();                                               // Range: 0x3FE0B0 -> 0x3FE1A8
s32 flFlip(u32 flag);                                             // Range: 0x3FE580 -> 0x3FE648

s32 flPS2PADModuleInit();                                    // Range: 0x4000B0 -> 0x400120
s32 tarPADInit();                                            // Range: 0x400120 -> 0x40041C
void tarPADDestroy();                                        // Range: 0x400420 -> 0x400448
void flPADConfigSetACRtoXX(s32 padnum, s16 a, s16 b, s16 c); // Range: 0x400450 -> 0x4004B8
void tarPADRead();                                           // Range: 0x4004C0 -> 0x400624

void func_00402698(void *mem, s32 size);                // Range: 0x402698 -> 0x4026B0
void func_00402570(const void *src, void *dest, s32 n); // Range: 0x402570 -> 0x402590

void MemcardInit();                  // Range: 0x403EC0 -> 0x403F38
void KnjFlush();                     // Range: 0x407E90 -> 0x407FE8
void ppgWorkInitializeApprication(); // Range: 0x413920 -> 0x413A54

// reboot.c
void Reboot_Program(s8 *args); // Range: 0x413F40 -> 0x414030

// .rodata

extern const u8 Dir_Menu_Max_Data[10][7];      // size: 0x46, address: 0x504FB0
extern const u8 PL_Color_Data[20];             // size: 0x14, address: 0x552050
extern const FLPAD_CONFIG fltpad_config_basic; // size: 0x2C, address: 0x55F530
extern const u32 flpad_io_map[25];             // size: 0x64, address: 0x55F560

// .sbss

extern MessageTable *msgSysDirTbl[1];     // size: 0x4, address: 0x575620
extern void (*plfree)(void *);            // size: 0x4, address: 0x578A10
extern void *(*plmalloc)(s32);            // size: 0x4, address: 0x578A14
extern BG_MVXY bg_mvxy;                   // size: 0x18, address: 0x578C80
extern s16 base_y_pos;                    // size: 0x2, address: 0x578CC4
extern MessageData Message_Data[4];       // size: 0x30, address: 0x578ED0
extern IO io_w;                           // size: 0x6C, address: 0x579230
extern TPU *tpu_free;                     // size: 0x4, address: 0x579A8C
extern u8 *texcash_melt_buffer;           // size: 0x4, address: 0x579A90
extern s32 Zoom_Base_Position_Z;          // size: 0x4, address: 0x579AC4
extern s32 Zoom_Base_Position_Y;          // size: 0x4, address: 0x579AC8
extern s32 Zoom_Base_Position_X;          // size: 0x4, address: 0x579ACC
extern f32 Frame_Zoom_Y;                  // size: 0x4, address: 0x579AD0
extern f32 Frame_Zoom_X;                  // size: 0x4, address: 0x579AD4
extern f32 SA_Zoom_Y;                     // size: 0x4, address: 0x579AD8
extern f32 SA_Zoom_X;                     // size: 0x4, address: 0x579ADC
extern f32 Screen_Zoom_Y;                 // size: 0x4, address: 0x579AE0
extern f32 Screen_Zoom_X;                 // size: 0x4, address: 0x579AE4
extern u8 Screen_PAL;                     // size: 0x1, address: 0x579C20
extern u16 PLsw[2][2];                    // size: 0x8, address: 0x579C28
extern u32 Interrupt_Timer;               // size: 0x4, address: 0x579C34
extern u16 p4sw_buff;                     // size: 0x2, address: 0x579C38
extern u16 p3sw_buff;                     // size: 0x2, address: 0x579C3C
extern u16 p2sw_buff;                     // size: 0x2, address: 0x579C40
extern u16 p1sw_buff;                     // size: 0x2, address: 0x579C44
extern u8 Interrupt_Flag;                 // size: 0x1, address: 0x579C48
extern s16 Correct_Y[4];                  // size: 0x8, address: 0x579C50
extern s16 Correct_X[4];                  // size: 0x8, address: 0x579C58
extern u8 Turbo_Timer;                    // size: 0x1, address: 0x579C60
extern u8 Turbo;                          // size: 0x1, address: 0x579C64
extern u8 Disp_Size_V;                    // size: 0x1, address: 0x579C6C
extern u8 Disp_Size_H;                    // size: 0x1, address: 0x579C70
extern s32 Y_Adjust_Buff[3];              // size: 0xC, address: 0x579C78
extern s32 X_Adjust_Buff[3];              // size: 0xC, address: 0x579C88
extern s32 Y_Adjust;                      // size: 0x4, address: 0x579C94
extern s32 X_Adjust;                      // size: 0x4, address: 0x579C98
extern u8 Interface_Type[2];              // size: 0x2, address: 0x579C9C
extern u8 Process_Counter;                // size: 0x1, address: 0x579CA4
extern u16 p4sw_1;                        // size: 0x2, address: 0x579CA8
extern u16 p4sw_0;                        // size: 0x2, address: 0x579CAC
extern u16 p3sw_1;                        // size: 0x2, address: 0x579CB0
extern u16 p3sw_0;                        // size: 0x2, address: 0x579CB4
extern u16 p2sw_1;                        // size: 0x2, address: 0x579CB8
extern u16 p2sw_0;                        // size: 0x2, address: 0x579CBC
extern u16 p1sw_1;                        // size: 0x2, address: 0x579CC0
extern u16 p1sw_0;                        // size: 0x2, address: 0x579CC4
extern struct _SYSTEM_W sys_w;            // size: 0x1C, address: 0x579D90
extern u32 current_task_num;              // size: 0x4, address: 0x579DAC
extern u8 plsw_01[2];                     // size: 0x4, address: 0x579DD0
extern u8 plsw_00[2];                     // size: 0x4, address: 0x579DD4
extern u16 VS_Win_Record[2];              // size: 0x4, address: 0x579DD8
extern u16 IO_Result;                     // size: 0x2, address: 0x579DDC
extern s16 Cont_Timer;                    // size: 0x2, address: 0x579E18
extern u16 Result_Timer[2];               // size: 0x4, address: 0x579E30
extern s16 Offset_BG_X[6];                // size: 0xC, address: 0x579E38
extern s16 Target_BG_X[6];                // size: 0xC, address: 0x579E48
extern u16 WGJ_Win;                       // size: 0x2, address: 0x579E54
extern u16 Win_Record[2];                 // size: 0x4, address: 0x579E5C
extern s16 M_Timer;                       // size: 0x2, address: 0x579FBC
extern s16 G_Timer;                       // size: 0x2, address: 0x57A02C
extern u8 Pause_Type;                     // size: 0x1, address: 0x57A048
extern u8 CPU_Rec[2];                     // size: 0x2, address: 0x57A04C
extern u8 Forbid_Reset;                   // size: 0x1, address: 0x57A050
extern u8 CPU_Time_Lag[2];                // size: 0x2, address: 0x57A054
extern u8 Decide_ID;                      // size: 0x1, address: 0x57A064
extern s8 Menu_Page_Buff;                 // size: 0x1, address: 0x57A06C
extern u8 Training_ID;                    // size: 0x1, address: 0x57A07C
extern s8 Vital_Handicap[6][2];           // size: 0xC, address: 0x57A090
extern u8 Direction_Working[6];           // size: 0x6, address: 0x57A0A0
extern u8 Page_Max;                       // size: 0x1, address: 0x57A0A8
extern u8 Play_Mode;                      // size: 0x1, address: 0x57A0AC
extern u8 Present_Mode;                   // size: 0x1, address: 0x57A0B0
extern s8 VS_Stage;                       // size: 0x1, address: 0x57A0B4
extern s8 Menu_Max;                       // size: 0x1, address: 0x57A0BC
extern s8 Menu_Page;                      // size: 0x1, address: 0x57A0C0
extern u8 Mode_Type;                      // size: 0x1, address: 0x57A0C4
extern s8 Menu_Cursor_Move;               // size: 0x1, address: 0x57A0D8
extern u8 Replay_Status[2];               // size: 0x2, address: 0x57A0E8
extern s8 Menu_Cursor_Y[2];               // size: 0x2, address: 0x57A0EC
extern u8 Unsubstantial_BG[4];            // size: 0x4, address: 0x57A0F4
extern s8 Convert_Buff[4][2][12];         // size: 0x60, address: 0x57A100
extern u8 Cont_No[4];                     // size: 0x4, address: 0x57A1F8
extern u8 test_flag;                      // size: 0x1, address: 0x57A200
extern u8 Play_Type;                      // size: 0x1, address: 0x57A250
extern u8 Pause_ID;                       // size: 0x1, address: 0x57A254
extern u8 Game_pause;                     // size: 0x1, address: 0x57A260
extern u8 Menu_Suicide[4];                // size: 0x4, address: 0x57A264
extern u8 Connect_Status;                 // size: 0x1, address: 0x57A268
extern s8 Cursor_Y_Pos[2][4];             // size: 0x8, address: 0x57A278
extern u8 M_No[4];                        // size: 0x4, address: 0x57A29C
extern u8 G_No[4];                        // size: 0x4, address: 0x57A2A4
extern u8 E_No[4];                        // size: 0x4, address: 0x57A2B0
extern u8 E_Number[2][4];                 // size: 0x8, address: 0x57A2B8
extern s8 Suicide[8];                     // size: 0x8, address: 0x57A2F8
extern s8 Last_Selected_EM[2];            // size: 0x2, address: 0x57A30C
extern u8 Continue_Count_Down[2];         // size: 0x2, address: 0x57A33C
extern u8 GO_No[4];                       // size: 0x4, address: 0x57A344
extern u8 Scene_Cut;                      // size: 0x1, address: 0x57A348
extern s8 Break_Com[2][20];               // size: 0x28, address: 0x57A4C0
extern s8 Operator_Status[2];             // size: 0x2, address: 0x57A550
extern u8 Usage;                          // size: 0x1, address: 0x57A55C
extern s8 Ignore_Entry[2];                // size: 0x2, address: 0x57A58C
extern u8 Continue_Coin[2];               // size: 0x2, address: 0x57A590
extern u8 Country;                        // size: 0x1, address: 0x57A5E4
extern s8 Player_id;                      // size: 0x1, address: 0x57A60C
extern s8 Cover_Timer;                    // size: 0x1, address: 0x57A678
extern s8 Next_Step;                      // size: 0x1, address: 0x57A680
extern s8 Champion;                       // size: 0x1, address: 0x57A690
extern s8 New_Challenger;                 // size: 0x1, address: 0x57A694
extern s8 LOSER;                          // size: 0x1, address: 0x57A698
extern s8 WINNER;                         // size: 0x1, address: 0x57A69C
extern s8 Continue_Count[2];              // size: 0x2, address: 0x57A6B4
extern s8 Forbid_Break;                   // size: 0x1, address: 0x57A6BC
extern u8 My_char[2];                     // size: 0x2, address: 0x57A6D4
extern s8 Break_Into;                     // size: 0x1, address: 0x57A6D8
extern s8 Winner_id;                      // size: 0x1, address: 0x57A6E8
extern u32 WGJ_Score;                     // size: 0x4, address: 0x57A70C
extern u32 Score[2][3];                   // size: 0x18, address: 0x57A760
extern u32 Record_Timer;                  // size: 0x4, address: 0x57A810
extern s8 Slow_Timer;                     // size: 0x1, address: 0x57A830
extern u8 sysSLOW;                        // size: 0x1, address: 0x57A834
extern u8 sysFF;                          // size: 0x1, address: 0x57A838
extern s8 Debug_w[72];                    // size: 0x48, address: 0x57A860
extern s16 *dctex_linear;                 // size: 0x4, address: 0x57A950
extern MPP mpp_w;                         // size: 0x4C, address: 0x57A9F0
extern s32 system_init_level;             // size: 0x4, address: 0x57AA3C
extern u32 flDebugTrueTime[4];            // size: 0x10, address: 0x57AB50
extern s32 flPS2FlipCancelFlag;           // size: 0x4, address: 0x57AB78
extern u32 flPs2FBA;                      // size: 0x4, address: 0x57AB84
extern s32 flClayNum;                     // size: 0x4, address: 0x57AB88
extern s32 flPTNum;                       // size: 0x4, address: 0x57AE38
extern FLPS2VIF1Control flPs2VIF1Control; // size: 0x3C, address: 0x57AE50
extern FL_FMS flFMS;                      // size: 0x18, address: 0x57AEB0
extern u32 flSystemRenderOperation;       // size: 0x4, address: 0x57AEC8
extern u32 flSystemRenderState;           // size: 0x4, address: 0x57AECC
extern u32 flLoadCount;                   // size: 0x4, address: 0x57AED8
extern plContext flFrameBuf;              // size: 0x48, address: 0x57AEF0
extern s32 flFrame;                       // size: 0x4, address: 0x57AF38
extern s32 flHeight;                      // size: 0x4, address: 0x57AF3C
extern s32 flWidth;                       // size: 0x4, address: 0x57AF40
extern s32 flCTNum;                       // size: 0x4, address: 0x57AF44
extern TARPAD tarpad_root[2];             // size: 0x68, address: 0x57B040

// .bss

extern MEM_BLOCK sysmemblock[4096]; // size: 0x10000, address: 0x584C80

extern BG bg_w;                       // size: 0x428, address: 0x595830
extern f32 PrioBase[128];             // size: 0x200, address: 0x5E3F50
extern PLW plw[2];                    // size: 0x8D8, address: 0x5E4D20
extern struct _SAVE_W save_w[6];      // size: 0xC30, address: 0x6B4E80
extern SystemDir system_dir[6];       // size: 0x1B0, address: 0x6B5B40
extern struct _TASK task[11];         // size: 0xDC, address: 0x6BD2D0
extern u8 Order_Dir[148];             // size: 0x94, address: 0x6BD5F0
extern u8 Order_Timer[148];           // size: 0x94, address: 0x6BD690
extern u8 Order[148];                 // size: 0x94, address: 0x6BD730
extern FLPS2DrawStart flPs2DrawStart; // size: 0x140, address: 0x6E24D0
extern FLPS2DB flPs2Db[2];            // size: 0x140, address: 0x6E2610
extern FLPS2State flPs2State;         // size: 0x470, address: 0x6E2750

#endif
