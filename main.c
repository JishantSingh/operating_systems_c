#include <stdio.h>
#include <unistd.h>
#include <sys/utsname.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include "chapter4/test_pid_manager.h"

void print_array(int *a) {
    int i = 0, sz = sizeof(a) / sizeof(*a);
    for (i = 0; i < sz; i++) {
        printf("%d, ", a[i]);
    }
}

int main() {
    start_tests(12);
    return 0;
}
