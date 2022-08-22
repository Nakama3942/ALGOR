#include <iostream>

#include "../include/ALGOR.hpp"
using namespace ALGOR;

//! [printer]
template <typename type_array>
class printer : public ALGOR::Printer
{
public:
	void setData(ALGOR::Array<type_array> **ARRAY)
	{
		Array = ARRAY;
	}
	void print() override
	{
		for (asize_t i = 0; i < (*Array)->array_size; i++)
		{
			std::cout << " " << (*Array)->array[i];
		}
		std::cout << "\n";
	}

private:
	ALGOR::Array<type_array> **Array;
};
//! [printer]

int main()
{
	//! [print]
	// Creating an array structure and generating data
	ALGOR::Array<long> *D = create_struct<long>(10);
	generate_struct<long>(D, 10, 1000);

	// Creating a printer object and passing it a reference to the structure
	printer<long> pr;
	pr.setData(&D);

	// Outputting data
	pr.print();
	// >print:> 597 104 23 150 491 594 495 428 875 382

	// Don't forget to free data at the end of the program
	remove_struct<long>(D);
	//! [print]

	std::cin.get();
	return 0;
}
