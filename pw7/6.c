#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>

int compare_strings(const void *a, const void *b) {
    const char **sa = (const char **)a;
    const char **sb = (const char **)b;
    return strcmp(*sa, *sb);
}

int main() {
    DIR *dir = opendir(".");
    if (!dir) {
        perror("opendir");
        return 1;
    }

    struct dirent *entry;
    char **dirs = NULL;
    size_t count = 0, capacity = 0;

    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
            continue;

        struct stat st;
        if (stat(entry->d_name, &st) == -1) {
            perror(entry->d_name);
            continue;
        }

        if (S_ISDIR(st.st_mode)) {
            if (count == capacity) {
                capacity = capacity ? capacity * 2 : 10;
                char **tmp = realloc(dirs, capacity * sizeof(char *));
                if (!tmp) {
                    perror("realloc");
                    free(dirs);
                    closedir(dir);
                    return 1;
                }
                dirs = tmp;
            }
            dirs[count] = strdup(entry->d_name);
            if (!dirs[count]) {
                perror("strdup");
                for (size_t i = 0; i < count; i++)
                    free(dirs[i]);
                free(dirs);
                closedir(dir);
                return 1;
            }
            count++;
        }
    }

    closedir(dir);

    qsort(dirs, count, sizeof(char *), compare_strings);

    for (size_t i = 0; i < count; i++) {
        printf("%s\n", dirs[i]);
        free(dirs[i]);
    }
    free(dirs);

    return 0;
}
