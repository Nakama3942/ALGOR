#include <iostream>
using std::cin;
using std::cout;

#include "../include/ALGOR.hpp"
using namespace ALGOR;

int main()
{
	ALGOR::byte4_t value1 = 5, value2 = 10;

	//! [swap]
	ALGOR::swap<ALGOR::byte4_t>(value1, value2);
	cout << value2 << "\n";
	// print 5
	//! [swap]

	//! [minimum]
	cout << ALGOR::minimum(value1, value2) << "\n";
	// print 5
	//! [minimum]

	//! [maximum]
	cout << ALGOR::maximum(value1, value2) << "\n";
	// print 10
	//! [maximum]

	//! [mem]
	cout << ALGOR::getMemoryCell() << "\n";
	// print 185214324139604
	//! [mem]

	//! [array struct]
	ALGOR::Array<ALGOR::byte4_t> *arr;
	//! [array struct]
	//! [create_struct]
	arr = ALGOR::create_struct<ALGOR::byte4_t>(10);
	//arr = @0x1a1700
	//! [create_struct]
	//! [generate_struct]
	ALGOR::generate_struct<ALGOR::byte4_t>(arr, 1, 12);
	//arr->array = {9 9 7 7 4 7 2 7 2 9}
	//! [generate_struct]
	//! [remove_struct]
	ALGOR::remove_struct<ALGOR::byte4_t>(arr);
	//arr = 0x0
	//! [remove_struct]

	cin.get();
	return 0;
}