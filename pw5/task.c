#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *data = malloc(10);
    if (data == NULL) {
        perror("malloc failed");
        return 1;
    }

    strcpy(data, "zxcursed");
    printf("Before realloc: %s\n", data);

    char *temp = realloc(data, 1024*1024*1024*10);  

    if (temp == NULL) {
        printf("ERROR: realloc failed. Data is now lost.\n");
        free(data);  
        return 1;
    }

    data = temp;
    printf("After realloc: %s\n", data);  

    free(data);
    return 0;
}
