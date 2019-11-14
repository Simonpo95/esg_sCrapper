#ifndef PARAMSHELPER
#define PARAMSHELPER

#include "supervisor.h"

void print_action(action * act);
void add_action_to_params(param_container * params, action * act);
void print_full_params(param_container *params);
void print_task(task *ta);
void add_task_to_params(param_container *params, task *ta);
param_container *create_empty_params();
task * create_empty_task();
action * create_empty_action();
void print_errors(param_container *params);
#endif