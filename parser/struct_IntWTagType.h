#ifndef INTWTAGTYPE
#define INTWTAGTYPE

#include "supervisor.h"

struct IntWTagType {
    int cursor;
    Tag tag;
};

IntWTagType *create_IntWTagType(int, Tag);

void printIntWTagType(IntWTagType);

//void printTabTag(IntWTagType *);

#endif
