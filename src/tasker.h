#ifndef TASKER
#define TASKER

#include "./supervisor.h"

void tasker_launcher(true_parameters *params);
void task_waiter(true_task *ttask);
void action_waiter(true_action * taction);
#endif