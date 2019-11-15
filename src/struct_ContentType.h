#ifndef CONTENTTYPE
#define CONTENTTYPE

#include "supervisor.h"

struct ContentType {
    char *content_type;
    char *extension;
};

ContentType *create_ContentType(char *, char *);

#endif
