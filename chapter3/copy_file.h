//
// Created by Jishant Singh on 27/09/21.
//

#ifndef PLAYGROUND_C_COPY_FILE_H
#define PLAYGROUND_C_COPY_FILE_H

#endif //PLAYGROUND_C_COPY_FILE_H

#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <sys/types.h>
#include <string.h>
#include <ctype.h>
#include <sys/wait.h>

int copy_file(char *input_file, char *output_file) {
    int fd[2];
    if (pipe(fd) != 0) return 1;
    fork();
    FILE *file = fopen(input_file, "r");
    int c, char_count = 0;
    while ((c = getc(file)) != EOF) {
        dprintf(fd[1], "%c", c);
        char_count++;
    }
    close(fd[1]);
    fclose(file);
    pid_t pid = fork();
    if (pid == 0) {
        printf("entered child\n");
        close(fd[1]);
        char output[char_count];
        if (read(fd[0], output, char_count + 1) == -1) {
            printf("Error code %d\n", errno);
            perror("read from pipe failed\n");
            return 1;
        }
        file = fopen(output_file, "w+");
        fprintf(file, "%s", output);
        fclose(file);
        close(fd[0]);
        return 0;
    } else {
        close(fd[0]);
        wait(NULL);
    }
    return 0;

}
