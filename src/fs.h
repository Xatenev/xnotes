#ifndef XNOTES_FS_H
#define XNOTES_FS_H

#include <stdbool.h>

#ifdef _WIN32
#define FS_SLASH "\\"
#endif
#ifdef __linux__
#define FS_SLASH "/"
#endif

void fs_get_home_dir(char buf[]);

bool fs_create_directory(char *path);

#endif 
