/**
 * @file lose_pl.c
 * Losing Character Animations
 */

#include "sf33rd/Source/Game/animation/lose_pl.h"
#include "common.h"
#include "sf33rd/Source/Game/effect/effc1.h"
#include "sf33rd/Source/Game/engine/charset.h"
#include "sf33rd/Source/Game/engine/plcnt.h"
#include "sf33rd/Source/Game/engine/pls02.h"
#include "sf33rd/Source/Game/engine/workuser.h"
#include "sf33rd/Source/Game/stage/bg_data.h"
#include "sf33rd/Source/Game/system/work_sys.h"

s16 lose_rno[3];
s16 lose_free[2];

const s16 loser_type_tbl[20] = { 0, 0, 0, 0, 0, 2, 0, 0, 1, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0 };

const s16 meta_lose_tbl[20] = { 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 28, 24, 24, 24, 24, 24, 24 };

void lose_player(PLW* wk) {
    void (*lose_jp_tbl[4])(PLW*) = { Lose_00000, Lose_10000, Lose_20000, Lose_30000 };

    if (My_char[wk->wu.id] != wk->player_number) {
        meta_lose_pause(wk);
        return;
    }

    lose_jp_tbl[loser_type_tbl[wk->player_number]](wk);
}

void Lose_00000(PLW* wk) {
    if ((gs.pcon_rno[0] == 2) && (gs.pcon_rno[1] == 3)) {
        Judge_normal_loser(wk);
        return;
    }

    Normal_normal_Loser(wk);
}

void Lose_10000(PLW* wk) {
    if ((gs.pcon_rno[0] == 2) && (gs.pcon_rno[1] == 3)) {
        switch (wk->wu.routine_no[3]) {
        case 0:
            wk->wu.routine_no[3]++;
            lose_rno[0] = lose_rno[1] = lose_rno[2] = 0;
            wk->wu.char_index = random_16();
            wk->wu.char_index &= 3;
            set_char_move_init(&wk->wu, 9, wk->wu.char_index + 0x38);
            break;

        default:
        case 1:
        case 9:
            char_move(&wk->wu);
            break;
        }
    } else if ((gs.pcon_rno[1] == 0) || (gs.pcon_rno[1] == 4)) {
        return;
    } else {
        switch (wk->wu.routine_no[3]) {
        case 0:
            wk->wu.routine_no[3]++;
            lose_rno[0] = lose_rno[1] = lose_rno[2] = 0;
            wk->wu.char_index = random_16();
            wk->wu.char_index &= 7;
            set_char_move_init(&wk->wu, 9, wk->wu.char_index + 0x18);
            break;

        case 1:
        case 9:
            char_move(&wk->wu);
            break;
        }
    }

    if (set_field_hosei_flag(&gs.plw[wk->wu.id], scrr, 1) != 0) {
        set_field_hosei_flag(&gs.plw[wk->wu.id], scrl, 0);
    }
}

void Lose_20000(PLW* wk) {
    s16 work;

    if ((gs.pcon_rno[0] == 2) && (gs.pcon_rno[1] == 3)) {
        Judge_normal_loser(wk);
        return;
    }

    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;

        if (!Extra_Break && ((Round_num >= (save_w[Present_Mode].Battle_Number[Play_Type]) * 2) ||
                             (PL_Wins[Winner_id] >= (save_w[Present_Mode].Battle_Number[Play_Type]) + 1))) {
            effect_C1_init(&wk->wu);
        }

        if ((gs.pcon_rno[1] != 0) && (gs.pcon_rno[1] != 4)) {
            lose_rno[0] = lose_rno[1] = lose_rno[2] = 0;
            work = random_16();
            work &= 7;
            set_char_move_init(&wk->wu, 9, work + 0x18);
            break;
        }

        break;

    default:
        Normal_normal_Loser(wk);
        break;
    }

    if (set_field_hosei_flag(&gs.plw[wk->wu.id], scrr, 1) != 0) {
        set_field_hosei_flag(&gs.plw[wk->wu.id], scrl, 0);
    }
}

void Lose_30000(PLW* wk) {
    if ((gs.pcon_rno[0] == 2) && (gs.pcon_rno[1] == 3)) {
        switch (wk->wu.routine_no[3]) {
        case 0:
            wk->wu.routine_no[3]++;
            lose_rno[0] = lose_rno[1] = lose_rno[2] = 0;
            if (Country != 1) {
                set_char_move_init(&wk->wu, 9, 0x3A);
            } else {
                set_char_move_init(&wk->wu, 9, 0x38);
            }
            break;

        default:
        case 1:
        case 9:
            char_move(&wk->wu);
            break;
        }

    } else if ((gs.pcon_rno[1] == 0) || (gs.pcon_rno[1] == 4)) {
        return;
    } else {
        switch (wk->wu.routine_no[3]) {
        case 0:
            wk->wu.routine_no[3]++;
            lose_rno[0] = lose_rno[1] = lose_rno[2] = 0;
            if (Country != 1) {
                set_char_move_init(&wk->wu, 9, 0x1C);
            } else {
                set_char_move_init(&wk->wu, 9, 0x18);
            }
            break;

        case 1:
        case 9:
            char_move(&wk->wu);
            break;
        }
    }

    if (set_field_hosei_flag(&gs.plw[wk->wu.id], scrr, 1) != 0) {
        set_field_hosei_flag(&gs.plw[wk->wu.id], scrl, 0);
    }
}

void Normal_normal_Loser(PLW* wk) {
    s16 work;

    if ((gs.pcon_rno[1] == 0) || (gs.pcon_rno[1] == 4)) {
        return;
    }

    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        lose_rno[0] = lose_rno[1] = lose_rno[2] = 0;
        work = random_16();
        work &= 7;
        set_char_move_init(&wk->wu, 9, work + 0x18);
        break;

    case 1:
    case 9:
        char_move(&wk->wu);
        break;
    }

    if (set_field_hosei_flag(&gs.plw[wk->wu.id], scrr, 1) != 0) {
        set_field_hosei_flag(&gs.plw[wk->wu.id], scrl, 0);
    }
}

void Judge_normal_loser(PLW* wk) {
    s16 work;

    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3] += 1;
        work = random_16();
        work &= 3;
        set_char_move_init(&wk->wu, 9, work + 0x38);
        break;

    case 1:
    case 9:
    default:
        char_move(&wk->wu);
        break;
    }

    if (set_field_hosei_flag(&gs.plw[wk->wu.id], scrr, 1) != 0) {
        set_field_hosei_flag(&gs.plw[wk->wu.id], scrl, 0);
    }
}

void meta_lose_pause(PLW* wk) {
    bg_app_stop = 1;

    if ((gs.pcon_rno[1] == 0) || (gs.pcon_rno[1] == 4)) {
        return;
    }

    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3] += 1;
        set_char_move_init(&wk->wu, 9, meta_lose_tbl[wk->player_number]);
        break;

    case 1:
    case 9:
        char_move(&wk->wu);
        break;
    }

    if (set_field_hosei_flag(&gs.plw[wk->wu.id], scrr, 1) != 0) {
        set_field_hosei_flag(&gs.plw[wk->wu.id], scrl, 0);
    }
}
