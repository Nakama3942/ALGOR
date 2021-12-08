#include <iostream>
using namespace std;

#include "sortingalgorithms.hpp"

Array<int> *Massiv = new Array<int>;       //Сгенериррованный массив
Array<int> *Massiv1 = new Array<int>;      //Скопированный массив
Array<int> *Sequence = new Array<int>;     //Подмассив для поиска
Array<int> *Occurrence = new Array<int>;   //Найденные вхождения подстроки
Array<int> *NumberPoints = new Array<int>; //Найденные вхождения указанного элемента
Array<int> *Modas = new Array<int>;        //Найденные вхождения моды
Array<int> *Extended = new Array<int>;     //Провенрка оператора ББ

//Вывод на экран массива
template <typename type_array>
void print(const char *representing_string, Array<type_array> *&ARRAY)
{
    cout << representing_string << "\n";
    for (int i = 0; i < ARRAY->array_size; i++)
    {
        cout << i + 1 << "->" << ARRAY->array[i] << "\t";
        //cout << ARRAY->array[i] << "\t";
    }
    cout << "\n";
}

//Генерация (заполнение) массива
void generator()
{
    ArrayProcessing::createdStruct(Massiv, 64);
    ArrayProcessing::generatedArray<int>(Massiv, 1, 50);
}

//Копирование массива
void copier()
{
    ArrayProcessing::createdStruct(Massiv1, 64);
    ArrayProcessing::copy<int>(Massiv1->array, Massiv->array, Massiv1->array_size);
}

//Сортировка массива
void sorter()
{
    //Exchange_Sorts::BubbleSort<int>::bubble_sort(Massiv1->array, Massiv1->array_size);
    //Exchange_Sorts::CocktailShakerSort<int>::cocktail_shaker_sort(Massiv1->array, Massiv1->array_size);
    //Exchange_Sorts::QuickSort<int>::quick_sort(Massiv1->array, 0, Massiv1->array_size - 1);
    //Selection_Sorts::HeapSort<int>::heap_sort(Massiv1->array, Massiv1->array_size);
    //Insertion_Sorts::InsertSort<int>::insert_sort(Massiv1->array, Massiv1->array_size);
    //Merge_Sorts::MergeSort<int>::merge_sort(Massiv1->array, 0, Massiv1->array_size - 1);
    Noncomparison_Sort::CountingSort::counting_sort(Massiv1->array, Massiv1->array_size);
    //Noncomparison_Sort::RadixSort::radix_sort(Massiv1->array, Massiv1->array_size);
}

//Нахождение максимального и минимального элемента
void search_minmax()
{
    int min, max;
    ArrayProcessing::getMin<int>(Massiv1->array, Massiv1->array_size, min, ArrayProcessing::SORTED);
    ArrayProcessing::getMax<int>(Massiv1->array, Massiv1->array_size, max, ArrayProcessing::SORTED);
    cout << "Минимальный элемент: " << min << "; Максимальный: " << max << "\n";
}

//Нахождение последовательности
void search_occurrence()
{
    ArrayProcessing::createdStruct<int>(Sequence, 0);
    ArrayProcessing::addElement<int>(Sequence, 20);
    ArrayProcessing::addElement<int>(Sequence, 21);
    try
    {
        ArrayProcessing::getOccurrencesOfSubstring<int>(Massiv1, Sequence, Occurrence);
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
}

//Нахождение определённого элемента в неотсортированном массиве
void search_numberpoints_lenear()
{
    try
    {
        ArrayProcessing::getElementsNumber_lenear<int>(Massiv, 20, NumberPoints);
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
}

//Нахождение определённого элемента в отсортированном массиве
void search_numberpoint_binary()
{
    int number_point;
    try
    {
        ArrayProcessing::getElementNumber_binary<int>(Massiv1->array, 0, Massiv1->array_size - 1, 23, number_point);
        cout << "Элемент \"23\" впервые встратился на месте " << number_point + 1 << "\n";
    }
    catch (int)
    {
        cout << "Элемент \"23\" не найден...\n";
    }
}

//Нахождение среднего арифметического
void search_average()
{
    int average;
    ArrayProcessing::average<int>(Massiv1, average);
    cout << "Среднее арифметическое: " << average << "\n";
}

//Нахождение медианы
void search_mediana()
{
    int mediana;
    ArrayProcessing::mediana<int>(Massiv1, mediana);
    cout << "Медиана: " << mediana << "\n";
}

//Нахождение моды с количеством
void search_moda()
{
    int moda, moda_count;
    ArrayProcessing::moda<int>(Massiv1, moda, moda_count);
    cout << "Чаще всего встречается элемент: " << moda << ", а именно " << moda_count << " раз.\n";
}

//Нахождение мод с количеством
void search_modas()
{
    int modas_count;
    ArrayProcessing::modas<int>(Massiv1, Modas, modas_count);
    cout << "Чаще всего встречаются элементы: ";
    for (int i = 0; i < Modas->array_size; i++)
    {
        cout << Modas->array[i] << " ";
    }
    cout << ", а именно " << modas_count << " раз.\n";
}

int main()
{
    generator();
    print<int>("Сгенерированный массив: ", Massiv);
    copier();
    sorter();
    print<int>("Отсортированный массив: ", Massiv1);
    search_minmax();
    search_occurrence();
    search_numberpoints_lenear();
    search_numberpoint_binary();
    search_average();
    search_mediana();
    search_moda();
    search_modas();

    delete (Modas);
    delete (NumberPoints);
    delete (Occurrence);
    delete (Sequence);
    delete (Massiv1);
    delete (Massiv);

    return 0;
}
