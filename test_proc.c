#include <signal.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

static bool conti = true;

void child_handler(int sig)
{
    conti = false;
}

int main(void)
{
    printf("My pid is \t %d\n", getpid());

    pid_t child = fork();
    if (!child) {
        signal(SIGINT, child_handler);
        pause();
    } else {
        printf("Child's pid is \t %d\n\n", child);
        printf("(Use Ctrl + C to exit)\n");
        wait(0);
    }

    return 0;
}
