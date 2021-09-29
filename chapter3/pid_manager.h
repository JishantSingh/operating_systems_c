//
// Created by Jishant Singh on 27/09/21.
//

#include <stdlib.h>

#ifndef PLAYGROUND_C_PID_MANAGER_H
#define PLAYGROUND_C_PID_MANAGER_H

#endif //PLAYGROUND_C_PID_MANAGER_H

#define MIN_PID 300
#define MAX_PID 310
#define NUM_PIDS (MAX_PID - MIN_PID +1)

int *pid_map;

int allocate_map() {
    pid_map = (int *) calloc(NUM_PIDS, sizeof(int));
    return (pid_map == NULL) ? -1 : 1;
}

int map_to_pid(int i) {
    return i + MIN_PID;
}

int map_to_index(int pid) {
    return pid - MIN_PID;
}

int allocate_pid() {
    int i = 0;
    for (i = 0; i < NUM_PIDS; i++) {
        if (pid_map[i] == 0) {
            pid_map[i] = 1;
            return map_to_pid(i);
        }
    }
    return -1;
}

int release_pid(int pid) {
    if(pid_map[map_to_index(pid)] == 1) {
        return pid_map[map_to_index(pid)] = 0;
    }
    return -1;
}