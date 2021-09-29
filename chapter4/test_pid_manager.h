//
// Created by Jishant Singh on 28/09/21.
//

#ifndef PLAYGROUND_C_TEST_PID_MANAGER_H
#define PLAYGROUND_C_TEST_PID_MANAGER_H

#endif //PLAYGROUND_C_TEST_PID_MANAGER_H

#include <pthread.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include "../chapter3/pid_manager.h"

int failure = 0;
struct ret_st {
    int ret_val;
};

void *test_pid_mgr() {
    pid_t pid;

    struct ret_st *ret_struct = calloc(1, sizeof(struct ret_st));
    if ((pid = allocate_pid()) != -1) {
        printf("Successfully got pid: %d\n", pid);
        sleep(2);
        if (release_pid(pid) != 0) {
            failure++;
            printf("Failed to release pid: %d\n", pid);
            (*ret_struct).ret_val = EXIT_FAILURE;
            pthread_exit((void *) ret_struct);
        }
    } else {
        printf("Failed to get a pid\n");
        failure++;
        (*ret_struct).ret_val = EXIT_FAILURE;
        pthread_exit((void *) ret_struct);
    }
    printf("Released pid: %d\n", pid);
    (*ret_struct).ret_val = EXIT_SUCCESS;
    pthread_exit((void *) ret_struct);
}

int start_tests(int num_tests) {
    if (allocate_map() == -1) return -1;
    int i = 0;
    pthread_t tid[num_tests];
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    struct ret_st *status[num_tests];
    for (i = 0; i < num_tests; i++) {
        pthread_create(&tid[i], &attr, test_pid_mgr, NULL);
    }
    for (i = 0; i < num_tests; i++) {
        int success = pthread_join(tid[i], (void **) &status[i]);
        if (success != 0) {
            printf("Error code is :%d\n", success);
            perror((const char *) &(*(status[i])).ret_val);
        }
    }
    printf("Num errors: %d\n", failure);
    return EXIT_SUCCESS;
}
