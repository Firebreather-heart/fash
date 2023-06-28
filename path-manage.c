#include "path-manage.h"


void add_path(const char *path){
    if (num_paths >= MAX_PATHS){
        puts("Error: Maximum number of paths reached\n");
        return;
    }

    strncpy(paths[num_paths], path, MAX_PATH_LEN - 1);
    paths[num_paths][MAX_PATH_LEN - 1] = '\0';
    num_paths++;
}


void print_paths(){
    printf("Current paths:\n");
    for (int i = 0; i < num_paths; i++){
        printf("%d: %s\n", i + 1, paths[i]);
    }
}


void save_paths(const char *filename){
    FILE *fp = fopen(filename, "w");
    if (fp == NULL){
        printf("Error: Failed to open file for writing. \n");
        return;
    }

    for (int i = 0; i < num_paths; i++){
        fprintf(fp, "%s\n", paths[i]);
    }

    fclose(fp);
    printf("Paths saved to file: %s\n", filename);
}


void load_paths(const char *filename){
    FILE *fp = fopen(filename, "r");
    if (fp == NULL){
        printf("Error: Failed to open file for reading. \n");
        return;
    }

    char path[MAX_PATH_LEN];
    while (fgets(path, MAX_PATH_LEN, fp) != NULL){
        path[strcspn(path, "\n")] = '\0';
        add_path(path);
    }

    fclose(fp);
    printf("paths loaded from file: %s\n", filename);
}