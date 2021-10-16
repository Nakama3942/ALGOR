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

/* **************************************************************************** *
 * ---------------------------------------------------------------------------- *
 *                                Version: 1.0.2                                *
 * ---------------------------------------------------------------------------- *
 * **************************************************************************** */

#ifndef SORTINGALGORITHMS_H
#define SORTINGALGORITHMS_H

#include <iostream>
#include <ctime>
#include <random>
using namespace std;

namespace SortingAlgorithms
{
    template <typename type_array>
    class ArrayProcessing
    {
    public:
        static void generatedArray(type_array *Array, int array_size, int left_limit, int right_limit)
        {
            srand(time(NULL));
            for (int i = 0; i < array_size; i++)
            {
                Array[i] = left_limit + rand() % right_limit;
            }
        }
        static void swap(type_array &firstNumber, type_array &secondNumber)
        {
            type_array *temp = new type_array(firstNumber);
            firstNumber = secondNumber;
            secondNumber = *temp;
            delete (temp);
        }
        static void print(const char *representing_string, type_array *Array, int array_size)
        {
            //Метод для консольных приложений
            cout << representing_string;
            for (int i = 0; i < array_size; i++)
            {
                cout << Array[i] << "\t";
            }
            cout << "\n";
        }
        static void getMin(type_array *Array, int array_size, type_array &point_min)
        {
            type_array min = Array[0];
            for (int i = 1; i < array_size; i++)
            {
                if (min > Array[i])
                {
                    min = Array[i];
                }
            }
            point_min = min;
        }
        static void getMax(type_array *Array, int array_size, type_array &point_max)
        {
            type_array max = Array[0];
            for (int i = 1; i < array_size; i++)
            {
                if (max < Array[i])
                {
                    max = Array[i];
                }
            }
            point_max = max;
        }
        static void reverse(type_array *Array, int array_size)
        {
            int left_limit = 0, right_limit = array_size - 1;
            for (int i = 0; i < array_size / 2; i++)
            {
                swap(Array[left_limit], Array[right_limit]);
                left_limit++;
                right_limit--;
            }
        }
        static void copy(type_array *new_array, type_array *old_array, int array_size)
        {
            for (int i = 0; i < array_size; i++)
            {
                new_array[i] = old_array[i];
            }
        }
        static void sum(type_array *Array, int array_size, type_array &sum)
        {
            sum = 0;
            for (int i = 0; i < array_size; i++)
            {
                sum += Array[i];
            }
        }
        static void average(type_array *Array, int array_size, type_array &average)
        {
            type_array array_sum;
            sum(Array, array_size, array_sum);
            average = array_sum / array_size;
        }
        static void mediana(type_array *Array, int array_size, type_array &mediana)
        {
            if (array_size % 2 == 0)
            {
                mediana = (Array[array_size / 2] + Array[(array_size / 2) - 1]) / 2;
            }
            else
            {
                mediana = (Array[array_size / 2]);
            }
        }
        static void moda(type_array *Array, int array_size, type_array &moda_element, int &moda_count)
        {
            type_array most_frequent;                         //Наиболее частый элемент
            int highest_frequency = 0, current_frequency = 0; //Самая высокая частота и текущая частота
            for (int i = 0; i < array_size; i++)
            {
                current_frequency++;
                if (i == array_size - 1 || Array[i] != Array[i + 1])
                {
                    if (current_frequency > highest_frequency)
                    {
                        highest_frequency = current_frequency;
                        most_frequent = Array[i];
                    }
                    current_frequency = 0;
                }
            }
            moda_element = most_frequent;
            moda_count = highest_frequency;
        }
    };

    template <typename type_array>
    class InsertSort
    {
    public:
        static void insert_sort(type_array *Array, int array_size)
        {
            for (int i = 0; i < array_size; i++)
            {
                for (int j = i; j > 0 && Array[j - 1] > Array[j]; j--)
                {
                    ArrayProcessing<type_array>::swap(Array[j - 1], Array[j]);
                }
            }
        }
    };

    template <typename type_array>
    class BubbleSort
    {
    public:
        static void bubble_sort(type_array *Array, int array_size)
        {
            for (int i = 0; i < array_size; i++)
            {
                for (int j = 0; j < array_size - 1; j++)
                {
                    if (Array[j] > Array[j + 1])
                    {
                        ArrayProcessing<type_array>::swap(Array[j], Array[j + 1]);
                    }
                }
            }
        }
    };

    template <typename type_array>
    class CocktailShakerSort
    {
    public:
        static void cocktail_shaker_sort(type_array *Array, int array_size)
        {
            int leftMark = 1, rightMark = array_size - 1;
            while (leftMark <= rightMark)
            {
                for (int i = rightMark; i >= leftMark; i--)
                {
                    if (Array[i - 1] > Array[i])
                    {
                        ArrayProcessing<type_array>::swap(Array[i], Array[i - 1]);
                    }
                }
                leftMark++;
                for (int i = leftMark; i <= rightMark; i++)
                {
                    if (Array[i - 1] > Array[i])
                    {
                        ArrayProcessing<type_array>::swap(Array[i], Array[i - 1]);
                    }
                }
                rightMark--;
            }
        }
    };

    template <typename type_array>
    class MergeSort
    {
    public:
        static void merge(type_array *Array, int left_limit, int middle_limit, int right_limit)
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
        static void merge_sort(type_array *Array, int left_limit, int right_limit)
        {
            if (left_limit < right_limit)
            {
                int middle = left_limit + (right_limit - left_limit) / 2;
                merge_sort(Array, left_limit, middle);
                merge_sort(Array, middle + 1, right_limit);
                merge(Array, left_limit, middle, right_limit);
            }
        }
    };

    template <typename type_array>
    class HeapSort
    {
    public:
        static void heapify(type_array *Array, int count, int array_size)
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
                ArrayProcessing<type_array>::swap(Array[count], Array[large]);
                heapify(Array, large, array_size);
            }
        }
        static void heap_sort(type_array *Array, int array_size)
        {
            for (int right = array_size / 2 - 1; right >= 0; right--)
            {
                heapify(Array, right, array_size);
            }
            for (int i = array_size - 1; i >= 0; i--)
            {
                ArrayProcessing<type_array>::swap(Array[0], Array[i]);
                heapify(Array, 0, i);
            }
        }
    };

    template <typename type_array>
    class QuickSort
    {
    public:
        static void quick_sort(type_array *Array, int left_limit, int right_limit)
        {
            type_array middle = Array[(left_limit + right_limit) / 2];
            int start = left_limit, finish = right_limit;
            do
            {
                while (Array[start] < middle)
                {
                    start++;
                }
                while (Array[finish] > middle)
                {
                    finish--;
                }
                if (start <= finish)
                {
                    ArrayProcessing<type_array>::swap(Array[start], Array[finish]);
                    start++;
                    finish--;
                }
            } while (start < finish);
            if (left_limit < finish)
            {
                quick_sort(Array, left_limit, finish);
            }
            if (start < right_limit)
            {
                quick_sort(Array, start, right_limit);
            }
        }
    };

    class CountingSort
    {
    public:
        static void counting_sort(int *Array, int array_size)
        {
            int min, max;
            ArrayProcessing<int>::getMin(Array, array_size, min);
            ArrayProcessing<int>::getMax(Array, array_size, max);
            int *tempArray = new int[max - min + 1];
            for (int i = 0; i < max - min + 1; i++)
            {
                tempArray[i] = 0;
            }
            for (int i = 0; i < array_size; i++)
            {
                tempArray[Array[i] - min] = tempArray[Array[i] - min] + 1;
            }
            for (int i = 0, j = min; j < max + 1; j++)
            {
                while (tempArray[j - min] != 0)
                {
                    Array[i] = j;
                    tempArray[j - min]--;
                    i++;
                }
            }
            delete[] tempArray;
        }
    };

    class RadixSort
    {
    public:
        static void radix_sort(int *Array, int array_size)
        {
            int exp = 1, bit = 10, max;
            ArrayProcessing<int>::getMax(Array, array_size, max);
            int *tempArray = new int[array_size], *bucket = new int[bit];
            while (max / exp > 0)
            {
                for (int i = 0; i < bit; i++)
                {
                    bucket[i] = 0;
                }
                for (int i = 0; i < array_size; i++)
                {
                    bucket[(Array[i] / exp) % bit]++;
                }
                for (int i = 1; i < bit; i++)
                {
                    bucket[i] += bucket[i - 1];
                }
                for (int i = array_size - 1; i >= 0; i--)
                {
                    int current = (Array[i] % (exp * bit)) / exp;
                    bucket[current]--;
                    tempArray[bucket[current]] = Array[i];
                }
                for (int i = 0; i < array_size; i++)
                {
                    Array[i] = tempArray[i];
                }
                exp *= bit;
            }
            delete[] bucket;
            delete[] tempArray;
        }
    };
}

#endif // SORTINGALGORITHMS_H
