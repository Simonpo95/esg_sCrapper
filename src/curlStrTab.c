#include "curlStrTab.h"

char *url_to_filable(char *url, char *principal_directory_path)
{

    char *dada_str = "dada";

    char *file_name = calloc((strlen(url)) + 100, sizeof(char));
    char *copy_url = calloc(strlen(url) + 5, sizeof(char));
    char *result;

    char *extension = calloc(50, sizeof(char));

    result = typecheck(url);
    fprintf(stderr, "type check = a%sa\n", result);
    if (result == NULL)
    {
        result = "dada";
    }
    fprintf(stderr, "%s\n", result);
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

    strcpy(copy_url, url);

    int y = 0;
    while (copy_url[y] != 0)
    {
        if (copy_url[y] == 34 || copy_url[y] == 38 || copy_url[y] == 47 ||
            copy_url[y] == 58 || copy_url[y] == 60 || copy_url[y] == 62 ||
            copy_url[y] == 63 || copy_url[y] == 92 || copy_url[y] == 124)
        {
            copy_url[y] = 45;
        }
        y++;
    }

    fprintf(stderr, " copyurl : extension : %s %s\n", copy_url, extension);

    sprintf(file_name, "%s%s", copy_url, extension);

    return file_name;
}

StrTab *curlStrTab(StrTab *url_strTab, char *directory_name)
{

    StrTab *filename_strTab = create_StrTab(url_strTab->size);

    char *principal_directory_path = calloc(400, sizeof(char));

    sprintf(principal_directory_path, "%s%s/", "../web_site/", directory_name);

    for (int i = 0; i < url_strTab->size; i++)
    {
        char *file_name_from_url = url_to_filable(url_strTab->content_tab[i], principal_directory_path); // retourne le nom du fichier correspondant a un url

        fprintf(stderr, "directory path :%s\n", principal_directory_path);

        char *principal_directory_path_with_file_name = calloc(sizeof(char) * (strlen(file_name_from_url) + strlen(principal_directory_path)), sizeof(char)); // creation d'un char pour nom fichier ou dossier

        sprintf(principal_directory_path_with_file_name, "%s%s", principal_directory_path, file_name_from_url);
        if (strlen(principal_directory_path_with_file_name) > 253)
        {
            principal_directory_path_with_file_name[253] = '\0';
        }

        if (!(addToStrTab(filename_strTab, file_name_from_url)))
        {
            fprintf(stderr, "filename = %s\n", file_name_from_url);
            fprintf(stderr, "path = %s\n", principal_directory_path_with_file_name);
            fprintf(stderr, "url = %s\n\n", url_strTab->content_tab[i]);
            curlit(principal_directory_path_with_file_name, url_strTab->content_tab[i]);
            fprintf(stderr, "\ncoucou\n");
        }
    }

    free(principal_directory_path);
    return filename_strTab;
}
