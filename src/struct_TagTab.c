#include "struct_TagTab.h"

TagTab *create_TagTab(Tag * content_tab) {
    struct TagTab *tagTab = (struct TagTab *) malloc(sizeof(struct TagTab));
    int capacity = 1;
    tagTab->size = 0;
    tagTab->capacity = capacity;
    content_tab = (Tag *) malloc(sizeof(Tag) * capacity);
    tagTab->content_tab = content_tab;
    return tagTab;
}

void printTagTab(TagTab tagTab){
    printf("\n");
    for (int i = 0; i < tagTab.size; i++) {
        printf("%d - ",i);
        printTag(tagTab.content_tab[i]);
    }
    printf("\nfin printf tagTab\n");
}

void addToTagTab(TagTab *tagTab, Tag *tag) {
    tagTab->content_tab[tagTab->size] = *tag;
    tagTab->size++;
    if (tagTab->size >= tagTab->capacity) {
        tagTab->capacity *= 2;
        tagTab->content_tab = realloc(tagTab->content_tab, sizeof(TagTab) * tagTab->capacity);
    }
    printf("\n-- fin add in TagTab\n");
}