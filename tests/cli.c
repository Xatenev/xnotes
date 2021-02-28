#include <string.h>

#define TEST_NO_MAIN

#include "../vendor/acutest.h"

#include "../src/cli.h"
#include "../src/list.h"

#include "cli.h"

void test_cli_get_action(void) {
    char *argv[] = {
            "./target/xn",
            "list"
    };

    Action action = cli_get_action(argv);

    TEST_CHECK(strcmp(action.key, "list") == 0);
    TEST_CHECK(action.fp == list);
}