#ifndef STRUCT_TABSTRTAB
#define STRUCT_TABSTRTAB

#include "supervisor.h"

struct TabStrTab {
    StrTab *content_tab;
    int size;
    int capacity;
};

TabStrTab *create_TabStrTab(StrTab *);

void printTabStrTab(TabStrTab);

void addToTabStrTab(TabStrTab *, StrTab *);

#endif
