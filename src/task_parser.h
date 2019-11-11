#ifndef TASKPARSER
#define TASKPARSER

#include "supervisor.h"


int fill_actions(param_container  * params);
int get_file_char_amount(FILE * f);
void fetch_action_parameters(param_container * params, FILE *f, char *line, size_t line_len);
char * parsed_line(char * line);
void fetch_task();
void fill_action_option();
void fill_action_with_line_parameter(char * line, action * action);
void add_parameter_to_action(action * action, scutted * scut, int isPoperty);

#endif