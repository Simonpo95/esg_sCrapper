#ifndef TASKPARSER
#define TASKPARSER

#include "supervisor.h"

typedef struct Action action;
struct Action{
    char ** keys;
    char ** values;
    char ** properties_name;
    char ** properties_value;
};

typedef struct ConfigContainer config_container;
struct ConfigContainer{
    int actions_amount;
    action * actions;
};

int fill_actions();
int get_file_char_amount(FILE * f);
void fetch_action();
char * parsed_line(char * line);
#endif