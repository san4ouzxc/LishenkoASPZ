#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

int compare_ints(const void *a, const void *b) {
    int arg1 = *(const int*)a;
    int arg2 = *(const int*)b;
    return (arg1 > arg2) - (arg1 < arg2); 
}

bool is_sorted(int *arr, size_t n) {
    for (size_t i = 1; i < n; ++i) {
        if (arr[i-1] > arr[i]) return false;
    }
    return true;
}

void fill_array(int *arr, size_t n, const char *type) {
    if (strcmp(type, "sorted") == 0) {
        for (size_t i = 0; i < n; ++i) arr[i] = i;
    } else if (strcmp(type, "reversed") == 0) {
        for (size_t i = 0; i < n; ++i) arr[i] = n - i;
    } else if (strcmp(type, "random") == 0) {
        for (size_t i = 0; i < n; ++i) arr[i] = rand() % 100000;
    } else if (strcmp(type, "identical") == 0) {
        for (size_t i = 0; i < n; ++i) arr[i] = 42;
    } else if (strcmp(type, "binary") == 0) {
        for (size_t i = 0; i < n; ++i) arr[i] = (i % 2 == 0) ? 0 : 1;
    }
}

double sort_and_time(int *arr, size_t n) {
    clock_t start = clock();
    qsort(arr, n, sizeof(int), compare_ints);
    clock_t end = clock();
    return (double)(end - start) / CLOCKS_PER_SEC;
}

int main() {
    srand(time(NULL));

    const char *patterns[] = {"sorted", "reversed", "random", "identical", "binary"};
    const size_t patterns_count = sizeof(patterns)/sizeof(patterns[0]);
    const size_t N = 100000;

    int *array = malloc(N * sizeof(int));
    if (!array) {
        perror("malloc");
        return 1;
    }

    printf("QSort performance test on %zu elements\n", N);
    printf("-----------------------------------------\n");

    for (size_t i = 0; i < patterns_count; ++i) {
        fill_array(array, N, patterns[i]);

        double time_taken = sort_and_time(array, N);
        bool sorted = is_sorted(array, N);

        printf("Pattern: %-10s | Time: %6.4f sec | Sorted: %s\n",
               patterns[i], time_taken, sorted ? "YES" : "NO");
    }

    free(array);
    return 0;
}
