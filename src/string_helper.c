#include "supervisor.h"

int is_it(char * characters_list, int list_size, char character_checked){
    for(int i = 0; i < list_size; i++){
        if(character_checked == characters_list[i]){
            return 1;
        }
    }
    return 0;
}
char * special_character_remover(char * string){
    int index = 0;
    char special_characters[4] = {' ', '\n', '\t', '\r'};
    printf("string = %d", strlen(string));
    char * result = malloc(strlen(string) + 1);
    while(*string != '\0'){
        printf("%c ", *string);
        if(!is_it(special_characters, 4, *string)){
            result[index] = *string;
            index++;
        }
        string++;
    }
    result[index] = '\0';
    return result;
}