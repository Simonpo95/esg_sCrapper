#include <stdio.h>
#include <string.h>
#include <curl/curl.h>
#include <stdlib.h>
#include <math.h>

int* seek_start_Tag(Tag*, char*);

int* seek_start_Tag(Tag* tabTag, char* file_name)
{
    int cursor;
    int tab_size = 1;
    int counter;
    int counter2 = 0;
    char letter;
    int* tabCursor = malloc(sizeof(int) * tab_size);

    FILE* f = fopen(file_name, "r");
    letter = fgetc(f);

    while (letter != EOF)
    {
        int counter = 0;
        while (letter == tabTag[0].start[counter])
        {
            if (counter == strlen(tabTag[0].start) - 1)
            {
                cursor = ftell(f);
                tabCursor[counter2] = cursor;
                if(tab_size <= counter2)
                {
                    tab_size *= 2;
                    tabCursor = (int*) realloc(tabCursor, sizeof(int) * tab_size);
                }
                counter2++;
            }
            counter++;
            letter = fgetc(f);
        }
        letter = fgetc(f);
    }

    cursor = ftell(f);
    tabCursor = (int*) realloc(tabCursor, sizeof(int) *counter2);
    return tabCursor;
}