#ifndef RESET_H
#define RESET_H

#include "types.h"
#include "unknown.h"

extern u8 Reset_Status[2];

void Reset_Task(struct _TASK *task_ptr);
u8 nowSoftReset();

#endif
