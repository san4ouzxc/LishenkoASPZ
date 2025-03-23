# Практична робота №4
# Лiшенко О.Д.
## Завдання 1

Максимальний обсяг пам'яті для malloc(3) на 64-бітних системах теоретично дорівнює 16 ексабайт (2^64 байт), але практично обмежується апаратними та операційними системами, що значно зменшує доступний обсяг пам'яті.

``` 
lilpeep@avice:~/pw4 $ gcc 1.c -o 1
lilpeep@avice:~/pw4 $ ./1
Спроба виділити 18446744073709551615 байт пам'яті...
malloc(3) провалився: неможливо виділити 18446744073709551615 байт
malloc(3) виділив(крок 1 ГБ) на 140040629911552 байтах (130423.00 ГБ)
lilpeep@avice:~/pw4 $ gcc 1.c -m32 -o 1
lilpeep@avice:~/pw4 $ ./1
Спроба виділити 4294967295 байт пам'яті...
malloc(3) провалився: неможливо виділити 4294967295 байт
malloc(3) виділив(крок 1 ГБ) на 3221225472 байтах (3.00 ГБ)
lilpeep@avice:~/pw4 $

```

## Завдання 2

Програма перевіряє поведінку функції `malloc` при передачі від'ємного аргументу та переповнення при множенні двох цілих чисел. 

Якщо передати від'ємний аргумент у `malloc(3)`, то функція поверне NULL, оскільки неможливо виділити пам'ять з від'ємним розміром. 

Також в програмі реалізовано множення і результат множення призводить до переповнення, і значення num стане від'ємним. В обох випадках, `malloc` поверне `NULL`, оскільки запитаний розмір пам'яті буде некоректним або занадто великим для системи.

Програма працюватиме аналогічно на архітектурах `x86_64` і `x86`, але на 32-бітній архітектурі обмеження на розмір пам'яті будуть меншими.

Помилки виникають через те, що від'ємні значення передаються як надто великі додатні числа в `malloc`, а переповнення цілої змінної призводить до некоректних результатів.

``` 
lilpeep@avice:~/pw4 $ gcc 2.c -o 2
2.c: In function 'main':
2.c:8:17: warning: argument 1 value '18446744073709551516' exceeds maximum object size 9223372036854775807 [-Walloc-size-larger-than=]
lilpeep@avice:~/pw4 $ gcc 2.c -o 2
2.c: In function 'main':
2.c:8:17: warning: argument 1 value '18446744073709551516' exceeds maximum object size 9223372036854775807 [-Walloc-size-larger-than=]
    8 |     void *ptr = malloc(-100);
      |                 ^~~~~~~~~~~~
In file included from 2.c:2:
/usr/include/stdlib.h:105:10: note: in a call to allocation function 'malloc' declared here
  105 | void    *malloc(size_t) __malloc_like __result_use_check __alloc_size(1);
      |          ^~~~~~
lilpeep@avice:~/pw4 $ ./2
Передача від'ємного аргументу в malloc(3)
malloc(-100) повернув NULL

Переповнення при множенні
Результат num = 1000000 * 1000000 = -727379968
Сталося переповнення. num став від'ємним.
malloc(-727379968) повернув NULL
lilpeep@avice:~/pw4 $ gcc 2.c -m32 -o 2
2.c: In function 'main':
2.c:8:17: warning: argument 1 value '4294967196' exceeds maximum object size 2147483647 [-Walloc-size-larger-than=]
    8 |     void *ptr = malloc(-100);
      |                 ^~~~~~~~~~~~
In file included from 2.c:2:
/usr/include/stdlib.h:105:10: note: in a call to allocation function 'malloc' declared here
  105 | void    *malloc(size_t) __malloc_like __result_use_check __alloc_size(1);
      |          ^~~~~~
lilpeep@avice:~/pw4 $ ./2
Передача від'ємного аргументу в malloc(3)
malloc(-100) повернув NULL

Переповнення при множенні
Результат num = 1000000 * 1000000 = -727379968
Сталося переповнення. num став від'ємним.
malloc(-727379968) повернув NULL


```
 



## Завдання 3

При виклику malloc(0) програма повертає ненульовий вказівник `(у даному випадку 0x3de56e208008)`.

Команда `ltrace` не доступна в `FreeBSD`, тому було використано `ktrace` та `kdump | grep malloc`, за допомогою яких можна перевірити, як саме викликаються функції `malloc` та інші системні виклики в процесі виконання програми.

``` 
lilpeep@avice:~/pw4 $ gcc 3.c -o 3
lilpeep@avice:~/pw4 $ ktrace -i ./3
Тест malloc(0)
malloc(0) повернув вказівник: 0x3de56e208008
free(ptr) виконано успішно
lilpeep@avice:~/pw4 $ kdump | grep malloc
  9630 3        NAMI  "/etc/malloc.conf"
       0x0000 d0a2 d0b5 d181 d182 206d 616c 6c6f 6328 3029  |........ malloc(0)|
       0x0000 6d61 6c6c 6f63 2830 2920 d0bf d0be d0b2 d0b5  |malloc(0) ........|
lilpeep@avice:~/pw4 $ 

```



## Завдання 4

Проблема в тому, що вказівник ptr після виклику `free(ptr)` залишається недійсним, і на наступній ітерації циклу програма намагається знову використовувати цей вказівник.

Це призводить до того, що вказівник `ptr` не можна використовувати після звільнення пам'яті.

Для виправлення програми після виклику `free(ptr)` вказівник потрібно обнулити `ptr = NULL`
``` 
lilpeep@avice:~/pw4 $ gcc 4_1.c -o 4_1
lilpeep@avice:~/pw4 $ ./4_1
Iteration 0: ptr = 0x207bde609000
After free: ptr = 0x207bde609000
Iteration 1: ptr = 0x207bde609000
After free: ptr = 0x207bde609000
Iteration 2: ptr = 0x207bde609000
After free: ptr = 0x207bde609000
lilpeep@avice:~/pw4 $ gcc 4_2.c -o 4_2
lilpeep@avice:~/pw4 $ ./4_2
Iteration 0: ptr = 0x382934c09000
After free: ptr = 0x0
Iteration 1: ptr = 0x382934c09000
After free: ptr = 0x0
Iteration 2: ptr = 0x382934c09000
After free: ptr = 0x0

```



## Завдання 5

Якщо `realloc(3)` не зможе виділити пам'ять, він поверне `NULL`, і вказівник на стару пам'ять залишиться недійсним. 

У тестовому випадку, виведення програми показує, що операція `realloc` не вдалася, і пам'ять не була перевиділена, що підтверджується повідомленням `"realloc failed! Memory not reallocated"`.

``` 
lilpeep@avice:~/pw4 $ gcc 5.c -o 5
lilpeep@avice:~/pw4 $ ./5
Allocated 1073741824 bytes at 0x359868a007c0
realloc failed! Memory not reallocated
lilpeep@avice:~/pw4 $ 

```



## Завдання 6

Якщо викликати `realloc(NULL, size)`, це еквівалентно виклику `malloc(size)`, тобто виділяється пам'ять.

Якщо викликати `realloc(ptr, 0)`, пам'ять звільняється.

``` 
lilpeep@avice:~/pw4 $ gcc 6.c -o 6
lilpeep@avice:~/pw4 $ ./6
Викликаємо realloc(NULL, 1024):
realloc(NULL, 1024) = 0x23dde1a13000
Викликаємо realloc(ptr, 0):
realloc(ptr, 0) = 0x23dde1a08008
lilpeep@avice:~/pw4 $ 

```

## Завдання 7

Використано `reallocarray(3)` у написаному коді.

Замість `ltrace` використано 

`ktrace -i ./7`

`kdump | grep malloc`

`kdump | grep realloc`

`kdump | grep munmap`

для дослідження програми.

``` 
lilpeep@avice:~/pw4 $ gcc 7.c -o 7
lilpeep@avice:~/pw4 $ ./7
Memory allocated for 1000 elements
Memory reallocated to 500 elements
lilpeep@avice:~/pw4 $ ktrace -i ./7
Memory allocated for 1000 elements
Memory reallocated to 500 elements
lilpeep@avice:~/pw4 $ kdump | grep malloc
 10342 7        NAMI  "/etc/malloc.conf"
lilpeep@avice:~/pw4 $ kdump | grep realloc
       "Memory reallocated to 500 elements
lilpeep@avice:~/pw4 $ kdump | grep munmap
 10342 7        CALL  munmap(0x8216b8000,0x1000)
 10342 7        RET   munmap 0

```


## Завдання 8
### Варіант 11. 

Програма перевіряє фрагментацію heap, виділяючи та звільняючи пам'ять через кілька етапів, що може призвести до фрагментації пам'яті.

Таким чином перевіряється фрагментація heap при виділенні/звільненні пам’яті.

Проаналізовано за допомогою команд:

`ktrace -i ./8` — для відслідковування викликів системних функцій.

`kdump | grep malloc` — для фільтрації та перегляду викликів функцій `malloc` і інших функцій виділення/звільнення пам'яті.


``` 
lilpeep@avice:~/pw4 $ ktrace -i ./8
Step 1: Allocating small blocks...
Step 2: Freeing half of them randomly...
Step 3: Allocating large blocks...
Large blocks allocated at 0x14f91cf0d000 and 0x14f91cf2e500
Heap fragmentation test complete.
lilpeep@avice:~/pw4 $ kdump | grep malloc
 10437 8        NAMI  "/etc/malloc.conf"
lilpeep@avice:~/pw4 $ kdump | grep -E 'malloc|free|mmap|munmap|brk|sbrk'
 10437 8        CALL  mmap(0,0x21000,0x3<PROT_READ|PROT_WRITE>,0x1002<MAP_PRIVATE|MAP_ANON>,0xffffffff,0)
 10437 8        RET   mmap 23060159660032/0x14f91ca00000
 10437 8        CALL  mmap(0,0x1000,0x1<PROT_READ>,0x40002<MAP_PRIVATE|MAP_PREFAULT_READ>,0x3,0)
 10437 8        RET   mmap 34959630336/0x823c1a000
 10437 8        CALL  mmap(0,0x303000,0<PROT_NONE>,0x2000<MAP_GUARD>,0xffffffff,0)
 10437 8        RET   mmap 34937425920/0x8226ed000
 10437 8        CALL  mmap(0x8226ed000,0x85000,0x1<PROT_READ>,0x60012<MAP_PRIVATE|MAP_FIXED|MAP_NOCORE|MAP_PREFAULT_READ>,0x3,0)
 10437 8        RET   mmap 34937425920/0x8226ed000
 10437 8        CALL  mmap(0x822772000,0x14b000,0x5<PROT_READ|PROT_EXEC>,0x60012<MAP_PRIVATE|MAP_FIXED|MAP_NOCORE|MAP_PREFAULT_READ>,0x3,0x84000)
 10437 8        RET   mmap 34937970688/0x822772000
 10437 8        CALL  mmap(0x8228bd000,0xa000,0x3<PROT_READ|PROT_WRITE>,0x40012<MAP_PRIVATE|MAP_FIXED|MAP_PREFAULT_READ>,0x3,0x1ce000)
 10437 8        RET   mmap 34939326464/0x8228bd000
 10437 8        CALL  mmap(0x8228c7000,0x7000,0x3<PROT_READ|PROT_WRITE>,0x40012<MAP_PRIVATE|MAP_FIXED|MAP_PREFAULT_READ>,0x3,0x1d7000)
 10437 8        RET   mmap 34939367424/0x8228c7000
 10437 8        CALL  mmap(0x8228ce000,0x122000,0x3<PROT_READ|PROT_WRITE>,0x1012<MAP_PRIVATE|MAP_FIXED|MAP_ANON>,0xffffffff,0)
 10437 8        RET   mmap 34939396096/0x8228ce000
 10437 8        CALL  munmap(0x823c1a000,0x1000)
 10437 8        RET   munmap 0
 10437 8        NAMI  "/etc/malloc.conf"
 10437 8        CALL  mmap(0,0x200000,0x3<PROT_READ|PROT_WRITE>,0x15001002<MAP_PRIVATE|MAP_ANON|MAP_ALIGNED(21)>,0xffffffff,0)
 10437 8        RET   mmap 23060161757184/0x14f91cc00000
 10437 8        CALL  mmap(0,0x200000,0x3<PROT_READ|PROT_WRITE>,0xc001002<MAP_PRIVATE|MAP_ANON|MAP_ALIGNED(12)>,0xffffffff,0)
 10437 8        RET   mmap 23060163854336/0x14f91ce00000
 10437 8        CALL  mmap(0,0x600000,0x3<PROT_READ|PROT_WRITE>,0x15001002<MAP_PRIVATE|MAP_ANON|MAP_ALIGNED(21)>,0xffffffff,0)
 10437 8        RET   mmap 23060165951488/0x14f91d000000
lilpeep@avice:~/pw4 $ 

```
