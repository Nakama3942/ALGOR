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
void ArrayProcessing::getMin(const type_array *Array, const int &array_size, type_array &point_min, ArrayStatus ArrStat)
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
template void ArrayProcessing::getMin<int>(const int *, const int &, int &, ArrayStatus);
template void ArrayProcessing::getMin<float>(const float *, const int &, float &, ArrayStatus);
template void ArrayProcessing::getMin<char>(const char *, const int &, char &, ArrayStatus);

template<typename type_array>
void ArrayProcessing::getMax(const type_array *Array, const int &array_size, type_array &point_max, ArrayStatus ArrStat)
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
template void ArrayProcessing::getMax<int>(const int *, const int &, int &, ArrayStatus);
template void ArrayProcessing::getMax<float>(const float *, const int &, float &, ArrayStatus);
template void ArrayProcessing::getMax<char>(const char *, const int &, char &, ArrayStatus);

template<typename type_array>
void ArrayProcessing::getElementsNumber_lenear(Array<type_array> *&ARRAY, const type_array &required_element, Array<int> *&NumberPoints)
{
    NumberPoints->array_size = 0;
    for (int i = 0; i < ARRAY->array_size; i++)
    {
        if (required_element == ARRAY->array[i])
        {
            addElement<int>(NumberPoints, i);
        }
    }
    if (NumberPoints->array_size == 0)
    {
        throw -1;
    }
}
template void ArrayProcessing::getElementsNumber_lenear<int>(Array<int> *&, const int &, Array<int> *&);
template void ArrayProcessing::getElementsNumber_lenear<float>(Array<float> *&, const float &, Array<int> *&);
template void ArrayProcessing::getElementsNumber_lenear<char>(Array<char> *&, const char &, Array<int> *&);

template<typename type_array>
void ArrayProcessing::getElementNumber_binary(Array<type_array> *&ARRAY, const type_array &required_element, int &number_point)
{
    getElementNumber_binary(ARRAY, required_element, number_point, 0, ARRAY->array_size - 1);
}
template void ArrayProcessing::getElementNumber_binary<int>(Array<int> *&, const int &, int &);
template void ArrayProcessing::getElementNumber_binary<float>(Array<float> *&, const float &, int &);
template void ArrayProcessing::getElementNumber_binary<char>(Array<char> *&, const char &, int &);

template<typename type_array>
void ArrayProcessing::getElementNumber_binary(Array<type_array> *&ARRAY, const type_array &required_element, int &number_point, int left_limit, int right_limit)
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
template void ArrayProcessing::getElementNumber_binary<int>(Array<int> *&, const int &, int &, int, int);
template void ArrayProcessing::getElementNumber_binary<float>(Array<float> *&, const float &, int &, int, int);
template void ArrayProcessing::getElementNumber_binary<char>(Array<char> *&, const char &, int &, int, int);

template<typename type_array>
void ArrayProcessing::getOccurrencesOfSubstring(Array<type_array> *&ARRAY, Array<type_array> *&SUBARRAY, Array<int> *&Occurrences, ArrayType ArrType)
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
                        addElement<int>(Occurrences, i);
                    }
                    break;
                case STRING:
                    if (SUBARRAY->array_size - j == 2)
                    {
                        addElement<int>(Occurrences, i);
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
template void ArrayProcessing::getOccurrencesOfSubstring<int>(Array<int> *&, Array<int> *&, Array<int> *&, ArrayType);
template void ArrayProcessing::getOccurrencesOfSubstring<float>(Array<float> *&, Array<float> *&, Array<int> *&, ArrayType);
template void ArrayProcessing::getOccurrencesOfSubstring<char>(Array<char> *&, Array<char> *&, Array<int> *&, ArrayType);

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

//template<typename type_array>
//void ArrayProcessing::resize(Array<type_array> *&ARRAY)
//{
//}
//template void ArrayProcessing::createdStruct<int>(Array<int> *&, const int &);
//template void ArrayProcessing::createdStruct<float>(Array<float> *&, const int &);
//template void ArrayProcessing::createdStruct<char>(Array<char> *&, const int &);

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
