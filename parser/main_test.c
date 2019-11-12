#include "supervisor.h"

int main(int argc, char **argv) {

    Tag *link = create_Tag("<a", "</a>");
    Tag *pict = create_Tag("<img", ">");
    Tag *href = create_Tag("href=\"", "\"");

    Tag* tab_of_tag;
    TagTab *tagTab = create_TagTab(tab_of_tag);

    addToTagTab(tagTab, link);
    addToTagTab(tagTab, pict);
    addToTagTab(tagTab, href);

//    for(int i = 0; i < 2002; i++)
//    {
//        addToTagTab(tagTab, href);
//        printf("size = %d\ncapacity = %d\n", tagTab->size, tagTab->capacity);
//    }

    IntTab *pr = seek_start_Tag(tagTab, "file_content.txt");

//    IntWTagType* allo = create_IntWTagType(12211, *test);
//    printIntWTagType(*allo);

//    addToTagTab(tagTab, link);
//    addToTagTab(tagTab, pict);

//    prIntTagTab(*tagTab);


//    printIntTab(*pr);

    StrTab *d = write_till_end(pr, tagTab, "file_content.txt");
    printStrTab(*d);

}