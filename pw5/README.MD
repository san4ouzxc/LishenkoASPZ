# Практична робота №4
# Лiшенко О.Д.
## Варiант 11
## Завдання 
```
Створіть ситуацію, в якій використання realloc() призводить до втрати даних, якщо неправильно обробити результат виклику.
```


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
