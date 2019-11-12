#include "struct_IntWTagType.h"


IntWTagType *create_IntWTagType(int cursor, Tag tag) {
    struct IntWTagType *intWTagType = (struct IntWTagType *) malloc(sizeof(struct IntWTagType));
    intWTagType->cursor = cursor;
    intWTagType->tag = tag;
    return intWTagType;
}

void printIntWTagType(IntWTagType intWTagType) {
    printf("%d\n", intWTagType.cursor);
    printTag(intWTagType.tag);
    printf("fin printf IntWTagType\n");
}
//
//void printTabTag(Tag *tabtag) {
//    int i = 0;
//    for (i; i < 2; i++) {
//        printTag(tabtag[i]);
//    }
//}