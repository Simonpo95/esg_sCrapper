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

void report_errors(param_container *params)
{

    char *tasks_authorized_properties[] = {"name", "second", "minute", "hour"};

    for (int i = 0; i < params->action_amount; i++)
    {
        report_action_errors(params->actions[i], i);
    }

    for (int i = 0; i < params->task_amount; i++)
    {
        report_tasks_errors(params->tasks[i], i, params->actions, params->action_amount);
    }
}

void report_action_errors(action *act, int index)
{
    char *actions_autorized_options[] = {"max-depth", "versioning", "type"};
    char *actions_autorized_properties[] = {"name", "url"};

    for (int i = 0; i < act->option_amount; i++)
    {
        if (!is_string_in_string_array(act->options[i]->name, actions_autorized_options, 3))
        {
            printf("Dans l'action %d :", index);
            printf("\nErreur : %s n'est pas une option valide", act->options[i]->name);
        }
    }

    for (int i = 0; i < act->properties_amount; i++)
    {
        if (!is_string_in_string_array(act->properties[i]->name, actions_autorized_properties, 3))
        {
            printf("\nDans l'action %d :", index);
            printf("\nErreur : %s n'est pas une propriete valide", act->properties[i]->name);
        }
    }

    check_if_action_is_named(act, index);
}

void check_if_action_is_named(action *act, int index)
{
    int has_name = 0;
    for (int i = 0; i < act->properties_amount; i++)
    {
        if (!strcmp(act->properties[i]->name, "name"))
        {
            has_name = 1;
        }
    }
    if (has_name)
    {
        return;
    }
    printf("\nDans l'action %d", index);
    printf("\nCette action ne possède pas de propriete 'name' et ne pourra pas etre appelee.\n");
}

void report_tasks_errors(task *task, int index, action **actions, int action_amount)
{
    char *tasks_authorized_properties[] = {"name", "second", "minute", "hour"};

    for (int i = 0; i < task->properties_amount; i++)
    {
        if (!is_string_in_string_array(task->properties[i]->name, tasks_authorized_properties, 4))
        {
            printf("Dans la tache %d :", index);
            printf("\nErreur : %s n'est pas une proriete valide", task->properties[i]->name);
        }
    }

    check_action_parameter_validity(task, index, actions, action_amount);
}

void check_action_parameter_validity(task *task, int index, action **actions, int action_amount)
{
    if (task->action_amount < 0)
    {
        printf("Dans la tache %d :", index);
        printf("\nErreur : Aucun tache n'a ete trouvee\n");
    }

    for (int i = 0; i < task->action_amount; i++)
    {
        int is_in_actions_pool = 0;
        for (int j = 0; j < action_amount; j++)
        {
            char *action_name = get_action_property(actions[j], "name");
            if (action_name != NULL)
            {
                if (!strcmp(task->actions_name[i], action_name))
                {
                    is_in_actions_pool = 1;
                    break;
                }
            }
        }
        if (!is_in_actions_pool)
        {
            printf("\nDans la tache %d :", index);
            printf("\nErreur : Aucun action du nom de %s n'a ete trouvee\n", task->actions_name[i]);
        }
    }
}

char *get_action_property(action *act, char *property_name)
{
    for (int i = 0; i < act->properties_amount; i++)
    {
        if (!strcmp(act->properties[i]->name, property_name))
        {
            return act->properties[i]->value;
        }
    }
    return NULL;
}

char *get_action_option(action *act, char *option_name)
{
    for (int i = 0; i < act->option_amount; i++)
    {
        if (!strcmp(act->options[i]->name, option_name))
        {
            return act->options[i]->value;
        }
    }
    return NULL;
}

true_parameters *generate_true_params(param_container *params)
{
    int action_amount = 0;
    true_parameters *true_params = malloc(sizeof(true_parameters));
    true_params->timer = 0;
    true_params->task_amount = 0;
    true_params->true_tasks = NULL;
    true_action **true_actions = generate_true_actions(params, &action_amount);
    true_task **true_tasks = generate_true_tasks(params, true_actions, action_amount, &(true_params->task_amount));
    print_true_tasks(true_tasks, true_params->task_amount);

    if (true_actions != NULL)
    {
        true_params->true_tasks = true_tasks;
    }

    return true_params;
}

true_action **generate_true_actions(param_container *params, int *amount)
{

    action **actions = params->actions;
    int action_amount = params->action_amount;

    true_action **true_actions = malloc(sizeof(true_action *) * params->action_amount);

    for (int i = 0; i < action_amount; i++)
    {
        true_action *new_true_action = fill_true_action(actions[i]);

        if (new_true_action != NULL)
        {
            true_actions[*amount] = new_true_action;
            (*amount)++;
        }
    }

    if (*amount == 0)
    {
        if (true_actions != NULL)
        {
            free(true_actions);
            return NULL;
        }
    }

    return true_actions;
}

true_action *fill_true_action(action *action)
{
    true_action *new_true_action = malloc(sizeof(true_action));
    new_true_action->types_amount = 0;
    char *action_url = get_action_property(action, "url");
    if (action_url == NULL)
    {
        free(new_true_action);
        return NULL;
    }
    else
    {
        new_true_action->url = action_url;
    }

    char *action_name = get_action_property(action, "name");
    if (action_name == NULL)
    {
        free(new_true_action);
        return NULL;
    }
    else
    {
        new_true_action->name = action_name;
    }

    char *max_depth = get_action_option(action, "max-depth");
    if (max_depth == NULL)
    {
        new_true_action->maximum_depth = 5;
    }
    else
    {
        new_true_action->maximum_depth = atoi(max_depth);
    }

    char *versioning = get_action_option(action, "versioning");
    if (versioning == NULL)
    {
        new_true_action->versioning = 0;
    }
    else
    {
        if (!strcmp(versioning, "true"))
        {
            new_true_action->versioning = 1;
        }
    }

    fill_types(new_true_action, action);

    return new_true_action;
}

void fill_types(true_action *true_act, action *act)
{
    char *types = get_action_option(act, "type");
    if (types == NULL)
    {
        true_act->types = NULL;
        true_act->types_amount = 0;
    }
    else
    {
        int error = 0;
        scutted *scut = string_cutter(&error, types, ",");
        if (error)
        {
            true_act->types = get_types(scut, &true_act->types_amount);
        }
    }
}

char **get_types(scutted *scut, int *size)
{
    char **extension_name_types = malloc(scut->size * sizeof(char *));
    for (int i = 0; i < scut->size; i++)
    {
        char *extension_name = get_extensions_from_types(scut->strings[i]);
        if (extension_name != NULL)
        {
            extension_name_types[*size] = extension_name;
            (*size)++;
        }
    }

    if ((*size) == 0)
    {
        free(extension_name_types);
        return NULL;
    }

    return extension_name_types;
}

void print_true_actions(true_action **true_actions, int amount)
{
    for (int i = 0; i < amount; i++)
    {
        printf("True action %d :\n");
        print_taction(true_actions[i]);
    }
}

void print_taction(true_action *taction)
{
    printf("nom : %s\n", taction->name);
    printf("url : %s\n", taction->url);
    printf("profondeur maximum : %d\n", taction->maximum_depth);
    printf("versioning %s\n", taction->versioning == 1 ? "active" : "desactive");
    printf("Type visé : %s\n", taction->types_amount == 0 ? "non" : "oui");
    for (int i = 0; i < taction->types_amount; i++)
    {
        printf("type %d : %s\n", i, taction->types[i]);
    }
}

true_task **generate_true_tasks(param_container *params, true_action **actions, int action_amount, int *tasks_amount)
{
    task **tasks = params->tasks;
    int amount = params->task_amount;
    true_task **true_tasks = malloc(sizeof(true_task *) * params->task_amount);
    for (int i = 0; i < amount; i++)
    {
        true_task *new_true_task = fill_true_task(tasks[i], actions, action_amount);
        if (new_true_task != NULL)
        {
            true_tasks[*tasks_amount] = new_true_task;
            (*tasks_amount)++;
        }
    }

    if (*tasks_amount == 0)
    {
        if (true_tasks != NULL)
        {
            free(true_tasks);
            return NULL;
        }
    }

    return true_tasks;
}

char *get_task_property(task *tas, char *property_name)
{
    for (int i = 0; i < tas->properties_amount; i++)
    {
        if (!strcmp(tas->properties[i]->name, property_name))
        {
            return tas->properties[i]->value;
        }
    }
    return NULL;
}

true_task *fill_true_task(task *tas, true_action **true_actions, int action_amount)
{
    true_task *new_true_task = malloc(sizeof(true_task));
    new_true_task->action_amount = 0;
    char *task_name = get_task_property(tas, "name");
    if (task_name == NULL)
    {
        task_name = "DefaultTaskName";
    }
    new_true_task->name = task_name;

    long long task_timer = get_task_timer(tas);
    new_true_task->respawn_time = task_timer;

    fill_task_with_actions(tas, new_true_task, true_actions, action_amount);

    if (new_true_task->action_amount == 0)
    {
        if (new_true_task != NULL)
        {
            free(new_true_task);
            return NULL;
        }
    }

    return new_true_task;
}

long long get_task_timer(task *tas)
{
    long long timer = 0;
    char *hour = get_task_property(tas, "hour");
    if (hour != NULL)
    {
        timer += (atoi(hour) * 3600000);
    }

    char *minute = get_task_property(tas, "minute");
    if (minute != NULL)
    {
        timer += (atoi(minute) * 60000);
    }

    char *second = get_task_property(tas, "second");
    if (second != NULL)
    {
        timer += (atoi(second) * 1000);
    }

    return timer;
}

void fill_task_with_actions(task *tas, true_task *true_tas, true_action **true_actions, int action_amount)
{
    true_tas->actions = malloc(sizeof(true_action *) * tas->action_amount);
    for (int i = 0; i < tas->action_amount; i++)
    {
        true_action *new_taction = get_action_by_action_name(tas->actions_name[i], true_actions, action_amount);
        if (new_taction != NULL)
        {
            true_tas->actions[true_tas->action_amount] = new_taction;
            true_tas->action_amount++;
        }
    }

    if (action_amount == 0)
    {
        if (true_tas->actions != NULL)
        {
            free(true_tas->actions);
        }
    }
}

true_action *get_action_by_action_name(char *action_name, true_action **true_actions, int action_amount)
{
    for (int i = 0; i < action_amount; i++)
    {
        if (!strcmp(action_name, true_actions[i]->name))
        {
            return true_actions[i];
        }
    }
    return NULL;
}

void print_true_tasks(true_task **true_tasks, int tasks_amount)
{
    for (int i = 0; i < tasks_amount; i++)
    {
        printf("True_task %d : \n", i);
        print_ttask(true_tasks[i]);
    }
}

void print_ttask(true_task *ttask)
{
    printf("name : %s\n", ttask->name);
    printf("time : %ld\n", ttask->respawn_time);
    printf("action_amount : %d\n\n", ttask->action_amount);
    print_true_actions(ttask->actions, ttask->action_amount);
}