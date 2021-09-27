#include <stdio.h>
#include <unistd.h>
#include <sys/utsname.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include "programs/rough.h"
#include "chapter3/zombie_child.h"
#include "chapter3/pid_manager.h"
#include "chapter3/collatz_conjecture.h"
#include "chapter3/string_reverse.h"
void print_array(int *a) {
    int i = 0, sz = sizeof(a) / sizeof(*a);
    for (i = 0; i < sz; i++) {
        printf("%d, ", a[i]);
    }
}

int main() {
    reverse_string("hIm");

    return 0;
}
