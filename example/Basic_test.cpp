#include "/usr/include/ALGOR.hpp"
using namespace ALGOR;

#include <iostream>
using std::cout;

int main()
{
	ARRAYDATA<long long> *array = new ARRAYDATA<long long>(10);
	array->generatedData(10, 100);
	Array<long long> *arr = array->getData();
	for (int i = 0; i < array->getSize(); i++) cout << arr->array[i] << " ";
	cout << "\n";

	return 0;
}
