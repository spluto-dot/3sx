#ifndef MAIN_H
#define MAIN_H

#include "types.h"

void cpInitTask();
void cpReadyTask(u16 num, void *func_adrs);
void cpExitTask(u16 num);

#endif
