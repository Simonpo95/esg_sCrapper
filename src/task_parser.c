#include "task_parser.h"

int fill_actions(param_container *params)
{
    int code_error = 0;
    size_t line_len = 0;
    ssize_t read;
    char *line = NULL;
    FILE *f = fopen("../scrapper.sconf", "r");

    if (f == NULL)
    {
        return 3;
    }

    while ((read = getline(&line, &line_len, f)) != -1)
    {
        char *fully_trimmed_parsed_line = special_character_remover(line);
        if (!strcmp("=", fully_trimmed_parsed_line))
        {
            fetch_action_parameters(params, f, line, line_len);
        }
        else if (!strcmp("==", fully_trimmed_parsed_line))
        {
            // fetch_task();
        }

        if (fully_trimmed_parsed_line != NULL)
        {
            free(fully_trimmed_parsed_line);
        }
    }

    if (line != NULL)
    {
        free(line);
    }

    fclose(f);

    return code_error;
}

int get_file_char_amount(FILE *f)
{
    fseek(f, 0, SEEK_END);
    int character_counter = ftell(f);
    rewind(f);
    return character_counter;
}

void fetch_action_parameters(param_container * params, FILE *f, char *line, size_t line_len)
{
    action * action_to_add = malloc(sizeof(action));

    ssize_t read;
    while ((read = getline(&line, &line_len, f)) != -1)
    {
        char *fully_trimmed_parsed_line = special_character_remover(line);
        printf("inside function : %s\n", fully_trimmed_parsed_line);
        if (!strcmp("=", fully_trimmed_parsed_line) || !strcmp("==", fully_trimmed_parsed_line))
        {
            return;
        }

        if (!strcmp("+", fully_trimmed_parsed_line))
        {
            fill_action_option();
            return;
        }

        free(fully_trimmed_parsed_line);

        char * option_trimmed_before_after = trim_before_after(line);
        if(check_first_last_character('{', '}', line)){
            fill_action_with_line_parameter(line, action_to_add);
        }
    }
}

void fetch_task()
{
    return;
}

void fill_action_option(){
    return;

}

void fill_action_with_line_parameter(char * line, action * action){
    int err = 0;
    scutted * cutted_line = string_cutter(&err, line, "->");
    if(err == 1){
        easy_error_with_message(WRONG_PARAMETER_ERROR_MESSAGE);
        return;
    }
    return;
}