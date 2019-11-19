#include "struct_Tag.h"

Tag *create_Tag(char *stt, char *ed) {
    struct Tag *tag = (struct Tag *) malloc(sizeof(struct Tag));
    tag->start = stt;
    tag->end = ed;
    return tag;
}

void printTag(Tag tag) {
    printf("%s | %s\n", tag.start, tag.end);
    printf("fin printf Tag\n");

}