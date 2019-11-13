#ifndef TAG
#define TAG

#include "supervisor.h"

struct Tag {
    char *start;
    char *end;
};

struct IntWTagType {
    int cursor;
    Tag tag;
};

Tag *create_Tag(char *, char *);

void printTag(Tag);

void printTabTag(Tag *);

#endif