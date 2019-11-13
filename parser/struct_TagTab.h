#ifndef TAGTAB
#define TAGTAB

#include "supervisor.h"

struct TagTab {
    Tag *content_tab;
    int size;
    int capacity;
};

TagTab *create_TagTab(Tag *);

void prIntTagTab(TagTab);

void addToTagTab(TagTab *, Tag *);

#endif
