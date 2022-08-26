/* ******************************   ALGOR.cpp   ******************************* *
 * ---------------------------------------------------------------------------- *
 *                                                                              *
 * Copyright © 2021-2022 Kalynovsky Valentin. All rights reserved.              *
 *                                                                              *
 * Licensed under the Apache License, Version 2.0 (the "License");              *
 * you may not use this file except in compliance with the License.             *
 * You may obtain a copy of the License at                                      *
 *                                                                              *
 *     http://www.apache.org/licenses/LICENSE-2.0                               *
 *                                                                              *
 * Unless required by applicable law or agreed to in writing, software          *
 * distributed under the License is distributed on an "AS IS" BASIS,            *
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.     *
 * See the License for the specific language governing permissions and          *
 * limitations under the License.                                               *
 *                                                                              *
 * ---------------------------------------------------------------------------- *
 * **************************************************************************** */

#include <iostream>

#include "../include/ALGOR.hpp"
using namespace ALGOR;

int main()
{
	unsigned long size = 5;
	long *arr = new long[size];
	ALGOR::RANDOM::MersenneTwister MT(ALGOR::getMemoryCell());
	for (unsigned long i = 0; i < size; i++)
	{
		arr[i] = MT.IRandom(10, 100);
		std::cout << arr[i] << "; ";
	}
	std::cout << "\n";

	//! [processing minimum]
	std::cout << "Minimum is " << ALGOR::ArrayProcessing<long>::minimum(arr, size) << "\n";

	// The data is not taken from the output, but from the debugger console
	// With array: 37; 23; 13; 48; 20

	// >print:> Minimum is 13
	//! [processing minimum]

	//! [processing maximum]
	std::cout << "Maximum is " << ALGOR::ArrayProcessing<long>::maximum(arr, size) << "\n";

	// The data is not taken from the output, but from the debugger console
	// With array: 37; 23; 13; 48; 20

	// >print:> Maximum is 48
	//! [processing maximum]

	//! [processing isOrderliness]
	std::cout << "Array is orderliness? " << ALGOR::ArrayProcessing<long>::isOrderliness(arr, size) << "\n";

	ALGOR::Comparative_Sorts<long>::LibrarySort sort1(arr, size); //or any sorting
	sort1.library_sort();
	for (unsigned long i = 0; i < size; i++)
	{
		std::cout << arr[i] << "; ";
	}
	std::cout << "\n";

	std::cout << "Array is orderliness? " << ALGOR::ArrayProcessing<long>::isOrderliness(arr, size) << "\n";

	// The data is not taken from the output, but from the debugger console
	// With array: 37; 23; 13; 48; 20

	// >print:>
	//   Array is orderliness? 0
	//   13; 20; 23; 37; 48;
	//   Array is orderliness? 1
	//! [processing isOrderliness]

	//! [processing distance]
	std::cout << "Distance is " << ALGOR::ArrayProcessing<long>::distance(&arr[2], &arr[4]) << "\n";
	// >print:> Distance is 2
	//! [processing distance]

	delete[] arr;

	size = 10;
	arr = new long[size];
	for (unsigned long i = 0; i < size; i++)
	{
		arr[i] = MT.IRandom(5, 10);
	}
	ALGOR::Comparative_Sorts<long>::LibrarySort sort2(arr, size); //or any sorting
	sort2.library_sort();
	for (unsigned long i = 0; i < size; i++)
	{
		std::cout << arr[i] << "; ";
	}
	std::cout << "\n";

	//! [processing lower_bound]
	std::cout << "First address in array " << &arr[0] << "\n";
	std::cout << "Lower bound 6 is " << ALGOR::ArrayProcessing<long>::lower_bound(&arr[0], &arr[9], 6) << "\n";

	// The data is not taken from the output, but from the debugger console
	// With array: 5; 5; 6; 6; 7; 8; 8; 9; 10; 10

	// >print:>
	//   First address in array 0x29347f0
	//   Lower bound 6 is 0x29347f8
	//! [processing lower_bound]

	//! [processing upper_bound]
	std::cout << "First address in array " << &arr[0];
	std::cout << "Upper bound 6 is " << ALGOR::ArrayProcessing<long>::upper_bound(&arr[0], &arr[9], 6) << "\n";

	// The data is not taken from the output, but from the debugger console
	// With array: 5; 5; 6; 6; 7; 8; 8; 9; 10; 10

	// >print:>
	//   First address in array 0x29347f0
	//   Upper bound 6 is 0x2934800
	//! [processing upper_bound]

	delete[] arr;

	arr = new long[size];
	for (unsigned long i = 0; i < size; i++)
	{
		arr[i] = MT.IRandom(5, 10);
		std::cout << arr[i] << "; ";
	}
	std::cout << "\n";

	//! [processing addElement]
	// Adding an element to the top of the array
	try
	{
		ALGOR::ArrayProcessing<long>::addElement(arr, size, 100, 0);
	}
	catch (ALGOR::EXCEPTION_SET::Exception ex)
	{
		std::cout << "\n\nCode: " << ex.code() << ";\n" << ex.what() << "\n-> " << ex.why() << "\n\n";
	}

	// Outputting an array on the screen
	for (unsigned long i = 0; i < size; i++)
	{
		std::cout << arr[i] << "; ";
	}
	std::cout << "\n";

	// Adding an element to the middle of the array
	try
	{
		ALGOR::ArrayProcessing<long>::addElement(arr, size, 100, 5);
	}
	catch (ALGOR::EXCEPTION_SET::Exception ex)
	{
		std::cout << "\n\nCode: " << ex.code() << ";\n" << ex.what() << "\n-> " << ex.why() << "\n\n";
	}

	// Outputting an array on the screen
	for (unsigned long i = 0; i < size; i++)
	{
		std::cout << arr[i] << "; ";
	}
	std::cout << "\n";

	// Adding an element to the end of the array
	try
	{
		ALGOR::ArrayProcessing<long>::addElement(arr, size, 100, size);
	}
	catch (ALGOR::EXCEPTION_SET::Exception ex)
	{
		std::cout << "\n\nCode: " << ex.code() << ";\n" << ex.what() << "\n-> " << ex.why() << "\n\n";
	}

	// Outputting an array on the screen
	for (unsigned long i = 0; i < size; i++)
	{
		std::cout << arr[i] << "; ";
	}
	std::cout << "\n";

	// The data is not taken from the output, but from the debugger console
	// With array: 10; 6; 8; 7; 6; 7; 8; 7; 9; 7

	// >print:>
	//   100; 10; 6; 8; 7; 6; 7; 8; 7; 9; 7
	//   100; 10; 6; 8; 7; 100; 6; 7; 8; 7; 9; 7
	//   100; 10; 6; 8; 7; 100; 6; 7; 8; 7; 9; 7; 100
	//! [processing addElement]

	//! [processing subtractElement]
	try
	{
		ALGOR::ArrayProcessing<long>::subtractElement(arr, size, 7);
	}
	catch (ALGOR::EXCEPTION_SET::Exception ex)
	{
		std::cout << "\n\nCode: " << ex.code() << ";\n" << ex.what() << "\n-> " << ex.why() << "\n\n";
	}

	// Outputting an array on the screen
	for (unsigned long i = 0; i < size; i++)
	{
		std::cout << arr[i] << "; ";
	}
	std::cout << "\n";

	// The data is not taken from the output, but from the debugger console
	// With array: 100; 10; 6; 8; 7; 100; 6; 7; 8; 7; 9; 7; 100

	// >print:> 100; 10; 6; 8; 7; 100; 6; 8; 7; 9; 7; 100
	//! [processing subtractElement]

	//! [processing subtractValue]
	try
	{
		ALGOR::ArrayProcessing<long>::subtractValue(arr, size, 7);
	}
	catch (ALGOR::EXCEPTION_SET::Exception ex)
	{
		std::cout << "\n\nCode: " << ex.code() << ";\n" << ex.what() << "\n-> " << ex.why() << "\n\n";
	}

	// Outputting an array on the screen
	for (unsigned long i = 0; i < size; i++)
	{
		std::cout << arr[i] << "; ";
	}
	std::cout << "\n";

	// The data is not taken from the output, but from the debugger console
	// With array: 100; 10; 6; 8; 7; 100; 6; 8; 7; 9; 7; 100

	// >print:> 100; 10; 6; 8; 100; 6; 8; 9; 100
	//! [processing subtractValue]

	delete[] arr;

	unsigned long size1 = 10, size2 = 15;
	long *arr1 = new long[size1], *arr2 = new long[size2];
	for (unsigned long i = 0; i < size1; i++)
	{
		arr1[i] = MT.IRandom(5, 10);
		std::cout << arr1[i] << "; ";
	}
	std::cout << "\n";
	for (unsigned long i = 0; i < size2; i++)
	{
		arr2[i] = MT.IRandom(15, 20);
		std::cout << arr2[i] << "; ";
	}
	std::cout << "\n";

	//! [processing copy]
	ALGOR::ArrayProcessing<long>::copy(arr1, arr2, 5, 5, 5);
	for (unsigned long i = 0; i < size1; i++)
	{
		std::cout << arr1[i] << "; ";
	}
	std::cout << "\n";

	// The data is not taken from the output, but from the debugger console
	// With array1: 7;  7;  6;  5;  6; 10; 10;  7; 10;  9
	// and array2: 17; 16; 15; 16; 17; 19; 15; 19; 19; 20; 20; 18; 18; 16; 20

	// >print:> 7;  7;  6;  5;  6; 19; 15; 19; 19; 20
	//! [processing copy]

	delete[] arr1;
	delete[] arr2;

	std::cin.get();
	return 0;
}
