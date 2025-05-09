# Практична робота №6
# Лiшенко О.Д.
## Варiант 11
## Завдання 

Порівняйте звіти `Valgrind` з параметрами `--leak-check=no`, `summary-only`, `--track-origins=yes`. Опишіть, які саме помилки приховуються або виявляються.

## Опис рішення






## Запуск програми
``` 
lilpeep@avice:~/pw6 $ gcc -g leak_example.c -o leak_example
lilpeep@avice:~/pw6 $ valgrind --leak-check=no ./leak_example 2> report_no.txt
lilpeep@avice:~/pw6 $ valgrind --leak-check=summary ./leak_example 2> report_summary.txt
lilpeep@avice:~/pw6 $ valgrind --track-origins=yes ./leak_example 2> report_origins.txt
lilpeep@avice:~/pw6 $ gcc -g task.c -o task
lilpeep@avice:~/pw6 $ 
lilpeep@avice:~/pw6 $ valgrind --leak-check=no ./task
/bin/sh: valgrind: not found
lilpeep@avice:~/pw6 $ valgrind --leak-check=no ./task> abc.txt
/bin/sh: valgrind: not found
lilpeep@avice:~/pw6 $ valgrind --leak-check=no ./task 2> abc.txt
lilpeep@avice:~/pw6 $ sudo pkg install valgrind
/bin/sh: sudo: not found
lilpeep@avice:~/pw6 $ su -
Password:
root@avice:~ # sudo pkg install valgrind
-su: sudo: not found
root@avice:~ # pkg install valgrind
Updating FreeBSD repository catalogue...
Fetching data.pkg: 100%   10 MiB   5.2MB/s    00:02    
Processing entries: 100%
FreeBSD repository update completed. 35953 packages processed.
All repositories are up to date.
New version of pkg detected; it needs to be installed first.
The following 1 package(s) will be affected (of 0 checked):

Installed packages to be UPGRADED:
        pkg: 1.21.3 -> 2.1.2

Number of packages to be upgraded: 1

12 MiB to be downloaded.

Proceed with this action? [y/N]: y
[1/1] Fetching pkg-2.1.2.pkg: 100%   12 MiB  12.6MB/s    00:01    
Checking integrity... done (0 conflicting)
[1/1] Upgrading pkg from 1.21.3 to 2.1.2...
[1/1] Extracting pkg-2.1.2: 100%
Updating FreeBSD repository catalogue...
FreeBSD repository is up to date.
All repositories are up to date.
The following 1 package(s) will be affected (of 0 checked):

New packages to be INSTALLED:
        valgrind: 3.24.0_1,1

Number of packages to be installed: 1

The process will require 241 MiB more space.
61 MiB to be downloaded.

Proceed with this action? [y/N]: y
[1/1] Fetching valgrind-3.24.0_1,1.pkg: 100%   61 MiB  10.8MB/s    00:06    
Checking integrity... done (0 conflicting)
[1/1] Installing valgrind-3.24.0_1,1...
[1/1] Extracting valgrind-3.24.0_1,1: 100%
root@avice:~ # valgrind --leak-check=no ./task
valgrind: ./task: No such file or directory
root@avice:~ # valgrind --leak-check=no ./task.c
valgrind: ./task.c: No such file or directory
root@avice:~ # exit
lilpeep@avice:~/pw6 $ valgrind --leak-check=no ./task
==11736== Memcheck, a memory error detector
==11736== Copyright (C) 2002-2024, and GNU GPL'd, by Julian Seward et al.
==11736== Using Valgrind-3.24.0 and LibVEX; rerun with -h for copyright info
==11736== Command: ./task
==11736== 
==11736== Use of uninitialised value of size 8
==11736==    at 0x4005E6: main (task.c:9)
==11736== 
==11736== Invalid read of size 4
==11736==    at 0x4005E6: main (task.c:9)
==11736==  Address 0xccd535a528c9cde8 is not stack'd, malloc'd or (recently) free'd
==11736== 
==11736== 
==11736== Process terminating with default action of signal 10 (SIGBUS): dumping core
==11736==  Hardware error at address 0x1002DBD2E1
==11736==    at 0x4005E6: main (task.c:9)
==11736== 
==11736== HEAP SUMMARY:
==11736==     in use at exit: 40 bytes in 1 blocks
==11736==   total heap usage: 1 allocs, 0 frees, 40 bytes allocated
==11736== 
==11736== For a detailed leak analysis, rerun with: --leak-check=full
==11736== 
==11736== Use --track-origins=yes to see where uninitialised values come from
==11736== For lists of detected and suppressed errors, rerun with: -s
==11736== ERROR SUMMARY: 2 errors from 2 contexts (suppressed: 0 from 0)
Bus error
lilpeep@avice:~/pw6 $ valgrind --leak-check=no ./task
==11745== Memcheck, a memory error detector
==11745== Copyright (C) 2002-2024, and GNU GPL'd, by Julian Seward et al.
==11745== Using Valgrind-3.24.0 and LibVEX; rerun with -h for copyright info
==11745== Command: ./task
==11745== 
==11745== Use of uninitialised value of size 8
==11745==    at 0x4005E6: main (task.c:9)
==11745== 
lilpeep@avice:~/pw6 $ gcc -g task.c -o task
lilpeep@avice:~/pw6 $ valgrind --leak-check=no ./task
==11774== Memcheck, a memory error detector
==11774== Copyright (C) 2002-2024, and GNU GPL'd, by Julian Seward et al.
==11774== Using Valgrind-3.24.0 and LibVEX; rerun with -h for copyright info
==11774== Command: ./task
==11774== 
==11774== Use of uninitialised value of size 8
==11774==    at 0x4005E6: main (task.c:9)
==11774== 
==11774== Invalid read of size 4
==11774==    at 0x4005E6: main (task.c:9)
==11774==  Address 0x38e0547bdfd53743 is not stack'd, malloc'd or (recently) free'd
==11774== 
==11774== 
==11774== Process terminating with default action of signal 10 (SIGBUS): dumping core
==11774==  Hardware error at address 0x1002DBD2E1
==11774==    at 0x4005E6: main (task.c:9)
==11774== 
==11774== HEAP SUMMARY:
==11774==     in use at exit: 40 bytes in 1 blocks
==11774==   total heap usage: 1 allocs, 0 frees, 40 bytes allocated
==11774== 
==11774== For a detailed leak analysis, rerun with: --leak-check=full
==11774== 
==11774== Use --track-origins=yes to see where uninitialised values come from
==11774== For lists of detected and suppressed errors, rerun with: -s
==11774== ERROR SUMMARY: 2 errors from 2 contexts (suppressed: 0 from 0)
Bus error
lilpeep@avice:~/pw6 $ 
```

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
