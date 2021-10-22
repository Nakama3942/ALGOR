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
    SortingAlgorithms::ArrayProcessing<int>::generatedArray(array, g_arraySize, 1, 1000);

    //Копирую массив
    int *array1 = new int[g_arraySize];
    SortingAlgorithms::ArrayProcessing<int>::copy(array1, array, g_arraySize);

    //Вывожу на экран массив
    print<int>("Сгенерированный массив: ", array1, g_arraySize);

    //Сортирую массив
    SortingAlgorithms::InsertSort<int>::insert_sort(array1, g_arraySize);
    //SortingAlgorithms::BubbleSort<int>::bubble_sort(array1, g_arraySize);
    //SortingAlgorithms::CocktailShakerSort<int>::cocktail_shaker_sort(array1, g_arraySize);
    //SortingAlgorithms::MergeSort<int>::merge_sort(array1, 0, g_arraySize - 1);
    //SortingAlgorithms::HeapSort<int>::heap_sort(array1, g_arraySize);
    //SortingAlgorithms::QuickSort<int>::quick_sort(array1, 0, g_arraySize - 1);
    //SortingAlgorithms::CountingSort::counting_sort(array1, g_arraySize);
    //SortingAlgorithms::RadixSort::radix_sort(array1, g_arraySize);

    //Вывожу на экран массив
    print<int>("Отсортированный массив: ", array1, g_arraySize);

    //Нахожу среднее арифметическое
    int average;
    SortingAlgorithms::ArrayProcessing<int>::average(array1, g_arraySize, average);
    cout << "Среднее арифметическое: " << average << "\n";

    //Нахожу медиану
    int mediana;
    SortingAlgorithms::ArrayProcessing<int>::mediana(array1, g_arraySize, mediana);
    cout << "Медиана: " << mediana << "\n";

    //Нахожу моду с количеством
    int moda, moda_count;
    SortingAlgorithms::ArrayProcessing<int>::moda(array1, g_arraySize, moda, moda_count);
    cout << "Чаще всего встречается элемент: " << moda << ", а именно " << moda_count << " раз.\n";

    delete[] array1;
    delete[] array;

    return 0;
}
