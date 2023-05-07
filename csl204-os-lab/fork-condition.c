#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(void) {
    if(fork()==0) {
        printf("Hello from child process\n");
    }
    else {
        printf("Hello from parent process\n");
    }
    
    return 0;
}
