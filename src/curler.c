#include "curler.h"

size_t write_data(void *ptr, size_t size, size_t nmemb, FILE *stream)
{
    size_t written = fwrite(ptr, size, nmemb, stream);
    return written;
}

int curlit(char *filepath, char *url)
{
    CURL *curl;
    FILE *f;
    CURLcode res;
    int size = 0;
    curl = curl_easy_init();
    if (curl)
    {
        f = fopen(filepath, "w+");
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, f);
        res = curl_easy_perform(curl);
        fclose(f);
    }
    curl_easy_cleanup(curl);
}

char *typecheck(char *url)
{
    CURL *curl;
    char *content_type;
    CURLcode response;
    FILE *f;
    curl = curl_easy_init();
    if (curl)
    {
        f = fopen("trash.txt", "w+");
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, f);
        response = curl_easy_perform(curl);
        if (!response)
        {
            response = curl_easy_getinfo(curl, CURLINFO_CONTENT_TYPE, &content_type);
            return content_type;
        }
        remove("trash.txt");
    }
    return "dada";
}