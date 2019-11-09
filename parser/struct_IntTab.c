#include <stdio.h>
#include <string.h>
#include <curl/curl.h>
#include <stdlib.h>
#include <math.h>

struct IntTab{
    int* content_tab;
    int size;
};

typedef struct IntTab IntTab;

//separation

IntTab* create_IntTab(int*);
//void printIntTab(IntTab);
void prIntTabIntTab(IntTab*);

//separation

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