#include <iostream>
using namespace std;

#include "sortingalgorithms.hpp"

//const int g_arraySize = 1024;
//const int g_arraySize = 64;

template <typename type_array>
void print(const char *representing_string, type_array *Array, int array_size)
{
    cout << representing_string << "\n";
    for (int i = 0; i < array_size; i++)
    {
        cout << i + 1 << "->" << Array[i] << "\t";
    }
    cout << "\n";
}

int main()
{
    //Генерирую (заполняю) массив
    Arr<int> *Array = new Arr<int>;
    ArrayProcessing::generatedStruct(Array, 64);
    ArrayProcessing::generatedArray<int>(Array->array, Array->array_size, 1, 50);

    //Вывожу на экран массив
    print<int>("Сгенерированный массив: ", Array->array, Array->array_size);

    //Копирую массив
    Arr<int> *Array1 = new Arr<int>;
    ArrayProcessing::generatedStruct(Array1, 64);
    ArrayProcessing::copy<int>(Array1->array, Array->array, Array1->array_size);

    //Сортирую массив
    //Exchange_Sorts::BubbleSort<int>::bubble_sort(array1, g_arraySize);
    //Exchange_Sorts::CocktailShakerSort<int>::cocktail_shaker_sort(array1, g_arraySize);
    //Exchange_Sorts::QuickSort<int>::quick_sort(array1, 0, g_arraySize - 1);
    //Selection_Sorts::HeapSort<int>::heap_sort(array1, g_arraySize);
    //Insertion_Sorts::InsertSort<int>::insert_sort(array1, g_arraySize);
    //Merge_Sorts::MergeSort<int>::merge_sort(array1, 0, g_arraySize - 1);
    Noncomparison_Sort::CountingSort::counting_sort(Array1->array, Array1->array_size);
    //Noncomparison_Sort::RadixSort::radix_sort(array1, g_arraySize);

    //Вывожу на экран массив
    print<int>("Отсортированный массив: ", Array1->array, Array1->array_size);

    //Нахожу максимальный и минимальный элемент
    int min, max;
    ArrayProcessing::getMin<int>(Array1->array, Array1->array_size, min, ArrayProcessing::SORTED);
    ArrayProcessing::getMax<int>(Array1->array, Array1->array_size, max, ArrayProcessing::SORTED);
    cout << "Минимальный элемент: " << min << "; Максимальный: " << max << "\n";

    //Нахожу последовательность
    int sequence[2] = {20, 21}, *occurrence, occurrence_size;
    try
    {
        ArrayProcessing::getOccurrencesOfSubstring<int>(Array1->array, Array1->array_size, sequence, 2, occurrence, occurrence_size);
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
        ArrayProcessing::getElementsNumber_lenear<int>(Array1->array, Array1->array_size, 20, number_points, number_points_size);
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
        ArrayProcessing::getElementNumber_binary<int>(Array1->array, 0, Array1->array_size - 1, 23, number_point);
        cout << "Элемент \"23\" впервые встратился на месте " << number_point + 1 << "\n";
    }
    catch (int)
    {
        cout << "Элемент \"23\" не найден...\n";
    }

    //Нахожу среднее арифметическое
    int average;
    ArrayProcessing::average<int>(Array1->array, Array1->array_size, average);
    cout << "Среднее арифметическое: " << average << "\n";

    //Нахожу медиану
    int mediana;
    ArrayProcessing::mediana<int>(Array1->array, Array1->array_size, mediana);
    cout << "Медиана: " << mediana << "\n";

    //Нахожу моду с количеством
    int moda, moda_count;
    ArrayProcessing::moda<int>(Array1->array, Array1->array_size, moda, moda_count);
    cout << "Чаще всего встречается элемент: " << moda << ", а именно " << moda_count << " раз.\n";

    //Нахожу моды с количеством
    int *modas, modas_size, modas_count;
    ArrayProcessing::modas<int>(Array1->array, Array1->array_size, modas, modas_size, modas_count);
    cout << "Чаще всего встречаются элементы: ";
    for (int i = 0; i < modas_size; i++)
    {
        cout << modas[i] << " ";
    }
    cout << ", а именно " << modas_count << " раз.\n";

    delete (Array);
    delete (Array1);

    return 0;
}
