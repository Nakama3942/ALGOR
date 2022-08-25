#include <iostream>

#include "../include/ALGOR.hpp"
using namespace ALGOR;

int main()
{
	//! [ARRAYDATA constructor struct]
	[[maybe_unused]]ALGOR::Array<long> *arr_str = ALGOR::create_struct<long>(12);
	// The data is not taken from the output, but from the debugger console
	// arr_str = @0x1b4870

	ALGOR::ARRAYDATA<long> *array_by_struct = new ALGOR::ARRAYDATA<long>(arr_str);
	// The data is not taken from the output, but from the debugger console
	// array_by_struct = @0x1b4eb0
	// array_by_struct->[ALGOR::ArrayBase]->ARRAY = @0x1b4870
	//! [ARRAYDATA constructor struct]

	//! [ARRAYDATA constructor size]
	ALGOR::ARRAYDATA<long> *array_by_size = new ALGOR::ARRAYDATA<long>(12);
	// The data is not taken from the output, but from the debugger console
	// array_by_size = @0x1b4ef0
	// array_by_size->[ALGOR::ArrayBase]->ARRAY = @0x1b4f30
	//! [ARRAYDATA constructor size]

	//! [ARRAYDATA generatedData]
	try
	{
		array_by_size->generatedData(1, 100);
	}
	catch (ALGOR::EXCEPTION_SET::Exception ex)
	{
		std::cout << "\n\nCode: " << ex.code() << ";\n" << ex.what() << "\n-> " << ex.why() << "\n\n";
	}
	// The data is not taken from the output, but from the debugger console
	// array_by_size->[ALGOR::ArrayBase]->ARRAY->array = {20 86 29 29 37 73 57 7 57 86 37 89}
	//! [ARRAYDATA generatedData]

	// ALGOR::Array<long> *arr_siz is required to test of memory removal by the next methods
	[[maybe_unused]]ALGOR::Array<long> *arr_siz;

	//! [ARRAYDATA setNewData]
	arr_siz = array_by_size->getData();
	// The data is not taken from the output, but from the debugger console
	// arr_siz->array = {20 86 29 29 37 73 57 7 57 86 37 89}
	ALGOR::ARRAYDATA<long> *second_array = new ALGOR::ARRAYDATA<long>(15);
	second_array->generatedData(100, 10000);
	// The data is not taken from the output, but from the debugger console
	// second_array->[ALGOR::ArrayBase]->ARRAY->array = {6752 7511 9038 8345 928 4627 1938 8125 8076 5135 1918 6821 5672 5819 1298}
	try
	{
		array_by_size->setNewData(second_array->getData());
	}
	catch (ALGOR::EXCEPTION_SET::Exception ex)
	{
		std::cout << "\n\nCode: " << ex.code() << ";\n" << ex.what() << "\n-> " << ex.why() << "\n\n";
	}
	// The data is not taken from the output, but from the debugger console
	// array_by_size->[ALGOR::ArrayBase]->ARRAY->array = {6752 7511 9038 8345 928 4627 1938 8125 8076 5135 1918 6821 5672 5819 1298}
	// arr_siz->array = {Data is lost...}
	//! [ARRAYDATA setNewData]

	//! [ARRAYDATA setData]
	arr_siz = array_by_size->getData();
	// The data is not taken from the output, but from the debugger console
	// arr_siz->array = {6752 7511 9038 8345 928 4627 1938 8125 8076 5135 1918 6821 5672 5819 1298}
	ALGOR::ARRAYDATA<long> *third_array = new ALGOR::ARRAYDATA<long>(20);
	third_array->generatedData(10, 1000);
	// The data is not taken from the output, but from the debugger console
	// third_array->[ALGOR::ArrayBase]->ARRAY->array = {722 491 38 335 838 577 858 115 66 95 838 791 632 779 218 879 882 517 612 267}
	try
	{
		array_by_size->setData(third_array->getData());
	}
	catch (ALGOR::EXCEPTION_SET::Exception ex)
	{
		std::cout << "\n\nCode: " << ex.code() << ";\n" << ex.what() << "\n-> " << ex.why() << "\n\n";
	}
	// The data is not taken from the output, but from the debugger console
	// array_by_size->[ALGOR::ArrayBase]->ARRAY->array = {722 491 38 335 838 577 858 115 66 95 838 791 632 779 218 879 882 517 612 267}
	// arr_siz->array = {6752 7511 9038 8345 928 4627 1938 8125 8076 5135 1918 6821 5672 5819 1298}
	//! [ARRAYDATA setData]

	//! [ARRAYDATA cloneNewData]
	arr_siz = array_by_size->getData();
	// The data is not taken from the output, but from the debugger console
	// arr_siz->array = {722 491 38 335 838 577 858 115 66 95 838 791 632 779 218 879 882 517 612 267}
	ALGOR::ARRAYDATA<long> *fourth_array = new ALGOR::ARRAYDATA<long>(10);
	fourth_array->generatedData(1000, 100000);
	// The data is not taken from the output, but from the debugger console
	// fourth_array->[ALGOR::ArrayBase]->ARRAY->array = {37352 57911 49538 19145 81028 74827 22638 18925 48576 95135}
	try
	{
		array_by_size->cloneNewData(fourth_array->getData());
	}
	catch (ALGOR::EXCEPTION_SET::Exception ex)
	{
		std::cout << "\n\nCode: " << ex.code() << ";\n" << ex.what() << "\n-> " << ex.why() << "\n\n";
	}
	// The data is not taken from the output, but from the debugger console
	// array_by_size->[ALGOR::ArrayBase]->ARRAY->array = {37352 57911 49538 19145 81028 74827 22638 18925 48576 95135}
	// arr_siz->array = {Data is lost...} ? BUG
	//! [ARRAYDATA cloneNewData]

	//! [ARRAYDATA cloneData]
	arr_siz = array_by_size->getData();
	// The data is not taken from the output, but from the debugger console
	// arr_siz->array = {37352 57911 49538 19145 81028 74827 22638 18925 48576 95135}
	ALGOR::ARRAYDATA<long> *fifth_array = new ALGOR::ARRAYDATA<long>(6);
	fifth_array->generatedData(6, 16);
	// The data is not taken from the output, but from the debugger console
	// third_array->[ALGOR::ArrayBase]->ARRAY->array = {8 7 14 11 14 13}
	try
	{
		array_by_size->cloneData(fifth_array->getData());
	}
	catch (ALGOR::EXCEPTION_SET::Exception ex)
	{
		std::cout << "\n\nCode: " << ex.code() << ";\n" << ex.what() << "\n-> " << ex.why() << "\n\n";
	}
	// The data is not taken from the output, but from the debugger console
	// array_by_size->[ALGOR::ArrayBase]->ARRAY->array = {8 7 14 11 14 13}
	// arr_siz->array = {37352 57911 49538 19145 81028 74827 22638 18925 48576 95135}
	//! [ARRAYDATA cloneData]

	//! [ARRAYDATA getData]
	// The data is not taken from the output, but from the debugger console
	// arr_str = @0x1b4870
	arr_str = array_by_size->getData();
	// The data is not taken from the output, but from the debugger console
	// arr_str = @0x30c16f0
	//! [ARRAYDATA getData]

	//! [ARRAYDATA getSize]
	std::cout << "Array size is " << array_by_size->getSize() << "\n";
	// >print:> Array size is 6
	//! [ARRAYDATA getSize]

	//! [ARRAYDATA getValue]
	try
	{
		std::cout << "Position is 4; value is " << array_by_size->getValue(4) << "\n";
	}
	catch (ALGOR::EXCEPTION_SET::Exception ex)
	{
		std::cout << "\n\nCode: " << ex.code() << ";\n" << ex.what() << "\n-> " << ex.why() << "\n\n";
	}
	// >print:> Position is 4; value is 8
	//! [ARRAYDATA getValue]

	//! [ARRAYDATA binary_getPosition]
	// Remind you that binary search works only with sorted data
	ALGOR::Comparative_Sorts<long>::LibrarySort sort1(array_by_size->getData()->array, array_by_size->getSize()); //or any sorting
	sort1.library_sort();
	try
	{
		std::cout << "Element \"8\" first encountered at location " << array_by_size->binary_getPosition(8)<< "\n";
	}
	catch (ALGOR::EXCEPTION_SET::Exception ex)
	{
		std::cout << "\n\nCode: " << ex.code() << ";\n" << ex.what() << "\n-> " << ex.why() << "\n\n";
	}
	// >print:> Element "8" first encountered at location 0
	//! [ARRAYDATA binary_getPosition]

	//! [ARRAYDATA lenear_getPosition]
	// Remind you that the ALGOR::ARRAYDATA::lenear_getPosition method returns an array of positions
	try
	{
		Array<asize_t> *NumberPoints = array_by_size->lenear_getPosition(15);
		std::cout << "Element \"15\" first encountered at locations: ";
		for (asize_t i = 0; i < NumberPoints->array_size; i++)
		{
			std::cout << NumberPoints->array[i] + 1 << " ";
		}
		std::cout << "\n";
		remove_struct<asize_t>(NumberPoints);
	}
	catch (ALGOR::EXCEPTION_SET::Exception ex)
	{
		std::cout << "\n\nCode: " << ex.code() << ";\n" << ex.what() << "\n-> " << ex.why() << "\n\n";
	}
	// >print:> Element "15" first encountered at locations: 5 6
	//! [ARRAYDATA lenear_getPosition]

	//! [ARRAYDATA getMin]
	std::cout << "Minimal element is " << array_by_size->getMin() << "\n";
	// >print:> Minimal element is 8
	//! [ARRAYDATA getMin]

	//! [ARRAYDATA getMax]
	std::cout << "Maximal element is " << array_by_size->getMax() << "\n";
	// >print:> Maximal element is 15
	//! [ARRAYDATA getMax]

	//! [ARRAYDATA reset]
	try
	{
		array_by_size->reset();
	}
	catch (ALGOR::EXCEPTION_SET::Exception ex)
	{
		std::cout << "\n\nCode: " << ex.code() << ";\n" << ex.what() << "\n-> " << ex.why() << "\n\n";
	}
	// The data is not taken from the output, but from the debugger console
	// array_by_size->[ALGOR::ArrayBase]->ARRAY->array = {Data is lost...}
	//! [ARRAYDATA reset]

	//! [ARRAYDATA resize]
	// Remind you that array_by_struct was empty until now (with empty data)
	array_by_struct->generatedData(10, 20);
	// The data is not taken from the output, but from the debugger console
	// array_by_size->[ALGOR::ArrayBase]->ARRAY->array = {12 11 18 15 18 17 18 15 16 15 18 11}
	try
	{
		array_by_struct->resize(7, 1);
	}
	catch (ALGOR::EXCEPTION_SET::Exception ex)
	{
		std::cout << "\n\nCode: " << ex.code() << ";\n" << ex.what() << "\n-> " << ex.why() << "\n\n";
	}
	// The data is not taken from the output, but from the debugger console
	// array_by_size->[ALGOR::ArrayBase]->ARRAY->array = {12 11 18 15 18 17 18}
	//! [ARRAYDATA resize]

	//! [ARRAYDATA replace]
	// The data is not taken from the output, but from the debugger console
	// array_by_size->[ALGOR::ArrayBase]->ARRAY->array = {12 11 18 15 18 17 18}
	try
	{
		array_by_struct->replace(5, 100);
	}
	catch (ALGOR::EXCEPTION_SET::Exception ex)
	{
		std::cout << "\n\nCode: " << ex.code() << ";\n" << ex.what() << "\n-> " << ex.why() << "\n\n";
	}
	// The data is not taken from the output, but from the debugger console
	// array_by_size->[ALGOR::ArrayBase]->ARRAY->array = {12 11 18 15 18 100 18}
	//! [ARRAYDATA replace]

	//! [ARRAYDATA reverse]
	// The data is not taken from the output, but from the debugger console
	// array_by_size->[ALGOR::ArrayBase]->ARRAY->array = {12 11 18 15 18 100 18}
	array_by_struct->reverse();
	// The data is not taken from the output, but from the debugger console
	// array_by_size->[ALGOR::ArrayBase]->ARRAY->array = {18 100 18 15 18 11 12}
	//! [ARRAYDATA reverse]

	//! [ARRAYDATA respawn]
	// The data is not taken from the output, but from the debugger console
	// array_by_size->[ALGOR::ArrayBase]->ARRAY->array = {18 100 18 15 18 11 12}
	try
	{
		array_by_struct->respawn();
	}
	catch (ALGOR::EXCEPTION_SET::Exception ex)
	{
		std::cout << "\n\nCode: " << ex.code() << ";\n" << ex.what() << "\n-> " << ex.why() << "\n\n";
	}
	// The data is not taken from the output, but from the debugger console
	// array_by_size->[ALGOR::ArrayBase]->ARRAY->array = {71 25 42 11 32 26 86}
	//! [ARRAYDATA respawn]

	//! [ARRAYDATA searcherOccurrencesOfSubstring]
	// Checking what data we have
	for (unsigned long i = 0; i < array_by_struct->getSize(); i++)
	{
		std::cout << array_by_struct->getData()->array[i] << "; ";
	}
	std::cout << "\n";

	// Сreating a subarray that will be searched in the array
	Array<long> *Sequence = new Array<long>;
	ArrayProcessing<long>::addElement(Sequence->array, Sequence->array_size, 79, 0);
	ArrayProcessing<long>::addElement(Sequence->array, Sequence->array_size, 72, 1);

	// Performing a search and display the result
	try
	{
		ALGOR::Array<asize_t> *Occurrence = array_by_struct->searcherOccurrencesOfSubstring(Sequence, ARRAYDATA<long>::ArrayType::NUMBER);
		std::cout << "Sequence \"79, 72\" first encountered at locations: ";
		for (asize_t i = 0; i < Occurrence->array_size; i++)
		{
			std::cout << Occurrence->array[i] << " ";
		}
		std::cout << "\n";
		remove_struct<asize_t>(Occurrence);
	}
	catch (ALGOR::EXCEPTION_SET::Exception ex)
	{
		std::cout << "\n\nCode: " << ex.code() << ";\n" << ex.what() << "\n-> " << ex.why() << "\n\n";
	}
	remove_struct<long>(Sequence);

	// >print:> Sequence "79, 72" first encountered at locations: 3
	//! [ARRAYDATA searcherOccurrencesOfSubstring]

	//! [ARRAYDATA average]
	try
	{
		std::cout << "Array's average: " << array_by_struct->average() << "\n";
	}
	catch (ALGOR::EXCEPTION_SET::Exception ex)
	{
		std::cout << "\n\nCode: " << ex.code() << ";\n" << ex.what() << "\n-> " << ex.why() << "\n\n";
	}
	// >print:> Array's average: 56
	//! [ARRAYDATA average]

	//! [ARRAYDATA mediana]
	std::cout << "Array's mediana: " << array_by_struct->mediana() << "\n";
	// >print:> Array's mediana: 79
	//! [ARRAYDATA mediana]

	//! [ARRAYDATA moda]
	try
	{
		ALGOR::ARRAYDATA<long>::mode *moda = array_by_struct->moda();
		std::cout << "Most frequent items: ";
		for (asize_t i = 0; i < moda->array_size; i++)
		{
			std::cout << moda->array[i] << " ";
		}
		std::cout << ", namely " << moda->highest_frequency << " times.\n";
		delete[] moda->array;
		delete (moda);
	}
	catch(ALGOR::EXCEPTION_SET::Exception ex)
	{
		std::cout << "There is no mode - all values are unique!\n";
	}
	// >print:> There is no mode - all values are unique!
	//! [ARRAYDATA moda]

	//! [ARRAYDATA =]
	try
	{
		std::cout << (*array_by_size = array_by_struct->getData()) << "\n";
	}
	catch (ALGOR::EXCEPTION_SET::Exception ex)
	{
		std::cout << "\n\nCode: " << ex.code() << ";\n" << ex.what() << "\n-> " << ex.why() << "\n\n";
	}
	// >print:> 1
	// That is, the operation is completed
	//! [ARRAYDATA =]

	//! [ARRAYDATA ==]
	std::cout << (*array_by_size == array_by_struct->getData()) << "\n";
	// >print:> 1
	// That is, the values are equal
	//! [ARRAYDATA ==]

	//! [ARRAYDATA ^=]
	// The data is not taken from the output, but from the debugger console
	// array_by_size->[ALGOR::ArrayBase]->ARRAY->array = {10 53 86 79 72 43 52}
	try
	{
		*array_by_size ^= 13;
	}
	catch (ALGOR::EXCEPTION_SET::Exception ex)
	{
		std::cout << "\n\nCode: " << ex.code() << ";\n" << ex.what() << "\n-> " << ex.why() << "\n\n";
	}
	// The data is not taken from the output, but from the debugger console
	// array_by_size->[ALGOR::ArrayBase]->ARRAY->array = {10 53 86 79 72 43 52 1 1 1 1 1 1}
	//! [ARRAYDATA ^=]

	//! [ARRAYDATA +=]
	// The data is not taken from the output, but from the debugger console
	// array_by_size->[ALGOR::ArrayBase]->ARRAY->array = {10 53 86 79 72 43 52 1 1 1 1 1 1}
	*array_by_size += 15;
	// The data is not taken from the output, but from the debugger console
	// array_by_size->[ALGOR::ArrayBase]->ARRAY->array = {25 68 101 94 87 58 67 16 16 16 16 16 16}
	//! [ARRAYDATA +=]

	//! [ARRAYDATA -=]
	// The data is not taken from the output, but from the debugger console
	// array_by_size->[ALGOR::ArrayBase]->ARRAY->array = {25 68 101 94 87 58 67 16 16 16 16 16 16}
	*array_by_size -= 17;
	// The data is not taken from the output, but from the debugger console
	// array_by_size->[ALGOR::ArrayBase]->ARRAY->array = {8 51 84 77 70 41 50 -1 -1 -1 -1 -1 -1}
	//! [ARRAYDATA -=]

	//! [ARRAYDATA *=]
	// The data is not taken from the output, but from the debugger console
	// array_by_size->[ALGOR::ArrayBase]->ARRAY->array = {8 51 84 77 70 41 50 -1 -1 -1 -1 -1 -1}
	*array_by_size *= 19;
	// The data is not taken from the output, but from the debugger console
	// array_by_size->[ALGOR::ArrayBase]->ARRAY->array = {152 969 1596 1463 1330 779 950 -19 -19 -19 -19 -19 -19}
	//! [ARRAYDATA *=]

	//! [ARRAYDATA /=]
	// The data is not taken from the output, but from the debugger console
	// array_by_size->[ALGOR::ArrayBase]->ARRAY->array = {152 969 1596 1463 1330 779 950 -19 -19 -19 -19 -19 -19}
	try
	{
		*array_by_size /= 21;
	}
	catch (ALGOR::EXCEPTION_SET::Exception ex)
	{
		std::cout << "\n\nCode: " << ex.code() << ";\n" << ex.what() << "\n-> " << ex.why() << "\n\n";
	}
	// The data is not taken from the output, but from the debugger console
	// array_by_size->[ALGOR::ArrayBase]->ARRAY->array = {7 46 76 69 63 37 45 0 0 0 0 0 0}
	// Since we have an array of integers, the remainder of the division is discarded
	//! [ARRAYDATA /=]

	//! [ARRAYDATA &=]
	// The data is not taken from the output, but from the debugger console
	// array_by_size->[ALGOR::ArrayBase]->ARRAY->array = {7 46 76 69 63 37 45 0 0 0 0 0 0}
	try
	{
		*array_by_size &= 23;
	}
	catch (ALGOR::EXCEPTION_SET::Exception ex)
	{
		std::cout << "\n\nCode: " << ex.code() << ";\n" << ex.what() << "\n-> " << ex.why() << "\n\n";
	}
	// The data is not taken from the output, but from the debugger console
	// array_by_size->[ALGOR::ArrayBase]->ARRAY->array = {7 46 76 69 63 37 45 0 0 0 0 0 0 23}
	//! [ARRAYDATA &=]

	//! [ARRAYDATA |=]
	// The data is not taken from the output, but from the debugger console
	// array_by_size->[ALGOR::ArrayBase]->ARRAY->array = {7 46 76 69 63 37 45 0 0 0 0 0 0 23}
	try
	{
		*array_by_size |= 45;
	}
	catch (ALGOR::EXCEPTION_SET::Exception ex)
	{
		std::cout << "\n\nCode: " << ex.code() << ";\n" << ex.what() << "\n-> " << ex.why() << "\n\n";
	}
	// The data is not taken from the output, but from the debugger console
	// array_by_size->[ALGOR::ArrayBase]->ARRAY->array = {7 46 76 69 63 37 0 0 0 0 0 0 23}
	//! [ARRAYDATA |=]

	//! [ARRAYDATA !]
	// The data is not taken from the output, but from the debugger console
	// array_by_size->[ALGOR::ArrayBase]->ARRAY->array = {7 46 76 69 63 37 0 0 0 0 0 0 23}
	try
	{
		!*array_by_size;
	}
	catch (ALGOR::EXCEPTION_SET::Exception ex)
	{
		std::cout << "\n\nCode: " << ex.code() << ";\n" << ex.what() << "\n-> " << ex.why() << "\n\n";
	}
	// The data is not taken from the output, but from the debugger console
	// array_by_size->[ALGOR::ArrayBase]->ARRAY->array = {7 46 76 69 63 37 0 0 0 0 0 0}
	//! [ARRAYDATA !]

	//! [ARRAYDATA <<=]
	// The data is not taken from the output, but from the debugger console
	// array_by_struct->[ALGOR::ArrayBase]->ARRAY->array = {10 53 86 79 72 43 52}
	// array_by_size->[ALGOR::ArrayBase]->ARRAY->array = {7 46 76 69 63 37 0 0 0 0 0 0}
	try
	{
		*array_by_size <<= array_by_struct;
	}
	catch (ALGOR::EXCEPTION_SET::Exception ex)
	{
		std::cout << "\n\nCode: " << ex.code() << ";\n" << ex.what() << "\n-> " << ex.why() << "\n\n";
	}
	// The data is not taken from the output, but from the debugger console
	// array_by_struct->[ALGOR::ArrayBase]->ARRAY->array = {10 53 86 79 72 43 52}
	// array_by_size->[ALGOR::ArrayBase]->ARRAY->array = {7 46 76 69 63 37 0 0 0 0 0 0 10 53 86 79 72 43 52}
	//! [ARRAYDATA <<=]

	//! [ARRAYDATA >>=]
	// The data is not taken from the output, but from the debugger console
	// array_by_struct->[ALGOR::ArrayBase]->ARRAY->array = {10 53 86 79 72 43 52}
	// array_by_size->[ALGOR::ArrayBase]->ARRAY->array = {7 46 76 69 63 37 0 0 0 0 0 0 10 53 86 79 72 43 52}
	try
	{
		*array_by_size >>= array_by_struct;
	}
	catch (ALGOR::EXCEPTION_SET::Exception ex)
	{
		std::cout << "\n\nCode: " << ex.code() << ";\n" << ex.what() << "\n-> " << ex.why() << "\n\n";
	}
	// The data is not taken from the output, but from the debugger console
	// array_by_struct->[ALGOR::ArrayBase]->ARRAY->array = {10 53 86 79 72 43 52 7 46 76 69 63 37 0 0 0 0 0 0 10 53 86 79 72 43 52}
	// array_by_size->[ALGOR::ArrayBase]->ARRAY->array = {7 46 76 69 63 37 0 0 0 0 0 0 10 53 86 79 72 43 52}
	//! [ARRAYDATA >>=]

	std::cin.get();
	return 0;
}
