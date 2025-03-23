#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <limits.h>

int main() {
    printf("Передача від'ємного аргументу в malloc(3)\n");
    void *ptr = malloc(-100);
    if (ptr == NULL) {
        printf("malloc(-100) повернув NULL\n");
    } else {
        free(ptr);
    }

    printf("\nПереповнення при множенні\n");

    int xa = 1000000;
    int xb = 1000000;
    int num = xa * xb;  

    printf("Результат num = %d * %d = %d\n", xa, xb, num);

    if (num < 0) {
        printf("Сталося переповнення. num став від'ємним.\n");
    }

    ptr = malloc(num);
    if (ptr == NULL) {
        printf("malloc(%d) повернув NULL\n", num);
    } else {
        printf("malloc(%d) успішно виділив пам'ять\n", num);
        free(ptr);
    }

    return 0;
}
