#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *who_fp, *more_fp;
    char buffer[1024];

    who_fp = popen("who", "r");
    if (who_fp == NULL) {
        perror("popen who");
        return 1;
    }

    more_fp = popen("more", "w");
    if (more_fp == NULL) {
        perror("popen more");
        pclose(who_fp);
        return 1;
    }

    while (fgets(buffer, sizeof(buffer), who_fp) != NULL) {
        fputs(buffer, more_fp);
    }

    pclose(who_fp);
    pclose(more_fp);

    return 0;
}
