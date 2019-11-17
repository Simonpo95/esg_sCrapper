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

//    printf("path = %s\n", path);
//    printf("base = %s\n", base_path);
//    printf("final = %s\n", a_path);

    scutted *scu = string_cutter(ptr_int, a_path, "/");
//    printf("final 2 = %s\n", a_path);

    for(int nb_path = 1; nb_path <= scu->size; nb_path++)
    {
//        printf("scu num %d = %s\n",nb_path, scu->strings[nb_path-1]);
        char* temp_path = calloc(sizeof(char) * 2045, sizeof(char));
//        printf("temp path calloc = %s\n", temp_path);
        for(int i = 0; i < nb_path; i++)
        {
//            printf("%d - %s\n", i, scu->strings[i]);
//            printf("temp path avant = %s\n", temp_path);
            sprintf(temp_path, "%s%s/", temp_path, scu->strings[i]);
//            printf("temp path apres = %s\n", temp_path);
        }

        if((stat(temp_path, &sb) == -1) && (strcmp(temp_path, "../") != 0))
        {
//            printf("nb_p = %d string = %s\n", nb_path, temp_path);
            mkdir(temp_path, 0777);
//            printf("yes \n");
        }
//        printf("\n");
//        printf("temp path 1 = %s\n", temp_path);
//        printf("final path 1 = %s\n", final_path);

        if(nb_path == scu->size)
        {
//            printf("temp path 1 = %s\n", temp_path);
//            printf("final path 1 = %s\n", final_path);
            strcpy(final_path, temp_path);
//            printf("temp path 2 = %s\n", temp_path);
//            printf("final path 2 = %s\n", final_path);
        }

        free(temp_path);
    }
    return final_path;
}