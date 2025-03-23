#include <stdio.h>
#include <stdlib.h>

int main() {
    size_t size = 1024; // 1 КБ
    
    printf("Викликаємо realloc(NULL, %zu)...\n", size);
    void *ptr = realloc(NULL, size);
    printf("realloc(NULL, %zu) Успішно виділено %zu байт за адресою %p\n", size, ptr);


    printf("Викликаємо realloc(ptr, 0)...\n");
    void *new_ptr = realloc(ptr, 0);

    if (new_ptr == NULL) {
        printf("realloc(ptr, 0) повернув NULL (еквівалент free(ptr))\n");
    } else {
        printf("realloc(ptr, 0) повернув %p (поведінка залежить від реалізації)\n", new_ptr);
    }

    return 0;
}
