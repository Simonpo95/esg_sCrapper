#include "struct_ContentType.h"

char *content_type;
char *extension;

ContentType *create_ContentType(char *content_type, char *extension) {
    struct ContentType *contentType = (struct ContentType *) malloc(sizeof(struct ContentType));
    contentType->content_type = content_type;
    contentType->extension = extension;
    return contentType;
}

void printContentType(ContentType contentType) {
    printf("%s | %s\n", contentType.content_type, contentType.extension);
    printf("fin printf ContentType\n");

}