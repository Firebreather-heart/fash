#include <stdio.h>
#include "tokenizer.h"

#define MAX_COMMAND_LEN 1024

char *prompt = "# ";
size_t n = 10;

int main(int argc, char **argv)
{
    char cwd[256];
    char *buf = NULL;
    char **args = NULL;
    char *filename = NULL;

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

            pid_t pid = fork();

            if (pid == 0)
            {
                execve(filename, args, NULL);
                fprintf(stderr, "\033[31mE:\033[0m %s\n", strerror(errno));
                exit(EXIT_FAILURE);
            }
            else if (pid > 0)
            {
                wait(NULL);
            }
            else
            {
                fprintf(stderr, "fatal: %s\n", strerror(errno));
            }
        }

        free_tokens(args);
    }

    free(buf);
}
