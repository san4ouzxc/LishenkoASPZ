#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid;

    pid = fork();

    if (pid < 0) {
        perror("Помилка fork");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        printf("Дочірній процес (PID: %d) виконує 'ls -l'\n", getpid());
        execlp("ls", "ls", "-l", (char *)NULL);

        perror("Помилка execlp");
        exit(EXIT_FAILURE);
    } else {
        printf("Батьківський процес (PID: %d) очікує завершення дочірнього процесу...\n", getpid());
        wait(NULL);  
        printf("Дочірній процес завершено.\n");
    }

    return 0;
}
