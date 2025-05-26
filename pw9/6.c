#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>
#include <errno.h>

void check_access(const char *filepath) {
    printf("\nФайл: %s\n", filepath);

    if (access(filepath, R_OK) == 0) {
        printf("Читання дозволено\n");
    } else {
        printf("Читання заборонено (%s)\n", strerror(errno));
    }

    if (access(filepath, W_OK) == 0) {
        printf("Запис дозволено\n");
    } else {
        printf("Запис заборонено (%s)\n", strerror(errno));
    }

    if (access(filepath, X_OK) == 0) {
        printf("Виконання дозволено\n");
    } else {
        printf("Виконання заборонено (%s)\n", strerror(errno));
    }
}

void list_and_test(const char *path, int limit) {
    printf("\nКаталог: %s\n", path);
    char cmd[512];
    snprintf(cmd, sizeof(cmd), "ls -l %s", path);
    system(cmd);

    DIR *dir = opendir(path);
    if (!dir) {
        perror("opendir");
        return;
    }

    struct dirent *entry;
    int count = 0;
    while ((entry = readdir(dir)) && count < limit) {
        if (entry->d_type == DT_REG || entry->d_type == DT_LNK || entry->d_type == DT_UNKNOWN) {
            char fullpath[1024];
            snprintf(fullpath, sizeof(fullpath), "%s/%s", path, entry->d_name);
            check_access(fullpath);
            count++;
        }
    }
    closedir(dir);
}

int main() {
    const char *home = getenv("HOME");
    if (!home) {
        fprintf(stderr, "Не вдалося визначити домашній каталог.\n");
        return 1;
    }

    list_and_test(home, 3);         // ~
    list_and_test("/usr/bin", 3);   // /usr/bin
    list_and_test("/etc", 3);       // /etc

    return 0;
}
