#include "task_parser.h"



int fill_actions(){
    int code_error = 0;
    size_t line_len = 0;
    ssize_t read;
    char * line = NULL;
    FILE * f = fopen("../scrapper.sconf", "r");

    if(f == NULL){ return 3;}

    while ((read = getline(&line, &line_len, f)) != -1) {
        if(!strcmp("=", special_character_remover(line))){
            fetch_action();
        } else if(!strcmp("==", special_character_remover(line))){
            
        }
    }

    if(line != NULL){
        free(line);
    }
    return code_error;
}

int get_file_char_amount(FILE * f){
    fseek(f, 0, SEEK_END);
    int character_counter = ftell(f);
    rewind(f);
    return character_counter;
}

void fetch_action(){

}

