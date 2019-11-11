#include "./supervisor.h"

int main(int argc, char **argv)
{
    char *filename = "file.html";
    char *url = "https://stackoverflow.com/questions/1636333/download-file-using-libcurl-in-c-c";

    param_container *params = malloc(sizeof(param_container));

    int err = fill_actions(params);

    return 0;
}