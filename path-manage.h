#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_PATHS 100
#define MAX_PATH_LEN 512

static char paths[MAX_PATHS][MAX_PATH_LEN];
static int num_paths = 0;

/*
 * add_path is called to add a new directory to path
 * @path: is a pointer to the directory string char
 */
void add_path(const char *);

/*
 * print_paths prints all the directories that have been added to path
 */
void print_paths();

/*
 * save paths function is used to persist the directories in path to a file
 * @filename: is a pointer to the filename string char
 */
void save_paths(const char *);

/*
 * load_paths is called upon startup to load the directory names
 * in the saved pathfile into memory
 */
void load_paths(const char *);
