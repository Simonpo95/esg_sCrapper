#include "struct_IntTab.h"

IntTab *create_IntTab(IntWTagType * content_tab) {
    struct IntTab *intTab = (struct IntTab *) malloc(sizeof(struct IntTab));
    intTab->size = 0;
    intTab->capacity = 1;
    content_tab = (IntWTagType*) malloc(sizeof(IntWTagType) * intTab->capacity);
    intTab->content_tab = content_tab;
    return intTab;
}

void printIntTab(IntTab intTab) {
    printf("\n");
    for (int i = 0; i < intTab.size; i++) {
        printf("%d = ", i);
        printIntWTagType(intTab.content_tab[i]);
//        printf("print of content_tab = %d \n content = %d\n", i, intTab->content_tab[i]);
//        printf("\n");
    }
    printf("fin printf intTab\n");
    printf("\n");
}

//void printTabIntTab(IntTab *tabintTab) {
//    for (int i = 0; i < tabintTab->size; i++) {
//        printIntTab(tabintTab[i]);
////        printf("%d\n", tabintTab->size);
//    }
//}

void addToIntTab(IntTab *intTab, IntWTagType *intWTagType) {
    intTab->content_tab[intTab->size] = *intWTagType;
//    printf("ité = %d - content = %d\n",intTab->size, intTab->content_tab[intTab->size]);
    intTab->size++;
    if (intTab->size >= intTab->capacity) {
        intTab->capacity *= 2;
        intTab->content_tab = realloc(intTab->content_tab, sizeof(IntWTagType) * intTab->capacity);
    }
//    printf("-- fin add in IntTab\n\n");
}