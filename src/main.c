#include "./supervisor.h"


int main(int argc, char ** argv){
    char * filename = "file.html";
    char * url = "https://stackoverflow.com/questions/1636333/download-file-using-libcurl-in-c-c";


//    char* res = seak_word("il", "qui", "il es est es beau le qu chat qui cours");
//    printf("%s \n", res);

//    int err = fill_actions();

char* l = seak_word_in_file("<a", "</a>", "file_content.txt");
printf("%s \n", l);
char* t = seak

    return 0;
}

//test push benoit