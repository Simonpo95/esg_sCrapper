#include "curlStrTab.h"

void curlStrTab(struct StrTab * strTab)
{

    char * path = make_director("hello", "../web_site/");

    char* possible_content_type[] = {
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
            "application/rss+xml"};

    char* possible_extension[] = {
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
            "xml"};

    if(sizeof(possible_content_type) != sizeof(possible_extension))
    {
        printf("size ne sont pas de la même taille");
    }

    char* dada_str = "dada";
//    char* null_str = "(null)";

    for(int i = strTab->last_curl; i < strTab->size; i++)
    {
//        char* final_path = malloc(sizeof(char) * 245); // creation d'un char pour nom fichier ou dossier
//        char* cpy_destination = malloc(sizeof(char) * 245); // creation d'un char pour copier d->content_tab[i]
//        char* result = malloc(sizeof(char) * 245); // creation d'un char pour get le type

        char* final_path = calloc(sizeof(char) * (strlen(strTab->content_tab[i])), sizeof(char));
        char* cpy_destination = calloc(sizeof(char) * (strlen(strTab->content_tab[i])), sizeof(char));
        char* result = calloc(sizeof(char) * 5000, sizeof(char));


        char* extension = calloc(sizeof(char) * 50, sizeof(char));

        result = typecheck(strTab->content_tab[i]);

        result = remove_all_after_character(result, 59);

        if(strcmp(dada_str, result) == 0)
        {
            extension = ".txt";
        }
        else
        {
            for(int i = 0; i < (sizeof(possible_content_type) / 8); i++)
            {
                if(strcmp(possible_content_type[i], result) == 0)
                {
                    extension = possible_extension[i];
                    break;
                }
                else
                {
                    extension = ".unknown";
                }
            }
        }

//        if(strcmp(null_str, extension) == 0)
//        {
//            extension = ".unknown_null";
//        }

        strcpy(cpy_destination, strTab->content_tab[i]);

        int y = 0;
        while(cpy_destination[y] != 0) {
            if (cpy_destination[y] == 34 || cpy_destination[y] == 38 || cpy_destination[y] == 47 ||
                cpy_destination[y] == 58 || cpy_destination[y] == 60 || cpy_destination[y] == 62 ||
                cpy_destination[y] == 63 || cpy_destination[y] == 92 || cpy_destination[y] == 124) {
                cpy_destination[y] = 45;
            }
            y++;
        }

//        char * path = "make_director";

        sprintf(final_path, "%s%s%s",path , cpy_destination, extension );


        curlit(final_path, strTab->content_tab[i]);


        printf("%d -/- %s \n", i, strTab->content_tab[i]);
        printf("\n");
        printf(" _ %s -/- %s\n", extension, result);
        printf(" ---\n");
    }
    strTab->last_curl = strTab->size;
}