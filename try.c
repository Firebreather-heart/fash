#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    pid_t pid = getpid();
    printf("PID: %d\n", pid);
    
    pid_t chpid = fork();
    if (chpid == 0)
    {
        puts("child here");
        printf("Child PID: %d\n", getpid());
    }
    else
    {
        printf("Parent PID: %d\n", getpid());
        printf("Child PID: %d\n", chpid);
    }
}