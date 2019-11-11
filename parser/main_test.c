#include "supervisor.h"

int main(int argc, char **argv)
{

    //    char **str_tab = malloc(sizeof(char *) * 100);
    //
    //    for (int o = 0; o > 100; o++) {
    //        str_tab[o] = malloc(sizeof(char *) * 100);
    //    }
    //
    //    StrTab* strTab = create_StrTab(str_tab);
    //    for(int i = 0; i < 42; i++)
    //    {
    //        addToStrTab(strTab, "test");
    //    }

    //    printStrTab(*strTab);

    Tag tabTag[2];
    //    IntTab tabIntTab[2];

    Tag *link = create_Tag("<a", "</a>");
    Tag *pict = create_Tag("<img", ">");

    tabTag[0] = *link;
    tabTag[1] = *pict;
//
////    printTabTag(tabTag);
//
    IntTab* pr = seek_start_Tag(tabTag, "file_content.txt");
//    IntTab* pr = seek_start_Tag(tabTag, "test_file.txt");
//    int i = 0;
//
////    IntTab* tab1 = create_IntTab(pr);
////    IntTab* tab2 = create_IntTab(pr);
//
//    tabIntTab[0] = *pr;
//    tabIntTab[1] = *pr;
//    char** hello = malloc(sizeof(char*)*1000);
////    prIntTabIntTab(tabIntTab);
//
    StrTab* d = write_till_end(pr, tabTag,"file_content.txt");
//    printf("\n\n\n\n");
    printStrTab(*d);


//    int y = 0;
//    while(y<10)
//    {
//        char* ph = d.content_tab[y];
//        printf("%s\n", ph);
//        y++;
//    }


//    while(i < 11)
//    {
//        int p = pr[i];
//        printf("%d \n", p);
//        i++;
//    }

}