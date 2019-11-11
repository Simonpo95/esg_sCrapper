#include "struct_Tag.h"
//separation

//separation

Tag *create_Tag(char *stt, char *ed)
{
    struct Tag *tag = (struct Tag *)malloc(sizeof(struct Tag));
    tag->start = stt;
    tag->end = ed;
    return tag;
}

void printTag(Tag tag)
{
    printf("%s | %s\n", tag.start, tag.end);
}
void printTabTag(Tag *tabtag)
{
    int i = 0;
    for (i; i < 2; i++)
    {
        printTag(tabtag[i]);
    }
}