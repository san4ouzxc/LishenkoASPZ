#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        perror("fork failed");
        return 1;
    }

    printf("I am process with pid: %d, fork() returned: %d\n", getpid(), pid);

    return 0;
}
