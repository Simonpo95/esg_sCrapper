#ifndef TASKPARSER
#define TASKPARSER

#include "./supervisor.h"

void add_parameter_to_action(action * action, scutted * scut, int isProperty);
int fill_actions(param_container  * params);
int get_file_char_amount(FILE * f);
void fetch_action_parameters(param_container * params, FILE *f, char *line, size_t line_len);
char * parsed_line(char * line);
void fetch_task();
void fill_action_option(action * act, FILE * f, char * line, size_t line_len);
void fill_action_with_line_parameter(char *line, action *action, int isProperties);
void fill_task_with_line_parameter(char * string, task * ta);
void add_parameter_to_task(task *ta, scutted *scut);

void fill_task_option(task *ta, FILE *f, char *line, size_t line_len);
void fill_task_with_line_option(char *string, task *ta);
void add_option_to_task(scutted *scut, task *ta);

#endif