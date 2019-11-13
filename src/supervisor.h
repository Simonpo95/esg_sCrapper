#ifndef SUPERVISOR

#define SUPERVISOR

#include <stdio.h>
#include <string.h>
#include <curl/curl.h>
#include <stdlib.h>
#include <math.h>

typedef struct StringCutted scutted;
typedef struct KeyValue keyvalue;
typedef struct Action action;
typedef struct Task task;
typedef struct Param_container param_container;


struct KeyValue{
    char * name;
    char * value;
};

struct Action{
    int properties_amount;
    keyvalue ** properties;
    int option_amount;
    keyvalue ** options;
};


struct Task{
    int properties_amount;
    keyvalue ** properties;
    int action_amount;
    char ** actions_name;
};


struct Param_container {
    int action_amount;
    action ** actions;
    int task_amount;
    task ** tasks;
};

typedef struct Tag Tag;

typedef struct TagTab TagTab;

typedef struct IntWTagType IntWTagType;

typedef struct IntTab IntTab;

typedef struct StrTab StrTab;

#include "struct_Tag.h"
#include "struct_TagTab.h"
#include "struct_IntTab.h"
#include "struct_StrTab.h"
#include "file_parser.h"
#include "struct_IntWTagType.h"

#include "params_helper.h"
#include "string_helper.h"
#include "curler.h"
#include "task_parser.h"
#include "error_file.h"


#endif