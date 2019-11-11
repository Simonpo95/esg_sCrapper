#include "string_helper.h"

int is_it(char *characters_list, int list_size, char character_checked)
{
    for (int i = 0; i < list_size; i++)
    {
        if (character_checked == characters_list[i])
        {
            return 1;
        }
    }
    return 0;
}
char *special_character_remover(char *string)
{
    int index = 0;
    char special_characters[4] = {' ', '\n', '\t', '\r'};
    char *result = malloc(strlen(string) + 1);
    while (*string != '\0')
    {
        if (!is_it(special_characters, 4, *string))
        {
            result[index] = *string;
            index++;
        }
        string++;
    }
    result[index] = '\0';
    return result;
}

char *trim_before_after(char *string)
{
    return trim_after(trim_before(string));
}

char *trim_before(char *string)
{

    while (*string == ' ')
    {
        string++;
    }
    return string;
}

char *trim_after(char *string)
{
    int to_remove = 0;
    for (int i = strlen(string) - 1; i >= 0 && (string[i] == ' ' || string[i] == '\n'); i--)
    {
        to_remove++;
    }

    int new_size = strlen(string) - to_remove + 1;

    char *new_string = malloc(new_size);
    for (int i = 0; i < new_size; i++)
    {
        new_string[i] = string[i];
    }
    new_string[new_size - 1] = '\0';

    string = new_string;

    return string;
}

int check_first_last_character(char first, char last, char *string)
{
    if (string[0] == first && string[strlen(string) - 1] == last)
    {
        return 1;
    }
    return 0;
}

scutted *string_cutter(int *error, char *string, char *cutter)
{
    scutted *string_cutted = malloc(sizeof(scutted));
    string_cutted->strings = NULL;
    string_cutted->size = 0;

    while (*string != '\0')
    {
        int word_size = 0;
        while (is_not_cutter(string, cutter) && *string != '\0')
        {
            word_size++;
            string++;
        }
        char *new_word = calloc(word_size + 1, 1);
        string -= word_size;
        int cword_size = word_size;
        while (cword_size != 0)
        {
            *new_word = *string;
            cword_size--;
            new_word++;
            string++;
        }

        *new_word = '\0';
        new_word -= word_size;

        if (strcmp(new_word, ""))
        {
            add_to_scutted(new_word, string_cutted);
        }

        if (*string != '\0')
        {
            string += strlen(cutter);
        }
    }

    *error = 1;
    return string_cutted;
}

int is_not_cutter(char *string, char *cutter)
{
    if (strlen(string) < strlen(cutter))
        return 1;
    for (int i = 0; i < strlen(cutter); i++)
    {
        if (string[i] != cutter[i])
        {
            return 1;
        }
    }
    return 0;
}

void add_to_scutted(char *string, scutted *scut)
{
    char **strings = malloc(sizeof(char *) * (scut->size + 1));
    for (int i = 0; i < scut->size; i++)
    {
        strings[i] = scut->strings[i];
    }
    strings[scut->size] = trim_before_after(string);
    scut->size++;
    if (scut->strings != NULL)
    {
        free(scut->strings);
    }
    scut->strings = strings;
}

void read_scutted(scutted *scut)
{
    for (int i = 0; i < scut->size; i++)
    {
        printf("%d : %s\n", i, scut->strings[i]);
    }
}

char *remove_first_last_character(char *string)
{
    if (string[strlen(string) - 1] == '\n')
    {
        string[strlen(string) - 2] = '\0';
    }
    else
    {
        string[strlen(string) - 1] = '\0';
    }
    return ++string;
}

char *remove_all_after_character(char *string, char delimitor)
{
    char *string_copy = malloc(strlen(string) + 1);
    strcpy(string_copy, string);
    int cut_index = 0;
    while (*string != '\0' && *string != delimitor)
    {
        cut_index++;
        printf("%c", *string);
        string++;
    }

    if (cut_index > 0)
    {
        char * cutted_string = malloc(cut_index + 1);
        for(int i = 0; i < cut_index; i++){
            cutted_string[i] = string_copy[i];
        }
        cutted_string[cut_index] = '\0';        

        return cutted_string;
    }

    return string_copy;
}
