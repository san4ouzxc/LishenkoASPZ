#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main() {
    size_t size = 1024 * 1024 * 1024; 
    void *ptr = malloc(size);         

    if (!ptr) {
        printf("malloc failed!\n");
        return 1;
    }

    printf("Allocated %zu bytes at %p\n", size, ptr);

    size_t new_size = SIZE_MAX;  
    void *new_ptr = realloc(ptr, new_size);

    if (!new_ptr) {
        printf("realloc failed! Memory not reallocated\n");
        free(ptr);  
    } else {
        printf("Reallocated %zu bytes at %p\n", new_size, new_ptr);
        free(new_ptr);
    }

    return 0;
}
