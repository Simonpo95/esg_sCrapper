#include "tasker.h"

void action_waiter(true_action taction)
{
    
}

void task_waiter(true_task *ttask)
{
    pthread_t *thread_action = malloc(sizeof(pthread_t) * ttask->action_amount * 5);
    int i = 0;
    for (i = 0; i < ttask->action_amount; i++)
    {
        pthread_create(thread_action + 1, NULL, (void *(*)(void *))action_waiter, ttask->actions[i]);
    }
    while (1)
    {
        sleep(ttask->respawn_time / 1000);
        for (i = 0; i < ttask->action_amount; i++)
        {
            pthread_create(thread_action + 1, NULL, (void *(*)(void *))action_waiter, ttask->actions[i]);
        }
    }
}

void tasker_launcher(true_parameters *params)
{
    pthread_t *thread_task = malloc(sizeof(pthread_t) * params->task_amount);
    for (int i = 0; i < params->task_amount; i++)
    {
        pthread_create(thread_task + i, NULL, (void *(*)(void *))task_waiter, params->true_tasks[i]);
    }

    while (1)
    {
        sleep(1);
    }
}