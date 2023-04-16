#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/wait.h>
#include "tokenizer.h"

char *prompt = "# ";
size_t n = 10;

int main(void)
{
        char  cwd[256];
        char *buf = NULL;
        char *filename = NULL;
        char *args[20] = {0};

        while(1)
        {
                getcwd(cwd, sizeof(cwd));
                printf("%s:%s", cwd, prompt);
                getline(&buf, &n, stdin);

                tokenize(buf, &filename, args);

                if (filename != NULL){
                    pid_t pid = fork();

                    if (pid == 0){
                        printf("%s", filename);
                        execve(filename, args, NULL);
                        fprintf(stderr,"E: %s\n", strerror(errno));
                    } else if (pid > 0){

                        wait(NULL);
                    } else {
                        fprintf(stderr, "fatal: %s\n", strerror(errno));
                    }
                }
        }
       /* free(buf);*/
}
