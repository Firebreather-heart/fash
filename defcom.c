#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include "cd.h"
#include <sys/wait.h>

int executeDefaultCommand(char *command, char **args)
{
    if (strcmp(command, "addpath") == 0)
    {
        printf("Adding directory to path...\n");
        return 0;
    }
    else if (strcmp(command, "cd") == 0)
    {
        change_directory(args[1]);
        return 0;
    }
    return 1;
}

int executeCommand(char *binf, char **args, char *env[], char **path, int path_cnt)
{
    // char basepath[100] = "../fbin/";
    // strcat(basepath, binf);

    char **t_env = malloc(sizeof(char *) * 50);
    int i = 0;
    if (t_env)
    {
        for (; t_env[i]; i++)
        {
            t_env[i] = strdup(env[i]);
        }
    }
    t_env[i] = NULL;
    env = t_env;

    pid_t pid;
    int status;
    // puts("ready to fork");
    pid = fork();
    if (pid == -1)
        printf("could not fork");
    if (pid == 0)
    {
        for (int j = 0; j < path_cnt; j++)
        {
            char temp[100];
            sprintf(temp, "%s/%s", path[j], binf);
            if (access(temp, X_OK) == F_OK)
            {
                // printf("trying: %s\n", temp);
                int res = execve(temp, args, env);
                puts("executed");
                if (res == -1)
                {
                    perror("<executeCommand error>");
                    exit(EXIT_FAILURE);
                    return 1;
                }
                break;
            }
        }
    }
    else
    {
        wait(&status);
        if (WIFEXITED(status))
        {
            errno = WEXITSTATUS(status);
        }
        else if (WIFSIGNALED(status))
            errno = 128 + WTERMSIG(status);
    }
    return 0;
}
