#include "params_helper.h"

void print_action(action *act)
{
    if (act->properties_amount == 0)
    {
        printf("\nL'action n'a aucune propriété\n");
    }

    for (int i = 0; i < act->properties_amount; i++)
    {
        printf("\nPropriete %d : %s -> %s", i, act->properties[i]->name, act->properties[i]->value);
    }

    if (act->option_amount == 0)
    {
        printf("\nL'action n'a aucune option\n");
    }

    for (int i = 0; i < act->option_amount; i++)
    {
        printf("\nOption %d : %s -> %s", i, act->options[i]->name, act->options[i]->value);
    }
}

void print_full_params(param_container *params)
{
    if (params->action_amount == 0)
    {
        printf("\nPas d'action présente.");
    }

    for (int i = 0; i < params->action_amount; i++)
    {
        printf("\n\nAction %d", i + 1);
        print_action(params->actions[i]);
    }

    printf("\n");

    if (params->task_amount == 0)
    {
        printf("\nPas de task présente.\n");
    }

    for (int i = 0; i < params->task_amount; i++)
    {
        printf("\nTask %d :\n", i + 1);
        print_task(params->tasks[i]);
    }
}

void add_action_to_params(param_container *params, action *act)
{
    int size = params->action_amount;
    action **new_action_list = malloc(sizeof(action *) * (size + 1));
    for (int i = 0; i < size; i++)
    {
        new_action_list[i] = params->actions[i];
    }

    new_action_list[size] = act;

    if (params->actions != NULL)
    {
        free(params->actions);
    }

    params->actions = new_action_list;
    params->action_amount++;
}

void add_task_to_params(param_container *params, task *ta)
{
    int size = params->task_amount;
    task **new_task_list = malloc(sizeof(task *) * (size + 1));
    for (int i = 0; i < size; i++)
    {
        new_task_list[i] = params->tasks[i];
    }

    new_task_list[size] = ta;

    if (params->tasks != NULL)
    {
        free(params->tasks);
    }

    params->tasks = new_task_list;
    params->task_amount++;
}

void print_task(task *ta)
{
    if (ta->properties_amount == 0)
    {
        printf("\nLa tache ne possede pas de propriete\n");
    }

    for (int i = 0; i < ta->properties_amount; i++)
    {
        printf("Propriete %d : %s -> %s\n", i, ta->properties[i]->name, ta->properties[i]->value);
    }

    if (ta->action_amount == 0)
    {
        printf("\nLa tache ne contient pas d'action\n");
    }

    for (int i = 0; i < ta->action_amount; i++)
    {
        printf("Action %d : %s\n", i, ta->actions_name[i]);
    }
}

void print_errors(param_container *params)
{
    
}

param_container *create_empty_params()
{
    param_container *params = malloc(sizeof(param_container));
    params->action_amount = 0;
    params->actions = NULL;
    params->task_amount = 0;
    params->tasks = NULL;
    return params;
}

action *create_empty_action()
{
    action *action_to_create = malloc(sizeof(action));
    action_to_create->option_amount = 0;
    action_to_create->properties_amount = 0;
    action_to_create->properties = NULL;
    action_to_create->options = NULL;
}

task *create_empty_task()
{
    task *task_to_create = malloc(sizeof(task));
    task_to_create->properties_amount = 0;
    task_to_create->action_amount = 0;
    task_to_create->actions_name = NULL;
    task_to_create->properties = NULL;
}