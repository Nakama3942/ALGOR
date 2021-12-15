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
void ArrayProcessing::createdStruct(Array<type_array> *&ARRAY, const int &SIZE)
{
    ARRAY->array_size = SIZE;
    ARRAY->array = new type_array[SIZE];
}
template void ArrayProcessing::createdStruct<int>(Array<int> *&, const int &);
template void ArrayProcessing::createdStruct<float>(Array<float> *&, const int &);
template void ArrayProcessing::createdStruct<char>(Array<char> *&, const int &);

template<typename type_array>
void ArrayProcessing::generatedArray(Array<type_array> *&ARRAY, const int &min_limit, const int &max_limit)
{
    srand(time(NULL));
    for (int i = 0; i < ARRAY->array_size; i++)
    {
        ARRAY->array[i] = min_limit + rand() % (max_limit - min_limit);
    }
}
template void ArrayProcessing::generatedArray<int>(Array<int> *&, const int &, const int &);
template void ArrayProcessing::generatedArray<float>(Array<float> *&, const int &, const int &);
template void ArrayProcessing::generatedArray<char>(Array<char> *&, const int &, const int &);

template<typename type_array>
void ArrayProcessing::swap(type_array &firstNumber, type_array &secondNumber)
{
    type_array *temp = new type_array(firstNumber);
    firstNumber = secondNumber;
    secondNumber = *temp;
    delete (temp);
}
template void ArrayProcessing::swap<int>(int &, int &);
template void ArrayProcessing::swap<float>(float &, float &);
template void ArrayProcessing::swap<char>(char &, char &);

template<typename type_array>
void ArrayProcessing::addElement(Array<type_array> *&ARRAY, const type_array &value)
{
    if (ARRAY->array_size == 0)
    {
        ARRAY->array_size++;
        ARRAY->array = new type_array[ARRAY->array_size]{value};
    }
    else
    {
        type_array *temp_Array = new type_array[ARRAY->array_size];
        copy<type_array>(temp_Array, ARRAY->array, ARRAY->array_size);
        delete[] ARRAY->array;
        int *limit = new int(ARRAY->array_size);
        ARRAY->array_size++;
        ARRAY->array = new type_array[ARRAY->array_size];
        copy<type_array>(ARRAY->array, temp_Array, *limit);
        ARRAY->array[*limit] = value;
        delete (limit);
        delete[] temp_Array;
    }
}
template void ArrayProcessing::addElement<int>(Array<int> *&, const int &);
template void ArrayProcessing::addElement<float>(Array<float> *&, const float &);
template void ArrayProcessing::addElement<char>(Array<char> *&, const char &);

template<typename type_array>
void ArrayProcessing::reverse(Array<type_array> *&ARRAY)
{
    int left_limit = 0, right_limit = ARRAY->array_size - 1;
    for (int i = 0; i < ARRAY->array_size / 2; i++)
    {
        swap<type_array>(ARRAY->array[left_limit], ARRAY->array[right_limit]);
        left_limit++;
        right_limit--;
    }
}
template void ArrayProcessing::reverse<int>(Array<int> *&);
template void ArrayProcessing::reverse<float>(Array<float> *&);
template void ArrayProcessing::reverse<char>(Array<char> *&);

template<typename type_array>
void ArrayProcessing::resize(Array<type_array> *&ARRAY, const int &NEW_SIZE, const type_array &setElement)
{
    Array<type_array> *OLD_ARRAY = ARRAY, *NEW_ARRAY = new Array<type_array>;
    createdStruct<type_array>(NEW_ARRAY, NEW_SIZE);
    if (OLD_ARRAY->array_size < NEW_ARRAY->array_size)
    {
        copy<type_array>(NEW_ARRAY->array, OLD_ARRAY->array, OLD_ARRAY->array_size);
        for(int i = OLD_ARRAY->array_size; i < NEW_ARRAY->array_size; i++)
        {
            NEW_ARRAY->array[i] = setElement;
        }
    }
    else
    {
        copy<type_array>(NEW_ARRAY->array, OLD_ARRAY->array, NEW_ARRAY->array_size);
    }
    ARRAY = NEW_ARRAY;
    delete[] OLD_ARRAY->array;
    delete(OLD_ARRAY);
}
template void ArrayProcessing::resize<int>(Array<int> *&, const int &, const int &);
template void ArrayProcessing::resize<float>(Array<float> *&, const int &, const float &);
template void ArrayProcessing::resize<char>(Array<char> *&, const int &, const char &);

template<typename type_array>
void ArrayProcessing::copy(type_array *new_array, const type_array *old_array, const int &size_of_copied, int position_in_new_array, int position_in_old_array)
{
    for (int i = 0; i < size_of_copied; i++)
    {
        new_array[i + position_in_new_array] = old_array[i + position_in_old_array];
    }
}
template void ArrayProcessing::copy<int>(int *, const int *, const int &, int, int);
template void ArrayProcessing::copy<float>(float *, const float *, const int &, int, int);
template void ArrayProcessing::copy<char>(char *, const char *, const int &, int, int);

template<typename type_array>
void ArrayGetter::getMin(const type_array *Array, const int &array_size, type_array &point_min, ArrayStatus ArrStat)
{
    switch (ArrStat)
    {
    case UNSORTED:
        point_min = Array[0];
        for (int i = 1; i < array_size; i++)
        {
            if (point_min > Array[i])
            {
                point_min = Array[i];
            }
        }
        break;
    case SORTED:
        point_min = Array[0];
        break;
    }
}
template void ArrayGetter::getMin<int>(const int *, const int &, int &, ArrayStatus);
template void ArrayGetter::getMin<float>(const float *, const int &, float &, ArrayStatus);
template void ArrayGetter::getMin<char>(const char *, const int &, char &, ArrayStatus);

template<typename type_array>
void ArrayGetter::getMax(const type_array *Array, const int &array_size, type_array &point_max, ArrayStatus ArrStat)
{
    switch (ArrStat)
    {
    case UNSORTED:
        point_max = Array[0];
        for (int i = 1; i < array_size; i++)
        {
            if (point_max < Array[i])
            {
                point_max = Array[i];
            }
        }
        break;
    case SORTED:
        point_max = Array[array_size - 1];
        break;
    }
}
template void ArrayGetter::getMax<int>(const int *, const int &, int &, ArrayStatus);
template void ArrayGetter::getMax<float>(const float *, const int &, float &, ArrayStatus);
template void ArrayGetter::getMax<char>(const char *, const int &, char &, ArrayStatus);

template<typename type_array>
void ArrayGetter::getElementsNumber_lenear(Array<type_array> *&ARRAY, const type_array &required_element, Array<int> *&NumberPoints)
{
    NumberPoints->array_size = 0;
    for (int i = 0; i < ARRAY->array_size; i++)
    {
        if (required_element == ARRAY->array[i])
        {
            ArrayProcessing::addElement<int>(NumberPoints, i);
        }
    }
    if (NumberPoints->array_size == 0)
    {
        throw -1;
    }
}
template void ArrayGetter::getElementsNumber_lenear<int>(Array<int> *&, const int &, Array<int> *&);
template void ArrayGetter::getElementsNumber_lenear<float>(Array<float> *&, const float &, Array<int> *&);
template void ArrayGetter::getElementsNumber_lenear<char>(Array<char> *&, const char &, Array<int> *&);

template<typename type_array>
void ArrayGetter::getElementNumber_binary(Array<type_array> *&ARRAY, const type_array &required_element, int &number_point)
{
    getElementNumber_binary(ARRAY, required_element, number_point, 0, ARRAY->array_size - 1);
}
template void ArrayGetter::getElementNumber_binary<int>(Array<int> *&, const int &, int &);
template void ArrayGetter::getElementNumber_binary<float>(Array<float> *&, const float &, int &);
template void ArrayGetter::getElementNumber_binary<char>(Array<char> *&, const char &, int &);

template<typename type_array>
void ArrayGetter::getElementNumber_binary(Array<type_array> *&ARRAY, const type_array &required_element, int &number_point, int left_limit, int right_limit)
{
    if (left_limit > right_limit)
    {
        throw -1;
    }
    int middle = left_limit + (right_limit - left_limit) / 2;
    if (ARRAY->array[middle] == required_element)
    {
        number_point = middle;
    }
    if (ARRAY->array[middle] > required_element)
    {
        getElementNumber_binary(ARRAY, required_element, number_point, left_limit, middle - 1);
    }
    if (ARRAY->array[middle] < required_element)
    {
        getElementNumber_binary(ARRAY, required_element, number_point, middle + 1, right_limit);
    }
}
template void ArrayGetter::getElementNumber_binary<int>(Array<int> *&, const int &, int &, int, int);
template void ArrayGetter::getElementNumber_binary<float>(Array<float> *&, const float &, int &, int, int);
template void ArrayGetter::getElementNumber_binary<char>(Array<char> *&, const char &, int &, int, int);

template<typename type_array>
void ArrayGetter::getOccurrencesOfSubstring(Array<type_array> *&ARRAY, Array<type_array> *&SUBARRAY, Array<int> *&Occurrences, ArrayType ArrType)
{
    Occurrences->array_size = 0;
    for (int i = 0; i <= ARRAY->array_size - SUBARRAY->array_size; i++)
    {
        for (int j = 0; j < SUBARRAY->array_size; j++)
        {
            if (ARRAY->array[i + j] == SUBARRAY->array[j])
            {
                switch (ArrType)
                {
                case NUMBER:
                    if (SUBARRAY->array_size - j == 1)
                    {
                        ArrayProcessing::addElement<int>(Occurrences, i);
                    }
                    break;
                case STRING:
                    if (SUBARRAY->array_size - j == 2)
                    {
                        ArrayProcessing::addElement<int>(Occurrences, i);
                    }
                    break;
                }
            }
            else
            {
                break;
            }
        }
    }
    if (Occurrences->array_size == 0)
    {
        throw -1;
    }
}
template void ArrayGetter::getOccurrencesOfSubstring<int>(Array<int> *&, Array<int> *&, Array<int> *&, ArrayType);
template void ArrayGetter::getOccurrencesOfSubstring<float>(Array<float> *&, Array<float> *&, Array<int> *&, ArrayType);
template void ArrayGetter::getOccurrencesOfSubstring<char>(Array<char> *&, Array<char> *&, Array<int> *&, ArrayType);

template<typename type_array>
void ArrayCharacteristic<type_array>::average(type_array &average)
{
    average = 0;
    for (int i = 0; i < this->ARRAY->array_size; i++)
    {
        average += this->ARRAY->array[i];
    }
    average = average / this->ARRAY->array_size;
}
template void ArrayCharacteristic<int>::average(int &);
template void ArrayCharacteristic<float>::average(float &);
template void ArrayCharacteristic<char>::average(char &);

template<typename type_array>
void ArrayCharacteristic<type_array>::mediana(type_array &mediana)
{
    this->ARRAY->array_size % 2 == 0 ? mediana = (this->ARRAY->array[this->ARRAY->array_size / 2] + this->ARRAY->array[(this->ARRAY->array_size / 2) - 1]) / 2 : mediana = (this->ARRAY->array[this->ARRAY->array_size / 2]);
}
template void ArrayCharacteristic<int>::mediana(int &);
template void ArrayCharacteristic<float>::mediana(float &);
template void ArrayCharacteristic<char>::mediana(char &);

template<typename type_array>
void ArrayCharacteristic<type_array>::moda(type_array &most_frequent, int &highest_frequency)
{
    highest_frequency = 0;
    int current_frequency = 0;
    for (int i = 0; i < this->ARRAY->array_size; i++)
    {
        current_frequency++;
        if (i == this->ARRAY->array_size - 1 || this->ARRAY->array[i] != this->ARRAY->array[i + 1])
        {
            if (current_frequency > highest_frequency)
            {
                highest_frequency = current_frequency;
                most_frequent = this->ARRAY->array[i];
            }
            current_frequency = 0;
        }
    }
}
template void ArrayCharacteristic<int>::moda(int &, int &);
template void ArrayCharacteristic<float>::moda(float &, int &);
template void ArrayCharacteristic<char>::moda(char &, int &);

template<typename type_array>
void ArrayCharacteristic<type_array>::modas(Array<type_array> *&MostFrequents, int &highest_frequency)
{
    type_array most_frequent;
    MostFrequents->array_size = 0, highest_frequency = 0;
    int current_frequency = 0;
    moda(most_frequent, highest_frequency);
    ArrayProcessing::addElement<type_array>(MostFrequents, most_frequent);
    for (int i = 0; i < this->ARRAY->array_size; i++)
    {
        if (most_frequent == this->ARRAY->array[i])
        {
            for (int j = i + highest_frequency; j < this->ARRAY->array_size; j++)
            {
                current_frequency++;
                if (j == this->ARRAY->array_size - 1 || this->ARRAY->array[j] != this->ARRAY->array[j + 1])
                {
                    if (current_frequency == highest_frequency)
                    {
                        ArrayProcessing::addElement<type_array>(MostFrequents, this->ARRAY->array[j]);
                    }
                    current_frequency = 0;
                }
            }
            break;
        }
    }
}
template void ArrayCharacteristic<int>::modas(Array<int> *&, int &);
template void ArrayCharacteristic<float>::modas(Array<float> *&, int &);
template void ArrayCharacteristic<char>::modas(Array<char> *&, int &);

template<typename type_array>
void Exchange_Sorts::BubbleSort<type_array>::start_sort()
{
    for (int i = 0; i < this->ARRAY->array_size; i++)
    {
        for (int j = 0; j < this->ARRAY->array_size - 1; j++)
        {
            if (this->ARRAY->array[j] > this->ARRAY->array[j + 1])
            {
                ArrayProcessing::swap<type_array>(this->ARRAY->array[j], this->ARRAY->array[j + 1]);
            }
        }
    }
}
template void Exchange_Sorts::BubbleSort<int>::start_sort();
template void Exchange_Sorts::BubbleSort<float>::start_sort();
template void Exchange_Sorts::BubbleSort<char>::start_sort();

template<typename type_array>
void Exchange_Sorts::CocktailShakerSort<type_array>::start_sort()
{
    int leftMark = 1, rightMark = this->ARRAY->array_size - 1;
    while (leftMark <= rightMark)
    {
        for (int i = rightMark; i >= leftMark; i--)
        {
            if (this->ARRAY->array[i - 1] > this->ARRAY->array[i])
            {
                ArrayProcessing::swap<type_array>(this->ARRAY->array[i], this->ARRAY->array[i - 1]);
            }
        }
        leftMark++;
        for (int i = leftMark; i <= rightMark; i++)
        {
            if (this->ARRAY->array[i - 1] > this->ARRAY->array[i])
            {
                ArrayProcessing::swap<type_array>(this->ARRAY->array[i], this->ARRAY->array[i - 1]);
            }
        }
        rightMark--;
    }
}
template void Exchange_Sorts::CocktailShakerSort<int>::start_sort();
template void Exchange_Sorts::CocktailShakerSort<float>::start_sort();
template void Exchange_Sorts::CocktailShakerSort<char>::start_sort();

template<typename type_array>
void Exchange_Sorts::QuickSort<type_array>::start_sort()
{
    quick_sort(0, this->ARRAY->array_size - 1);
}
template void Exchange_Sorts::QuickSort<int>::start_sort();
template void Exchange_Sorts::QuickSort<float>::start_sort();
template void Exchange_Sorts::QuickSort<char>::start_sort();

template<typename type_array>
void Exchange_Sorts::QuickSort<type_array>::quick_sort(const int &left_limit, const int &right_limit)
{
    type_array middle = this->ARRAY->array[(left_limit + right_limit) / 2];
    int start = left_limit, finish = right_limit;
    do
    {
        while (this->ARRAY->array[start] < middle)
        {
            start++;
        }
        while (this->ARRAY->array[finish] > middle)
        {
            finish--;
        }
        if (start <= finish)
        {
            ArrayProcessing::swap<type_array>(this->ARRAY->array[start], this->ARRAY->array[finish]);
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
void Selection_Sorts::HeapSort<type_array>::start_sort()
{
    for (int right = this->ARRAY->array_size / 2 - 1; right >= 0; right--)
    {
        heapify(this->ARRAY->array, right, this->ARRAY->array_size);
    }
    for (int i = this->ARRAY->array_size - 1; i >= 0; i--)
    {
        ArrayProcessing::swap<type_array>(this->ARRAY->array[0], this->ARRAY->array[i]);
        heapify(this->ARRAY->array, 0, i);
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
void Insertion_Sorts::InsertSort<type_array>::start_sort()
{
    for (int i = 0; i < this->ARRAY->array_size; i++)
    {
        for (int j = i; j > 0 && this->ARRAY->array[j - 1] > this->ARRAY->array[j]; j--)
        {
            ArrayProcessing::swap<type_array>(this->ARRAY->array[j - 1], this->ARRAY->array[j]);
        }
    }
}
template void Insertion_Sorts::InsertSort<int>::start_sort();
template void Insertion_Sorts::InsertSort<float>::start_sort();
template void Insertion_Sorts::InsertSort<char>::start_sort();

template<typename type_array>
void Merge_Sorts::MergeSort<type_array>::start_sort()
{
    merge_sort(this->ARRAY->array, 0, this->ARRAY->array_size - 1);
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

void Noncomparison_Sort::CountingSort::start_sort()
{
    int min, max;
    ArrayGetter::getMin<int>(ARRAY->array, ARRAY->array_size, min);
    ArrayGetter::getMax<int>(ARRAY->array, ARRAY->array_size, max);
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

void Noncomparison_Sort::RadixSort::start_sort()
{
    int exp = 1, bit = 10, max;
    ArrayGetter::getMax<int>(ARRAY->array, ARRAY->array_size, max);
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
