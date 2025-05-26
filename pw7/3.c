#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Використання: %s <ім'я_файлу> <слово>\n", argv[0]);
        return 1;
    }

    const char *filename = argv[1];
    const char *search_word = argv[2];
    FILE *fp = fopen(filename, "r");
    if (!fp) {
        perror("Помилка відкриття файлу");
        return 1;
    }

    char line[1024];

    while (fgets(line, sizeof(line), fp)) {
        if (strstr(line, search_word) != NULL) {
            fputs(line, stdout);
        }
    }

    fclose(fp);
    return 0;
}
