#include "struct_StrTab.h"

//separation

StrTab *create_StrTab(char **content_tab) {
    struct StrTab *strTab = (struct StrTab *) malloc(sizeof(struct StrTab));
    int capacity = 1;
    strTab->size = 0;
    strTab->capacity = capacity;
    strTab->content_tab = content_tab;
    return strTab;
}

void printStrTab(StrTab strTab) {
    printf("\n");
    for (int i = 0; i < strTab.size; i++) {
        printf("print of content_tab = %d \n content = %s\n", i, strTab.content_tab[i]);
        printf("\n");
    }
    printf("fin printf strTab\n");
    printf("\n");
}

void prIntTabStrTab(StrTab *tabstrTab) {
    int i = 0;
    for (i; i < 2; i++) {
//        printStrTab(tabstrTab[i]);
        printf("%d\n", tabstrTab->size);
    }
}

void addToStrTab(StrTab *strTab, char *string) {
    strTab->content_tab[strTab->size] = string;
    //    printf("ité = %d - content = %s | act size = %d | capa = %d\n",strTab->size, strTab->content_tab[strTab->size], strTab->size, strTab->capacity);
    strTab->size++;
    if (strTab->size >= strTab->capacity) {
        strTab->capacity *= 2;
    }
    printf("-- fin add in StrTab\n\n");
}