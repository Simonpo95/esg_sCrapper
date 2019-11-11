#include "./supervisor.h"

int main(int argc, char **argv)
{
    char *filename = "file.html";
    char *url = "https://stackoverflow.com/questions/1636333/download-file-using-libcurl-in-c-c";

    param_container *params = malloc(sizeof(param_container));
    params->action_amount = 0;
    params->actions = NULL;
    params->task_amount = 0;
    params->tasks = NULL;

    int err = fill_actions(params);

    if(err == 3){
        
    }

    print_full_params(params);

    printf("%s\n", remove_all_after_character("salut les gens #coucou les quilles", '#'));

    return 0;
}