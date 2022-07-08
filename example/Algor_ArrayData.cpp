#include <iostream>
using std::cin;
using std::cout;

#include "../src/ALGOR.hpp"

int main()
{
	//! [ARRAYDATA constructor struct]
	ALGOR::Array<long long> *arr = ALGOR::create_struct(12);

	ALGOR::ARRAYDATA<long long> *array_struct = new ALGOR::ARRAYDATA<long long>(arr);
	//! [ARRAYDATA constructor struct]

	//! [ARRAYDATA constructor size]
	ALGOR::ARRAYDATA<long long> *array_size = new ALGOR::ARRAYDATA<long long>(12);
	//! [ARRAYDATA constructor size]

	//! [ARRAYDATA generatedData]
	array_size->generatedData(1, 100);
	//! [ARRAYDATA generatedData]

	//! [ARRAYDATA moda]
	ALGOR::ARRAYDATA<long long>::mode *moda = array_size->moda();
	cout << "Чаще всего встречаются элементы: ";
	for (unsigned int i = 0; i < moda->array_size; i++)
	{
		cout << moda->array[i] << " ";
	}
	cout << ", а именно " << moda->highest_frequency << " раз.\n";

	delete[] moda->array;
	delete (moda);
	//! [ARRAYDATA moda]

	cin.get();
	return 0;
}