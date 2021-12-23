[![template](https://img.shields.io/badge/Repository-template-darkred)](https://github.com/Nakama3942/template_rep)
[![GitHub license](https://img.shields.io/github/license/Nakama3942/ALGOR?color=gold&style=flat-square)](https://github.com/Nakama3942/ALGOR/blob/main/LICENSE)

[![CHANGELOG](https://img.shields.io/badge/here-CHANGELOG-yellow)](https://github.com/Nakama3942/ALGOR/blob/main/CHANGELOG.md)
[![CONTRIBUTING](https://img.shields.io/badge/here-CONTRIBUTING-indigo)](https://github.com/Nakama3942/ALGOR/blob/main/CONTRIBUTING.md)
[![CODE_OF_CONDUCT](https://img.shields.io/badge/here-CODE_OF_CONDUCT-darkgreen)](https://github.com/Nakama3942/ALGOR/blob/main/CODE_OF_CONDUCT.md)
[![PULL_REQUEST_TEMPLATE](https://img.shields.io/badge/here-PULL_REQUEST_TEMPLATE-orange)](https://github.com/Nakama3942/ALGOR/blob/main/.github/PULL_REQUEST_TEMPLATE.md)

# ALGOR
## Overview
Library for processing and sorting arrays. Processing means outputting to the array console, finding the maximum and minimum elements, etc.

In search of sorting algorithms and explanations in the form of a code, I often came across large codes with a bunch of unnecessary things not related to the sorting algorithm (such as testing) and, in principle, the code contained variables not with normal names, but with names like A, B, C - the style of the code is broken (and sometimes even terrible), sometimes you can find out of order tabulation and there are a bunch of other factors that make the code unreadable and inaccessible for understanding. I spent a lot of time to understand these algorithms and wrote this library, firstly, so as not to write the same thing every time, but simply connect the library and use the ready-made code, and secondly for other people who are just learning algorithms, that I could easily figure it out: the code contains only the necessary methods, they are in order, the code I try to optimize, the style is not broken, and most importantly, thanks to normal names, the code is clear, readable and suitable for learning algorithms.

<!--
В поисках алгоритмов сортировок и пояснений в виде кода, я часто натыкался на большие коды с кучей лишнего, не относящегося к алгоритму сортировки (типа тестирование) и, в принципе, в коде присутствовали переменные не с нормальными названиеми, а с названиями типа А, В, С - стиль кода нарушен (а иногда даже ужасен), иногда можно встретить сбившуюся табуляцию и есть куча других факторов, которые делают код нечитабельным и недоступным для понимания. Я потратил кучу времени, чтобы разобрать в этих алгоритмах и написал эту библиотеку, во-первых, чтобы каждый раз не писать одно и тоже, а просто подключил библиотеку и используешь готовый код, во-вторых для других людей, которые только учат алгоритмы, что бы можно было легко разобраться: в коде присутствуют только нужные методы, находятся они в порядке код я стараюсь оптимизировать, стиль не нарушен и самое главное - благодаря нормальным именам код понятен, читабелен и пригоден для изучения алгоритмов.
-->

## Usage
<!--
To use the library, just download the "sortingalgorithms.hpp" file and link it to your program
```cpp
#include "sortingalgorithms.hpp"
```
-->
The library is designed for compilation and dynamic linking. However, you can put the files ALGOR.hpp and ALGOR.cpp into your project and just connect the header:
```cpp
#include "ALGOR.hpp"
```
If you follow the idea, then after compiling the library, in the settings of your project you need to specify the path to the .a-file, and in the source you just connect the header, as shown above. The library itself (.dll or .so) must be placed next to the executable file for it to work.

## Building
<!--
In general, the library is intended for static compilation with the main program. After choosing the desired sorting method, all other classes in the namespace can be commented out, except for the ArrayProcessing class and the class of the desired sorting method. This can be done to reduce the size of the original program. Otherwise, the assembly is similar to any other program written in C++.
-->
The library is designed for dynamic linking. You must first compile the library before using it. Development was transferred to Qt, however this project remains independent and is written in pure C++. You just need to clone the repository, open the project in Qt and compile the library. You can use another IDE or compile it yourself in the terminal.

## Troubleshooting
All algorithms have been tested by me, but if you have problems using the library, the code does not work, there are suggestions for optimization or advice on improving the style of the code and names - I invite you [here](https://github.com/Nakama3942/ALGOR/blob/main/CONTRIBUTING.md).

## Authors
<table>
    <tr>
        <td align="center"><a href="https://github.com/Nakama3942"><img src="https://avatars.githubusercontent.com/u/73797846?s=400&u=a9b7688ac521d739825d7003a5bd599aab74cb76&v=4" width="150px;" alt=""/><br /><sub><b>Kalynovsky Valentin</b></sub></a><sub><br />"Ideological inspirer and Author"</sub></td>
        <!--<td></td>-->
    </tr>
<!--
    <tr>
        <td></td>
        <td></td>
    </tr>
-->
</table>