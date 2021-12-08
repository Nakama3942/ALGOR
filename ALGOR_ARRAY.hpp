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

#ifndef ALGORARRAY_HPP
#define ALGORARRAY_HPP

//#include <iostream> //Иногда используется для тестов
#include <ctime>  //Будет убран после написания рандомизатора
#include <random> //Будет убран после написания рандомизатора
using namespace std;

template <typename type_array>
struct Array
{
    type_array *array;
    int array_size;
};

//После написания будет перенесён в ALGOR_RANDOM.hpp
//class Randomizer
//{
//public:
//};

class ArrayProcessing
{
public:
    enum ArrayStatus
    {
        SORTED,
        UNSORTED
    };
    enum ArrayType
    {
        NUMBER,
        STRING
    };
    template <typename type_array>
    static void createdStruct(Array<type_array> *&ARRAY, const int &SIZE)
    {
        ARRAY->array_size = SIZE;
        ARRAY->array = new type_array[SIZE];
    }
    template <typename type_array>
    static void generatedArray(Array<type_array> *&ARRAY, const int &left_limit, const int &right_limit)
    {
        srand(time(NULL));
        for (int i = 0; i < ARRAY->array_size; i++)
        {
            ARRAY->array[i] = left_limit + rand() % right_limit;
        }
    }
    template <typename type_array>
    static void swap(type_array &firstNumber, type_array &secondNumber)
    {
        type_array *temp = new type_array(firstNumber);
        firstNumber = secondNumber;
        secondNumber = *temp;
        delete (temp);
    }
    template <typename type_array>
    static void getMin(const type_array *Array, const int &array_size, type_array &point_min, ArrayStatus ArrStat = UNSORTED)
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
    template <typename type_array>
    static void getMax(const type_array *Array, const int &array_size, type_array &point_max, ArrayStatus ArrStat = UNSORTED)
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
    template <typename type_array>
    static void getElementsNumber_lenear(Array<type_array> *&ARRAY, const type_array &required_element, Array<int> *&NumberPoints)
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
    template <typename type_array>
    static void getElementNumber_binary(const type_array *Array, const int &left_limit, const int &right_limit, const type_array &required_element, int &number_point)
    {
        if (left_limit > right_limit)
        {
            throw -1;
        }
        int middle = left_limit + (right_limit - left_limit) / 2;
        if (Array[middle] == required_element)
        {
            number_point = middle;
        }
        if (Array[middle] > required_element)
        {
            getElementNumber_binary(Array, left_limit, middle - 1, required_element, number_point);
        }
        if (Array[middle] < required_element)
        {
            getElementNumber_binary(Array, middle + 1, right_limit, required_element, number_point);
        }
    }
    template <typename type_array>
    static void getOccurrencesOfSubstring(Array<type_array> *&ARRAY, Array<type_array> *&SUBARRAY, Array<int> *&Occurrences, ArrayType ArrType = NUMBER)
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
    template <typename type_array>
    static void addElement(Array<type_array> *&ARRAY, const type_array &value)
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
    template <typename type_array>
    static void reverse(Array<type_array> *&ARRAY)
    {
        int left_limit = 0, right_limit = ARRAY->array_size - 1;
        for (int i = 0; i < ARRAY->array_size / 2; i++)
        {
            swap(ARRAY->array[left_limit], ARRAY->array[right_limit]);
            left_limit++;
            right_limit--;
        }
    }
    //template <typename type_array>
    //static void resize(Array<type_array> *&ARRAY)
    //{
    //}
    template <typename type_array>
    static void copy(type_array *new_array, const type_array *old_array, const int &size_of_copied, int position_in_new_array = 0, int position_in_old_array = 0)
    {
        for (int i = 0; i < size_of_copied; i++)
        {
            new_array[i + position_in_new_array] = old_array[i + position_in_old_array];
        }
    }
    template <typename type_array>
    static void average(Array<type_array> *&ARRAY, type_array &average)
    {
        average = 0;
        for (int i = 0; i < ARRAY->array_size; i++)
        {
            average += ARRAY->array[i];
        }
        average = average / ARRAY->array_size;
    }
    template <typename type_array>
    static void mediana(Array<type_array> *&ARRAY, type_array &mediana)
    {
        ARRAY->array_size % 2 == 0 ? mediana = (ARRAY->array[ARRAY->array_size / 2] + ARRAY->array[(ARRAY->array_size / 2) - 1]) / 2 : mediana = (ARRAY->array[ARRAY->array_size / 2]);
    }
    template <typename type_array>
    static void moda(Array<type_array> *&ARRAY, type_array &most_frequent, int &highest_frequency)
    {
        highest_frequency = 0;
        int current_frequency = 0;
        for (int i = 0; i < ARRAY->array_size; i++)
        {
            current_frequency++;
            if (i == ARRAY->array_size - 1 || ARRAY->array[i] != ARRAY->array[i + 1])
            {
                if (current_frequency > highest_frequency)
                {
                    highest_frequency = current_frequency;
                    most_frequent = ARRAY->array[i];
                }
                current_frequency = 0;
            }
        }
    }
    template <typename type_array>
    static void modas(Array<type_array> *&ARRAY, Array<type_array> *&MostFrequents, int &highest_frequency)
    {
        type_array most_frequent;
        MostFrequents->array_size = 0, highest_frequency = 0;
        int current_frequency = 0;
        moda<type_array>(ARRAY, most_frequent, highest_frequency);
        addElement<type_array>(MostFrequents, most_frequent);
        for (int i = 0; i < ARRAY->array_size; i++)
        {
            if (most_frequent == ARRAY->array[i])
            {
                for (int j = i + highest_frequency; j < ARRAY->array_size; j++)
                {
                    current_frequency++;
                    if (j == ARRAY->array_size - 1 || ARRAY->array[j] != ARRAY->array[j + 1])
                    {
                        if (current_frequency == highest_frequency)
                        {
                            addElement<type_array>(MostFrequents, ARRAY->array[j]);
                        }
                        current_frequency = 0;
                    }
                }
                break;
            }
        }
    }
};

#endif //ALGORARRAY_HPP