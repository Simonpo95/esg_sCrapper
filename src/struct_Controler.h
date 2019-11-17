#ifndef STRUCT_CONTROLER
#define STRUCT_CONTROLER

#include "supervisor.h"

struct Controler {
    TabStrTab* strTab_controler;
    int generation;
    int size;
    int capacity;
};

Controler *create_Controler(StrTab * strTab_controler);

void printControler(Controler controler);


#endif