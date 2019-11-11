#ifndef STRINT
#define STRINT

#include "supervisor.h"

struct IntTab
{
    int *content_tab;
    int size;
};

IntTab *create_IntTab(int *);
void prIntTabIntTab(IntTab *);

#endif