#ifndef XNOTES_CLI_H
#define XNOTES_CLI_H

#include "app.h"

typedef void (*ActionFunctionPointer)(App *app);

typedef struct {
    char *key;
    ActionFunctionPointer fp;
} Action;

Action cli_get_action(char *argv[]);

#endif
