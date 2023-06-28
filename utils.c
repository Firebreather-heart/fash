#include "utils.h"

char **reader(char *dir)
{
    DIR *od = opendir(dir);
    struct dirent *entry;
    char **dircont;
    int cnt = 0;

    if (od)
    {
        while ((entry = readdir(dir)) != NULL)
        {
            dircont[cnt] = entry->d_name;
            cnt++;
        }
        closedir(dir);
        return dircont;
    }
    else
    {
        perror("An error occurred!");
        return 1;
    }
}