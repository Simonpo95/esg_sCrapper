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
        printf("\n\nAction %d", i);
        print_action(params->actions[i]);
    }

    if (params->task_amount == 0)
    {
        printf("\nPas de task présente.\n");
    }

    // TODO lorsqque task créée
    //  for (int i = 0; i < params->action_amount; i++)
    // {
    //     print_action(params->actions[i]);
    // }
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