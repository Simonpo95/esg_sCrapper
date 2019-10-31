#include "generic_file_parser.h"

// return the string pointer at the next position after the founded word (if founded)
// otherwise, return the string at its end. Precise if word found with error_code

//char * seak_word(char * word, char * file_string, int * error_code){
char* seak_word(char *start, char *end, char* file) {

    char *res = malloc(sizeof(char) * 1000);
    char lettre;
    int counter2 = 0;
    FILE* f = fopen(file, "r");
    lettre = fgetc(f);

    while (lettre != EOF) {
        int counter = 0;
        while (lettre == start[counter]) {
            if (counter == strlen(start) - 1) {
//                printf("%d\n", counter);
//                *error_code = 1;
                while (lettre != '\0') {
                    int counter = 0;
                    while (lettre == end[counter]) {
                        if (counter == strlen(end) - 1) {
//                            printf("%d\n", counter);
//                            printf("%d\n", counter2);
                            return res;
                        }
                        res[counter2] = lettre;
                        counter2++;
                        counter++;
                        lettre = fgetc(f);
                    }
                    res[counter2] = lettre;
                    counter2++;
                    lettre = fgetc(f);
                }
                return res;
            }
            counter++;
            lettre = fgetc(f);
        }
        lettre = fgetc(f);
    }

//    *error_code = 0;
    return "res \n";
//
//    return lettre;

}
