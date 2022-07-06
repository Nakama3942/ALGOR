#include <iostream>
using std::cin;
using std::cout;

#include "../src/ALGOR.hpp"

int main()
{
	int size = 5;
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
	//   37; 23; 20; 48; 13;
	//   Minimum is 20
	//! [processing minimum]

	//! [processing maximum]
	cout << "\nMaximum is " << ALGOR::ArrayProcessing<long long>::maximum(arr, size) << "\n";
	// print:
	//   37; 23; 20; 48; 13;
	//   Maximum is 48
	//! [processing maximum]

	cin.get();
	return 0;
}