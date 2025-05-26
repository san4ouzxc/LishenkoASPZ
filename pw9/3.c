#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    const char *src = "/home/lilpeep/myfile.txt";
    const char *dest = "/home/lilpeep/copied_by_root.txt";

    FILE *f = fopen(src, "w");
    if (!f) {
        perror("fopen");
        return 1;
    }
    fprintf(f, "Цей файл створено звичайним користувачем.\n");
    fclose(f);
    printf("Створено файл: %s\n", src);

    char cmd[512];
    snprintf(cmd, sizeof(cmd), "sudo cp %s %s", src, dest);
    printf("Копіюємо файл через sudo...\n");
    system(cmd);

    printf("Пробуємо змінити файл %s як звичайний користувач...\n", dest);
    FILE *f2 = fopen(dest, "a");
    if (f2) {
        fprintf(f2, "Додаємо зміни від звичайного користувача.\n");
        fclose(f2);
        printf("Зміни записано (це означає, що права дозволяли це).\n");
    } else {
        perror("fopen");
        printf("Не вдалося змінити файл (немає прав?)\n");
    }


    printf("Пробуємо видалити файл...\n");
    int del = remove(dest);
    if (del == 0) {
        printf("Файл видалено успішно.\n");
    } else {
        perror("remove");
        printf("Не вдалося видалити файл (ймовірно, немає прав).\n");
    }

    return 0;
}
