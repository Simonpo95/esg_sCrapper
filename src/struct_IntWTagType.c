#include "struct_IntWTagType.h"


IntWTagType *create_IntWTagType(int cursor, struct Tag tag) {
    IntWTagType *intWTagType = (IntWTagType *) malloc(sizeof(IntWTagType));
    intWTagType->cursor = cursor;
    intWTagType->tag = tag;
    return intWTagType;
}

void printIntWTagType(IntWTagType intWTagType) {
    printf("%d\n", intWTagType.cursor);
    printTag(intWTagType.tag);
    printf("fin printf IntWTagType\n");
}