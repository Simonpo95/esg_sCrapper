#ifndef STRINGHELPER
#define STRINGHELPER

#include "supervisor.h"

typedef struct String_cutted scutted;

struct String_cutted{
    int size;
    char ** strings;
};

char * special_character_remover(char * string);
int is_it(char * characters_list, int list_size, char character_checked);
int check_first_last_character(char first, char last, char * string);
char * trim_before_after(char * string);
char * trim_before(char * string);
char * trim_after(char * string);
scutted * string_cutter(int * error, char * string, char * cutter);
int is_not_cutter(char * string, char * cutter);
void add_to_scutted(char * string, scutted * scut);
void read_scutted(scutted * scut);
#endif