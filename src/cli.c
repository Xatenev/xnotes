#include <string.h>

#include "cli.h"
#include "list.h"

Action cli_get_action(char *argv[]) {
    Action actions[] = {
            {"list", list}
    };

    Action activeAction = {NULL, NULL};
    for (size_t i = 0; i < sizeof(actions) / sizeof(actions[0]); i++) {
        Action action = actions[i];
        if (strcmp(action.key, argv[1]) == 0) {
            activeAction = action;
            break;
        }
    }

    return activeAction;
}