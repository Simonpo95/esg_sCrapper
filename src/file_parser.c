#include "file_parser.h"

IntTab *seek_start_Tag(TagTab *tabTag, char *file_name) {
    int cursor;
    int counter; // this counter will help us to track the start string
    char letter;
    IntWTagType *tabCursor; // creation of an IntTabType type array named tabCursor
    IntTab *intTab = create_IntTab(tabCursor); // creation of an IntTab type array named intTab that contain tabCursor

    FILE *f = fopen(file_name, "r"); // opening of a file using the string given by the second parameter of this function, in read mode
    letter = fgetc(f); // giving of the first character in the file to letter

    while (letter != EOF) { // browsing through untill the End Of File thanks to fgetc() function
        int counter = 0;
        for (int j = 0; j < tabTag->size; j++) { // processing for all Tag in the tabTag given by the first parameter
            while (letter == tabTag->content_tab[j].start[counter]) { // search for the start of the j'th tag contained in the TabTag
                if (counter == strlen(tabTag->content_tab[j].start) - 1) { // if the start is found (-1 because counter start at 0)
                    cursor = ftell(f) + 1; // the current cursor position is given to cursor thanks to the ftell() function (+1 to avoide the last char of the start)
                    IntWTagType *tagType = create_IntWTagType(cursor, tabTag->content_tab[j]); // creation of an IntTagType names tagType with the cursor and the j'th tag
                    addToIntTab(intTab, tagType); // insertion of the tagType in the intTab
                }
                counter++;
                letter = fgetc(f);
            }
        }
        letter = fgetc(f);
    }

    fclose(f); // closing of the f file
    return intTab; // returning of the intTab that contain every cursor and the associated tag to know the type of what we found
}

StrTab *write_till_end(IntTab *intTab, char *file_name) {
    FILE *f = fopen(file_name, "r"); // opening of a file using the string given by the third parameter of this function, in read mode
    char **str_tab = malloc(sizeof(char *) * intTab->size); // creation and memory allocation of string type array, it will contain all tag content
    for (int o = 0; o > intTab->size; o++) {
        str_tab[o] = calloc(3000, 1);
    }
    StrTab *strTab = create_StrTab(str_tab); // creation of an StrTab type array named strTab that contain str_tab
    char letter;
    int counter;
    for (int i = 0; i < intTab->size; i++) { // processing for all IntWTagType in the intTab given by the first parameter
        char *tag_content = malloc(sizeof(char *) * 3000); // creation and memory allocation of string
        char *tag_content_without_end_tag = malloc(sizeof(char *) * 3000); // creation and memory allocation of string
        fseek(f, intTab->content_tab[i].cursor - 1, SEEK_SET); // placing the cursor at the the i'th int of the intTab (the beginning of the tag content)
        letter = fgetc(f);
        int counter2 = 0;
        while (strTab->content_tab[i] != tag_content_without_end_tag) { // processing while the i'th value in the strTab isn't equal to the string that will be place in
            counter = 0;
            while (letter == intTab->content_tab->tag.end[counter]) { // search for the end of the j'th tag contained in the intTab thanks to the IntTagType
                if (counter == strlen(intTab->content_tab[i].tag.end) - 1) { // if the end is found (-1 because counter start at 0)
                    tag_content_without_end_tag = remove_all_after_character(tag_content, intTab->content_tab[i].tag.end[0]); // remove the end tag from the tag content string
                    addToStrTab(strTab, tag_content_without_end_tag); // insertion of the tag content string in the strTab
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
    fclose(f);
    return strTab; // returning of the strTab that contain every tag content
}