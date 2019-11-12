#ifndef TAGTAB
#define TAGTAB

struct TagTab {
    Tag *content_tab;
    int size;
    int capacity;
};

TagTab *create_TagTab(Tag *);

void prIntTagTab(TagTab);

void addToTagTab(TagTab *, Tag *);

#endif
