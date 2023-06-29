#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/wait.h>
#include "path-manage.h"
#include "defcom.h"
#include "utils.h"

char** tokenize(char *input, ssize_t input_len);
void free_tokens(char **tokens);
