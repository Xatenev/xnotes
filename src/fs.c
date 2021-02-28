#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#ifdef _WIN32

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <direct.h>

#endif

#ifdef __linux__

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#endif

#include "fs.h"

void fs_get_home_dir(char buf[]) {
    strcpy(buf, getenv("HOME"));
}

bool fs_create_directory(char *path) {
    struct stat s = {0};
    int stat_result = stat(path, &s);

    printf("%d", stat_result);
    if (stat_result == -1) {
#ifdef _WIN32
        _mkdir(path);
#endif
#ifdef __linux__
        mkdir(path, 0700);
#endif

        return true;
    }

    return false;
}