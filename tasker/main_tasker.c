#include "./supervisor.h"

int main(){
    param_container * params = create_empty_params();
    int error = fill_actions(params, "../a.sconf");
    print_full_params(params);
    return 0;
}