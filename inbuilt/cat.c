#include <stdio.h>

int main(int argc, char *argv[]){
    char buf[256];
    FILE *file = fopen(argv[1], "r");
    if (file == NULL){
        perror("Could not open file");
    }
    while(fgets(buf, sizeof(buf), file)){
        printf("%s", buf);
    }
    fclose(file);
}