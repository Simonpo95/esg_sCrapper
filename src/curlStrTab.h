#ifndef CURLSTRTAB
#define CURLSTRTAB

#include "supervisor.h"

//char** url_to_filable(char * url);
char* url_to_filable(char * url, char * principal_directory_path);

StrTab *curlStrTab(StrTab *url_strTab, char *principal_directory_path);
//StrTab* curlStrTab(StrTab * url_strTab, char * principal_directory_path);

#endif