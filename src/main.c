#include "./supervisor.h"

int main(int argc, char **argv)
{

////    curler part

//    char* dir_path = "../web_site/"

//    make_director("",dir_path);

//    if((stat(temp_path, &sb) == -1) && (strcmp(temp_path, "../") != 0))

//    int error = curlit("../web_site/test_curler.txt", "http://alexandre-mesle.com/");
////    curler part


////    start part

    char * first_url = "http://alexandre-mesle.com/";
    int max_generation = 5;

    Controler *controler = create_Controler(max_generation, first_url);

//    printControler(*controler);

////    start part

//
//
//    Tag *href = create_Tag("href=\"", "\"");
//
//    Tag* tab_of_tag;
//    TagTab *tagTab = create_TagTab(tab_of_tag);
//
//    addToTagTab(tagTab, href);
//
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
//    }

















//    char* url_to_dir(char * url)
//    {
//
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

    return 0;
}