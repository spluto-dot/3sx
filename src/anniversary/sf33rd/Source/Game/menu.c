#include "common.h"
#include "sf33rd/Source/Game/menu.h"
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

const MenuFunc Menu_Jmp_Tbl[16] = { After_Title,    In_Game,         Wait_Load_Save,   Wait_Replay_Check,
                                    Disp_Auto_Save, Suspend_Menu,    Wait_Replay_Load, Training_Menu,
                                    After_Replay,   Disp_Auto_Save2, Wait_Pause_in_Tr, Reset_Training,
                                    Reset_Replay,   End_Replay_Menu, };

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", Menu_Task);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", Setup_Pad_or_Stick);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", After_Title);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", Menu_Init);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", Mode_Select);
// Mode_Select contains jtbl_literal_292_005225F0

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", literal_336_00522610);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", Setup_VS_Mode);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", Menu_in_Sub);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", toSelectGame);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", jmpRebootProgram);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", imgSelectGameButton);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", Training_Mode);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", Option_Select);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", System_Direction);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", System_Dir_Move_Sub);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", System_Dir_Move_Sub_LR);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", Direction_Menu);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", Dir_Move_Sub);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", Dir_Move_Sub2);

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
