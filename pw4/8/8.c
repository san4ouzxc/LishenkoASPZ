#define _GNU_SOURCE  
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BLOCKS 1000
#define SMALL_SIZE 1024  // 1 KB
#define LARGE_SIZE 128 * 1024  // 128 KB

int main() {
    void *pointers[BLOCKS] = {0};

    printf("Step 1: Allocating small blocks...\n");
    for (int i = 0; i < BLOCKS; i++) {
        pointers[i] = malloc(SMALL_SIZE);
        if (!pointers[i]) {
            perror("malloc failed");
            return 1;
        }
    }

    printf("Step 2: Freeing half of them randomly...\n");
    for (int i = 0; i < BLOCKS; i += 2) {
        free(pointers[i]);
        pointers[i] = NULL;
    }

    printf("Step 3: Allocating large blocks...\n");
    void *large_block1 = malloc(LARGE_SIZE);
    void *large_block2 = malloc(LARGE_SIZE);

    if (!large_block1 || !large_block2) {
        perror("malloc failed for large blocks");
    } else {
        printf("Large blocks allocated at %p and %p\n", large_block1, large_block2);
    }

    printf("Heap fragmentation test complete.\n");

    free(large_block1);
    free(large_block2);

    for (int i = 0; i < BLOCKS; i++) {
        free(pointers[i]);
    }

    return 0;
}
