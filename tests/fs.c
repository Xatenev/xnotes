#include <string.h>
#include <stdbool.h>

#define TEST_NO_MAIN

#include "../vendor/acutest.h"

#include "../src/fs.h"

#include "fs.h"

void test_fs_create_directory(void) {
    char *path = "./target/test_dir";

    TEST_CHECK(fs_create_directory(path) == true);
    TEST_CHECK(fs_create_directory(path) == false);
}

void test_fs_remove_directory(void) {
    char *path = "./target/test_dir";

    TEST_CHECK(fs_remove_directory(path) == true);
    TEST_CHECK(fs_remove_directory(path) == false);
}