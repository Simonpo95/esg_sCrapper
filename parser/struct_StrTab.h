#ifndef STRTAB
#define STRTAB


struct StrTab{
    char** content_tab;
    int size;
    int capacity;
};

typedef struct StrTab StrTab;

//separation

StrTab* create_StrTab(char** content_tab, int capacity);
void printStrTab(StrTab);
void addToStrTab(StrTab*, char*);

#endif