#include <dirent.h>
#include <stdio.h>

void reader(const char *dir, const char ***dircont, int *count);
int search(const char **arr, char *vector, int size);