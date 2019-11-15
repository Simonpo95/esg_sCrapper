#ifndef TALKER
#define TALKER

#include "supervisor.h"

void smash_hand();
void inform_user_about_loaded_params(param_container *params);
void parsed_conf_file_successful(int error);
void ask_user_if_needed_details(param_container *params);
int check_answer(char * answer);
int interprete_answer(char * answer);
int ask_launch_tasks(param_container * params);
int get_user_proper_answer(char * question);
void ask_user_if_needed_bug_reported(param_container *params);
#endif