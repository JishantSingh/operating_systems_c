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
#include "chapter3/copy_file.h"
void print_array(int *a) {
    int i = 0, sz = sizeof(a) / sizeof(*a);
    for (i = 0; i < sz; i++) {
        printf("%d, ", a[i]);
    }
}

int main() {
//    reverse_string("hIm");
    copy_file("/tmp/tmp.d9Owzev49p/resources/input.txt","/tmp/tmp.d9Owzev49p/resources/output.txt");
//    FILE *file;
//    char c;
//
//    file=fopen("/tmp/tmp.d9Owzev49p/resources/my.txt", "w");
//
//    for (c = 'a' ; c <= 'z' ; c++) {
//        putc (c , file);
//    }
//    fclose (file);
    return 0;

    return 0;
}
