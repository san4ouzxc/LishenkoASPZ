# Практична робота №6
# Лiшенко О.Д.
## Варiант 11
## Завдання 

Порівняйте звіти `Valgrind` з параметрами `--leak-check=no`, `summary-only`, `--track-origins=yes`. Опишіть, які саме помилки приховуються або виявляються.

## Опис рішення

Для виконання завдання було скомпільовано програму з відлагоджувальною інформацією за допомогою команди `gcc -g task.c -o task`. Далі ця програма запускалась з використанням інструменту `Valgrind` з трьома різними наборами параметрів для порівняння результатів.

Перший запуск відбувся з параметром `--leak-check=no`, який не перевіряє наявність витоків пам’яті, а лише повідомляє про критичні помилки під час виконання, наприклад, використання неініціалізованих змінних або звернення до неіснуючої пам’яті.

Другий запуск було виконано з параметром `--leak-check=summary`, який надає коротке зведення по витоках пам’яті: скільки байт було втрачено, скільки все ще доступно, і які типи витоків були виявлені (наприклад, still reachable, definitely lost).

Третій запуск було здійснено з параметром `--track-origins=yes`, який дозволяє `Valgrind` показати точне місце в коді, де вперше з’явилося неініціалізоване значення. Це суттєво допомагає в пошуку джерела помилки, яка згодом призводить до аварійного завершення програми.




## Запуск програми

### 1. `--leak-check=no`

Було виявлено:

`Use of uninitialised value` — `*b` використовується без ініціалізації.

`Invalid read` — спроба читання з неініціалізованої/невалідної адреси.

В результаті — програма аварійно завершується з `SIGBUS`.

Було приховано:

`Valgrind` не виводить інформацію про витік пам’яті, тобто виділена через `malloc` пам’ять не була проаналізована.


``` 
lilpeep@avice:~/pw6 $ gcc -g task.c -o task
lilpeep@avice:~/pw6 $ valgrind --leak-check=no ./task
==11835== Memcheck, a memory error detector
==11835== Copyright (C) 2002-2024, and GNU GPL'd, by Julian Seward et al.
==11835== Using Valgrind-3.24.0 and LibVEX; rerun with -h for copyright info
==11835== Command: ./task
==11835== 
==11835== Use of uninitialised value of size 8
==11835==    at 0x4005E6: main (task.c:9)
==11835== 
==11835== Invalid read of size 4
==11835==    at 0x4005E6: main (task.c:9)
==11835==  Address 0x60d1a03168e233cc is not stack'd, malloc'd or (recently) free'd
==11835== 
==11835== 
==11835== Process terminating with default action of signal 10 (SIGBUS): dumping core
==11835==  Hardware error at address 0x1002DBD2E1
==11835==    at 0x4005E6: main (task.c:9)
==11835== 
==11835== HEAP SUMMARY:
==11835==     in use at exit: 40 bytes in 1 blocks
==11835==   total heap usage: 1 allocs, 0 frees, 40 bytes allocated
==11835== 
==11835== For a detailed leak analysis, rerun with: --leak-check=full
==11835== 
==11835== Use --track-origins=yes to see where uninitialised values come from
==11835== For lists of detected and suppressed errors, rerun with: -s
==11835== ERROR SUMMARY: 2 errors from 2 contexts (suppressed: 0 from 0)
Bus error
lilpeep@avice:~/pw6 $ 
```

### 2. `--leak-check=summary`

Було виявлено:

У зведенні про витоки пам’яті:

`still reachable: 40 bytes` — пам’ять виділена через `malloc`, але не звільнена.

Немає `definitely lost`, бо вказівник a все ще існує до завершення програми.

Було приховано:

Місця, де саме в коді витік відбувся, не показані — лише загальна статистика.


```
lilpeep@avice:~/pw6 $ valgrind --leak-check=summary ./task
==11779== Memcheck, a memory error detector
==11779== Copyright (C) 2002-2024, and GNU GPL'd, by Julian Seward et al.
==11779== Using Valgrind-3.24.0 and LibVEX; rerun with -h for copyright info
==11779== Command: ./task
==11779== 
==11779== Use of uninitialised value of size 8
==11779==    at 0x4005E6: main (task.c:9)
==11779== 
==11779== Invalid read of size 4
==11779==    at 0x4005E6: main (task.c:9)
==11779==  Address 0x1ba50ad4b842f1af is not stack'd, malloc'd or (recently) free'd
==11779== 
==11779== 
==11779== Process terminating with default action of signal 10 (SIGBUS): dumping core
==11779==  Hardware error at address 0x1002DBD2E1
==11779==    at 0x4005E6: main (task.c:9)
==11779== 
==11779== HEAP SUMMARY:
==11779==     in use at exit: 40 bytes in 1 blocks
==11779==   total heap usage: 1 allocs, 0 frees, 40 bytes allocated
==11779== 
==11779== LEAK SUMMARY:
==11779==    definitely lost: 0 bytes in 0 blocks
==11779==    indirectly lost: 0 bytes in 0 blocks
==11779==      possibly lost: 0 bytes in 0 blocks
==11779==    still reachable: 40 bytes in 1 blocks
==11779==         suppressed: 0 bytes in 0 blocks
==11779== Rerun with --leak-check=full to see details of leaked memory
==11779== 
==11779== Use --track-origins=yes to see where uninitialised values come from
==11779== For lists of detected and suppressed errors, rerun with: -s
==11779== ERROR SUMMARY: 2 errors from 2 contexts (suppressed: 0 from 0)
Bus error
lilpeep@avice:~/pw6 $ 
```

### 3. `--track-origins=yes`

Було виявлено:

Ті ж самі 2 помилки (`uninitialised value` і `invalid read`), але з точним місцем походження:

`Uninitialised value was created by a stack allocation` — змінна `b` створена на рядку `int *b`;.

Зведення по витоках також збережене (`still reachable: 40 bytes`).

Було приховано:

Нічого критичного не приховано — це найповніший звіт.


```
lilpeep@avice:~/pw6 $ valgrind --track-origins=yes ./task
==11803== Memcheck, a memory error detector
==11803== Copyright (C) 2002-2024, and GNU GPL'd, by Julian Seward et al.
==11803== Using Valgrind-3.24.0 and LibVEX; rerun with -h for copyright info
==11803== Command: ./task
==11803== 
==11803== Use of uninitialised value of size 8
==11803==    at 0x4005E6: main (task.c:9)
==11803==  Uninitialised value was created by a stack allocation
==11803==    at 0x4005C2: main (task.c:4)
==11803== 
==11803== Invalid read of size 4
==11803==    at 0x4005E6: main (task.c:9)
==11803==  Address 0xf0e3867f4518157c is not stack'd, malloc'd or (recently) free'd
==11803== 
==11803== 
==11803== Process terminating with default action of signal 10 (SIGBUS): dumping core
==11803==  Hardware error at address 0x1009227948
==11803==    at 0x4005E6: main (task.c:9)
==11803== 
==11803== HEAP SUMMARY:
==11803==     in use at exit: 40 bytes in 1 blocks
==11803==   total heap usage: 1 allocs, 0 frees, 40 bytes allocated
==11803== 
==11803== LEAK SUMMARY:
==11803==    definitely lost: 0 bytes in 0 blocks
==11803==    indirectly lost: 0 bytes in 0 blocks
==11803==      possibly lost: 0 bytes in 0 blocks
==11803==    still reachable: 40 bytes in 1 blocks
==11803==         suppressed: 0 bytes in 0 blocks
==11803== Rerun with --leak-check=full to see details of leaked memory
==11803== 
==11803== For lists of detected and suppressed errors, rerun with: -s
==11803== ERROR SUMMARY: 2 errors from 2 contexts (suppressed: 0 from 0)
Bus error
lilpeep@avice:~/pw6 $ 
```
