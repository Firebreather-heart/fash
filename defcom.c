#include <stdio.h>
#include <unistd.h>
#include <string.h>

void executeDefaultCommand(char *command){
    if (strcmp(command, "addpath") == 0){
        printf("Adding directory to path...\n");
    } else if (strcmp(command, "ls") == 0) {
        printf("Listing directory contents...\n");
    } else {
        printf("command not found: %s\n", command);
    }
}

void executeCommand(char *binf, char **args){
    execve(binf, args, NULL);
}