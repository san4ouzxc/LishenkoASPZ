#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define UID_THRESHOLD 1000  

int main() {
    FILE *fp;
    char line[1024];
    int current_uid = getuid();  
    int found = 0;

    fp = popen("getent passwd", "r");
    if (fp == NULL) {
        perror("popen");
        return 1;
    }

    printf("Звичайні користувачі в системі (UID > %d), окрім вас (UID %d):\n", UID_THRESHOLD, current_uid);

    while (fgets(line, sizeof(line), fp) != NULL) {
        char *username = strtok(line, ":");
        strtok(NULL, ":"); 
        char *uid_str = strtok(NULL, ":");
        int uid = atoi(uid_str);

        if (uid >= UID_THRESHOLD && uid != current_uid) {
            printf("  - %s (UID: %d)\n", username, uid);
            found = 1;
        }
    }

    pclose(fp);

    if (!found) {
        printf("  Немає інших звичайних користувачів.\n");
    }

    return 0;
}
