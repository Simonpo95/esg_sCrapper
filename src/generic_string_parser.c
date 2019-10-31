#include "generic_string_parser.h"

// return the string pointer at the next position after the founded word (if founded)
// otherwise, return the string at its end. Precise if word found with error_code

//char * seak_word(char * word, char * file_string, int * error_code){
char *seak_word(char *start, char *end, char *file_string) {

    char *res = malloc(sizeof(char) * 1000);
    int counter2 = 0;
    while (*file_string != '\0') {
        int counter = 0;
        while (*file_string == start[counter]) {
            if (counter == strlen(start) - 1) {
//                *error_code = 1;
                while (*file_string != '\0') {
                    int counter = 0;
                    while (*file_string == end[counter]) {
                        if (counter == strlen(end) - 1) {
                            return res;
                        }
                        res[counter2] = *file_string;
                        counter2++;
                        counter++;
                        file_string++;
                    }
                    res[counter2] = *file_string;
                    counter2++;
                    file_string++;
                }
                return res;
            }
            counter++;
            file_string++;
        }
        file_string++;
    }

//    *error_code = 0;
    return file_string;
}