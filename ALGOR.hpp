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
using namespace std;

//ALGOR_CORE

template <typename type_array>
struct Array
{
    type_array *array;
    int array_size;
};

//ALGOR_RANDOM

//class Randomizer
//{
//public:
//};

//ALGOR_ARRAY

namespace ArrayProcessing
{
enum ArrayStatus { SORTED, UNSORTED };
enum ArrayType { NUMBER, STRING };
template <typename type_array> void createdStruct(Array<type_array> *&ARRAY, const int &SIZE);
template <typename type_array> void generatedArray(Array<type_array> *&ARRAY, const int &min_limit, const int &max_limit);
template <typename type_array> void swap(type_array &firstNumber, type_array &secondNumber);
template <typename type_array> void getMin(const type_array *Array, const int &array_size, type_array &point_min, ArrayStatus ArrStat = UNSORTED);
template <typename type_array> void getMax(const type_array *Array, const int &array_size, type_array &point_max, ArrayStatus ArrStat = UNSORTED);
template <typename type_array> void getElementsNumber_lenear(Array<type_array> *&ARRAY, const type_array &required_element, Array<int> *&NumberPoints);
template <typename type_array> void getElementNumber_binary(Array<type_array> *&ARRAY, const type_array &required_element, int &number_point);
template <typename type_array> void getElementNumber_binary(Array<type_array> *&ARRAY, const type_array &required_element, int &number_point, int left_limit, int right_limit);
template <typename type_array> void getOccurrencesOfSubstring(Array<type_array> *&ARRAY, Array<type_array> *&SUBARRAY, Array<int> *&Occurrences, ArrayType ArrType = NUMBER);
template <typename type_array> void addElement(Array<type_array> *&ARRAY, const type_array &value);
template <typename type_array> void reverse(Array<type_array> *&ARRAY);
//template <typename type_array> void resize(Array<type_array> *&ARRAY);
template <typename type_array> void copy(type_array *new_array, const type_array *old_array, const int &size_of_copied, int position_in_new_array = 0, int position_in_old_array = 0);
}

namespace ArrayCharacteristic
{
template <typename type_array> void average(Array<type_array> *&ARRAY, type_array &average);
template <typename type_array> void mediana(Array<type_array> *&ARRAY, type_array &mediana);
template <typename type_array> void moda(Array<type_array> *&ARRAY, type_array &most_frequent, int &highest_frequency);
template <typename type_array> void modas(Array<type_array> *&ARRAY, Array<type_array> *&MostFrequents, int &highest_frequency);
}

//ALGOR_SORTING

namespace Exchange_Sorts
{
    template <typename type_array> class BubbleSort
    {
    public:
        BubbleSort(Array<type_array> *&Array);
        void start_sort();
    private:
        Array<type_array> *ARRAY;
    };

    template <typename type_array> class CocktailShakerSort
    {
    public:
        CocktailShakerSort(Array<type_array> *&Array);
        void start_sort();
    private:
        Array<type_array> *ARRAY;
    };

    //class OddevenSort{};

    //class CombSort{};

    //class GnomeSort{};

    template <typename type_array> class QuickSort
    {
    public:
        QuickSort(Array<type_array> *&Array);
        void start_sort();
    private:
        Array<type_array> *ARRAY;
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

    template <typename type_array> class HeapSort
    {
    public:
        HeapSort(Array<type_array> *&Array);
        void start_sort();
    private:
        Array<type_array> *ARRAY;
        void heapify(type_array *Array, const int &count, const int &array_size);
    };

    //class SmoothSort{};
}

namespace Insertion_Sorts
{
    template <typename type_array> class InsertSort
    {
    public:
        InsertSort(Array<type_array> *&Array);
        void start_sort();
    private:
        Array<type_array> *ARRAY;
    };

    //class ShellSort{};

    //class LibrarySort{};

    //class PatienceSort{};

    //class TreeSort{};

    //class CycleSort{};
}

namespace Merge_Sorts
{
    template <typename type_array> class MergeSort
    {
    public:
        MergeSort(Array<type_array> *&Array);
        void start_sort();
    private:
        Array<type_array> *ARRAY;
        void merge_sort(type_array *Array, const int &left_limit, const int &right_limit);
        void merge(type_array *Array, const int &left_limit, const int &middle_limit, const int &right_limit);
    };

    //class SlowSort{};

    //class StrandSort{};
}

namespace Noncomparison_Sort
{
    class CountingSort
    {
    public:
        CountingSort(Array<int> *&Array);
        void start_sort();
    private:
        Array<int> *ARRAY;
    };

    //class BucketSort{};

    class RadixSort
    {
    public:
        RadixSort(Array<int> *&Array);
        void start_sort();
    private:
        Array<int> *ARRAY;
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
