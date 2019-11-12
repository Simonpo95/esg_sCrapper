#ifndef TAG
#define TAG

#include "supervisor.h"

struct Tag {
    char *start;
    char *end;
};

typedef struct Tag Tag;

Tag *create_Tag(char *, char *);

void printTag(Tag);

void printTabTag(Tag *);

#endif