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
 * **************************************************************************** */

#include "ALGOR.hpp"

template<typename type_array>
Exchange_Sorts::BubbleSort<type_array>::BubbleSort(Array<type_array> *&Array)
{
    ARRAY = Array;
}
template Exchange_Sorts::BubbleSort<int>::BubbleSort(Array<int> *&);
template Exchange_Sorts::BubbleSort<float>::BubbleSort(Array<float> *&);
template Exchange_Sorts::BubbleSort<char>::BubbleSort(Array<char> *&);

template<typename type_array>
void Exchange_Sorts::BubbleSort<type_array>::start_sort()
{
    for (int i = 0; i < ARRAY->array_size; i++)
    {
        for (int j = 0; j < ARRAY->array_size - 1; j++)
        {
            if (ARRAY->array[j] > ARRAY->array[j + 1])
            {
                ArrayProcessing::swap<type_array>(ARRAY->array[j], ARRAY->array[j + 1]);
            }
        }
    }
}
template void Exchange_Sorts::BubbleSort<int>::start_sort();
template void Exchange_Sorts::BubbleSort<float>::start_sort();
template void Exchange_Sorts::BubbleSort<char>::start_sort();

template<typename type_array>
Exchange_Sorts::CocktailShakerSort<type_array>::CocktailShakerSort(Array<type_array> *&Array)
{
    ARRAY = Array;
}
template Exchange_Sorts::CocktailShakerSort<int>::CocktailShakerSort(Array<int> *&);
template Exchange_Sorts::CocktailShakerSort<float>::CocktailShakerSort(Array<float> *&);
template Exchange_Sorts::CocktailShakerSort<char>::CocktailShakerSort(Array<char> *&);

template<typename type_array>
void Exchange_Sorts::CocktailShakerSort<type_array>::start_sort()
{
    int leftMark = 1, rightMark = ARRAY->array_size - 1;
    while (leftMark <= rightMark)
    {
        for (int i = rightMark; i >= leftMark; i--)
        {
            if (ARRAY->array[i - 1] > ARRAY->array[i])
            {
                ArrayProcessing::swap<type_array>(ARRAY->array[i], ARRAY->array[i - 1]);
            }
        }
        leftMark++;
        for (int i = leftMark; i <= rightMark; i++)
        {
            if (ARRAY->array[i - 1] > ARRAY->array[i])
            {
                ArrayProcessing::swap<type_array>(ARRAY->array[i], ARRAY->array[i - 1]);
            }
        }
        rightMark--;
    }
}
template void Exchange_Sorts::CocktailShakerSort<int>::start_sort();
template void Exchange_Sorts::CocktailShakerSort<float>::start_sort();
template void Exchange_Sorts::CocktailShakerSort<char>::start_sort();

template<typename type_array>
Exchange_Sorts::QuickSort<type_array>::QuickSort(Array<type_array> *&Array)
{
    ARRAY = Array;
}
template Exchange_Sorts::QuickSort<int>::QuickSort(Array<int> *&);
template Exchange_Sorts::QuickSort<float>::QuickSort(Array<float> *&);
template Exchange_Sorts::QuickSort<char>::QuickSort(Array<char> *&);

template<typename type_array>
void Exchange_Sorts::QuickSort<type_array>::start_sort()
{
    quick_sort(0, ARRAY->array_size - 1);
}
template void Exchange_Sorts::QuickSort<int>::start_sort();
template void Exchange_Sorts::QuickSort<float>::start_sort();
template void Exchange_Sorts::QuickSort<char>::start_sort();

template<typename type_array>
void Exchange_Sorts::QuickSort<type_array>::quick_sort(const int &left_limit, const int &right_limit)
{
    type_array middle = ARRAY->array[(left_limit + right_limit) / 2];
    int start = left_limit, finish = right_limit;
    do
    {
        while (ARRAY->array[start] < middle)
        {
            start++;
        }
        while (ARRAY->array[finish] > middle)
        {
            finish--;
        }
        if (start <= finish)
        {
            ArrayProcessing::swap<type_array>(ARRAY->array[start], ARRAY->array[finish]);
            start++;
            finish--;
        }
    } while (start < finish);
    if (left_limit < finish)
    {
        quick_sort(left_limit, finish);
    }
    if (start < right_limit)
    {
        quick_sort(start, right_limit);
    }
}
template void Exchange_Sorts::QuickSort<int>::quick_sort(const int &, const int &);
template void Exchange_Sorts::QuickSort<float>::quick_sort(const int &, const int &);
template void Exchange_Sorts::QuickSort<char>::quick_sort(const int &, const int &);

template<typename type_array>
Selection_Sorts::HeapSort<type_array>::HeapSort(Array<type_array> *&Array)
{
    ARRAY = Array;
}
template Selection_Sorts::HeapSort<int>::HeapSort(Array<int> *&);
template Selection_Sorts::HeapSort<float>::HeapSort(Array<float> *&);
template Selection_Sorts::HeapSort<char>::HeapSort(Array<char> *&);

template<typename type_array>
void Selection_Sorts::HeapSort<type_array>::start_sort()
{
    for (int right = ARRAY->array_size / 2 - 1; right >= 0; right--)
    {
        heapify(ARRAY->array, right, ARRAY->array_size);
    }
    for (int i = ARRAY->array_size - 1; i >= 0; i--)
    {
        ArrayProcessing::swap<type_array>(ARRAY->array[0], ARRAY->array[i]);
        heapify(ARRAY->array, 0, i);
    }
}
template void Selection_Sorts::HeapSort<int>::start_sort();
template void Selection_Sorts::HeapSort<float>::start_sort();
template void Selection_Sorts::HeapSort<char>::start_sort();

template<typename type_array>
void Selection_Sorts::HeapSort<type_array>::heapify(type_array *Array, const int &count, const int &array_size)
{
    int left = 2 * count + 1, large = count, right = 2 * count + 2;
    if (left < array_size && Array[left] > Array[large])
    {
        large = left;
    }
    if (right < array_size && Array[right] > Array[large])
    {
        large = right;
    }
    if (large != count)
    {
        ArrayProcessing::swap<type_array>(Array[count], Array[large]);
        heapify(Array, large, array_size);
    }
}
template void Selection_Sorts::HeapSort<int>::heapify(int *, const int &, const int &);
template void Selection_Sorts::HeapSort<float>::heapify(float *, const int &, const int &);
template void Selection_Sorts::HeapSort<char>::heapify(char *, const int &, const int &);

template<typename type_array>
Insertion_Sorts::InsertSort<type_array>::InsertSort(Array<type_array> *&Array)
{
    ARRAY = Array;
}
template Insertion_Sorts::InsertSort<int>::InsertSort(Array<int> *&);
template Insertion_Sorts::InsertSort<float>::InsertSort(Array<float> *&);
template Insertion_Sorts::InsertSort<char>::InsertSort(Array<char> *&);

template<typename type_array>
void Insertion_Sorts::InsertSort<type_array>::start_sort()
{
    for (int i = 0; i < ARRAY->array_size; i++)
    {
        for (int j = i; j > 0 && ARRAY->array[j - 1] > ARRAY->array[j]; j--)
        {
            ArrayProcessing::swap<type_array>(ARRAY->array[j - 1], ARRAY->array[j]);
        }
    }
}
template void Insertion_Sorts::InsertSort<int>::start_sort();
template void Insertion_Sorts::InsertSort<float>::start_sort();
template void Insertion_Sorts::InsertSort<char>::start_sort();

template<typename type_array>
Merge_Sorts::MergeSort<type_array>::MergeSort(Array<type_array> *&Array)
{
    ARRAY = Array;
}
template Merge_Sorts::MergeSort<int>::MergeSort(Array<int> *&);
template Merge_Sorts::MergeSort<float>::MergeSort(Array<float> *&);
template Merge_Sorts::MergeSort<char>::MergeSort(Array<char> *&);

template<typename type_array>
void Merge_Sorts::MergeSort<type_array>::start_sort()
{
    merge_sort(ARRAY->array, 0, ARRAY->array_size - 1);
}
template void Merge_Sorts::MergeSort<int>::start_sort();
template void Merge_Sorts::MergeSort<float>::start_sort();
template void Merge_Sorts::MergeSort<char>::start_sort();

template<typename type_array>
void Merge_Sorts::MergeSort<type_array>::merge_sort(type_array *Array, const int &left_limit, const int &right_limit)
{
    if (left_limit < right_limit)
    {
        int middle = left_limit + (right_limit - left_limit) / 2;
        merge_sort(Array, left_limit, middle);
        merge_sort(Array, middle + 1, right_limit);
        merge(Array, left_limit, middle, right_limit);
    }
}
template void Merge_Sorts::MergeSort<int>::merge_sort(int *, const int &, const int &);
template void Merge_Sorts::MergeSort<float>::merge_sort(float *, const int &, const int &);
template void Merge_Sorts::MergeSort<char>::merge_sort(char *, const int &, const int &);

template<typename type_array>
void Merge_Sorts::MergeSort<type_array>::merge(type_array *Array, const int &left_limit, const int &middle_limit, const int &right_limit)
{
    int start = left_limit, finish = middle_limit + 1;
    type_array *tempArray = new type_array[right_limit - left_limit + 1];
    for (int i = left_limit; i <= right_limit; i++)
    {
        if ((start <= middle_limit) && ((finish > right_limit) || (Array[start] < Array[finish])))
        {
            tempArray[i - left_limit] = Array[start];
            start++;
        }
        else
        {
            tempArray[i - left_limit] = Array[finish];
            finish++;
        }
    }
    for (int i = left_limit; i <= right_limit; i++)
    {
        Array[i] = tempArray[i - left_limit];
    }
    delete[] tempArray;
}
template void Merge_Sorts::MergeSort<int>::merge(int *, const int &, const int &, const int &);
template void Merge_Sorts::MergeSort<float>::merge(float *, const int &, const int &, const int &);
template void Merge_Sorts::MergeSort<char>::merge(char *, const int &, const int &, const int &);

Noncomparison_Sort::CountingSort::CountingSort(Array<int> *&Array)
{
    ARRAY = Array;
}

void Noncomparison_Sort::CountingSort::start_sort()
{
    int min, max;
    ArrayProcessing::getMin<int>(ARRAY->array, ARRAY->array_size, min);
    ArrayProcessing::getMax<int>(ARRAY->array, ARRAY->array_size, max);
    int *tempArray = new int[max - min + 1];
    for (int i = 0; i < max - min + 1; i++)
    {
        tempArray[i] = 0;
    }
    for (int i = 0; i < ARRAY->array_size; i++)
    {
        tempArray[ARRAY->array[i] - min] = tempArray[ARRAY->array[i] - min] + 1;
    }
    for (int i = 0, j = min; j < max + 1; j++)
    {
        while (tempArray[j - min] != 0)
        {
            ARRAY->array[i] = j;
            tempArray[j - min]--;
            i++;
        }
    }
    delete[] tempArray;
}

Noncomparison_Sort::RadixSort::RadixSort(Array<int> *&Array)
{
    ARRAY = Array;
}

void Noncomparison_Sort::RadixSort::start_sort()
{
    int exp = 1, bit = 10, max;
    ArrayProcessing::getMax<int>(ARRAY->array, ARRAY->array_size, max);
    int *tempArray = new int[ARRAY->array_size], *bucket = new int[bit];
    while (max / exp > 0)
    {
        for (int i = 0; i < bit; i++)
        {
            bucket[i] = 0;
        }
        for (int i = 0; i < ARRAY->array_size; i++)
        {
            bucket[(ARRAY->array[i] / exp) % bit]++;
        }
        for (int i = 1; i < bit; i++)
        {
            bucket[i] += bucket[i - 1];
        }
        for (int i = ARRAY->array_size - 1; i >= 0; i--)
        {
            int current = (ARRAY->array[i] % (exp * bit)) / exp;
            bucket[current]--;
            tempArray[bucket[current]] = ARRAY->array[i];
        }
        for (int i = 0; i < ARRAY->array_size; i++)
        {
            ARRAY->array[i] = tempArray[i];
        }
        exp *= bit;
    }
    delete[] bucket;
    delete[] tempArray;
}
