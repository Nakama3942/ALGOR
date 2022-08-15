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
	
	//! [ARRAYDATA reset]
	array_size->reset();
	//! [ARRAYDATA reset]
	
	//! [ARRAYDATA resize]
	array_struct->resize(7, 1);
	//! [ARRAYDATA resize]
	
	//! [ARRAYDATA replace]
	array_struct->replace(5, 100);
	//! [ARRAYDATA replace]
	
	//! [ARRAYDATA reverse]
	array_struct->reverse();
	//! [ARRAYDATA reverse]
	
	//! [ARRAYDATA respawn]
	array_struct->respawn();
	//! [ARRAYDATA respawn]
	
	//! [ARRAYDATA searcherOccurrencesOfSubstring]
	Array<byte8_t> *Sequence = new Array<byte8_t>;
	ArrayProcessing<byte8_t>::addElement(Sequence->array, Sequence->array_size, 5, 0);
	ArrayProcessing<byte8_t>::addElement(Sequence->array, Sequence->array_size, 6, 1);
	try
	{
		Array<asize_t> *Occurrence = array_struct->searcherOccurrencesOfSubstring(Sequence, ARRAYDATA<byte8_t>::ArrayType::NUMBER);
		cout << "Последовательность \"5, 6\" встречается на местах: \n";
		for (asize_t i = 0; i < Occurrence->array_size; i++)
		{
			cout << Occurrence->array[i] + 1 << " ";
		}
		cout << "\n";
		remove_struct<asize_t>(Occurrence);
	}
	catch (EXCEPTION_SET::Exception ex)
	{
		cout << "\n\nCode: " << ex.code() << ";\n" << ex.what() << "\n-> " << ex.why() << "\n\n";
		cout << "Последовательность \"5, 6\" не найдена...\n";
	}
	remove_struct<byte8_t>(Sequence);
	//! [ARRAYDATA searcherOccurrencesOfSubstring]
	
	//! [ARRAYDATA average]
	cout << "Среднее арифметическое: " << array_struct->average() << "\n";
	//! [ARRAYDATA average]
	
	//! [ARRAYDATA mediana]
	cout << "Медиана: " << array_struct->mediana() << "\n";
	//! [ARRAYDATA mediana]
	
	//! [ARRAYDATA moda]
	ARRAYDATA<byte8_t>::mode *moda = array_struct->moda();
	cout << "Чаще всего встречаются элементы: ";
	for (asize_t i = 0; i < moda->array_size; i++)
	{
		cout << moda->array[i] << " ";
	}
	cout << ", а именно " << moda->highest_frequency << " раз.\n";

	delete[] moda->array;
	delete (moda);
	//! [ARRAYDATA moda]

	//! [ARRAYDATA =]
	cout << *array_size = array_struct->getData() << "\n";
	//! [ARRAYDATA =]
	
	//! [ARRAYDATA ==]
	cout << *array_size == array_struct->getData() << "\n";
	//! [ARRAYDATA ==]
	
	//! [ARRAYDATA ^=]
	*array_size ^= 13;
	//! [ARRAYDATA ^=]
	
	//! [ARRAYDATA +=]
	*array_size += 15;
	//! [ARRAYDATA +=]
	
	//! [ARRAYDATA -=]
	*array_size -= 17;
	//! [ARRAYDATA -=]
	
	//! [ARRAYDATA *=]
	*array_size *= 19;
	//! [ARRAYDATA *=]
	
	//! [ARRAYDATA /=]
	*array_size /= 21;
	//! [ARRAYDATA /=]
	
	//! [ARRAYDATA &=]
	*array_size &= 23;
	//! [ARRAYDATA &=]
	
	//! [ARRAYDATA |=]
	*array_size |= 25;
	//! [ARRAYDATA |=]
	
	//! [ARRAYDATA !]
	!*array_size;
	//! [ARRAYDATA !]
	
	//! [ARRAYDATA <<=]
	*array_size <<= *array_struct;
	//! [ARRAYDATA <<=]
	
	//! [ARRAYDATA >>=]
	*array_size >>= *array_struct;
	//! [ARRAYDATA >>=]

	cin.get();
	return 0;
}