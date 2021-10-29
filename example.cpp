#include <iostream>
using namespace std;

#include "sortingalgorithms.hpp"

const int g_arraySize = 1024;

template <typename type_array>
void print(const char *representing_string, type_array *Array, int array_size)
{
    cout << representing_string;
    for (int i = 0; i < array_size; i++)
    {
        cout << Array[i] << "\t";
    }
    cout << "\n";
}

int main()
{
    int *array = new int[g_arraySize];

    //Генерирую (заполняю) массив
    ArrayProcessing<int>::generatedArray(array, g_arraySize, 1, 1000);

    //Копирую массив
    int *array1 = new int[g_arraySize];
    ArrayProcessing<int>::copy(array1, array, g_arraySize);

    //Вывожу на экран массив
    print<int>("Сгенерированный массив: ", array1, g_arraySize);

    //Сортирую массив
    Exchange_Sorts::BubbleSort<int>::bubble_sort(array1, g_arraySize);
    //Exchange_Sorts::CocktailShakerSort<int>::cocktail_shaker_sort(array1, g_arraySize);
    //Exchange_Sorts::QuickSort<int>::quick_sort(array1, 0, g_arraySize - 1);
    //Selection_Sorts::HeapSort<int>::heap_sort(array1, g_arraySize);
    //Insertion_Sorts::InsertSort<int>::insert_sort(array1, g_arraySize);
    //Merge_Sorts::MergeSort<int>::merge_sort(array1, 0, g_arraySize - 1);
    //Noncomparison_Sort::CountingSort::counting_sort(array1, g_arraySize);
    //Noncomparison_Sort::RadixSort::radix_sort(array1, g_arraySize);

    //Вывожу на экран массив
    print<int>("Отсортированный массив: ", array1, g_arraySize);

    //Нахожу среднее арифметическое
    int average;
    ArrayProcessing<int>::average(array1, g_arraySize, average);
    cout << "Среднее арифметическое: " << average << "\n";

    //Нахожу медиану
    int mediana;
    ArrayProcessing<int>::mediana(array1, g_arraySize, mediana);
    cout << "Медиана: " << mediana << "\n";

    //Нахожу моду с количеством
    int moda, moda_count;
    ArrayProcessing<int>::moda(array1, g_arraySize, moda, moda_count);
    cout << "Чаще всего встречается элемент: " << moda << ", а именно " << moda_count << " раз.\n";

    delete[] array1;
    delete[] array;

    return 0;
}
