#include <iostream>
using std::cin;
using std::cout;

#include "../src/ALGOR.hpp"

int main()
{
	unsigned long size = 5;
	long long *arr = new long long[size];
	ALGOR::RANDOM::MersenneTwister MT(ALGOR::getMemoryCell());
	for (int i = 0; i < size; i++)
	{
		arr[i] = MT.IRandom(10, 100);
		cout << arr[i] << "; ";
	}

	//! [processing minimum]
	cout << "\nMinimum is " << ALGOR::ArrayProcessing<long long>::minimum(arr, size) << "\n";
	// print:
	//   37; 23; 13; 48; 20;
	//   Minimum is 13
	//! [processing minimum]

	//! [processing maximum]
	cout << "\nMaximum is " << ALGOR::ArrayProcessing<long long>::maximum(arr, size) << "\n";
	// print:
	//   37; 23; 13; 48; 20;
	//   Maximum is 48
	//! [processing maximum]

	//! [processing isOrderliness]
	cout << "\nArray is orderliness? " << ALGOR::ArrayProcessing<long long>::isOrderliness(arr, size) << "\n";
	
	ALGOR::Comparative_Sorts<long long>::LibrarySort sort(arr, size); //or any sorting
	sort.library_sort();
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << "; ";
	}
	
	cout << "\nArray is orderliness? " << ALGOR::ArrayProcessing<long long>::isOrderliness(arr, size) << "\n";
	
	//print:
	//  37; 23; 13; 48; 20;
	//  Array is orderliness? 0
	//  13; 20; 23; 37; 48;
	//  Array is orderliness? 1
	//! [processing isOrderliness]
	
	//! [processing distance]
	cout << "Distance " << ALGOR::ArrayProcessing<long long>::distance(&arr[2], &arr[4]) << "\n";
	//print:
	//  Distance 2
	//! [processing distance]

	delete (arr);
	size = 10;
	long long *arr = new long long[size];
	ALGOR::RANDOM::MersenneTwister MT(ALGOR::getMemoryCell());
	for (int i = 0; i < size; i++)
	{
		arr[i] = MT.IRandom(5, 10);
	}
	ALGOR::Comparative_Sorts<long long>::LibrarySort sort(arr, size); //or any sorting
	sort.library_sort();
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << "; ";
	}

	//! [processing lower_bound]
	cout << "\nFirst address in array " << &arr[0];
	cout << "\nLower bound 6 is " << ALGOR::ArrayProcessing<long long>::lower_bound(&arr[0], &arr[9], 6) << "\n";
	//print:
	//  5; 5; 6; 6; 7; 8; 8; 9; 10; 10;
	//  First address in array 0x29347f0
	//  Lower bound 6 is 0x29347f8
	//! [processing lower_bound]
	
	//! [processing upper_bound]
	cout << "\nFirst address in array " << &arr[0];
	cout << "\nUpper bound 6 is " << ALGOR::ArrayProcessing<long long>::upper_bound(&arr[0], &arr[9], 6) << "\n";
	//print:
	//  5; 5; 6; 6; 7; 8; 8; 9; 10; 10;
	//  First address in array 0x29347f0
	//  Upper bound 6 is 0x2934800
	//! [processing upper_bound]

	delete (arr);
	long long *arr = new long long[size];
	ALGOR::RANDOM::MersenneTwister MT(ALGOR::getMemoryCell());
	for (int i = 0; i < size; i++)
	{
		arr[i] = MT.IRandom(5, 10);
		cout << arr[i] << "; ";
	}
	cout << "\n";

	//! [processing addElement]
	//Додаю елемент на початок масиву
	ALGOR::ArrayProcessing<long long>::addElement(arr, size, 100, 0);

	//Виводжу на екран масив
	for (unsigned long i = 0; i < size; i++)
	{
		cout << arr[i] << "; ";
	}
	cout << "\n";

	//Додаю елемент у середину масиву
	ALGOR::ArrayProcessing<long long>::addElement(arr, size, 100, 5);

	//Виводжу на екран масив
	//...

	//Додаю елемент на кінець масиву
	ALGOR::ArrayProcessing<long long>::addElement(arr, size, 100, size);

	//Виводжу на екран масив
	//...

	//print:
	//  10; 6; 8; 7; 6; 7; 8; 7; 9; 7;
	//  100; 10; 6; 8; 7; 6; 7; 8; 7; 9; 7;
	//  100; 10; 6; 8; 7; 100; 6; 7; 8; 7; 9; 7;
	//  100; 10; 6; 8; 7; 100; 6; 7; 8; 7; 9; 7; 100;
	//! [processing addElement]

	//! [processing subtractElement]
	ALGOR::ArrayProcessing<long long>::subtractElement(arr, size, 7);

	//Виводжу на екран масив
	//...

	//print:
	//  100; 10; 6; 8; 7; 100; 6; 7; 8; 7; 9; 7; 100;
	//  100; 10; 6; 8; 7; 100; 6; 8; 7; 9; 7; 100;
	//! [processing subtractElement]

	//! [processing subtractValue]
	ALGOR::ArrayProcessing<long long>::subtractValue(arr, size, 7);

	//Виводжу на екран масив
	//...

	//print:
	//  100; 10; 6; 8; 7; 100; 6; 8; 7; 9; 7; 100;
	//  100; 10; 6; 8; 100; 6; 8; 9; 100;
	//! [processing subtractValue]

	delete(arr);

	unsigned long size1 = 10, size2 = 15;
	long long *arr1 = new long long[size1], *arr2 = new long long[size2];
	ALGOR::RANDOM::MersenneTwister MT(ALGOR::getMemoryCell());
	for (unsigned long i = 0; i < size1; i++)
	{
		arr1[i] = MT.IRandom(5, 10);
		cout << arr1[i] << "; ";
	}
	cout << "\n";
	for (unsigned long i = 0; i < size2; i++)
	{
		arr2[i] = MT.IRandom(5, 10);
		cout << arr2[i] << "; ";
	}
	cout << "\n";

	//! [processing copy]
	ALGOR::ArrayProcessing<long long>::copy(arr1, arr2, 5, 5, 5);
	for (unsigned long i = 0; i < size1; i++)
	{
		cout << arr1[i] << "; ";
	}
	cout << "\n";
	//print:
	//   7;  7;  6;  5;  6; 10; 10;  7; 10;  9;
	//  17; 16; 15; 16; 17; 19; 15; 19; 19; 20; 20; 18; 18; 16; 20;
	//   7;  7;  6;  5;  6; 19; 15; 19; 19; 20;
	//! [processing copy]

	delete(arr1);
	delete(arr2);

	cin.get();
	return 0;
}