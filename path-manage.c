#include "path-manage.h"
#include <string.h>
#include <stdlib.h>

/**
 * Loads the environment variable PATH into the given path array.
 * 
 * @param path The array to store the path elements.
 * @param pathcnt The count of the number of path elements.
 * @return The updated count of path elements.
 */
int load_path(char*** path, int pathcnt) {
    char* env_path = getenv("PATH");
    if (env_path == NULL) {
        return pathcnt;
    }

    char* env_path_copy = strdup(env_path);
    char* token = strtok(env_path_copy, ":");
    while (token != NULL) {
        *path = realloc(*path, sizeof(char *) * (pathcnt + 1));
        (*path)[pathcnt] = strdup(token);
        pathcnt++;
        token = strtok(NULL, ":");
    }
    free(env_path_copy);
    return pathcnt;
}

