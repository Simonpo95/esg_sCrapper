#ifndef CURLER
#define CURLER

#include "supervisor.h"


int curlit(char * filepath, char * url);
size_t write_data(void *ptr, size_t size, size_t nmemb, FILE *stream);
char * typecheck(char * url);
#endif