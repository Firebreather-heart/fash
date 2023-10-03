#include <stdio.h>
#include "tokenizer.h"
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define MAX_COMMAND_LEN 1024

char *prompt = "# ";
size_t n = 10;

/**
 * The main function which starts the whole shell
 * @cwd: The array to storethe current working directory
 * 
 **/
int main(int argc, char **argv)
{
    char cwd[256];
    char *buf = NULL;
    char **args = NULL;
    char *filename = NULL;
    pid_t pid;
    int status;

    const char **ffs = NULL;
    int ffsCount = 0;
    reader("../fbin", &ffs, &ffsCount);

    while (1)
    {
        getcwd(cwd, sizeof(cwd));
        printf("\033[33m%s:%s\033[0m", cwd, prompt);
        printf("\033[?12h");
        getline(&buf, &n, stdin);

        args = tokenize(buf, strlen(buf));
        if (args[0] != NULL)
        {
            filename = args[0];

            if (strcmp(filename, "exit") == 0)
            {
                break; // Exit the program if the command is 'exit'
            }
            else if (executeDefaultCommand(filename, args) != 1)
            {

                if (search(ffs, filename, ffsCount) == 0)
                {
                    pid = fork();
                    if (pid == -1)
                        printf("fork failed");
                    else if (pid == 0)
                    {
                        executeCommand(filename, args);
                    }
                    else{
                        wait(&status);
                    }
                }
            }
            else
            {
                fprintf(stderr, "Unknown command: %s\n", filename);
            }
        }

        free_tokens(args);
    }

    free(buf);
    for (int i = 0; i < ffsCount; i++)
    {
        free(ffs[i]);
    }
    free(ffs);

    return 0;
}
