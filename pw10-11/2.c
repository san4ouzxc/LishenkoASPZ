#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        perror("fork error");
        return 1;
    } else if (pid == 0) {
        printf("Child process (PID: %d) is exiting with code 0\n", getpid());
        exit(0);
    } else {
        int status;
        wait(&status);

        if (WIFEXITED(status)) {
            printf("Exited with code %d\n", WEXITSTATUS(status));
        }
    }

    return 0;
}
