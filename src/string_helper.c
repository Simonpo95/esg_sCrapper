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
    scut->strings = realloc(scut->strings, (scut->size + 1) * sizeof(char *));
    scut->strings[scut->size++] = trim_before_after(string);
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
        string++;
    }

    if (cut_index > 0)
    {
        char *cutted_string = calloc(cut_index + 1, 1);
        for (int i = 0; i < cut_index; i++)
        {
            cutted_string[i] = string_copy[i];
        }

        return cutted_string;
    }

    return string_copy;
}

int is_string_in_string_array(char *string, char **string_array, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (!strcmp(string, string_array[i]))
        {
            return 1;
        }
    }
    return 0;
}

char *get_extensions_from_types(char *type)
{

    char *possible_content_type[] = {
        "audio/aac",
        "application/x-abiword",
        "application/octet-stream",
        "video/x-msvideo",
        "application/vnd.amazon.ebook",
        "application/octet-stream",
        "application/x-bzip",
        "application/x-bzip2",
        "application/x-csh",
        "text/css",
        "text/csv",
        "application/msword",
        "application/vnd.openxmlformats-officedocument.wordprocessingml.document",
        "application/vnd.ms-fontobject",
        "application/epub+zip",
        "image/gif",
        "text/html",
        "image/x-icon",
        "text/calendar",
        "application/java-archive",
        "image/jpeg",
        "application/javascript",
        "application/json",
        "audio/midi",
        "video/mpeg",
        "application/vnd.apple.installer+xml",
        "application/vnd.oasis.opendocument.presentation",
        "application/vnd.oasis.opendocument.spreadsheet",
        "application/vnd.oasis.opendocument.text",
        "audio/ogg",
        "video/ogg",
        "application/ogg",
        "font/otf",
        "image/png",
        "application/pdf",
        "application/vnd.ms-powerpoint",
        "application/vnd.openxmlformats-officedocument.presentationml.presentation",
        "application/x-rar-compressed",
        "application/rtf",
        "application/x-sh",
        "image/svg+xml",
        "application/x-shockwave-flash",
        "application/x-tar",
        "image/tiff",
        "application/typescript",
        "font/ttf",
        "application/vnd.visio",
        "audio/x-wav",
        "audio/webm",
        "video/webm",
        "image/webp",
        "font/woff",
        "font/woff2",
        "application/xhtml+xml",
        "application/vnd.ms-excel",
        "application/vnd.openxmlformats-officedocument.spreadsheetml.sheet",
        "application/xml",
        "application/vnd.mozilla.xul+xml",
        "application/zip",
        "video/3gpp",
        "audio/3gpp",
        "video/3gpp2",
        "audio/3gpp2",
        "application/x-7z-compressed",
        "application/rss+xml",
        "text/plain",
        "text/xml"};

    char *possible_extension[] = {
        ".aac",
        ".abw",
        ".arc",
        ".avi",
        ".azw",
        ".bin",
        ".bz",
        ".bz2",
        ".csh",
        ".css",
        ".csv",
        ".doc",
        ".docx",
        ".eot",
        ".epub",
        ".gif",
        ".html",
        ".ico",
        ".ics",
        ".jar",
        ".jpeg",
        ".js",
        ".json",
        ".midi",
        ".mpeg",
        ".mpkg",
        ".odp",
        ".ods",
        ".odt",
        ".oga",
        ".ogv",
        ".ogx",
        ".otf",
        ".png",
        ".pdf",
        ".ppt",
        ".pptx",
        ".rar",
        ".rtf",
        ".sh",
        ".svg",
        ".swf",
        ".tar",
        ".tiff",
        ".ts",
        ".ttf",
        ".vsd",
        ".wav",
        ".weba",
        ".webm",
        ".webp",
        ".woff",
        ".woff2",
        ".xhtml",
        ".xls",
        ".xlsx",
        ".xml",
        ".xul",
        ".zip",
        ".3gp",
        ".3gp",
        ".3g2",
        ".3g2",
        ".7z",
        ".xml",
        ".html",
        ".xml"};

    if(sizeof(possible_content_type) == sizeof(possible_extension))
    {
        for (int i = 0; i < sizeof(possible_content_type) / 8; i++)
        {
            if (!strcmp(type, possible_content_type[i]))
            {
                char * returned = malloc(sizeof(char) * 30);
                strcpy(returned, possible_extension[i]);
                return returned;
            }
        }
    }
    else
    {
        printf("\nLes tableaux de types ne sont pas de la même taille !!! \n\n");
    }

    return "null";
}