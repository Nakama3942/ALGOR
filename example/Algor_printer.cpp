#include <iostream>
using std::cin;
using std::cout;

#include "../src/ALGOR.hpp"

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
	//Створюю вказівник на структуру
	ALGOR::Array<ALGOR::byte8_t> *D;

	//Створюю об'єкт принтера і передаю йому посилання на структуру
	printer<ALGOR::byte8_t> *pr = new printer<ALGOR::byte8_t>;
	pr->setData(&D);

	//Створюю об'єкт класу масиву та генерую данні
	ALGOR::ARRAYDATA<ALGOR::byte8_t> *A = new ALGOR::ARRAYDATA<ALGOR::byte8_t>(35);
	A->generatedData(10, 1000);

	//Зберігаю у структурі вказівник на масив
	D = A->getData();

	//Виводжу данні
	pr->print();
	//! [print]

	cin.get();
	return 0;
}