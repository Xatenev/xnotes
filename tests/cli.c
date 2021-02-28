#include <string.h>

#define TEST_NO_MAIN

#include "../vendor/acutest.h"

#include "../src/cli.h"
#include "../src/notes.h"

#include "cli.h"

void test_cli_get_action(void) {
    int argc = 2;
    char *argv[] = {
            "./target/xn",
            "list"
    };

    Action action = cli_get_action(argc, argv);

    TEST_CHECK(strcmp(action.keys[0], "list") == 0);
    TEST_CHECK(strcmp(action.keys[1], "l") == 0);
    TEST_CHECK(action.call == notes_list);

    int argc2 = 1;
    char *argv2[]= {
            "./target/xn"
    };

    Action action2 = cli_get_action(argc2, argv2);

    TEST_CHECK(action2.keys[0] == NULL);
    TEST_CHECK(action2.keys[1] == NULL);
    TEST_CHECK(action2.call == NULL);
}