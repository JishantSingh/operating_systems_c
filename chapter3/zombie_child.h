//
// Created by Jishant Singh on 27/09/21.
//
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int create_zombie() {
    pid_t pid = fork();
    if (pid < 0) {
        printf("ERROR creating child process");
        return 1;
    }
    if (pid == 0) {
        printf("child pid is %d\n", getpid());
    } else if (pid > 0) {
        printf("sleeping");
        sleep(30);
        printf("waking up");
        wait(NULL);
    }
    return 0;
}

