#include <stdio.h>
#include <dirent.h>

int main(int argc, char **argv)
{
    // Get the directory path from command-line argument
    char *dir_path = ".";
    if (argc > 1)
    {
        dir_path = argv[1];
    }

    // Open the directory
    DIR *dir = opendir(dir_path);
    if (dir == NULL)
    {
        perror("Unable to open directory");
        return 1;
    }

    // Read the directory entries
    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL)
    {
        printf("%s\n", entry->d_name);
    }

    // Close the directory
    closedir(dir);

    return 0;
}
