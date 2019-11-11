#ifndef SUPERVISOR

#define SUPERVISOR

#include <stdio.h>
#include <string.h>
#include <curl/curl.h>
#include <stdlib.h>
#include <math.h>

typedef struct KeyValue keyvalue;

struct KeyValue{
    char * property_name;
    char * property_value;
};

typedef struct Action action;
struct Action{
    int properties_amount;
    keyvalue ** properties;
    int option_amount;
    keyvalue ** options;
};

typedef struct Task task;

struct Task{
    int keys_amount;
    char ** keys;
    char ** values;
    int action_amount;
    char ** actions_name;
};

typedef struct Param_container param_container;

struct Param_container {
    int action_amount;
    action ** actions;
    int task_amount;
    task ** tasks;
};

#include "curler.h"
#include "generic_parser.h"
#include "generic_string_parser.h"
#include "generic_file_parser.h"
#include "struct_tag.h"
#include "task_parser.h"
#include "string_helper.h"
#include "error_file.h"


#endif