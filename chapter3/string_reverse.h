//
// Created by Jishant Singh on 27/09/21.
//

#ifndef PLAYGROUND_C_STRING_REVERSE_H
#define PLAYGROUND_C_STRING_REVERSE_H

#endif //PLAYGROUND_C_STRING_REVERSE_H

#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <sys/types.h>
#include <string.h>
#include <ctype.h>
#include <sys/wait.h>


char flip_case(char c) {
    return islower(c) ? toupper(c) : tolower(c);
}

int reverse_string(char *input) {
    int fd[2];
    if (pipe(fd) != 0) {
        perror("Error occured while creating pipe");
        return 1;
    }

    pid_t pid = fork();
    if (pid == 0) {
        close(fd[0]);
        int i = 0;
        char output[strlen(input)];
        for (i = 0; i < strlen(input); i++) {
            output[i] = flip_case(input[i]);
        }
        write(fd[1], output, strlen(output));
        close(fd[1]);
        return 0;
    } else {
        printf("parent: input is: %s\n", input);
        close(fd[1]);
        int status;
        wait(&status);
        if (WEXITSTATUS(status) == 0) {
            char output[strlen(input) + 1];
            read(fd[0], output, strlen(input));
            output[strlen(input)] = '\0';
            printf("parent: output is :%s\n", output);
        } else {
            printf("Error occurred in child process\n");
        }
        close(fd[0]);

    }
    return 0;
}