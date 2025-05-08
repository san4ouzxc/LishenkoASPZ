# Практична робота №5
# Лiшенко О.Д.
## Варiант 11
## Завдання 

Створіть ситуацію, в якій використання `realloc()` призводить до втрати даних, якщо неправильно обробити результат виклику.

## Опис рішення

У рамках цього завдання була розроблена ситуація, яка демонструє можливість втрати даних при використанні функції `realloc()` в мові програмування C. Втрата даних відбувається через неправильну обробку результату виклику `realloc()`, коли програма не зберігає старий вказівник при невдачі перерозподілу пам'яті. У цьому випадку, після невдалого виклику функції `realloc()`, пам'ять залишається зайнятою, але вказівник на старі дані втрачається.

Ключові бібліотеки:

`stdlib.h:` Включає в себе функції для роботи з пам'яттю, такі як `malloc()`, `free()` та `realloc()`. Функція `realloc()` дозволяє змінити розмір уже виділеного блоку пам'яті.

`string.h:` Містить функцію `strcpy()`, яка копіює рядки, що використовується для запису даних у виділений блок пам'яті.


## Запуск програми
``` 
lilpeep@avice:~/pw5 $ gcc task.c -o task
task.c: In function 'main':
task.c:15:46: warning: integer overflow in expression of type 'int' results in '-2147483648' [-Woverflow]
   15 |     char *temp = realloc(data, 1024*1024*1024*10);
      |                                              ^
task.c:15:18: warning: argument 2 value '18446744071562067968' exceeds maximum object size 9223372036854775807 [-Walloc-size-larger-than=]
   15 |     char *temp = realloc(data, 1024*1024*1024*10);
      |                  ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
In file included from task.c:2:
/usr/include/stdlib.h:112:10: note: in a call to allocation function 'realloc' declared here
  112 | void    *realloc(void *, size_t) __result_use_check __alloc_size(2);
      |          ^~~~~~~
lilpeep@avice:~/pw5 $ ./task
Before realloc: zxcursed
ERROR: realloc failed. Data is now lost.
lilpeep@avice:~/pw5 $ 

```
