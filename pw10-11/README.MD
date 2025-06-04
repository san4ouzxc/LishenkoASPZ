# Практична робота №10-11
# Лiшенко О.Д.
## Варiант 11

## Завдання 1

DumbSH

### Виконання:

Простий shell, виконує команди користувача.

``` 
lilpeep@avice:~/pw1011 $ gcc -Wall 1.c -o 1
lilpeep@avice:~/pw1011 $ ./1
dumbsh> ls          
1       1.c     11.c    2.c     3.c
dumbsh> whoami
lilpeep
dumbsh> exit
lilpeep@avice:~/pw1011 $ 
```

## Завдання 2

API wait

### Виконання:

Чекає завершення дочірнього процесу, виводить код.

``` 
lilpeep@avice:~/pw1011 $ gcc -Wall 2.c -o 2
lilpeep@avice:~/pw1011 $ ./2
Child process (PID: 3191) is exiting with code 0
Exited with code 0
lilpeep@avice:~/pw1011 $ 
```

## Завдання 3

Приклад створення кількох дітей

### Виконання:

Створює кілька дочірніх процесів через цикл.

``` 
lilpeep@avice:~/pw1011 $ gcc -Wall 3.c -o 3
lilpeep@avice:~/pw1011 $ ./3
Child 0
Child 1
Child 2
lilpeep@avice:~/pw1011 $ 
```


## Завдання по варiанту 11

Створіть програму, де після fork() дочірній процес виконує команду ls -l за допомогою execlp().

### Виконання:

fork() + execlp() для запуску ls -l.

``` 
lilpeep@avice:~/pw1011 $ gcc -Wall 11.c -o 11
lilpeep@avice:~/pw1011 $ ./11
Батьківський процес (PID: 3235) очікує завершення дочірнього процесу...
Дочірній процес (PID: 3236) виконує 'ls -l'
total 88
-rwxr-xr-x  1 lilpeep lilpeep 9488 Jun  4 17:52 1
-rw-r--r--  1 lilpeep lilpeep  551 Jun  4 17:40 1.c
-rwxr-xr-x  1 lilpeep lilpeep 9496 Jun  4 18:05 11
-rw-r--r--  1 lilpeep lilpeep  759 Jun  4 17:44 11.c
-rwxr-xr-x  1 lilpeep lilpeep 9008 Jun  4 17:57 2
-rw-r--r--  1 lilpeep lilpeep  521 Jun  4 17:57 2.c
-rwxr-xr-x  1 lilpeep lilpeep 8624 Jun  4 17:58 3
-rw-r--r--  1 lilpeep lilpeep  323 Jun  4 17:42 3.c
Дочірній процес завершено.
lilpeep@avice:~/pw1011 $ 
```
