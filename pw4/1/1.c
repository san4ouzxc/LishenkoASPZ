#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main() {
    size_t max_size = SIZE_MAX;

    printf("Спроба виділити %zu байт пам'яті...\n", max_size);

    void *ptr = malloc(max_size);

    if (ptr == NULL) {
        printf("malloc(3) провалився: неможливо виділити %zu байт\n", max_size);
    } else {
        printf("malloc(3) успішно виділив %zu байт\n", max_size);
        free(ptr);
        return 0;
    }

    size_t step = 1L << 30; 
    size_t total = 0;

    while ((ptr = malloc(step)) != NULL) { 
        total += step;
    }

    printf("malloc(3) виділив(крок 1 ГБ) на %lu байтах (%.2f ГБ)\n", total, total / (double)(1L << 30));

    return 0;
}
