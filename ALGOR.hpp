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
template <typename type_array> type_array minimum(const type_array *Array, const unsigned int &array_size);
template <typename type_array> type_array maximum(const type_array *Array, const unsigned int &array_size);
//Улучшить addElement()
template <typename type_array> void addElement(type_array *&Array, unsigned int &array_size, const type_array &value);
//replaceElement()
//subtractElement()
template <typename type_array> void copy(type_array *new_array, const type_array *old_array, const unsigned int &size_of_copied, unsigned int position_in_new_array = 0, unsigned int position_in_old_array = 0);

template <typename type_array> struct Array { type_array *array; unsigned int array_size = 0; };
template <typename type_array> Array<type_array> *create_struct(const unsigned int &SIZE);
template <typename type_array> void remove_struct(Array<type_array> *&Array);

template <typename type_array> class ArrayBase
{
public:
    ArrayBase(Array<type_array> *&Array) : ARRAY(Array) {};
    ArrayBase(const unsigned int &SIZE) { ARRAY = create_struct<type_array>(SIZE); };
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

template<typename type_array> class ARRAYDATA : public ArrayBase<type_array>
{
public:
    ARRAYDATA(Array<type_array> *&Array) : ArrayBase<type_array>(Array) {}
    ARRAYDATA(const unsigned int &SIZE) : ArrayBase<type_array>(SIZE) {}
    void generatedData(const int &min_limit, const int &max_limit);
    void setNewData(Array<type_array> *&Array);
    void setData(Array<type_array> *&Array);
    void getData(Array<type_array> *&DATA);
    Array<type_array> *getData();
    void reset();
    void resize(const unsigned int &NEW_SIZE, const type_array &setElement);
    void reverse();
    void remove();
    type_array getMin(ArrayStatus ArrStat = UNSORTED);
    type_array getMax(ArrayStatus ArrStat = UNSORTED);
    Array<int> *lenear_searcher(const type_array &required_element);
    int binary_searcher(const type_array &required_element);
    Array<int> *searcherOccurrencesOfSubstring(Array<type_array> *&SUBARRAY, ArrayType ArrType = NUMBER);
    type_array average();
    type_array mediana();
    type_array moda(int &highest_frequency);
    Array<type_array> *modas(int &highest_frequency);
    //оператор < для добавления в конец массива
    //оператор > для удаления из конца массива

    //оператор & для слияния двух массивов
    //оператор % для влияния массива в массив
    //    ARRAYDATA<type_array> operator& (const ARRAYDATA<type_array> *&addArray)
    //    {
    //        Array<type_array> *temp = create_struct<type_array>(this->ARRAY->array_size + addArray->ARRAY->array_size);
    //        copy<type_array>(temp->array, this->ARRAY->array, this->ARRAY->array_size);
    //        copy<type_array>(temp->array, addArray->ARRAY->array, addArray->ARRAY->array_size, this->ARRAY->array_size);
    //        ARRAYDATA<type_array> *tempArrayData = new ARRAYDATA<type_array>(temp);
    //        return tempArrayData;
    //    }

    //оператор + для увеличения массива на конкретный размер
    //оператор - для уменьшения массива на конкретный размер
    void operator+ (const unsigned int &addSize)
    {
        Array<type_array> *temp = create_struct<type_array>(this->ARRAY->array_size);
        copy<type_array>(temp->array, this->ARRAY->array, this->ARRAY->array_size);
        remove();
        this->ARRAY = create_struct<type_array>(temp->array_size + addSize);
        copy<type_array>(this->ARRAY->array, temp->array, temp->array_size);
        remove_struct<type_array>(temp);
    }
    void operator- (const unsigned int &subtractSize)
    {
        if (subtractSize >= this->ARRAY->array_size)
        {
            remove();
            return;
        }
        Array<type_array> *temp = create_struct<type_array>(this->ARRAY->array_size);
        copy<type_array>(temp->array, this->ARRAY->array, this->ARRAY->array_size);
        remove();
        this->ARRAY = create_struct<type_array>(temp->array_size - subtractSize);
        copy<type_array>(this->ARRAY->array, temp->array, this->ARRAY->array_size);
        remove_struct<type_array>(temp);
    }

    //оператор * для увеличения массива во сколько-то раз
    //оператор / для уменьшения массива во сколько-то раз
private:
    void binary_searcher(const type_array &required_element, int &number_point, int left_limit, int right_limit);
};

//ALGOR_SORTING

namespace Exchange_Sorts
{
    template <typename type_array> class BubbleSort : public ArrayBase<type_array>
    {
    public:
        BubbleSort(Array<type_array> *&Array) : ArrayBase<type_array>(Array) {};
        void start_sort();
    };

    template <typename type_array> class CocktailShakerSort : public ArrayBase<type_array>
    {
    public:
        CocktailShakerSort(Array<type_array> *&Array) : ArrayBase<type_array>(Array) {};
        void start_sort();
    };

    //class OddevenSort{};

    //class CombSort{};

    //class GnomeSort{};

    template <typename type_array> class QuickSort : public ArrayBase<type_array>
    {
    public:
        QuickSort(Array<type_array> *&Array) : ArrayBase<type_array>(Array) {};
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

    template <typename type_array> class HeapSort : public ArrayBase<type_array>
    {
    public:
        HeapSort(Array<type_array> *&Array) : ArrayBase<type_array>(Array) {};
        void start_sort();
    private:
        void heapify(type_array *Array, const int &count, const int &array_size);
    };

    //class SmoothSort{};
}

namespace Insertion_Sorts
{
    template <typename type_array> class InsertSort : public ArrayBase<type_array>
    {
    public:
        InsertSort(Array<type_array> *&Array) : ArrayBase<type_array>(Array) {};
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
    template <typename type_array> class MergeSort : public ArrayBase<type_array>
    {
    public:
        MergeSort(Array<type_array> *&Array) : ArrayBase<type_array>(Array) {};
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
    class CountingSort : public ArrayBase<int>
    {
    public:
        CountingSort(Array<int> *&Array) : ArrayBase<int>(Array) {};
        void start_sort();
    };

    //class BucketSort{};

    class RadixSort : public ArrayBase<int>
    {
    public:
        RadixSort(Array<int> *&Array) : ArrayBase<int>(Array) {};
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
