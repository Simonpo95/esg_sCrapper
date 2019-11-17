#ifndef CURLSTRTAB
#define CURLSTRTAB

#include "supervisor.h"

char** url_to_filable(char* path, char * url);

StrTab* curlStrTab(StrTab * url_strTab);
//StrTab* curlStrTab(StrTab * url_strTab, char * source_filename);

#endif