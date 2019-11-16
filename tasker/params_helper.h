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
void report_errors(param_container *params);
void report_action_errors(action *act, int index);
void check_if_action_is_named(action *act, int index);
void report_tasks_errors(task *task, int index, action ** actions, int action_amount);
void check_action_parameter_validity(task *task, int index, action ** actions, int action_amount);
char *get_action_name(action *act);
#endif