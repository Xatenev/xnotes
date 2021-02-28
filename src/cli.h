#ifndef XNOTES_CLI_H
#define XNOTES_CLI_H

#include "app.h"

#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"
#define HT    "    "

typedef void (*ActionFunctionPointer)(App *app);

typedef struct {
    char *keys[2];
    ActionFunctionPointer call;
} Action;

void cli_usage(App *app);

Action cli_get_action(int argc, char *argv[]);

#endif
