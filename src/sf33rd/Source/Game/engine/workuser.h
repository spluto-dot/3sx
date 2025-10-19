#ifndef WORKUSER_H
#define WORKUSER_H

#include "sf33rd/Source/Game/engine/cmd_data.h"
#include "types.h"

#include <stdbool.h>

typedef enum AppearanceType {
    APPEAR_TYPE_NON_ANIMATED,
    APPEAR_TYPE_ANIMATED,
    APPEAR_TYPE_UNKNOWN_2, // FIXME: document
    APPEAR_TYPE_UNKNOWN_3, // FIXME: document
} AppearanceType;

typedef struct GameState {
    PLW plw[2];

    /// Afterimage data
    ZanzouTableEntry zanzou_table[2][48];

    SA_WORK super_arts[2];

    /// Stun data
    PiyoriType piyori_type[2];

    AppearanceType appear_type;

    /// Player controller routine indices
    s16 pcon_rno[4];

    /// `true` if the game has been slowed down at round end
    bool round_slow_flag;

    bool pcon_dp_flag;
    u8 win_sp_flag;

    /// `true` if death SFX playback needs to be requested
    bool dead_voice_flag;
} GameState;

extern GameState gs;

// bss
extern u8 Order[148];
extern u8 Order_Timer[148];
extern u8 Order_Dir[148];

// sbss
extern u32 Score[2][3];
extern const_s16_arr Tech_Address[2];
extern u32 Complete_Bonus;
extern void* Shell_Address[2];
extern u32 Stock_Score[2];
extern u32 Vital_Bonus[2];
extern u32 Time_Bonus[2];
extern u32 Stage_Stock_Score[2];
extern u32 Bonus_Score;
extern u32 Final_Bonus_Score;
extern void* Synchro_Address[2][2];
extern u32 WGJ_Score;
extern u32 Bonus_Score_Plus;
extern u32 Perfect_Bonus[2];
extern u32 Keep_Score[2];
extern u32 Disp_Score_Buff[2];
extern s8 Winner_id;
extern s8 Loser_id;
extern s8 Counter_hi;
extern s8 Counter_low;
extern s8 Break_Into;
extern u8 My_char[2];
extern u8 Allow_a_battle_f;
extern u8 Round_num;
extern s8 Complete_Judgement;
extern s8 Fade_Flag;
extern s8 Super_Arts[2];
extern s8 Forbid_Break;
extern s8 Request_Break[2];
extern s8 Continue_Count[2];
extern s8 Personal_Continue_Flag[2];
extern s8 Personal_Disp_Flag;
extern s8 win_pause_go;
extern s8 request_message;
extern s8 judge_flag;
extern s8 WINNER;
extern s8 LOSER;
extern s8 New_Challenger;
extern s8 Champion;
extern s8 Fade_Half_Flag;
extern s8 Reserve_Cut;
extern s8 Perfect_Flag;
extern s8 Next_Step;
extern s8 Switch_Type;
extern s8 Cover_Timer;
extern s8 Personal_Timer[2];
extern s8 Request_E_No;
extern s8 Request_G_No;
extern u8 Present_Rank[2];
extern s8 Best_Grade[2];
extern s8 Cursor_Timer[2];
extern s8 Demo_Type;
extern s8 Rank_Type;
extern s8 Flash_Sign[2];
extern s8 Flash_Rank_Time;
extern s8 Flash_Rank_Interval;
extern s32 Ranking_X;
extern s8 Rank;
extern s8 Rank_X;
extern s8 E_07_Flag[2];
extern s8 Complete_Victory;
extern s8 Demo_Flag;
extern s32 Next_Demo;
extern s8 Demo_PL_Index;
extern s8 Demo_Stage_Index;
extern s8 Face_MV_Request;
extern s8 Face_Move;
extern s8 Appear_Cursor;
extern s8 Select_Timer;
extern s8 Time_Stop;
extern s8 Time_Over;
extern s8 Player_id;
extern s8 Last_Player_id;
extern s8 Player_Number;
extern u8 DENJIN_Term[2];
extern s8 Rapid_No[2][4];
extern s8 COM_id;
extern s8 EM_id;
extern s8 Select_Status[2];
extern s8 Select_Demo_Index;
extern u8 Country;
extern s8 Demo_Time_Stop;
extern s8 Combo_Speed[2];
extern s8 Exec_Wipe;
extern s8 Passive_Mode;
extern s8 Passive_Flag[2];
extern s8 Flip_Flag[2];
extern s8 Lie_Flag[2];
extern s8 Counter_Attack[2];
extern s8 Attack_Flag[2];
extern s8 Limited_Flag[2];
extern s8 Shell_Ignore_Timer[2];
extern s8 Event_Judge_Gals;
extern u8 EJG_index[4];
extern s8 Guard_Flag[2];
extern s8 Pierce_Menu[2];
extern s8 Face_MV_Time;
extern s8 Before_Jump[2];
extern s8 Stop_Combo;
extern u8 Stock_Hit_Flag[2];
extern s8 Rolling_Flag[2];
extern u8 Continue_Coin[2];
extern s8 Ignore_Entry[2];
extern s8 Slide_Type;
extern s8 Moving_Plate[2];
extern s8 Naming_Cut[2];
extern s8 Moving_Plate_Counter[2];
extern s8 Player_Color[2];
extern s8 PP_Priority[2][3];
extern s8 OK_Priority[2];
extern u8 Stock_My_char[2];
extern s8 Stock_Player_Color[2];
extern u8 Usage;
extern s8 Music_Fade;
extern s8 Stop_SG;
extern s8 Operator_Status[2];
extern s8 Round_Operator[2];
extern s8 another_bg[2];
extern s8 Last_Super_Arts[2];
extern s8 Last_My_char[2];
extern s8 Continue_Menu[2];
extern s8 Timer_Freeze;
extern u8 Type_of_Attack[2];
extern s8 Standing_Timer[2];
extern s8 Before_Look[2];
extern s8 Attack_Count_No0[2];
extern s8 Standing_Master_Timer[2];
extern s8 PB_Music_Off;
extern s8 No_Death;
extern s8 Flash_MT[2];
extern s8 Squat_Timer[2];
extern s8 Squat_Master_Timer[2];
extern s8 Turn_Over[2];
extern s8 Turn_Over_Timer[2];
extern s8 Jump_Pass_Timer[2][4];
extern s8 sa_gauge_flash[2];
extern s8 Receive_Flag[2];
extern s8 Disposal_Again[2];
extern volatile s8 BGM_Vol;
extern u8 Used_char[2];
extern s8 Break_Com[2][20];
extern s8 aiuchi_flag;
extern u8 paring_counter[2];
extern u8 paring_bonus_r[2];
extern u8 paring_ctr_vs[2][2];
extern u8 paring_ctr_ori[2];
extern u8 Attack_Count_Buff[2][4];
extern u8 Attack_Count_Index[2];
extern u8 CC_Value[2];
extern u8 Continue_Coin2[2];
extern u8 Weak_PL;
extern u8 Bullet_No[2];
extern u8 Bullet_Counter[2];
extern u8 Final_Result_id;
extern s8 Disp_Win_Name;
extern u8 Perfect_Counter[2];
extern u8 Straight_Counter[2];
extern u8 Appear_Q;
extern s8 Cut_Scroll;
extern s8 Break_Into_CPU;
extern s8 ID_of_Face[3][8];
extern s8 Cursor_Move[2];
extern s8 Auto_Cursor[2];
extern s8 Auto_No[2];
extern s8 Auto_Index[2];
extern s8 Auto_Timer[2];
extern s8 Explosion;
extern s8 Introduce_Break_Into[2];
extern s8 gouki_wins;
extern s8 EM_Rank;
extern s8 Disp_PERFECT;
extern s8 Escape_SS;
extern s8 Deley_Shot_No[2];
extern s8 Deley_Shot_Timer[2];
extern s8 Lost_Round[2];
extern s8 Super_Arts_Finish[2];
extern s8 Stage_SA_Finish[2];
extern s8 Perfect_Finish[2];
extern s8 Cheap_Finish[2];
extern s8 Last_My_char2[2];
extern s8 gouki_app;
extern s8 Bonus_Game_Complete;
extern u8 Get_Demo_Index;
extern u8 Combo_Demo_Flag;
extern u8 Stage_Continue[2];
extern u8 Pause_Hit_Marks;
extern u8 Extra_Break;
extern u8 Shin_Gouki_BGM;
extern s8 Stage_Lost_Round[2];
extern s8 Stage_Perfect_Finish[2];
extern s8 Stage_Cheap_Finish[2];
extern s8 EXE_obroll;
extern u8 End_PL;
extern s8 Stock_Com_Arts[2];
extern u8 PB_Status;
extern u8 Flip_Counter[2];
extern u8 Stage_Time_Finish[2];
extern u8 Bonus_Type;
extern s8 Completion_Bonus[2][2];
extern s8 ichikannkei;
extern s8 Complete_Face;
extern u8 Plate_Disposal_No[2][3];
extern u8 SO_No[2];
extern u8 Disp_Command_Name[2][3];
extern u8 SC_No[4];
extern const u8* Free_Ptr[2];
extern u8 BGM_No[2];
extern u8 BGM_Timer[2];
extern u8 EM_List[2][2];
extern s8 Sel_EM_Complete[2];
extern s8 Temporary_EM[2];
extern s8 OK_Moving_SA_Plate[2];
extern u8 Battle_Q[2];
extern u8 EM_History[2][10];

// Go faster during a non-gameplay animation
extern bool Scene_Cut;

extern u8 GO_No[4];
extern u8 Aborigine;
extern u8 Continue_Count_Down[2];
extern u8 WGJ_Target;
extern u8 EM_Candidate[2][2][10];
extern s8 Last_Selected_EM[2];
extern u8 Q_Country;
extern u8 Continue_Cut[2];
extern u8 Introduce_Boss[2][2];
extern s8 Suicide[8];
extern u8 Final_Play_Type[2];
extern s8 Rank_In[2][4];
extern s8 Request_Disp_Rank[2][4];
extern u8 Reset_Timer[2];
extern u8 bbbs_type;
extern u8 Straight_Flag[2];
extern u8 kakushi_ix;
extern u8 kakushi_op;
extern u8 RO_backup[2];
extern u8 PT_backup;
extern u8 E_Number[2][4];
extern u8 E_No[4];
extern u8 C_No[4];

// Character select routine indices
extern u8 S_No[4];

// Game routine indices
extern u8 G_No[4];

extern u8 D_No[4];
extern u8 M_No[4];
extern u8 Exit_No;
extern u8 SP_No[2][4];
extern u8 Face_No[2];
extern s8 Select_Start[2];
extern s8 Cursor_X[2];
extern s8 Cursor_Y[2];
extern s8 Cursor_Y_Pos[2][4];
extern s8 Stop_Cursor[2];
extern u8 Training_Index;
extern u8 Connect_Status;
extern u8 Menu_Suicide[4];
extern u8 Game_pause;
extern u8 Game_difficulty;
extern u8 Pause;
extern u8 Pause_ID;
extern u8 Play_Type;
extern u8 Exit_Menu;
extern u8 Conclusion_Flag;
extern u8 CP_No[2][4];
extern u8 CP_Index[2][8];
extern u8 Gap_Timer;
extern u8 Message_Suicide[4];

// Whether or not battle UI is displayed
extern u8 Disp_Cockpit;

extern s8 Select_Arts[2];
extern u8 Lamp_No;
extern u8 Lamp_Index;
extern u8 Lamp_Color;
extern u8 Stop_Update_Score;
extern u8 test_flag;
extern u8 ixbfw_cut;
extern u8 Cont_No[4];
extern u8 PL_Wins[2];
extern u8 Fade_R_No0;
extern u8 Fade_R_No1;
extern u8 Conclusion_Type;
extern u8 win_type[2][4];
extern u8 message_index;
extern u8 F_No0[2];
extern u8 F_No1[2];
extern u8 F_No2[2];
extern u8 F_No3[2];
extern u8 keep_condition[11];
extern s8 Check_Buff[4][2][12];
extern s8 Convert_Buff[4][2][12];
extern u8 Unsubstantial_BG[4];
extern s8 Menu_Cursor_X[2];
extern s8 Menu_Cursor_Y[2];
extern u8 Replay_Status[2];
extern u8 Disappear_LOGO;
extern u8 count_end;
extern u8 Play_Game;
extern s8 Menu_Cursor_Move;
extern u8 flash_win_type[2][4];
extern u8 sync_win_type[2][4];

typedef enum ModeType {
    MODE_ARCADE,
    MODE_VERSUS,
    MODE_NETWORK,
    MODE_NORMAL_TRAINING,
    MODE_PARRY_TRAINING,
    MODE_REPLAY,
} ModeType;

extern ModeType Mode_Type;

extern s8 Menu_Page;
extern s8 Menu_Max;
extern u8 reset_NG_flag;
extern s8 VS_Stage;
extern u8 Present_Mode;
extern u8 Play_Mode;
extern u8 Page_Max;
extern u8 Direction_Working[6];
extern s8 Vital_Handicap[6][2];
extern s8 Cursor_Limit[2];
extern u8 Synchro_No;
extern s8 SA_shadow_on;
extern u8 Pause_Down;
extern u8 Training_ID;
extern u8 Disp_Attack_Data;
extern u8 Record_Data_Tr;
extern u8 End_Training;
extern s8 Menu_Page_Buff;
extern u8 Reset_Bootrom;
extern u8 Decide_ID;
extern s8 Training_Cursor;
extern s8 Lag_Timer;
extern u8* Lag_Ptr;
extern u8 CPU_Time_Lag[2];
extern u8 Forbid_Reset;
extern u8 CPU_Rec[2];
extern u8 Pause_Type;
extern u16 Game_timer;
extern s16 Control_Time;
extern s16 Time_in_Time;
extern s16 Round_Level;
extern u16 Round_Result;
extern u16 Fade_Number;
extern s16 G_Timer;
extern s16 D_Timer;
extern s16 Rank_Pos_X;
extern s16 Rank_Pos_Y;
extern s16 E_Timer;
extern s16 F_Timer[2];
extern s16 ENTRY_X;
extern s16 C_Timer;
extern s16 S_Timer;
extern s16 Flash_Complete[2];
extern s16 Sel_PL_Complete[2];
extern s16 Sel_Arts_Complete[2];
extern s16 Arts_Y[2];
extern s16 Move_Super_Arts[2];
extern s16 Battle_Country;
extern s16 Face_Status;
extern s16 Unit_Of_Timer;

// ID of the player currently operated on during player selection routines
extern s16 ID;

// ID of the player currently operated on during player selection routines (similar to `ID`)
extern s8 ID2;

extern s16 mes_already;
extern s16 Timer_00[2];
extern s16 Timer_01[2];
extern s16 PL_Distance[2];
extern s16 Area_Number[2];
extern u16 Lever_Buff[2];
extern u16 Lever_Pool[2];
extern s16 Tech_Index[2];
extern s16 Random_ix16;
extern s16 Random_ix32;
extern s16 M_Timer;
extern s16 VS_Tech[2];
extern u16 Guard_Type[2];
extern s16 Separate_Area[2][3];
extern u16 Free_Lever[2];
extern s16 Term_No[2];
extern s16 Com_Width_Data[2];
extern u16 Lever_Squat[2];
extern u16 M_Lv[2];
extern s16 Insert_Y;
extern s16 scr_req_x;
extern s16 scr_req_y;
extern s16 zoom_req_flag_old;
extern s16 zoom_request_flag;
extern s16 zoom_request_level;
extern s16 Last_Selected_ID;
extern s16 Last_Called_SE;
extern s16 VS_Index[2];
extern s16 Rapid_Index[2];
extern s16 Shell_Separate_Area[2][3];
extern s16 Attack_Counter[2];
extern s16 Last_Attack_Counter[2];
extern u16 Pattern_Index[2];
extern s16 Com_Color_Shot;
extern u16 Resume_Lever[2][20];
extern u16 players_timer;
extern u16 Lever_Store[2][3];
extern s16 Return_CP_No[2];
extern s16 Return_CP_Index[2];
extern s16 Return_Pattern_Index[2];
extern u16 Lever_LR[2];
extern s16 Last_Eftype[2];
extern u16 DENJIN_No[2];
extern u16 SC_Personal_Time[2];
extern s16 Guard_Counter[2];
extern s16 Limit_Time;
extern s16 Last_Pattern_Index[2];
extern s16 Random_ix16_ex;
extern s16 Random_ix32_ex;
extern s16 DE_X[2];
extern s16 Exit_Timer;
extern s16 Max_vitality;
extern s16 Bonus_Game_Flag;
extern s16 Bonus_Game_Work;
extern s16 Bonus_Game_result;
extern s16 Stock_Bonus_Game_Result;
extern s16 bs_scrrrl[2][2];
extern s16 Bonus_Stage_RNO[4];
extern s16 Bonus_Stage_Level;
extern s16 Bonus_Stage_Tix;
extern s16 Bonus_Game_ex_result;
extern s16 Stock_Com_Color[2];
extern s16 bs2_floor[3];
extern s16 bs2_hosei[3];
extern s16 bs2_current_damage;
extern u16 Win_Record[2];
extern u16 Stock_Win_Record[2];
extern u16 WGJ_Win;
extern s16 Target_BG_X[6];
extern s16 Offset_BG_X[6];
extern u16 Result_Timer[2];
extern s16 scrl;
extern s16 scrr;
extern u16 vital_stop_flag[2];
extern u16 gauge_stop_flag[2];
extern s16 Lamp_Timer;
extern s16 Cont_Timer;
extern u16* Demo_Ptr[2];
extern s16 Plate_X[2][3];
extern s16 Plate_Y[2][3];
extern u16 Demo_Timer[2];
extern u16 Condense_Buff[2];
extern u16 Keep_Grade[2];
extern u16 IO_Result;
extern u16 VS_Win_Record[2];
extern u16 plsw_00[2];
extern u16 plsw_01[2];
extern s16 Flash_Synchro;
extern s16 Synchro_Level;
extern s16 Random_ix16_com;
extern s16 Random_ix32_com;
extern s16 Random_ix16_ex_com;
extern s16 Random_ix32_ex_com;
extern s16 Random_ix16_bg;
extern s16 Opening_Now;

#endif
