#include <iostream>
using namespace std;

#include "ALGOR.hpp"

int main()
{
    cout << "Hello World!" << endl;

    //Генерация (заполнение) массива
    Array<int> *GenArray = new Array<int>;
    ArrayProcessing::createdStruct<int>(GenArray, 64);
    ArrayProcessing::generatedArray<int>(GenArray, 1, 50);

    //Вывод на экран сгенерированного массива
    for (int i = 0; i < 64; i++)
    {
        cout << " " << GenArray->array[i];
    }
    cout << "\n";

    //Копирование массива
    Array<int> *SortArray = new Array<int>;
    ArrayProcessing::createdStruct<int>(SortArray, 64);
    ArrayProcessing::copy<int>(SortArray->array, GenArray->array, SortArray->array_size);

    //Сортировка массива
    //Exchange_Sorts::BubbleSort<int> *sort = new Exchange_Sorts::BubbleSort<int>(SortArray);
    //Exchange_Sorts::CocktailShakerSort<int> *sort = new Exchange_Sorts::CocktailShakerSort<int>(SortArray);
    //Exchange_Sorts::QuickSort<int> *sort = new Exchange_Sorts::QuickSort<int>(SortArray);
    //Selection_Sorts::HeapSort<int> *sort = new Selection_Sorts::HeapSort<int>(SortArray);
    //Insertion_Sorts::InsertSort<int> *sort = new Insertion_Sorts::InsertSort<int>(SortArray);
    //Merge_Sorts::MergeSort<int> *sort = new Merge_Sorts::MergeSort<int>(SortArray);
    Noncomparison_Sort::CountingSort *sort = new Noncomparison_Sort::CountingSort(SortArray);
    //Noncomparison_Sort::RadixSort *sort = new Noncomparison_Sort::RadixSort(SortArray);
    sort->start_sort();
    delete (sort);

    //Вывод на экран отсортированного массива
    for (int i = 0; i < 64; i++)
    {
        cout << " " << SortArray->array[i];
    }
    cout << "\n";

    //Нахождение максимального и минимального элемента
    int min, max;
    ArrayProcessing::getMin<int>(GenArray->array, GenArray->array_size, min);
    ArrayProcessing::getMax<int>(SortArray->array, SortArray->array_size, max, ArrayProcessing::SORTED);
    cout << "Минимальный элемент: " << min << "; Максимальный: " << max << "\n";

    //Нахождение последовательности
    Array<int> *Sequence = new Array<int>;
    Array<int> *Occurrence = new Array<int>;
    ArrayProcessing::createdStruct<int>(Sequence, 0);
    ArrayProcessing::addElement<int>(Sequence, 20);
    ArrayProcessing::addElement<int>(Sequence, 21);
    try
    {
        ArrayProcessing::getOccurrencesOfSubstring<int>(SortArray, Sequence, Occurrence);
        cout << "Последовательность \"20, 21\" встречается на местах: \n";
        for (int i = 0; i < Occurrence->array_size; i++)
        {
            cout << Occurrence->array[i] + 1 << " ";
        }
        cout << "\n";
    }
    catch (int)
    {
        cout << "Последовательность \"20, 21\" не найдена...\n";
    }
    delete[] Occurrence->array;
    delete (Occurrence);
    delete[] Sequence->array;
    delete (Sequence);

    //Нахождение определённого элемента в неотсортированном массиве
    Array<int> *NumberPoints = new Array<int>;
    try
    {
        ArrayProcessing::getElementsNumber_lenear<int>(GenArray, 20, NumberPoints);
        cout << "Элемент \"20\" встречается на местах: \n";
        for (int i = 0; i < NumberPoints->array_size; i++)
        {
            cout << NumberPoints->array[i] + 1 << " ";
        }
        cout << "\n";
    }
    catch (int)
    {
        cout << "Элемент \"20\" не найден...\n";
    }
    delete[] NumberPoints->array;
    delete (NumberPoints);

    //Нахождение определённого элемента в отсортированном массиве
    int number_point;
    try
    {
        ArrayProcessing::getElementNumber_binary<int>(SortArray, 23, number_point);
        cout << "Элемент \"23\" впервые встратился на месте " << number_point + 1 << "\n";
    }
    catch (int)
    {
        cout << "Элемент \"23\" не найден...\n";
    }

    //Нахождение среднего арифметического
    int average;
    ArrayCharacteristic::average<int>(SortArray, average);
    cout << "Среднее арифметическое: " << average << "\n";

    //Нахождение медианы
    int mediana;
    ArrayCharacteristic::mediana<int>(SortArray, mediana);
    cout << "Медиана: " << mediana << "\n";

    //Нахождение моды с количеством
    int moda, moda_count;
    ArrayCharacteristic::moda<int>(SortArray, moda, moda_count);
    cout << "Чаще всего встречается элемент: " << moda << ", а именно " << moda_count << " раз.\n";

    //Нахождение мод с количеством
    Array<int> *Modas = new Array<int>;
    int modas_count;
    ArrayCharacteristic::modas<int>(SortArray, Modas, modas_count);
    cout << "Чаще всего встречаются элементы: ";
    for (int i = 0; i < Modas->array_size; i++)
    {
        cout << Modas->array[i] << " ";
    }
    cout << ", а именно " << modas_count << " раз.\n";
    delete[] Modas->array;
    delete (Modas);

    //Освобождение памяти
    delete[] SortArray->array;
    delete (SortArray);
    delete[] GenArray->array;
    delete (GenArray);

    //Выход из программы
    //cin.get();
    //cin.get();
    return 0;
}
