#include "menu.h"
#include "main.h"
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

// const MenuFunc Menu_Jmp_Tbl[14] = { After_Title,    In_Game,         Wait_Load_Save,   Wait_Replay_Check,
//                                     Disp_Auto_Save, Suspend_Menu,    Wait_Replay_Load, Training_Menu,
//                                     After_Replay,   Disp_Auto_Save2, Wait_Pause_in_Tr, Reset_Training,
//                                     Reset_Replay,   End_Replay_Menu };
