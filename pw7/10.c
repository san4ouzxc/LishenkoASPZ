#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float random_0_to_1() {
    return (float)rand() / (float)RAND_MAX;
}

float random_0_to_n(float n) {
    return random_0_to_1() * n;
}

int main() {
    float n;
    int i;

    srand((unsigned int)time(NULL));

    printf("Введіть значення n (дійсне число): ");
    if (scanf("%f", &n) != 1 || n <= 0.0) {
        printf("Некоректне значення n.\n");
        return 1;
    }

    printf("\n(а) Випадкові числа в діапазоні [0.0, 1.0]:\n");
    for (i = 0; i < 5; i++) {
        printf("  %.6f\n", random_0_to_1());
    }

    printf("\n(b) Випадкові числа в діапазоні [0.0, %.2f]:\n", n);
    for (i = 0; i < 5; i++) {
        printf("  %.6f\n", random_0_to_n(n));
    }

    return 0;
}
