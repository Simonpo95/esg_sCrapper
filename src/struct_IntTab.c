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
    printf("fin printf intTab\n");
    printf("\n");
}
void addToIntTab(IntTab *intTab, IntWTagType *intWTagType) {
    intTab->content_tab[intTab->size] = *intWTagType;
    intTab->size++;
    if (intTab->size >= intTab->capacity) {
        intTab->capacity *= 2;
        intTab->content_tab = realloc(intTab->content_tab, sizeof(IntWTagType) * intTab->capacity);
    }
}