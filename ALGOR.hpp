/* **************************************************************************** *
 * ---------------------------------------------------------------------------- *
 *                                                                              *
 * Copyright © 2021 Kalynovsky Valentin. All rights reserved.                   *
 *                                                                              *
 * Licensed under the Apache License, Version 2.0 (the "License");              *
 * you may not use this file except in compliance with the License.             *
 * You may obtain a copy of the License at                                      *
 *                                                                              *
 *     http://www.apache.org/licenses/LICENSE-2.0                               *
 *                                                                              *
 * Unless required by applicable law or agreed to in writing, software          *
 * distributed under the License is distributed on an "AS IS" BASIS,            *
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.     *
 * See the License for the specific language governing permissions and          *
 * limitations under the License.                                               *
 *                                                                              *
 * ---------------------------------------------------------------------------- *
 * **************************************************************************** *
 * ---------------------------------------------------------------------------- *
 *                              Version: 2.0.0-dev                              *
 * ---------------------------------------------------------------------------- *
 * **************************************************************************** *
 * ---------------------------------------------------------------------------- *
 *                                                                              *
 *                              Структура проекта:                              *
 * 1. ALGOR_CORE - основные структуры и функции библиотеки                      *
 * 2. ALGOR_RANDOM - собственный генератор случайных чисел                      *
 * 3. AlGOR_ARRAY - набор функций для работы с массивами                        *
 * 4. AlGOR_SORTING - Набор методов сортировок                                  *
 * 5. AlGOR_HEAP - набор функций для работы с деревьями                         *
 * 6. AlGOR_LIST - набор функций для работы со списками                         *
 *                                                                              *
 * ---------------------------------------------------------------------------- *
 * **************************************************************************** */

#ifndef ALGOR_HPP
#define ALGOR_HPP

#include "ALGOR_global.h"

//#include <iostream> //Иногда используется для тестов
#include <ctime>  //Будет убран после написания рандомизатора
#include <random> //Будет убран после написания рандомизатора
//using namespace std;

//ALGOR_CORE

template <typename type_array> void swap(type_array &firstNumber, type_array &secondNumber);
template <typename type_array> type_array minimum(const type_array *Array, const int &array_size);
template <typename type_array> type_array maximum(const type_array *Array, const int &array_size);
template <typename type_array> void addElement(const type_array *Array, const int &array_size, const type_array &value);
template <typename type_array> void copy(type_array *new_array, const type_array *old_array, const int &size_of_copied, int position_in_new_array = 0, int position_in_old_array = 0);

template <typename type_array> struct Array
{
    type_array *array;
    int array_size;
};
template <typename type_array> void remove_struct(Array<type_array> *&Array);

template <typename type_array> class ArrayData
{
public:
    ArrayData(Array<type_array> *&Array) : ARRAY(Array) {};
    ArrayData() {};
protected:
    Array<type_array> *ARRAY;
};

//ALGOR_RANDOM

//class Randomizer
//{
//public:
//};

//ALGOR_ARRAY

enum ArrayStatus { SORTED, UNSORTED };
enum ArrayType { NUMBER, STRING };

template<typename type_array> class ArrayProcessing : public ArrayData<type_array>
{
public:
    ArrayProcessing(Array<type_array> *&Array);
    ArrayProcessing();
    void createdStruct(const int &SIZE);
    void generatedArray(const int &min_limit, const int &max_limit);
    type_array getMin(ArrayStatus ArrStat = UNSORTED);
    type_array getMax(ArrayStatus ArrStat = UNSORTED);
    void getData(Array<type_array> *&DATA);
    Array<type_array> *getData();
    void lenear_searcher(const type_array &required_element, Array<int> *&NumberPoints);
    void binary_searcher(const type_array &required_element, int &number_point);
    void searcherOccurrencesOfSubstring(Array<type_array> *&SUBARRAY, Array<int> *&Occurrences, ArrayType ArrType = NUMBER);
    void reverse();
    void resize(const int &NEW_SIZE, const type_array &setElement);
    void average(type_array &average);
    void mediana(type_array &mediana);
    void moda(type_array &most_frequent, int &highest_frequency);
    void modas(Array<type_array> *&MostFrequents, int &highest_frequency);
    void remove();
private:
    void binary_searcher(const type_array &required_element, int &number_point, int left_limit, int right_limit);
};

//ALGOR_SORTING

namespace Exchange_Sorts
{
    template <typename type_array> class BubbleSort : public ArrayData<type_array>
    {
    public:
        BubbleSort(Array<type_array> *&Array) : ArrayData<type_array>(Array) {};
        void start_sort();
    };

    template <typename type_array> class CocktailShakerSort : public ArrayData<type_array>
    {
    public:
        CocktailShakerSort(Array<type_array> *&Array) : ArrayData<type_array>(Array) {};
        void start_sort();
    };

    //class OddevenSort{};

    //class CombSort{};

    //class GnomeSort{};

    template <typename type_array> class QuickSort : public ArrayData<type_array>
    {
    public:
        QuickSort(Array<type_array> *&Array) : ArrayData<type_array>(Array) {};
        void start_sort();
    private:
        void quick_sort(const int &left_limit, const int &right_limit);
    };

    namespace Ineffective_Sorts
    {
        //class StoogeSort{};

        //class BogoSort{};
    }
}

namespace Selection_Sorts
{
    //class SelectionSort{};

    template <typename type_array> class HeapSort : public ArrayData<type_array>
    {
    public:
        HeapSort(Array<type_array> *&Array) : ArrayData<type_array>(Array) {};
        void start_sort();
    private:
        void heapify(type_array *Array, const int &count, const int &array_size);
    };

    //class SmoothSort{};
}

namespace Insertion_Sorts
{
    template <typename type_array> class InsertSort : public ArrayData<type_array>
    {
    public:
        InsertSort(Array<type_array> *&Array) : ArrayData<type_array>(Array) {};
        void start_sort();
    };

    //class ShellSort{};

    //class LibrarySort{};

    //class PatienceSort{};

    //class TreeSort{};

    //class CycleSort{};
}

namespace Merge_Sorts
{
    template <typename type_array> class MergeSort : public ArrayData<type_array>
    {
    public:
        MergeSort(Array<type_array> *&Array) : ArrayData<type_array>(Array) {};
        void start_sort();
    private:
        void merge_sort(type_array *Array, const int &left_limit, const int &right_limit);
        void merge(type_array *Array, const int &left_limit, const int &middle_limit, const int &right_limit);
    };

    //class SlowSort{};

    //class StrandSort{};
}

namespace Noncomparison_Sort
{
    class CountingSort : public ArrayData<int>
    {
    public:
        CountingSort(Array<int> *&Array) : ArrayData<int>(Array) {};
        void start_sort();
    };

    //class BucketSort{};

    class RadixSort : public ArrayData<int>
    {
    public:
        RadixSort(Array<int> *&Array) : ArrayData<int>(Array) {};
        void start_sort();
    };

    //class PigeonholeSort{};

    //class BurstSort{};

    //class BeadSort{};

    //class PostmanSort{};
}

namespace Hybrid_Sorts
{
    //class TimSort{};

    //class BlockSort{};

    //class IntroSort{};

    //class SpreadSort{};
}

namespace Other_Sorts
{
    //class TopologicalSort{};

    //class BitonicSorter{};

    //class FlashSort{};

    //class PancakeSort{};

    //class SpaghettiSort{};
}

namespace Unknown_Sorts
{
    //class SampleSort{};
}

//ALGOR_HEAP

//ALGOR_LIST

#endif //ALGOR_HPP
