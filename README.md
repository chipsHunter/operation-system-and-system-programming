## Лабораторная работа №1
Утилита `find` Linux 

**********************************  

### Задание  

Программа **_dirwalk_** с выводом, аналогичным утилите `find` :  

`dirwalk FILEPATH OPTIONS` 

> [!TIP]  
> `FILEPATH` и `OPTIONS` не обязательны. По умолчанию `FILEPATH` - каталог с проектом. Опции могут быть заданы как раздельно, так и вместе ( `-ldfs` & `-l -f` корректны)

*****************************  

### Список опций  
* `-l` -> символмческие ссылки
* `-f` -> файлы
* `-d` -> каталоги
* `-s` -> сортировать вывод в соответствии с `LC_COLLATE`

********************************

Результат программы записывается в `stdout`
