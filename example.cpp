#include <iostream>
using namespace std;

#include "sortingalgorithms.hpp"

//const int g_arraySize = 1024;
const int g_arraySize = 64;

template <typename type_array>
void print(const char *representing_string, type_array *Array, int array_size)
{
    cout << representing_string;
    for (int i = 0; i < array_size; i++)
    {
        cout << i + 1 << "->" << Array[i] << "\t";
    }
    cout << "\n";
}

int main()
{
    int *array = new int[g_arraySize];

    //Генерирую (заполняю) массив
    ArrayProcessing::generatedArray<int>(array, g_arraySize, 1, 50);

    //Вывожу на экран массив
    print<int>("Сгенерированный массив: ", array, g_arraySize);

    //Копирую массив
    int *array1 = new int[g_arraySize];
    ArrayProcessing::copy<int>(array1, array, g_arraySize);

    //Сортирую массив
    //Exchange_Sorts::BubbleSort<int>::bubble_sort(array1, g_arraySize);
    //Exchange_Sorts::CocktailShakerSort<int>::cocktail_shaker_sort(array1, g_arraySize);
    //Exchange_Sorts::QuickSort<int>::quick_sort(array1, 0, g_arraySize - 1);
    //Selection_Sorts::HeapSort<int>::heap_sort(array1, g_arraySize);
    //Insertion_Sorts::InsertSort<int>::insert_sort(array1, g_arraySize);
    //Merge_Sorts::MergeSort<int>::merge_sort(array1, 0, g_arraySize - 1);
    Noncomparison_Sort::CountingSort::counting_sort(array1, g_arraySize);
    //Noncomparison_Sort::RadixSort::radix_sort(array1, g_arraySize);

    //Вывожу на экран массив
    print<int>("Отсортированный массив: ", array1, g_arraySize);

    //Нахожу максимальный и минимальный элемент
    int min, max;
    ArrayProcessing::getMin<int>(array1, g_arraySize, min, ArrayProcessing::SORTED);
    ArrayProcessing::getMax<int>(array1, g_arraySize, max, ArrayProcessing::SORTED);
    cout << "Минимальный элемент: " << min << "; Максимальный: " << max << "\n";

    //Нахожу последовательность
    int sequence[2] = {20, 21}, *occurrence, occurrence_size;
    try
    {
        ArrayProcessing::getOccurrencesOfSubstring<int>(array1, g_arraySize, sequence, 2, occurrence, occurrence_size);
        cout << "Последовательность \"20, 21\" встречается на местах: \n";
        for (int i = 0; i < occurrence_size; i++)
        {
            cout << occurrence[i] + 1 << " ";
        }
        cout << "\n";
    }
    catch (int)
    {
        cout << "Последовательность \"20, 21\" не найдена...\n";
    }

    //Нахожу определённый элемент в неотсортированном массиве
    int *number_points, number_points_size;
    try
    {
        ArrayProcessing::getElementsNumber_lenear<int>(array, g_arraySize, 20, number_points, number_points_size);
        cout << "Элемент \"20\" встречается на местах: \n";
        for (int i = 0; i < number_points_size; i++)
        {
            cout << number_points[i] + 1 << " ";
        }
        cout << "\n";
    }
    catch (int)
    {
        cout << "Элемент \"20\" не найден...\n";
    }

    //Нахожу определённый элемент в отсортированном массиве
    int number_point;
    try
    {
        ArrayProcessing::getElementNumber_binary<int>(array1, 0, g_arraySize - 1, 23, number_point);
        cout << "Элемент \"23\" впервые встратился на месте " << number_point + 1 << "\n";
    }
    catch (int)
    {
        cout << "Элемент \"23\" не найден...\n";
    }

    //Нахожу среднее арифметическое
    int average;
    ArrayProcessing::average<int>(array1, g_arraySize, average);
    cout << "Среднее арифметическое: " << average << "\n";

    //Нахожу медиану
    int mediana;
    ArrayProcessing::mediana<int>(array1, g_arraySize, mediana);
    cout << "Медиана: " << mediana << "\n";

    //Нахожу моду с количеством
    int moda, moda_count;
    ArrayProcessing::moda<int>(array1, g_arraySize, moda, moda_count);
    cout << "Чаще всего встречается элемент: " << moda << ", а именно " << moda_count << " раз.\n";

    delete[] array1;
    delete[] array;

    return 0;
}
