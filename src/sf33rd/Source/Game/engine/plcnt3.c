/**
 * @file plcnt3.c
 * Player Controller for the "Crush the Car!" Bonus Stage
 */

#include "sf33rd/Source/Game/engine/plcnt3.h"
#include "common.h"
#include "sf33rd/Source/Game/engine/hitcheck.h"
#include "sf33rd/Source/Game/engine/manage.h"
#include "sf33rd/Source/Game/engine/plcnt.h"
#include "sf33rd/Source/Game/engine/plcnt2.h"
#include "sf33rd/Source/Game/engine/pls02.h"
#include "sf33rd/Source/Game/engine/slowf.h"
#include "sf33rd/Source/Game/engine/workuser.h"
#include "sf33rd/Source/Game/stage/bg_sub.h"

void plcnt_b2_move();
void plcnt_b2_die();

void (*const player_bonus2_process[3])() = { plcnt_b_init, plcnt_b2_move, plcnt_b2_die };

s32 Player_control_bonus2() {
    if (((gs.pcon_rno[0] + gs.pcon_rno[1]) == 0) || (!Game_pause && !EXE_flag)) {
        players_timer++;
        players_timer &= 0x7FFF;
        player_bonus2_process[gs.pcon_rno[0]]();

        if (check_be_car_object()) {
            check_body_touch2();
            check_damage_hosei_bonus();
        }

        set_quake(&gs.plw[0]);
        set_quake(&gs.plw[1]);

        if (!gs.plw[0].zuru_flag && !gs.plw[0].zettai_muteki_flag) {
            hit_push_request(&gs.plw[0].wu);
        }

        if (!gs.plw[1].zuru_flag && !gs.plw[1].zettai_muteki_flag) {
            hit_push_request(&gs.plw[1].wu);
        }

        add_next_position(gs.plw);
        add_next_position(&gs.plw[1]);
        check_cg_zoom();
    }

    if (Game_pause != 0x81) {
        store_player_after_image_data();
    }

    if (gs.pcon_rno[0] == 2 && gs.pcon_rno[1] == 0 && gs.pcon_rno[2] == 2) {
        return 1;
    }

    return 0;
}

void plcnt_b2_move() {
    if (No_Death) {
        gs.plw[0].wu.dm_vital = gs.plw[1].wu.dm_vital = 0;
    }

    if (Break_Into) {
        gs.plw[0].wu.dm_vital = gs.plw[1].wu.dm_vital = 0;
    }

    move_player_work_bonus();

    if (Bonus_Stage_RNO[0] == 2) {
        Time_Stop = 1;
        gs.pcon_rno[0] = 2;
        gs.pcon_rno[1] = 0;
        gs.pcon_rno[2] = 0;
    }

    if (Time_Over) {
        gs.pcon_rno[0] = 2;
        gs.pcon_rno[1] = 0;
        gs.pcon_rno[2] = 0;
    }
}

void plcnt_b2_die() {
    gs.plw[0].wu.dm_vital = gs.plw[1].wu.dm_vital = 0;

    switch (gs.pcon_rno[2]) {
    case 0:
        gs.plw[0].wkey_flag = gs.plw[1].wkey_flag = 1;
        gs.plw[0].image_setup_flag = gs.plw[1].image_setup_flag = 0;
        gs.pcon_rno[2]++;
        /* fallthrough */

    case 1:
        if (footwork_check_bns(0) && footwork_check_bns(1)) {
            gs.pcon_rno[2]++;
        }

        break;

    case 2:
        complete_victory_pause();

        if (gs.plw[0].wu.operator) {
            gs.plw[0].wu.routine_no[1] = 0;
            gs.plw[0].wu.routine_no[2] = 40;
            gs.plw[0].wu.routine_no[3] = 0;
        } else {
            gs.plw[0].wu.routine_no[3] = 9;
        }

        if (gs.plw[1].wu.operator) {
            gs.plw[1].wu.routine_no[1] = 0;
            gs.plw[1].wu.routine_no[2] = 40;
            gs.plw[1].wu.routine_no[3] = 0;
        } else {
            gs.plw[1].wu.routine_no[3] = 9;
        }

        gs.plw[0].wu.cg_type = gs.plw[1].wu.cg_type = 0;
        gs.pcon_rno[2]++;
        break;

    case 3:
        if ((gs.plw[0].wu.routine_no[3] == 9) && (gs.plw[1].wu.routine_no[3] == 9)) {
            gs.pcon_rno[2]++;
        }

        break;
    }

    move_player_work_bonus();
}
