#include "dir_maker.h"

void make_director(char * path)
{
    char * base_path = "../web_site/";
    int tge = 0;
    int *ptr_int = &tge;
    struct stat sb = {0};

    char* final_path = malloc(sizeof(char) * 245);
    char* chaine = path;

    sprintf(final_path, "%s%s", base_path, chaine);

    printf("final = %s\n", final_path);

    scutted *scu = string_cutter(ptr_int, final_path, "/");

    for(int i = 0; i < scu->size; i++)
    {
        printf("element %d de final_path = %s\n",i, scu->strings[i]);
    }

    for(int nb_path = 1; nb_path <= scu->size; nb_path++)
    {
        char* temp_path = malloc(sizeof(char) * 245);
        for(int i = 0; i < nb_path; i++)
        {
            sprintf(temp_path, "%s%s/", temp_path, scu->strings[i]);
        }

        if((stat(temp_path, &sb) == -1) && (strcmp(temp_path, "../") != 0))
        {
            printf("nb_p = %d string = %s\n", nb_path, temp_path);
            mkdir(temp_path, 0777);
            printf("yes \n");
        }
    }
}



