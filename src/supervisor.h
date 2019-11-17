#ifndef SUPERVISOR

#define SUPERVISOR

#include <stdio.h>
#include <string.h>
#include <curl/curl.h>
#include <stdlib.h>
#include <math.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/stat.h>
#include <dirent.h>
#include <sys/types.h>

typedef struct StringCutted scutted;
typedef struct KeyValue keyvalue;
typedef struct Action action;
typedef struct Task task;
typedef struct Param_container param_container;
typedef struct TrueTask true_task;
typedef struct TrueAction true_action;
typedef struct TrueParameters true_parameters;



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

struct TrueAction
{
    char *name;
    char *url;
    int maximum_depth;
    int versioning;
    int types_amount;
    char **types;
};

struct TrueTask
{
    char *name;
    long long respawn_time;
    int action_amount;
    true_action **actions;
};

struct TrueParameters
{
    long long timer;
    int task_amount;
    true_task **true_tasks;
};

typedef struct Tag Tag;

typedef struct TagTab TagTab;

typedef struct IntWTagType IntWTagType;

typedef struct IntTab IntTab;

typedef struct StrTab StrTab;

typedef struct TabStrTab TabStrTab;

typedef struct Controler Controler;

typedef struct ContentType ContentType;

#include "struct_Tag.h"
#include "struct_TagTab.h"
#include "struct_IntTab.h"
#include "struct_StrTab.h"
#include "file_parser.h"
#include "struct_IntWTagType.h"
#include "struct_ContentType.h"

#include "curlStrTab.h"
#include "struct_Controler.h"
#include "dir_maker.h"
#include "struct_TabStrTab.h"

#include "params_helper.h"
#include "string_helper.h"
#include "curler.h"
#include "task_parser.h"
#include "error_file.h"
#include "user_talker.h"
#include "tasker.h"

#endif