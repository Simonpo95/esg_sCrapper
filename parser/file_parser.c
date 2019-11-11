#include <stdio.h>
#include <string.h>
#include <curl/curl.h>
#include <stdlib.h>
#include <math.h>

IntTab* seek_start_Tag(Tag*, char*);
StrTab* write_till_end(IntTab*, Tag*, char*);

IntTab* seek_start_Tag(Tag* tabTag, char* file_name)
{
    int cursor;
    int tab_size = 1;
    int counter;
    int counter2 = 0;
    char letter;
    int* tabCursor = malloc(sizeof(int) * tab_size);
    IntTab* tab1 = create_IntTab(tabCursor);

    FILE* f = fopen(file_name, "r");
    letter = fgetc(f);

    while (letter != EOF)
    {
        int counter = 0;
        for(int j = 0; j < 2; j++)
        {
            while (letter == tabTag[j].start[counter])
            {
                if (counter == strlen(tabTag[j].start) - 1)
                {
                    cursor = ftell(f) + 1;
                    tab1->content_tab[counter2] = cursor;
                    if(tab1->size <= counter2)
                    {
                        tab1->size *= 2;
                        tab1->content_tab = (int*) realloc(tab1->content_tab, sizeof(int) * tab1->size);
                    }
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
    tab1->content_tab = (int*) realloc(tab1->content_tab, sizeof(int) * (tab1->size));
    return tab1;
}

StrTab* write_till_end(IntTab* intTab, Tag* tabTag, char* file_name)
{
    FILE* f = fopen(file_name, "r");

    char ** str_tab = malloc(sizeof(char*) * 100);
    for(int o = 0; o > 100; o++)
    {
        str_tab[o] = calloc(1000, 1);
    }
    StrTab* strTab = create_StrTab(str_tab, 1000);

    char letter;
    int counter;

    for(int i = 0; i < intTab->size; i++)
    {
        char* tag_content = malloc(sizeof(char*) * 1000);
        fseek(f, intTab->content_tab[i] - 1, SEEK_SET);
        letter = fgetc(f);
        for(int j = 0; j < 1; j++)
        {
            int counter2 = 0;
//            printf("%d --- %d --- %s\n", i,j,tabTag[j].end);
            while (strTab->content_tab[i] != tag_content)
            {
                counter = 0;
                while (letter == tabTag[j].end[counter])
                {
                    if (counter == strlen(tabTag[j].end) - 1)
                    {
                        printf("%d tag content -- %s\n\n",i, tag_content);
                        addToStrTab(strTab, tag_content);
                        printf("%d content tab -- %s\n\n",i, strTab->content_tab[i]);
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
//    printf("%d - %ld - %c - %s\n",i, ftell(f), letter, ler);
    }
    fclose(f);
    return strTab;
}

//StrTab* write_till_end(IntTab* intTab, Tag* tabTag, char* file_name)
//{
//    FILE* f = fopen(file_name, "r");
//
//    char ** str_tab = malloc(sizeof(char*) * 1000);
//    StrTab* strTab = create_StrTab(*str_tab);
//    char* tag_content = malloc(sizeof(char) * 1000);
//    char letter;
//    int counter;
//    int counter2 = 0;
//
//    printf("%d \n",intTab->size);
//
//    for(int i = 0; i < intTab->size; i++)
//    {
//        fseek(f, intTab->content_tab[i] - 1, SEEK_SET);
//        letter = fgetc(f);
//
//        for(int j = 0; j < 1; j++)
//        {
//            while (letter != EOF)
//            {
////                printf("%d - dada\n", i);
//                counter = 0;
//                while (letter == tabTag[j].end[counter])
//                {
//                    if (counter == strlen(tabTag[j].end) - 1)
//                    {
////                        printf("%s\n", tag_content);
//                        strTab->content_tab[i] = "*tag_content";
//                        return strTab;
////                        printf("%s\n", tag_content);
//                        char* tag_content = malloc(sizeof(char) * 1000);
//                    }
//                    tag_content[counter2] = letter;
//                    counter2++;
//                    counter++;
//                    letter = fgetc(f);
//                }
//                tag_content[counter2] = letter;
//                counter2++;
//                letter = fgetc(f);
//            }
//        }
//    }
////    strTab->content_tab[0] = tag_content;
//    return strTab;
//}