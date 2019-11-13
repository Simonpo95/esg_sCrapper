#ifndef INTTAB
#define INTTAB

#include "supervisor.h"

struct IntTab {
    IntWTagType *content_tab;
    int size;
    int capacity;
};

IntTab *create_IntTab(IntWTagType *);

void prIntTabIntTab(IntTab *);

void addToIntTab(IntTab *, IntWTagType *);

#endif