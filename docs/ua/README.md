[![template](https://img.shields.io/badge/Repository-template-darkred)](https://github.com/Nakama3942/template_rep)
[![GitHub license](https://img.shields.io/github/license/Nakama3942/ALGOR?color=gold&style=flat-square)](https://github.com/Nakama3942/ALGOR/blob/main/LICENSE)

[![CHANGELOG](https://img.shields.io/badge/here-CHANGELOG-yellow)](https://github.com/Nakama3942/ALGOR/blob/main/CHANGELOG.md)
[![CONTRIBUTING](https://img.shields.io/badge/here-CONTRIBUTING-indigo)](https://github.com/Nakama3942/ALGOR/blob/main/CONTRIBUTING.md)
[![CODE_OF_CONDUCT](https://img.shields.io/badge/here-CODE_OF_CONDUCT-darkgreen)](https://github.com/Nakama3942/ALGOR/blob/main/CODE_OF_CONDUCT.md)
[![PULL_REQUEST_TEMPLATE](https://img.shields.io/badge/here-PULL_REQUEST_TEMPLATE-orange)](https://github.com/Nakama3942/ALGOR/blob/main/.github/PULL_REQUEST_TEMPLATE.md)

# ALGOR
## Огляд
Бібліотека для обробки та сортування структур даних.

У пошуках алгоритмів сортування та пояснень у вигляді коду я часто зустрічав великі коди з купою непотрібних речей, не пов'язаних з алгоритмом сортування (наприклад, тестування) і, в принципі, код містив змінні не зі звичайними іменами, а з назвами типу A, B, C - стиль коду порушений (а іноді навіть жахливий), іноді можна виявити збиту табуляцію та є купа інших факторів, які роблять код нечитабельним і недоступним для розуміння. Я витратив багато часу, щоб зрозуміти ці алгоритми і написав цю бібліотеку, по-перше, щоб не писати щоразу одне і те ж, а просто підключити бібліотеку і використовувати готовий код, а по-друге для інших людей, які тільки навчаються алгоритмам, щоб можна було легко розібратися: код містить лише необхідні методи, вони розташовані по порядку, код я намагаюся оптимізувати, стиль не порушений, і головне - завдяки нормальним іменам код зрозуміліший, читабельніший і підходить для навчання алгоритмам.

## Функціонал
Бібліотека реалізує наступний функціонал:
- *ALGOR_CORE*
	- Розділ реалізації головних базових функцій, класів і визначень
- *ALGOR_EXCEPTION*
	- Розділ реалізації винятків
- *ALGOR_RANDOM*
	- Розділ реалізації рандомайзерів
- *ALGOR_ARRAY*
	- Розділ реалізації класів та функцій роботи з масивами
- *ALGOR_SORTING*
	- Розділ реалізації алгоритмів сортування

## Використання
Бібліотека призначена для компіляції та динамічного лінкування. Однак можна помістити файли ALGOR.hpp і ALGOR.cpp у свій проект і просто підключити заголовок:
```cpp
#include "ALGOR.hpp"
```
Якщо ви дотримуєтеся ідеї, то після компіляції бібліотеки в налаштуваннях вашого проекту потрібно вказати шлях до .a-файлу, а в джерелі просто підключити заголовок, як показано вище. Сама бібліотека (.dll або .so) повинна бути розміщена поруч із виконуваним файлом, щоб вона (програма) працювала.

## Збірка проекту
Бібліотека призначена для динамічного підключення. Перш ніж використовувати бібліотеку, потрібно спершу зібрати бібліотеку. Розробка здійснюється на IDE Qt, проте цей проект залишається незалежним і написаний на чистому C++. Вам просто потрібно клонувати репозиторій, відкрити проект у Qt і скомпілювати бібліотеку. Ви можете використовувати іншу IDE або скомпілювати її самостійно в терміналі.

## Вирішення проблем
Всі алгоритми перевірені мною, але якщо у вас виникли проблеми з використанням бібліотеки, код не працює, є пропозиції щодо оптимізації або поради щодо покращення стилю коду та імен - запрошую [сюди](https://github.com/Nakama3942/ALGOR/blob/main/CONTRIBUTING.md) та [сюди](https://github.com/Nakama3942/ALGOR/blob/main/CODE_OF_CONDUCT.md).

## Автори
<table>
	<tr>
		<td align="center"><a href="https://github.com/Nakama3942"><img src="https://avatars.githubusercontent.com/u/73797846?s=400&u=a9b7688ac521d739825d7003a5bd599aab74cb76&v=4" width="150px;" alt=""/><br /><sub><b>Калиновський Валентин</b></sub></a><sub><br />"Ідейний натхненник і Автор"</sub></td>
		<!--<td></td>-->
	</tr>
<!--
	<tr>
		<td></td>
		<td></td>
	</tr>
-->
</table>