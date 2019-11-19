#include "curlStrTab.h"

char* url_to_filable(char * url)
{

    char *dada_str = "dada";

    char *final_path = calloc(sizeof(char) * (strlen(url)), sizeof(char));
    char *cpy_destination = calloc(sizeof(char) * (strlen(url)), sizeof(char));
    char *result = calloc(sizeof(char) * 200, sizeof(char));

    char *extension = calloc(sizeof(char) * 50, sizeof(char));

    result = typecheck(url);
    printf("type check = %s\n", result);
    result = remove_all_after_character(result, 59);
    printf("type check after remove = %s\n", result);

    if (strcmp(dada_str, result) == 0)
    {
        extension = ".txt";
    }
    else
    {
        extension = get_extensions_from_types(result);
    }

    strcpy(cpy_destination, url);

    int y = 0;
    while (cpy_destination[y] != 0)
    {
        if (cpy_destination[y] == 34 || cpy_destination[y] == 38 || cpy_destination[y] == 47 ||
            cpy_destination[y] == 58 || cpy_destination[y] == 60 || cpy_destination[y] == 62 ||
            cpy_destination[y] == 63 || cpy_destination[y] == 92 || cpy_destination[y] == 124)
        {
            cpy_destination[y] = 45;
        }
        y++;
    }

    sprintf(final_path, "%s%s", cpy_destination, extension);

    char **tab = calloc(sizeof(char *) * 2, sizeof(char *));
    for (int o = 0; o < 2; o++)
    {
        tab[o] = calloc(600, sizeof(char));
    }

    tab[1] = url;

    return final_path;
}


//StrTab *curlStrTab(StrTab *url_strTab, char *principal_directory_path)
StrTab *curlStrTab(StrTab *url_strTab)
{

    StrTab *filename_strTab = create_StrTab(url_strTab->size);

    for (int i = 0; i < url_strTab->size; i++)
    {
        char * file_name_from_url = url_to_filable(url_strTab->content_tab[i]); // retourne le nom du fichier correspondant a un url
        char * principal_directory_path = calloc(sizeof(char) * strlen(DIR_ROOT), sizeof(char));

        strcpy(principal_directory_path, DIR_ROOT);

        char *principal_directory_path_with_file_name = calloc(sizeof(char) * (strlen(file_name_from_url) + strlen(principal_directory_path)), sizeof(char));      // creation d'un char pour nom fichier ou dossier

        sprintf(principal_directory_path_with_file_name, "%s%s", principal_directory_path, file_name_from_url);

        if (!(addToStrTab(filename_strTab, file_name_from_url)))
        {
            fprintf(stderr, "path = %s\n",principal_directory_path_with_file_name);
            fprintf(stderr, "url = %s\n\n",url_strTab->content_tab[i]);
            curlit(principal_directory_path_with_file_name, url_strTab->content_tab[i]);
//            fprintf(stderr,"\n");
        }
    }

    return filename_strTab;
}
