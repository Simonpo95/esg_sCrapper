#include "file_parser.h"

int is_inside(char *string, StrTab *strTab)
{

    for (int i = 0; i < strTab->size; i++)
    {
        if (strcmp(string, strTab->content_tab[i]) == 0)
        {
            printf("~~ %s\n",string);
            printf("~~ chaine deja présente dans le tableau\n");
            return 1;
        }
    }

    return 0;
}

IntTab *seek_start_Tag(TagTab *tagTab, char *file_name)
{
    if (strcmp("html", get_extension(file_name)))
    {
        printf("%s", get_extension(file_name));
        return NULL;
    }

    char * principal_directory_path = calloc(sizeof(char) * strlen(DIR_ROOT), sizeof(char));

    strcpy(principal_directory_path, DIR_ROOT);

    char *principal_directory_path_with_file_name = calloc(sizeof(char) * (strlen(file_name) + strlen(principal_directory_path)), sizeof(char));      // creation d'un char pour nom fichier ou dossier

    sprintf(principal_directory_path_with_file_name, "%s%s", principal_directory_path, file_name);

    int cursor;
    int counter; // this counter will help us to track the start string
    char letter;
    IntWTagType *tabCursor;                    // creation of an IntTabType type array named tabCursor
    IntTab *intTab = create_IntTab(tabCursor); // creation of an IntTab type array named intTab that contain tabCursor

    FILE *f = fopen(principal_directory_path_with_file_name, "r"); // opening of a file using the string given by the second parameter of this function, in read mode
    letter = fgetc(f);               // giving of the first character in the file to letter

    while (letter != EOF)
    { // browsing through untill the End Of File thanks to fgetc() function
        int counter = 0;
        for (int j = 0; j < tagTab->size; j++)
        { // processing for all Tag in the tagTab given by the first parameter
            while (letter == tagTab->content_tab[j].start[counter])
            { // search for the start of the j'th tag contained in the TabTag
                if (counter == strlen(tagTab->content_tab[j].start) - 1)
                {                                                                              // if the start is found (-1 because counter start at 0)
                    cursor = ftell(f) + 1;                                                     // the current cursor position is given to cursor thanks to the ftell() function (+1 to avoide the last char of the start)
                    IntWTagType *tagType = create_IntWTagType(cursor, tagTab->content_tab[j]); // creation of an IntTagType names tagType with the cursor and the j'th tag
                    addToIntTab(intTab, tagType);                                              // insertion of the tagType in the intTab
                }
                counter++;
                letter = fgetc(f);
            }
        }
        letter = fgetc(f);
    }

    fclose(f);     // closing of the f file
    return intTab; // returning of the intTab that contain every cursor and the associated tag to know the type of what we found
}

StrTab *write_till_end(IntTab *intTab, char *file_name)
{
    char * principal_directory_path = calloc(sizeof(char) * strlen(DIR_ROOT), sizeof(char));

    strcpy(principal_directory_path, DIR_ROOT);

    char *principal_directory_path_with_file_name = calloc(sizeof(char) * (strlen(file_name) + strlen(principal_directory_path)), sizeof(char));      // creation d'un char pour nom fichier ou dossier

    sprintf(principal_directory_path_with_file_name, "%s%s", principal_directory_path, file_name);

    FILE *f = fopen(principal_directory_path_with_file_name, "r");              // opening of a file using the string given by the third parameter of this function, in read mode
    StrTab *strTab = create_StrTab(intTab->size); // creation of an StrTab type array named strTab that contain str_tab
    char letter;
    int counter;
    for (int i = 0; i < intTab->size; i++)
    { // processing for all IntWTagType in the intTab given by the first parameter
        int should_break = 0;
        char *tag_content = calloc(sizeof(char) * 3000, sizeof(char));                 // creation and memory allocation of string
        char *tag_content_without_end_tag = calloc(sizeof(char) * 3000, sizeof(char)); // creation and memory allocation of string
        fseek(f, intTab->content_tab[i].cursor - 1, SEEK_SET);                         // placing the cursor at the the i'th int of the intTab (the beginning of the tag content)
        letter = fgetc(f);
        int counter2 = 0;
        while (strTab->content_tab[i] != tag_content_without_end_tag)
        { // processing while the i'th value in the strTab isn't equal to the string that will be place in
            counter = 0;
            while (letter == intTab->content_tab->tag.end[counter])
            { // search for the end of the j'th tag contained in the intTab thanks to the IntTagType
                if (counter == strlen(intTab->content_tab[i].tag.end) - 1)
                {                                                                                                             // if the end is found (-1 because counter start at 0)
                    tag_content_without_end_tag = remove_all_after_character(tag_content, intTab->content_tab[i].tag.end[0]); // remove the end tag from the tag content string
                                                                                                                              //                    tag_content_without_end_tag = remove_all_after_character(tag_content_without_end_tag, '#');
                    tag_content_without_end_tag = remove_all_after_character(tag_content_without_end_tag, '?');
//                    if (tag_content_without_end_tag[strlen(tag_content_without_end_tag) - 1] == '/')
//                    {
//                        tag_content_without_end_tag[strlen(tag_content_without_end_tag) - 1] = 0; // remove last char / to avoide double
//                    }

                    if (tag_content_without_end_tag != "" && (strcmp(tag_content_without_end_tag, "#") != 0))
                    {
                        should_break = addToStrTab(strTab, tag_content_without_end_tag); // insertion of the tag content string in the strTab
                    }
                    else
                    {
                        should_break = 1;
                    }
                }
                tag_content[counter2] = letter;
                counter2++;
                counter++;
                letter = fgetc(f);
            }
            if (should_break == 1)
            {
                break;
            }
            tag_content[counter2] = letter;
            counter2++;
            letter = fgetc(f);
        }
    }
    fclose(f);
    return strTab; // returning of the strTab that contain every tag content
}

char *get_extension(char *file_name)
{
    int error = 0;
    scutted *scut = string_cutter(&error, file_name, ".");
    return scut->strings[(scut->size) - 1];
}