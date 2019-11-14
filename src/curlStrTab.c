#include "curlStrTab.h"

void curlStrTab(struct StrTab * strTab)
{
    for(int i = 0; i < strTab->size; i++)
    {
        char* final_path = malloc(sizeof(char) * 245); // creation d'un char pour nom fichier ou dossier
        char* cpy_destination = malloc(sizeof(char) * 245); // creation d'un char pour copier d->content_tab[i]

        strcpy(cpy_destination, strTab->content_tab[i]);

        int y = 0;
        while(cpy_destination[y] != 0) {
            if (cpy_destination[y] == 34 || cpy_destination[y] == 38 || cpy_destination[y] == 47 ||
                cpy_destination[y] == 58 || cpy_destination[y] == 60 || cpy_destination[y] == 62 ||
                cpy_destination[y] == 63 || cpy_destination[y] == 92 || cpy_destination[y] == 124) {
                cpy_destination[y] = 45;
            }
            y++;
        }

        char* extension  = ".txt";
        sprintf(final_path, "file/site_files/%s%s", cpy_destination, extension );

        curlit(final_path, strTab->content_tab[i]);

        printf("%d -/- %s\n", i, final_path);
        printf(" ---\n");
    }
}