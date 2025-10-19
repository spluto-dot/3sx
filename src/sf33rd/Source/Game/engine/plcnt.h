#ifndef PLCNT_H
#define PLCNT_H

#include "structs.h"
#include "types.h"

typedef struct {
    u8 nmsa_g_ix;
    u8 exsa_g_ix;
    u8 exs2_g_ix;
    u8 nmsa_a_ix;
    u8 exsa_a_ix;
    u8 exs2_a_ix;
    u8 ex4th_full;
    s8 gauge_type;
    s16 gauge_len;
    s16 store_max;
    s32 dtm;
} SA_DATA;

extern const s8 plid_data[20];

extern UNK_1 rambod[2];
extern UNK_2 ramhan[2];
extern u32 omop_spmv_ng_table[2];
extern u32 omop_spmv_ng_table2[2];
extern u16 vital_inc_timer;
extern u16 vital_dec_timer;
extern char cmd_sel[2];
extern s8 vib_sel[2];
extern s16 sag_inc_timer[2];
extern char no_sa[2];

extern const s16** kizetsu_timer_table[];

void Player_control();
void reqPlayerDraw();
void erase_extra_plef_work();
void set_base_data_metamorphose(PLW* wk, s16 dmid);
void set_player_shadow(PLW* wk);
void clear_chainex_check(s16 ix);
void set_kizetsu_status(s16 ix);
void clear_kizetsu_point(PLW* wk);
void set_super_arts_status(s16 ix);
void clear_super_arts_point(PLW* wk);
s16 check_combo_end(s16 ix);
void set_quake(PLW* wk);
void add_next_position(PLW* wk);
void store_player_after_image_data();
void setup_base_and_other_data();
s32 check_sa_type_rebirth(PLW* wk);
void pli_0002();
void set_super_arts_status_dc(s16 ix);

#endif
