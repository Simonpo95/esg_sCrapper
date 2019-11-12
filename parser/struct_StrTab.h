#ifndef STRTAB
#define STRTAB


struct StrTab {
    char **content_tab;
    int size;
    int capacity;
};

void prIntTabStrTab(StrTab *);

StrTab *create_StrTab(char **);

void printStrTab(StrTab);

void addToStrTab(StrTab *, char *);

#endif