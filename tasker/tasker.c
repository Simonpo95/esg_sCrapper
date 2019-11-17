#include "tasker.h"

void *(*pointer)(void *);

void task_waiter(true_task *ttask)
{
    int i = 0;
    while (1)
    {
        sleep(ttask->respawn_time / 1000);
        i++;

        char * path_name = malloc(sizeof(char) * 150);
        sprintf(path_name, "salut %d", i);
        mkdir(path_name, 0777);
    }
}

void tasker_launcher(true_parameters *params)
{
    pthread_t *thread = malloc(sizeof(thread) * params->task_amount);
    for (int i = 0; i < params->task_amount; i++)
    {
        pthread_create(thread + i, NULL, (void * (*)(void *))task_waiter, params->true_tasks[i]);
    }

    while(1)
    {
        sleep(1);
    }
}