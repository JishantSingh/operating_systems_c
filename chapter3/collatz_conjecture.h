//
// Created by Jishant Singh on 27/09/21.
//

#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/stat.h>        /* For mode constants */
#include <fcntl.h>           /* For O_* constants */
#include <sys/wait.h>
//#include <sys/mman.h>

#ifndef PLAYGROUND_C_COLLATZ_CONJECTURE_H
#define PLAYGROUND_C_COLLATZ_CONJECTURE_H

#endif //PLAYGROUND_C_COLLATZ_CONJECTURE_H

#define MAX_LENGTH 500
#define MAX_BUFFER_SIZE sizeof(int)*MAX_LENGTH

int collatz() {
#define SHM_NAME "shm_collatz"
    int k = 1;
    pid_t pid = fork();
    if (pid == 0) {
        do {
            printf("Enter a positive value\n");
            scanf("%d", &k);
        } while (k <= 0);
        int shm_fd = shm_open(SHM_NAME, O_CREAT | O_RDWR, 0666);
        ftruncate(shm_fd, MAX_BUFFER_SIZE);
        int *fd = (int *) mmap(NULL, MAX_BUFFER_SIZE, PROT_WRITE | PROT_READ, MAP_SHARED, shm_fd, 0);
        int count = 1;
        int i = 1;
        fd[i++] = k;
        while (k != 1) {
            if (i >= MAX_LENGTH) {
                printf("BUFFER OVERFLOW");
                return -1;
            }
            if (k % 2 == 0) k = k / 2;
            else k = 3 * k + 1;
            if (k < 0) {
                printf("Integer overflow \n");
                return -1;
            }
            fd[i++] = k;
            count++;
        }
        fd[0] = count;
        printf("child process complete\n");
    } else {
        wait(NULL);
        int shm_fd = shm_open(SHM_NAME, O_CREAT | O_RDWR, 0666);
        ftruncate(shm_fd, MAX_BUFFER_SIZE);
        int *fd = (int *) mmap(NULL, MAX_BUFFER_SIZE, PROT_WRITE | PROT_READ, MAP_SHARED, shm_fd, 0);
        int size = fd[0];
        for (int i = 1; i <= size; i++) {
            printf("%d, ", fd[i]);
        }
        shm_unlink(SHM_NAME);
    }
    return 0;

}
