#ifndef STRUCT_CONTROLER
#define STRUCT_CONTROLER

#include "supervisor.h"

struct Controler {
    StrTab** url_strTab_controler;
    StrTab** file_name_strTab_controler;
    int generation;
    int max_generation;
};

Controler *create_Controler(int max_generation, char* first_url);

void printControler(Controler controler);


#endif