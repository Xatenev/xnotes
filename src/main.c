#include <stdio.h>
#include <stdlib.h>

#include "cli.h"

int main(int argc, char *argv[]) {
    App app = {
            .argc = argc,
            .argv = argv
    };

    Action action = cli_get_action(argc, argv);

    if (!action.call) {
        cli_usage(&app);
        return 0;
    }

    action.call(&app);

    return 0;
}