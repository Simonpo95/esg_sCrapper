#ifndef SUP
#define SUP

#include <stdio.h>
#include <string.h>
#include <curl/curl.h>
#include <stdlib.h>
#include <math.h>

typedef struct Tag Tag;

typedef struct TagTab TagTab;

typedef struct IntTab IntTab;

typedef struct StrTab StrTab;

#include "struct_Tag.c"
#include "struct_TagTab.c"
#include "struct_IntTab.c"
#include "struct_StrTab.c"
#include "file_parser.c"


#endif