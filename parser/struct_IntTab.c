#include "struct_IntTab.h"



IntTab* create_IntTab(int* content_tab)
{
    struct IntTab* intTab = (struct IntTab*)malloc(sizeof(struct IntTab));
    intTab->content_tab = content_tab;
    intTab->size = 1;
    return intTab;
}

//void printIntTab(IntTab intTab){
//    printf("%s | %s\n", intTab.content_tab, intTab.size);
//}

void prIntTabIntTab(IntTab* tabintTab){
    int i = 0;
    for(i; i<2; i++)
    {
//        printIntTab(tabintTab[i]);
        printf("%d\n", tabintTab->size);
    }
}