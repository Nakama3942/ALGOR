#include <iostream>
using std::cin;
using std::cout;

#include "../src/ALGOR.hpp"

int main()
{
	int value1 = 5, value2 = 10;

	//! [swap]
	ALGOR::swap(value1, value2);
	cout << value2 << "\n"; // print 5
	//! [swap]

	//! [minimum]
	cout << ALGOR::minimum(value1, value2) << "\n"; // print 5
	//! [minimum]

	//! [maximum]
	int value1 = 5, value2 = 10;
	cout << ALGOR::maximum(value1, value2) << "\n"; // print 10
	//! [maximum]

	//! [mem]
	cout << ALGOR::getMemoryCell() << "\n"; // print 185214324139604
	//! [mem]

	//! [array struct]
	ALGOR::Array<long long> *arr;
	//! [array struct]
	//! [create_struct]
	arr = ALGOR::create_struct<long long>(10); //arr = @0x1a1700
	//! [create_struct]
	//! [generate_struct]
	ALGOR::generate_struct(arr, 1, 12); //arr->array = {9 9 7 7 4 7 2 7 2 9}
	//! [generate_struct]
	//! [remove_struct]
	ALGOR::remove_struct(arr); //arr = 0x0
	//! [remove_struct]

	cin.get();
	return 0;
}