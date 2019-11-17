#include "struct_Controler.h"

Controler *create_Controler(int max_generation, char* first_url) {
    struct Controler *controler = (struct Controler *) malloc(sizeof(struct Controler));
    controler->generation = 0;
    controler->max_generation = max_generation;

    StrTab ** url_strTab_controler = (StrTab**) malloc(sizeof(StrTab*) * controler->max_generation);
    StrTab * first_gen_url_strTab = create_StrTab(12);
    addToStrTab(first_gen_url_strTab, first_url);
//    printStrTab(*first_gen_url_strTab);
    url_strTab_controler[0] = first_gen_url_strTab; // peut etre remplacer 0 par generation ?
    controler->url_strTab_controler = url_strTab_controler;

//    curlStrTab = controler->url_strTab_controler



    StrTab ** file_name_strTab_controler = (StrTab**) malloc(sizeof(StrTab*) * controler->max_generation);
//    StrTab * first_gen_filename_strTab = create_StrTab(0);

//    StrTab * first_gen_filename_strTab = curlStrTab(controler->url_strTab_controler[0]);
//    file_name_strTab_controler[0] = first_gen_filename_strTab;

    controler->file_name_strTab_controler = file_name_strTab_controler;
    return controler;
}

void printControler(Controler controler){
    printf("\n");
    for (int i = 0; i <= controler.generation; i++) {
//        for(int j = 0; j < controler.url_strTab_controler[i]->size; j++)
//        {
//            fprintf(stderr,"i = %d - j = %d -- printof url tab\n",i,j);
//            printStrTab(controler.url_strTab_controler[j][0]);
//        }
//        for(int j = 0; j < controler.file_name_strTab_controler[i]->size; j++)
//        {
//            fprintf(stderr,"i = %d - j = %d -- printof filename tab \n",i,j);
//            printStrTab(controler.file_name_strTab_controler[j][0]);
//        }

            fprintf(stderr,"i = %d -- printof url tab\n",i);
            printStrTab(controler.url_strTab_controler[i][0]);

            fprintf(stderr,"i = %d -- printof filename tab \n",i);
            printStrTab(controler.file_name_strTab_controler[i][0]);

    }
    printf("\nfin printf Controler\n");
}