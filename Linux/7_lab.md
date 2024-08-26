# Модули ядра

## Что за модули?

Ядро GNU/Linux является [монолитным](https://ru.wikipedia.org/wiki/%D0%9C%D0%BE%D0%BD%D0%BE%D0%BB%D0%B8%D1%82%D0%BD%D0%BE%D0%B5_%D1%8F%D0%B4%D1%80%D0%BE), то есть все его драйвера и подсистемы работают в своем адресном пространстве, отделенном от пользовательского.

Модули позволяют добавлять или убирать функционал Linux без надобности рекомпилировать ядро.

## Суть лабораторной работы

Лабораторная работа №7 (№2 относительно семестра) требует от вас собрать несколько модулей ядра, загрузить их в системе и продемонстрировать результат преподавателю.

В этой статье я опишу актуальный способ выполнения работы. В методичке с dl работа выполняется на версии ядра 2.x.x, мы делаем её на более свежей 6.x.x.

## Подготовка

> [!NOTE]
> Гайд предназначен для Debian 12 Bookworm, но совместим с Ubuntu/другими Debian-based дистрибутивами при условии соблюдения версий пакетов

### Установка зависимостей сборки

Для того, чтобы собирать модули ядра, нужно установить пакет `build-essential` (включает `gcc`, `make`). После выполнения работы №6 он, возможно, имеется у вас в системе.

Также требуется установить пакет с заголовочными файлами вашего ядра. На Debian 12 это `linux-headers-6.1.0-18-amd64`, для ARM (e.g. MacBook на M-чипе) - `linux-headers-6.1.0-18-arm64`.

TL;DR:

```sh
sudo apt install -y build-essential linux-headers-6.1.0-18-amd64
# или если ARM
sudo apt install -y build-essential linux-headers-6.1.0-18-arm64
```

> [!CAUTION]
> В репозитории, скорее всего, имеются заголовки ядра только той версии ядра, которая поставлялась с ним из коробки. Для выполнения работы советую перейти под ядро, предоставляемое дистрибутивом. У Debian 12 это `6.1.0`.

## Выполнение работы

Если игнорировать "канон", задаваемый методичкой, работу можно выполнить всего лишь создав один Makefile, ~~написав~~ скопировав 6 программ на C и выполнив пару команд в терминале.

### Написание и загрузка первого модуля ядра

> [!NOTE]
> Это интерпретация примера №1. из методички, что является заимствованием  [TLKMPG, 4.1](https://sysprog21.github.io/lkmpg/#the-simplest-module).

Код на C сохраняем в файл `hello-1.c`:

```c
#include <linux/module.h> /* Требуется для всех модулей */
#include <linux/printk.h> /* Требуется для pr_info() */

int init_module(void)
{
    /* Выводит строку в буфер сообщений ядра (dmesg) */
    pr_info("Hello world 1.\n");

    /* Ненулевой код возврата означает ошибку при работе init_module. В этом случае модуль не будет загружен */
    return 0;
}

/* Будет выполнена при отключении модуля (rmmod) */
void cleanup_module(void)
{
    pr_info("Goodbye world 1.\n");
}

/* Тег для указания лицензии, под которой распространяется модуль */
/* see: https://www.kernel.org/doc/html/latest/process/license-rules.html#id1 */
MODULE_LICENSE("GPL");
```

В Makefile записываем следующее:

```Makefile
obj-m += hello-1.o

PWD := $(CURDIR)
```

После всего запускаем следующее:

```sh
# Держите в голове, что версия ядра может отличаться. Заранее проверьте, есть ли директория при флаге -C
make -C /lib/modules/6.1.0-18-common/build/ M=$PWD modules
# Или, если у вас ARM
make -C /lib/modules/6.1.0-18-arm64/build/ M=$PWD modules
```

После этого в терминале должно появится примерно следующее:

```
make: Entering directory '/usr/src/linux-headers-6.1.0-18-arm64'
make: Leaving directory '/usr/src/linux-headers-6.1.0-18-arm64'
```

А в активной директории появится несколько новых файлов, в том числе `hello-1.ko`. Это собранный модуль, который может загрузить ядро.

Теперь загрузим модуль следующей командой:

```
sudo insmod hello-1.ko
```

Если команда ничего не вывела - то вы только что успешно загрузили модуль! Проверьте журнал сообщений:

```sh
sudo dmesg
```

В конце должно появится заветное:

```
[   20.873534] Hello world 1.
```

Можно попробовать выгрузить модуль...

```sh
sudo rmmod hello-1.ko
```

...и снова посмотреть логи ядра (`dmesg`).

### Собираем и грузим несколько модулей сразу

> Адаптация примера 3 из методички

В работе потребуется подгрузить сразу 6 модулей ядра. Конечно, можно сделать это в 6 команд:

```sh
sudo insmod hello-1.ko
sudo insmod hello-2.ko
sudo insmod hello-3.ko
sudo insmod hello-4.ko
sudo insmod hello-5.ko
sudo insmod startstop.ko
```

Однако, имеется способ и лучше. Для этого опишем и соберем еще один модуль, `hello-2`, показывающий использование макроопределений `module_init` и `module_exit`.

```c
/* hello-2.c */
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>

static int __init hello_2_init(void)
{
 printk(KERN_ALERT "Hello, world 2\n");
 return 0;
}

static void __exit hello_2_exit(void)
{
 printk(KERN_ALERT "Goodbye, world 2\n");
}

module_init(hello_2_init);
module_exit(hello_2_exit);
MODULE_LICENSE("GPL");
```

Дополним Makefile: добавим строку `obj-m += hello-2.o`, чтобы вышло следующее:

```Makefile
obj-m += hello-1.o
obj-m += hello-2.o

PWD := $(CURDIR)
```

Соберем модули:

```sh
make -C /lib/modules/VERSION/build/ M=$PWD modules
```

Теперь необходимо создать [символьные ссылки](https://www.gnu.org/software/coreutils/manual/html_node/ln-invocation.html#ln-invocation) на модули в директории `/lib/modules/VERSION`:

```sh
sudo ln -s $PWD/hello-1.ko /lib/modules/6.1.0-18-arm64/
sudo ln -s $PWD/hello-2.ko /lib/modules/6.1.0-18-arm64/
```

Сгенерируем файл зависимости модулей `modules.dep`:

```sh
sudo depmod -a
```

Воспользуемся командой `modprobe` для загрузки модулей:

```sh
sudo modprobe -a hello-1 hello-2
```

Снова проверьте `dmesg`, там появится вывод от этих модулей.

### Остальная работа

Далее приведены только примеры адаптированные примеры кода из методчики:

#### *Пример 5. hello-3.c*

```c
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
static int hello3_data __initdata = 3;
static int __init hello_3_init(void)
{
 printk(KERN_ALERT "Hello, world %d\n", hello3_data);
 return 0;
}
static void __exit hello_3_exit(void)
{
 printk(KERN_ALERT "Goodbye, world 3\n");
}
module_init(hello_3_init);
module_exit(hello_3_exit);
MODULE_LICENSE("GPL");
```

Дополнение к Makefile:

```Makefile
obj-m += hello-3.o
```

#### *Пример 6. hello-4.c*

> [!NOTE]
> Методичка только в этом примере приводит определение `MODULE_LICENSE`. На 2.x.x без определения модуль работал, но предупреждал о "загрязнении". А сейчас модуль и вовсе не собирается, давая ошибку `missing MODULE_LICENSE()`. Поэтому он есть и в примерах выше.

```c
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#define DRIVER_AUTHOR "Peter Jay Salzman <p@dirac.org>"
#define DRIVER_DESC "A sample driver"
static int __init init_hello_4(void)
{
 printk(KERN_ALERT "Hello, world 4\n");
 return 0;
}
static void __exit cleanup_hello_4(void)
{
 printk(KERN_ALERT "Goodbye, world 4\n");
}
module_init(init_hello_4);
module_exit(cleanup_hello_4);
MODULE_LICENSE("GPL");
MODULE_AUTHOR(DRIVER_AUTHOR);
MODULE_DESCRIPTION(DRIVER_DESC);
```

Дополнение к Makefile:

```Makefile
obj-m += hello-4.o
```

#### *Пример 7. hello-5.c*

```c
#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/stat.h>
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Peter Jay Salzman");
static short int myshort = 1;
static int myint = 420;
static long int mylong = 9999;
static char *mystring = "blah";
module_param(myshort, short, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP);
MODULE_PARM_DESC(myshort, "A short integer");
module_param(myint, int, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
MODULE_PARM_DESC(myint, "An integer");
module_param(mylong, long, S_IRUSR);
MODULE_PARM_DESC(mylong, "A long integer");
module_param(mystring, charp, 0000);
MODULE_PARM_DESC(mystring, "A character string");
static int __init hello_5_init(void)
{
 printk(KERN_ALERT "Hello, world 5\n=============\n");
 printk(KERN_ALERT "myshort is a short integer: %hd\n", myshort);
 printk(KERN_ALERT "myint is an integer: %d\n", myint);
 printk(KERN_ALERT "mylong is a long integer: %ld\n", mylong);
 printk(KERN_ALERT "mystring is a string: %s\n", mystring);
 return 0;
}
static void __exit hello_5_exit(void)
{
 printk(KERN_ALERT "Goodbye, world 5\n");
}
module_init(hello_5_init);
module_exit(hello_5_exit);
```

Дополнение к Makefile:

```Makefile
obj-m += hello-5.o
```

#### *Пример 8-9. Модули, состоящие из нескольких файлов*

```c
// Пример 8. start.c
#include <linux/kernel.h>
#include <linux/module.h>
int init_module(void)
{
 printk("Hello, world - this is the kernel speaking\n");
 return 0;
}
MODULE_LICENSE("GPL");
```

```c
// Пример 9. stop.c
#include <linux/kernel.h>
#include <linux/module.h>
void cleanup_module()
{
 printk("<1>Short is the life of a kernel module\n");
}
MODULE_LICENSE("GPL");
```

Дополнение к Makefile:

```Makefile
obj-m += startstop.o
startstop-objs := start.o stop.o
```

#### Собираем все вместе

Makefile должен быть таким:

```Makefile
obj-m += hello-1.o
obj-m += hello-2.o
obj-m += hello-3.o
obj-m += hello-4.o
obj-m += hello-5.o
obj-m += startstop.o
startstop-objs := start.o stop.o

PWD := $(CURDIR)
```

Собираем модули:

```sh
make -C /lib/modules/VERSION/build/ M=$PWD modules
```

Создаем симлинки:

```sh
sudo ln -s $PWD/hello-1.ko /lib/modules/VERSION/ # если не создавали
sudo ln -s $PWD/hello-2.ko /lib/modules/VERSION/ # если не создавали
sudo ln -s $PWD/hello-3.ko /lib/modules/VERSION/
sudo ln -s $PWD/hello-4.ko /lib/modules/VERSION/
sudo ln -s $PWD/hello-5.ko /lib/modules/VERSION/
sudo ln -s $PWD/startstop.ko /lib/modules/VERSION/
```

AND FINALLY,

```sh
sudo depmod -a
sudo modprobe -a hello-1 hello-2 hello-3 hello-4 hello-5 startstop
```

Проверьте логи ядра, а также посмотите список загруженных модулей:

```sh
ls /proc/modules # "как-то сложно"
lsmod
```

## Литература

- [The Linux Kernel Module Programming Guide](https://sysprog21.github.io/lkmpg/#the-simplest-module) // sysprog21.github.io
- [Справочные страницы по `kmod` в Debian](https://manpages.debian.org/bookworm/kmod/index.html): [`lsmod`](https://manpages.debian.org/bookworm/kmod/lsmod.8.en.html), [`insmod`](https://manpages.debian.org/bookworm/kmod/insmod.8.en.html), [`rmmod`](https://manpages.debian.org/bookworm/kmod/rmmod.8.en.html), [`modprobe`](https://manpages.debian.org/bookworm/kmod/modprobe.8.en.html) // manpages.debian.org
- [Неолурк: Линукс](https://neolurk.org/wiki/%D0%9B%D0%B8%D0%BD%D1%83%D0%BA%D1%81) // neolurk.org
