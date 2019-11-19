#include "action_worker.h"

void action_work(char *initial_url, int max_depth)
{

    char * principal_directory_path = calloc(sizeof(char) * strlen(DIR_ROOT), sizeof(char));

    strcpy(principal_directory_path, DIR_ROOT);

    ////    curler part

    //    char* dir_path = "../web_site/"

    //    make_director("",dir_path);

    //    if((stat(temp_path, &sb) == -1) && (strcmp(temp_path, "../") != 0))

    //    int error = curlit("../web_site/test_curler.txt", "http://alexandre-mesle.com/");
    ////    curler part

    ////    start part

    char *first_url = initial_url;
    int max_generation = max_depth;
    //    int max_generation = 5;
//    char *start_path = "../web_site/";

    Controler *controler = create_Controler(max_generation, first_url);
    StrTab * Url_Banned_List = create_StrTab(1);
    addToStrTab(Url_Banned_List, first_url); // va contenir tous les urls qui on été déja curlé
    ////    start part

    //
    //
    Tag *href = create_Tag("href=\"", "\"");

    Tag *tab_of_tag;
    TagTab *tagTab = create_TagTab(tab_of_tag);

    addToTagTab(tagTab, href);

    for (int i = 0; i < controler->max_generation; i++)
    {
        printf("\n\n controler n°%d \n\n", i);
//        printStrTab(*(controler->url_strTab_controler[i]));

        printf("\n\n ---- avant phase de curl \n\n");

        StrTab *new_file_name_tab = curlStrTab(controler->url_strTab_controler[i]);
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

    //    for(int i = 0, i < controler->max_generation; i++){
    //        for(int j = 0; j < urlTab[i]; j++){
    //
    //        }
    //    }
    //    for(int i = 0; i < controler->max_generation; i++)
    //    {
    //        for(int j = 0; j < controler->url_strTab_controler[i]->size; j++) // pour chaque url dans la url tab
    //        {
    //            char ** dual_url_filename = url_to_filable(start_path, controler->url_strTab_controler[i]->content_tab[j]); // recuperation du file_name du first url
    //
    ////            controler->file_name_strTab_controler[i] = create_StrTab(controler->url_strTab_controler[i]->size); // création du tab file_name, taille = url tab
    ////
    ////            addToStrTab(controler->file_name_strTab_controler[i] ,dual_url_filename[0]); // ajout du file name dans le tableau du controler
    //
    //            fprintf(stderr,"path = \n");
    //            StrTab * next_gen_file_name = curlStrTab(controler->url_strTab_controler[i], controler->file_name_strTab_controler[i]->content_tab[0]); // curl des url et recuperation des file name
    //
    //            controler->file_name_strTab_controler[i] = next_gen_file_name;
    //        }
    //
    //        if(i+1 > controler->max_generation)
    //        {
    //            StrTab * next_gen_url_tab = create_StrTab(controler->file_name_strTab_controler[i]->size);
    //            for (int z = 0; z < controler->file_name_strTab_controler[i]->size; ++z) {
    //                IntTab *cursor_tab = seek_start_Tag(tagTab, controler->file_name_strTab_controler[0]->content_tab[i]);
    //                StrTab *url_tab = write_till_end(cursor_tab, controler->file_name_strTab_controler[0]->content_tab[i]);
    //                for(int j = 0; j < url_tab->size; j++)
    //                {
    //                    addToStrTab(next_gen_url_tab, url_tab->content_tab[j]);
    //                }
    //            }
    //            controler->url_strTab_controler[i+1] = next_gen_url_tab;
    //            printStrTab(controler->url_strTab_controler[i+1][0]);
    //        }
    //        else
    //        {
    //            continue;
    //        }
    //
    //    }

    //    printStrTab(*(controler->url_strTab_controler[0]));

    //    printControler(*controler);

    //    controler->file_name_strTab_controler[i][j] = dual_url_filename[0];
    //
    //    for( tout les url )
    //    {
    //        curl de ( path , url);
    //        creation du fichier
    //    }
    //
    //    mettre le nom dans le tab file name de generation suivante

    //    for(int i = 0; i < controler->file_name_strTab_controler[0]->size; i++)
    //    {
    //        printf("i == %d\n", i);
    //        printf("char = %s\n",controler->file_name_strTab_controler[0]->content_tab[i]);
    //        IntTab *cursor_tab = seek_start_Tag(tagTab, controler->file_name_strTab_controler[0]->content_tab[i]);
    ////        printIntTab(*cursor_tab); // result check
    //        StrTab *url_tab = write_till_end(cursor_tab, controler->file_name_strTab_controler[0]->content_tab[i]);
    //        printStrTab(*url_tab);
    ////        StrTab * file_name = curlStrTab(url_tab, controler->file_name_strTab_controler[0]->content_tab[i]);
    //        StrTab * file_name = curlStrTab(url_tab);
    //        printStrTab(* file_name);
    //    }s

    //    char * str = "http://alexandre-mesle.com/";
    //
    //    char ** heo = url_to_filable("../web_site/", str);
    //
    //    for (int t = 0; t < 2; t++)
    //    {
    //        printf(" %s \n", heo[t]);
    //    }

    //////    needed to work
    //    char * file_name = "file/test_curler.txt";
    ////    char * file_name = "file/file_content.txt";
    ////    char * file_name = "file/test_file.txt";
    ////    char * file_name = "file/page_facebook.txt";
    //    Tag *href = create_Tag("href=\"", "\"");
    ////    Tag *src = create_Tag("src=\"", "\"");
    ////    Tag *link = create_Tag("<a", "</a>");
    ////    Tag *pict = create_Tag("<img", ">");
    //
    //    Tag* tab_of_tag;
    //    TagTab *tagTab = create_TagTab(tab_of_tag);
    //
    //    addToTagTab(tagTab, href);
    ////    addToTagTab(tagTab, src);
    ////    addToTagTab(tagTab, link);
    ////    addToTagTab(tagTab, pict);
    //
    //    IntTab *cursor_tab = seek_start_Tag(tagTab, file_name);
    ////    prIntTabIntTab(cursor_tab); // result check
    //    StrTab *url_tab = write_till_end(cursor_tab, file_name);
    //    printTabStrTab(url_tab); // result check
    ////////    needed to work

    //    curlStrTab(url_tab);
    //    printf("last_curl = %d\n",url_tab->last_curl);

    //    char* rouge = make_director("hello", "../web_site/");
    //
    //    char * tableau[] = {"hello", "bo", "coucou"};
    //    char * tableau1[] = {"hello", "bo", "cacaaa"};
    //
    //    printf("size of tab = %ld\n", sizeof(tableau) / 8);
    //    printf("size of tab = %ld\n", sizeof(tableau1) / 8);
}