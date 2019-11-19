#include "dir_maker.h"

void make_director( char * directory_name)
{
    int tge = 0;
    int *ptr_int = &tge;
    struct stat sb = {0};

    scutted *scu = string_cutter(ptr_int, directory_name, "/");

    for(int nb_path = 1; nb_path <= scu->size; nb_path++)
    {
        char* temp_path = calloc(sizeof(char) * 2045, sizeof(char));
        for(int i = 0; i < nb_path; i++)
        {
            sprintf(temp_path, "%s%s/", temp_path, scu->strings[i]);
        }

        if((stat(temp_path, &sb) == -1) && (strcmp(temp_path, "../") != 0))
        {
            mkdir(temp_path, 0777);
        }

        free(temp_path);
    }
}