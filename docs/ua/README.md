[![template](https://img.shields.io/badge/Repository-template-darkred)](https://github.com/Nakama3942/template_rep)
[![GitHub license](https://img.shields.io/github/license/Nakama3942/ALGOR?color=gold&style=flat-square)](https://github.com/Nakama3942/ALGOR/blob/main/LICENSE)

[![CHANGELOG](https://img.shields.io/badge/here-CHANGELOG-yellow)](https://github.com/Nakama3942/ALGOR/blob/main/CHANGELOG.md)
[![CONTRIBUTING](https://img.shields.io/badge/here-CONTRIBUTING-indigo)](https://github.com/Nakama3942/ALGOR/blob/main/CONTRIBUTING.md)
[![CODE_OF_CONDUCT](https://img.shields.io/badge/here-CODE_OF_CONDUCT-darkgreen)](https://github.com/Nakama3942/ALGOR/blob/main/CODE_OF_CONDUCT.md)
[![PULL_REQUEST_TEMPLATE](https://img.shields.io/badge/here-PULL_REQUEST_TEMPLATE-orange)](https://github.com/Nakama3942/ALGOR/blob/main/.github/PULL_REQUEST_TEMPLATE.md)

<img src="LOGO.png" width="940">

# ALGOR
## Зміст
- [ALGOR](#algor)
	- [Зміст](#зміст)
	- [Огляд](#огляд)
	- [ЛІЦЕНЗІЯ](#ліцензія)
	- [Функціонал](#функціонал)
	- [Документація](#документація)
	- [Використання](#використання)
	- [Збірка проекту](#збірка-проекту)
		- [Через IDE (Windows)](#через-ide-windows)
		- [Через IDE (LINUX)](#через-ide-linux)
		- [Через консоль (Windows)](#через-консоль-windows)
		- [Через консоль (LINUX)](#через-консоль-linux)
		- [Тест консольної збірки](#тест-консольної-збірки)
	- [Вирішення проблем](#вирішення-проблем)
	- [Автори](#автори)
	- [Гіфки](#гіфки)
		- [Компіляція та лінковка на Windows у IDE](#компіляція-та-лінковка-на-windows-у-ide)
		- [Компіляція та лінковка на Windows у консолі](#компіляція-та-лінковка-на-windows-у-консолі)
		- [Компіляція та лінковка на Linux у консолі](#компіляція-та-лінковка-на-linux-у-консолі)
		- [Збірка бібліотеки через консоль у Windows](#збірка-бібліотеки-через-консоль-у-windows)
		- [Збірка бібліотеки через консоль у Linux](#збірка-бібліотеки-через-консоль-у-linux)
		- [Тест зібраної бібліотеки через консоль](#тест-зібраної-бібліотеки-через-консоль)

## Огляд
Бібліотека для обробки та сортування структур даних.

У пошуках алгоритмів сортувань та пояснень у вигляді коду я часто зустрічав великі коди з купою непотрібних речей, не пов'язаних з алгоритмом сортування (наприклад, тестування) і, в принципі, код містив змінні не зі звичайними іменами, а з назвами типу A, B, C - стиль коду порушений (а іноді навіть жахливий), іноді можна виявити збиту табуляцію та є купа інших факторів, які роблять код нечитабельним і недоступним для розуміння. Я витратив багато часу, щоб зрозуміти ці алгоритми і написав цю бібліотеку, по-перше, щоб не писати щоразу одне і те ж, а просто підключити бібліотеку і використовувати готовий код, а по-друге для інших людей, які тільки навчаються алгоритмам, щоб можна було легко розібратися: код містить лише необхідні методи, вони розташовані по порядку, код я намагаюся оптимізувати, стиль не порушений, і головне - завдяки нормальним іменам код зрозуміліший, читабельніший і підходить для навчання алгоритмам.

## ЛІЦЕНЗІЯ
Повний текст ліцензії знаходиться за наступним [посиланням](https://github.com/Nakama3942/ALGOR/blob/main/LICENSE).

> Copyright © 2021-2022 Kalynovsky Valentin. All rights reserved.
> 
> Licensed under the Apache License, Version 2.0 (the "License");
> you may not use this file except in compliance with the License.
> You may obtain a copy of the License at
> 
>     http://www.apache.org/licenses/LICENSE-2.0
> 
> Unless required by applicable law or agreed to in writing, software
> distributed under the License is distributed on an "AS IS" BASIS,
> WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
> See the License for the specific language governing permissions and
> limitations under the License.

## Функціонал
Бібліотека реалізує наступний функціонал:
- [x] *ALGOR_CORE*
	- Розділ реалізації головних базових функцій, класів і визначень
- [x] *ALGOR_EXCEPTION*
	- Розділ реалізації винятків
- [x] *ALGOR_RANDOM*
	- Розділ реалізації рандомайзерів
- [x] *ALGOR_ARRAY*
	- Розділ реалізації класів та функцій роботи з масивами
- [x] *ALGOR_SORTING*
	- Розділ реалізації алгоритмів сортування
- [ ] *ALGOR_MATRIX* <s>(не реалізовано)</s>
	- Розділ реалізації класів та функцій роботи з матрицями
- [ ] *ALGOR_HEAP* <s>(не реалізовано)</s>
	- Розділ реалізації класів та функцій роботи з купами
- [ ] *ALGOR_LIST* <s>(не реалізовано)</s>
	- Розділ реалізації класів та функцій роботи зі списками

## Документація
За документацією резпозиторію звертатись за наступним [посиланням](https://nakama3942.github.io/ALGOR_DOCUMENTATION/).

## Використання
Бібліотека призначена для компіляції та динамічного лінкування. У релізі доступна зібрана Windows-версія бібліотеки. Можна завантажити та розпакувати архів і:
- У IDE (перевірялося на Qt) необхідно додати шлях до статичної бібліотеки <i>.a</i>, щоб IDE побачила бібліотеку;
- Потім потрібно оголосити хідер бібліотеки у програмі;
- Після компіляції програми потрібно розмістити динамічну бібліотеку .dll поряд з виконуючим файлом.

Оголошення хідеру відбувається наступним чином:
```cpp
#include "/usr/include/ALGOR.hpp"				// on Linux
#include "specify/correct/path/to/ALGOR.hpp"	// on Windows
```

Сніппет:
```cpp
#include "/usr/include/ALGOR.hpp"
using namespace ALGOR;

#include <iostream>

int main()
{
	//Creating the array and generating the data
	ARRAYDATA<long> *array = new ARRAYDATA<long>(10);
	array->generatedData(10, 100);

	//Outputting the minimum and maximum elements
	std::cout << array->getMin() << " " << array->getMax() << "\n";

	//Outputting the array to the screen
	for (unsigned long i = 0; i < array->getSize(); i++)
	{
		std::cout << array->getData()->array[i] << (i != array->getSize() - 1 ? " " : "\n");
	}

	return 0;
}

// >print:>
//   13 80
//   76 73 22 13 34 21 78 53 80 49
```

Компіляція програми з використанням та лінковкою бібліотеки [на Windows у IDE](#компіляція-та-лінковка-на-windows-у-ide), [на Windows у консолі](#компіляція-та-лінковка-на-windows-у-консолі) та [на Linux у консолі](#компіляція-та-лінковка-на-linux-у-консолі).

Можна бібліотеку зібрати власноруч. Як її зібрати та використовувати описано [далі](#збірка-проекту).

## Збірка проекту
### Через IDE (Windows)
Бібліотека була написана на чистому С++ у IDE Qt, тому достатньо відкрити .pro-файл у IDE, підключити Kit і зібрати бібліотеку. Тоді створюється окрема директорія з потрібними файлами ALGOR1.dll та libALGOR1.a.

### Через IDE (LINUX)
Компіляція через IDE Qt на Linux не здійснювалась, а тому автор не може дати порад, як зібрати бібліотеку...

### Через консоль (Windows)
Збирати бібліотеку бажано у консолі GitBush (потрібно встановити), так як інструкції даються саме для неї. З директорії бібліотеки потрібно перейти до build/win/ і там запустити файл командою
```sh
./makefile
```
Надалі при зборках програм потрібно просто додавати ці (зібрані) файли бібліотеки до програм, що їх використовують:
- Якщо програма компілюється **власноруч**, то необхідно оголосити хідер бібліотеки у програмі та злінкувати .dll командою до програми і розмістити його поряд з виконуючим файлом і файл .a у цьому випадку не використовується. Як скомпілювати програму з лінкуванням бібліотеки показано у файлі test.sh у цій же директорії.
- Інакше ж якщо програма збирається через **IDE** (перевірялося тільки на Qt), то тоді будуть використовуватись усі файли а саме: щоб IDE побачила бібліотеку, у меню додання бібліотеки необхідно зазначити шлях до .a файла, потім потрібно оголосити хідер бібліотеки у програмі і після компіляції необхідно .dll файл розмістити поряд з виконуючим файлом.

Анімоване зображення [збірки бібліотеки](#збірка-бібліотеки-через-консоль-у-windows).

### Через консоль (LINUX)
З директорії бібліотеки потрібно перейти до build/linux/ і запустити програму make
```sh
make install
make clean
```
Бібліотека встановлюється в систему, а тому її можна видалити
```sh
make uninstall
```
- Якщо програма компілюється **власноруч**, то необхідно оголосити хідер бібліотеки у програмі та злінкувати .so командою до програми і файл .a у цьому випадку не використовується. Як скомпілювати програму з лінкуванням бібліотеки показано у файлі test.sh у цій же директорії.
- Варіант з **IDE** не здійснювався, а тому автор не може дати порад, як зібрати збірку...

Анімоване зображення [збірки бібліотеки](#збірка-бібліотеки-через-консоль-у-linux).

### Тест консольної збірки
У відповідній директорії (build/win/ чи build/linux/) у консолі (на Windows це все той же GitBush) запускаємо файл test.sh
```sh
sh test.sh
```
Також у цьому файлі показано команду компіляції з лінковкою бібліотеки.

Анімоване зображення [збірки бібліотеки](#тест-зібраної-бібліотеки-через-консоль).

## Вирішення проблем
Всі алгоритми перевірені мною, але якщо у вас виникли проблеми з використанням бібліотеки, код не працює, є пропозиції щодо оптимізації або поради щодо покращення стилю коду та імен - запрошую [сюди](https://github.com/Nakama3942/ALGOR/blob/main/CONTRIBUTING.md) та [сюди](https://github.com/Nakama3942/ALGOR/blob/main/CODE_OF_CONDUCT.md).

## Автори
<table align="center" style="border-width: 10; border-style: ridge">
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

## Гіфки
<!--На ГітХабі зображення не відображається. Цей README налаштований під документацію. У Doxygen все працює відмінно і на сайті документації проекту зображення відображаються-->
### Компіляція та лінковка на Windows у IDE
<img src="UsingLibraryWinIDE_Animation.gif">

### Компіляція та лінковка на Windows у консолі
<img src="UsingLibraryWinConsole_Animation.gif">

### Компіляція та лінковка на Linux у консолі
<img src="UsingLibraryLinuxConsole_Animation.gif" width="940">

### Збірка бібліотеки через консоль у Windows
<img src="MakingWinLibrary_Animation.gif">

### Збірка бібліотеки через консоль у Linux
<img src="MakingLinuxLibrary_Animation.gif" width="940">

### Тест зібраної бібліотеки через консоль
<img src="Testing_Animation.gif">
