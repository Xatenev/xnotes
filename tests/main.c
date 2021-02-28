#include "../vendor/acutest.h"

#include "fs.h"
#include "cli.h"

TEST_LIST = {
        {"cli_get_action", test_cli_get_action},
        {"fs_create_directory", test_fs_create_directory},
        {"fs_remove_directory", test_fs_remove_directory},
        {NULL,             NULL}
};