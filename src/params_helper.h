#ifndef PARAMSHELPER
#define PARAMSHELPER

#include "supervisor.h"

void print_action(action * act);
void add_action_to_params(param_container * params, action * act);
void print_full_params(param_container *params);
void print_task(task *ta);
void add_task_to_params(param_container *params, task *ta);
#endif