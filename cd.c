#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "cd.h"

int change_directory(const char *path)
{
    char *resolved_path;
    // Handle ~ (home directory)
    if (path[0] == '~')
    {
        const char *home_dir = getenv("HOME");
        resolved_path = malloc(sizeof(char) * (strlen(home_dir) + strlen(path)));
        strcpy(resolved_path, home_dir);
        strcat(resolved_path, path + 1);
    }
    else
    {
        resolved_path = strdup(path);
        
    }

    // Handle -
    if (strcmp(resolved_path, "-") == 0)
    {
        const char *previous_dir = getenv("OLDPWD");
        if (previous_dir == NULL)
        {
            fprintf(stderr, "cd: OLDPWD not set\n");
            free(resolved_path);
            return 1;
        }
        printf("%s\n", previous_dir);
        chdir(previous_dir);
    }
    else
    {
        if (chdir(resolved_path) == -1)
        {
            perror("cd");
            free(resolved_path);
            return 1;
        }
    }

    // Update PWD environment variable
    char *cwd = getcwd(NULL, 0);
    if (cwd != NULL)
    {
        setenv("PWD", cwd, 1);
        free(cwd);
    }
    else
    {
        perror("cd");
        free(resolved_path);
        return 1;
    }

    // Update OLDPWD environment variable
    setenv("OLDPWD", resolved_path, 1);

    free(resolved_path);
    return 0;
}

