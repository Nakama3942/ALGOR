/* ********************************************************************* *
 * Тестування бібліотеки (можна самому скомпілювати бібліотеку           *
 *  (перший варіант) чи використати IDE-шну версію (другий варіант)).    *
 *                                                                       *
 *	№1) g++ ../ALGOR.cpp -s -shared -o ALGOR2.dll                        *
 *	№2) cp ../../build-ALGOR-TDM_GCC-Debug/debug/ALGOR2.dll ./ALGOR2.dll *
 *                                                                       *
 *  Далі просто компілюється програма тесту, запускається                *
 *  та виводиться результат роботи:                                      *
 *                                                                       *
 *	g++ -s -o test.exe test.cpp -L. -lALGOR2                             *
 *	./test.exe                                                           *
 *	cat ./test_report.txt                                                *
 * ********************************************************************* */

#include <fstream>
using std::fstream;

#include "N:/ALGOR/ALGOR.hpp"
using namespace ALGOR;

template <typename type_array>
class printer : public Printer<type_array>
{
public:
	void setData(Array<type_array> **ARRAY)
	{
		Array = ARRAY;
	}
	void setFile(fstream *report_file)
	{
		this->report_file = report_file;
	}
	void print() override
	{
		for (asize_t i = 0; i < (*Array)->array_size; i++)
		{
			*report_file << " " << (*Array)->array[i];
		}
		*report_file << "\n";
	}
private:
	Array<type_array> **Array;
	fstream *report_file;
};

int main()
{
	//Файл з результатом роботи
	fstream report("test_report.txt", std::ios_base::out | std::ios_base::trunc);

	//Структура для вытягивания массива из объекта
	Array<int> *ArrayStruct = nullptr;

	//Об'єкт для друку
	printer<int> pr;
	pr.setData(&ArrayStruct);
	pr.setFile(&report);

	//Генерация (заполнение) массива
	ARRAYDATA<int> *array = new ARRAYDATA<int>(12);
	array->generatedData(1, 10);

	//Вывод на экран неотсортированного массива
	ArrayStruct = array->getData();
	pr.print();

	//Копирование массива
	ARRAYDATA<int> *copy_array = new ARRAYDATA<int>(12);
	copy_array->cloneData(array);

	//Сортировка массива
	ArrayStruct = copy_array->getData();

//	Comparative_Sorts<int>::LibrarySort *sort = new Comparative_Sorts<int>::LibrarySort(ArrayStruct->array, ArrayStruct->array_size);
//	sort->library_sort();
	Comparative_Sorts<int> *sort = new Comparative_Sorts<int>(ArrayStruct);
	sort->Library_Sort();

//	Distribution_Sorts::BucketSort *sort = new Distribution_Sorts::BucketSort(ArrayStruct->array, ArrayStruct->array_size);
//	sort->bucket_sort();
//	Distribution_Sorts *sort = new Distribution_Sorts(ArrayStruct);
//	sort->Bucket_Sort();

	delete (sort);

	//Вывод на экран отсортированного массива
	pr.print();

	ArrayProcessing<int>::isOrderliness(ArrayStruct->array, ArrayStruct->array_size) ? report << "Масив отсортовано\n" : report << "Масив НЕ отсортовано\n" ;

	//Изменение размера массива
	array->resize(7, 1);
	array->getData(ArrayStruct);
	pr.print();

	//Нахождение максимального и минимального элемента
	//cout << "Минимальный элемент: " << minimum(array->getData()->array, array->getData()->array_size) << "; Максимальный: " << maximum(copy_array->getData()->array, copy_array->getData()->array_size) << "\n";
	report << "Минимальный элемент: " << array->getMin() << "; Максимальный: " << copy_array->getMax() << "\n";

	//Нахождение определённого элемента в неотсортированном массиве
	try
	{
		Array<int> *NumberPoints = array->lenear_searcher(5);
		report << "Элемент \"5\" встречается на местах: \n";
		for (asize_t i = 0; i < NumberPoints->array_size; i++)
		{
			report << NumberPoints->array[i] + 1 << " ";
		}
		report << "\n";
		remove_struct<int>(NumberPoints);
	}
	catch (Exception)
	{
		report << "Элемент \"5\" не найден...\n";
	}

	//Нахождение определённого элемента в отсортированном массиве
	try
	{
		report << "Элемент \"7\" впервые встратился на месте " << copy_array->binary_searcher(7) + 1 << "\n";
	}
	catch (Exception)
	{
		report << "Элемент \"7\" не найден...\n";
	}

	//Нахождение последовательности
	Array<int> *Sequence = new Array<int>;
	ArrayProcessing<int>::addElement(Sequence->array, Sequence->array_size, 5);
	ArrayProcessing<int>::addElement(Sequence->array, Sequence->array_size, 6);
	try
	{
		Array<int> *Occurrence = copy_array->searcherOccurrencesOfSubstring(Sequence);
		report << "Последовательность \"5, 6\" встречается на местах: \n";
		for (asize_t i = 0; i < Occurrence->array_size; i++)
		{
			report << Occurrence->array[i] + 1 << " ";
		}
		report << "\n";
		remove_struct<int>(Occurrence);
	}
	catch (Exception)
	{
		report << "Последовательность \"5, 6\" не найдена...\n";
	}
	remove_struct<int>(Sequence);

	//Нахождение среднего арифметического
	report << "Среднее арифметическое: " << copy_array->average() << "\n";

	//Нахождение медианы
	report << "Медиана: " << copy_array->mediana() << "\n";

	//Нахождение моды с количеством
	int moda_count, moda = copy_array->moda(moda_count);
	report << "Чаще всего встречается элемент: " << moda << ", а именно " << moda_count << " раз.\n";

	//Нахождение мод с количеством
	int modas_count;
	Array<int> *Modas = copy_array->modas(modas_count);
	report << "Чаще всего встречаются элементы: ";
	for (unsigned int i = 0; i < Modas->array_size; i++)
	{
		report << Modas->array[i] << " ";
	}
	report << ", а именно " << modas_count << " раз.\n";
	remove_struct<int>(Modas);

	//Тест операторов
	*array + 10;
	Array<int> *temp = array->getData();
	for (unsigned int i = 7; i < temp->array_size; i++)
	{
		temp->array[i] = i;
	}
	pr.setData(&temp);
	pr.print();
	*array && 2;
	temp = array->getData();
	pr.print();

	//Освобождение памяти
	delete (copy_array);
	delete (array);

	//Тестую функції distance() та подібні
	ARRAYDATA<int> *test = new ARRAYDATA<int>(20);
	test->generatedData(1, 18);
	ArrayStruct = test->getData();
	Comparative_Sorts<int> *tsort = new Comparative_Sorts<int>(ArrayStruct);
	tsort->Library_Sort();
	delete (tsort);
	report << "Distance = " << ArrayProcessing<int>::distance(&ArrayStruct->array[2], &ArrayStruct->array[8]) << "\n";
	pr.setData(&ArrayStruct);
	pr.print();
	report << "ArrayStruct address " << &ArrayStruct->array[0] << " and lower_bound = " << ArrayProcessing<int>::lower_bound(&ArrayStruct->array[0], &ArrayStruct->array[8], 3) << "\n";
	report << "ArrayStruct address " << &ArrayStruct->array[0] << " and upper_bound = " << ArrayProcessing<int>::upper_bound(&ArrayStruct->array[0], &ArrayStruct->array[8], 3) << "\n";
	delete (test);

	//Выход из программы
	//cin.get();
	//cin.get();
	return 0;
}
