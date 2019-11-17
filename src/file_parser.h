#ifndef FILEPARSER
#define FILEPARSER

#include "supervisor.h"

int is_inside(char *, StrTab *);

IntTab *seek_start_Tag(TagTab *, char *);

StrTab *write_till_end(IntTab *, char *);
char *get_extension(char *file_name);

#endif