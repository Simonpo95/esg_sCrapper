#include "struct_StrTab.h"

//separation

StrTab *create_StrTab(int capacity) {
    struct StrTab *strTab = (struct StrTab *) malloc(sizeof(struct StrTab));
    strTab->size = 0;
    strTab->capacity = capacity;

    char **str_tab = (char**) malloc(sizeof(char *) * strTab->capacity);
    for (int o = 0; o < strTab->capacity; o++) {
        str_tab[o] = calloc(3000, sizeof(char));
    }

    strTab->content_tab = str_tab;
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

int addToStrTab(StrTab *strTab, char *string) {
    if(is_inside(string, strTab))
    {
        return 1;
    }
    else
    {
        strTab->content_tab[strTab->size] = string;

        printf("ité = %d - content = %s\n",strTab->size, strTab->content_tab[strTab->size]);

        strTab->size++;
        if (strTab->size >= strTab->capacity) {
            strTab->capacity *= 2;
            strTab->content_tab = realloc(strTab->content_tab, sizeof(char**) * strTab->capacity);
        }
        printf("-- fin add in StrTab\n");
        return 0;
    }
}