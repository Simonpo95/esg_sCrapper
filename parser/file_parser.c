#include <stdio.h>
#include <string.h>
#include <curl/curl.h>
#include <stdlib.h>
#include <math.h>

IntTab* seek_start_Tag(Tag*, char*);

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