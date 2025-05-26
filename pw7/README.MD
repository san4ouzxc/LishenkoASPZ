# Практична робота №6
# Лiшенко О.Д.
## Варiант 11

## Завдання 1

``` 
lilpeep@avice:~/pw7 $ gcc -Wall 1.c -o 1
lilpeep@avice:~/pw7 $ ./1
lilpeep          ttyv8        Mar 22 15:16 (:0)
lilpeep@avice:~/pw7 $ 

```

## Завдання 2

``` 
lilpeep@avice:~/pw7 $ gcc -Wall 2.c -o 2
lilpeep@avice:~/pw7 $ ./2
-rwxr-xr-x  1 lilpeep  lilpeep     10584 May 19 17:42 2
-rw-r--r--  1 lilpeep  lilpeep      1982 May 19 17:41 2.c
-rwxr-xr-x  1 lilpeep  lilpeep      8880 May 19 17:40 1
-rw-r--r--  1 lilpeep  lilpeep       514 May 19 17:34 1.c

запустить заного после запуска всех кодов

```

## Завдання 3

``` 
lilpeep@avice:~/pw7 $ gcc -Wall 3.c -o 3
lilpeep@avice:~/pw7 $ ./3
Використання: ./3 <ім'я_файлу> <слово>
lilpeep@avice:~/pw7 $ ./3 2.c else
    else if (S_ISLNK(mode)) perms[0] = 'l';
    else if (S_ISCHR(mode)) perms[0] = 'c';
    else if (S_ISBLK(mode)) perms[0] = 'b';
    else if (S_ISFIFO(mode)) perms[0] = 'p';
    else if (S_ISSOCK(mode)) perms[0] = 's';
lilpeep@avice:~/pw7 $

```

## Завдання 4

``` 
lilpeep@avice:~/pw7 $ gcc -Wall 4.c -o 4
lilpeep@avice:~/pw7 $ ./4
Використання: ./4 <файл1> [файл2 ...]
lilpeep@avice:~/pw7 $ ./4 3.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Використання: %s <ім'я_файлу> <слово>\n", argv[0]);
        return 1;
    }

    const char *filename = argv[1];
    const char *search_word = argv[2];
    FILE *fp = fopen(filename, "r");
    if (!fp) {
        perror("Помилка відкриття файлу");
        return 1;
    }

    char line[1024];

--More--
    while (fgets(line, sizeof(line), fp)) {
        if (strstr(line, search_word) != NULL) {
            fputs(line, stdout);
        }
    }

    fclose(fp);
    return 0;
}
lilpeep@avice:~/pw7 $

```

## Завдання 5

``` 
lilpeep@avice:~/pw7 $ gcc -Wall 5.c -o 5
lilpeep@avice:~/pw7 $ cd ..
lilpeep@avice:~ $ ./pw7/5
./.vboxclient-clipboard.pid
./pw2/2
./pw2/3.c
./pw2/11
./pw2/2.c
./pw2/5
./pw2/12
./pw2/6
./pw2/12.c
./pw2/5.c
./pw2/4
./pw2/3
./pw2/4.c
./pw2/11.c
./pw2/6.c
./.vboxclient-seamless.pid
./.mail_aliases

…

./.vscode-oss/argv.json
./pw7/2
./pw7/2.c
./pw7/3.c
./pw7/5
./pw7/1
./pw7/1.c
./pw7/6
./pw7/4
./pw7/4.c
./pw7/5.c
./pw7/3
./pw7/6.c
./.cache/tracker/db-locale.txt
./.cache/tracker/db-version.txt
./.cache/tracker/meta.db
./.cache/tracker/meta.db-wal
./.cache/tracker/meta.db-shm
./.cache/ibus/bus/registry
./.cache/gdm/session.log
./.cache/gdm/session.log.old
./.cache/samba/gencache.tdb
./.cache/mesa_shader_cache/index
./.cache/mesa_shader_cache/marker
./.cache/dconf/user
./.login_conf
./.vboxclient-draganddrop.pid
lilpeep@avice:~ $

```

## Завдання 6

``` 
lilpeep@avice:~/pw7 $ gcc -Wall 6.c -o 6
lilpeep@avice:~/pw7 $ cd ..
lilpeep@avice:~ $ ./pw7/6
.cache
.config
.dbus
.local
.pki
.vscode-oss
pw2
pw3
pw4
pw5
pw6
pw7
lilpeep@avice:~ $ 

```

## Завдання 7

``` 
lilpeep@avice:~/pw7 $ gcc -Wall 7.c -o 7
lilpeep@avice:~/pw7 $ ./7
Ваші виконувані файли:
 - 2
Надати іншим дозвіл на читання для "2"? (y/n): y
Дозвіл на читання для інших надано: /home/lilpeep/pw7/2
 - 5
Надати іншим дозвіл на читання для "5"? (y/n): y
Дозвіл на читання для інших надано: /home/lilpeep/pw7/5
 - 1
Надати іншим дозвіл на читання для "1"? (y/n): y
Дозвіл на читання для інших надано: /home/lilpeep/pw7/1
 - 6
Надати іншим дозвіл на читання для "6"? (y/n): y
Дозвіл на читання для інших надано: /home/lilpeep/pw7/6
 - 4
Надати іншим дозвіл на читання для "4"? (y/n): y
Дозвіл на читання для інших надано: /home/lilpeep/pw7/4
 - 3
Надати іншим дозвіл на читання для "3"? (y/n): y
Дозвіл на читання для інших надано: /home/lilpeep/pw7/3
 - 7
Надати іншим дозвіл на читання для "7"? (y/n): y
Дозвіл на читання для інших надано: /home/lilpeep/pw7/7
lilpeep@avice:~/pw7 $

```

## Завдання 8

``` 
lilpeep@avice:~/pw7 $ gcc -Wall 8.c -o 8
lilpeep@avice:~/pw7 $ ./8
Видалити файл "8"? (y/n): n
Видалити файл "2"? (y/n): n
Видалити файл "8.c"? (y/n): n
Видалити файл "2.c"? (y/n): n
Видалити файл "3.c"? (y/n): n
Видалити файл "5"? (y/n): n
Видалити файл "1"? (y/n): n
Видалити файл "1.c"? (y/n): n
Видалити файл "6"? (y/n): n
lilpeep@avice:~/pw7 $ gcc -Wall 8.c -o 8
lilpeep@avice:~/pw7 $ ./8
Видалити файл "8"? (y/n): n
Видалити файл "2"? (y/n): n
Видалити файл "8.c"? (y/n): n
Видалити файл "2.c"? (y/n): n
Видалити файл "3.c"? (y/n): n
Видалити файл "5"? (y/n): n
Видалити файл "1"? (y/n): n
Видалити файл "1.c"? (y/n): n
Видалити файл "6"? (y/n): n
Видалити файл "4"? (y/n): n
Видалити файл "4.c"? (y/n): n
Видалити файл "5.c"? (y/n): n
Видалити файл "3"? (y/n): n
Видалити файл "7"? (y/n): n
Видалити файл "7.c"? (y/n): n
Видалити файл "6.c"? (y/n): n
Видалити файл "deletethisfilefortestprogram.c"? (y/n): y
Файл "deletethisfilefortestprogram.c" видалено.
lilpeep@avice:~/pw7 $ 

```

## Завдання 9

``` 
lilpeep@avice:~/pw7 $ gcc -Wall 9.c -o 9
lilpeep@avice:~/pw7 $ ./9
Час виконання: 54 мс
lilpeep@avice:~/pw7 $ 

```

## Завдання 10

``` 
lilpeep@avice:~/pw7 $ gcc -Wall 10.c -o 10
lilpeep@avice:~/pw7 $ ./10
Введіть значення n (дійсне число): 9

(а) Випадкові числа в діапазоні [0.0, 1.0]:
  0.047577
  0.071957
  0.701630
  0.560207
  0.705020

(b) Випадкові числа в діапазоні [0.0, 9.00]:
  8.282355
  6.976847
  7.882582
  4.210455
  5.700918
lilpeep@avice:~/pw7 $ 

```

## Завдання по варiанту 11

``` 
lilpeep@avice:~/pw7 $ gcc -Wall 11.c -o 11
lilpeep@avice:~/pw7 $ history > my_history.txt
lilpeep@avice:~/pw7 $ ./11
Найменш використовувані команди (1 разів):
  clear
  bash
  history
lilpeep@avice:~/pw7 $

```


