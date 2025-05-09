#include <stdio.h>
#include <stdlib.h>

int main() {
    int *a = malloc(sizeof(int) * 10); 
    a[0] = 5;

    int *b;
    printf("%d\n", *b); 

    return 0;
}
