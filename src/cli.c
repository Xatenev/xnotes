#include <stdio.h>
#include <string.h>

#include "cli.h"
#include "list.h"

void cli_usage(void) {
    puts("Usage: "KGRN "xn " KRED "[action]" KNRM "\n\n"
         "Available actions: \n"
         KRED "\tlist " KNRM "- " KGRN "List all ");
}

Action cli_get_action(int argc, char *argv[]) {
    Action actions[] = {
            {"list", list}
    };

    Action activeAction = {NULL, NULL};

    if(argc == 0 || argc == 1) {
        return activeAction;
    }

    for (size_t i = 0; i < sizeof(actions) / sizeof(actions[0]); i++) {
        Action action = actions[i];
        if (strcmp(action.key, argv[1]) == 0) {
            activeAction = action;
            break;
        }
    }

    return activeAction;
}