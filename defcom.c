#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include "cd.h"

int executeDefaultCommand(char *command, char *args){
    if (strcmp(command, "addpath") == 0){
        printf("Adding directory to path...\n");
        return 1;
    }
    else if (strcmp(command, "cd") == 0)
    {
        change_directory(args);
        return 1;
    }
}

void executeCommand(char *binf, char **args)
{
    char basepath[100] = "./fbin/";
    strcat(basepath, binf);
    execve(basepath, args, NULL);
}
