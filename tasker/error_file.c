#include "error_file.h"


void easy_error_with_message(char * error_message){
}

void hard_error_with_message(char * error_message){
    printf("\nError : %s\n", error_message);
    exit(-1);
}