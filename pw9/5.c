#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    const char *filename = "/home/lilpeep/tempfile.txt";

    int fd = open(filename, O_CREAT | O_WRONLY, 0600);
    if (fd == -1) {
        perror("open");
        return 1;
    }
    write(fd, "test", 4);
    close(fd);

    printf("Змінюємо власника та права на root:wheel, 0644\n");
    char cmd[256];
    snprintf(cmd, sizeof(cmd), "sudo chown root:wheel %s && sudo chmod 644 %s", filename, filename);
    system(cmd);

    printf("Намагаємось читати файл...\n");
    FILE *f = fopen(filename, "r");
    if (f) {
        char buffer[100];
        fgets(buffer, sizeof(buffer), f);
        printf("Прочитано: %s\n", buffer);
        fclose(f);
    } else {
        perror("fopen (read)");
    }

    printf("Намагаємось писати у файл...\n");
    f = fopen(filename, "a");
    if (f) {
        fprintf(f, "append test\n");
        fclose(f);
    } else {
        perror("fopen (write)");
    }

    return 0;
}
