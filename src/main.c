#include <stdio.h>

#include "cli.h"

int main(int argc, char *argv[]) {
    if(argc == 1) {
        cli_usage();
        return 0;
    }

    Action action = cli_get_action(argc, argv);

    action.fp();

    return 0;
}