#include "task_parser.h"



int fill_actions(){
    int code_error = 0;
    size_t line_len = 0;
    ssize_t read;
    char * line = NULL;
    FILE * f = fopen("../scrapper.sconf", "r");

    if(f == NULL){ return 3;}

    while ((read = getline(&line, &line_len, f)) != -1) {
        char * fully_trimmed_parsed_line = special_character_remover(line);
        if(!strcmp("=", fully_trimmed_parsed_line)){
            // fetch_action();
        } else if(!strcmp("==", fully_trimmed_parsed_line)){
            // fetch_task();
        }

        if(fully_trimmed_parsed_line != NULL){
            free(fully_trimmed_parsed_line);
        }
    }

    if(line != NULL){
        free(line);
    }

    fclose(f);

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

void fetch_task(){

}

