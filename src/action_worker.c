#include "action_worker.h"

void action_work(char *initial_url, int max_depth, char * directory_name)
{
    char * principal_directory_path = calloc(strlen(DIR_ROOT) + strlen(directory_name) + 5, sizeof(char));

    strcpy(principal_directory_path, DIR_ROOT);

    make_director(principal_directory_path);

    sprintf(principal_directory_path, "%s%s/", principal_directory_path, directory_name);

    make_director(principal_directory_path);



    ////    start part

    char *first_url = initial_url;
    int max_generation = max_depth;

    Controler *controler = create_Controler(max_generation, first_url);
    StrTab * Url_Banned_List = create_StrTab(1);
    addToStrTab(Url_Banned_List, first_url); // va contenir tous les urls qui on été déja curlé

    Tag *href = create_Tag("href=\"", "\"");

    Tag *tab_of_tag;
    TagTab *tagTab = create_TagTab(tab_of_tag);

    addToTagTab(tagTab, href);

    ////    start part

    for (int i = 0; i < controler->max_generation; i++)
    {
        printf("\n\n controler n°%d \n\n", i);
//        printStrTab(*(controler->url_strTab_controler[i]));

        printf("\n\n ---- avant phase de curl \n\n");

        StrTab *new_file_name_tab = curlStrTab(controler->url_strTab_controler[i], directory_name);
        printf("--- print de new_file_name_tab\n");
        printStrTab(*new_file_name_tab);

        printf("\n\n ---- après phase de curl \n\n");

        printf("\n\n ---- avant ajout des file name dans le controler \n\n");

        controler->file_name_strTab_controler[i] = new_file_name_tab;
        printf("--- print de controler->file_name_strTab_controler[i]\n");
        printStrTab(*(controler->file_name_strTab_controler[i]));
        printf("\n\n ---- après ajout des file name dans le controler \n\n");

        if (i + 1 < controler->max_generation)
        {
            printf("\n ---- i = %d\n",i);

            printf("\n ---- create de next_generation_url_tab \n");
            StrTab *next_generation_url_tab = create_StrTab(700);

            printf("\n\n ---- avant boucle pour chaque ajout des file name dans le controler \n\n");

            for (int j = 0; j < controler->file_name_strTab_controler[i]->size; j++)
            {
                printf("\n ---- i = %d - j = %d\n",i,j);

                printf("\n ---- avant seek_start_Tag d'un file name du file_name_strTab_controler\n");
                IntTab *cursor_tab = seek_start_Tag(tagTab, controler->file_name_strTab_controler[i]->content_tab[j]);
                printf("\n ---- après seek_start_Tag d'un file name du file_name_strTab_controler\n");
                if (cursor_tab != NULL)
                {
                    printf("\n ---- avant write_till_end d'un file name du file_name_strTab_controler\n");
                    StrTab *url_tab = write_till_end(cursor_tab, controler->file_name_strTab_controler[i]->content_tab[j]);
                    printf("--- print de url_tab\n");
                    printStrTab(*url_tab);
                    printf("\n ---- après write_till_end d'un file name du file_name_strTab_controler\n");

                    printf("\n ---- avant boucle pour chaque url trouver dans le file name \n");
                    for (int k = 0; k < url_tab->size; k++)
                    {
                        printf("\n ---- i = %d - j = %d - k = %d\n",i,j,k);

                        printf("\n ---- avant test url_banned_list \n");
                        if(!(addToStrTab(Url_Banned_List, url_tab->content_tab[k])))
                        {
                            printf("\n ---- avant ajout d'un des url dans next_generation_url_tab \n");
                            addToStrTab(next_generation_url_tab, url_tab->content_tab[k]);
                            printf("\n ---- après ajout d'un des url dans next_generation_url_tab \n");
                        }
                    }
                    printf("--- print de next_generation_url_tab\n");
                    printStrTab(*next_generation_url_tab);
                    printf("\n ---- après boucle pour chaque url trouver dans le file name \n");
                }
            }
            printf("\n\n ---- après boucle pour chaque ajout des file name dans le controler \n\n");
            printf("\n\n ---- avant ajout de next_generation_url_tab dans controler->url_strTab_controler[i + 1]\n\n");
            controler->url_strTab_controler[i + 1] = next_generation_url_tab;
            printf("--- print de controler->url_strTab_controler[i + 1]\n");
            printStrTab(*(controler->url_strTab_controler[i + 1]));
            printf("\n\n ---- après ajout de next_generation_url_tab dans controler->url_strTab_controler[i + 1]\n\n");
        }
        else
        {
            continue;
        }
    }
}