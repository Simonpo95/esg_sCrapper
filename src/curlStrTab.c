#include "curlStrTab.h"

char **url_to_filable(char *path, char *url)
{

    char *dada_str = "dada";

    char *final_path = calloc(sizeof(char) * (strlen(url)), sizeof(char));      // creation d'un char pour nom fichier ou dossier
    char *cpy_destination = calloc(sizeof(char) * (strlen(url)), sizeof(char)); // creation d'un char pour copier d->content_tab[i]
    char *result = calloc(sizeof(char) * 5000, sizeof(char));                   // creation d'un char pour get le type

    char *extension = calloc(sizeof(char) * 50, sizeof(char));

    result = typecheck(url);
    result = remove_all_after_character(result, 59);

    fprintf(stderr, "coca");
    if (strcmp(dada_str, result) == 0)
    {
        extension = ".txt";
    }
    else
    {
        fprintf(stderr, "coca1.5");
        extension = get_extensions_from_types(result);
        fprintf(stderr, "coca1.7");
    }

    fprintf(stderr, "coca2");
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

    fprintf(stderr, "coca3");

    sprintf(final_path, "%s%s", cpy_destination, extension);
    fprintf(stderr, "coca4");

    char **tab = calloc(sizeof(char *) * 2, sizeof(char *));
    for (int o = 0; o < 2; o++)
    {
        tab[o] = calloc(600, sizeof(char));
    }

    fprintf(stderr, "coca5");

    tab[0] = final_path;

    //    if(url[strlen(url) - 1] == '/')
    //    {
    //        printf("dernier = %c\n",url[strlen(url) - 1]);
    ////        url[strlen(url) - 1] = 'f'; // remove last char / to avoide double
    //        printf("dernier = %c\n",url[strlen(url) - 1]);
    //        tab[1] = url;
    //        return tab;
    //    }

    tab[1] = url;

    return tab;
}

StrTab *curlStrTab(StrTab *url_strTab, char *source_url)
{
    char *source_filename = url_to_filable("", source_url)[0];
    StrTab *filename_strTab = create_StrTab(url_strTab->size);

    //    char * path = make_director(source_filename, "../web_site/");
    char *path = make_director(source_filename, "../web_site/");

    char *null_str = "(null)";

    for (int i = 0; i < url_strTab->size; i++)
    {
        fprintf(stderr, "on retourne");
        char *root = malloc(sizeof(char) * 10000);
        strcpy(root, path);
        int inside = 0;
        fprintf(stderr, "on affecte");

        char *final_path = calloc(sizeof(char) * (strlen(url_strTab->content_tab[i])), sizeof(char));      // creation d'un char pour nom fichier ou dossier
        char *cpy_destination = calloc(sizeof(char) * (strlen(url_strTab->content_tab[i])), sizeof(char)); // creation d'un char pour copier d->content_tab[i]
        char *result = calloc(sizeof(char) * 5000, sizeof(char));                                          // creation d'un char pour get le type
        char *fp = calloc(sizeof(char) * 5000, sizeof(char));     

        fprintf(stderr, "on fillable");

        char **tab = url_to_filable(path, url_strTab->content_tab[i]);
        fprintf(stderr, "on regarde une valeur pétée");

        final_path = tab[0];


        fprintf(stderr, "on add");

        inside = addToStrTab(filename_strTab, final_path);

        sprintf(root, "%s%s", root, final_path);

        if (inside == 0)
        {
            fprintf(stderr, "before curl\n");
            fprintf(stderr, "root :%s content_tab : %s\n",root, url_strTab->content_tab[i]);
            curlit(root, url_strTab->content_tab[i]);
            fprintf(stderr, "after curl\n");
        }
    }

    fprintf(stderr, "out");

    return filename_strTab;
}