#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Тест malloc(0)\n");

    void *ptr = malloc(0);  

    if (ptr == NULL) {
        printf("malloc(0) повернув NULL\n");
    } else {
        printf("malloc(0) повернув вказівник: %p\n", ptr);
        free(ptr);  
        printf("free(ptr) виконано успішно\n");
    }

    return 0;
}
