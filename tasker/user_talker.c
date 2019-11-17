#include "user_talker.h"

void smash_hand()
{
    puts("Merci de répondre en suivant les consignes de réponses");
}

char *get_scrapper_configuration_file()
{
    char *file_name = calloc(200, sizeof(char));
    strcpy(file_name, "../scrapper_configurations/");
    struct dirent *lecture;
    DIR *rep;
    rep = opendir("../scrapper_configurations");
    char **names = malloc(sizeof(char *) * 100);
    int index = 0;
    char *answer = calloc(1000, sizeof(char));
    while ((lecture = readdir(rep)))
    {
        if (lecture->d_name[0] == '.')
        {
            continue;
        }
        printf("%d : %s\n", index, lecture->d_name);
        names[index] = lecture->d_name;
        index++;
    }

    printf("Veuillez choisir le numero du fichier dont vous souhaitez lire la configuration\n");
    fgets(answer, 1000, stdin);
    closedir(rep);
    if (names[atoi(answer)] == NULL)
    {
        free(answer);
        hard_error_with_message("La valeur entrée est incorrect. \nPour des raisons de sécurité, nous mettons fin au programme.\n");
    }
    strcat(file_name, names[atoi(answer)]);
    return file_name;
}

int get_user_file_choice()
{
}

int get_user_proper_answer(char *question)
{
    int yesno = 0;
    char *answer = malloc(sizeof(char) * 500);
    int failed = 0;
    do
    {
        printf("\n%s\n[O]ui. [N]on.\n", question);
        fgets(answer, 500, stdin);
        failed = check_answer(answer);
        if (failed == 1)
        {
            smash_hand();
        }
    } while (failed == 1);
    yesno = interprete_answer(answer);
    free(answer);
    return yesno;
}

int check_answer(char *answer)
{
    answer = special_character_remover(answer);
    switch (strlen(answer))
    {
    case 1:
        if (answer[0] == 'O' || answer[0] == 'N')
            return 0;
        break;
    case 3:
        if (!strcmp(answer, "Oui") || !strcmp(answer, "Non"))
            return 0;
        break;
    default:
        return 1;
    }
    return 1;
}

int interprete_answer(char *answer)
{
    switch (answer[0])
    {
    case 'O':
        return 1;
        break;
    case 'N':
        return 0;
    default:
        return 2;
    }
    return 2;
}

void parsed_conf_file_successful(int error)
{

    if (!error)
    {
        puts("Le parse du fichier de configuration n'a rencontre aucun probleme bloquant !");
    }
    else
    {
        char *reason = NULL;
        puts("Malheureusement, le fichier n'a pas pu etre charge. Merci d'en choisir un autre.");
        switch (error)
        {
        case 3:
            reason = "Le nom du fichier était incorrect\n";
            break;
        default:
            reason = "L'erreur n'a pu être indentifiée\n";
        }
        printf("Raison : %s", reason);
    }
}

void inform_user_about_loaded_params(param_container *params)
{
    printf("Le fichier de configuration contient %d actions, et %d taches parametrees.\n", params->action_amount, params->task_amount);
}

void ask_user_if_needed_details(param_container *params)
{
    int yesno = get_user_proper_answer("Souhaitez-vous en savoir plus sur le contenu du fichier de configuration?");

    if (!yesno)
    {
        return;
    }

    print_full_params(params);
}

void ask_user_if_needed_bug_reported(param_container *params)
{
    int yesno = get_user_proper_answer("Souhaitez-vous un retour sur les éventuels erreurs présentent dans la configuration?");

    if (!yesno)
    {
        return;
    }

    report_errors(params);
}

int ask_launch_tasks(param_container *params)
{
    return get_user_proper_answer("Souhaitez-vous lancer les taches ?");
}