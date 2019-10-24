#include "generic_parser.h"



// return the string pointer at the next position after the founded word (if founded)
// otherwise, return the string at its end. Precise if word found with error_code
char * seak_word(char * word, char * file_string, int * error_code){

    while(*file_string != '\0'){
        int counter = 0;
        while(*file_string == word[counter]){
            if(counter == strlen(word) - 1){
                *error_code = 1;
                return file_string + 1;
            }
            counter++;
            file_string++;
        }
        file_string++;
    }
    
    *error_code = 0;
    return file_string;
}
