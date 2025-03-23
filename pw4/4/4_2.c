#include <stdio.h>
#include <stdlib.h>

int main() {
    void *ptr = NULL;
    for (int i = 0; i < 3; i++) {
        if (!ptr)
            ptr = malloc(16);

        printf("Iteration %d: ptr = %p\n", i, ptr);

        free(ptr);
        ptr = NULL;  

        printf("After free: ptr = %p\n", ptr);
    }

    return 0;
}
