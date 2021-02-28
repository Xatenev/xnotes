#include <stdio.h>

#include "cli.h"

int main(int argc, char *argv[]) {
    if(argc == 0) {
        return 0;
    }

    Action action = cli_get_action(argv);

    printf("%s", action.key);
    return 0;
}