#include <stdio.h>
#include <string.h>
#include <curl/curl.h>
#include <stdlib.h>
#include <math.h>

#include "struct_tag.c"
#include "file_parser.c"

//int seek_start_Tag();

int main(int argc, char ** argv){

    Tag tabTag[2];

    Tag* link = create_Tag("<a", "</a>");
    Tag* pict = create_Tag("<img", ">");

    tabTag[0] = *link;
    tabTag[1] = *pict;

//    printTabTag(tabTag);

    int* pr = seek_start_Tag(tabTag, "file_content.txt");
    int i = 0;
    while(i < 10)
    {
        int p = pr[i];
        printf("%d \n", p);
        i++;
    }

    return 0;
}