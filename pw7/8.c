#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

#define MAX_PATH 1024

int is_regular_file(const char *path) {
    struct stat st;
    return stat(path, &st) == 0 && S_ISREG(st.st_mode);
}

int main() {
    DIR *dir = opendir(".");
    if (!dir) {
        perror("opendir");
        return 1;
    }

    struct dirent *entry;
    char fullpath[MAX_PATH];
    char answer[10];

    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
            continue;

        snprintf(fullpath, sizeof(fullpath), "./%s", entry->d_name);

        if (is_regular_file(fullpath)) {
            printf("Видалити файл \"%s\"? (y/n): ", entry->d_name);
            if (fgets(answer, sizeof(answer), stdin)) {
                if (answer[0] == 'y' || answer[0] == 'Y') {
                    if (remove(fullpath) == 0) {
                        printf("Файл \"%s\" видалено.\n", entry->d_name);
                    } else {
                        perror("Помилка видалення");
                    }
                }
            }
        }
    }

    closedir(dir);
    return 0;
}

