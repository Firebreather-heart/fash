#include "tokenizer.h"

char **tokenize(char *input, ssize_t input_len)
{
    char **tokens = NULL;
    char *token = NULL;
    int token_count = 0;

    /* Replace newline with null terminator */
    input[input_len - 1] = '\0';

    /* Tokenize using space as a delimiter */
    token = strtok(input, " ");
    while (token != NULL)
    {
        token_count++;
        tokens = (char **)realloc(tokens, token_count * sizeof(char *));
        if (tokens == NULL)
        {
            perror("Memory allocation error");
            exit(EXIT_FAILURE);
        }
        tokens[token_count - 1] = token;
        token = strtok(NULL, "");
    }

    /*
     * Add a null pointer to the end of the token array
     */
    token_count++;
    tokens = (char **)realloc(tokens, token_count * sizeof(char *));
    if (tokens == NULL)
    {
        perror("Memory Allocation Error");
        exit(EXIT_FAILURE);
    }
    tokens[token_count - 1] = NULL;

    return tokens;
}

void free_tokens(char **tokens)
{
    if (tokens != NULL)
    {
        free(tokens);
    }
}

