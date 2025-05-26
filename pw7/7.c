#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_PATH 1024

int is_executable(const char *path) {
    return access(path, X_OK) == 0;
}

int is_regular_file(const char *path) {
    struct stat st;
    return stat(path, &st) == 0 && S_ISREG(st.st_mode);
}

void add_read_permission_for_others(const char *path) {
    struct stat st;
    if (stat(path, &st) != 0) {
        perror("stat");
        return;
    }

    mode_t new_mode = st.st_mode | S_IROTH;

    if (chmod(path, new_mode) != 0) {
        perror("chmod");
    } else {
        printf("Дозвіл на читання для інших надано: %s\n", path);
    }
}

int main() {
    char cwd[MAX_PATH];
    if (getcwd(cwd, sizeof(cwd)) == NULL) {
        perror("getcwd");
        return 1;
    }

    DIR *dir = opendir(cwd);
    if (!dir) {
        perror("opendir");
        return 1;
    }

    struct dirent *entry;
    printf("Ваші виконувані файли:\n");

    while ((entry = readdir(dir)) != NULL) {
        char fullpath[MAX_PATH];
        snprintf(fullpath, sizeof(fullpath), "%s/%s", cwd, entry->d_name);

        if (is_regular_file(fullpath) && is_executable(fullpath)) {
            printf(" - %s\n", entry->d_name);
            printf("Надати іншим дозвіл на читання для \"%s\"? (y/n): ", entry->d_name);
            char answer[10];
            if (fgets(answer, sizeof(answer), stdin)) {
                if (answer[0] == 'y' || answer[0] == 'Y') {
                    add_read_permission_for_others(fullpath);
                }
            }
        }
    }

    closedir(dir);
    return 0;
}
