#include <stdio.h>
#include <string.h>

#include "cli.h"
#include "notes.h"

void cli_usage(App *app) {
    printf(KGRN "%s " KRED "[action]" KNRM "\n\n"
         "Available actions: \n"
         KRED HT "help   [h] " KNRM "- " KGRN "Display usage help\n"
         KRED HT "init   [i] " KNRM "- " KGRN "Initialize notes directory\n"
         KRED HT "add    [a] " KNRM "- " KGRN "Add entry\n"
         KRED HT "remove [r] " KNRM "- " KGRN "Remove entry\n"
         KRED HT "list   [l] " KNRM "- " KGRN "List entries\n"
         , app->argv[0]);
}

Action cli_get_action(int argc, char *argv[]) {
    Action actions[] = {
            {{"help", "h"}, cli_usage},
            {{"init", "i"}, notes_init},
            {{"add", "a"}, notes_add},
            {{"remove", "r"}, notes_remove},
            {{"list", "l"}, notes_list}
    };

    Action activeAction = {{NULL, NULL}, NULL};

    if(argc == 0 || argc == 1) {
        return activeAction;
    }

    for (size_t i = 0; i < sizeof(actions) / sizeof(actions[0]); i++) {
        Action action = actions[i];
        if (strcmp(action.keys[0], argv[1]) == 0 || strcmp(action.keys[1], argv[1]) == 0) {
            activeAction = action;
            break;
        }
    }

    return activeAction;
}