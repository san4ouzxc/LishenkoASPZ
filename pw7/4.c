#include <stdio.h>

#define LINES_PER_PAGE 20
#define LINE_LEN 1024

void wait_for_key() {
    printf("--More--");
    fflush(stdout);
    getchar();  
    printf("\r         \r");  
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Використання: %s <файл1> [файл2 ...]\n", argv[0]);
        return 1;
    }

    for (int i = 1; i < argc; i++) {
        FILE *fp = fopen(argv[i], "r");
        if (!fp) {
            perror(argv[i]);
            continue;
        }

        char line[LINE_LEN];
        int line_count = 0;

        while (fgets(line, LINE_LEN, fp)) {
            printf("%s", line);
            line_count++;

            if (line_count == LINES_PER_PAGE) {
                wait_for_key();
                line_count = 0;
            }
        }

        fclose(fp);
    }

    return 0;
}
