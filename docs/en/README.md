[![template](https://img.shields.io/badge/Repository-template-darkred)](https://github.com/Nakama3942/template_rep)
[![GitHub license](https://img.shields.io/github/license/Nakama3942/ALGOR?color=gold&style=flat-square)](https://github.com/Nakama3942/ALGOR/blob/main/LICENSE)

[![CHANGELOG](https://img.shields.io/badge/here-CHANGELOG-yellow)](https://github.com/Nakama3942/ALGOR/blob/main/CHANGELOG.md)
[![CONTRIBUTING](https://img.shields.io/badge/here-CONTRIBUTING-indigo)](https://github.com/Nakama3942/ALGOR/blob/main/CONTRIBUTING.md)
[![CODE_OF_CONDUCT](https://img.shields.io/badge/here-CODE_OF_CONDUCT-darkgreen)](https://github.com/Nakama3942/ALGOR/blob/main/CODE_OF_CONDUCT.md)
[![PULL_REQUEST_TEMPLATE](https://img.shields.io/badge/here-PULL_REQUEST_TEMPLATE-orange)](https://github.com/Nakama3942/ALGOR/blob/main/.github/PULL_REQUEST_TEMPLATE.md)

<img src="LOGO.png" width="940">

<!--
Copyright © 2021-2022 Kalynovsky Valentin. All rights reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

   http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
-->

# ALGOR
## Content
- [ALGOR](#algor)
	- [Content](#content)
	- [Overview](#overview)
	- [LICENSE](#license)
	- [Functional](#functional)
	- [Documentation](#documentation)
	- [Usage](#usage)
	- [Building](#building)
		- [In IDE (Windows)](#in-ide-windows)
		- [In IDE (Linux)](#in-ide-linux)
		- [In console (Windows)](#in-console-windows)
		- [In console (Linux)](#in-console-linux)
		- [Console buits test](#console-buits-test)
	- [Troubleshooting](#troubleshooting)
	- [Authors](#authors)
	- [GIFs](#gifs)
		- [Compilation and linking on Windows in IDE](#compilation-and-linking-on-windows-in-ide)
		- [Compilation and linking on Windows in the console](#compilation-and-linking-on-windows-in-the-console)
		- [Compilation and linking on Linux in the console](#compilation-and-linking-on-linux-in-the-console)
		- [Building of a library in console in Windows](#building-of-a-library-in-console-in-windows)
		- [Building of a library in console in Linux](#building-of-a-library-in-console-in-linux)
		- [Test of the built library in console](#test-of-the-built-library-in-console)

## Overview
A library for processing and sorting data structures.

In search of sorting algorithms and explanations in the form of a code, I often came across large codes with a bunch of unnecessary things not related to the sorting algorithm (such as testing) and, in principle, the code contained variables not with normal names, but with names like A, B, C - the style of the code is broken (and sometimes even terrible), sometimes you can find out of order tabulation and there are a bunch of other factors that make the code unreadable and inaccessible for understanding. I spent a lot of time to understand these algorithms and wrote this library, firstly, so as not to write the same thing every time, but simply connect the library and use the ready-made code, and secondly for other people who are just learning algorithms, that I could easily figure it out: the code contains only the necessary methods, they are in order, the code I try to optimize, the style is not broken, and most importantly, thanks to normal names, the code is clear, readable and suitable for learning algorithms.

## LICENSE
The full text of the license can be found at the following [link](https://github.com/Nakama3942/ALGOR/blob/main/LICENSE).

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

## Functional
The library implements the next functionality:
- [x] *ALGOR_CORE*
	- Section of implementation of the main basic functions, classes and definitions.
- [x] *ALGOR_EXCEPTION*
	- Section of implementation of exceptions.
- [x] *ALGOR_RANDOM*
	- Section of implementation of randoms.
- [x] *ALGOR_ARRAY*
	- Section of implementation of classes and functions for working with arrays.
- [x] *ALGOR_SORTING*
	- Section of implementation of sorting algorithm.
- [ ] *ALGOR_MATRIX* <s>(not implemented)</s>
	- Section of implementation of classes and functions for working with matrixs.
- [ ] *ALGOR_HEAP* <s>(not implemented)</s>
	- Section of implementation of classes and functions for working with heaps.
- [ ] *ALGOR_LIST* <s>(not implemented)</s>
	- Section of implementation of classes and functions for working with lists.

## Documentation
For repository documentation, please use the following [link](https://nakama3942.github.io/ALGOR_DOCUMENTATION/).

## Usage
The library is intended for compilation and dynamic linking. A compiled Windows version of the library is available in the release. You can download and extract the archive and:
- In the IDE (tested on Qt), it is necessary to add the path to the static library <i>.a</i> so that the IDE can see the library;
- Then you need to declare the library hider in the program;
- After compiling the program, you need to place the dynamic library .dll next to the executable file.

The hider is announced as follows:
```cpp
#include "/usr/include/ALGOR.hpp"				// on Linux
#include "specify/correct/path/to/ALGOR.hpp"	// on Windows
```

Snippet:
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

Compiling the program with using and linking with the library [on Windows in the IDE](#compilation-and-linking-on-windows-in-ide), [on Windows in the console](#compilation-and-linking-on-windows-in-the-console), and [on Linux in the console](#compilation-and-linking-on-linux-in-the-console).

You can assemble the library yourself. How to collect and use it is described [below](#building).

## Building
### In IDE (Windows)
The library was written in pure C++ in the Qt IDE, so it is enough to open the .pro file in the IDE, connect Kit and compile the library. Then a separate directory is created with the necessary files ALGOR1.dll and libALGOR1.a.

### In IDE (Linux)
Compilation via the Qt IDE on Linux was not done, so the author cannot give advice on how to compile the library...

### In console (Windows)
It is preferable to compile the library in the GitBush console (must be installed), since the instructions are given specifically for it. From the library directory, you need to go to build/win/ and run the file there with the command:
```sh
./makefile
```
In the future, when building programs, you just need to add these (compiled) library files to the programs that use them:
- If the program is compiled **by hand**, then it is necessary to declare the library hider in the program and link the .dll command to the program and place it next to the executable file and the .a file is not used in this case. How to compile a program with library linking is shown in the test.sh file in the same directory.
- Otherwise, if the program is compiled through **IDE** (checked only on Qt), then all files will be used, namely: in order for IDE to see the library, the path to the .a file must be specified in the library addition menu, then the library hider must be declared in the program and after compilation, it is necessary to place the .dll file next to the executable file.

An animated image of a [built library](#building-of-a-library-in-console-in-windows).

### In console (Linux)
From the Library directory, you need to go to build/linux/ and launch Make:
```sh
make install
make clean
```
The library is installed in the system, so it can be deleted:
```sh
make uninstall
```
- If the program is compiled **by hand**, then it is necessary to declare the library hider in the program and link the .so command to the program and the .a file is not used in this case. How to compile a program with library linking is shown in the test.sh file in the same directory.
- Option with **IDE** was not done, so the author cannot give advice on how to collect a collection ...

An animated image of a [built library](#building-of-a-library-in-console-in-linux).

### Console buits test
In the appropriate Directory (Build/Win/or Build/Linux/) in the console (on Windows it's all the same gitbush) we launch a Test.sh file:
```sh
sh test.sh
```
This file also shows a compilation command with a library.

An animated image of a [built library](#test-of-the-built-library-in-console).

## Troubleshooting
All algorithms have been tested by me, but if you have problems using the library, the code does not work, have suggestions for optimization or advice to improve the style of the code and the name - I invite you [here](https://github.com/Nakama3942/ALGOR/blob/main/CONTRIBUTING.md) and [here](https://github.com/Nakama3942/ALGOR/blob/main/CODE_OF_CONDUCT.md).

## Authors
<table align="center" style="border-width: 10; border-style: ridge">
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

## GIFs
<!--The image is not displayed on Hithabi.This readme is configured under documentation.Doxygen is working perfectly and the image documentation website is displayed-->
### Compilation and linking on Windows in IDE
<img src="UsingLibraryWinIDE_Animation.gif">

### Compilation and linking on Windows in the console
<img src="UsingLibraryWinConsole_Animation.gif">

### Compilation and linking on Linux in the console
<img src="UsingLibraryLinuxConsole_Animation.gif" width="940">

### Building of a library in console in Windows
<img src="MakingWinLibrary_Animation.gif">

### Building of a library in console in Linux
<img src="MakingLinuxLibrary_Animation.gif" width="940">

### Test of the built library in console
<img src="Testing_Animation.gif">
