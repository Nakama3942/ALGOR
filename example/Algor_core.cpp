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

	cin.get();
	return 0;
}