#include <stdio.h>
#include <string.h>
#include <curl/curl.h>
#include <stdlib.h>
#include <math.h>

struct StrTab{
    char** content_tab;
    int size;
    int capacity;
};

typedef struct StrTab StrTab;

//separation

StrTab* create_StrTab(char**);
void printStrTab(StrTab);
void addToStrTab(StrTab*, char*);

//separation

StrTab* create_StrTab(char** content_tab)
{
    struct StrTab* strTab = (struct StrTab*)malloc(sizeof(struct StrTab));
    strTab->content_tab = content_tab;
    strTab->size = 0;
    strTab->capacity = 4;
    return strTab;
}

void printStrTab(StrTab strTab){
    printf("\n");
    for(int i = 0; i < strTab.size; i++)
    {
        printf("print of content_tab = %d \n content = %s\n",i, strTab.content_tab[i]);
        printf("\n");
    }
    printf("fin printf\n");
    printf("\n");
}

void addToStrTab(StrTab* strTab, char* string)
{
    strTab->content_tab[strTab->size] = string;
//    printf("ité = %d - content = %s | act size = %d | capa = %d\n",strTab->size, strTab->content_tab[strTab->size], strTab->size, strTab->capacity);
    strTab->size ++;
    if(strTab->size >= strTab->capacity)
    {
        strTab->capacity *= 1.5;
    }
    printf("-- fin add\n\n");
}