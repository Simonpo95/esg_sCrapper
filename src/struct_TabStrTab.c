#include "struct_TabStrTab.h"

TabStrTab *create_TabStrTab(StrTab * content_tab) {
    struct TabStrTab *tabStrTab = (struct TabStrTab *) malloc(sizeof(struct TabStrTab));
    int capacity = 1;
    tabStrTab->size = 0;
    tabStrTab->capacity = capacity;
    content_tab = (StrTab *) malloc(sizeof(StrTab) * capacity);
    tabStrTab->content_tab = content_tab;
    return tabStrTab;
}

void printTabStrTab(TabStrTab tabStrTab){
    printf("\n");
    for (int i = 0; i < tabStrTab.size; i++) {
        printf("%d - ",i);
        printStrTab(tabStrTab.content_tab[i]);
    }
    printf("\nfin printf TabStrTab\n");
}

void addToTabStrTab(TabStrTab *tabStrTab, StrTab *strTab) {
    tabStrTab->content_tab[tabStrTab->size] = *strTab;
    tabStrTab->size++;
    if (tabStrTab->size >= tabStrTab->capacity) {
        tabStrTab->capacity *= 2;
        tabStrTab->content_tab = realloc(tabStrTab->content_tab, sizeof(TabStrTab) * tabStrTab->capacity);
    }
    printf("\n-- fin add in TabStrTab\n");
}
