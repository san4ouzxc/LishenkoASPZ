#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int key;
    int original_position;
} Item;

void print_items(Item *arr, int n, const char *label) {
    printf("%s:\n", label);
    for (int i = 0; i < n; ++i) {
        printf("  { key: %d, pos: %d }\n", arr[i].key, arr[i].original_position);
    }
    printf("\n");
}

int compare_by_key(const void *a, const void *b) {
    const Item *ia = a;
    const Item *ib = b;
    return ia->key - ib->key;
}

int stable_compare(const void *a, const void *b) {
    const Item *ia = a;
    const Item *ib = b;
    if (ia->key != ib->key)
        return ia->key - ib->key;
    return ia->original_position - ib->original_position;
}

void my_qsort(Item *arr, int left, int right) {
    if (left >= right) return;

    int pivot = arr[(left + right) / 2].key;
    int i = left, j = right;
    while (i <= j) {
        while (arr[i].key < pivot) i++;
        while (arr[j].key > pivot) j--;
        if (i <= j) {
            Item tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++; j--;
        }
    }
    if (left < j) my_qsort(arr, left, j);
    if (i < right) my_qsort(arr, i, right);
}

int main() {
    Item original[] = {
        {5, 0}, {2, 1}, {5, 2}, {2, 3}, {5, 4}
    };
    int n = sizeof(original) / sizeof(original[0]);

    Item a[n], b[n];
    memcpy(a, original, sizeof(original));
    memcpy(b, original, sizeof(original));

    qsort(a, n, sizeof(Item), compare_by_key);
    my_qsort(b, 0, n - 1);

    print_items(original, n, "Original");
    print_items(a, n, "System qsort");
    print_items(b, n, "My qsort");

    return 0;
}
