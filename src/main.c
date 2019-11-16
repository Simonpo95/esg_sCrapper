#include "./supervisor.h"

int main(int argc, char **argv)
{

//////    curler part
//    int error = curlit("file/test_curler.txt", "http://alexandre-mesle.com/");
//////    curler part
//
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
//
//    printf("last_curl = %d\n",url_tab->last_curl);

//
//    if (stat("some/directory", &st) == -1) {
//        printf("ok pour mkdir\n");
//        mkdir("some", 0777);
//    } else{
//        printf("non pour mkdir\n");
//    }

//    char * chaine = "some/directory";


//    sprintf(final_path, "file/site_files/%s%s", cpy_destination, extension );


//    scutted *scu = string_cutter(tge, "some/directory", "/");
//
//    printf("%s\n",scu->strings[1]);

//    if(stat(chaine, &st) == -1)
//    {
//        scutted *scu = string_cutter(ptr, "some/directory", "/");
//        for(int i = 0; i < scu->size; i++)
//        {
//            printf("ok pour mkdir\n");
//            printf("mkdir de = %s\n", scu->strings[i]);
//            mkdir(scu->strings[i], 0777);
//        }
//    }

//    if(stat(base_path, &sb) == -1)
//    {
//        mkdir(base_path, 0777);
//    }


    return 0;
}