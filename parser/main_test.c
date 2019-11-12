#include "supervisor.h"

int main(int argc, char **argv) {

    Tag* tab_of_tag;
    TagTab *tagTab = create_TagTab(tab_of_tag);

    Tag *link = create_Tag("<a", "</a>");
    Tag *pict = create_Tag("<img", ">");
    Tag *test = create_Tag("Lorem", "dolor");

    addToTagTab(tagTab, link);
    addToTagTab(tagTab, pict);
    addToTagTab(tagTab, test);

//    prIntTagTab(*tagTab);

    IntTab *pr = seek_start_Tag(tagTab, "file_content.txt");

//    printIntTab(*pr);

    StrTab *d = write_till_end(pr, tagTab, "file_content.txt");
//    printStrTab(*d);

}