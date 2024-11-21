#include "sf33rd/Source/Game/menu.h"
#include "common.h"
#include "sf33rd/Source/Game/main.h"
#include "unknown.h"

void After_Title(struct _TASK *task_ptr);
void In_Game(struct _TASK *task_ptr);
void Wait_Load_Save(struct _TASK *task_ptr);
void Wait_Replay_Check(struct _TASK *task_ptr);
void Disp_Auto_Save(struct _TASK *task_ptr);
void Suspend_Menu();
void Wait_Replay_Load();
void Training_Menu(struct _TASK *task_ptr);
void After_Replay(struct _TASK *task_ptr);
void Disp_Auto_Save2(struct _TASK *task_ptr);
void Wait_Pause_in_Tr(struct _TASK *task_ptr);
void Reset_Training(struct _TASK *task_ptr);
void Reset_Replay(struct _TASK *task_ptr);
void End_Replay_Menu(struct _TASK *task_ptr);
void Mode_Select(struct _TASK *task_ptr);
void Option_Select(struct _TASK *task_ptr);
void Training_Mode(struct _TASK *task_ptr);
void System_Direction(struct _TASK *task_ptr);
void Load_Replay(struct _TASK *task_ptr);
void toSelectGame(struct _TASK *task_ptr);
void Game_Option(struct _TASK *task_ptr);
void Button_Config(struct _TASK *task_ptr);
void Screen_Adjust(struct _TASK *task_ptr);
void Sound_Test(struct _TASK *task_ptr);
void Memory_Card(struct _TASK *task_ptr);
void Extra_Option(struct _TASK *task_ptr);
void VS_Result(struct _TASK *task_ptr);
void Save_Replay(struct _TASK *task_ptr);
void Direction_Menu(struct _TASK *task_ptr);
void Save_Direction(struct _TASK *task_ptr);
void Load_Direction(struct _TASK *task_ptr);
void Setup_VS_Mode(struct _TASK *task_ptr);
void Setup_Next_Page(struct _TASK *task_ptr, s32 /* unused */);

void bg_etc_write_ex(s16 type);
void Decide_PL(s16 PL_id);
void imgSelectGameButton();
void jmpRebootProgram();

void Menu_in_Sub(struct _TASK *task_ptr);
s32 Exit_Sub(struct _TASK *task_ptr, s16 cursor_ix, s16 next_routine);
u16 MC_Move_Sub(u16 sw, s16 cursor_id, s16 menu_max, s16 cansel_menu);
s32 Menu_Sub_case1(struct _TASK *task_ptr);
void System_Dir_Move_Sub(s16 PL_id);
void System_Dir_Move_Sub_LR(u16 sw, s16 cursor_id);
void Dir_Move_Sub(struct _TASK *task_ptr, s16 PL_id);
u16 Dir_Move_Sub2(u16 sw);
void Dir_Move_Sub_LR(u16 sw, s16 /* unused */);
void Ex_Move_Sub_LR(u16 sw, s16 PL_id);

typedef void (*MenuFunc)(struct _TASK *);

const MenuFunc Menu_Jmp_Tbl[16] = {
    After_Title,   In_Game,      Wait_Load_Save,  Wait_Replay_Check, Disp_Auto_Save, Suspend_Menu, Wait_Replay_Load,
    Training_Menu, After_Replay, Disp_Auto_Save2, Wait_Pause_in_Tr,  Reset_Training, Reset_Replay, End_Replay_Menu,
};

void Menu_Task(struct _TASK *task_ptr) {
    if (nowSoftReset()) {
        return;
    }

    if (Interface_Type[0] == 0 || Interface_Type[1] == 0) {
        Connect_Status = 0;
    } else {
        Connect_Status = 1;
    }

    Setup_Pad_or_Stick();
    IO_Result = 0;
    Menu_Jmp_Tbl[task_ptr->r_no[0]](task_ptr);
}

void Setup_Pad_or_Stick() {
    ((u16 *)plsw_00)[0] = PLsw[0][0];
    ((u16 *)plsw_01)[0] = PLsw[0][1];
    ((u16 *)plsw_00)[1] = PLsw[1][0];
    ((u16 *)plsw_01)[1] = PLsw[1][1];
}

void After_Title(struct _TASK *task_ptr) {
    void (*AT_Jmp_Tbl[21])() = { Menu_Init,        Mode_Select,   Option_Select, Option_Select,  Training_Mode,
                                 System_Direction, Load_Replay,   Option_Select, toSelectGame,   Game_Option,
                                 Button_Config,    Screen_Adjust, Sound_Test,    Memory_Card,    Extra_Option,
                                 Option_Select,    VS_Result,     Save_Replay,   Direction_Menu, Save_Direction,
                                 Load_Direction };

    AT_Jmp_Tbl[task_ptr->r_no[1]](task_ptr);
}

void Menu_Init(struct _TASK *task_ptr) {
    s16 ix;
    s16 fade_on;

    if (Pause_Type == 2) {
        task_ptr->r_no[1] = 4;
    } else {
        task_ptr->r_no[1] = 1;
    }

    task_ptr->r_no[2] = 0;
    task_ptr->r_no[3] = 0;
    Menu_Cursor_Y[0] = 0;
    Menu_Cursor_Y[1] = 0;

    for (ix = 0; ix < 4; ix++) {
        Menu_Suicide[ix] = 0;
        Unsubstantial_BG[ix] = 0;
        Cursor_Y_Pos[0][ix] = 0;
    }

    All_Clear_Suicide();
    pulpul_stop();

    if (task_ptr->r_no[0] == 0) {
        FadeOut(1, 0xFF, 8);
        bg_etc_write_ex(2);
        Setup_Virtual_BG(0, 0x200, 0);
        Setup_BG(1, 0x200, 0);
        Setup_BG(2, 0x200, 0);
        base_y_pos = 0;

        if (task_ptr->r_no[1] != 0x12) {
            fade_on = 0;
        } else {
            fade_on = 1;
        }

        Order[0x4E] = 5;
        Order_Timer[0x4E] = 1;
        effect_57_init(0x4E, 0, 0, 0x45, fade_on);
        load_any_texture_patnum(0x7F30, 0xC, 0);
        setup_pos_remake_key(0);
    }

    cpReadyTask(6, Saver_Task);
}

void Mode_Select(struct _TASK *task_ptr) {
    s16 ix;
    s16 PL_id;
    s16 loop_counter = 7;

    switch (task_ptr->r_no[2]) {
    case 0:
        FadeOut(1, 0xFF, 8);
        task_ptr->r_no[2] += 1;
        task_ptr->timer = 5;
        Mode_Type = 0;
        Present_Mode = 1;

        if (task[1].condition != 1) {
            E_No[0] = 1;
            E_No[1] = 2;
            E_No[2] = 2;
            E_No[3] = 0;
            cpReadyTask(1, Entry_Task);
        }

        Menu_Common_Init();

        for (ix = 0; ix < 4; ix++) {
            Menu_Suicide[ix] = 0;
        }

        Clear_Personal_Data(0);
        Clear_Personal_Data(1);
        Menu_Cursor_Y[0] = Cursor_Y_Pos[0][0];
        Cursor_Y_Pos[0][1] = 0;
        Cursor_Y_Pos[0][2] = 0;
        Cursor_Y_Pos[0][3] = 0;

        for (ix = 0; ix < 4; ix++) {
            Vital_Handicap[ix][0] = 7;
            Vital_Handicap[ix][1] = 7;
        }

        VS_Stage = 0x14;
        Order[0x8A] = 4;
        Order_Timer[0x8A] = 1;

        for (ix = 0; ix < 4; ix++) {
            Message_Data[ix].order = 3;
        }

        effect_57_init(0x64, 0, 0, 0x3F, 2);
        Order[0x64] = 1;
        Order_Dir[0x64] = 8;
        Order_Timer[0x64] = 1;
        Menu_Suicide[0] = 0;
        effect_04_init(0, 0, 0, 0x48);

        for (ix = 0; ix < loop_counter; ix++) {
            effect_61_init(0, ix + 0x50, 0, 0, (u32)ix, ix, 0x7047);
            Order[ix + 0x50] = 1;
            Order_Dir[ix + 0x50] = 4;
            Order_Timer[ix + 0x50] = ix + 0x14;
        }

        Menu_Cursor_Move = loop_counter;
        break;

    case 1:
        if (Menu_Sub_case1(task_ptr) != 0) {
            Order[0x4E] = 2;
            Order_Dir[0x4E] = 0;
            Order_Timer[0x4E] = 1;
            checkAdxFileLoaded();
            checkSelObjFileLoaded();
        }

        break;

    case 2:
        if (FadeIn(1, 0x19, 8) != 0) {
            task_ptr->r_no[2] += 1;
            Suicide[3] = 0;
        }

        break;

    case 3:
        if (Connect_Status == 0 && Menu_Cursor_Y[0] == 1) {
            Menu_Cursor_Y[0] = 2;
        } else {
            PL_id = 0;

            if (MC_Move_Sub(Check_Menu_Lever(0, 0), 0, loop_counter - 1, 1) == 0) {
                PL_id = 1;
                MC_Move_Sub(Check_Menu_Lever(1, 0), 0, loop_counter - 1, 1);
            }
        }

        switch (IO_Result) {
        case 0x100:
            switch (Menu_Cursor_Y[0]) {
            case 0:
                G_No[2] += 1;
                Mode_Type = 0;
                task_ptr->r_no[0] = 5;
                cpExitTask(6);
                Decide_PL(PL_id);
                break;

            case 1:
                Setup_VS_Mode(task_ptr);
                G_No[1] = 0xC;
                G_No[2] = 1;
                Mode_Type = 1;
                cpExitTask(3);
                break;

            case 2:
            case 3:
            case 4:
            case 5:
            case 6:
                task_ptr->r_no[2] += 1;
                task_ptr->free[0] = 0;
                task_ptr->free[1] = Menu_Cursor_Y[0] + 2;
                break;

            default:
                break;
            }

            SE_selected();
            break;
        }

        break;

    default:
        Exit_Sub(task_ptr, 0, task_ptr->free[1]);
        break;
    }
}

void Setup_VS_Mode(struct _TASK *task_ptr) {
    task_ptr->r_no[0] = 5;
    cpExitTask(6);
    plw->wu.operator= 1;
    plw[1].wu.operator= 1;
    Operator_Status[0] = 1;
    Operator_Status[1] = 1;
    grade_check_work_1st_init(0, 0);
    grade_check_work_1st_init(0, 1);
    grade_check_work_1st_init(1, 0);
    grade_check_work_1st_init(1, 1);
    Setup_Training_Difficulty();
}

void Menu_in_Sub(struct _TASK *task_ptr) {
    FadeOut(1, 0xFF, 8);
    task_ptr->r_no[2] += 1;
    task_ptr->timer = 5;
    Menu_Common_Init();
    Menu_Cursor_Y[0] = Cursor_Y_Pos[0][1];
    Menu_Suicide[0] = 1;
    Menu_Suicide[1] = 0;
    Order[0x64] = 4;
    Order_Timer[0x64] = 1;
}

void toSelectGame(struct _TASK *task_ptr) {
    u16 sw;

    switch (task_ptr->r_no[2]) {
    case 0:
        Forbid_Reset = 1;
        Menu_in_Sub(task_ptr);
        Setup_BG(1, 0x200, 0);
        effect_66_init(0x8A, 8, 1, 0, -1, -1, -0x7FF2);
        Order[0x8A] = 3;
        Order_Timer[0x8A] = 1;
        task_ptr->free[0] = 0;
        task_ptr->timer = 0x10;
        break;

    case 1:
        if (Menu_Sub_case1(task_ptr) != 0) {
            Message_Data->kind_req = 5;
            Message_Data->request = 0;
            Message_Data->order = 1;
            Message_Data->timer = 2;
            Message_Data->pos_x = 0;
            Message_Data->pos_y = 0xA0;
            Message_Data->pos_z = 0x18;
            effect_45_init(0, 0, 2);
        }

        break;

    case 2:
        if (FadeIn(1, 0x19, 8) != 0) {
            task_ptr->r_no[2] += 1;
        }

        imgSelectGameButton();
        break;

    case 3:
        imgSelectGameButton();
        sw = (~(*(u16 *)&plsw_01[0]) & (*(u16 *)&plsw_00[0])) |
             (~(*(u16 *)&plsw_01[2]) & (*(u16 *)&plsw_00[2])); // potential macro
        sw &= 0x300;

        if (sw != 0) {
            if (sw != 0x300) {
                if (sw & 0x100) {
                    task_ptr->free[0] = 1;
                }

                SE_selected();
                FadeInit();
                task_ptr->r_no[2] = 8;
                break;
            }
        }

        break;

    case 8:
        imgSelectGameButton();

        if (FadeOut(1, 0x19, 8) != 0) {
            if (task_ptr->free[0]) {
                task_ptr->r_no[2] = 0xA;
                sound_all_off();
                break;
            }

            task_ptr->r_no[2] = 9;
            break;
        }

        break;

    case 9:
        Menu_Suicide[0] = 0;
        Menu_Suicide[1] = 1;
        task_ptr->r_no[1] = 1;
        task_ptr->r_no[2] = 0;
        task_ptr->r_no[3] = 0;
        task_ptr->free[0] = 0;
        FadeOut(1, 0xFF, 8);
        Forbid_Reset = 0;
        break;

    case 10:
        Exit_sound_system();
        task_ptr->r_no[2] += 1;
        break;

    default:
        jmpRebootProgram();
        break;
    }
}

void jmpRebootProgram() {
    Reboot_Program("cdrom0:\\SLUS_209.49;1");
}

void imgSelectGameButton() {
    dispButtonImage2(0x74, 0x6B, 0x18, 0x20, 0x1A, 0, 4);
    dispButtonImage2(0xB2, 0x6B, 0x18, 0x20, 0x1A, 0, 5);
}

void Training_Mode(struct _TASK *task_ptr) {
    s16 ix;
    s16 char_index;
    s16 PL_id;

    s16 unused_s4;
    s16 unused_s3;

    switch (task_ptr->r_no[2]) {
    case 0:
        Menu_in_Sub(task_ptr);
        mpp_w.initTrainingData = 1;
        effect_57_init(0x6F, 0xB, 0, 0x3F, 2);
        Order[0x6F] = 1;
        Order_Dir[0x6F] = 8;
        Order_Timer[0x6F] = 1;
        effect_04_init(1, 5, 0, 0x48);

        ix = 0;
        unused_s4 = char_index = 0x35;

        while (ix < 3) {
            effect_61_init(0, ix + 0x50, 0, 1, char_index, ix, 0x7047);
            Order[ix + 0x50] = 1;
            Order_Dir[ix + 0x50] = 4;
            Order_Timer[ix + 0x50] = ix + 0x14;
            ix++;
            unused_s3 = char_index++;
        }

        Menu_Cursor_Move = 3;
        system_dir[4] = system_dir[1];
        system_dir[5] = system_dir[1];
        break;

    case 1:
        Menu_Sub_case1(task_ptr);
        break;

    case 2:
        if (FadeIn(1, 0x19, 8) != 0) {
            task_ptr->r_no[2] += 1;
            Suicide[3] = 0;
        }

        break;

    case 3:
        PL_id = 0;

        if (MC_Move_Sub(Check_Menu_Lever(0, 0), 0, 2, 0xFF) == 0) {
            PL_id = 1;
            MC_Move_Sub(Check_Menu_Lever(1, 0), 0, 2, 0xFF);
        }

        switch (IO_Result) {
        case 0x100:
        case 0x200:
            break;

        default:
            return;
        }

        SE_selected();

        if (Menu_Cursor_Y[0] == 2 || IO_Result == 0x200) {
            Menu_Suicide[0] = 0;
            Menu_Suicide[1] = 1;
            task_ptr->r_no[1] = 1;
            task_ptr->r_no[2] = 0;
            task_ptr->r_no[3] = 0;
            task_ptr->free[0] = 0;
            Order[0x6F] = 4;
            Order_Timer[0x6F] = 4;
            break;
        }

        Decide_ID = PL_id;

        if (Menu_Cursor_Y[0] == 0) {
            Mode_Type = 3;
            Present_Mode = 4;
        } else {
            Mode_Type = 4;
            Present_Mode = 5;
        }

        Setup_VS_Mode(task_ptr);
        G_No[2] += 1;
        task_ptr->r_no[0] = 5;
        cpExitTask(6);
        Champion = PL_id;
        Pause_ID = PL_id;
        Training_ID = PL_id;
        New_Challenger = PL_id ^ 1;
        cpExitTask(1);

        break;
    }
}

void Option_Select(struct _TASK *task_ptr) {
    s16 ix;         // r16
    s16 char_index; // r17

    s16 unused_s5;
    s16 unused_s4;
    s16 unused_s3;
    s16 unused_s2;

    switch (task_ptr->r_no[2]) {
    case 0:
        Menu_in_Sub(task_ptr);
        Order[0x4E] = 2;
        Order_Dir[0x4E] = 0;
        Order_Timer[0x4E] = 1;
        effect_57_init(0x4F, 1, 0, 0x3F, 2);
        Order[0x4F] = 1;
        Order_Dir[0x4F] = 8;
        Order_Timer[0x4F] = 1;

        if (save_w[Present_Mode].Extra_Option == 0) {
            effect_04_init(1, 4, 0, 0x48);

            ix = 0;
            unused_s5 = char_index = 0x2F;

            while (ix < 6) {
                effect_61_init(0, ix + 0x50, 0, 1, char_index, ix, 0x7047);
                Order[ix + 0x50] = 1;
                Order_Dir[ix + 0x50] = 4;
                Order_Timer[ix + 0x50] = ix + 0x14;
                ix++;
                unused_s4 = char_index++;
            }

            Menu_Cursor_Move = 6;
            break;
        }

        effect_04_init(1, 1, 0, 0x48);

        ix = 0;
        unused_s3 = char_index = 7;

        while (ix < 7) {
            effect_61_init(0, ix + 0x50, 0, 1, char_index, ix, 0x7047);
            Order[ix + 0x50] = 1;
            Order_Dir[ix + 0x50] = 4;
            Order_Timer[ix + 0x50] = ix + 0x14;
            ix++;
            unused_s2 = char_index++;
        }

        Menu_Cursor_Move = 7;
        break;

    case 1:
        if (Menu_Sub_case1(task_ptr) != 0) {
            checkSelObjFileLoaded();
        }

        break;

    case 2:
        if (FadeIn(1, 0x19, 8) != 0) {
            task_ptr->r_no[2] += 1;
            Suicide[3] = 0;
        }

        break;

    case 3:
        if (save_w[Present_Mode].Extra_Option) {
            ix = 1;
        } else {
            ix = 0;
        }

        if (MC_Move_Sub(Check_Menu_Lever(0, 0), 0, ix + 5, 0xFF) == 0) {
            MC_Move_Sub(Check_Menu_Lever(1, 0), 0, ix + 5, 0xFF);
        }

        switch (IO_Result) {
        case 0x100:
        case 0x200:
            break;

        default:
            return;
        }

        SE_selected();

        if (Menu_Cursor_Y[0] == ix + 5 || IO_Result == 0x200) {
            Menu_Suicide[0] = 0;
            Menu_Suicide[1] = 1;
            task_ptr->r_no[1] = 1;
            task_ptr->r_no[2] = 0;
            task_ptr->r_no[3] = 0;
            task_ptr->free[0] = 0;
            Order[0x4F] = 4;
            Order_Timer[0x4F] = 4;

            if (Check_Change_Contents()) {
                if (save_w[Present_Mode].Auto_Save) {
                    task_ptr->r_no[0] = 4;
                    task_ptr->r_no[1] = 0;
                    Forbid_Reset = 1;
                    Copy_Check_w();
                    break;
                }
            }

            break;
        }

        task_ptr->r_no[2] += 1;
        task_ptr->free[0] = 0;
        X_Adjust_Buff[0] = X_Adjust;
        X_Adjust_Buff[1] = X_Adjust;
        X_Adjust_Buff[2] = X_Adjust;
        Y_Adjust_Buff[0] = Y_Adjust;
        Y_Adjust_Buff[1] = Y_Adjust;
        Y_Adjust_Buff[2] = Y_Adjust;
        Correct_X[1] = Correct_X[0];
        Correct_X[2] = Correct_X[0];
        Correct_X[3] = Correct_X[0];
        Correct_Y[1] = Correct_Y[0];
        Correct_Y[2] = Correct_Y[0];
        Correct_Y[3] = Correct_Y[0];
        break;

    default:
        Exit_Sub(task_ptr, 1, Menu_Cursor_Y[0] + 9);
        break;
    }
}

void System_Direction(struct _TASK *task_ptr) {
    s16 ix;
    s16 char_index;

    s16 unused_s3;
    s16 unused_s2;

    switch (task_ptr->r_no[2]) {
    case 0:
        Menu_in_Sub(task_ptr);
        Order[0x4E] = 2;
        Order_Dir[0x4E] = 3;
        Order_Timer[0x4E] = 1;
        effect_57_init(0x6D, 0xA, 0, 0x3F, 2);
        Order[0x6D] = 1;
        Order_Dir[0x6D] = 8;
        Order_Timer[0x6D] = 1;
        effect_04_init(1, 3, 0, 0x48);
        Convert_Buff[3][0][0] = Direction_Working[1];
        effect_64_init(0x61U, 0, 1, 0xA, 0, 0x7047, 0xB, 3, 0);
        Order[0x61] = 1;
        Order_Dir[0x61] = 4;
        Order_Timer[0x61] = 0x14;

        ix = 0;
        unused_s3 = char_index = 0x2B;

        while (ix < 4) {
            effect_61_init(0, ix + 0x50, 0, 1, char_index, ix + 1, 0x7047);
            Order[ix + 0x50] = 1;
            Order_Dir[ix + 0x50] = 4;
            Order_Timer[ix + 0x50] = ix + 0x15;
            ix++;
            unused_s2 = char_index++;
        }

        Menu_Cursor_Move = 4;
        Page_Max = Check_SysDir_Page();
        break;

    case 1:
        Menu_Sub_case1(task_ptr);
        break;

    case 2:
        if (FadeIn(1, 0x19, 8) != 0) {
            task_ptr->r_no[2] += 1;
            Suicide[3] = 0;
        }

        break;

    case 3:
        System_Dir_Move_Sub(0);

        if (IO_Result == 0) {
            System_Dir_Move_Sub(1);
        }

        switch (IO_Result) {
        case 0x100:
            if (Menu_Cursor_Y[0] == 0) {
                break;
            }

            // fallthrough

        case 0x200:
            SE_selected();
            Order[0x6D] = 4;
            Order_Timer[0x6D] = 4;

            if (Menu_Cursor_Y[0] == 4 || IO_Result == 0x200) {
                Menu_Suicide[0] = 0;
                Menu_Suicide[1] = 1;
                task_ptr->r_no[1] = 1;
                task_ptr->r_no[2] = 0;
                task_ptr->r_no[3] = 0;
                task_ptr->free[0] = 0;
                break;
            }

            task_ptr->r_no[2] += 1;
            task_ptr->free[0] = 0;

            break;
        }

        break;

    default:
        Exit_Sub(task_ptr, 1, Menu_Cursor_Y[0] + 0x11);
        break;
    }
}

void System_Dir_Move_Sub(s16 PL_id) {
    u16 sw = ~((u16 *)plsw_01)[PL_id] & ((u16 *)plsw_00)[PL_id]; // potential macro
    sw = Check_Menu_Lever(PL_id, 0);
    MC_Move_Sub(sw, 0, 4, 0xFF);
    System_Dir_Move_Sub_LR(sw, 0);
    Direction_Working[1] = Convert_Buff[3][0][0];
    Direction_Working[4] = Convert_Buff[3][0][0];
    Direction_Working[5] = Convert_Buff[3][0][0];
}

void System_Dir_Move_Sub_LR(u16 sw, s16 cursor_id) {
    if (Menu_Cursor_Y[cursor_id] != 0) {
        return;
    }

    switch (sw) {
    case 4:
        Convert_Buff[3][cursor_id][Menu_Cursor_Y[cursor_id]] -= 1;

        if (Convert_Buff[3][cursor_id][Menu_Cursor_Y[cursor_id]] < 0) {
            Convert_Buff[3][cursor_id][Menu_Cursor_Y[cursor_id]] = 1;
        }

        SE_dir_cursor_move();
        return;

    case 8:
        Convert_Buff[3][cursor_id][Menu_Cursor_Y[cursor_id]] += 1;

        if (Convert_Buff[3][cursor_id][Menu_Cursor_Y[cursor_id]] > 1) {
            Convert_Buff[3][cursor_id][Menu_Cursor_Y[cursor_id]] = 0;
        }

        SE_dir_cursor_move();
        return;
    }
}

void Direction_Menu(struct _TASK *task_ptr) {
    Menu_Cursor_Y[1] = Menu_Cursor_Y[0];

    switch (task_ptr->r_no[2]) {
    case 0:
        FadeOut(1, 0xFF, 8);
        task_ptr->r_no[2] += 1;
        task_ptr->timer = 5;
        Menu_Suicide[1] = 1;
        Menu_Suicide[2] = 0;
        Menu_Page = 0;
        Menu_Page_Buff = Menu_Page;
        Message_Data->kind_req = 3;
        break;

    case 1:
        FadeOut(1, 0xFF, 8);
        task_ptr->r_no[2] += 1;
        Setup_Next_Page(task_ptr, 0);
        /* fallthrough */

    case 2:
        FadeOut(1, 0xFF, 8);

        if (--task_ptr->timer == 0) {
            task_ptr->r_no[2] += 1;
            FadeInit();
        }

        break;

    case 3:
        if (FadeIn(1, 0x19, 8) != 0) {
            task_ptr->r_no[2] += 1;
        }

        break;

    case 4:
        Pause_ID = 0;

        Dir_Move_Sub(task_ptr, 0);

        if (IO_Result == 0) {
            Pause_ID = 1;
            Dir_Move_Sub(task_ptr, 1);
        }

        if (Menu_Cursor_Y[1] != Menu_Cursor_Y[0]) {
            SE_cursor_move();
            system_dir[1].contents[Menu_Page][Menu_Max] = 1;

            if (Menu_Cursor_Y[0] < Menu_Max) {
                Message_Data->order = 1;
                Message_Data->request = Menu_Page * 0xC + Menu_Cursor_Y[0] * 2 + 1;
                Message_Data->timer = 2;

                if (msgSysDirTbl[0]->msgNum[Menu_Page * 0xC + Menu_Cursor_Y[0] * 2 + 1] == 1) {
                    Message_Data->pos_y = 0x36;
                } else {
                    Message_Data->pos_y = 0x3E;
                }
            } else {
                Message_Data->order = 1;
                Message_Data->request = system_dir[1].contents[Menu_Page][Menu_Max] + 0x74;
                Message_Data->timer = 2;
                Message_Data->pos_y = 0x36;
            }
        }

        switch (IO_Result) {
        case 0x200:
            task_ptr->r_no[2] += 1;
            Menu_Suicide[0] = 0;
            Menu_Suicide[1] = 0;
            Menu_Suicide[2] = 1;
            SE_dir_selected();
            break;

        case 0x80:
        case 0x800:
            task_ptr->r_no[2] = 1;
            task_ptr->timer = 5;

            if (--Menu_Page < 0) {
                Menu_Page = (s8)Page_Max;
            }

            SE_dir_selected();
            break;

        case 0x40:
        case 0x400:
            task_ptr->r_no[2] = 1;
            task_ptr->timer = 5;

            if (++Menu_Page > Page_Max) {
                Menu_Page = 0;
            }

            SE_dir_selected();
            break;

        case 0x100:
            if (Menu_Cursor_Y[0] == Menu_Max) {
                switch (system_dir[1].contents[Menu_Page][Menu_Max]) {
                case 0:
                    task_ptr->r_no[2] = 1;
                    task_ptr->timer = 5;

                    if (--Menu_Page < 0) {
                        Menu_Page = (s8)Page_Max;
                    }

                    break;

                case 2:
                    task_ptr->r_no[2] = 1;
                    task_ptr->timer = 5;

                    if (++Menu_Page > Page_Max) {
                        Menu_Page = 0;
                    }

                    break;

                default:
                    task_ptr->r_no[2] += 1;
                    Menu_Suicide[0] = 0;
                    Menu_Suicide[1] = 0;
                    Menu_Suicide[2] = 1;
                    break;
                }

                SE_selected();
                break;
            }

            break;
        }

        break;

    default:
        Exit_Sub(task_ptr, 2, 5);
        break;
    }
}

void Dir_Move_Sub(struct _TASK *task_ptr, s16 PL_id) {
    u16 sw;
    u16 ix;

    ((u16 *)plsw_00)[0] = PLsw[0][0];
    ((u16 *)plsw_01)[0] = PLsw[0][1];
    ((u16 *)plsw_00)[1] = PLsw[1][0];
    ((u16 *)plsw_01)[1] = PLsw[1][1];

    for (ix = 0; ix < 2; ix++) {
        ((u16 *)plsw_00)[ix] &= 0x4FFF;
        ((u16 *)plsw_01)[ix] &= 0x4FFF;
    }

    sw = Check_Menu_Lever(PL_id, 0);
    Dir_Move_Sub2(sw);

    if (task_ptr->r_no[1] == 0xE) {
        Ex_Move_Sub_LR(sw, PL_id);
        return;
    }

    Dir_Move_Sub_LR(sw, PL_id);
}

u16 Dir_Move_Sub2(u16 sw) {
    if (Menu_Cursor_Move > 0) {
        return 0;
    }

    switch (sw) {
    case 0x1:
        Menu_Cursor_Y[0] -= 1;

        if (Menu_Cursor_Y[0] < 0) {
            Menu_Cursor_Y[0] = Menu_Max;
        }

        SE_cursor_move();
        return IO_Result = 1;

    case 0x2:
        Menu_Cursor_Y[0] += 1;

        if (Menu_Cursor_Y[0] > Menu_Max) {
            Menu_Cursor_Y[0] = 0;
        }

        SE_cursor_move();
        return IO_Result = 2;

    case 0x10:
        return IO_Result = 0x10;

    case 0x20:
        return IO_Result = 0x20;

    case 0x40:
        return IO_Result = 0x40;

    case 0x80:
        return IO_Result = 0x80;

    case 0x100:
        return IO_Result = 0x100;

    case 0x200:
        return IO_Result = 0x200;

    case 0x400:
        return IO_Result = 0x400;

    case 0x800:
        return IO_Result = 0x800;

    case 0x4000:
        return IO_Result = 0x4000;

    default:
        return IO_Result = 0;
    }
}

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", Dir_Move_Sub_LR);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", Setup_Next_Page);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", Save_Direction);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", Load_Direction);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", Load_Replay);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", Load_Replay_Sub);
// Load_Replay_Sub literal_742_00522630

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", Setup_Index_64);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", Game_Option_Index_Data);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", Sound_Data_Max);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", Load_Replay_MC_Sub);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", Game_Option);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", Game_Option_Sub);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", GO_Move_Sub_LR);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", Button_Config);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", Button_Config_Sub);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", Button_Move_Sub_LR);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", Button_Exit_Check);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", Return_Option_Mode_Sub);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", Screen_Adjust);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", Screen_Adjust_Sub);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", Screen_Exit_Check);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", Screen_Move_Sub_LR);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", Sound_Test);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", Setup_Sound_Mode);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", Sound_Cursor_Sub);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", SD_Move_Sub_LR);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", Memory_Card);
// Memory_Card contains literal_1183_00522690

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", Menu_Deley_Time);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", Save_Load_Menu);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", Go_Back_MC);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", Setup_Final_Cursor_Pos);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", Memory_Card_Sub);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", Memory_Card_Move_Sub_LR);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", MC_Move_Sub);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", Exit_Sub);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", Menu_Common_Init);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", Check_Menu_Lever);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", Suspend_Menu);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", In_Game);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", Menu_Select);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", Yes_No_Cursor_Move_Sub);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", Button_Config_in_Game);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", Setup_Button_Sub);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", Button_Exit_Check_in_Game);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", Return_Pause_Sub);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", Check_Pad_in_Pause);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", Pad_Come_Out);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", bg_etc_write_ex);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", Wait_Load_Save);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", Disp_Auto_Save);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", DAS_1st);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", DAS_2nd);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", DAS_3rd);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", DAS_4th);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", Disp_Auto_Save2);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", DAS2_4th);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", Wait_Replay_Check);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", VS_Result);
// VS_Result contains literal_1803

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", literal_2159);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", literal_2160);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", literal_2215);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", literal_2216);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", Setup_Win_Lose_OBJ);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", VS_Result_Select_Sub);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", After_VS_Move_Sub);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", VS_Result_Move_Sub);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", Save_Replay);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", Setup_Save_Replay_1st);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", Setup_Save_Replay_2nd);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", Setup_Replay_Sub);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", Return_VS_Result_Sub);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", Save_Replay_MC_Sub);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", Exit_Replay_Save);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", Decide_PL);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", Wait_Pause_in_Tr);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", Control_Player_Tr);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", Next_Be_Tr_Menu);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", Check_Pause_Term_Tr);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", Pause_Check_Tr);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", Setup_Tr_Pause);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", Flash_1P_or_2P);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", Pause_in_Normal_Tr);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", Pause_1st_Sub);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", Reset_Training);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", Reset_Replay);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", Training_Menu);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", Training_Init);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", Normal_Training);
// Normal_Training contains literal_2331

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", Menu_Max_Data_Tr);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", Setup_NTr_Data);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", Check_Skip_Replay);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", Check_Skip_Recording);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", Yes_No_Cursor_Exit_Training);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", Button_Config_Tr);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", Button_Exit_Check_in_Tr);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", Dummy_Setting);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", Training_Option);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", Training_Disp_Sub);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", Dummy_Move_Sub);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", Dummy_Move_Sub_LR);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", Blocking_Training);
// Blocking_Training contains literal_2592

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", literal_2708);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", literal_2709);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", literal_2710);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", literal_2711);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", literal_2712);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", literal_2713);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", training_letter_data);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", Blocking_Tr_Option);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", Training_Init_Sub);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", Training_Exit_Sub);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", Character_Change);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", Default_Training_Data);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", Default_Training_Option);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", Wait_Replay_Load);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", After_Replay);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", Menu_Sub_case1);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", Back_to_Mode_Select);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", Extra_Option);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", Ex_Move_Sub_LR);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", End_Replay_Menu);
