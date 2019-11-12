#ifndef TAG
#define TAG

#include "supervisor.h"

struct Tag {
    char *start;
    char *end;
};

Tag *create_Tag(char *, char *);

void printTag(Tag);

void printTabTag(Tag *);

#endif