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

#include <iostream>
using std::cout;

#include "N:/ALGOR/src/ALGOR.hpp"
using namespace ALGOR;
using namespace ALGOR::SORTING;

template <typename type_array>
class printer : public Printer<type_array>
{
public:
    void setData(Array<type_array> **ARRAY)
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
    Array<type_array> **Array;
};

int main()
{
    cout << getMemoryCell() << "\n";

    //Структура для вытягивания массива из объекта
    Array<byte8_t> *ArrayStruct = nullptr;

    //Об'єкт для друку
    printer<byte8_t> pr;
    pr.setData(&ArrayStruct);

    //Генерация (заполнение) массива
    ARRAYDATA<byte8_t> *array = new ARRAYDATA<byte8_t>(8);
    array->generatedData(1, 10);

    //Вывод на экран неотсортированного массива
    ArrayStruct = array->getData();
    pr.print();

    //Копирование массива
    ARRAYDATA<byte8_t> *copy_array = new ARRAYDATA<byte8_t>(10);
    copy_array->cloneData(ArrayStruct);

    //Сортировка массива
    ArrayStruct = copy_array->getData();

    //	Comparative_Sorts<int>::LibrarySort *sort = new Comparative_Sorts<int>::LibrarySort(ArrayStruct->array, ArrayStruct->array_size);
    //	sort->library_sort();
    Comparative_Sorts<byte8_t> *sort = new Comparative_Sorts<byte8_t>(ArrayStruct);
    sort->Bitonic_Sorter();

    //	Distribution_Sorts::BucketSort *sort = new Distribution_Sorts::BucketSort(ArrayStruct->array, ArrayStruct->array_size);
    //	sort->bucket_sort();
    //	Distribution_Sorts *sort = new Distribution_Sorts(ArrayStruct);
    //	sort->Bucket_Sort();

    delete (sort);

    //Вывод на экран отсортированного массива
    pr.print();

    ArrayProcessing<byte8_t>::isOrderliness(ArrayStruct->array, ArrayStruct->array_size) ? cout << "Масив отсортовано\n" : cout << "Масив НЕ отсортовано\n";

    //Изменение размера массива
    array->resize(7, 1);
    ArrayStruct = array->getData();
    pr.print();

    //Нахождение максимального и минимального элемента
    // cout << "Минимальный элемент: " << minimum(array->getData()->array, array->getData()->array_size) << "; Максимальный: " << maximum(copy_array->getData()->array, copy_array->getData()->array_size) << "\n";
    cout << "Минимальный элемент: " << array->getMin() << "; Максимальный: " << copy_array->getMax() << "\n";

    //Нахождение определённого элемента в неотсортированном массиве
    try
    {
        Array<asize_t> *NumberPoints = array->lenear_searcher(5);
        cout << "Элемент \"5\" встречается на местах: \n";
        for (asize_t i = 0; i < NumberPoints->array_size; i++)
        {
            cout << NumberPoints->array[i] + 1 << " ";
        }
        cout << "\n";
        remove_struct<asize_t>(NumberPoints);
    }
    catch (EXCEPTION_SET::Exception)
    {
        cout << "Элемент \"5\" не найден...\n";
    }

    //Нахождение определённого элемента в отсортированном массиве
    try
    {
        cout << "Элемент \"7\" впервые встратился на месте " << copy_array->binary_searcher(7) + 1 << "\n";
    }
    catch (EXCEPTION_SET::Exception)
    {
        cout << "Элемент \"7\" не найден...\n";
    }

    //Нахождение последовательности
    Array<byte8_t> *Sequence = new Array<byte8_t>;
    ArrayProcessing<byte8_t>::addElement(Sequence->array, Sequence->array_size, 5, 0);
    ArrayProcessing<byte8_t>::addElement(Sequence->array, Sequence->array_size, 6, 1);
    try
    {
        Array<asize_t> *Occurrence = copy_array->searcherOccurrencesOfSubstring(Sequence);
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
        cout << "\n\nCode: " << ex.code() << ";\n"
             << ex.what() << "\n-> " << ex.why() << "\n\n";
        cout << "Последовательность \"5, 6\" не найдена...\n";
    }
    remove_struct<byte8_t>(Sequence);

    //Нахождение среднего арифметического
    cout << "Среднее арифметическое: " << copy_array->average() << "\n";

    //Нахождение медианы
    cout << "Медиана: " << copy_array->mediana() << "\n";

    //Нахождение моды с её частотой
    ARRAYDATA<byte8_t>::mode *moda = copy_array->moda();
    cout << "Чаще всего встречаются элементы: ";
    for (asize_t i = 0; i < moda->array_size; i++)
    {
        cout << moda->array[i] << " ";
    }
    cout << ", а именно " << moda->highest_frequency << " раз.\n";

    delete[] moda->array;
    delete (moda);

    //Тест операторов
    *array += 10;
    Array<byte8_t> *temp = array->getData();
    for (asize_t i = 7; i < temp->array_size; i++)
    {
        temp->array[i] = i;
    }
    pr.setData(&temp);
    pr.print();
    *array &= 13;
    temp = array->getData();
    pr.print();

    //Освобождение памяти
    delete (copy_array);
    delete (array);

    //Тестую функції distance() та подібні
    ARRAYDATA<byte8_t> *test = new ARRAYDATA<byte8_t>(20);
    test->generatedData(1, 18);
    ArrayStruct = test->getData();
    Comparative_Sorts<byte8_t> *tsort = new Comparative_Sorts<byte8_t>(ArrayStruct);
    tsort->Library_Sort();
    delete (tsort);
    cout << "Distance = " << ArrayProcessing<byte8_t>::distance(&ArrayStruct->array[0], &ArrayStruct->array[ArrayStruct->array_size]) << " and array_size = " << ArrayStruct->array_size << "\n";
    pr.setData(&ArrayStruct);
    pr.print();
    cout << "ArrayStruct address " << &ArrayStruct->array[0] << " and lower_bound = " << ArrayProcessing<byte8_t>::lower_bound(&ArrayStruct->array[0], &ArrayStruct->array[8], 3) << "\n";
    cout << "ArrayStruct address " << &ArrayStruct->array[0] << " and upper_bound = " << ArrayProcessing<byte8_t>::upper_bound(&ArrayStruct->array[0], &ArrayStruct->array[8], 3) << "\n";
    delete (test);

    //Выход из программы
    // cin.get();
    // cin.get();
    return 0;
}