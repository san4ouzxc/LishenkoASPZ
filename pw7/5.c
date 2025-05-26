#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>

void list_files_recursive(const char *path) {
    DIR *dir = opendir(path);
    if (!dir) {
        perror(path);
        return;
    }

    struct dirent *entry;
    char fullpath[4096];

    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
            continue;

        snprintf(fullpath, sizeof(fullpath), "%s/%s", path, entry->d_name);

        struct stat st;
        if (stat(fullpath, &st) == -1) {
            perror(fullpath);
            continue;
        }

        if (S_ISDIR(st.st_mode)) {
            list_files_recursive(fullpath);
        } else {
            printf("%s\n", fullpath);
        }
    }

    closedir(dir);
}

int main() {
    list_files_recursive(".");
    return 0;
}
