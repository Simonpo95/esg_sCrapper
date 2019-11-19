#include "./supervisor.h"

int main()
{
     char *principal_directory_path = calloc(sizeof(char) * strlen(DIR_ROOT), sizeof(char));

     strcpy(principal_directory_path, DIR_ROOT);
    // //
     char * url = "http://alexandre-mesle.com/";
    ////    char * url = "http://benoit-valle.fr/";
    ////    char * url = "http://mocodo.wingi.net/";
    ////    char * url = "http://www.lyc-ferry-conflans.ac-versailles.fr/";
    ////    char * principal_directory_path = "../web_site/test5/";
    // char *url = "http://www.makeplayingcards.com/";
     make_director(principal_directory_path);
    ////
    //
    //////// url type testing part
    //

        //  Tag *href = create_Tag("href=\"", "\"");

        //  Tag *tab_of_tag;
        //  TagTab *tagTab = create_TagTab(tab_of_tag);

        //  addToTagTab(tagTab, href);

        //  StrTab * test_strTab = create_StrTab(12);

        //  addToStrTab(test_strTab, "http://alexandre-mesle.com/index.php/conneries/kaamelott/");
        //  addToStrTab(test_strTab, "http://alexandre-mesle.com/index.php/conneries/");
        //  addToStrTab(test_strTab, "http://instagram.com/embed/");
        //  addToStrTab(test_strTab, "http://www.makeplayingcards.com/environmentally-friendly.aspx");

        //  printStrTab(*test_strTab);

        //  StrTab * file_name_srtTab = curlStrTab(test_strTab);

        //  printStrTab(*file_name_srtTab);

        //  for (int i = 0; i < file_name_srtTab->size; ++i) {
        //      IntTab *cursor_tab = seek_start_Tag(tagTab, file_name_srtTab->content_tab[i]);

        //      if (cursor_tab != NULL)
        //      {
        //          StrTab *url_tab = write_till_end(cursor_tab, file_name_srtTab->content_tab[i]);
        //          printf("i = %d",i);
        //          printStrTab(*url_tab);
        //      }
        //  }

    // //
    // //////// url type testing part
    //
    action_work(url, 5, hello); ////pour lancer le programme
                         //
                         //
                         //
                         ////    action_work(url, 5, principal_directory_path);
                         //
                         ////    char ** ok = url_to_filable(url);
                         ////    char * ok = url_to_filable(url);
                         //
                         ////    printf(" 0 %s\n", ok[0]);
                         ////    printf(" 1 %s\n", ok[1]);

    //    char * path = make_director( principal_directory_path, "test2");

    //interface utilisateur pour charger un fichier selon le choix du user

       char *file_name = get_scrapper_configuration_file();

       param_container *params = create_empty_params();
       int error = fill_actions(params, file_name);
       parsed_conf_file_successful(error);
       if (!error)
       {
           inform_user_about_loaded_params(params);
           ask_user_if_needed_details(params);
           ask_user_if_needed_bug_reported(params);
           int answer = ask_launch_tasks(params);
           if (answer)
           {
               true_parameters *true_params = generate_true_params(params);
               tasker_launcher(true_params);
           }
           else
           {
               printf("Nous comprenons, merci d'avoir fait usage de notre service !\n");
           }
       }

    return 0;
}