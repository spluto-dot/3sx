#ifndef UNKNOWN_H
#define UNKNOWN_H

// MARK: - Types

typedef struct {
    // total size: 0x18
    float x0; // offset 0x0, size 0x4
    float y0; // offset 0x4, size 0x4
    float x1; // offset 0x8, size 0x4
    float y1; // offset 0xC, size 0x4
    float ne; // offset 0x10, size 0x4
    float fa; // offset 0x14, size 0x4
} VPRM;

typedef struct {
    // total size: 0x8
    unsigned char *pFrame; // offset 0x0, size 0x4
    int heapnum;           // offset 0x4, size 0x4
} FMS_FRAME;

typedef struct {
    // total size: 0x4C
    FMS_FRAME fmsFrame;        // offset 0x0, size 0x8
    unsigned char *ramcntBuff; // offset 0x8, size 0x4
    VPRM vprm;                 // offset 0xC, size 0x18
    char ds_h[2];              // offset 0x24, size 0x2
    char ds_v[2];              // offset 0x26, size 0x2
    char sysStop;              // offset 0x28, size 0x1
    char initTrainingData;     // offset 0x29, size 0x1
    char inGame;               // offset 0x2A, size 0x1
    char ctrDemo;              // offset 0x2B, size 0x1
    char language;             // offset 0x2C, size 0x1
    char langload;             // offset 0x2D, size 0x1
    char cutAnalogStickData;   // offset 0x2E, size 0x1
    char useAnalogStickData;   // offset 0x2F, size 0x1
    char pal50Hz;              // offset 0x30, size 0x1
    unsigned int hanFbTex;     // offset 0x34, size 0x4
    unsigned char useChar[20]; // offset 0x38, size 0x14
} MPP;                         // size: 0x4C

typedef struct {
    // total size: 0xC
    signed short x;   // offset 0x0, size 0x2
    signed short y;   // offset 0x2, size 0x2
    signed short pow; // offset 0x4, size 0x2
    signed short ang; // offset 0x6, size 0x2
    float rad;        // offset 0x8, size 0x4
} PAD_STICK;

typedef struct {
    // total size: 0x6C
    struct /* @anon26 */ {
        // total size: 0x34
        unsigned char state;    // offset 0x0, size 0x1
        unsigned char anstate;  // offset 0x1, size 0x1
        unsigned short kind;    // offset 0x2, size 0x2
        unsigned int sw;        // offset 0x4, size 0x4
        unsigned int sw_old;    // offset 0x8, size 0x4
        unsigned int sw_new;    // offset 0xC, size 0x4
        unsigned int sw_off;    // offset 0x10, size 0x4
        unsigned int sw_chg;    // offset 0x14, size 0x4
        unsigned int sw_repeat; // offset 0x18, size 0x4
        PAD_STICK stick[2];     // offset 0x1C, size 0x18
    } data[2];                  // offset 0x0, size 0x68
    unsigned short sw[2];       // offset 0x68, size 0x4
} IO;                           // size: 0x6C

struct _TASK {
    // total size: 0x14
    void (*func_adrs)();      // offset 0x0, size 0x4
    void (*callback_adrs)();  // offset 0x4, size 0x4
    unsigned char r_no[4];    // offset 0x8, size 0x4
    unsigned short condition; // offset 0xC, size 0x2
    signed short timer;       // offset 0xE, size 0x2
    unsigned char free[4];    // offset 0x10, size 0x4
};

typedef struct {
    // total size: 0xD08
    signed int x16;                // offset 0x0, size 0x4
    signed int x32;                // offset 0x4, size 0x4
    unsigned short x16_used[1024]; // offset 0x8, size 0x800
    unsigned short x32_used[640];  // offset 0x808, size 0x500
} TPU;

struct _disp {
    // total size: 0xC
    unsigned short size_x; // offset 0x0, size 0x2
    unsigned short size_y; // offset 0x2, size 0x2
    unsigned short now;    // offset 0x4, size 0x2
    unsigned short new;    // offset 0x6, size 0x2
    signed int cable;      // offset 0x8, size 0x4
};

struct _SYSTEM_W {
    // total size: 0x1C
    struct _disp disp;         // offset 0x0, size 0xC
    signed int pause;          // offset 0xC, size 0x4
    signed int gd_error;       // offset 0x10, size 0x4
    signed int reset;          // offset 0x14, size 0x4
    unsigned char sound_mode;  // offset 0x18, size 0x1
    unsigned char screen_mode; // offset 0x19, size 0x1
    unsigned char bgm_type;    // offset 0x1A, size 0x1
    unsigned char dummy;       // offset 0x1B, size 0x1
};

typedef struct {
    // total size: 0x46C
    struct /* @anon46 */ {
        // total size: 0x388
        char be_flag;               // offset 0x0, size 0x1
        char disp_flag;             // offset 0x1, size 0x1
        unsigned char blink_timing; // offset 0x2, size 0x1
        unsigned char operator;     // offset 0x3, size 0x1
        unsigned char type;         // offset 0x4, size 0x1
        unsigned char charset_id;   // offset 0x5, size 0x1
        signed short work_id;       // offset 0x6, size 0x2
        signed short id;            // offset 0x8, size 0x2
        char rl_flag;               // offset 0xA, size 0x1
        char rl_waza;               // offset 0xB, size 0x1
        unsigned int *target_adrs;  // offset 0xC, size 0x4
        unsigned int *hit_adrs;     // offset 0x10, size 0x4
        unsigned int *dmg_adrs;     // offset 0x14, size 0x4
        signed short before;        // offset 0x18, size 0x2
        signed short myself;        // offset 0x1A, size 0x2
        signed short behind;        // offset 0x1C, size 0x2
        signed short listix;        // offset 0x1E, size 0x2
        signed short dead_f;        // offset 0x20, size 0x2
        signed short timing;        // offset 0x22, size 0x2
        signed short routine_no[8]; // offset 0x24, size 0x10
        signed short old_rno[8];    // offset 0x34, size 0x10
        signed short hit_stop;      // offset 0x44, size 0x2
        signed short hit_quake;     // offset 0x46, size 0x2
        char cgromtype;             // offset 0x48, size 0x1
        unsigned char kage_flag;    // offset 0x49, size 0x1
        signed short kage_hx;       // offset 0x4A, size 0x2
        signed short kage_hy;       // offset 0x4C, size 0x2
        signed short kage_prio;     // offset 0x4E, size 0x2
        signed short kage_width;    // offset 0x50, size 0x2
        signed short kage_char;     // offset 0x52, size 0x2
        signed short position_x;    // offset 0x54, size 0x2
        signed short position_y;    // offset 0x56, size 0x2
        signed short position_z;    // offset 0x58, size 0x2
        signed short next_x;        // offset 0x5A, size 0x2
        signed short next_y;        // offset 0x5C, size 0x2
        signed short next_z;        // offset 0x5E, size 0x2
        signed short scr_mv_x;      // offset 0x60, size 0x2
        signed short scr_mv_y;      // offset 0x62, size 0x2
        union /* @anon29 */ {
            signed int cal; // offset 0x0, size 0x4
            struct /* @anon31 */ {
                // total size: 0x4
                signed short low;    // offset 0x0, size 0x2
                signed short pos;    // offset 0x2, size 0x2
            } disp;                  // offset 0x0, size 0x4
        } xyz[3];                    // offset 0x64, size 0xC
        signed short old_pos[3];     // offset 0x70, size 0x6
        signed short sync_suzi;      // offset 0x76, size 0x2
        unsigned short *suzi_offset; // offset 0x78, size 0x4
        struct /* @anon4 */ {
            // total size: 0x18
            union /* @anon5 */ {
                signed int sp; // offset 0x0, size 0x4
                struct /* @anon7 */ {
                    // total size: 0x4
                    signed short l; // offset 0x0, size 0x2
                    signed short h; // offset 0x2, size 0x2
                } real;             // offset 0x0, size 0x4
            } a[2];                 // offset 0x0, size 0x8
            union /* @anon11 */ {
                signed int sp; // offset 0x0, size 0x4
                struct /* @anon13 */ {
                    // total size: 0x4
                    signed short l; // offset 0x0, size 0x2
                    signed short h; // offset 0x2, size 0x2
                } real;             // offset 0x0, size 0x4
            } d[2];                 // offset 0x8, size 0x8
            signed short kop[2];    // offset 0x10, size 0x4
            unsigned short index;   // offset 0x14, size 0x2
        } mvxy;                     // offset 0x7C, size 0x18
        signed short direction;     // offset 0x94, size 0x2
        signed short dir_old;       // offset 0x96, size 0x2
        signed short dir_step;      // offset 0x98, size 0x2
        signed short dir_timer;     // offset 0x9A, size 0x2
        signed short vitality;      // offset 0x9C, size 0x2
        signed short vital_new;     // offset 0x9E, size 0x2
        signed short vital_old;     // offset 0xA0, size 0x2
        signed short dm_vital;      // offset 0xA2, size 0x2
        signed short dmcal_m;       // offset 0xA4, size 0x2
        signed short dmcal_d;       // offset 0xA6, size 0x2
        char weight_level;          // offset 0xA8, size 0x1
        struct /* @anon21 */ {
            // total size: 0x8
            unsigned short code; // offset 0x0, size 0x2
            signed short koc;    // offset 0x2, size 0x2
            signed short ix;     // offset 0x4, size 0x2
            signed short pat;    // offset 0x6, size 0x2
        } cmoa;                  // offset 0xAA, size 0x8
        struct /* @anon21 */ {
            // total size: 0x8
            unsigned short code; // offset 0x0, size 0x2
            signed short koc;    // offset 0x2, size 0x2
            signed short ix;     // offset 0x4, size 0x2
            signed short pat;    // offset 0x6, size 0x2
        } cmsw;                  // offset 0xB2, size 0x8
        struct /* @anon21 */ {
            // total size: 0x8
            unsigned short code; // offset 0x0, size 0x2
            signed short koc;    // offset 0x2, size 0x2
            signed short ix;     // offset 0x4, size 0x2
            signed short pat;    // offset 0x6, size 0x2
        } cmlp;                  // offset 0xBA, size 0x8
        struct /* @anon21 */ {
            // total size: 0x8
            unsigned short code; // offset 0x0, size 0x2
            signed short koc;    // offset 0x2, size 0x2
            signed short ix;     // offset 0x4, size 0x2
            signed short pat;    // offset 0x6, size 0x2
        } cml2;                  // offset 0xC2, size 0x8
        struct /* @anon21 */ {
            // total size: 0x8
            unsigned short code; // offset 0x0, size 0x2
            signed short koc;    // offset 0x2, size 0x2
            signed short ix;     // offset 0x4, size 0x2
            signed short pat;    // offset 0x6, size 0x2
        } cmja;                  // offset 0xCA, size 0x8
        struct /* @anon21 */ {
            // total size: 0x8
            unsigned short code; // offset 0x0, size 0x2
            signed short koc;    // offset 0x2, size 0x2
            signed short ix;     // offset 0x4, size 0x2
            signed short pat;    // offset 0x6, size 0x2
        } cmj2;                  // offset 0xD2, size 0x8
        struct /* @anon21 */ {
            // total size: 0x8
            unsigned short code; // offset 0x0, size 0x2
            signed short koc;    // offset 0x2, size 0x2
            signed short ix;     // offset 0x4, size 0x2
            signed short pat;    // offset 0x6, size 0x2
        } cmj3;                  // offset 0xDA, size 0x8
        struct /* @anon21 */ {
            // total size: 0x8
            unsigned short code; // offset 0x0, size 0x2
            signed short koc;    // offset 0x2, size 0x2
            signed short ix;     // offset 0x4, size 0x2
            signed short pat;    // offset 0x6, size 0x2
        } cmj4;                  // offset 0xE2, size 0x8
        struct /* @anon21 */ {
            // total size: 0x8
            unsigned short code; // offset 0x0, size 0x2
            signed short koc;    // offset 0x2, size 0x2
            signed short ix;     // offset 0x4, size 0x2
            signed short pat;    // offset 0x6, size 0x2
        } cmj5;                  // offset 0xEA, size 0x8
        struct /* @anon21 */ {
            // total size: 0x8
            unsigned short code; // offset 0x0, size 0x2
            signed short koc;    // offset 0x2, size 0x2
            signed short ix;     // offset 0x4, size 0x2
            signed short pat;    // offset 0x6, size 0x2
        } cmj6;                  // offset 0xF2, size 0x8
        struct /* @anon21 */ {
            // total size: 0x8
            unsigned short code; // offset 0x0, size 0x2
            signed short koc;    // offset 0x2, size 0x2
            signed short ix;     // offset 0x4, size 0x2
            signed short pat;    // offset 0x6, size 0x2
        } cmj7;                  // offset 0xFA, size 0x8
        struct /* @anon21 */ {
            // total size: 0x8
            unsigned short code; // offset 0x0, size 0x2
            signed short koc;    // offset 0x2, size 0x2
            signed short ix;     // offset 0x4, size 0x2
            signed short pat;    // offset 0x6, size 0x2
        } cmms;                  // offset 0x102, size 0x8
        struct /* @anon21 */ {
            // total size: 0x8
            unsigned short code; // offset 0x0, size 0x2
            signed short koc;    // offset 0x2, size 0x2
            signed short ix;     // offset 0x4, size 0x2
            signed short pat;    // offset 0x6, size 0x2
        } cmmd;                  // offset 0x10A, size 0x8
        struct /* @anon21 */ {
            // total size: 0x8
            unsigned short code; // offset 0x0, size 0x2
            signed short koc;    // offset 0x2, size 0x2
            signed short ix;     // offset 0x4, size 0x2
            signed short pat;    // offset 0x6, size 0x2
        } cmyd;                  // offset 0x112, size 0x8
        struct /* @anon21 */ {
            // total size: 0x8
            unsigned short code; // offset 0x0, size 0x2
            signed short koc;    // offset 0x2, size 0x2
            signed short ix;     // offset 0x4, size 0x2
            signed short pat;    // offset 0x6, size 0x2
        } cmcf;                  // offset 0x11A, size 0x8
        struct /* @anon21 */ {
            // total size: 0x8
            unsigned short code; // offset 0x0, size 0x2
            signed short koc;    // offset 0x2, size 0x2
            signed short ix;     // offset 0x4, size 0x2
            signed short pat;    // offset 0x6, size 0x2
        } cmcr;                  // offset 0x122, size 0x8
        struct /* @anon21 */ {
            // total size: 0x8
            unsigned short code; // offset 0x0, size 0x2
            signed short koc;    // offset 0x2, size 0x2
            signed short ix;     // offset 0x4, size 0x2
            signed short pat;    // offset 0x6, size 0x2
        } cmbk;                  // offset 0x12A, size 0x8
        struct /* @anon21 */ {
            // total size: 0x8
            unsigned short code; // offset 0x0, size 0x2
            signed short koc;    // offset 0x2, size 0x2
            signed short ix;     // offset 0x4, size 0x2
            signed short pat;    // offset 0x6, size 0x2
        } cmb2;                  // offset 0x132, size 0x8
        struct /* @anon21 */ {
            // total size: 0x8
            unsigned short code; // offset 0x0, size 0x2
            signed short koc;    // offset 0x2, size 0x2
            signed short ix;     // offset 0x4, size 0x2
            signed short pat;    // offset 0x6, size 0x2
        } cmb3;                  // offset 0x13A, size 0x8
        struct /* @anon21 */ {
            // total size: 0x8
            unsigned short code; // offset 0x0, size 0x2
            signed short koc;    // offset 0x2, size 0x2
            signed short ix;     // offset 0x4, size 0x2
            signed short pat;    // offset 0x6, size 0x2
        } cmhs;                  // offset 0x142, size 0x8
        struct /* @anon21 */ {
            // total size: 0x8
            unsigned short code; // offset 0x0, size 0x2
            signed short koc;    // offset 0x2, size 0x2
            signed short ix;     // offset 0x4, size 0x2
            signed short pat;    // offset 0x6, size 0x2
        } cmr0;                  // offset 0x14A, size 0x8
        struct /* @anon21 */ {
            // total size: 0x8
            unsigned short code; // offset 0x0, size 0x2
            signed short koc;    // offset 0x2, size 0x2
            signed short ix;     // offset 0x4, size 0x2
            signed short pat;    // offset 0x6, size 0x2
        } cmr1;                  // offset 0x152, size 0x8
        struct /* @anon21 */ {
            // total size: 0x8
            unsigned short code; // offset 0x0, size 0x2
            signed short koc;    // offset 0x2, size 0x2
            signed short ix;     // offset 0x4, size 0x2
            signed short pat;    // offset 0x6, size 0x2
        } cmr2;                  // offset 0x15A, size 0x8
        struct /* @anon21 */ {
            // total size: 0x8
            unsigned short code;       // offset 0x0, size 0x2
            signed short koc;          // offset 0x2, size 0x2
            signed short ix;           // offset 0x4, size 0x2
            signed short pat;          // offset 0x6, size 0x2
        } cmr3;                        // offset 0x162, size 0x8
        signed short cmwk[32];         // offset 0x16A, size 0x40
        unsigned int *char_table[12];  // offset 0x1AC, size 0x30
        unsigned int *se_random_table; // offset 0x1DC, size 0x4
        signed short *step_xy_table;   // offset 0x1E0, size 0x4
        signed short *move_xy_table;   // offset 0x1E4, size 0x4
        struct /* @anon49 */ {
            // total size: 0x10
            signed short parts_hos_x;  // offset 0x0, size 0x2
            signed short parts_hos_y;  // offset 0x2, size 0x2
            unsigned char parts_colmd; // offset 0x4, size 0x1
            unsigned char parts_colcd; // offset 0x5, size 0x1
            unsigned char parts_prio;  // offset 0x6, size 0x1
            unsigned char parts_flip;  // offset 0x7, size 0x1
            unsigned char parts_timer; // offset 0x8, size 0x1
            unsigned char parts_disp;  // offset 0x9, size 0x1
            signed short parts_mts;    // offset 0xA, size 0x2
            unsigned short parts_nix;  // offset 0xC, size 0x2
            unsigned short parts_char; // offset 0xE, size 0x2
        } *overlap_char_tbl;           // offset 0x1E8, size 0x4
        struct /* @anon43 */ {
            // total size: 0x8
            signed short olc_ix[4]; // offset 0x0, size 0x8
        } *olc_ix_table;            // offset 0x1EC, size 0x4
        struct /* @anon43 */ {
            // total size: 0x8
            signed short olc_ix[4]; // offset 0x0, size 0x8
        } cg_olc;                   // offset 0x1F0, size 0x8
        struct /* @anon58 */ {
            // total size: 0x8
            signed short catch_hos_x; // offset 0x0, size 0x2
            signed short catch_hos_y; // offset 0x2, size 0x2
            unsigned char catch_prio; // offset 0x4, size 0x1
            unsigned char catch_flip; // offset 0x5, size 0x1
            signed short catch_nix;   // offset 0x6, size 0x2
        } *rival_catch_tbl;           // offset 0x1F8, size 0x4
        struct /* @anon58 */ {
            // total size: 0x8
            signed short catch_hos_x; // offset 0x0, size 0x2
            signed short catch_hos_y; // offset 0x2, size 0x2
            unsigned char catch_prio; // offset 0x4, size 0x1
            unsigned char catch_flip; // offset 0x5, size 0x1
            signed short catch_nix;   // offset 0x6, size 0x2
        } *curr_rca;                  // offset 0x1FC, size 0x4
        unsigned int *set_char_ad;    // offset 0x200, size 0x4
        signed short cg_ix;           // offset 0x204, size 0x2
        signed short now_koc;         // offset 0x206, size 0x2
        signed short char_index;      // offset 0x208, size 0x2
        signed short current_colcd;   // offset 0x20A, size 0x2
        signed short cgd_type;        // offset 0x20C, size 0x2
        unsigned char pat_status;     // offset 0x20E, size 0x1
        unsigned char kind_of_waza;   // offset 0x20F, size 0x1
        unsigned char hit_range;      // offset 0x210, size 0x1
        unsigned char total_paring;   // offset 0x211, size 0x1
        unsigned char total_att_set;  // offset 0x212, size 0x1
        unsigned char sp_tech_id;     // offset 0x213, size 0x1
        unsigned char cg_type;        // offset 0x214, size 0x1
        unsigned char cg_ctr;         // offset 0x215, size 0x1
        unsigned short cg_se;         // offset 0x216, size 0x2
        unsigned short cg_olc_ix;     // offset 0x218, size 0x2
        unsigned short cg_number;     // offset 0x21A, size 0x2
        unsigned short cg_hit_ix;     // offset 0x21C, size 0x2
        signed short cg_att_ix;       // offset 0x21E, size 0x2
        unsigned char cg_extdat;      // offset 0x220, size 0x1
        unsigned char cg_cancel;      // offset 0x221, size 0x1
        unsigned char cg_effect;      // offset 0x222, size 0x1
        unsigned char cg_eftype;      // offset 0x223, size 0x1
        unsigned short cg_zoom;       // offset 0x224, size 0x2
        unsigned short cg_rival;      // offset 0x226, size 0x2
        unsigned short cg_add_xy;     // offset 0x228, size 0x2
        unsigned char cg_next_ix;     // offset 0x22A, size 0x1
        unsigned char cg_status;      // offset 0x22B, size 0x1
        signed short cg_wca_ix;       // offset 0x22C, size 0x2
        signed short cg_jphos;        // offset 0x22E, size 0x2
        unsigned short cg_meoshi;     // offset 0x230, size 0x2
        unsigned char cg_prio;        // offset 0x232, size 0x1
        unsigned char cg_flip;        // offset 0x233, size 0x1
        unsigned short old_cgnum;     // offset 0x234, size 0x2
        signed short floor;           // offset 0x236, size 0x2
        unsigned short ccoff;         // offset 0x238, size 0x2
        signed short colcd;           // offset 0x23A, size 0x2
        signed short my_col_mode;     // offset 0x23C, size 0x2
        signed short my_col_code;     // offset 0x23E, size 0x2
        signed short my_priority;     // offset 0x240, size 0x2
        signed short my_family;       // offset 0x242, size 0x2
        signed short my_ext_pri;      // offset 0x244, size 0x2
        signed short my_bright_type;  // offset 0x246, size 0x2
        signed short my_bright_level; // offset 0x248, size 0x2
        signed short my_clear_level;  // offset 0x24A, size 0x2
        signed short my_mts;          // offset 0x24C, size 0x2
        signed short my_mr_flag;      // offset 0x24E, size 0x2
        struct /* @anon47 */ {
            // total size: 0x4
            struct /* @anon48 */ {
                // total size: 0x4
                signed short x;     // offset 0x0, size 0x2
                signed short y;     // offset 0x2, size 0x2
            } size;                 // offset 0x0, size 0x4
        } my_mr;                    // offset 0x250, size 0x4
        signed short my_trans_mode; // offset 0x254, size 0x2
        signed short my_roll_flag;  // offset 0x256, size 0x2
        struct /* @anon52 */ {
            // total size: 0x8
            signed short now;         // offset 0x0, size 0x2
            signed short add;         // offset 0x2, size 0x2
            signed short free;        // offset 0x4, size 0x2
            signed short old;         // offset 0x6, size 0x2
        } my_roll;                    // offset 0x258, size 0x8
        signed short waku_work_index; // offset 0x260, size 0x2
        signed short olc_work_ix[4];  // offset 0x262, size 0x8
        struct /* @anon6 */ {
            // total size: 0x10
            unsigned short boix; // offset 0x0, size 0x2
            unsigned short bhix; // offset 0x2, size 0x2
            unsigned short haix; // offset 0x4, size 0x2
            union /* @anon10 */ {
                unsigned short full; // offset 0x0, size 0x2
                struct /* @anon12 */ {
                    // total size: 0x2
                    unsigned char bx; // offset 0x0, size 0x1
                    unsigned char mv; // offset 0x1, size 0x1
                } half;               // offset 0x0, size 0x2
            } mf;                     // offset 0x6, size 0x2
            unsigned short caix;      // offset 0x8, size 0x2
            unsigned short cuix;      // offset 0xA, size 0x2
            unsigned short atix;      // offset 0xC, size 0x2
            unsigned short hoix;      // offset 0xE, size 0x2
        } *hit_ix_table;              // offset 0x26C, size 0x4
        struct /* @anon6 */ {
            // total size: 0x10
            unsigned short boix; // offset 0x0, size 0x2
            unsigned short bhix; // offset 0x2, size 0x2
            unsigned short haix; // offset 0x4, size 0x2
            union /* @anon10 */ {
                unsigned short full; // offset 0x0, size 0x2
                struct /* @anon12 */ {
                    // total size: 0x2
                    unsigned char bx; // offset 0x0, size 0x1
                    unsigned char mv; // offset 0x1, size 0x1
                } half;               // offset 0x0, size 0x2
            } mf;                     // offset 0x6, size 0x2
            unsigned short caix;      // offset 0x8, size 0x2
            unsigned short cuix;      // offset 0xA, size 0x2
            unsigned short atix;      // offset 0xC, size 0x2
            unsigned short hoix;      // offset 0xE, size 0x2
        } cg_ja;                      // offset 0x270, size 0x10
        struct /* @anon22 */ {
            // total size: 0x20
            signed short body_dm[4][4]; // offset 0x0, size 0x20
        } *body_adrs;                   // offset 0x280, size 0x4
        struct /* @anon22 */ {
            // total size: 0x20
            signed short body_dm[4][4]; // offset 0x0, size 0x20
        } *h_bod;                       // offset 0x284, size 0x4
        struct /* @anon26 */ {
            // total size: 0x20
            signed short hand_dm[4][4]; // offset 0x0, size 0x20
        } *hand_adrs;                   // offset 0x288, size 0x4
        struct /* @anon26 */ {
            // total size: 0x20
            signed short hand_dm[4][4]; // offset 0x0, size 0x20
        } *h_han;                       // offset 0x28C, size 0x4
        struct /* @anon26 */ {
            // total size: 0x20
            signed short hand_dm[4][4]; // offset 0x0, size 0x20
        } *dumm_adrs;                   // offset 0x290, size 0x4
        struct /* @anon26 */ {
            // total size: 0x20
            signed short hand_dm[4][4]; // offset 0x0, size 0x20
        } *h_dumm;                      // offset 0x294, size 0x4
        struct /* @anon36 */ {
            // total size: 0x8
            signed short cat_box[4]; // offset 0x0, size 0x8
        } *catch_adrs;               // offset 0x298, size 0x4
        struct /* @anon36 */ {
            // total size: 0x8
            signed short cat_box[4]; // offset 0x0, size 0x8
        } *h_cat;                    // offset 0x29C, size 0x4
        struct /* @anon39 */ {
            // total size: 0x8
            signed short cau_box[4]; // offset 0x0, size 0x8
        } *caught_adrs;              // offset 0x2A0, size 0x4
        struct /* @anon39 */ {
            // total size: 0x8
            signed short cau_box[4]; // offset 0x0, size 0x8
        } *h_cau;                    // offset 0x2A4, size 0x4
        struct /* @anon32 */ {
            // total size: 0x20
            signed short att_box[4][4]; // offset 0x0, size 0x20
        } *attack_adrs;                 // offset 0x2A8, size 0x4
        struct /* @anon32 */ {
            // total size: 0x20
            signed short att_box[4][4]; // offset 0x0, size 0x20
        } *h_att;                       // offset 0x2AC, size 0x4
        struct /* @anon32 */ {
            // total size: 0x20
            signed short att_box[4][4]; // offset 0x0, size 0x20
        } *h_eat;                       // offset 0x2B0, size 0x4
        struct /* @anon42 */ {
            // total size: 0x8
            signed short hos_box[4]; // offset 0x0, size 0x8
        } *hosei_adrs;               // offset 0x2B4, size 0x4
        struct /* @anon42 */ {
            // total size: 0x8
            signed short hos_box[4]; // offset 0x0, size 0x8
        } *h_hos;                    // offset 0x2B8, size 0x4
        struct /* @anon60 */ {
            // total size: 0x10
            unsigned char reaction; // offset 0x0, size 0x1
            unsigned char level;    // offset 0x1, size 0x1
            unsigned char mkh_ix;   // offset 0x2, size 0x1
            unsigned char but_ix;   // offset 0x3, size 0x1
            unsigned char dipsw;    // offset 0x4, size 0x1
            unsigned char guard;    // offset 0x5, size 0x1
            unsigned char dir;      // offset 0x6, size 0x1
            unsigned char free;     // offset 0x7, size 0x1
            unsigned char pow;      // offset 0x8, size 0x1
            unsigned char impact;   // offset 0x9, size 0x1
            unsigned char piyo;     // offset 0xA, size 0x1
            unsigned char ng_type;  // offset 0xB, size 0x1
            char hs_me;             // offset 0xC, size 0x1
            char hs_you;            // offset 0xD, size 0x1
            unsigned char hit_mark; // offset 0xE, size 0x1
            unsigned char dmg_mark; // offset 0xF, size 0x1
        } *att_ix_table;            // offset 0x2BC, size 0x4
        struct /* @anon60 */ {
            // total size: 0x10
            unsigned char reaction;       // offset 0x0, size 0x1
            unsigned char level;          // offset 0x1, size 0x1
            unsigned char mkh_ix;         // offset 0x2, size 0x1
            unsigned char but_ix;         // offset 0x3, size 0x1
            unsigned char dipsw;          // offset 0x4, size 0x1
            unsigned char guard;          // offset 0x5, size 0x1
            unsigned char dir;            // offset 0x6, size 0x1
            unsigned char free;           // offset 0x7, size 0x1
            unsigned char pow;            // offset 0x8, size 0x1
            unsigned char impact;         // offset 0x9, size 0x1
            unsigned char piyo;           // offset 0xA, size 0x1
            unsigned char ng_type;        // offset 0xB, size 0x1
            char hs_me;                   // offset 0xC, size 0x1
            char hs_you;                  // offset 0xD, size 0x1
            unsigned char hit_mark;       // offset 0xE, size 0x1
            unsigned char dmg_mark;       // offset 0xF, size 0x1
        } att;                            // offset 0x2C0, size 0x10
        unsigned short zu_flag;           // offset 0x2D0, size 0x2
        unsigned short at_attribute;      // offset 0x2D2, size 0x2
        signed short kezuri_pow;          // offset 0x2D4, size 0x2
        unsigned short add_arts_point;    // offset 0x2D6, size 0x2
        unsigned short buttobi_type;      // offset 0x2D8, size 0x2
        unsigned short att_zuru;          // offset 0x2DA, size 0x2
        unsigned short at_ten_ix;         // offset 0x2DC, size 0x2
        signed short dir_atthit;          // offset 0x2DE, size 0x2
        signed short vs_id;               // offset 0x2E0, size 0x2
        unsigned char att_hit_ok;         // offset 0x2E2, size 0x1
        unsigned char meoshi_hit_flag;    // offset 0x2E3, size 0x1
        unsigned short at_koa;            // offset 0x2E4, size 0x2
        unsigned char paring_attack_flag; // offset 0x2E6, size 0x1
        char no_death_attack;             // offset 0x2E7, size 0x1
        unsigned char jump_att_flag;      // offset 0x2E8, size 0x1
        char shell_vs_refrect;            // offset 0x2E9, size 0x1
        signed short renew_attack;        // offset 0x2EA, size 0x2
        unsigned short attack_num;        // offset 0x2EC, size 0x2
        unsigned short uketa_att[4];      // offset 0x2EE, size 0x8
        union /* @anon16 */ {
            struct /* @anon18 */ {
                // total size: 0x2
                unsigned char player;    // offset 0x0, size 0x1
                unsigned char effect;    // offset 0x1, size 0x1
            } hit;                       // offset 0x0, size 0x2
            unsigned short hit_flag;     // offset 0x0, size 0x2
        } hf;                            // offset 0x2F6, size 0x2
        signed short hit_mark_x;         // offset 0x2F8, size 0x2
        signed short hit_mark_y;         // offset 0x2FA, size 0x2
        signed short hit_mark_z;         // offset 0x2FC, size 0x2
        signed short kohm;               // offset 0x2FE, size 0x2
        unsigned char dm_fushin;         // offset 0x300, size 0x1
        char dm_weight;                  // offset 0x301, size 0x1
        unsigned short dm_butt_type;     // offset 0x302, size 0x2
        unsigned short dm_zuru;          // offset 0x304, size 0x2
        unsigned short dm_attribute;     // offset 0x306, size 0x2
        signed short dm_guard_success;   // offset 0x308, size 0x2
        signed short dm_plnum;           // offset 0x30A, size 0x2
        signed short dm_attlv;           // offset 0x30C, size 0x2
        signed short dm_dir;             // offset 0x30E, size 0x2
        char dm_rl;                      // offset 0x310, size 0x1
        unsigned char dm_impact;         // offset 0x311, size 0x1
        signed short dm_stop;            // offset 0x312, size 0x2
        signed short dm_quake;           // offset 0x314, size 0x2
        unsigned short dm_piyo;          // offset 0x316, size 0x2
        unsigned short dm_ten_ix;        // offset 0x318, size 0x2
        unsigned short dm_koa;           // offset 0x31A, size 0x2
        signed short dm_work_id;         // offset 0x31C, size 0x2
        unsigned short dm_arts_point;    // offset 0x31E, size 0x2
        unsigned char dm_jump_att_flag;  // offset 0x320, size 0x1
        unsigned char dm_free;           // offset 0x321, size 0x1
        signed short dm_count_up;        // offset 0x322, size 0x2
        char dm_nodeathattack;           // offset 0x324, size 0x1
        unsigned char dm_exdm_ix;        // offset 0x325, size 0x1
        unsigned char dm_dip;            // offset 0x326, size 0x1
        unsigned char dm_kind_of_waza;   // offset 0x327, size 0x1
        signed short attpow;             // offset 0x328, size 0x2
        signed short defpow;             // offset 0x32A, size 0x2
        unsigned int *my_effadrs;        // offset 0x32C, size 0x4
        signed short shell_ix[8];        // offset 0x330, size 0x10
        signed short hm_dm_side;         // offset 0x340, size 0x2
        signed short extra_col;          // offset 0x342, size 0x2
        signed short extra_col_2;        // offset 0x344, size 0x2
        signed short original_vitality;  // offset 0x346, size 0x2
        unsigned char hit_work_id;       // offset 0x348, size 0x1
        unsigned char dmg_work_id;       // offset 0x349, size 0x1
        char K5_init_flag;               // offset 0x34A, size 0x1
        char K5_exec_ok;                 // offset 0x34B, size 0x1
        unsigned char kow;               // offset 0x34C, size 0x1
        unsigned char swallow_no_effect; // offset 0x34D, size 0x1
        signed short E3_work_index;      // offset 0x34E, size 0x2
        signed short E4_work_index;      // offset 0x350, size 0x2
        unsigned char kezurare_flag;     // offset 0x352, size 0x1
        unsigned char wrd_free[53];      // offset 0x353, size 0x35
    } wu;                                // offset 0x0, size 0x388
    struct /* @anon65 */ {
        // total size: 0x406
        unsigned short sw_lvbt;      // offset 0x0, size 0x2
        unsigned short sw_new;       // offset 0x2, size 0x2
        unsigned short sw_old;       // offset 0x4, size 0x2
        unsigned short sw_now;       // offset 0x6, size 0x2
        unsigned short sw_off;       // offset 0x8, size 0x2
        unsigned short sw_chg;       // offset 0xA, size 0x2
        unsigned short old_now;      // offset 0xC, size 0x2
        signed short lgp;            // offset 0xE, size 0x2
        unsigned char ca14;          // offset 0x10, size 0x1
        unsigned char ca25;          // offset 0x11, size 0x1
        unsigned char ca36;          // offset 0x12, size 0x1
        unsigned char calf;          // offset 0x13, size 0x1
        unsigned char calr;          // offset 0x14, size 0x1
        unsigned char lever_dir;     // offset 0x15, size 0x1
        signed short waza_flag[56];  // offset 0x16, size 0x70
        signed short reset[56];      // offset 0x86, size 0x70
        unsigned char waza_r[56][4]; // offset 0xF6, size 0xE0
        unsigned short btix[56];     // offset 0x1D6, size 0x70
        unsigned short exdt[56][4];  // offset 0x246, size 0x1C0
    } *cp;                           // offset 0x388, size 0x4
    unsigned int spmv_ng_flag;       // offset 0x38C, size 0x4
    unsigned int spmv_ng_flag2;      // offset 0x390, size 0x4
    signed short player_number;      // offset 0x394, size 0x2
    signed short zuru_timer;         // offset 0x396, size 0x2
    unsigned short zuru_ix_counter;  // offset 0x398, size 0x2
    unsigned char zuru_flag;         // offset 0x39A, size 0x1
    char tsukamarenai_flag;          // offset 0x39B, size 0x1
    unsigned char kizetsu_kow;       // offset 0x39C, size 0x1
    unsigned char micchaku_flag;     // offset 0x39D, size 0x1
    unsigned char hos_fi_flag;       // offset 0x39E, size 0x1
    unsigned char hos_em_flag;       // offset 0x39F, size 0x1
    signed short tsukami_num;        // offset 0x3A0, size 0x2
    char tsukami_f;                  // offset 0x3A2, size 0x1
    char tsukamare_f;                // offset 0x3A3, size 0x1
    char kind_of_catch;              // offset 0x3A4, size 0x1
    unsigned char old_gdflag;        // offset 0x3A5, size 0x1
    unsigned char guard_flag;        // offset 0x3A6, size 0x1
    unsigned char guard_chuu;        // offset 0x3A7, size 0x1
    signed short dm_ix;              // offset 0x3A8, size 0x2
    signed short hosei_amari;        // offset 0x3AA, size 0x2
    char dm_hos_flag;                // offset 0x3AC, size 0x1
    unsigned char dm_point;          // offset 0x3AD, size 0x1
    signed short muriyari_ugoku;     // offset 0x3AE, size 0x2
    char scr_pos_set_flag;           // offset 0x3B0, size 0x1
    char hoshi_flag;                 // offset 0x3B1, size 0x1
    char the_same_players;           // offset 0x3B2, size 0x1
    char *dm_step_tbl;               // offset 0x3B4, size 0x4
    char running_f;                  // offset 0x3B8, size 0x1
    char cancel_timer;               // offset 0x3B9, size 0x1
    char jpdir;                      // offset 0x3BA, size 0x1
    char jptim;                      // offset 0x3BB, size 0x1
    signed short current_attack;     // offset 0x3BC, size 0x2
    struct /* @anon17 */ {
        // total size: 0x6
        signed short r_no;    // offset 0x0, size 0x2
        signed short char_ix; // offset 0x2, size 0x2
        signed short data_ix; // offset 0x4, size 0x2
    } *as;                    // offset 0x3C0, size 0x4
    struct /* @anon25 */ {
        // total size: 0x2C
        signed short kind_of_arts; // offset 0x0, size 0x2
        unsigned char nmsa_g_ix;   // offset 0x2, size 0x1
        unsigned char exsa_g_ix;   // offset 0x3, size 0x1
        unsigned char exs2_g_ix;   // offset 0x4, size 0x1
        unsigned char nmsa_a_ix;   // offset 0x5, size 0x1
        unsigned char exsa_a_ix;   // offset 0x6, size 0x1
        unsigned char exs2_a_ix;   // offset 0x7, size 0x1
        char gauge_type;           // offset 0x8, size 0x1
        char mp;                   // offset 0x9, size 0x1
        char ok;                   // offset 0xA, size 0x1
        char ex;                   // offset 0xB, size 0x1
        char ba;                   // offset 0xC, size 0x1
        char dtm_mul;              // offset 0xD, size 0x1
        char mp_rno;               // offset 0xE, size 0x1
        char mp_rno2;              // offset 0xF, size 0x1
        char sa_rno;               // offset 0x10, size 0x1
        char sa_rno2;              // offset 0x11, size 0x1
        char ex_rno;               // offset 0x12, size 0x1
        char gt2;                  // offset 0x13, size 0x1
        char saeff_ok;             // offset 0x14, size 0x1
        char saeff_mp;             // offset 0x15, size 0x1
        signed short gauge_len;    // offset 0x16, size 0x2
        union /* @anon63 */ {
            signed int i; // offset 0x0, size 0x4
            struct /* @anon64 */ {
                // total size: 0x4
                signed short l;   // offset 0x0, size 0x2
                signed short h;   // offset 0x2, size 0x2
            } s;                  // offset 0x0, size 0x4
        } gauge;                  // offset 0x18, size 0x4
        signed int dtm;           // offset 0x1C, size 0x4
        signed short store_max;   // offset 0x20, size 0x2
        signed short store;       // offset 0x22, size 0x2
        signed short id_arts;     // offset 0x24, size 0x2
        unsigned char ex4th_full; // offset 0x26, size 0x1
        unsigned char ex4th_exec; // offset 0x27, size 0x1
        signed short total_gauge; // offset 0x28, size 0x2
        signed short bacckup_g_h; // offset 0x2A, size 0x2
    } *sa;                        // offset 0x3C4, size 0x4
    struct /* @anon27 */ {
        // total size: 0xA8
        signed short total;             // offset 0x0, size 0x2
        signed short new_dm;            // offset 0x2, size 0x2
        signed short req_f;             // offset 0x4, size 0x2
        signed short old_r;             // offset 0x6, size 0x2
        signed short kind_of[10][4][2]; // offset 0x8, size 0xA0
    } *cb;                              // offset 0x3C8, size 0x4
    struct /* @anon28 */ {
        // total size: 0x14
        char flag;           // offset 0x0, size 0x1
        signed short genkai; // offset 0x2, size 0x2
        signed short time;   // offset 0x4, size 0x2
        union /* @anon40 */ {
            signed int timer; // offset 0x0, size 0x4
            struct /* @anon41 */ {
                // total size: 0x4
                signed short l;    // offset 0x0, size 0x2
                signed short h;    // offset 0x2, size 0x2
            } quantity;            // offset 0x0, size 0x4
        } now;                     // offset 0x8, size 0x4
        signed int recover;        // offset 0xC, size 0x4
        signed short store;        // offset 0x10, size 0x2
        signed short again;        // offset 0x12, size 0x2
    } *py;                         // offset 0x3CC, size 0x4
    char wkey_flag;                // offset 0x3D0, size 0x1
    char dead_flag;                // offset 0x3D1, size 0x1
    signed short ukemi_ok_timer;   // offset 0x3D2, size 0x2
    signed short backup_ok_timer;  // offset 0x3D4, size 0x2
    char uot_cd_ok_flag;           // offset 0x3D6, size 0x1
    char ukemi_success;            // offset 0x3D7, size 0x1
    signed short old_pos_data[8];  // offset 0x3D8, size 0x10
    signed short move_distance;    // offset 0x3E8, size 0x2
    signed short move_power;       // offset 0x3EA, size 0x2
    signed short sa_stop_sai;      // offset 0x3EC, size 0x2
    unsigned char saishin_lvdir;   // offset 0x3EE, size 0x1
    unsigned char sa_stop_lvdir;   // offset 0x3EF, size 0x1
    unsigned char sa_stop_flag;    // offset 0x3F0, size 0x1
    unsigned char kezurijini_flag; // offset 0x3F1, size 0x1
    struct /* @anon46 */ {
        // total size: 0x388
        char be_flag;               // offset 0x0, size 0x1
        char disp_flag;             // offset 0x1, size 0x1
        unsigned char blink_timing; // offset 0x2, size 0x1
        unsigned char operator;     // offset 0x3, size 0x1
        unsigned char type;         // offset 0x4, size 0x1
        unsigned char charset_id;   // offset 0x5, size 0x1
        signed short work_id;       // offset 0x6, size 0x2
        signed short id;            // offset 0x8, size 0x2
        char rl_flag;               // offset 0xA, size 0x1
        char rl_waza;               // offset 0xB, size 0x1
        unsigned int *target_adrs;  // offset 0xC, size 0x4
        unsigned int *hit_adrs;     // offset 0x10, size 0x4
        unsigned int *dmg_adrs;     // offset 0x14, size 0x4
        signed short before;        // offset 0x18, size 0x2
        signed short myself;        // offset 0x1A, size 0x2
        signed short behind;        // offset 0x1C, size 0x2
        signed short listix;        // offset 0x1E, size 0x2
        signed short dead_f;        // offset 0x20, size 0x2
        signed short timing;        // offset 0x22, size 0x2
        signed short routine_no[8]; // offset 0x24, size 0x10
        signed short old_rno[8];    // offset 0x34, size 0x10
        signed short hit_stop;      // offset 0x44, size 0x2
        signed short hit_quake;     // offset 0x46, size 0x2
        char cgromtype;             // offset 0x48, size 0x1
        unsigned char kage_flag;    // offset 0x49, size 0x1
        signed short kage_hx;       // offset 0x4A, size 0x2
        signed short kage_hy;       // offset 0x4C, size 0x2
        signed short kage_prio;     // offset 0x4E, size 0x2
        signed short kage_width;    // offset 0x50, size 0x2
        signed short kage_char;     // offset 0x52, size 0x2
        signed short position_x;    // offset 0x54, size 0x2
        signed short position_y;    // offset 0x56, size 0x2
        signed short position_z;    // offset 0x58, size 0x2
        signed short next_x;        // offset 0x5A, size 0x2
        signed short next_y;        // offset 0x5C, size 0x2
        signed short next_z;        // offset 0x5E, size 0x2
        signed short scr_mv_x;      // offset 0x60, size 0x2
        signed short scr_mv_y;      // offset 0x62, size 0x2
        union /* @anon29 */ {
            signed int cal; // offset 0x0, size 0x4
            struct /* @anon31 */ {
                // total size: 0x4
                signed short low;    // offset 0x0, size 0x2
                signed short pos;    // offset 0x2, size 0x2
            } disp;                  // offset 0x0, size 0x4
        } xyz[3];                    // offset 0x64, size 0xC
        signed short old_pos[3];     // offset 0x70, size 0x6
        signed short sync_suzi;      // offset 0x76, size 0x2
        unsigned short *suzi_offset; // offset 0x78, size 0x4
        struct /* @anon4 */ {
            // total size: 0x18
            union /* @anon5 */ {
                signed int sp; // offset 0x0, size 0x4
                struct /* @anon7 */ {
                    // total size: 0x4
                    signed short l; // offset 0x0, size 0x2
                    signed short h; // offset 0x2, size 0x2
                } real;             // offset 0x0, size 0x4
            } a[2];                 // offset 0x0, size 0x8
            union /* @anon11 */ {
                signed int sp; // offset 0x0, size 0x4
                struct /* @anon13 */ {
                    // total size: 0x4
                    signed short l; // offset 0x0, size 0x2
                    signed short h; // offset 0x2, size 0x2
                } real;             // offset 0x0, size 0x4
            } d[2];                 // offset 0x8, size 0x8
            signed short kop[2];    // offset 0x10, size 0x4
            unsigned short index;   // offset 0x14, size 0x2
        } mvxy;                     // offset 0x7C, size 0x18
        signed short direction;     // offset 0x94, size 0x2
        signed short dir_old;       // offset 0x96, size 0x2
        signed short dir_step;      // offset 0x98, size 0x2
        signed short dir_timer;     // offset 0x9A, size 0x2
        signed short vitality;      // offset 0x9C, size 0x2
        signed short vital_new;     // offset 0x9E, size 0x2
        signed short vital_old;     // offset 0xA0, size 0x2
        signed short dm_vital;      // offset 0xA2, size 0x2
        signed short dmcal_m;       // offset 0xA4, size 0x2
        signed short dmcal_d;       // offset 0xA6, size 0x2
        char weight_level;          // offset 0xA8, size 0x1
        struct /* @anon21 */ {
            // total size: 0x8
            unsigned short code; // offset 0x0, size 0x2
            signed short koc;    // offset 0x2, size 0x2
            signed short ix;     // offset 0x4, size 0x2
            signed short pat;    // offset 0x6, size 0x2
        } cmoa;                  // offset 0xAA, size 0x8
        struct /* @anon21 */ {
            // total size: 0x8
            unsigned short code; // offset 0x0, size 0x2
            signed short koc;    // offset 0x2, size 0x2
            signed short ix;     // offset 0x4, size 0x2
            signed short pat;    // offset 0x6, size 0x2
        } cmsw;                  // offset 0xB2, size 0x8
        struct /* @anon21 */ {
            // total size: 0x8
            unsigned short code; // offset 0x0, size 0x2
            signed short koc;    // offset 0x2, size 0x2
            signed short ix;     // offset 0x4, size 0x2
            signed short pat;    // offset 0x6, size 0x2
        } cmlp;                  // offset 0xBA, size 0x8
        struct /* @anon21 */ {
            // total size: 0x8
            unsigned short code; // offset 0x0, size 0x2
            signed short koc;    // offset 0x2, size 0x2
            signed short ix;     // offset 0x4, size 0x2
            signed short pat;    // offset 0x6, size 0x2
        } cml2;                  // offset 0xC2, size 0x8
        struct /* @anon21 */ {
            // total size: 0x8
            unsigned short code; // offset 0x0, size 0x2
            signed short koc;    // offset 0x2, size 0x2
            signed short ix;     // offset 0x4, size 0x2
            signed short pat;    // offset 0x6, size 0x2
        } cmja;                  // offset 0xCA, size 0x8
        struct /* @anon21 */ {
            // total size: 0x8
            unsigned short code; // offset 0x0, size 0x2
            signed short koc;    // offset 0x2, size 0x2
            signed short ix;     // offset 0x4, size 0x2
            signed short pat;    // offset 0x6, size 0x2
        } cmj2;                  // offset 0xD2, size 0x8
        struct /* @anon21 */ {
            // total size: 0x8
            unsigned short code; // offset 0x0, size 0x2
            signed short koc;    // offset 0x2, size 0x2
            signed short ix;     // offset 0x4, size 0x2
            signed short pat;    // offset 0x6, size 0x2
        } cmj3;                  // offset 0xDA, size 0x8
        struct /* @anon21 */ {
            // total size: 0x8
            unsigned short code; // offset 0x0, size 0x2
            signed short koc;    // offset 0x2, size 0x2
            signed short ix;     // offset 0x4, size 0x2
            signed short pat;    // offset 0x6, size 0x2
        } cmj4;                  // offset 0xE2, size 0x8
        struct /* @anon21 */ {
            // total size: 0x8
            unsigned short code; // offset 0x0, size 0x2
            signed short koc;    // offset 0x2, size 0x2
            signed short ix;     // offset 0x4, size 0x2
            signed short pat;    // offset 0x6, size 0x2
        } cmj5;                  // offset 0xEA, size 0x8
        struct /* @anon21 */ {
            // total size: 0x8
            unsigned short code; // offset 0x0, size 0x2
            signed short koc;    // offset 0x2, size 0x2
            signed short ix;     // offset 0x4, size 0x2
            signed short pat;    // offset 0x6, size 0x2
        } cmj6;                  // offset 0xF2, size 0x8
        struct /* @anon21 */ {
            // total size: 0x8
            unsigned short code; // offset 0x0, size 0x2
            signed short koc;    // offset 0x2, size 0x2
            signed short ix;     // offset 0x4, size 0x2
            signed short pat;    // offset 0x6, size 0x2
        } cmj7;                  // offset 0xFA, size 0x8
        struct /* @anon21 */ {
            // total size: 0x8
            unsigned short code; // offset 0x0, size 0x2
            signed short koc;    // offset 0x2, size 0x2
            signed short ix;     // offset 0x4, size 0x2
            signed short pat;    // offset 0x6, size 0x2
        } cmms;                  // offset 0x102, size 0x8
        struct /* @anon21 */ {
            // total size: 0x8
            unsigned short code; // offset 0x0, size 0x2
            signed short koc;    // offset 0x2, size 0x2
            signed short ix;     // offset 0x4, size 0x2
            signed short pat;    // offset 0x6, size 0x2
        } cmmd;                  // offset 0x10A, size 0x8
        struct /* @anon21 */ {
            // total size: 0x8
            unsigned short code; // offset 0x0, size 0x2
            signed short koc;    // offset 0x2, size 0x2
            signed short ix;     // offset 0x4, size 0x2
            signed short pat;    // offset 0x6, size 0x2
        } cmyd;                  // offset 0x112, size 0x8
        struct /* @anon21 */ {
            // total size: 0x8
            unsigned short code; // offset 0x0, size 0x2
            signed short koc;    // offset 0x2, size 0x2
            signed short ix;     // offset 0x4, size 0x2
            signed short pat;    // offset 0x6, size 0x2
        } cmcf;                  // offset 0x11A, size 0x8
        struct /* @anon21 */ {
            // total size: 0x8
            unsigned short code; // offset 0x0, size 0x2
            signed short koc;    // offset 0x2, size 0x2
            signed short ix;     // offset 0x4, size 0x2
            signed short pat;    // offset 0x6, size 0x2
        } cmcr;                  // offset 0x122, size 0x8
        struct /* @anon21 */ {
            // total size: 0x8
            unsigned short code; // offset 0x0, size 0x2
            signed short koc;    // offset 0x2, size 0x2
            signed short ix;     // offset 0x4, size 0x2
            signed short pat;    // offset 0x6, size 0x2
        } cmbk;                  // offset 0x12A, size 0x8
        struct /* @anon21 */ {
            // total size: 0x8
            unsigned short code; // offset 0x0, size 0x2
            signed short koc;    // offset 0x2, size 0x2
            signed short ix;     // offset 0x4, size 0x2
            signed short pat;    // offset 0x6, size 0x2
        } cmb2;                  // offset 0x132, size 0x8
        struct /* @anon21 */ {
            // total size: 0x8
            unsigned short code; // offset 0x0, size 0x2
            signed short koc;    // offset 0x2, size 0x2
            signed short ix;     // offset 0x4, size 0x2
            signed short pat;    // offset 0x6, size 0x2
        } cmb3;                  // offset 0x13A, size 0x8
        struct /* @anon21 */ {
            // total size: 0x8
            unsigned short code; // offset 0x0, size 0x2
            signed short koc;    // offset 0x2, size 0x2
            signed short ix;     // offset 0x4, size 0x2
            signed short pat;    // offset 0x6, size 0x2
        } cmhs;                  // offset 0x142, size 0x8
        struct /* @anon21 */ {
            // total size: 0x8
            unsigned short code; // offset 0x0, size 0x2
            signed short koc;    // offset 0x2, size 0x2
            signed short ix;     // offset 0x4, size 0x2
            signed short pat;    // offset 0x6, size 0x2
        } cmr0;                  // offset 0x14A, size 0x8
        struct /* @anon21 */ {
            // total size: 0x8
            unsigned short code; // offset 0x0, size 0x2
            signed short koc;    // offset 0x2, size 0x2
            signed short ix;     // offset 0x4, size 0x2
            signed short pat;    // offset 0x6, size 0x2
        } cmr1;                  // offset 0x152, size 0x8
        struct /* @anon21 */ {
            // total size: 0x8
            unsigned short code; // offset 0x0, size 0x2
            signed short koc;    // offset 0x2, size 0x2
            signed short ix;     // offset 0x4, size 0x2
            signed short pat;    // offset 0x6, size 0x2
        } cmr2;                  // offset 0x15A, size 0x8
        struct /* @anon21 */ {
            // total size: 0x8
            unsigned short code;       // offset 0x0, size 0x2
            signed short koc;          // offset 0x2, size 0x2
            signed short ix;           // offset 0x4, size 0x2
            signed short pat;          // offset 0x6, size 0x2
        } cmr3;                        // offset 0x162, size 0x8
        signed short cmwk[32];         // offset 0x16A, size 0x40
        unsigned int *char_table[12];  // offset 0x1AC, size 0x30
        unsigned int *se_random_table; // offset 0x1DC, size 0x4
        signed short *step_xy_table;   // offset 0x1E0, size 0x4
        signed short *move_xy_table;   // offset 0x1E4, size 0x4
        struct /* @anon49 */ {
            // total size: 0x10
            signed short parts_hos_x;  // offset 0x0, size 0x2
            signed short parts_hos_y;  // offset 0x2, size 0x2
            unsigned char parts_colmd; // offset 0x4, size 0x1
            unsigned char parts_colcd; // offset 0x5, size 0x1
            unsigned char parts_prio;  // offset 0x6, size 0x1
            unsigned char parts_flip;  // offset 0x7, size 0x1
            unsigned char parts_timer; // offset 0x8, size 0x1
            unsigned char parts_disp;  // offset 0x9, size 0x1
            signed short parts_mts;    // offset 0xA, size 0x2
            unsigned short parts_nix;  // offset 0xC, size 0x2
            unsigned short parts_char; // offset 0xE, size 0x2
        } *overlap_char_tbl;           // offset 0x1E8, size 0x4
        struct /* @anon43 */ {
            // total size: 0x8
            signed short olc_ix[4]; // offset 0x0, size 0x8
        } *olc_ix_table;            // offset 0x1EC, size 0x4
        struct /* @anon43 */ {
            // total size: 0x8
            signed short olc_ix[4]; // offset 0x0, size 0x8
        } cg_olc;                   // offset 0x1F0, size 0x8
        struct /* @anon58 */ {
            // total size: 0x8
            signed short catch_hos_x; // offset 0x0, size 0x2
            signed short catch_hos_y; // offset 0x2, size 0x2
            unsigned char catch_prio; // offset 0x4, size 0x1
            unsigned char catch_flip; // offset 0x5, size 0x1
            signed short catch_nix;   // offset 0x6, size 0x2
        } *rival_catch_tbl;           // offset 0x1F8, size 0x4
        struct /* @anon58 */ {
            // total size: 0x8
            signed short catch_hos_x; // offset 0x0, size 0x2
            signed short catch_hos_y; // offset 0x2, size 0x2
            unsigned char catch_prio; // offset 0x4, size 0x1
            unsigned char catch_flip; // offset 0x5, size 0x1
            signed short catch_nix;   // offset 0x6, size 0x2
        } *curr_rca;                  // offset 0x1FC, size 0x4
        unsigned int *set_char_ad;    // offset 0x200, size 0x4
        signed short cg_ix;           // offset 0x204, size 0x2
        signed short now_koc;         // offset 0x206, size 0x2
        signed short char_index;      // offset 0x208, size 0x2
        signed short current_colcd;   // offset 0x20A, size 0x2
        signed short cgd_type;        // offset 0x20C, size 0x2
        unsigned char pat_status;     // offset 0x20E, size 0x1
        unsigned char kind_of_waza;   // offset 0x20F, size 0x1
        unsigned char hit_range;      // offset 0x210, size 0x1
        unsigned char total_paring;   // offset 0x211, size 0x1
        unsigned char total_att_set;  // offset 0x212, size 0x1
        unsigned char sp_tech_id;     // offset 0x213, size 0x1
        unsigned char cg_type;        // offset 0x214, size 0x1
        unsigned char cg_ctr;         // offset 0x215, size 0x1
        unsigned short cg_se;         // offset 0x216, size 0x2
        unsigned short cg_olc_ix;     // offset 0x218, size 0x2
        unsigned short cg_number;     // offset 0x21A, size 0x2
        unsigned short cg_hit_ix;     // offset 0x21C, size 0x2
        signed short cg_att_ix;       // offset 0x21E, size 0x2
        unsigned char cg_extdat;      // offset 0x220, size 0x1
        unsigned char cg_cancel;      // offset 0x221, size 0x1
        unsigned char cg_effect;      // offset 0x222, size 0x1
        unsigned char cg_eftype;      // offset 0x223, size 0x1
        unsigned short cg_zoom;       // offset 0x224, size 0x2
        unsigned short cg_rival;      // offset 0x226, size 0x2
        unsigned short cg_add_xy;     // offset 0x228, size 0x2
        unsigned char cg_next_ix;     // offset 0x22A, size 0x1
        unsigned char cg_status;      // offset 0x22B, size 0x1
        signed short cg_wca_ix;       // offset 0x22C, size 0x2
        signed short cg_jphos;        // offset 0x22E, size 0x2
        unsigned short cg_meoshi;     // offset 0x230, size 0x2
        unsigned char cg_prio;        // offset 0x232, size 0x1
        unsigned char cg_flip;        // offset 0x233, size 0x1
        unsigned short old_cgnum;     // offset 0x234, size 0x2
        signed short floor;           // offset 0x236, size 0x2
        unsigned short ccoff;         // offset 0x238, size 0x2
        signed short colcd;           // offset 0x23A, size 0x2
        signed short my_col_mode;     // offset 0x23C, size 0x2
        signed short my_col_code;     // offset 0x23E, size 0x2
        signed short my_priority;     // offset 0x240, size 0x2
        signed short my_family;       // offset 0x242, size 0x2
        signed short my_ext_pri;      // offset 0x244, size 0x2
        signed short my_bright_type;  // offset 0x246, size 0x2
        signed short my_bright_level; // offset 0x248, size 0x2
        signed short my_clear_level;  // offset 0x24A, size 0x2
        signed short my_mts;          // offset 0x24C, size 0x2
        signed short my_mr_flag;      // offset 0x24E, size 0x2
        struct /* @anon47 */ {
            // total size: 0x4
            struct /* @anon48 */ {
                // total size: 0x4
                signed short x;     // offset 0x0, size 0x2
                signed short y;     // offset 0x2, size 0x2
            } size;                 // offset 0x0, size 0x4
        } my_mr;                    // offset 0x250, size 0x4
        signed short my_trans_mode; // offset 0x254, size 0x2
        signed short my_roll_flag;  // offset 0x256, size 0x2
        struct /* @anon52 */ {
            // total size: 0x8
            signed short now;         // offset 0x0, size 0x2
            signed short add;         // offset 0x2, size 0x2
            signed short free;        // offset 0x4, size 0x2
            signed short old;         // offset 0x6, size 0x2
        } my_roll;                    // offset 0x258, size 0x8
        signed short waku_work_index; // offset 0x260, size 0x2
        signed short olc_work_ix[4];  // offset 0x262, size 0x8
        struct /* @anon6 */ {
            // total size: 0x10
            unsigned short boix; // offset 0x0, size 0x2
            unsigned short bhix; // offset 0x2, size 0x2
            unsigned short haix; // offset 0x4, size 0x2
            union /* @anon10 */ {
                unsigned short full; // offset 0x0, size 0x2
                struct /* @anon12 */ {
                    // total size: 0x2
                    unsigned char bx; // offset 0x0, size 0x1
                    unsigned char mv; // offset 0x1, size 0x1
                } half;               // offset 0x0, size 0x2
            } mf;                     // offset 0x6, size 0x2
            unsigned short caix;      // offset 0x8, size 0x2
            unsigned short cuix;      // offset 0xA, size 0x2
            unsigned short atix;      // offset 0xC, size 0x2
            unsigned short hoix;      // offset 0xE, size 0x2
        } *hit_ix_table;              // offset 0x26C, size 0x4
        struct /* @anon6 */ {
            // total size: 0x10
            unsigned short boix; // offset 0x0, size 0x2
            unsigned short bhix; // offset 0x2, size 0x2
            unsigned short haix; // offset 0x4, size 0x2
            union /* @anon10 */ {
                unsigned short full; // offset 0x0, size 0x2
                struct /* @anon12 */ {
                    // total size: 0x2
                    unsigned char bx; // offset 0x0, size 0x1
                    unsigned char mv; // offset 0x1, size 0x1
                } half;               // offset 0x0, size 0x2
            } mf;                     // offset 0x6, size 0x2
            unsigned short caix;      // offset 0x8, size 0x2
            unsigned short cuix;      // offset 0xA, size 0x2
            unsigned short atix;      // offset 0xC, size 0x2
            unsigned short hoix;      // offset 0xE, size 0x2
        } cg_ja;                      // offset 0x270, size 0x10
        struct /* @anon22 */ {
            // total size: 0x20
            signed short body_dm[4][4]; // offset 0x0, size 0x20
        } *body_adrs;                   // offset 0x280, size 0x4
        struct /* @anon22 */ {
            // total size: 0x20
            signed short body_dm[4][4]; // offset 0x0, size 0x20
        } *h_bod;                       // offset 0x284, size 0x4
        struct /* @anon26 */ {
            // total size: 0x20
            signed short hand_dm[4][4]; // offset 0x0, size 0x20
        } *hand_adrs;                   // offset 0x288, size 0x4
        struct /* @anon26 */ {
            // total size: 0x20
            signed short hand_dm[4][4]; // offset 0x0, size 0x20
        } *h_han;                       // offset 0x28C, size 0x4
        struct /* @anon26 */ {
            // total size: 0x20
            signed short hand_dm[4][4]; // offset 0x0, size 0x20
        } *dumm_adrs;                   // offset 0x290, size 0x4
        struct /* @anon26 */ {
            // total size: 0x20
            signed short hand_dm[4][4]; // offset 0x0, size 0x20
        } *h_dumm;                      // offset 0x294, size 0x4
        struct /* @anon36 */ {
            // total size: 0x8
            signed short cat_box[4]; // offset 0x0, size 0x8
        } *catch_adrs;               // offset 0x298, size 0x4
        struct /* @anon36 */ {
            // total size: 0x8
            signed short cat_box[4]; // offset 0x0, size 0x8
        } *h_cat;                    // offset 0x29C, size 0x4
        struct /* @anon39 */ {
            // total size: 0x8
            signed short cau_box[4]; // offset 0x0, size 0x8
        } *caught_adrs;              // offset 0x2A0, size 0x4
        struct /* @anon39 */ {
            // total size: 0x8
            signed short cau_box[4]; // offset 0x0, size 0x8
        } *h_cau;                    // offset 0x2A4, size 0x4
        struct /* @anon32 */ {
            // total size: 0x20
            signed short att_box[4][4]; // offset 0x0, size 0x20
        } *attack_adrs;                 // offset 0x2A8, size 0x4
        struct /* @anon32 */ {
            // total size: 0x20
            signed short att_box[4][4]; // offset 0x0, size 0x20
        } *h_att;                       // offset 0x2AC, size 0x4
        struct /* @anon32 */ {
            // total size: 0x20
            signed short att_box[4][4]; // offset 0x0, size 0x20
        } *h_eat;                       // offset 0x2B0, size 0x4
        struct /* @anon42 */ {
            // total size: 0x8
            signed short hos_box[4]; // offset 0x0, size 0x8
        } *hosei_adrs;               // offset 0x2B4, size 0x4
        struct /* @anon42 */ {
            // total size: 0x8
            signed short hos_box[4]; // offset 0x0, size 0x8
        } *h_hos;                    // offset 0x2B8, size 0x4
        struct /* @anon60 */ {
            // total size: 0x10
            unsigned char reaction; // offset 0x0, size 0x1
            unsigned char level;    // offset 0x1, size 0x1
            unsigned char mkh_ix;   // offset 0x2, size 0x1
            unsigned char but_ix;   // offset 0x3, size 0x1
            unsigned char dipsw;    // offset 0x4, size 0x1
            unsigned char guard;    // offset 0x5, size 0x1
            unsigned char dir;      // offset 0x6, size 0x1
            unsigned char free;     // offset 0x7, size 0x1
            unsigned char pow;      // offset 0x8, size 0x1
            unsigned char impact;   // offset 0x9, size 0x1
            unsigned char piyo;     // offset 0xA, size 0x1
            unsigned char ng_type;  // offset 0xB, size 0x1
            char hs_me;             // offset 0xC, size 0x1
            char hs_you;            // offset 0xD, size 0x1
            unsigned char hit_mark; // offset 0xE, size 0x1
            unsigned char dmg_mark; // offset 0xF, size 0x1
        } *att_ix_table;            // offset 0x2BC, size 0x4
        struct /* @anon60 */ {
            // total size: 0x10
            unsigned char reaction;       // offset 0x0, size 0x1
            unsigned char level;          // offset 0x1, size 0x1
            unsigned char mkh_ix;         // offset 0x2, size 0x1
            unsigned char but_ix;         // offset 0x3, size 0x1
            unsigned char dipsw;          // offset 0x4, size 0x1
            unsigned char guard;          // offset 0x5, size 0x1
            unsigned char dir;            // offset 0x6, size 0x1
            unsigned char free;           // offset 0x7, size 0x1
            unsigned char pow;            // offset 0x8, size 0x1
            unsigned char impact;         // offset 0x9, size 0x1
            unsigned char piyo;           // offset 0xA, size 0x1
            unsigned char ng_type;        // offset 0xB, size 0x1
            char hs_me;                   // offset 0xC, size 0x1
            char hs_you;                  // offset 0xD, size 0x1
            unsigned char hit_mark;       // offset 0xE, size 0x1
            unsigned char dmg_mark;       // offset 0xF, size 0x1
        } att;                            // offset 0x2C0, size 0x10
        unsigned short zu_flag;           // offset 0x2D0, size 0x2
        unsigned short at_attribute;      // offset 0x2D2, size 0x2
        signed short kezuri_pow;          // offset 0x2D4, size 0x2
        unsigned short add_arts_point;    // offset 0x2D6, size 0x2
        unsigned short buttobi_type;      // offset 0x2D8, size 0x2
        unsigned short att_zuru;          // offset 0x2DA, size 0x2
        unsigned short at_ten_ix;         // offset 0x2DC, size 0x2
        signed short dir_atthit;          // offset 0x2DE, size 0x2
        signed short vs_id;               // offset 0x2E0, size 0x2
        unsigned char att_hit_ok;         // offset 0x2E2, size 0x1
        unsigned char meoshi_hit_flag;    // offset 0x2E3, size 0x1
        unsigned short at_koa;            // offset 0x2E4, size 0x2
        unsigned char paring_attack_flag; // offset 0x2E6, size 0x1
        char no_death_attack;             // offset 0x2E7, size 0x1
        unsigned char jump_att_flag;      // offset 0x2E8, size 0x1
        char shell_vs_refrect;            // offset 0x2E9, size 0x1
        signed short renew_attack;        // offset 0x2EA, size 0x2
        unsigned short attack_num;        // offset 0x2EC, size 0x2
        unsigned short uketa_att[4];      // offset 0x2EE, size 0x8
        union /* @anon16 */ {
            struct /* @anon18 */ {
                // total size: 0x2
                unsigned char player;    // offset 0x0, size 0x1
                unsigned char effect;    // offset 0x1, size 0x1
            } hit;                       // offset 0x0, size 0x2
            unsigned short hit_flag;     // offset 0x0, size 0x2
        } hf;                            // offset 0x2F6, size 0x2
        signed short hit_mark_x;         // offset 0x2F8, size 0x2
        signed short hit_mark_y;         // offset 0x2FA, size 0x2
        signed short hit_mark_z;         // offset 0x2FC, size 0x2
        signed short kohm;               // offset 0x2FE, size 0x2
        unsigned char dm_fushin;         // offset 0x300, size 0x1
        char dm_weight;                  // offset 0x301, size 0x1
        unsigned short dm_butt_type;     // offset 0x302, size 0x2
        unsigned short dm_zuru;          // offset 0x304, size 0x2
        unsigned short dm_attribute;     // offset 0x306, size 0x2
        signed short dm_guard_success;   // offset 0x308, size 0x2
        signed short dm_plnum;           // offset 0x30A, size 0x2
        signed short dm_attlv;           // offset 0x30C, size 0x2
        signed short dm_dir;             // offset 0x30E, size 0x2
        char dm_rl;                      // offset 0x310, size 0x1
        unsigned char dm_impact;         // offset 0x311, size 0x1
        signed short dm_stop;            // offset 0x312, size 0x2
        signed short dm_quake;           // offset 0x314, size 0x2
        unsigned short dm_piyo;          // offset 0x316, size 0x2
        unsigned short dm_ten_ix;        // offset 0x318, size 0x2
        unsigned short dm_koa;           // offset 0x31A, size 0x2
        signed short dm_work_id;         // offset 0x31C, size 0x2
        unsigned short dm_arts_point;    // offset 0x31E, size 0x2
        unsigned char dm_jump_att_flag;  // offset 0x320, size 0x1
        unsigned char dm_free;           // offset 0x321, size 0x1
        signed short dm_count_up;        // offset 0x322, size 0x2
        char dm_nodeathattack;           // offset 0x324, size 0x1
        unsigned char dm_exdm_ix;        // offset 0x325, size 0x1
        unsigned char dm_dip;            // offset 0x326, size 0x1
        unsigned char dm_kind_of_waza;   // offset 0x327, size 0x1
        signed short attpow;             // offset 0x328, size 0x2
        signed short defpow;             // offset 0x32A, size 0x2
        unsigned int *my_effadrs;        // offset 0x32C, size 0x4
        signed short shell_ix[8];        // offset 0x330, size 0x10
        signed short hm_dm_side;         // offset 0x340, size 0x2
        signed short extra_col;          // offset 0x342, size 0x2
        signed short extra_col_2;        // offset 0x344, size 0x2
        signed short original_vitality;  // offset 0x346, size 0x2
        unsigned char hit_work_id;       // offset 0x348, size 0x1
        unsigned char dmg_work_id;       // offset 0x349, size 0x1
        char K5_init_flag;               // offset 0x34A, size 0x1
        char K5_exec_ok;                 // offset 0x34B, size 0x1
        unsigned char kow;               // offset 0x34C, size 0x1
        unsigned char swallow_no_effect; // offset 0x34D, size 0x1
        signed short E3_work_index;      // offset 0x34E, size 0x2
        signed short E4_work_index;      // offset 0x350, size 0x2
        unsigned char kezurare_flag;     // offset 0x352, size 0x1
        unsigned char wrd_free[53];      // offset 0x353, size 0x35
    } *illusion_work;                    // offset 0x3F4, size 0x4
    signed short image_setup_flag;       // offset 0x3F8, size 0x2
    signed short image_data_index;       // offset 0x3FA, size 0x2
    unsigned char caution_flag;          // offset 0x3FC, size 0x1
    unsigned char tc_1st_flag;           // offset 0x3FD, size 0x1
    struct /* @anon27 */ {
        // total size: 0xA8
        signed short total;             // offset 0x0, size 0x2
        signed short new_dm;            // offset 0x2, size 0x2
        signed short req_f;             // offset 0x4, size 0x2
        signed short old_r;             // offset 0x6, size 0x2
        signed short kind_of[10][4][2]; // offset 0x8, size 0xA0
    } *rp;                              // offset 0x400, size 0x4
    signed short bullet_hcnt;           // offset 0x404, size 0x2
    signed short bhcnt_timer;           // offset 0x406, size 0x2
    char cat_break_ok_timer;            // offset 0x408, size 0x1
    char cat_break_reserve;             // offset 0x409, size 0x1
    char hazusenai_flag;                // offset 0x40A, size 0x1
    char hurimukenai_flag;              // offset 0x40B, size 0x1
    unsigned char tk_success;           // offset 0x40C, size 0x1
    unsigned char resurrection_resv;    // offset 0x40D, size 0x1
    signed short tk_dageki;             // offset 0x40E, size 0x2
    signed short tk_nage;               // offset 0x410, size 0x2
    signed short tk_kizetsu;            // offset 0x412, size 0x2
    signed short tk_konjyou;            // offset 0x414, size 0x2
    signed short utk_dageki;            // offset 0x416, size 0x2
    signed short utk_nage;              // offset 0x418, size 0x2
    signed short utk_kizetsu;           // offset 0x41A, size 0x2
    unsigned char atemi_flag;           // offset 0x41C, size 0x1
    unsigned char atemi_point;          // offset 0x41D, size 0x1
    signed short dm_vital_backup;       // offset 0x41E, size 0x2
    unsigned char dm_refrect;           // offset 0x420, size 0x1
    unsigned char dm_vital_use;         // offset 0x421, size 0x1
    unsigned char exdm_ix;              // offset 0x422, size 0x1
    unsigned char meoshi_jump_flag;     // offset 0x423, size 0x1
    signed short cmd_request;           // offset 0x424, size 0x2
    signed short rl_save;               // offset 0x426, size 0x2
    unsigned char zettai_muteki_flag;   // offset 0x428, size 0x1
    unsigned char do_not_move;          // offset 0x429, size 0x1
    unsigned short just_sa_stop_timer;  // offset 0x42A, size 0x2
    signed short total_att_hit_ok;      // offset 0x42C, size 0x2
    unsigned char sa_healing;           // offset 0x42E, size 0x1
    unsigned char auto_guard;           // offset 0x42F, size 0x1
    unsigned char hsjp_ok;              // offset 0x430, size 0x1
    unsigned char high_jump_flag;       // offset 0x431, size 0x1
    signed short att_plus;              // offset 0x432, size 0x2
    signed short def_plus;              // offset 0x434, size 0x2
    char bs2_on_car;                    // offset 0x436, size 0x1
    char bs2_area_car;                  // offset 0x437, size 0x1
    char bs2_over_car;                  // offset 0x438, size 0x1
    char bs2_area_car2;                 // offset 0x439, size 0x1
    char bs2_over_car2;                 // offset 0x43A, size 0x1
    unsigned char micchaku_wall_time;   // offset 0x43B, size 0x1
    unsigned char extra_jump;           // offset 0x43C, size 0x1
    unsigned char air_jump_ok_time;     // offset 0x43D, size 0x1
    signed short waku_ram_index;        // offset 0x43E, size 0x2
    unsigned short permited_koa;        // offset 0x440, size 0x2
    unsigned char ja_nmj_rno;           // offset 0x442, size 0x1
    unsigned char ja_nmj_cnt;           // offset 0x443, size 0x1
    unsigned char kind_of_blocking;     // offset 0x444, size 0x1
    unsigned char metamorphose;         // offset 0x445, size 0x1
    signed short metamor_index;         // offset 0x446, size 0x2
    unsigned char metamor_over;         // offset 0x448, size 0x1
    unsigned char gill_ccch_go;         // offset 0x449, size 0x1
    unsigned char renew_attchar;        // offset 0x44A, size 0x1
    signed short omop_vital_timer;      // offset 0x44C, size 0x2
    signed short sfwing_pos;            // offset 0x44E, size 0x2
    unsigned char init_E3_flag;         // offset 0x450, size 0x1
    unsigned char init_E4_flag;         // offset 0x451, size 0x1
    unsigned short pl09_dat_index;      // offset 0x452, size 0x2
    signed short reserv_add_y;          // offset 0x454, size 0x2
    unsigned char pt_free[20];          // offset 0x456, size 0x14
} PLW;

typedef struct {
    // total size: 0x470
    unsigned int VideoMode;        // offset 0x0, size 0x4
    unsigned int InterlaceMode;    // offset 0x4, size 0x4
    unsigned int DisplayMode;      // offset 0x8, size 0x4
    signed int DispWidth;          // offset 0xC, size 0x4
    signed int DispHeight;         // offset 0x10, size 0x4
    unsigned int MAGH;             // offset 0x14, size 0x4
    unsigned int FrameBitDepth;    // offset 0x18, size 0x4
    unsigned int FrameBuffForm;    // offset 0x1C, size 0x4
    unsigned int FrameBuffPageX;   // offset 0x20, size 0x4
    unsigned int FrameBuffPageY;   // offset 0x24, size 0x4
    unsigned int FrameBuffAdrs0;   // offset 0x28, size 0x4
    unsigned int FrameBuffAdrs1;   // offset 0x2C, size 0x4
    unsigned int ZBuffBitDepth;    // offset 0x30, size 0x4
    unsigned int ZBuffForm;        // offset 0x34, size 0x4
    unsigned int ZBuffPageX;       // offset 0x38, size 0x4
    unsigned int ZBuffPageY;       // offset 0x3C, size 0x4
    unsigned int ZBuffAdrs;        // offset 0x40, size 0x4
    float ZBuffMax;                // offset 0x44, size 0x4
    unsigned int TextureStartAdrs; // offset 0x48, size 0x4
    signed int Oddeven;            // offset 0x4C, size 0x4
    signed int Dbi;                // offset 0x50, size 0x4
    signed int FrameCount;         // offset 0x54, size 0x4
    signed int FrameCountNext;     // offset 0x58, size 0x4
    signed int Irq_count;          // offset 0x5C, size 0x4
    signed int Db_change_enable;   // offset 0x60, size 0x4
    struct /* @anon25 */ {
        // total size: 0x330
        struct /* @anon31 */ {
            // total size: 0x28
            struct /* @anon10 */ {
                // total size: 0x8
                unsigned int EN1 : 1;   // offset 0x0, size 0x4
                unsigned int EN2 : 1;   // offset 0x0, size 0x4
                unsigned int CRTMD : 3; // offset 0x0, size 0x4
                unsigned int MMOD : 1;  // offset 0x0, size 0x4
                unsigned int AMOD : 1;  // offset 0x0, size 0x4
                unsigned int SLBG : 1;  // offset 0x0, size 0x4
                unsigned int ALP : 8;   // offset 0x0, size 0x4
                unsigned int p0 : 16;   // offset 0x0, size 0x4
                unsigned int p1;        // offset 0x4, size 0x4
            } pmode;                    // offset 0x0, size 0x8
            struct /* @anon15 */ {
                // total size: 0x8
                unsigned int INT : 1;  // offset 0x0, size 0x4
                unsigned int FFMD : 1; // offset 0x0, size 0x4
                unsigned int DPMS : 2; // offset 0x0, size 0x4
                unsigned int p0 : 28;  // offset 0x0, size 0x4
                unsigned int p1;       // offset 0x4, size 0x4
            } smode2;                  // offset 0x8, size 0x8
            struct /* @anon11 */ {
                // total size: 0x8
                unsigned int FBP : 9;  // offset 0x0, size 0x4
                unsigned int FBW : 6;  // offset 0x0, size 0x4
                unsigned int PSM : 5;  // offset 0x0, size 0x4
                unsigned int p0 : 12;  // offset 0x0, size 0x4
                unsigned int DBX : 11; // offset 0x4, size 0x4
                unsigned int DBY : 11; // offset 0x4, size 0x4
                unsigned int p1 : 10;  // offset 0x4, size 0x4
            } dispfb;                  // offset 0x10, size 0x8
            struct /* @anon19 */ {
                // total size: 0x8
                unsigned int DX : 12;  // offset 0x0, size 0x4
                unsigned int DY : 11;  // offset 0x0, size 0x4
                unsigned int MAGH : 4; // offset 0x0, size 0x4
                unsigned int MAGV : 2; // offset 0x0, size 0x4
                unsigned int p0 : 3;   // offset 0x0, size 0x4
                unsigned int DW : 12;  // offset 0x4, size 0x4
                unsigned int DH : 11;  // offset 0x4, size 0x4
                unsigned int p1 : 9;   // offset 0x4, size 0x4
            } display;                 // offset 0x18, size 0x8
            struct /* @anon17 */ {
                // total size: 0x8
                unsigned int R : 8;  // offset 0x0, size 0x4
                unsigned int G : 8;  // offset 0x0, size 0x4
                unsigned int B : 8;  // offset 0x0, size 0x4
                unsigned int p0 : 8; // offset 0x0, size 0x4
                unsigned int p1;     // offset 0x4, size 0x4
            } bgcolor;               // offset 0x20, size 0x8
        } disp[2];                   // offset 0x0, size 0x50
        struct /* @anon6 */ {
            // total size: 0x10
            unsigned long long NLOOP : 15; // offset 0x0, size 0x4
            unsigned long long EOP : 1;    // offset 0x0, size 0x4
            unsigned long long pad16 : 16; // offset 0x0, size 0x4
            unsigned long long id : 14;    // offset 0x0, size 0x4
            unsigned long long PRE : 1;    // offset 0x0, size 0x4
            unsigned long long PRIM : 11;  // offset 0x0, size 0x4
            unsigned long long FLG : 2;    // offset 0x0, size 0x4
            unsigned long long NREG : 4;   // offset 0x0, size 0x4
            unsigned long long REGS0 : 4;  // offset 0x8, size 0x4
            unsigned long long REGS1 : 4;  // offset 0x8, size 0x4
            unsigned long long REGS2 : 4;  // offset 0x8, size 0x4
            unsigned long long REGS3 : 4;  // offset 0x8, size 0x4
            unsigned long long REGS4 : 4;  // offset 0x8, size 0x4
            unsigned long long REGS5 : 4;  // offset 0x8, size 0x4
            unsigned long long REGS6 : 4;  // offset 0x8, size 0x4
            unsigned long long REGS7 : 4;  // offset 0x8, size 0x4
            unsigned long long REGS8 : 4;  // offset 0x8, size 0x4
            unsigned long long REGS9 : 4;  // offset 0x8, size 0x4
            unsigned long long REGS10 : 4; // offset 0x8, size 0x4
            unsigned long long REGS11 : 4; // offset 0x8, size 0x4
            unsigned long long REGS12 : 4; // offset 0x8, size 0x4
            unsigned long long REGS13 : 4; // offset 0x8, size 0x4
            unsigned long long REGS14 : 4; // offset 0x8, size 0x4
            unsigned long long REGS15 : 4; // offset 0x8, size 0x4
        } giftag0;                         // offset 0x50, size 0x10
        struct /* @anon32 */ {
            // total size: 0x80
            struct /* @anon16 */ {
                // total size: 0x8
                unsigned long long FBP : 9;    // offset 0x0, size 0x4
                unsigned long long pad09 : 7;  // offset 0x0, size 0x4
                unsigned long long FBW : 6;    // offset 0x0, size 0x4
                unsigned long long pad22 : 2;  // offset 0x0, size 0x4
                unsigned long long PSM : 6;    // offset 0x0, size 0x4
                unsigned long long pad30 : 2;  // offset 0x0, size 0x4
                unsigned long long FBMSK : 32; // offset 0x0, size 0x4
            } frame1;                          // offset 0x0, size 0x8
            unsigned long long frame1addr;     // offset 0x8, size 0x4
            struct /* @anon28 */ {
                // total size: 0x8
                unsigned long long ZBP : 9;    // offset 0x0, size 0x4
                unsigned long long pad09 : 15; // offset 0x0, size 0x4
                unsigned long long PSM : 4;    // offset 0x0, size 0x4
                unsigned long long pad28 : 4;  // offset 0x0, size 0x4
                unsigned long long ZMSK : 1;   // offset 0x0, size 0x4
                unsigned long long pad33 : 31; // offset 0x0, size 0x4
            } zbuf1;                           // offset 0x10, size 0x8
            signed long zbuf1addr;             // offset 0x18, size 0x4
            struct /* @anon21 */ {
                // total size: 0x8
                unsigned long long OFX : 16;   // offset 0x0, size 0x4
                unsigned long long pad16 : 16; // offset 0x0, size 0x4
                unsigned long long OFY : 16;   // offset 0x0, size 0x4
                unsigned long long pad48 : 16; // offset 0x0, size 0x4
            } xyoffset1;                       // offset 0x20, size 0x8
            signed long xyoffset1addr;         // offset 0x28, size 0x4
            struct /* @anon12 */ {
                // total size: 0x8
                unsigned long long SCAX0 : 11; // offset 0x0, size 0x4
                unsigned long long pad11 : 5;  // offset 0x0, size 0x4
                unsigned long long SCAX1 : 11; // offset 0x0, size 0x4
                unsigned long long pad27 : 5;  // offset 0x0, size 0x4
                unsigned long long SCAY0 : 11; // offset 0x0, size 0x4
                unsigned long long pad43 : 5;  // offset 0x0, size 0x4
                unsigned long long SCAY1 : 11; // offset 0x0, size 0x4
                unsigned long long pad59 : 5;  // offset 0x0, size 0x4
            } scissor1;                        // offset 0x30, size 0x8
            signed long scissor1addr;          // offset 0x38, size 0x4
            struct /* @anon5 */ {
                // total size: 0x8
                unsigned long long AC : 1;     // offset 0x0, size 0x4
                unsigned long long pad01 : 63; // offset 0x0, size 0x4
            } prmodecont;                      // offset 0x40, size 0x8
            signed long prmodecontaddr;        // offset 0x48, size 0x4
            struct /* @anon27 */ {
                // total size: 0x8
                unsigned long long CLAMP : 1;  // offset 0x0, size 0x4
                unsigned long long pad01 : 63; // offset 0x0, size 0x4
            } colclamp;                        // offset 0x50, size 0x8
            signed long colclampaddr;          // offset 0x58, size 0x4
            struct /* @anon9 */ {
                // total size: 0x8
                unsigned long long DTHE : 1;   // offset 0x0, size 0x4
                unsigned long long pad01 : 63; // offset 0x0, size 0x4
            } dthe;                            // offset 0x60, size 0x8
            signed long dtheaddr;              // offset 0x68, size 0x4
            struct /* @anon20 */ {
                // total size: 0x8
                unsigned long long ATE : 1;    // offset 0x0, size 0x4
                unsigned long long ATST : 3;   // offset 0x0, size 0x4
                unsigned long long AREF : 8;   // offset 0x0, size 0x4
                unsigned long long AFAIL : 2;  // offset 0x0, size 0x4
                unsigned long long DATE : 1;   // offset 0x0, size 0x4
                unsigned long long DATM : 1;   // offset 0x0, size 0x4
                unsigned long long ZTE : 1;    // offset 0x0, size 0x4
                unsigned long long ZTST : 2;   // offset 0x0, size 0x4
                unsigned long long pad19 : 45; // offset 0x0, size 0x4
            } test1;                           // offset 0x70, size 0x8
            signed long test1addr;             // offset 0x78, size 0x4
        } draw01;                              // offset 0x60, size 0x80
        struct /* @anon8 */ {
            // total size: 0x80
            struct /* @anon16 */ {
                // total size: 0x8
                unsigned long long FBP : 9;    // offset 0x0, size 0x4
                unsigned long long pad09 : 7;  // offset 0x0, size 0x4
                unsigned long long FBW : 6;    // offset 0x0, size 0x4
                unsigned long long pad22 : 2;  // offset 0x0, size 0x4
                unsigned long long PSM : 6;    // offset 0x0, size 0x4
                unsigned long long pad30 : 2;  // offset 0x0, size 0x4
                unsigned long long FBMSK : 32; // offset 0x0, size 0x4
            } frame2;                          // offset 0x0, size 0x8
            unsigned long long frame2addr;     // offset 0x8, size 0x4
            struct /* @anon28 */ {
                // total size: 0x8
                unsigned long long ZBP : 9;    // offset 0x0, size 0x4
                unsigned long long pad09 : 15; // offset 0x0, size 0x4
                unsigned long long PSM : 4;    // offset 0x0, size 0x4
                unsigned long long pad28 : 4;  // offset 0x0, size 0x4
                unsigned long long ZMSK : 1;   // offset 0x0, size 0x4
                unsigned long long pad33 : 31; // offset 0x0, size 0x4
            } zbuf2;                           // offset 0x10, size 0x8
            signed long zbuf2addr;             // offset 0x18, size 0x4
            struct /* @anon21 */ {
                // total size: 0x8
                unsigned long long OFX : 16;   // offset 0x0, size 0x4
                unsigned long long pad16 : 16; // offset 0x0, size 0x4
                unsigned long long OFY : 16;   // offset 0x0, size 0x4
                unsigned long long pad48 : 16; // offset 0x0, size 0x4
            } xyoffset2;                       // offset 0x20, size 0x8
            signed long xyoffset2addr;         // offset 0x28, size 0x4
            struct /* @anon12 */ {
                // total size: 0x8
                unsigned long long SCAX0 : 11; // offset 0x0, size 0x4
                unsigned long long pad11 : 5;  // offset 0x0, size 0x4
                unsigned long long SCAX1 : 11; // offset 0x0, size 0x4
                unsigned long long pad27 : 5;  // offset 0x0, size 0x4
                unsigned long long SCAY0 : 11; // offset 0x0, size 0x4
                unsigned long long pad43 : 5;  // offset 0x0, size 0x4
                unsigned long long SCAY1 : 11; // offset 0x0, size 0x4
                unsigned long long pad59 : 5;  // offset 0x0, size 0x4
            } scissor2;                        // offset 0x30, size 0x8
            signed long scissor2addr;          // offset 0x38, size 0x4
            struct /* @anon5 */ {
                // total size: 0x8
                unsigned long long AC : 1;     // offset 0x0, size 0x4
                unsigned long long pad01 : 63; // offset 0x0, size 0x4
            } prmodecont;                      // offset 0x40, size 0x8
            signed long prmodecontaddr;        // offset 0x48, size 0x4
            struct /* @anon27 */ {
                // total size: 0x8
                unsigned long long CLAMP : 1;  // offset 0x0, size 0x4
                unsigned long long pad01 : 63; // offset 0x0, size 0x4
            } colclamp;                        // offset 0x50, size 0x8
            signed long colclampaddr;          // offset 0x58, size 0x4
            struct /* @anon9 */ {
                // total size: 0x8
                unsigned long long DTHE : 1;   // offset 0x0, size 0x4
                unsigned long long pad01 : 63; // offset 0x0, size 0x4
            } dthe;                            // offset 0x60, size 0x8
            signed long dtheaddr;              // offset 0x68, size 0x4
            struct /* @anon20 */ {
                // total size: 0x8
                unsigned long long ATE : 1;    // offset 0x0, size 0x4
                unsigned long long ATST : 3;   // offset 0x0, size 0x4
                unsigned long long AREF : 8;   // offset 0x0, size 0x4
                unsigned long long AFAIL : 2;  // offset 0x0, size 0x4
                unsigned long long DATE : 1;   // offset 0x0, size 0x4
                unsigned long long DATM : 1;   // offset 0x0, size 0x4
                unsigned long long ZTE : 1;    // offset 0x0, size 0x4
                unsigned long long ZTST : 2;   // offset 0x0, size 0x4
                unsigned long long pad19 : 45; // offset 0x0, size 0x4
            } test2;                           // offset 0x70, size 0x8
            signed long test2addr;             // offset 0x78, size 0x4
        } draw02;                              // offset 0xE0, size 0x80
        struct /* @anon14 */ {
            // total size: 0x60
            struct /* @anon20 */ {
                // total size: 0x8
                unsigned long long ATE : 1;    // offset 0x0, size 0x4
                unsigned long long ATST : 3;   // offset 0x0, size 0x4
                unsigned long long AREF : 8;   // offset 0x0, size 0x4
                unsigned long long AFAIL : 2;  // offset 0x0, size 0x4
                unsigned long long DATE : 1;   // offset 0x0, size 0x4
                unsigned long long DATM : 1;   // offset 0x0, size 0x4
                unsigned long long ZTE : 1;    // offset 0x0, size 0x4
                unsigned long long ZTST : 2;   // offset 0x0, size 0x4
                unsigned long long pad19 : 45; // offset 0x0, size 0x4
            } testa;                           // offset 0x0, size 0x8
            signed long testaaddr;             // offset 0x8, size 0x4
            struct /* @anon30 */ {
                // total size: 0x8
                unsigned long long PRIM : 3;   // offset 0x0, size 0x4
                unsigned long long IIP : 1;    // offset 0x0, size 0x4
                unsigned long long TME : 1;    // offset 0x0, size 0x4
                unsigned long long FGE : 1;    // offset 0x0, size 0x4
                unsigned long long ABE : 1;    // offset 0x0, size 0x4
                unsigned long long AA1 : 1;    // offset 0x0, size 0x4
                unsigned long long FST : 1;    // offset 0x0, size 0x4
                unsigned long long CTXT : 1;   // offset 0x0, size 0x4
                unsigned long long FIX : 1;    // offset 0x0, size 0x4
                unsigned long long pad11 : 53; // offset 0x0, size 0x4
            } prim;                            // offset 0x10, size 0x8
            signed long primaddr;              // offset 0x18, size 0x4
            struct /* @anon7 */ {
                // total size: 0x8
                unsigned int R : 8; // offset 0x0, size 0x4
                unsigned int G : 8; // offset 0x0, size 0x4
                unsigned int B : 8; // offset 0x0, size 0x4
                unsigned int A : 8; // offset 0x0, size 0x4
                float Q;            // offset 0x4, size 0x4
            } rgbaq;                // offset 0x20, size 0x8
            signed long rgbaqaddr;  // offset 0x28, size 0x4
            struct /* @anon24 */ {
                // total size: 0x8
                unsigned long long X : 16; // offset 0x0, size 0x4
                unsigned long long Y : 16; // offset 0x0, size 0x4
                unsigned long long Z : 32; // offset 0x0, size 0x4
            } xyz2a;                       // offset 0x30, size 0x8
            signed long xyz2aaddr;         // offset 0x38, size 0x4
            struct /* @anon24 */ {
                // total size: 0x8
                unsigned long long X : 16; // offset 0x0, size 0x4
                unsigned long long Y : 16; // offset 0x0, size 0x4
                unsigned long long Z : 32; // offset 0x0, size 0x4
            } xyz2b;                       // offset 0x40, size 0x8
            signed long xyz2baddr;         // offset 0x48, size 0x4
            struct /* @anon20 */ {
                // total size: 0x8
                unsigned long long ATE : 1;    // offset 0x0, size 0x4
                unsigned long long ATST : 3;   // offset 0x0, size 0x4
                unsigned long long AREF : 8;   // offset 0x0, size 0x4
                unsigned long long AFAIL : 2;  // offset 0x0, size 0x4
                unsigned long long DATE : 1;   // offset 0x0, size 0x4
                unsigned long long DATM : 1;   // offset 0x0, size 0x4
                unsigned long long ZTE : 1;    // offset 0x0, size 0x4
                unsigned long long ZTST : 2;   // offset 0x0, size 0x4
                unsigned long long pad19 : 45; // offset 0x0, size 0x4
            } testb;                           // offset 0x50, size 0x8
            signed long testbaddr;             // offset 0x58, size 0x4
        } clear0;                              // offset 0x160, size 0x60
        struct /* @anon6 */ {
            // total size: 0x10
            unsigned long long NLOOP : 15; // offset 0x0, size 0x4
            unsigned long long EOP : 1;    // offset 0x0, size 0x4
            unsigned long long pad16 : 16; // offset 0x0, size 0x4
            unsigned long long id : 14;    // offset 0x0, size 0x4
            unsigned long long PRE : 1;    // offset 0x0, size 0x4
            unsigned long long PRIM : 11;  // offset 0x0, size 0x4
            unsigned long long FLG : 2;    // offset 0x0, size 0x4
            unsigned long long NREG : 4;   // offset 0x0, size 0x4
            unsigned long long REGS0 : 4;  // offset 0x8, size 0x4
            unsigned long long REGS1 : 4;  // offset 0x8, size 0x4
            unsigned long long REGS2 : 4;  // offset 0x8, size 0x4
            unsigned long long REGS3 : 4;  // offset 0x8, size 0x4
            unsigned long long REGS4 : 4;  // offset 0x8, size 0x4
            unsigned long long REGS5 : 4;  // offset 0x8, size 0x4
            unsigned long long REGS6 : 4;  // offset 0x8, size 0x4
            unsigned long long REGS7 : 4;  // offset 0x8, size 0x4
            unsigned long long REGS8 : 4;  // offset 0x8, size 0x4
            unsigned long long REGS9 : 4;  // offset 0x8, size 0x4
            unsigned long long REGS10 : 4; // offset 0x8, size 0x4
            unsigned long long REGS11 : 4; // offset 0x8, size 0x4
            unsigned long long REGS12 : 4; // offset 0x8, size 0x4
            unsigned long long REGS13 : 4; // offset 0x8, size 0x4
            unsigned long long REGS14 : 4; // offset 0x8, size 0x4
            unsigned long long REGS15 : 4; // offset 0x8, size 0x4
        } giftag1;                         // offset 0x1C0, size 0x10
        struct /* @anon32 */ {
            // total size: 0x80
            struct /* @anon16 */ {
                // total size: 0x8
                unsigned long long FBP : 9;    // offset 0x0, size 0x4
                unsigned long long pad09 : 7;  // offset 0x0, size 0x4
                unsigned long long FBW : 6;    // offset 0x0, size 0x4
                unsigned long long pad22 : 2;  // offset 0x0, size 0x4
                unsigned long long PSM : 6;    // offset 0x0, size 0x4
                unsigned long long pad30 : 2;  // offset 0x0, size 0x4
                unsigned long long FBMSK : 32; // offset 0x0, size 0x4
            } frame1;                          // offset 0x0, size 0x8
            unsigned long long frame1addr;     // offset 0x8, size 0x4
            struct /* @anon28 */ {
                // total size: 0x8
                unsigned long long ZBP : 9;    // offset 0x0, size 0x4
                unsigned long long pad09 : 15; // offset 0x0, size 0x4
                unsigned long long PSM : 4;    // offset 0x0, size 0x4
                unsigned long long pad28 : 4;  // offset 0x0, size 0x4
                unsigned long long ZMSK : 1;   // offset 0x0, size 0x4
                unsigned long long pad33 : 31; // offset 0x0, size 0x4
            } zbuf1;                           // offset 0x10, size 0x8
            signed long zbuf1addr;             // offset 0x18, size 0x4
            struct /* @anon21 */ {
                // total size: 0x8
                unsigned long long OFX : 16;   // offset 0x0, size 0x4
                unsigned long long pad16 : 16; // offset 0x0, size 0x4
                unsigned long long OFY : 16;   // offset 0x0, size 0x4
                unsigned long long pad48 : 16; // offset 0x0, size 0x4
            } xyoffset1;                       // offset 0x20, size 0x8
            signed long xyoffset1addr;         // offset 0x28, size 0x4
            struct /* @anon12 */ {
                // total size: 0x8
                unsigned long long SCAX0 : 11; // offset 0x0, size 0x4
                unsigned long long pad11 : 5;  // offset 0x0, size 0x4
                unsigned long long SCAX1 : 11; // offset 0x0, size 0x4
                unsigned long long pad27 : 5;  // offset 0x0, size 0x4
                unsigned long long SCAY0 : 11; // offset 0x0, size 0x4
                unsigned long long pad43 : 5;  // offset 0x0, size 0x4
                unsigned long long SCAY1 : 11; // offset 0x0, size 0x4
                unsigned long long pad59 : 5;  // offset 0x0, size 0x4
            } scissor1;                        // offset 0x30, size 0x8
            signed long scissor1addr;          // offset 0x38, size 0x4
            struct /* @anon5 */ {
                // total size: 0x8
                unsigned long long AC : 1;     // offset 0x0, size 0x4
                unsigned long long pad01 : 63; // offset 0x0, size 0x4
            } prmodecont;                      // offset 0x40, size 0x8
            signed long prmodecontaddr;        // offset 0x48, size 0x4
            struct /* @anon27 */ {
                // total size: 0x8
                unsigned long long CLAMP : 1;  // offset 0x0, size 0x4
                unsigned long long pad01 : 63; // offset 0x0, size 0x4
            } colclamp;                        // offset 0x50, size 0x8
            signed long colclampaddr;          // offset 0x58, size 0x4
            struct /* @anon9 */ {
                // total size: 0x8
                unsigned long long DTHE : 1;   // offset 0x0, size 0x4
                unsigned long long pad01 : 63; // offset 0x0, size 0x4
            } dthe;                            // offset 0x60, size 0x8
            signed long dtheaddr;              // offset 0x68, size 0x4
            struct /* @anon20 */ {
                // total size: 0x8
                unsigned long long ATE : 1;    // offset 0x0, size 0x4
                unsigned long long ATST : 3;   // offset 0x0, size 0x4
                unsigned long long AREF : 8;   // offset 0x0, size 0x4
                unsigned long long AFAIL : 2;  // offset 0x0, size 0x4
                unsigned long long DATE : 1;   // offset 0x0, size 0x4
                unsigned long long DATM : 1;   // offset 0x0, size 0x4
                unsigned long long ZTE : 1;    // offset 0x0, size 0x4
                unsigned long long ZTST : 2;   // offset 0x0, size 0x4
                unsigned long long pad19 : 45; // offset 0x0, size 0x4
            } test1;                           // offset 0x70, size 0x8
            signed long test1addr;             // offset 0x78, size 0x4
        } draw11;                              // offset 0x1D0, size 0x80
        struct /* @anon8 */ {
            // total size: 0x80
            struct /* @anon16 */ {
                // total size: 0x8
                unsigned long long FBP : 9;    // offset 0x0, size 0x4
                unsigned long long pad09 : 7;  // offset 0x0, size 0x4
                unsigned long long FBW : 6;    // offset 0x0, size 0x4
                unsigned long long pad22 : 2;  // offset 0x0, size 0x4
                unsigned long long PSM : 6;    // offset 0x0, size 0x4
                unsigned long long pad30 : 2;  // offset 0x0, size 0x4
                unsigned long long FBMSK : 32; // offset 0x0, size 0x4
            } frame2;                          // offset 0x0, size 0x8
            unsigned long long frame2addr;     // offset 0x8, size 0x4
            struct /* @anon28 */ {
                // total size: 0x8
                unsigned long long ZBP : 9;    // offset 0x0, size 0x4
                unsigned long long pad09 : 15; // offset 0x0, size 0x4
                unsigned long long PSM : 4;    // offset 0x0, size 0x4
                unsigned long long pad28 : 4;  // offset 0x0, size 0x4
                unsigned long long ZMSK : 1;   // offset 0x0, size 0x4
                unsigned long long pad33 : 31; // offset 0x0, size 0x4
            } zbuf2;                           // offset 0x10, size 0x8
            signed long zbuf2addr;             // offset 0x18, size 0x4
            struct /* @anon21 */ {
                // total size: 0x8
                unsigned long long OFX : 16;   // offset 0x0, size 0x4
                unsigned long long pad16 : 16; // offset 0x0, size 0x4
                unsigned long long OFY : 16;   // offset 0x0, size 0x4
                unsigned long long pad48 : 16; // offset 0x0, size 0x4
            } xyoffset2;                       // offset 0x20, size 0x8
            signed long xyoffset2addr;         // offset 0x28, size 0x4
            struct /* @anon12 */ {
                // total size: 0x8
                unsigned long long SCAX0 : 11; // offset 0x0, size 0x4
                unsigned long long pad11 : 5;  // offset 0x0, size 0x4
                unsigned long long SCAX1 : 11; // offset 0x0, size 0x4
                unsigned long long pad27 : 5;  // offset 0x0, size 0x4
                unsigned long long SCAY0 : 11; // offset 0x0, size 0x4
                unsigned long long pad43 : 5;  // offset 0x0, size 0x4
                unsigned long long SCAY1 : 11; // offset 0x0, size 0x4
                unsigned long long pad59 : 5;  // offset 0x0, size 0x4
            } scissor2;                        // offset 0x30, size 0x8
            signed long scissor2addr;          // offset 0x38, size 0x4
            struct /* @anon5 */ {
                // total size: 0x8
                unsigned long long AC : 1;     // offset 0x0, size 0x4
                unsigned long long pad01 : 63; // offset 0x0, size 0x4
            } prmodecont;                      // offset 0x40, size 0x8
            signed long prmodecontaddr;        // offset 0x48, size 0x4
            struct /* @anon27 */ {
                // total size: 0x8
                unsigned long long CLAMP : 1;  // offset 0x0, size 0x4
                unsigned long long pad01 : 63; // offset 0x0, size 0x4
            } colclamp;                        // offset 0x50, size 0x8
            signed long colclampaddr;          // offset 0x58, size 0x4
            struct /* @anon9 */ {
                // total size: 0x8
                unsigned long long DTHE : 1;   // offset 0x0, size 0x4
                unsigned long long pad01 : 63; // offset 0x0, size 0x4
            } dthe;                            // offset 0x60, size 0x8
            signed long dtheaddr;              // offset 0x68, size 0x4
            struct /* @anon20 */ {
                // total size: 0x8
                unsigned long long ATE : 1;    // offset 0x0, size 0x4
                unsigned long long ATST : 3;   // offset 0x0, size 0x4
                unsigned long long AREF : 8;   // offset 0x0, size 0x4
                unsigned long long AFAIL : 2;  // offset 0x0, size 0x4
                unsigned long long DATE : 1;   // offset 0x0, size 0x4
                unsigned long long DATM : 1;   // offset 0x0, size 0x4
                unsigned long long ZTE : 1;    // offset 0x0, size 0x4
                unsigned long long ZTST : 2;   // offset 0x0, size 0x4
                unsigned long long pad19 : 45; // offset 0x0, size 0x4
            } test2;                           // offset 0x70, size 0x8
            signed long test2addr;             // offset 0x78, size 0x4
        } draw12;                              // offset 0x250, size 0x80
        struct /* @anon14 */ {
            // total size: 0x60
            struct /* @anon20 */ {
                // total size: 0x8
                unsigned long long ATE : 1;    // offset 0x0, size 0x4
                unsigned long long ATST : 3;   // offset 0x0, size 0x4
                unsigned long long AREF : 8;   // offset 0x0, size 0x4
                unsigned long long AFAIL : 2;  // offset 0x0, size 0x4
                unsigned long long DATE : 1;   // offset 0x0, size 0x4
                unsigned long long DATM : 1;   // offset 0x0, size 0x4
                unsigned long long ZTE : 1;    // offset 0x0, size 0x4
                unsigned long long ZTST : 2;   // offset 0x0, size 0x4
                unsigned long long pad19 : 45; // offset 0x0, size 0x4
            } testa;                           // offset 0x0, size 0x8
            signed long testaaddr;             // offset 0x8, size 0x4
            struct /* @anon30 */ {
                // total size: 0x8
                unsigned long long PRIM : 3;   // offset 0x0, size 0x4
                unsigned long long IIP : 1;    // offset 0x0, size 0x4
                unsigned long long TME : 1;    // offset 0x0, size 0x4
                unsigned long long FGE : 1;    // offset 0x0, size 0x4
                unsigned long long ABE : 1;    // offset 0x0, size 0x4
                unsigned long long AA1 : 1;    // offset 0x0, size 0x4
                unsigned long long FST : 1;    // offset 0x0, size 0x4
                unsigned long long CTXT : 1;   // offset 0x0, size 0x4
                unsigned long long FIX : 1;    // offset 0x0, size 0x4
                unsigned long long pad11 : 53; // offset 0x0, size 0x4
            } prim;                            // offset 0x10, size 0x8
            signed long primaddr;              // offset 0x18, size 0x4
            struct /* @anon7 */ {
                // total size: 0x8
                unsigned int R : 8; // offset 0x0, size 0x4
                unsigned int G : 8; // offset 0x0, size 0x4
                unsigned int B : 8; // offset 0x0, size 0x4
                unsigned int A : 8; // offset 0x0, size 0x4
                float Q;            // offset 0x4, size 0x4
            } rgbaq;                // offset 0x20, size 0x8
            signed long rgbaqaddr;  // offset 0x28, size 0x4
            struct /* @anon24 */ {
                // total size: 0x8
                unsigned long long X : 16; // offset 0x0, size 0x4
                unsigned long long Y : 16; // offset 0x0, size 0x4
                unsigned long long Z : 32; // offset 0x0, size 0x4
            } xyz2a;                       // offset 0x30, size 0x8
            signed long xyz2aaddr;         // offset 0x38, size 0x4
            struct /* @anon24 */ {
                // total size: 0x8
                unsigned long long X : 16; // offset 0x0, size 0x4
                unsigned long long Y : 16; // offset 0x0, size 0x4
                unsigned long long Z : 32; // offset 0x0, size 0x4
            } xyz2b;                       // offset 0x40, size 0x8
            signed long xyz2baddr;         // offset 0x48, size 0x4
            struct /* @anon20 */ {
                // total size: 0x8
                unsigned long long ATE : 1;    // offset 0x0, size 0x4
                unsigned long long ATST : 3;   // offset 0x0, size 0x4
                unsigned long long AREF : 8;   // offset 0x0, size 0x4
                unsigned long long AFAIL : 2;  // offset 0x0, size 0x4
                unsigned long long DATE : 1;   // offset 0x0, size 0x4
                unsigned long long DATM : 1;   // offset 0x0, size 0x4
                unsigned long long ZTE : 1;    // offset 0x0, size 0x4
                unsigned long long ZTST : 2;   // offset 0x0, size 0x4
                unsigned long long pad19 : 45; // offset 0x0, size 0x4
            } testb;                           // offset 0x50, size 0x8
            signed long testbaddr;             // offset 0x58, size 0x4
        } clear1;                              // offset 0x2D0, size 0x60
    } Db;                                      // offset 0x70, size 0x330
    unsigned int FrameClearColor;              // offset 0x3A0, size 0x4
    signed int D2dOffsetX;                     // offset 0x3A4, size 0x4
    signed int D2dOffsetY;                     // offset 0x3A8, size 0x4
    signed int ScreenOffsetX;                  // offset 0x3AC, size 0x4
    signed int ScreenOffsetY;                  // offset 0x3B0, size 0x4
    signed int ScreenDispX;                    // offset 0x3B4, size 0x4
    signed int ScreenDispY;                    // offset 0x3B8, size 0x4
    signed int ScreenAdjustX;                  // offset 0x3BC, size 0x4
    signed int ScreenAdjustY;                  // offset 0x3C0, size 0x4
    struct /* @anon18 */ {
        // total size: 0x90
        struct /* @anon23 */ {
            // total size: 0x4
            unsigned int DIR : 1;            // offset 0x0, size 0x4
            unsigned int p0 : 1;             // offset 0x0, size 0x4
            unsigned int MOD : 2;            // offset 0x0, size 0x4
            unsigned int ASP : 2;            // offset 0x0, size 0x4
            unsigned int TTE : 1;            // offset 0x0, size 0x4
            unsigned int TIE : 1;            // offset 0x0, size 0x4
            unsigned int STR : 1;            // offset 0x0, size 0x4
            unsigned int p1 : 7;             // offset 0x0, size 0x4
            unsigned int TAG : 16;           // offset 0x0, size 0x4
        } chcr;                              // offset 0x0, size 0x4
        unsigned int p0[3];                  // offset 0x4, size 0xC
        void *madr;                          // offset 0x10, size 0x4
        unsigned int p1[3];                  // offset 0x14, size 0xC
        unsigned int qwc;                    // offset 0x20, size 0x4
        unsigned int p2[3];                  // offset 0x24, size 0xC
        struct _sceDmaTag *tadr;             // offset 0x30, size 0x4
        unsigned int p3[3];                  // offset 0x34, size 0xC
        void *as0;                           // offset 0x40, size 0x4
        unsigned int p4[3];                  // offset 0x44, size 0xC
        void *as1;                           // offset 0x50, size 0x4
        unsigned int p5[3];                  // offset 0x54, size 0xC
        unsigned int p6[4];                  // offset 0x60, size 0x10
        unsigned int p7[4];                  // offset 0x70, size 0x10
        void *sadr;                          // offset 0x80, size 0x4
        unsigned int p8[3];                  // offset 0x84, size 0xC
    } *DmaChan[10];                          // offset 0x3C4, size 0x28
    signed int NowVu1Code;                   // offset 0x3EC, size 0x4
    signed int NowVu1Size;                   // offset 0x3F0, size 0x4
    signed int DrawDisable;                  // offset 0x3F4, size 0x4
    unsigned int system_memory_start;        // offset 0x3F8, size 0x4
    signed int system_memory_size;           // offset 0x3FC, size 0x4
    unsigned int SystemStatus;               // offset 0x400, size 0x4
    signed int SystemIndex;                  // offset 0x404, size 0x4
    unsigned int SystemTmpBuffStartAdrs;     // offset 0x408, size 0x4
    unsigned int SystemTmpBuffEndAdrs;       // offset 0x40C, size 0x4
    unsigned int SystemTmpBuffNow;           // offset 0x410, size 0x4
    unsigned int SystemTmpBuffHandle[2];     // offset 0x414, size 0x8
    unsigned long long RenderTESTStatus1;    // offset 0x420, size 0x4
    unsigned long long RenderTESTStatus2;    // offset 0x428, size 0x4
    unsigned long long RenderZBUFStatus1;    // offset 0x430, size 0x4
    unsigned long long RenderZBUFStatus2;    // offset 0x438, size 0x4
    unsigned long long RenderSCISSORStatus1; // offset 0x440, size 0x4
    signed int RenderSCISSORValue1[4];       // offset 0x448, size 0x10
    unsigned long long RenderSCISSORStatus2; // offset 0x458, size 0x4
    signed int RenderSCISSORValue2[4];       // offset 0x460, size 0x10
} FLPS2State;

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
    signed int size;           // offset 0x8, size 0x4
};

typedef struct {
    // total size: 0x2C
    unsigned char *memHead;        // offset 0x0, size 0x4
    int memSize;                   // offset 0x4, size 0x4
    unsigned int ownNumber;        // offset 0x8, size 0x4
    int ownUnit;                   // offset 0xC, size 0x4
    int remainder;                 // offset 0x10, size 0x4
    int remainderMin;              // offset 0x14, size 0x4
    struct _MEMMAN_CELL *cell_1st; // offset 0x18, size 0x4
    struct _MEMMAN_CELL *cell_fin; // offset 0x1C, size 0x4
    unsigned char *oriHead;        // offset 0x20, size 0x4
    int oriSize;                   // offset 0x24, size 0x4
    int debIndex;                  // offset 0x28, size 0x4
} _MEMMAN_OBJ;

typedef union {
    signed int cal; // offset 0x0, size 0x4
    struct {
        // total size: 0x4
        signed short low; // offset 0x0, size 0x2
        signed short pos; // offset 0x2, size 0x2
    } disp;               // offset 0x0, size 0x4
} XY;

typedef struct {
    // total size: 0x90
    signed char be_flag;         // offset 0x0, size 0x1
    signed char disp_flag;       // offset 0x1, size 0x1
    signed short fam_no;         // offset 0x2, size 0x2
    signed short r_no_0;         // offset 0x4, size 0x2
    signed short r_no_1;         // offset 0x6, size 0x2
    signed short r_no_2;         // offset 0x8, size 0x2
    signed short position_x;     // offset 0xA, size 0x2
    signed short position_y;     // offset 0xC, size 0x2
    signed int speed_x;          // offset 0x10, size 0x4
    signed int speed_y;          // offset 0x14, size 0x4
    XY xy[2];                    // offset 0x18, size 0x8
    XY wxy[2];                   // offset 0x20, size 0x8
    unsigned short *bg_address;  // offset 0x28, size 0x4
    unsigned short *suzi_adrs;   // offset 0x2C, size 0x4
    signed short old_pos_x;      // offset 0x30, size 0x2
    signed int zuubun;           // offset 0x34, size 0x4
    signed short no_suzi_line;   // offset 0x38, size 0x2
    unsigned short *start_suzi;  // offset 0x3C, size 0x4
    signed short u_line;         // offset 0x40, size 0x2
    signed short d_line;         // offset 0x42, size 0x2
    signed short bg_adrs_c_no;   // offset 0x44, size 0x2
    signed short suzi_c_no;      // offset 0x46, size 0x2
    signed short pos_x_work;     // offset 0x48, size 0x2
    signed short pos_y_work;     // offset 0x4A, size 0x2
    signed char rewrite_flag;    // offset 0x4C, size 0x1
    signed char suzi_base_flag;  // offset 0x4D, size 0x1
    XY hos_xy[2];                // offset 0x50, size 0x8
    XY chase_xy[2];              // offset 0x58, size 0x8
    signed short free;           // offset 0x60, size 0x2
    signed short frame_deff;     // offset 0x62, size 0x2
    signed short r_limit;        // offset 0x64, size 0x2
    signed short r_limit2;       // offset 0x66, size 0x2
    signed short l_limit;        // offset 0x68, size 0x2
    signed short l_limit2;       // offset 0x6A, size 0x2
    signed short y_limit;        // offset 0x6C, size 0x2
    signed short y_limit2;       // offset 0x6E, size 0x2
    unsigned short *suzi_adrs2;  // offset 0x70, size 0x4
    unsigned short *start_suzi2; // offset 0x74, size 0x4
    signed short suzi_c_no2;     // offset 0x78, size 0x2
    signed int max_x_limit;      // offset 0x7C, size 0x4
    signed short *deff_rl;       // offset 0x80, size 0x4
    signed short *deff_plus;     // offset 0x84, size 0x4
    signed short *deff_minus;    // offset 0x88, size 0x4
    signed short abs_x;          // offset 0x8C, size 0x2
    signed short abs_y;          // offset 0x8E, size 0x2
} BGW;

typedef struct {
    // total size: 0x428
    signed char bg_routine;     // offset 0x0, size 0x1
    signed char bg_r_1;         // offset 0x1, size 0x1
    signed char bg_r_2;         // offset 0x2, size 0x1
    signed char stage;          // offset 0x3, size 0x1
    signed char area;           // offset 0x4, size 0x1
    signed char compel_flag;    // offset 0x5, size 0x1
    signed int scroll_cg_adr;   // offset 0x8, size 0x4
    signed int ake_cg_adr;      // offset 0xC, size 0x4
    unsigned char scno;         // offset 0x10, size 0x1
    unsigned char scrno;        // offset 0x11, size 0x1
    signed short bg2_sp_x;      // offset 0x12, size 0x2
    signed short bg2_sp_y;      // offset 0x14, size 0x2
    signed short scr_stop;      // offset 0x16, size 0x2
    signed char frame_flag;     // offset 0x18, size 0x1
    signed char chase_flag;     // offset 0x19, size 0x1
    signed char old_chase_flag; // offset 0x1A, size 0x1
    signed char old_frame_flag; // offset 0x1B, size 0x1
    signed short pos_offset;    // offset 0x1C, size 0x2
    signed short quake_x_index; // offset 0x1E, size 0x2
    signed short quake_y_index; // offset 0x20, size 0x2
    signed short bg_f_x;        // offset 0x22, size 0x2
    signed short bg_f_y;        // offset 0x24, size 0x2
    signed short bg2_sp_x2;     // offset 0x26, size 0x2
    signed short bg2_sp_y2;     // offset 0x28, size 0x2
    signed short frame_deff;    // offset 0x2A, size 0x2
    signed short center_x;      // offset 0x2C, size 0x2
    signed short center_y;      // offset 0x2E, size 0x2
    signed short bg_index;      // offset 0x30, size 0x2
    signed char frame_vol;      // offset 0x32, size 0x1
    signed short max_x;         // offset 0x34, size 0x2
    unsigned char bg_opaque;    // offset 0x36, size 0x1
    BGW bgw[7];                 // offset 0x38, size 0x3F0
} BG;

typedef union {
    signed int sp; // offset 0x0, size 0x4
    struct /* @anon17 */ {
        // total size: 0x4
        signed short l; // offset 0x0, size 0x2
        signed short h; // offset 0x2, size 0x2
    } real;             // offset 0x0, size 0x4
} BG_MVXY_UNK;

typedef struct {
    // total size: 0x18
    BG_MVXY_UNK a[2];     // offset 0x0, size 0x8
    BG_MVXY_UNK d[2];     // offset 0x8, size 0x8
    signed short kop[2];  // offset 0x10, size 0x4
    unsigned short index; // offset 0x14, size 0x2
} BG_MVXY;

typedef struct {
    // total size: 0x18
    unsigned char *memoryblock;   // offset 0x0, size 0x4
    unsigned char *baseandcap[2]; // offset 0x4, size 0x8
    unsigned char *frame[2];      // offset 0xC, size 0x8
    int align;                    // offset 0x14, size 0x4
} FMS_FL;

typedef struct {
    // total size: 0x10
    unsigned char *ptr;   // offset 0x0, size 0x4
    unsigned int len;     // offset 0x4, size 0x4
    unsigned short align; // offset 0x8, size 0x2
    unsigned short id;    // offset 0xA, size 0x2
    unsigned short prev;  // offset 0xC, size 0x2
    unsigned short next;  // offset 0xE, size 0x2
} MEM_BLOCK;

typedef struct {
    // total size: 0x28
    signed int cnt;         // offset 0x0, size 0x4
    signed int memsize;     // offset 0x4, size 0x4
    MEM_BLOCK *block;       // offset 0x8, size 0x4
    signed int direction;   // offset 0xC, size 0x4
    unsigned char *memnow;  // offset 0x10, size 0x4
    unsigned char *memptr;  // offset 0x14, size 0x4
    signed int memalign;    // offset 0x18, size 0x4
    signed int used_size;   // offset 0x1C, size 0x4
    signed int tmemsize;    // offset 0x20, size 0x4
    unsigned int blocklist; // offset 0x24, size 0x4
} MEM_MGR;

typedef union /* @anon0 */ {
    unsigned int etc; // offset 0x0, size 0x4
    struct /* @anon1 */ {
        // total size: 0x4
        unsigned char vib;  // offset 0x0, size 0x1
        unsigned char etc0; // offset 0x1, size 0x1
        unsigned char etc1; // offset 0x2, size 0x1
        unsigned char etc2; // offset 0x3, size 0x1
    } gc;                   // offset 0x0, size 0x4
    struct /* @anon4 */ {
        // total size: 0x4
        unsigned char port; // offset 0x0, size 0x1
        unsigned char slot; // offset 0x1, size 0x1
        unsigned char vib;  // offset 0x2, size 0x1
        unsigned char etc;  // offset 0x3, size 0x1
    } ps;                   // offset 0x0, size 0x4
    struct /* @anon6 */ {
        // total size: 0x4
        unsigned char socket1; // offset 0x0, size 0x1
        unsigned char socket2; // offset 0x1, size 0x1
        unsigned short etc;    // offset 0x2, size 0x2
    } dc;                      // offset 0x0, size 0x4
    struct /* @anon8 */ {
        // total size: 0x4
        void *handle; // offset 0x0, size 0x4
    } xbox;           // offset 0x0, size 0x4
} PAD_CONN;

typedef struct {
    // total size: 0x10
    unsigned char pow[16]; // offset 0x0, size 0x10
} PAD_ANSHOT;

typedef struct {
    // total size: 0x88
    unsigned char state;    // offset 0x0, size 0x1
    unsigned char anstate;  // offset 0x1, size 0x1
    unsigned short kind;    // offset 0x2, size 0x2
    PAD_CONN conn;          // offset 0x4, size 0x4
    unsigned int sw;        // offset 0x8, size 0x4
    unsigned int sw_old;    // offset 0xC, size 0x4
    unsigned int sw_new;    // offset 0x10, size 0x4
    unsigned int sw_off;    // offset 0x14, size 0x4
    unsigned int sw_chg;    // offset 0x18, size 0x4
    PAD_ANSHOT anshot;      // offset 0x1C, size 0x10
    PAD_STICK stick[2];     // offset 0x2C, size 0x18
    unsigned int sw_repeat; // offset 0x44, size 0x4
    union /* @anon9 */ {
        unsigned short work; // offset 0x0, size 0x2
        struct /* @anon10 */ {
            // total size: 0x2
            unsigned char press; // offset 0x0, size 0x1
            unsigned char sw_up; // offset 0x1, size 0x1
        } ctr;                   // offset 0x0, size 0x2
    } rpsw[32];                  // offset 0x48, size 0x40
} FLPAD;

typedef struct {
    // total size: 0x34
    unsigned char state;   // offset 0x0, size 0x1
    unsigned char anstate; // offset 0x1, size 0x1
    unsigned short kind;   // offset 0x2, size 0x2
    PAD_CONN conn;         // offset 0x4, size 0x4
    unsigned int sw;       // offset 0x8, size 0x4
    PAD_ANSHOT anshot;     // offset 0xC, size 0x10
    PAD_STICK stick[2];    // offset 0x1C, size 0x18
} TARPAD;

typedef struct {
    // total size: 0x2C
    unsigned char conf_sw[32]; // offset 0x0, size 0x20
    unsigned char flip_lever;  // offset 0x20, size 0x1
    unsigned char flip_ast1;   // offset 0x21, size 0x1
    unsigned char flip_ast2;   // offset 0x22, size 0x1
    unsigned char free;        // offset 0x23, size 0x1
    short abut_on;             // offset 0x24, size 0x2
    short ast1_on;             // offset 0x26, size 0x2
    short ast2_on;             // offset 0x28, size 0x2
    unsigned short free2;      // offset 0x2A, size 0x2
} FLPAD_CONFIG;

// MARK: - Variables

// .rodata

extern const unsigned char fllever_flip_data[4][16];      // size: 0x40, address: 0x4D9820
extern const unsigned char fllever_depth_flip_data[4][4]; // size: 0x10, address: 0x4D9860
extern const FLPAD_CONFIG fltpad_config_basic;            // size: 0x2C, address: 0x55F530
extern const unsigned int flpad_io_map[25];               // size: 0x64, address: 0x55F560

// .sbss

extern unsigned char NumOfValidPads;         // size: 0x1, address: 0x5789A8
extern FLPAD_CONFIG flpad_config[2];         // size: 0x58, address: 0x5789B0
extern FLPAD *flpad_adr[2];                  // size: 0x8, address: 0x578A08
extern BG_MVXY bg_mvxy;                      // size: 0x18, address: 0x578C80
extern IO io_w;                              // size: 0x6C, address: 0x579230
extern TPU *tpu_free;                        // size: 0x4, address: 0x579A8C
extern unsigned char *texcash_melt_buffer;   // size: 0x4, address: 0x579A90
extern signed int Zoom_Base_Position_Z;      // size: 0x4, address: 0x579AC4
extern signed int Zoom_Base_Position_Y;      // size: 0x4, address: 0x579AC8
extern signed int Zoom_Base_Position_X;      // size: 0x4, address: 0x579ACC
extern float Frame_Zoom_Y;                   // size: 0x4, address: 0x579AD0
extern float Frame_Zoom_X;                   // size: 0x4, address: 0x579AD4
extern float SA_Zoom_Y;                      // size: 0x4, address: 0x579AD8
extern float SA_Zoom_X;                      // size: 0x4, address: 0x579ADC
extern float Screen_Zoom_Y;                  // size: 0x4, address: 0x579AE0
extern float Screen_Zoom_X;                  // size: 0x4, address: 0x579AE4
extern unsigned char Screen_PAL;             // size: 0x1, address: 0x579C20
extern unsigned short PLsw[2][2];            // size: 0x8, address: 0x579C28
extern unsigned int Interrupt_Timer;         // size: 0x4, address: 0x579C34
extern unsigned short p4sw_buff;             // size: 0x2, address: 0x579C38
extern unsigned short p3sw_buff;             // size: 0x2, address: 0x579C3C
extern unsigned short p2sw_buff;             // size: 0x2, address: 0x579C40
extern unsigned short p1sw_buff;             // size: 0x2, address: 0x579C44
extern unsigned char Interrupt_Flag;         // size: 0x1, address: 0x579C48
extern short Correct_Y[4];                   // size: 0x8, address: 0x579C50
extern short Correct_X[4];                   // size: 0x8, address: 0x579C58
extern unsigned char Turbo_Timer;            // size: 0x1, address: 0x579C60
extern unsigned char Turbo;                  // size: 0x1, address: 0x579C64
extern unsigned char Disp_Size_V;            // size: 0x1, address: 0x579C6C
extern unsigned char Disp_Size_H;            // size: 0x1, address: 0x579C70
extern int Y_Adjust;                         // size: 0x4, address: 0x579C94
extern int X_Adjust;                         // size: 0x4, address: 0x579C98
extern unsigned char Process_Counter;        // size: 0x1, address: 0x579CA4
extern unsigned short p4sw_1;                // size: 0x2, address: 0x579CA8
extern unsigned short p4sw_0;                // size: 0x2, address: 0x579CAC
extern unsigned short p3sw_1;                // size: 0x2, address: 0x579CB0
extern unsigned short p3sw_0;                // size: 0x2, address: 0x579CB4
extern unsigned short p2sw_1;                // size: 0x2, address: 0x579CB8
extern unsigned short p2sw_0;                // size: 0x2, address: 0x579CBC
extern unsigned short p1sw_1;                // size: 0x2, address: 0x579CC0
extern unsigned short p1sw_0;                // size: 0x2, address: 0x579CC4
extern struct _SYSTEM_W sys_w;               // size: 0x1C, address: 0x579D90
extern unsigned int current_task_num;        // size: 0x4, address: 0x579DAC
extern signed short Cont_Timer;              // size: 0x2, address: 0x579E18
extern short Offset_BG_X[6];                 // size: 0xC, address: 0x579E38
extern short Target_BG_X[6];                 // size: 0xC, address: 0x579E48
extern unsigned char CPU_Rec[2];             // size: 0x2, address: 0x57A04C
extern unsigned char CPU_Time_Lag[2];        // size: 0x2, address: 0x57A054
extern unsigned char Play_Mode;              // size: 0x1, address: 0x57A0AC
extern unsigned char Mode_Type;              // size: 0x1, address: 0x57A0C4
extern unsigned char Replay_Status[2];       // size: 0x2, address: 0x57A0E8
extern unsigned char Cont_No[4];             // size: 0x4, address: 0x57A1F8
extern unsigned char test_flag;              // size: 0x1, address: 0x57A200
extern unsigned char Game_pause;             // size: 0x1, address: 0x57A260
extern unsigned char E_Number[2][4];         // size: 0x8, address: 0x57A2B8
extern char Suicide[8];                      // size: 0x8, address: 0x57A2F8
extern unsigned char Continue_Count_Down[2]; // size: 0x2, address: 0x57A33C
extern unsigned char Scene_Cut;              // size: 0x1, address: 0x57A348
extern unsigned char Usage;                  // size: 0x1, address: 0x57A55C
extern unsigned char Country;                // size: 0x1, address: 0x57A5E4
extern char Next_Step;                       // size: 0x1, address: 0x57A680
extern char LOSER;                           // size: 0x1, address: 0x57A698
extern char Continue_Count[2];               // size: 0x2, address: 0x57A6B4
extern unsigned int Record_Timer;            // size: 0x4, address: 0x57A810
extern char Slow_Timer;                      // size: 0x1, address: 0x57A830
extern unsigned char sysSLOW;                // size: 0x1, address: 0x57A834
extern unsigned char sysFF;                  // size: 0x1, address: 0x57A838
extern char Debug_w[72];                     // size: 0x48, address: 0x57A860
extern short *dctex_linear;                  // size: 0x4, address: 0x57A950
extern MPP mpp_w;                            // size: 0x4C, address: 0x57A9F0
extern int system_init_level;                // size: 0x4, address: 0x57AA3C
extern TARPAD tarpad_root[2];                // size: 0x68, address: 0x57B040

// .bss

extern MEM_BLOCK sysmemblock[4096];    // size: 0x10000, address: 0x584C80
extern FLPAD flpad_conf[2];            // size: 0x110, address: 0x594C80
extern FLPAD flpad_root[2];            // size: 0x110, address: 0x594D90
extern BG bg_w;                        // size: 0x428, address: 0x595830
extern float PrioBase[128];            // size: 0x200, address: 0x5E3F50
extern PLW plw[2];                     // size: 0x8D8, address: 0x5E4D20
extern struct _TASK task[11];          // size: 0xDC, address: 0x6BD2D0
extern unsigned char Order_Timer[148]; // size: 0x94, address: 0x6BD690
extern unsigned char Order[148];       // size: 0x94, address: 0x6BD730
extern FLPS2State flPs2State;          // size: 0x470, address: 0x6E2750

// MARK: - Functions

void plmemInit(MEM_MGR *memmgr, MEM_BLOCK *block, int count, void *mem_ptr, int memsize, int memalign,
               int direction);                             // Range: 0x116180 -> 0x11629C
unsigned int plmemRegister(MEM_MGR *memmgr, int len);      // Range: 0x1162A0 -> 0x1162D8
unsigned int plmemRegisterS(MEM_MGR *memmgr, int len);     // Range: 0x1164C0 -> 0x116980
void *plmemTemporaryUse(MEM_MGR *memmgr, int len);         // Range: 0x116980 -> 0x116AAC
void *plmemRetrieve(MEM_MGR *memmgr, unsigned int handle); // Range: 0x116AB0 -> 0x116B20
int plmemRelease(MEM_MGR *memmgr, unsigned int handle);    // Range: 0x116B20 -> 0x116BFC
void *plmemCompact(MEM_MGR *memmgr);                       // Range: 0x116C00 -> 0x116E9C
unsigned int plmemGetSpace(MEM_MGR *memmgr);               // Range: 0x116EA0 -> 0x116EC8
unsigned int plmemGetFreeSpace(MEM_MGR *memmgr);           // Range: 0x116ED0 -> 0x116F5C

void flpad_ram_clear(unsigned int *adrs_int, int xx);                                 // Range: 0x117300 -> 0x1173C8
int flPADInitialize();                                                                // Range: 0x1173D0 -> 0x117458
void flPADWorkClear();                                                                // Range: 0x117480 -> 0x1174C0
void flPADConfigSet(const FLPAD_CONFIG *adrs, int padnum);                            // Range: 0x1174C0 -> 0x1175A4
void flPADGetALL();                                                                   // Range: 0x1175B0 -> 0x117988
void flPADACRConf();                                                                  // Range: 0x117990 -> 0x11880C
void padconf_setup_depth(unsigned char *deps, unsigned char num, unsigned int iodat); // Range: 0x118810 -> 0x1188D8
void flupdate_pad_stick_dir(PAD_STICK *st);                                           // Range: 0x1188E0 -> 0x1189D8
void flupdate_pad_button_data(FLPAD *pad, unsigned int data);                         // Range: 0x1189E0 -> 0x118A80
void flupdate_pad_on_cnt(FLPAD *pad);                                                 // Range: 0x118A80 -> 0x118B64
void flPADSetRepeatSw(FLPAD *pad, unsigned int IOdata, unsigned char ctr,
                      unsigned char times); // Range: 0x118B70 -> 0x118CF0

void plMemset(void *dst, unsigned int pat, int size); // Range: 0x11B3B0 -> 0x11B41C

void appViewSetItems(VPRM *prm);                                                    // Range: 0x11C0D0 -> 0x11C118
void appViewGetItems(VPRM *prm);                                                    // Range: 0x11C120 -> 0x11C168
void appViewMatrix();                                                               // Range: 0x11C170 -> 0x11C1CC
void render_start();                                                                // Range: 0x11C1D0 -> 0x11C1F0
void render_end();                                                                  // Range: 0x11C1F0 -> 0x11C210
void initRenderState(int flag);                                                     // Range: 0x11C210 -> 0x11C328
void setBackGroundColor(unsigned int color);                                        // Range: 0x11C4D0 -> 0x11C4FC
void Setup_Disp_Size();                                                             // Range: 0x11BFF0 -> 0x11C0B4
void Scrn_Renew();                                                                  // Range: 0x170BE0 -> 0x170BF0
void Irl_Family();                                                                  // Range: 0x170BF0 -> 0x170CD0
void Irl_Scrn();                                                                    // Range: 0x170CD0 -> 0x170E9C
void palCreateGhost();                                                              // Range: 0x19F8D0 -> 0x19FB50
void njdp2d_init();                                                                 // Range: 0x1C0330 -> 0x1C034C
void njdp2d_draw();                                                                 // Range: 0x1C0350 -> 0x1C0568
void njdp2d_sort(float *pos, float pri, unsigned int col, int flag);                // Range: 0x1C0570 -> 0x1C0A0C
int effect_49_init(short vital_new);                                                // Range: 0x1E52B0 -> 0x1E54D8
int effect_58_init(short id, short time0, short option);                            // Range: 0x1E97D0 -> 0x1E98A0
int effect_76_init(short dir_old);                                                  // Range: 0x1F2670 -> 0x1F27A0
int effect_95_init(short vital_new);                                                // Range: 0x1FCFD0 -> 0x1FD218
int effect_A9_init(short Char_Index, short Option, short Pos_Index, short Option2); // Range: 0x201A80 -> 0x201C78
void disp_effect_work();                                                            // Range: 0x21AD30 -> 0x21AED8
int Setup_Directory_Record_Data();                                                  // Range: 0x254330 -> 0x2543CC
void Init_Task(struct _TASK *task_ptr);                                             // Range: 0x266080 -> 0x2660D4
void keyConvert();                                                                  // Range: 0x266A90 -> 0x267118
void appSetupBasePriority();                                                        // Range: 0x286180 -> 0x2861F4
void appSetupTempPriority();                                                        // Range: 0x286200 -> 0x286264
void seqsInitialize(void *adrs);                                                    // Range: 0x286300 -> 0x286350
void seqsBeforeProcess();                                                           // Range: 0x286370 -> 0x2863B4
void seqsAfterProcess();                                                            // Range: 0x2863C0 -> 0x2865E4
void disp_ramcnt_free_area();                                                       // Range: 0x37BB90 -> 0x37BC58
void Init_ram_control_work(unsigned char *adrs, int size);                          // Range: 0x37BC60 -> 0x37BDF8
void BGM_Request(short Code);                                                       // Range: 0x3891A0 -> 0x3891CC
void Init_sound_system();                                                           // Range: 0x3963A0 -> 0x396438
void sndInitialLoad();                                                              // Range: 0x3964D0 -> 0x396524
void Init_bgm_work();                                                               // Range: 0x3966E0 -> 0x396718
void BGM_Server();                                                                  // Range: 0x396B30 -> 0x3977D8
void Check_Replay_Status(short PL_id, unsigned char Status);                        // Range: 0x3A58D0 -> 0x3A5A30
void zlib_Initialize(void *tempAdrs, int tempSize);                                 // Range: 0x3B76E0 -> 0x3B776C
int Check_Exit_Check();                                                             // Range: 0x3BF690 -> 0x3BF6E0
void mmSystemInitialize();                                                          // Range: 0x3C0080 -> 0x3C008C
void mmHeapInitialize(_MEMMAN_OBJ *mmobj, unsigned char *adrs, int size, int unit,
                      char *format);                            // Range: 0x3C0090 -> 0x3C020C
unsigned char *mmAlloc(_MEMMAN_OBJ *mmobj, int size, int flag); // Range: 0x3C02D0 -> 0x3C037C
void mmFree(_MEMMAN_OBJ *mmobj, unsigned char *adrs);           // Range: 0x3C0560 -> 0x3C05D8
void ppg_Initialize(void *lcmAdrs, int lcmSize);                // Range: 0x3C05E0 -> 0x3C0650
void ppgMakeConvTableTexDC();                                   // Range: 0x3C3620 -> 0x3C3768
void CP3toPS2Draw();                                            // Range: 0x3C64D0 -> 0x3C6D8C
void njUserInit();                                              // Range: 0x3E5BA0 -> 0x3E5E64
void cpInitTask();                                              // Range: 0x3E61C0 -> 0x3E61F0
void cpReadyTask(unsigned short num, void *func_adrs);          // Range: 0x3E61F0 -> 0x3E625C

int flSetRenderState(enum _FLSETRENDERSTATE func, unsigned int value); // Range: 0x3EEC50 -> 0x3EFDD8
void flAdjustScreen(int x, int y);                                     // Range: 0x3F2230 -> 0x3F2268
int flSetDebugMode(unsigned int flag);                                 // Range: 0x3F2280 -> 0x3F22A0
int flPrintL(int posi_x, int posi_y, char *format);                    // Range: 0x3F2B40 -> 0x3F2D08
int flPrintColor(unsigned int col);                                    // Range: 0x3F2D10 -> 0x3F2E04
void *flAllocMemory(int size);                                         // Range: 0x3F5F30 -> 0x3F5F60
int flGetFrame(FMS_FRAME *frame);                                      // Range: 0x3F5F60 -> 0x3F5F90
int flGetSpace();                                                      // Range: 0x3F5F90 -> 0x3F5FB4
int flInitialize();                                                    // Range: 0x3FE0B0 -> 0x3FE1A8
int flFlip(unsigned int flag);                                         // Range: 0x3FE580 -> 0x3FE648

int tarPADInit();                                                  // Range: 0x400120 -> 0x40041C
void tarPADDestroy();                                              // Range: 0x400420 -> 0x400448
void flPADConfigSetACRtoXX(int padnum, short a, short b, short c); // Range: 0x400450 -> 0x4004B8
void tarPADRead();                                                 // Range: 0x4004C0 -> 0x400624

void MemcardInit();                  // Range: 0x403EC0 -> 0x403F38
void KnjFlush();                     // Range: 0x407E90 -> 0x407FE8
void ppgWorkInitializeApprication(); // Range: 0x413920 -> 0x413A54

#endif
