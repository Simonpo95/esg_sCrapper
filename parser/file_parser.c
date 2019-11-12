#include <stdio.h>
#include <string.h>
#include <curl/curl.h>
#include <stdlib.h>
#include <math.h>

IntTab *seek_start_Tag(TagTab *tabTag, char *file_name) {
    int cursor;
    int counter;
    int counter2 = 0;
    char letter;
    IntWTagType *tabCursor;

    IntTab *tab1 = create_IntTab(tabCursor);

    FILE *f = fopen(file_name, "r");
    letter = fgetc(f);

    while (letter != EOF) {
        int counter = 0;
        for (int j = 0; j < tabTag->size; j++) {
            while (letter == tabTag->content_tab[j].start[counter]) {
                if (counter == strlen(tabTag->content_tab[j].start) - 1) {
                    cursor = ftell(f) + 1;
                    IntWTagType *tagType = create_IntWTagType(cursor, tabTag->content_tab[j]);
//                    printf("cursor === %d\n", cursor);
                    addToIntTab(tab1, tagType);
                    counter2++;
                }
                counter++;
                letter = fgetc(f);
            }
        }
        letter = fgetc(f);
    }

    fclose(f);
    tab1->size = counter2;
    return tab1;
}

StrTab *write_till_end(IntTab *intTab, TagTab *tagTab, char *file_name) {
    FILE *f = fopen(file_name, "r");

    char **str_tab = malloc(sizeof(char *) * 100);
    for (int o = 0; o > 100; o++) {
        str_tab[o] = calloc(1000, 1);
    }
    StrTab *strTab = create_StrTab(str_tab);

    char letter;
    int counter;

    for (int i = 0; i < intTab->size; i++) {
        char *tag_content = malloc(sizeof(char *) * 1000);
        fseek(f, intTab->content_tab[i].cursor - 1, SEEK_SET);
        letter = fgetc(f);
        for (int j = 0; j < 1; j++) {
//            printf("j = %d\n", tagTab->size);
            int counter2 = 0;
            while (strTab->content_tab[i] != tag_content) {
                counter = 0;
                while (letter == tagTab->content_tab[j].end[counter]) {
                    if (counter == strlen(tagTab->content_tab[j].end) - 1) {
                        addToStrTab(strTab, tag_content);
//                        printf("%d content tab -- %s\n\n", i, strTab->content_tab[i]);
                        break;
                    }
                    tag_content[counter2] = letter;
                    counter2++;
                    counter++;
                    letter = fgetc(f);
                }
                tag_content[counter2] = letter;
                counter2++;
                letter = fgetc(f);
            }
        }
    }
    fclose(f);
    return strTab;
}