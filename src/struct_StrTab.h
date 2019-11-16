#ifndef STRTAB
#define STRTAB

#include "supervisor.h"

struct StrTab {
    char **content_tab;
    int size;
    int capacity;
    int last_curl;
};

void printTabStrTab(StrTab *);

StrTab *create_StrTab(char **);

void printStrTab(StrTab);

int addToStrTab(StrTab *, char *);

#endif