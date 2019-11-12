#ifndef INTTAB
#define INTTAB

#include "supervisor.h"

struct IntTab {
    int *content_tab;
    int size;
    int capacity;
};

IntTab *create_IntTab(int *);

void prIntTabIntTab(IntTab *);

void addToIntTab(IntTab *, int );

#endif