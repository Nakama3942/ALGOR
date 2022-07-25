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
	
	//! [ARRAYDATA setNewData]
	ALGOR::ARRAYDATA<long long> *second_array = new ALGOR::ARRAYDATA<long long>(50);
	second_array->generatedData(100, 10000);
	array_size->setNewData(second_array->getData());
	//! [ARRAYDATA setNewData]
	
	//! [ARRAYDATA setData]
	ALGOR::ARRAYDATA<long long> *third_array = new ALGOR::ARRAYDATA<long long>(100);
	third_array->generatedData(10, 1000);
	array_size->setData(third_array->getData());
	//! [ARRAYDATA setData]
	
	//! [ARRAYDATA cloneNewData]
	ALGOR::ARRAYDATA<long long> *fourth_array = new ALGOR::ARRAYDATA<long long>(1000);
	fourth_array->generatedData(1000, 100000);
	array_size->cloneNewData(fourth_array->getData());
	//! [ARRAYDATA cloneNewData]
	
	//! [ARRAYDATA cloneData]
	ALGOR::ARRAYDATA<long long> *fifth_array = new ALGOR::ARRAYDATA<long long>(6);
	fifth_array->generatedData(6, 16);
	array_size->cloneData(fifth_array->getData());
	//! [ARRAYDATA cloneData]
	
	//! [ARRAYDATA getData]
	arr = array_size->getData();
	//! [ARRAYDATA getData]
	
	//! [ARRAYDATA getSize]
	cout << "Array size is " << array_size->getSize() << "\n";
	//! [ARRAYDATA getSize]
	
	//! [ARRAYDATA getValue]
	cout << "Position is 4; value is " << array_size->getValue(4) << "\n";
	//! [ARRAYDATA getValue]
	
	//! [ARRAYDATA binary_getPosition]
	cout << "Элемент \"7\" впервые встратился на месте " << array_size->binary_getPosition(7) + 1 << "\n";
	//! [ARRAYDATA binary_getPosition]
	
	//! [ARRAYDATA lenear_getPosition]
	Array<asize_t> *NumberPoints = array_size->lenear_getPosition(7);
	cout << "Элемент \"5\" встречается на местах: \n";
	for (asize_t i = 0; i < NumberPoints->array_size; i++)
	{
		cout << NumberPoints->array[i] + 1 << " ";
	}
	cout << "\n";
	remove_struct<asize_t>(NumberPoints);
	//! [ARRAYDATA lenear_getPosition]
	
	//! [ARRAYDATA getMin]
	cout << "Минимальный элемент: " << array_size->getMin() << "\n";
	//! [ARRAYDATA getMin]
	
	//! [ARRAYDATA getMax]
	cout << "Максимальный элемент: " << array_size->getMax() << "\n";
	//! [ARRAYDATA getMax]

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