#include "dir_maker.h"

char* make_director(char * path, char * root)
{
    char * base_path = root;
    int tge = 0;
    int *ptr_int = &tge;
    struct stat sb = {0};

    char* a_path = malloc(sizeof(char) * 245);
    char* final_path = malloc(sizeof(char) * 2100); // changer pour plus de profondeur

    sprintf(a_path, "%s%s", base_path, path);

    scutted *scu = string_cutter(ptr_int, a_path, "/");

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

        if(nb_path == scu->size)
        {
            strcpy(final_path, temp_path);
        }

        free(temp_path);
    }
    return final_path;
}