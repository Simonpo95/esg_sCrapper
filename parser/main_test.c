#include <stdio.h>
#include <string.h>
#include <curl/curl.h>
#include <stdlib.h>
#include <math.h>

#include "struct_Tag.c"
#include "struct_Tab.c"
#include "file_parser.c"

//int seek_start_Tag();

int main(int argc, char ** argv){

    Tag tabTag[2];
    IntTab tabIntTab[2];

    Tag* link = create_Tag("<a", "</a>");
    Tag* pict = create_Tag("<img", ">");

    tabTag[0] = *link;
    tabTag[1] = *pict;

//    printTabTag(tabTag);

    IntTab* pr = seek_start_Tag(tabTag, "file_content.txt");
//    IntTab* pr = seek_start_Tag(tabTag, "test_file.txt");
    int i = 0;

//    IntTab* tab1 = create_IntTab(pr);
//    IntTab* tab2 = create_IntTab(pr);

    tabIntTab[0] = *pr;
    tabIntTab[1] = *pr;

    prIntTabIntTab(tabIntTab);

//    while(i < 11)
//    {
//        int p = pr[i];
//        printf("%d \n", p);
//        i++;
//    }

    return 0;
}