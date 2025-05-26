#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Виконуємо whoami:\n");
    system("whoami");

    printf("\nВиконуємо id:\n");
    system("id");

    return 0;
}
