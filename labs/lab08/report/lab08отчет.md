---
## Front matter
lang: ru-RU
title: Текстовой редактор vi
author: |
	Roza A. Bekbuzarova\inst{1}
institute: |
	\inst{1}RUDN University, Moscow, Russian Federation
date: 2022, 7 May

## Formatting
toc: false
slide_level: 2
theme: metropolis
header-includes: 
 - \metroset{progressbar=frametitle,sectionpage=progressbar,numbering=fraction}
 - '\makeatletter'
 - '\beamer@ignorenonframefalse'
 - '\makeatother'
aspectratio: 43
section-titles: true
---

## Цель работы

Познакомиться с операционной системой Linux. Получить практические навыки работы с редактором vi, установленным по умолчанию практически во всех дистрибутивах.

## Ход работы

1. Ознакомиться с теоретическим материалом.
2. Ознакомиться с редактором vi.
3. Выполнить упражнения, используя команды vi.
1. Создайте каталог с именем ~/work/os/lab06.
![Screen](1gh.jpg)
2. Перейдите во вновь созданный каталог.
3. Вызовите vi и создайте файл hello.sh
  vi hello.sh
  ![Screen](2gh.jpg)
4. Нажмите клавишу i и вводите следующий текст.
1 #!/bin/bash
2 HELL=Hello
3 function hello {
4 LOCAL HELLO=World
5 echo $HELLO
6 }
7 echo $HELLO
8 hello
![Screen](3gh.jpg)

---

5. Нажмите клавишу Esc для перехода в командный режим после завершения ввода
текста.
6. Нажмите : для перехода в режим последней строки и внизу вашего экрана появится
приглашение в виде двоеточия.
7. Нажмите w (записать) и q (выйти), а затем нажмите клавишу Enter для сохранения
вашего текста и завершения работы.
8. Сделайте файл исполняемым
  chmod +x hello.sh
  

---

8.3.2. Задание 2. Редактирование существующего файла
1. Вызовите vi на редактирование файла
 vi ~/work/os/lab06/hello.sh
![Screen](4gh.jpg)
2. Установите курсор в конец слова HELL второй строки.
3. Перейдите в режим вставки и замените на HELLO. Нажмите Esc для возврата в командный режим.
4. Установите курсор на четвертую строку и сотрите слово LOCAL.
5. Перейдите в режим вставки и наберите следующий текст: local, нажмите Esc для
возврата в командный режим.
6. Установите курсор на последней строке файла. Вставьте после неё строку, содержащую
следующий текст: echo $HELLO.
![Screen](5gh.jpg)

---

7. Нажмите Esc для перехода в командный режим.
8. Удалите последнюю строку.
9. Введите команду отмены изменений u для отмены последней команды.
10. Введите символ : для перехода в режим последней строки. Запишите произведённые
изменения и выйдите из vi.

---

## Вывод

Ознакомились с инструментами поиска файлов и  фильтрации текстовых данных. Приобрели  практические навыки по управлению  процессами (и заданиями), по проверке  использования диска и обслуживанию файловых  систем.


