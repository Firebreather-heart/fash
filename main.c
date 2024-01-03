#include <stdio.h>
#include "tokenizer.h"
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <fash.h>
#define MAX_COMMAND_LEN 1024

char *prompt = "# ";
size_t n = 10;
char cwd[256];
int path_cnt = 0;
char **path = NULL;

/**
 * The main function which starts the whole shell
 * @cwd: The array to store the current working directory
 *
 **/
int main(int argc, char *argv[], char *env[])
{
    char *buf = NULL;
    char **args = NULL;
    char *filename = NULL;
    // puts("loading path");
    path_cnt = load_path(&path, path_cnt);
    // printf("loaded path, pathcnt => %d\n", path_cnt);
    // for (int i = 0; i < path_cnt; i++) {
    //     printf("path[%d]: %s\n", i, path[i]);
    // }

    //signal(SIGINT, handle_ctrl_c);

    while (1)
    {
        getcwd(cwd, sizeof(cwd));
        printf("\033[34m%s:%s\033[0m", cwd, prompt);
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
            else if (executeDefaultCommand(filename, args) != 0)
            {
                executeCommand(filename, args, env, path, path_cnt);
            }
        }

        free_tokens(args);
        }

    free(buf);

    return 0;
}

void handle_ctrl_c(int opr UNUSED)
{
    puts("\n");
    printf("\033[34m%s:%s\033[0m", cwd, prompt);
}