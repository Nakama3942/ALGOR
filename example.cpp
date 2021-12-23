#include <iostream>
using std::cout;

#include "ALGOR.hpp"

template <typename type_array>
void printer(Array<type_array> *&ARRAY)
{
    for (unsigned int i = 0; i < ARRAY->array_size; i++)
    {
        cout << " " << ARRAY->array[i];
    }
    cout << "\n";
}

int main()
{
    //Структура для вытягивания массива из объекта
    Array<int> *ArrayStruct;

    //Генерация (заполнение) массива
    ARRAYDATA<int> *array = new ARRAYDATA<int>(12);
    array->generatedData(1, 100);

    //Вывод на экран неотсортированного массива
    ArrayStruct = array->getData();
    printer(ArrayStruct);

    //Копирование массива
    ARRAYDATA<int> *copy_array = new ARRAYDATA<int>(12);
    copy_array->cloneData(array);

    //Сортировка массива
    ArrayStruct = copy_array->getData();
    //Exchange_Sorts::BubbleSort<int> *sort = new Exchange_Sorts::BubbleSort<int>(ArrayStruct);
    //Exchange_Sorts::CocktailShakerSort<int> *sort = new Exchange_Sorts::CocktailShakerSort<int>(ArrayStruct);
    //Exchange_Sorts::QuickSort<int> *sort = new Exchange_Sorts::QuickSort<int>(ArrayStruct);
    //Selection_Sorts::HeapSort<int> *sort = new Selection_Sorts::HeapSort<int>(ArrayStruct);
    //Insertion_Sorts::InsertSort<int> *sort = new Insertion_Sorts::InsertSort<int>(ArrayStruct);
    //Merge_Sorts::MergeSort<int> *sort = new Merge_Sorts::MergeSort<int>(ArrayStruct);
    Noncomparison_Sort::CountingSort *sort = new Noncomparison_Sort::CountingSort(ArrayStruct);
    //Noncomparison_Sort::RadixSort *sort = new Noncomparison_Sort::RadixSort(ArrayStruct);
    sort->start_sort();
    delete (sort);

    //Вывод на экран отсортированного массива
    printer(ArrayStruct);

    //Изменение размера массива
    array->resize(7, 1);
    array->getData(ArrayStruct);
    printer(ArrayStruct);

    //Нахождение максимального и минимального элемента
    //cout << "Минимальный элемент: " << minimum(array->getData()->array, array->getData()->array_size) << "; Максимальный: " << maximum(copy_array->getData()->array, copy_array->getData()->array_size) << "\n";
    cout << "Минимальный элемент: " << array->getMin() << "; Максимальный: " << copy_array->getMax(ArrayStatus::SORTED) << "\n";

    //Нахождение определённого элемента в неотсортированном массиве
    try
    {
        Array<int> *NumberPoints = array->lenear_searcher(5);
        cout << "Элемент \"5\" встречается на местах: \n";
        for (unsigned int i = 0; i < NumberPoints->array_size; i++)
        {
            cout << NumberPoints->array[i] + 1 << " ";
        }
        cout << "\n";
        remove_struct<int>(NumberPoints);
    }
    catch (int)
    {
        cout << "Элемент \"5\" не найден...\n";
    }

    //Нахождение определённого элемента в отсортированном массиве
    try
    {
        cout << "Элемент \"7\" впервые встратился на месте " << copy_array->binary_searcher(7) + 1 << "\n";
    }
    catch (int)
    {
        cout << "Элемент \"7\" не найден...\n";
    }

    //Нахождение последовательности
    Array<int> *Sequence = new Array<int>;
    addElement<int>(Sequence->array, Sequence->array_size, 5);
    addElement<int>(Sequence->array, Sequence->array_size, 6);
    try
    {
        Array<int> *Occurrence = copy_array->searcherOccurrencesOfSubstring(Sequence);
        cout << "Последовательность \"5, 6\" встречается на местах: \n";
        for (unsigned int i = 0; i < Occurrence->array_size; i++)
        {
            cout << Occurrence->array[i] + 1 << " ";
        }
        cout << "\n";
        remove_struct<int>(Occurrence);
    }
    catch (int)
    {
        cout << "Последовательность \"5, 6\" не найдена...\n";
    }
    remove_struct<int>(Sequence);

    //Нахождение среднего арифметического
    cout << "Среднее арифметическое: " << copy_array->average() << "\n";

    //Нахождение медианы
    cout << "Медиана: " << copy_array->mediana() << "\n";

    //Нахождение моды с количеством
    int moda_count, moda = copy_array->moda(moda_count);
    cout << "Чаще всего встречается элемент: " << moda << ", а именно " << moda_count << " раз.\n";

    //Нахождение мод с количеством
    int modas_count;
    Array<int> *Modas = copy_array->modas(modas_count);
    cout << "Чаще всего встречаются элементы: ";
    for (unsigned int i = 0; i < Modas->array_size; i++)
    {
        cout << Modas->array[i] << " ";
    }
    cout << ", а именно " << modas_count << " раз.\n";
    remove_struct<int>(Modas);

    //Тест операторов
    *array + 10;
    Array<int> *temp = array->getData();
    for (unsigned int i = 7; i < temp->array_size; i++)
    {
        temp->array[i] = i;
    }
    printer(temp);
    *array && 2;
    temp = array->getData();
    printer(temp);

    //Освобождение памяти
    copy_array->remove();
    delete (copy_array);
    array->remove();
    delete (array);

    //Выход из программы
    //cin.get();
    //cin.get();
    return 0;
}
