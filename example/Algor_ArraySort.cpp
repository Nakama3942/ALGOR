#include <iostream>
using std::cin;
using std::cout;

#include "../src/ALGOR.hpp"

int main()
{
	ALGOR::Array<long long> *arr = ALGOR::create_struct(12);
	generate_struct(arr, 1, 100);
	
	//! [Comparative_Sorts constructor]
	Comparative_Sorts<long long> *sort = new Comparative_Sorts<long long>(ArrayStruct);
	//! [Comparative_Sorts constructor]

	cin.get();
	return 0;
}