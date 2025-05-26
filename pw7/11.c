#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMMANDS 1000
#define MAX_LINE 1024

typedef struct {
    char command[MAX_LINE];
    int count;
} CommandEntry;

int main() {
    FILE *fp = popen("cat my_history.txt", "r");
    if (fp == NULL) {
        perror("popen failed");
        return 1;
    }

    CommandEntry commands[MAX_COMMANDS];
    int command_count = 0;
    char line[MAX_LINE];

    while (fgets(line, sizeof(line), fp)) {
        line[strcspn(line, "\n")] = 0;  

        char number[MAX_LINE], command[MAX_LINE];
        if (sscanf(line, "%s %s", number, command) != 2) {
            continue;
        }

        int found = 0;
        for (int i = 0; i < command_count; ++i) {
            if (strcmp(commands[i].command, command) == 0) {
                commands[i].count++;
                found = 1;
                break;
            }
        }

        if (!found && command_count < MAX_COMMANDS) {
            strncpy(commands[command_count].command, command, MAX_LINE - 1);
            commands[command_count].command[MAX_LINE - 1] = '\0';
            commands[command_count].count = 1;
            command_count++;
        }
    }

    pclose(fp);

    if (command_count == 0) {
        printf("Історія команд порожня або не вдалося прочитати.\n");
        return 1;
    }

    int min_usage = commands[0].count;
    for (int i = 1; i < command_count; ++i) {
        if (commands[i].count < min_usage) {
            min_usage = commands[i].count;
        }
    }

    printf("Найменш використовувані команди (%d разів):\n", min_usage);
    for (int i = 0; i < command_count; ++i) {
        if (commands[i].count == min_usage) {
            printf("  %s\n", commands[i].command);
        }
    }

    return 0;
}
