#include "utils.h"
#include <string.h>
#include <stdlib.h>


void reader(const char *dir, const char ***dircont, int *count)
{
    DIR *od = opendir(dir);
    struct dirent *entry;

    if (od)
    {
        *count = 0;
        *dircont = NULL;
        while ((entry = readdir(od)) != NULL)
        {
            (*count)++;
            *dircont = realloc(*dircont, (*count) * sizeof(const char *));
            (*dircont)[*count - 1] = strdup(entry->d_name);
            // printf("%s found\n", entry->d_name);
        }

        closedir(od);
    }
    else
    {
        perror("An error occurred!");
    }
}

int search(const char **arr, char *vector, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (strcmp(arr[i], vector))
        {
            return 0;
            break;
        }
    }
    return 1;
}