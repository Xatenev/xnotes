#include <stdio.h>
#include <string.h>

#include "fs.h"
#include "notes.h"

void notes_init(App *app) {
    char home[256];
    fs_get_home_dir(home);

    char defaultPath[512];
    strcpy(defaultPath, home);
    strcat(defaultPath, FS_SLASH);
    strcat(defaultPath, ".xnotes");

    printf("Enter initialization path (%s) or press enter to confirm:\n", defaultPath);
    fflush(stdout);

    char path[512];
    fgets(path, sizeof(path), stdin);

    int path_length = strlen(path);

    if(path_length == 1) { // No input, use default
        strcpy(path, defaultPath);
    }

    if(!fs_create_directory(path)) {
        printf("Xnotes has already been initialized\n");
    };
}

void notes_add(App *app) {
    puts("list");
}

void notes_remove(App *app) {
    puts("add");
}

void notes_list(App *app) {
    puts("list");
}