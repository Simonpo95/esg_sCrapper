#include "./supervisor.h"


int main(int argc, char ** argv){
    char * filename = "file.html";
    char * url = "https://stackoverflow.com/questions/1636333/download-file-using-libcurl-in-c-c";
    // curlit(filename, url);
    printf("%s\n", typecheck(url));
    return 0;
}

//test push benoit