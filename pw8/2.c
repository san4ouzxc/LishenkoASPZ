#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    const char *filename = "test.bin";
    unsigned char data[] = {4, 5, 2, 2, 3, 3, 7, 9, 1, 5};

    int fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd < 0) {
        perror("open for writing");
        return 1;
    }
    write(fd, data, sizeof(data));
    close(fd);

    fd = open(filename, O_RDONLY);
    if (fd < 0) {
        perror("open for reading");
        return 1;
    }

    if (lseek(fd, 3, SEEK_SET) == -1) {
        perror("lseek");
        close(fd);
        return 1;
    }

    unsigned char buffer[4];
    ssize_t bytes_read = read(fd, buffer, 4);
    if (bytes_read < 0) {
        perror("read");
        close(fd);
        return 1;
    }

    printf("Read %zd bytes:\n", bytes_read);
    for (int i = 0; i < bytes_read; i++) {
        printf("Byte %d: %d\n", i, buffer[i]);
    }

    close(fd);
    return 0;
}
