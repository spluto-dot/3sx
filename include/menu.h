#ifndef MENU_H
#define MENU_H

#include "unknown.h"

void Menu_Task(struct _TASK *task_ptr);
void Menu_Init(struct _TASK *task_ptr);
void Setup_Pad_or_Stick();
u16 Check_Menu_Lever(u8 PL_id, s16 type);
void Menu_Common_Init();

#endif
