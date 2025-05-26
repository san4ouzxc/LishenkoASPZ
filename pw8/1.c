#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

int main() {
    int pipefd[2];
    if (pipe(pipefd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    int flags = fcntl(pipefd[1], F_GETFL);
    fcntl(pipefd[1], F_SETFL, flags | O_NONBLOCK);

    const int buf_size = 65536; 
    char *buffer = malloc(buf_size);
    memset(buffer, 'A', buf_size);

    ssize_t total_written = 0;

    while (1) {
        ssize_t written = write(pipefd[1], buffer, buf_size);
        if (written == -1) {
            perror("write");
            break;
        } else if (written < buf_size) {
            printf("Partial write detected! Requested: %d, Written: %zd\n", buf_size, written);
            break;
        }
        total_written += written;
    }

    printf("Total written before partial write: %zd bytes\n", total_written);

    close(pipefd[0]);
    close(pipefd[1]);
    free(buffer);

    return 0;
}
