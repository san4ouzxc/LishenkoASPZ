# Практична робота №8
# Лiшенко О.Д.
## Варiант 11

## Завдання 1

Напишіть програму, яка читає файл `/etc/passwd` за допомогою команди `getent passwd`, щоб дізнатись, які облікові записи визначені на вашому комп’ютері.
Програма повинна визначити, чи є серед них звичайні користувачі (ідентифікатори `UID` повинні бути більші за 500 або 1000, залежно від вашого дистрибутива), окрім вас.

### Виконання:
Було реалізовано програму, яка переглядає файл `/etc/passwd` і виводить усіх звичайних користувачів з `UID > 1000`, крім поточного користувача. Програма коректно визначила користувачів `nobody`, `zxcursed`, `no4rfl`.

``` 
lilpeep@avice:~/pw9 $ gcc -Wall 1.c -o 1
lilpeep@avice:~/pw9 $ ./1
Звичайні користувачі в системі (UID > 1000), окрім вас (UID 1003):
  - nobody (UID: 65534)
  - zxcursed (UID: 1001)
  - no4rfl (UID: 1002)
lilpeep@avice:~/pw9 $ 
```

## Завдання 2

Напишіть програму, яка виконує команду `cat /etc/shadow` від імені адміністратора, хоча запускається від звичайного користувача.
(Ваша програма повинна робити необхідне, виходячи з того, що конфігурація системи дозволяє отримувати адміністративний доступ за допомогою відповідної команди.)

### Виконання:

Програма прочитала файл `/etc/master.passwd` та вивела інформацію про всіх користувачів системи разом із хешами паролів, `UID`, `GID` та шляхами до домашніх каталогів. Це дозволило побачити, у яких облікових записів встановлені паролі та як організовано їх зберігання.



``` 
lilpeep@avice:~/pw9 $ gcc -Wall 2.c -o 2
lilpeep@avice:~/pw9 $ ./2
root:$6$Bt41u6nzp2lDvBZd$KNMWuTmFtsgQ1Szrwv8g56NGgq/3dHk0tLPmhljGDJSX/ZXte5OoxuNVq5XDggGzWYlIeKB9SFgfSVUWDSFnD0:0:0::0:0:Charlie &:/root:/bin/sh
toor:*:0:0::0:0:Bourne-again Superuser:/root:
daemon:*:1:1::0:0:Owner of many system processes:/root:/usr/sbin/nologin
operator:*:2:5::0:0:System &:/:/usr/sbin/nologin
bin:*:3:7::0:0:Binaries Commands and Source:/:/usr/sbin/nologin
tty:*:4:65533::0:0:Tty Sandbox:/:/usr/sbin/nologin
kmem:*:5:65533::0:0:KMem Sandbox:/:/usr/sbin/nologin
games:*:7:13::0:0:Games pseudo-user:/:/usr/sbin/nologin
news:*:8:8::0:0:News Subsystem:/:/usr/sbin/nologin
man:*:9:9::0:0:Mister Man Pages:/usr/share/man:/usr/sbin/nologin
sshd:*:22:22::0:0:Secure Shell Daemon:/var/empty:/usr/sbin/nologin
smmsp:*:25:25::0:0:Sendmail Submission User:/var/spool/clientmqueue:/usr/sbin/nologin
mailnull:*:26:26::0:0:Sendmail Default User:/var/spool/mqueue:/usr/sbin/nologin
bind:*:53:53::0:0:Bind Sandbox:/:/usr/sbin/nologin
unbound:*:59:59::0:0:Unbound DNS Resolver:/var/unbound:/usr/sbin/nologin
proxy:*:62:62::0:0:Packet Filter pseudo-user:/nonexistent:/usr/sbin/nologin
_pflogd:*:64:64::0:0:pflogd privsep user:/var/empty:/usr/sbin/nologin
_dhcp:*:65:65::0:0:dhcp programs:/var/empty:/usr/sbin/nologin
uucp:*:66:66::0:0:UUCP pseudo-user:/var/spool/uucppublic:/usr/local/libexec/uucp/uucico
pop:*:68:6::0:0:Post Office Owner:/nonexistent:/usr/sbin/nologin
auditdistd:*:78:77::0:0:Auditdistd unprivileged user:/var/empty:/usr/sbin/nologin
www:*:80:80::0:0:World Wide Web Owner:/nonexistent:/usr/sbin/nologin
ntpd:*:123:123::0:0:NTP Daemon:/var/db/ntp:/usr/sbin/nologin
_ypldap:*:160:160::0:0:YP LDAP unprivileged user:/var/empty:/usr/sbin/nologin
hast:*:845:845::0:0:HAST unprivileged user:/var/empty:/usr/sbin/nologin
tests:*:977:977::0:0:Unprivileged user for tests:/nonexistent:/usr/sbin/nologin
nobody:*:65534:65534::0:0:Unprivileged user:/nonexistent:/usr/sbin/nologin
zxcursed:*LOCKED*$6$JNYD2.t.TzqAgdMh$43YnFRnA4NRzAFasu5mPO30D3iwPULjKMDzOk3E1/ubGfKVi2c.o.F9erz6lfzbUdJVPMdukuQ4B3MLQqw1ah/:1001:0::0:0:zxcursed name:/home/zxcursed:/bin/sh
messagebus:*:556:556::0:0:D-BUS Daemon User:/nonexistent:/usr/sbin/nologin
polkitd:*:565:565::0:0:Polkit Daemon User:/var/empty:/usr/sbin/nologin
avahi:*:558:558::0:0:Avahi Daemon User:/nonexistent:/usr/sbin/nologin
cups:*:193:193::0:0:Cups Owner:/nonexistent:/usr/sbin/nologin
colord:*:970:970::0:0:colord color management daemon:/nonexistent:/usr/sbin/nologin
cyrus:*:60:60::0:0:the cyrus mail server:/nonexistent:/usr/sbin/nologin
pulse:*:563:563::0:0:PulseAudio System User:/nonexistent:/usr/sbin/nologin
webcamd:*:145:145::0:0:Webcamd user:/var/empty:/usr/sbin/nologin
gdm:*:92:92::0:0:GNOME Display Manager:/usr/local/etc/gdm/home:/usr/sbin/nologin
_sndio:*:702:702::0:0:sndio privsep:/var/empty:/usr/sbin/nologin
no4rfl:$6$feb005GEh2BlJsno$U8pidD6CDQfdQJj.D/vubGQnaZZ5i2.K6/qLgydcPha5HjJsFdeKWO7Ja3my2GmHAcinpwbthaHWFZ80YXOOf/:1002:1002::0:0:demon:/home/no4rfl:/bin/sh
lilpeep:$6$R.VoVAVE7aNcyOLC$Vjo9h5T9qEQ8OuHWEaAis7weywMZW40OWJE9SlmoGIE9fE5G/C6aYbACEFCIgBw26qMoGOFPvl.4u7h3WpNtu0:1003:1003::0:0:lilpeep:/home/lilpeep:/bin/sh
lilpeep@avice:~/pw9 $
```

## Завдання 3

Напишіть програму, яка від імені root копіює файл, який вона перед цим створила від імені звичайного користувача. Потім вона повинна помістити копію у домашній каталог звичайного користувача.
Далі, використовуючи звичайний обліковий запис, програма намагається змінити файл і зберегти зміни. Що відбудеться?
Після цього програма намагається видалити цей файл за допомогою команди rm. Що відбудеться?

### Виконання:

Було створено файл і скопійовано його з root-доступом. Потім звичайний користувач намагався змінити його — запис не дозволено, але видалити вдалося. Це показало відмінності між правами на читання, запис і видалення, навіть якщо файл належить `root`.


``` 
lilpeep@avice:~/pw9 $ gcc -Wall 3.c -o 3
lilpeep@avice:~/pw9 $ ./3
Створено файл: /home/lilpeep/myfile.txt
Копіюємо файл через sudo...
Пробуємо змінити файл /home/lilpeep/copied_by_root.txt як звичайний користувач...
fopen: Permission denied
Не вдалося змінити файл (немає прав?)
Пробуємо видалити файл...
Файл видалено успішно.
lilpeep@avice:~/pw9 $ 
```

## Завдання 4

Напишіть програму, яка по черзі виконує команди whoami та id, щоб перевірити стан облікового запису користувача, від імені якого вона запущена.
Є ймовірність, що команда id виведе список різних груп, до яких ви належите. Програма повинна це продемонструвати.

### Виконання:

Програма запускала системні команди whoami та id, демонструючи ім’я користувача, UID, GID та список груп. Це показало, як зовнішні утиліти можуть використовуватись у C-програмі для отримання інформації про користувача.

``` 
lilpeep@avice:~/pw9 $ gcc -Wall 4.c -o 4
lilpeep@avice:~/pw9 $ ./4
Виконуємо whoami:
lilpeep

Виконуємо id:
uid=1003(lilpeep) gid=1003(lilpeep) groups=1003(lilpeep),0(wheel)
lilpeep@avice:~/pw9 $
```

## Завдання 5

Напишіть програму, яка створює тимчасовий файл від імені звичайного користувача. Потім від імені суперкористувача використовує команди chown і chmod, щоб змінити тип володіння та права доступу.
Програма повинна визначити, в яких випадках вона може виконувати читання та запис файлу, використовуючи свій обліковий запис.

### Виконання:

Програма створювала файл, змінювала його власника на root:wheel та встановлювала права 0644. Читання як звичайний користувач було дозволено, проте запис завершився помилкою. Це наочно демонструє вплив прав доступу на операції з файлами.

``` 
lilpeep@avice:~/pw9 $ ./5
Змінюємо власника та права на root:wheel, 0644
Намагаємось читати файл...
Прочитано: test
Намагаємось писати у файл...
fopen (write): Permission denied
```

## Завдання 6

Напишіть програму, яка виконує команду ls -l, щоб переглянути власника і права доступу до файлів у своєму домашньому каталозі, в /usr/bin та в /etc.
Продемонструйте, як ваша програма намагається обійти різні власники та права доступу користувачів, а також здійснює спроби читання, запису та виконання цих файлів.

### Виконання:

Було реалізовано перегляд вмісту каталогів /home/lilpeep, /usr/bin та /etc, з перевіркою прав на читання, запис і виконання для окремих файлів. Отримано вичерпну інформацію про доступність файлів користувачем, що показує вплив прав і власності.



``` 
lilpeep@avice:~/pw9 $ gcc -Wall 6.c -o 6
lilpeep@avice:~/pw9 $ ./6

Каталог: /home/lilpeep
total 6188
-rw-------  1 lilpeep lilpeep 37629952 Mar  6 12:40 ibus-extension-gtk3.core
-rw-r--r--  1 lilpeep lilpeep       78 May 26 15:20 myfile.txt
drwxr-xr-x  2 lilpeep lilpeep       16 Mar  6 20:40 pw2
drwxr-xr-x  2 lilpeep lilpeep        3 Mar 22 11:20 pw3
drwxr-xr-x  2 lilpeep lilpeep       21 Mar 23 21:33 pw4
drwxr-xr-x  2 lilpeep lilpeep        4 May  8 16:50 pw5
drwxr-xr-x  2 lilpeep lilpeep       11 May  9 15:36 pw6
drwxr-xr-x  2 lilpeep lilpeep       25 May 26 03:21 pw7
drwxr-xr-x  2 lilpeep lilpeep       13 May 26 14:15 pw8
drwxr-xr-x  2 lilpeep lilpeep       15 May 26 15:50 pw9
-rw-r--r--  1 root    wheel          4 May 26 15:47 tempfile.txt
-rw-r--r--  1 root    lilpeep     2469 May 26 15:19 test.txt

Файл: /home/lilpeep/.vboxclient-clipboard.pid
Читання дозволено
Запис дозволено
Виконання заборонено (Permission denied)

Файл: /home/lilpeep/.vboxclient-seamless.pid
Читання дозволено
Запис дозволено
Виконання заборонено (Permission denied)

Файл: /home/lilpeep/.mail_aliases
Читання дозволено
Запис дозволено
Виконання заборонено (Permission denied)

Каталог: /usr/bin
total 1004128
-r-xr-xr-x   1 root wheel      86576 Nov 29 10:25 addr2line
-r-xr-xr-x  15 root wheel         74 Nov 29 10:21 alias
-r-xr-xr-x   1 root wheel      10672 Nov 29 10:21 apply
-r-xr-xr-x   4 root wheel     513696 Nov 29 10:22 apropos
-r-xr-xr-x   2 root wheel      50520 Nov 29 10:25 ar
-r-xr-xr-x   1 root wheel       7824 Nov 29 10:21 asa
-r-xr-xr-x   1 root wheel     112544 Nov 29 10:15 asn1_compile
-r-sr-xr-x   4 root wheel      29936 Nov 29 10:24 at
-r-sr-xr-x   4 root wheel      29936 Nov 29 10:24 atq
-r-sr-xr-x   4 root wheel      29936 Nov 29 10:24 atrm
-r-xr-xr-x   2 root wheel     233608 Nov 29 10:21 awk
-r-xr-xr-x   6 root wheel      21648 Nov 29 10:21 b64decode
-r-xr-xr-x   6 root wheel      21648 Nov 29 10:21 b64encode
-r-xr-xr-x   1 root wheel      11336 Nov 29 10:21 backlight
-r-xr-xr-x   1 root wheel      19776 Nov 29 10:21 banner
-r-xr-xr-x   6 root wheel      21648 Nov 29 10:21 base64
-r-xr-xr-x   1 root wheel       8744 Nov 29 10:21 basename
-r-sr-xr-x   4 root wheel      29936 Nov 29 10:24 batch
-r-xr-xr-x   2 root wheel     220920 Nov 29 10:23 bc
-r-xr-xr-x   1 root wheel      10056 Nov 29 10:21 beep
-r-xr-xr-x  15 root wheel         74 Nov 29 10:21 bg
-r-xr-xr-x   1 root wheel       6544 Nov 29 10:24 biff
-r-xr-xr-x   6 root wheel      21648 Nov 29 10:21 bintrans
-r-xr-xr-x   2 root wheel     215568 Nov 29 10:25 bmake
-r-xr-xr-x   1 root wheel      11248 Nov 29 10:21 brandelf
-r-xr-xr-x   1 root wheel      10288 Nov 29 10:21 bsdcat
-r-xr-xr-x   1 root wheel      38752 Nov 29 10:24 bsdcpio
-r-xr-xr-x   1 root wheel      45896 Nov 29 10:21 bsddialog
-r-xr-xr-x   1 root wheel      48896 Nov 29 10:21 bsdiff
-r-xr-xr-x   1 root wheel      69208 Nov 29 10:22 bsdtar
-r-xr-xr-x   1 root wheel      24888 Nov 29 10:22 bsdunzip
-r-xr-xr-x   3 root wheel      81352 Nov 29 10:26 bsnmpget
-r-xr-xr-x   3 root wheel      81352 Nov 29 10:26 bsnmpset
-r-xr-xr-x   3 root wheel      81352 Nov 29 10:26 bsnmpwalk
-r-xr-xr-x   1 root wheel      11608 Nov 29 10:21 bspatch
-r-xr-xr-x   1 root wheel       7280 Nov 29 10:24 bthost
-r-xr-sr-x   1 root kmem       14672 Nov 29 10:24 btsockstat
-r-xr-xr-x   3 root wheel      33864 Nov 29 10:21 bunzip2
-r-xr-xr-x   2 root wheel     115024 Nov 29 10:26 byacc
-r-xr-xr-x   3 root wheel      33864 Nov 29 10:21 bzcat
-r-xr-xr-x  15 root wheel       4167 Nov 29 10:21 bzegrep
-r-xr-xr-x  15 root wheel       4167 Nov 29 10:21 bzfgrep
-r-xr-xr-x  15 root wheel       4167 Nov 29 10:21 bzgrep
-r-xr-xr-x   3 root wheel      33864 Nov 29 10:21 bzip2
-r-xr-xr-x   1 root wheel      12240 Nov 29 10:21 bzip2recover
-r-xr-xr-x   5 root wheel         83 Nov 29 10:22 bzless
-r-xr-xr-x   6 root wheel  105730000 Nov 29 10:22 c++
-r-xr-xr-x   2 root wheel     404664 Nov 29 10:23 c++filt
-r-xr-xr-x   1 root wheel       6552 Nov 29 10:25 c89
-r-xr-xr-x   1 root wheel       7688 Nov 29 10:25 c99
-r-xr-xr-x   1 root wheel       9400 Nov 29 10:24 caesar
-r-xr-xr-x   2 root wheel      27448 Nov 29 10:22 cal
-r-xr-xr-x   1 root wheel      61152 Nov 29 10:24 calendar
-r-xr-xr-x   1 root wheel       8288 Nov 29 10:21 cap_mkdb
-r-xr-xr-x   3 root wheel      88728 Nov 29 10:22 captoinfo
-r-xr-xr-x   6 root wheel  105730000 Nov 29 10:22 cc
-r-xr-xr-x   1 root wheel         70 Nov 29 10:22 CC
-r-xr-xr-x  15 root wheel         74 Nov 29 10:21 cd
-r-xr-xr-x   1 root wheel      23672 Nov 29 10:21 chat
lrwxr-xr-x   1 root wheel          6 Nov 29 10:21 chfn -> chpass
-r-xr-xr-x   2 root wheel      10448 Nov 29 10:22 chgrp
-r-xr-xr-x   1 root wheel      12880 Nov 29 10:25 chkey
-r-sr-xr-x   1 root wheel      24400 Nov 29 10:21 chpass
lrwxr-xr-x   1 root wheel          6 Nov 29 10:21 chsh -> chpass
-r-xr-xr-x   2 root wheel      11296 Nov 29 10:21 cksum
-r-xr-xr-x   6 root wheel  105730000 Nov 29 10:22 clang
-r-xr-xr-x   6 root wheel  105730000 Nov 29 10:22 clang-cpp
-r-xr-xr-x   6 root wheel  105730000 Nov 29 10:22 clang++
-r-xr-xr-x   1 root wheel       9168 Nov 29 10:22 clear
-r-xr-xr-x   1 root wheel      16824 Nov 29 10:21 cmp
-r-xr-xr-x   1 root wheel      13336 Nov 29 10:21 col
-r-xr-xr-x   1 root wheel       7800 Nov 29 10:21 colrm
-r-xr-xr-x   1 root wheel      11552 Nov 29 10:21 column
-r-xr-xr-x   1 root wheel       9072 Nov 29 10:21 comm
-r-xr-xr-x  15 root wheel         74 Nov 29 10:21 command
-r-xr-xr-x   1 root wheel      27392 Nov 29 10:24 compile_et
-r-xr-xr-x   2 root wheel      16872 Nov 29 10:21 compress
lrwxr-xr-x   1 root wheel          7 Nov 29 10:24 cpio -> bsdcpio
-r-xr-xr-x   6 root wheel  105730000 Nov 29 10:22 cpp
lrwxr-xr-x   1 root wheel         16 Nov 29 09:57 cpuset -> ../../bin/cpuset
-r-sr-xr-x   1 root wheel      35392 Nov 29 10:22 crontab
-r-xr-xr-x   1 root wheel      40952 Nov 29 10:29 crunchgen
-r-xr-xr-x   1 root wheel      17720 Nov 29 10:29 crunchide
-r-xr-xr-x   2 root wheel       8728 Nov 29 10:21 crypt
-r-xr-xr-x   1 root wheel      14160 Nov 29 10:21 csplit
-r-xr-xr-x   1 root wheel      26256 Nov 29 10:25 ctags
-r-xr-xr-x   1 root wheel      93208 Nov 29 10:12 ctfconvert
-r-xr-xr-x   1 root wheel      25248 Nov 29 10:12 ctfdump
-r-xr-xr-x   1 root wheel      78248 Nov 29 10:12 ctfmerge
-r-xr-xr-x   1 root wheel      23464 Nov 29 10:21 ctlstat
-r-xr-xr-x   2 root wheel      74936 Nov 29 10:22 cu
-r-xr-xr-x   1 root wheel      14616 Nov 29 10:21 cut
-r-xr-xr-x   2 root wheel     220920 Nov 29 10:23 dc
-r-xr-xr-x   1 root wheel      59480 Nov 29 10:13 dialog
-r-xr-xr-x   1 root wheel      49992 Nov 29 10:21 diff
-r-xr-xr-x   1 root wheel      28736 Nov 29 10:13 diff3
-r-xr-xr-x   1 root wheel       7336 Nov 29 10:21 dirname
-r-xr-xr-x   1 root wheel      14056 Nov 29 10:24 dpv
-r-xr-xr-x   1 root wheel      65696 Nov 29 10:24 drill
-r-xr-xr-x   1 root wheel     267824 Nov 29 10:21 dtc
-r-xr-xr-x   1 root wheel      12168 Nov 29 10:21 du
-r-xr-xr-x   3 root wheel      94680 Nov 29 10:24 edit
-r-xr-xr-x   3 root wheel      94680 Nov 29 10:24 ee
-r-xr-xr-x   4 root wheel      29624 Nov 29 10:21 egrep
-r-xr-xr-x   1 root wheel      13384 Nov 29 10:21 elfctl
-r-xr-xr-x   1 root wheel      25920 Nov 29 10:21 elfdump
-r-xr-xr-x   2 root wheel       8728 Nov 29 10:21 enigma
-r-xr-xr-x   1 root wheel      14944 Nov 29 10:21 env
-r-xr-xr-x   1 root wheel      12824 Nov 29 10:21 etdump
-r-xr-xr-x   6 root wheel     457544 Nov 29 10:26 ex
-r-xr-xr-x   1 root wheel       8096 Nov 29 10:21 expand
-r-xr-xr-x   1 root wheel      64120 Nov 29 10:24 factor
-r-xr-xr-x   1 root wheel       4944 Nov 29 10:21 false
-r-xr-xr-x  15 root wheel         74 Nov 29 10:21 fc
-r-xr-xr-x   1 root wheel      28368 Nov 29 10:21 fetch
-r-xr-xr-x  15 root wheel         74 Nov 29 10:21 fg
-r-xr-xr-x   4 root wheel      29624 Nov 29 10:21 fgrep
-r-xr-xr-x   1 root wheel      26336 Nov 29 10:24 file
-r-xr-xr-x   1 root wheel       7488 Nov 29 10:25 file2c
-r-xr-xr-x   1 root wheel      66240 Nov 29 10:21 find
-r-xr-xr-x   1 root wheel      26784 Nov 29 10:24 finger
-r-xr-xr-x   4 root wheel     444032 Nov 29 10:26 flex
-r-xr-xr-x   4 root wheel     444032 Nov 29 10:26 flex++
-r-xr-xr-x   1 root wheel      14512 Nov 29 10:21 fmt
-r-xr-xr-x   1 root wheel       9192 Nov 29 10:21 fold
-r-xr-xr-x   1 root wheel      22064 Nov 29 10:24 fortune
-r-xr-xr-x   1 root wheel       7904 Nov 29 10:24 from
-r-xr-xr-x   2 root wheel      18864 Nov 29 10:21 fstat
-r-xr-xr-x   1 root wheel       5816 Nov 29 10:21 fsync
-r-xr-xr-x   3 root wheel     159720 Nov 29 10:24 ftp
-r-xr-xr-x   2 root wheel      18864 Nov 29 10:21 fuser
-r-xr-xr-x   3 root wheel     159720 Nov 29 10:24 gate-ftp
-r-xr-xr-x   1 root wheel      19640 Nov 29 10:21 gcore
-r-xr-xr-x   2 root wheel    4877352 Nov 29 10:23 gcov
-r-xr-xr-x   1 root wheel      13200 Nov 29 10:21 gencat
-r-xr-xr-x   1 root wheel      17952 Nov 29 10:25 genl
-r-xr-xr-x   1 root wheel      17728 Nov 29 10:21 getaddrinfo
-r-xr-xr-x   1 root wheel      26456 Nov 29 10:21 getconf
-r-xr-xr-x   1 root wheel      21392 Nov 29 10:21 getent
-r-xr-xr-x   1 root wheel       7144 Nov 29 10:21 getopt
-r-xr-xr-x  15 root wheel         74 Nov 29 10:21 getopts
-r-xr-xr-x   1 root wheel      32672 Nov 29 10:25 gprof
-r-xr-xr-x   1 root wheel      11480 Nov 29 10:24 grdc
-r-xr-xr-x   4 root wheel      29624 Nov 29 10:21 grep
-r-xr-xr-x   3 root wheel      13232 Nov 29 10:21 groups
-r-xr-xr-x   4 root wheel      64464 Nov 29 10:21 gunzip
-r-xr-xr-x   4 root wheel      64464 Nov 29 10:21 gzcat
-r-xr-xr-x   1 root wheel       4010 Nov 29 10:21 gzexe
-r-xr-xr-x   4 root wheel      64464 Nov 29 10:21 gzip
-r-xr-xr-x  15 root wheel         74 Nov 29 10:21 hash
-r-xr-xr-x   3 root wheel      29024 Nov 29 10:21 hd
-r-xr-xr-x   1 root wheel      11216 Nov 29 10:21 head
-r-xr-xr-x   3 root wheel      29024 Nov 29 10:21 hexdump
-r-xr-xr-x   1 root wheel      31888 Nov 29 10:24 host
-r-xr-xr-x   1 root wheel      92504 Nov 29 10:15 hxtool
-r-xr-xr-x   1 root wheel      32736 Nov 29 10:26 ibstat
-r-xr-xr-x   1 root wheel       8456 Nov 29 10:26 ibv_asyncwatch
-r-xr-xr-x   1 root wheel       6392 Nov 29 10:26 ibv_devices
-r-xr-xr-x   1 root wheel      18376 Nov 29 10:26 ibv_devinfo
-r-xr-xr-x   1 root wheel      24840 Nov 29 10:26 ibv_rc_pingpong
-r-xr-xr-x   1 root wheel      24728 Nov 29 10:26 ibv_srq_pingpong
-r-xr-xr-x   1 root wheel      22616 Nov 29 10:26 ibv_uc_pingpong
-r-xr-xr-x   1 root wheel      22640 Nov 29 10:26 ibv_ud_pingpong
-r-xr-xr-x   1 root wheel      12544 Nov 29 10:24 iconv
-r-xr-xr-x   3 root wheel      13232 Nov 29 10:21 id
-r-xr-xr-x   1 root wheel      10200 Nov 29 10:21 ident
-r-xr-xr-x   1 root wheel      52352 Nov 29 10:25 indent
-r-xr-xr-x   1 root wheel      62488 Nov 29 10:22 infocmp
-r-xr-xr-x   3 root wheel      88728 Nov 29 10:22 infotocap
-r-xr-xr-x   1 root wheel      31552 Nov 29 10:22 install
-r-xr-xr-x   1 root wheel      14176 Nov 29 10:21 ipcrm
-r-xr-xr-x   1 root wheel      18976 Nov 29 10:21 ipcs
-r-xr-xr-x   1 root wheel      51680 Nov 29 10:24 iscsictl
-r-xr-xr-x  15 root wheel         74 Nov 29 10:21 jobs
-r-xr-xr-x   1 root wheel      14096 Nov 29 10:21 join
-r-xr-xr-x   1 root wheel      13688 Nov 29 10:21 jot
-r-xr-xr-x   1 root wheel      89472 Nov 29 10:15 kadmin
-r-xr-xr-x   3 root wheel      40296 Nov 29 10:15 kcc
-r-xr-xr-x   1 root wheel      10096 Nov 29 10:15 kdestroy
-r-xr-xr-x   1 root wheel      62696 Nov 29 10:24 kdump
-r-xr-xr-x   1 root wheel       6328 Nov 29 10:21 keylogin
-r-xr-xr-x   1 root wheel       5840 Nov 29 10:21 keylogout
-r-xr-xr-x   1 root wheel      13200 Nov 29 10:15 kf
-r-xr-xr-x   1 root wheel      12704 Nov 29 10:15 kgetcred
-r-xr-xr-x   1 root wheel      14088 Nov 29 10:21 killall
-r-xr-xr-x   1 root wheel      27960 Nov 29 10:15 kinit
-r-xr-xr-x   3 root wheel      40296 Nov 29 10:15 klist
-r-xr-xr-x   1 root wheel      12184 Nov 29 10:15 kpasswd
-r-xr-xr-x   1 root wheel       3629 Nov 29 10:15 krb5-config
-r-xr-xr-x   1 root wheel      16168 Nov 29 10:15 ksu
-r-xr-xr-x   3 root wheel      40296 Nov 29 10:15 kswitch
-r-xr-xr-x   1 root wheel      10136 Nov 29 10:21 ktrace
-r-xr-xr-x   1 root wheel      14496 Nov 29 10:22 ktrdump
-r-xr-xr-x   1 root wheel    1313400 Nov 29 10:25 kyua
-r-xr-xr-x   1 root wheel      10528 Nov 29 10:22 lam
-r-xr-xr-x   1 root wheel      16016 Nov 29 10:26 last
-r-xr-xr-x   1 root wheel      12552 Nov 29 10:24 lastcomm
lrwxr-xr-x   1 root wheel          6 Nov 29 10:23 ld -> ld.lld
-r-xr-xr-x   1 root wheel   60255136 Nov 29 10:23 ld.lld
-r-xr-xr-x   1 root wheel      12624 Nov 29 10:22 ldd
-r-xr-xr-x   1 root wheel       9048 Nov 29 10:24 ldd32
-r-xr-xr-x   1 root wheel       7944 Nov 29 10:22 leave
-r-xr-xr-x   2 root wheel     219208 Nov 29 10:22 less
-r-xr-xr-x   1 root wheel       9176 Nov 29 10:22 lessecho
-r-xr-xr-x   1 root wheel      19552 Nov 29 10:22 lesskey
-r-xr-xr-x   1 root wheel        412 Nov 29 10:22 lesspipe.sh
-r-xr-xr-x   4 root wheel     444032 Nov 29 10:26 lex
-r-xr-xr-x   4 root wheel     444032 Nov 29 10:26 lex++
-r-xr-xr-x   1 root wheel      28064 Nov 29 10:22 limits
-r-xr-xr-x   1 root wheel   97920136 Nov 29 10:23 lldb
-r-xr-xr-x   1 root wheel   25058024 Nov 29 10:23 lldb-server
-r-xr-xr-x   2 root wheel    4869432 Nov 29 10:23 llvm-addr2line
-r-xr-xr-x   2 root wheel   15148424 Nov 29 10:22 llvm-ar
-r-xr-xr-x   2 root wheel    4877352 Nov 29 10:23 llvm-cov
-r-xr-xr-x   2 root wheel     404664 Nov 29 10:23 llvm-cxxfilt
-r-xr-xr-x   1 root wheel   16039816 Nov 29 10:22 llvm-nm
-r-xr-xr-x   2 root wheel    4608880 Nov 29 10:23 llvm-objcopy
-r-xr-xr-x   2 root wheel   17497456 Nov 29 10:23 llvm-objdump
-r-xr-xr-x   1 root wheel    5552792 Nov 29 10:23 llvm-profdata
-r-xr-xr-x   2 root wheel   15148424 Nov 29 10:22 llvm-ranlib
-r-xr-xr-x   2 root wheel    6812360 Nov 29 10:23 llvm-readelf
-r-xr-xr-x   2 root wheel    6812360 Nov 29 10:23 llvm-readobj
-r-xr-xr-x   1 root wheel    3953144 Nov 29 10:23 llvm-size
-r-xr-xr-x   1 root wheel     355800 Nov 29 10:23 llvm-strings
-r-xr-xr-x   2 root wheel    4608880 Nov 29 10:23 llvm-strip
-r-xr-xr-x   2 root wheel    4869432 Nov 29 10:23 llvm-symbolizer
-r-xr-xr-x   1 root wheel      22984 Nov 29 10:22 locale
-r-xr-xr-x   1 root wheel      89888 Nov 29 10:22 localedef
-r-xr-xr-x   1 root wheel      20456 Nov 29 10:24 locate
-r-sr-xr-x   1 root wheel      11736 Nov 29 10:22 lock
-r-xr-xr-x   1 root wheel      10584 Nov 29 10:22 lockf
-r-xr-xr-x   1 root wheel      16728 Nov 29 10:22 logger
-r-sr-xr-x   1 root wheel      26104 Nov 29 10:22 login
-r-xr-xr-x   1 root wheel      10944 Nov 29 10:22 logins
-r-xr-xr-x   1 root wheel       7064 Nov 29 10:22 logname
-r-xr-xr-x   1 root wheel      10080 Nov 29 10:22 look
-r-xr-xr-x   1 root wheel       2922 Nov 29 10:26 lorder
-r-xr-xr-x   1 root wheel       2708 Nov 29 10:27 lp
-r-sr-sr-x   1 root daemon     35408 Nov 29 10:27 lpq
-r-sr-sr-x   1 root daemon     39392 Nov 29 10:27 lpr
-r-sr-sr-x   1 root daemon     32672 Nov 29 10:27 lprm
-r-xr-xr-x   1 root wheel       7808 Nov 29 10:22 lsvfs
-r-xr-xr-x   6 root wheel      77064 Nov 29 10:22 lzcat
-r-xr-xr-x   2 root wheel      10984 Nov 29 10:22 lzdec
-r-xr-xr-x  15 root wheel       4167 Nov 29 10:21 lzegrep
-r-xr-xr-x  15 root wheel       4167 Nov 29 10:21 lzfgrep
-r-xr-xr-x  15 root wheel       4167 Nov 29 10:21 lzgrep
-r-xr-xr-x   5 root wheel         83 Nov 29 10:22 lzless
-r-xr-xr-x   6 root wheel      77064 Nov 29 10:22 lzma
-r-xr-xr-x   1 root wheel       9592 Nov 29 10:22 lzmainfo
-r-xr-xr-x   1 root wheel      72536 Nov 29 10:22 m4
-r-xr-xr-x   3 root wheel     105416 Nov 29 10:24 mail
-r-xr-xr-x   3 root wheel     105416 Nov 29 10:24 Mail
lrwxr-xr-x   1 root wheel         19 Nov 29 10:23 mailq -> ../sbin/mailwrapper
-r-xr-xr-x   3 root wheel     105416 Nov 29 10:24 mailx
-r-xr-xr-x   2 root wheel     215568 Nov 29 10:25 make
-r-xr-xr-x   1 root wheel      15000 Nov 29 10:15 make-roken
-r-xr-xr-x   4 root wheel     513696 Nov 29 10:22 makewhatis
-r-xr-xr-x   2 root wheel      24443 Nov 29 10:25 man
-r-xr-xr-x   4 root wheel     513696 Nov 29 10:22 mandoc
-r-xr-xr-x   2 root wheel      24443 Nov 29 10:25 manpath
-r-xr-xr-x   1 root wheel      14456 Nov 29 10:26 mckey
-r-xr-xr-x   1 root wheel       7216 Nov 29 10:22 mdo
-r-xr-xr-x   1 root wheel       6240 Nov 29 10:22 mesg
-r-xr-xr-x   1 root wheel      11536 Nov 29 10:22 mididump
-r-xr-xr-x   1 root wheel      25904 Nov 29 10:22 ministat
-r-xr-xr-x   1 root wheel      29344 Nov 29 10:24 mkcsmapper
-r-xr-xr-x   1 root wheel       2977 Nov 29 10:22 mkdep
-r-xr-xr-x   1 root wheel      23824 Nov 29 10:24 mkesdb
-r-xr-xr-x   1 root wheel       6624 Nov 29 10:22 mkfifo
-r-xr-xr-x   1 root wheel      53352 Nov 29 10:22 mkimg
-r-xr-xr-x   1 root wheel      11312 Nov 29 10:26 mkstr
-r-xr-xr-x   1 root wheel       8832 Nov 29 10:22 mktemp
-r-xr-xr-x   1 root wheel      21376 Nov 29 10:22 mkuzip
-r-xr-xr-x   2 root wheel     219208 Nov 29 10:22 more
-r-xr-xr-x   1 root wheel      19160 Nov 29 10:24 morse
-r-xr-xr-x   1 root wheel      20824 Nov 29 10:24 msgs
-r-xr-xr-x   1 root wheel      30288 Nov 29 10:22 mt
-r-xr-xr-x   2 root wheel     233608 Nov 29 10:21 nawk
-r-xr-xr-x   1 root wheel      32576 Nov 29 10:25 nc
-r-xr-xr-x   2 root wheel      27448 Nov 29 10:22 ncal
-r-xr-sr-x   1 root kmem      189968 Nov 29 10:22 netstat
lrwxr-xr-x   1 root wheel         19 Nov 29 10:23 newaliases -> ../sbin/mailwrapper
-r-xr-xr-x   1 root wheel      10600 Nov 29 10:22 newgrp
-r-xr-xr-x   1 root wheel      12144 Nov 29 10:25 newkey
-r-xr-xr-x   6 root wheel     457544 Nov 29 10:26 nex
-r-xr-xr-x   1 root wheel      26848 Nov 29 10:22 nfsstat
-r-xr-xr-x   1 root wheel       7336 Nov 29 10:22 nice
-r-xr-xr-x   1 root wheel      11896 Nov 29 10:22 nl
-r-xr-xr-x   1 root wheel      97512 Nov 29 10:25 nm
-r-xr-xr-x   1 root wheel       6944 Nov 29 10:22 nohup
-r-xr-xr-x   1 root wheel     339632 Nov 29 10:28 ntpq
-r-xr-xr-x   1 root wheel      10352 Nov 29 10:24 number
-r-xr-xr-x   6 root wheel     457544 Nov 29 10:26 nvi
-r-xr-xr-x   6 root wheel     457544 Nov 29 10:26 nview
-r-xr-xr-x   2 root wheel     126512 Nov 29 10:25 objcopy
-r-xr-xr-x   2 root wheel   17497456 Nov 29 10:23 objdump
-r-xr-xr-x   3 root wheel      29024 Nov 29 10:21 od
-r-xr-xr-x   1 root wheel     968784 Nov 29 10:21 openssl
-r-xr-xr-x   1 root wheel       1732 Nov 29 10:22 pagesize
-r-xr-xr-x   4 root wheel      56344 Nov 29 10:22 pargs
-r-sr-xr-x   1 root wheel       8968 Nov 29 10:22 passwd
-r-xr-xr-x   1 root wheel       7992 Nov 29 10:22 paste
-r-xr-xr-x   1 root wheel      59576 Nov 29 10:22 patch
-r-xr-xr-x   1 root wheel       7832 Nov 29 10:22 pathchk
-r-xr-xr-x   4 root wheel      56344 Nov 29 10:22 penv
-r-xr-xr-x   1 root wheel       5960 Nov 29 10:22 perror
-r-xr-xr-x   3 root wheel     159720 Nov 29 10:24 pftp
lrwxr-xr-x   1 root wheel         15 Nov 29 09:57 pgrep -> ../../bin/pgrep
lrwxr-xr-x   1 root wheel         15 Nov 29 09:57 pkill -> ../../bin/pkill
-r-xr-xr-x   1 root wheel      60824 Nov 29 10:29 pmcstudy
-r-xr-xr-x   1 root wheel      10320 Nov 29 10:24 pom
-r-xr-xr-x   1 root wheel      18192 Nov 29 10:22 posixmqcontrol
-r-xr-xr-x   1 root wheel      15584 Nov 29 10:22 posixshmcontrol
-r-xr-xr-x   1 root wheel      27872 Nov 29 10:22 pr
-r-xr-xr-x   1 root wheel      77624 Nov 29 10:24 primes
-r-xr-xr-x   1 root wheel       7488 Nov 29 10:22 printenv
-r-xr-xr-x   1 root wheel      13800 Nov 29 10:22 printf
-r-xr-xr-x   1 root wheel       8792 Nov 29 10:22 proccontrol
-r-xr-xr-x   4 root wheel      56344 Nov 29 10:22 procstat
-r-xr-xr-x   1 root wheel       7016 Nov 29 10:22 protect
-r-xr-xr-x   4 root wheel      56344 Nov 29 10:22 pwdx
-r-sr-xr-x   1 root wheel      16584 Nov 29 10:25 quota
-r-xr-xr-x   1 root wheel      11896 Nov 29 10:24 random
-r-xr-xr-x   2 root wheel      50520 Nov 29 10:25 ranlib
-r-xr-xr-x   1 root wheel      14880 Nov 29 10:22 rctl
-r-xr-xr-x  15 root wheel         74 Nov 29 10:21 read
-r-xr-xr-x   1 root wheel     156168 Nov 29 10:25 readelf
-r-xr-xr-x   2 root wheel      17176 Nov 29 10:22 readlink
-r-xr-xr-x   3 root wheel      94680 Nov 29 10:24 ree
-r-xr-xr-x   1 root wheel       7672 Nov 29 10:22 renice
-r-xr-xr-x   2 root wheel      22040 Nov 29 10:22 reset
-r-xr-xr-x   1 root wheel       7352 Nov 29 10:22 resizewin
-r-xr-xr-x   1 root wheel       6928 Nov 29 10:22 rev
-r-xr-xr-x   1 root wheel       5544 Nov 29 10:22 revoke
-r-xr-xr-x   1 root wheel      15064 Nov 29 10:24 rfcomm_sppd
-r-xr-xr-x   4 root wheel      29624 Nov 29 10:21 rgrep
-r-xr-xr-x   1 root wheel       1645 Nov 29 10:24 rot13
-r-xr-xr-x   1 root wheel      84208 Nov 29 10:26 rpcgen
-r-xr-xr-x   1 root wheel      26888 Nov 29 10:22 rpcinfo
-r-xr-xr-x   1 root wheel      25848 Nov 29 10:26 rping
-r-xr-xr-x   1 root wheel      16072 Nov 29 10:22 rs
-r-xr-xr-x   1 root wheel       8952 Nov 29 10:22 rup
-r-xr-xr-x   1 root wheel      10592 Nov 29 10:22 ruptime
-r-xr-xr-x   1 root wheel       9432 Nov 29 10:22 rusers
-r-xr-xr-x   1 root wheel       9384 Nov 29 10:22 rwall
-r-xr-xr-x   1 root wheel       9648 Nov 29 10:22 rwho
-r-xr-xr-x   1 root wheel     101488 Nov 29 10:21 scp
-r-xr-xr-x   1 root wheel      17976 Nov 29 10:22 script
-r-xr-xr-x   1 root wheel      25416 Nov 29 10:22 sdiff
-r-xr-xr-x   1 root wheel      39792 Nov 29 10:22 sed
-r-xr-xr-x   1 root wheel      12608 Nov 29 10:22 seq
-r-xr-xr-x   1 root wheel     114624 Nov 29 10:21 sftp
-r-xr-xr-x   1 root wheel       2442 Nov 29 10:22 shar
-r-xr-xr-x   1 root wheel      10256 Nov 29 10:22 showmount
-r-xr-xr-x   1 root wheel      21936 Nov 29 10:25 size
-r-xr-xr-x   1 root wheel      40976 Nov 29 10:15 slc
-r-xr-xr-x   2 root wheel     285888 Mar 22 11:31 slogin
-r-xr-xr-x   1 root wheel      20760 Nov 29 10:24 smbutil
-r-xr-xr-x   1 root wheel      27616 Nov 29 10:22 sockstat
-r-xr-xr-x   1 root wheel       8488 Nov 29 10:22 soelim
-r-xr-xr-x   1 root wheel      62304 Nov 29 10:22 sort
-r-xr-xr-x   1 root wheel      11728 Nov 29 10:22 split
-r-xr-xr-x   2 root wheel     285888 Mar 22 11:31 ssh
-r-xr-xr-x   1 root wheel      37800 Mar 22 11:31 ssh-add
-r-xr-xr-x   1 root wheel      66120 Mar 22 11:31 ssh-agent
-r-xr-xr-x   1 root wheel       2875 Nov 29 10:25 ssh-copy-id
-r-xr-xr-x   1 root wheel     117256 Mar 22 11:31 ssh-keygen
-r-xr-xr-x   1 root wheel      24776 Nov 29 10:21 ssh-keyscan
-r-xr-xr-x   2 root wheel      17176 Nov 29 10:22 stat
-r-xr-xr-x   1 root wheel       7176 Nov 29 10:22 stdbuf
-r-xr-xr-x   1 root wheel      12112 Nov 29 10:24 strfile
-r-xr-xr-x   1 root wheel      10984 Nov 29 10:15 string2key
-r-xr-xr-x   1 root wheel      16208 Nov 29 10:24 strings
-r-xr-xr-x   2 root wheel     126512 Nov 29 10:25 strip
-r-sr-xr-x   1 root wheel      17568 Nov 29 10:22 su
-r-xr-xr-x   2 root wheel      11296 Nov 29 10:21 sum
-r-xr-xr-x   1 root wheel     117264 Nov 29 10:22 systat
-r-xr-xr-x   1 root wheel      16832 Nov 29 10:22 tabs
-r-xr-xr-x   1 root wheel      22448 Nov 29 10:22 tail
-r-xr-xr-x   1 root wheel      25424 Nov 29 10:25 talk
lrwxr-xr-x   1 root wheel          6 Nov 29 10:22 tar -> bsdtar
-r-xr-xr-x   1 root wheel      10824 Nov 29 10:22 tcopy
-r-xr-xr-x   1 root wheel       8424 Nov 29 10:22 tee
-r-xr-xr-x   1 root wheel     164128 Nov 29 10:25 telnet
-r-xr-xr-x   1 root wheel      49952 Nov 29 10:25 tftp
-r-xr-xr-x   3 root wheel      88728 Nov 29 10:22 tic
-r-xr-xr-x   1 root wheel      11216 Nov 29 10:22 time
lrwxr-xr-x   1 root wheel         17 Nov 29 09:58 timeout -> ../../bin/timeout
-r-xr-xr-x   2 root wheel      74936 Nov 29 10:22 tip
-r-xr-xr-x   1 root wheel      16248 Nov 29 10:22 toe
-r-xr-xr-x   1 root wheel      72856 Nov 29 10:22 top
-r-xr-xr-x   1 root wheel      10336 Nov 29 10:22 touch
-r-xr-xr-x   1 root wheel      53472 Nov 29 10:22 tput
-r-xr-xr-x   1 root wheel      22256 Nov 29 10:22 tr
-r-xr-xr-x   1 root wheel       4944 Nov 29 10:22 true
-r-xr-xr-x   1 root wheel       8856 Nov 29 10:22 truncate
-r-xr-xr-x   1 root wheel     118096 Nov 29 10:24 truss
-r-xr-xr-x   2 root wheel      22040 Nov 29 10:22 tset
-r-xr-xr-x   1 root wheel      10416 Nov 29 10:22 tsort
-r-xr-xr-x   1 root wheel       5832 Nov 29 10:22 tty
-r-xr-xr-x  15 root wheel         74 Nov 29 10:21 type
-r-xr-xr-x   1 root wheel      18776 Nov 29 10:26 ucmatose
-r-xr-xr-x   1 root wheel      18144 Nov 29 10:26 udaddy
-r-xr-xr-x   1 root wheel      14248 Nov 29 10:25 ul
-r-xr-xr-x  15 root wheel         74 Nov 29 10:21 ulimit
-r-xr-xr-x  15 root wheel         74 Nov 29 10:21 umask
-r-xr-xr-x  15 root wheel         74 Nov 29 10:21 unalias
-r-xr-xr-x   1 root wheel      14472 Nov 29 10:22 uname
-r-xr-xr-x   2 root wheel      16872 Nov 29 10:21 uncompress
-r-xr-xr-x   1 root wheel       8432 Nov 29 10:22 unexpand
-r-xr-xr-x   1 root wheel      42928 Nov 29 10:26 unifdef
-r-xr-xr-x   1 root wheel       2096 Nov 29 10:26 unifdefall
-r-xr-xr-x   1 root wheel      13160 Nov 29 10:22 uniq
-r-xr-xr-x   1 root wheel      19056 Nov 29 10:22 units
-r-xr-xr-x   6 root wheel      77064 Nov 29 10:22 unlzma
-r-xr-xr-x   1 root wheel       7408 Nov 29 10:24 unstr
-r-xr-xr-x   1 root wheel       8232 Nov 29 10:22 unvis
-r-xr-xr-x   6 root wheel      77064 Nov 29 10:22 unxz
lrwxr-xr-x   1 root wheel          8 Nov 29 10:22 unzip -> bsdunzip
-r-xr-xr-x   4 root wheel     137800 Nov 29 10:22 unzstd
-r-xr-xr-x   2 root wheel      19248 Nov 29 10:22 uptime
-r-xr-xr-x   1 root wheel      15392 Nov 29 10:26 usbhidaction
-r-xr-xr-x   1 root wheel      15352 Nov 29 10:26 usbhidctl
-r-xr-xr-x   1 root wheel      13488 Nov 29 10:26 users
-r-xr-xr-x   6 root wheel      21648 Nov 29 10:21 uudecode
-r-xr-xr-x   6 root wheel      21648 Nov 29 10:21 uuencode
-r-xr-xr-x   1 root wheel     104560 Nov 29 10:25 vacation
-r-xr-xr-x   1 root wheel      29104 Nov 29 10:15 verify_krb5_conf
-r-xr-xr-x   6 root wheel     457544 Nov 29 10:26 vi
-r-xr-xr-x   6 root wheel     457544 Nov 29 10:26 view
-r-xr-xr-x   1 root wheel       9512 Nov 29 10:22 vis
-r-xr-xr-x   1 root wheel      39808 Nov 29 10:22 vmstat
-r-xr-xr-x   1 root wheel      28928 Nov 29 10:26 vtfontcvt
-r-xr-xr-x   2 root wheel      19248 Nov 29 10:22 w
-r-xr-xr-x  15 root wheel         74 Nov 29 10:21 wait
-r-xr-sr-x   1 root tty        14208 Nov 29 10:22 wall
-r-xr-xr-x   1 root wheel      12928 Nov 29 10:22 wc
-r-xr-xr-x   1 root wheel      91752 Nov 29 10:22 wg
-r-xr-xr-x   1 root wheel       7680 Nov 29 10:22 what
-r-xr-xr-x   4 root wheel     513696 Nov 29 10:22 whatis
-r-xr-xr-x   1 root wheel      15424 Nov 29 10:22 whereis
-r-xr-xr-x   1 root wheel       7224 Nov 29 10:22 which
-r-xr-xr-x   1 root wheel      10928 Nov 29 10:26 who
-r-xr-xr-x   3 root wheel      13232 Nov 29 10:21 whoami
-r-xr-xr-x   1 root wheel      15480 Nov 29 10:22 whois
-r-xr-sr-x   1 root tty        13848 Nov 29 10:22 write
-r-xr-xr-x   1 root wheel      17376 Nov 29 10:22 xargs
-r-xr-xr-x   1 root wheel      15568 Nov 29 10:22 xo
-r-xr-xr-x   1 root wheel      13016 Nov 29 10:26 xstr
-r-xr-xr-x   6 root wheel      77064 Nov 29 10:22 xz
-r-xr-xr-x   6 root wheel      77064 Nov 29 10:22 xzcat
-r-xr-xr-x   2 root wheel      10984 Nov 29 10:22 xzdec
-r-xr-xr-x   3 root wheel       3200 Nov 29 10:21 xzdiff
-r-xr-xr-x  15 root wheel       4167 Nov 29 10:21 xzegrep
-r-xr-xr-x  15 root wheel       4167 Nov 29 10:21 xzfgrep
-r-xr-xr-x  15 root wheel       4167 Nov 29 10:21 xzgrep
-r-xr-xr-x   5 root wheel         83 Nov 29 10:22 xzless
-r-xr-xr-x   2 root wheel     115024 Nov 29 10:26 yacc
-r-xr-xr-x   1 root wheel       6968 Nov 29 10:22 yes
-r-xr-xr-x   1 root wheel       7392 Nov 29 10:25 ypcat
lrwxr-xr-x   1 root wheel          6 Nov 29 10:21 ypchfn -> chpass
lrwxr-xr-x   1 root wheel          6 Nov 29 10:21 ypchpass -> chpass
lrwxr-xr-x   1 root wheel          6 Nov 29 10:21 ypchsh -> chpass
-r-xr-xr-x   1 root wheel       7656 Nov 29 10:25 ypmatch
lrwxr-xr-x   1 root wheel          6 Nov 29 10:22 yppasswd -> passwd
-r-xr-xr-x   1 root wheel      13952 Nov 29 10:25 ypwhich
-r-xr-xr-x   4 root wheel      64464 Nov 29 10:21 zcat
-r-xr-xr-x   3 root wheel       3200 Nov 29 10:21 zcmp
-r-xr-xr-x   3 root wheel       3200 Nov 29 10:21 zdiff
-r-xr-xr-x  15 root wheel       4167 Nov 29 10:21 zegrep
-r-xr-xr-x  15 root wheel       4167 Nov 29 10:21 zfgrep
-r-xr-xr-x   1 root wheel       1378 Nov 29 10:21 zforce
-r-xr-xr-x  15 root wheel       4167 Nov 29 10:21 zgrep
-r-xr-xr-x   1 root wheel      29040 Nov 29 10:12 zinject
-r-xr-xr-x   5 root wheel         83 Nov 29 10:22 zless
-r-xr-xr-x   1 root wheel       2006 Nov 29 10:21 zmore
-r-xr-xr-x   1 root wheel       3302 Nov 29 10:21 znew
-r-xr-xr-x   4 root wheel     137800 Nov 29 10:22 zstd
-r-xr-xr-x   4 root wheel     137800 Nov 29 10:22 zstdcat
-r-xr-xr-x  15 root wheel       4167 Nov 29 10:21 zstdegrep
-r-xr-xr-x  15 root wheel       4167 Nov 29 10:21 zstdfgrep
-r-xr-xr-x  15 root wheel       4167 Nov 29 10:21 zstdgrep
-r-xr-xr-x   5 root wheel         83 Nov 29 10:22 zstdless
-r-xr-xr-x   4 root wheel     137800 Nov 29 10:22 zstdmt
-r-xr-xr-x   1 root wheel      37672 Nov 29 10:12 zstream
lrwxr-xr-x   1 root wheel          7 Nov 29 10:12 zstreamdump -> zstream
-r-xr-xr-x   1 root wheel     158848 Nov 29 10:12 ztest

Файл: /usr/bin/env
Читання дозволено
Запис заборонено (Permission denied)
Виконання дозволено

Файл: /usr/bin/zless
Читання дозволено
Запис заборонено (Permission denied)
Виконання дозволено

Файл: /usr/bin/alias
Читання дозволено
Запис заборонено (Permission denied)
Виконання дозволено

Каталог: /etc
total 997
lrwxr-xr-x  1 root wheel       12 Nov 29 10:42 aliases -> mail/aliases
drwxr-xr-x  2 root wheel        2 Nov 29 09:54 authpf
-rw-r--r--  1 root wheel      151 Nov 29 10:25 auto_master
drwxr-xr-x  2 root wheel        9 Nov 29 10:25 autofs
-rw-r--r--  1 root wheel      379 Nov 29 10:25 blacklistd.conf
drwxr-xr-x  2 root wheel        5 Nov 29 10:26 bluetooth
drwxr-xr-x  2 root wheel        3 Nov 29 10:24 cron.d
-rw-r--r--  1 root wheel      646 Nov 29 10:22 crontab
-rw-r--r--  1 root wheel       40 Nov 29 09:58 csh.cshrc
-rw-r--r--  1 root wheel      288 Nov 29 09:58 csh.login
-rw-r--r--  1 root wheel       41 Nov 29 09:58 csh.logout
-rw-r--r--  1 root wheel      494 Nov 29 10:16 ddb.conf
drwxr-xr-x  2 root wheel        6 Nov 29 10:26 defaults
drwxr-xr-x  2 root wheel       15 Nov 29 10:26 devd
-rw-r--r--  1 root wheel     6107 Nov 29 10:16 devd.conf
-rw-r--r--  1 root wheel     1917 Nov 29 10:16 devfs.conf
-rw-r--r--  1 root wheel      193 Nov 29 10:16 dhclient.conf
-rw-r--r--  1 root wheel     5826 Nov 29 10:16 disktab
drwxr-xr-x  2 root wheel        3 Nov 29 09:56 dma
-rw-rw-r--  1 root operator     0 Nov 29 10:16 dumpdates
-rw-r--r--  1 root wheel       78 Nov 29 10:22 fbtab
-rw-r--r--  1 root wheel     2885 Nov 29 10:26 freebsd-update.conf
-rw-r--r--  1 root wheel      124 Feb 14 17:31 fstab
-rw-r--r--  1 root wheel      212 Nov 29 09:56 ftpusers
-rw-r--r--  1 root wheel     6120 Nov 29 09:56 gettytab
-rw-r--r--  1 root wheel      680 Mar  6 12:34 group
drwxr-xr-x  2 root wheel        4 Nov 29 10:42 gss
-rw-r--r--  1 root wheel       37 Feb 14 16:28 hostid
-rw-r--r--  1 root wheel     1035 Nov 29 10:02 hosts
-rw-r--r--  1 root wheel     3385 Nov 29 10:04 hosts.allow
-rw-r--r--  1 root wheel       41 Nov 29 10:02 hosts.equiv
-rw-r--r--  1 root wheel       31 Nov 29 10:27 hosts.lpd
-rw-r--r--  1 root wheel     6311 Nov 29 10:26 inetd.conf
drwxr-xr-x  2 root wheel        2 Nov 29 09:54 jail.conf.d
drwxr-xr-x  2 root wheel        3 Nov 29 10:25 kyua
-rw-r--r--  1 root wheel      133 Nov 29 10:02 libalias.conf
-rw-r--r--  1 root wheel       35 Nov 29 09:56 libmap.conf
-r--r--r--  1 root wheel      114 Feb 14 16:25 localtime
-rw-r--r--  1 root wheel      862 Nov 29 10:24 locate.rc
-rw-r--r--  1 root wheel     1773 Nov 29 10:22 login.access
-rw-r--r--  1 root wheel     7116 Nov 29 10:22 login.conf
-rw-r--r--  1 root wheel    16384 Mar 22 11:31 login.conf.db
-rw-r--r--  1 root wheel      495 Nov 29 10:02 mac.conf
-rw-r--r--  1 root wheel       33 Feb 14 16:28 machine-id
drwxr-xr-x  2 root wheel       16 Nov 29 10:42 mail
-rw-r--r--  1 root wheel      106 Nov 29 10:24 mail.rc
-rw-------  1 root wheel     3097 Mar  6 12:37 master.passwd
lrwxr-xr-x  1 root wheel       13 Feb 14 16:28 motd -> /var/run/motd
-rw-r--r--  1 root wheel      849 Nov 29 10:22 motd.template
drwxr-xr-x  2 root wheel       10 Nov 29 10:42 mtree
-rw-r--r--  1 root wheel      717 Nov 29 10:02 netconfig
-rwxr-xr-x  1 root wheel     2109 Nov 29 09:56 netstart
-rw-r--r--  1 root wheel    36848 Nov 29 09:56 network.subr
-rw-r--r--  1 root wheel      298 Nov 29 10:02 networks
-rw-r--r--  1 root wheel     1697 Nov 29 10:23 newsyslog.conf
drwxr-xr-x  2 root wheel        8 Nov 29 10:23 newsyslog.conf.d
-rw-r--r--  1 root wheel      219 Nov 29 10:27 nscd.conf
-rw-------  1 root wheel     1623 Nov 29 10:04 nsmb.conf
-rw-r--r--  1 root wheel      260 Nov 29 10:02 nsswitch.conf
drwx------  2 root wheel        3 Nov 29 10:28 ntp
-rw-r--r--  1 root wheel     4393 Nov 29 10:28 ntp.conf
lrwxr-xr-x  1 root wheel       21 Nov 29 10:42 os-release -> ../var/run/os-release
drwxr-xr-x  2 root wheel       16 Feb 14 16:25 pam.d
-rw-r--r--  1 root wheel     2469 Mar 22 11:31 passwd
-rwxr-xr-x  1 root wheel     2735 Nov 29 09:56 pccard_ether
drwxr-xr-x  6 root wheel        6 Nov 29 09:54 periodic
-rw-r--r--  1 root wheel    29273 Nov 29 10:17 pf.os
-rw-r--r--  1 root wheel      171 Nov 29 10:22 phones
drwxr-xr-x  2 root wheel        3 Nov 29 10:29 pkg
drwxr-xr-x  2 root wheel        3 Nov 29 10:29 ppp
-rw-r--r--  1 root wheel     1968 Nov 29 10:27 printcap
-rw-r--r--  1 root wheel      889 Nov 29 09:58 profile
drwxr-xr-x  2 root wheel        2 Nov 29 09:54 profile.d
-rw-r--r--  1 root wheel     6382 Nov 29 10:02 protocols
-rw-r--r--  1 root wheel    40960 Mar 22 11:31 pwd.db
-rw-r--r--  1 root wheel     5086 Nov 29 09:56 rc
-rw-r--r--  1 root wheel     4531 Nov 29 09:56 rc.bsdextended
-rw-r--r--  1 root wheel      378 Mar 23 19:32 rc.conf
drwxr-xr-x  2 root wheel        2 Nov 29 09:54 rc.conf.d
drwxr-xr-x  2 root wheel      175 Nov 29 09:56 rc.d
-rw-r--r--  1 root wheel    18696 Nov 29 09:56 rc.firewall
-rw-r--r--  1 root wheel    13689 Nov 29 09:56 rc.initdiskless
-rwxr-xr-x  1 root wheel     2239 Nov 29 09:56 rc.resume
-rw-r--r--  1 root wheel     3400 Nov 29 09:56 rc.shutdown
-rw-r--r--  1 root wheel    53442 Nov 29 09:56 rc.subr
-rwxr-xr-x  1 root wheel     2351 Nov 29 09:56 rc.suspend
-rw-r--r--  1 root wheel    61412 Nov 29 10:03 regdomain.xml
-rw-r--r--  1 root wheel     2627 Nov 29 10:22 remote
-rw-r--r--  1 root wheel       47 Feb 14 16:28 resolv.conf
-rw-r--r--  1 root wheel       21 Feb 14 16:28 resolv.conf.bak
lrwxr-xr-x  1 root wheel       15 Nov 29 10:42 rmt -> ../usr/sbin/rmt
-rw-r--r--  1 root wheel     1608 Nov 29 10:02 rpc
drwxr-xr-x  2 root wheel        7 Nov 29 10:25 security
-rw-r--r--  1 root wheel    72588 Nov 29 10:23 services
-rw-r--r--  1 root wheel      195 Feb 14 16:07 shells
-rw-------  1 root wheel     9803 Nov 29 10:26 snmpd.config
-rw-------  1 root wheel    40960 Mar 22 11:31 spwd.db
drwxr-xr-x  2 root wheel       11 Feb 14 16:28 ssh
drwxr-xr-x  4 root wheel        6 Feb 14 15:59 ssl
-rw-r--r--  1 root wheel      326 Feb 14 16:26 sysctl.conf
drwxr-xr-x  2 root wheel        2 Nov 29 09:54 sysctl.kld.d
-rw-r--r--  1 root wheel     1421 Nov 29 10:23 syslog.conf
drwxr-xr-x  2 root wheel        5 Nov 29 10:23 syslog.d
lrwxr-xr-x  1 root wheel       23 Nov 29 10:42 termcap -> /usr/share/misc/termcap
-rw-r--r--  1 root wheel     9272 Nov 29 10:30 termcap.small
-rw-r--r--  1 root wheel     2237 Nov 29 10:16 ttys
lrwxr-xr-x  1 root wheel       14 Nov 29 10:42 unbound -> ../var/unbound
drwxr-xr-x  2 root wheel        2 Nov 29 09:54 X11
drwxr-xr-x  3 root wheel        5 Feb 14 16:28 zfs

Файл: /etc/rc.conf
Читання дозволено
Запис заборонено (Permission denied)
Виконання заборонено (Permission denied)

Файл: /etc/motd
Читання дозволено
Запис заборонено (Permission denied)
Виконання заборонено (Permission denied)

Файл: /etc/printcap
Читання дозволено
Запис заборонено (Permission denied)
Виконання заборонено (Permission denied)
lilpeep@avice:~/pw9 $ 
lilpeep@avice:~/pw9 $ 


```


## Завдання по варiанту 11

Чим відрізняється виконання `id` у `shell` та з системного виклику? Протестуйте в різних середовищах.

### Виконання:

Було використано системні виклики `getuid()`, `getgid()` і `getgroups()` для отримання ідентифікаторів користувача. Результати порівняно з командою `id`, яка додатково виводить імена користувачів/груп. Це показало різницю між системним рівнем та рівнем оболонки.


``` 
lilpeep@avice:~/pw9 $ gcc -Wall 11.c -o 11
lilpeep@avice:~/pw9 $ ./11
UID: 1003
GID: 1003
Groups (2):
  1003
  0
lilpeep@avice:~/pw9 $
```


```
lilpeep@avice:~/pw9 $ id
uid=1003(lilpeep) gid=1003(lilpeep) groups=1003(lilpeep),0(wheel)
```




