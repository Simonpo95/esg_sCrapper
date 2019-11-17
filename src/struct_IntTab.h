#ifndef INTTAB
#define INTTAB

#include "supervisor.h"

struct IntTab {
    IntWTagType *content_tab;
    int size;
    int capacity;
};

IntTab *create_IntTab(IntWTagType *);

void printTabIntTab(IntTab *);

void printIntTab(IntTab);

void addToIntTab(IntTab *, IntWTagType *);

#endif