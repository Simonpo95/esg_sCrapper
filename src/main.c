#include "./supervisor.h"

int main()
{
    char *file_name = get_scrapper_configuration_file();

    param_container *params = create_empty_params();
    int error = fill_actions(params, file_name);
    parsed_conf_file_successful(error);
    if (!error)
    {
        inform_user_about_loaded_params(params);
        ask_user_if_needed_details(params);
        ask_user_if_needed_bug_reported(params);
        int answer = ask_launch_tasks(params);
        if (answer)
        {
            true_parameters *true_params = generate_true_params(params);
            tasker_launcher(true_params);
        }
        else
        {
            printf("Nous comprenons, merci d'avoir fait usage de notre service !\n");
        }
    }

    return 0;
}