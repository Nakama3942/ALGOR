#include <iostream>
using std::cin;
using std::cout;

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
			cout << " " << (*Array)->array[i];
		}
		cout << "\n";
	}

private:
	ALGOR::Array<type_array> **Array;
};
//! [printer]

int main()
{
	//! [print]
	//Створюю структуру масиву та генерую данні
	ALGOR::Array<ALGOR::byte4_t> *D = create_struct<ALGOR::byte4_t>(10);
	generate_struct<ALGOR::byte4_t>(D, 10, 1000);

	//Створюю об'єкт принтера і передаю йому посилання на структуру
	printer<ALGOR::byte4_t> pr;
	pr.setData(&D);

	//Виводжу данні
	pr.print();
	//print 597 104 23 150 491 594 495 428 875 382

	//Не забуваю у кінці програми звільнити данні
	remove_struct<ALGOR::byte4_t>(D);
	//! [print]

	cin.get();
	return 0;
}
