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
        static void print(type_array *Array, int array_size)
        {
            for (int i = 0; i < array_size; i++)
            {
                cout << Array[i] << " ";
            }
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

    template <typename type_arr>
    class BubbleSort
    {
    public:
        static void bubble_sort(type_arr *Array, int array_size)
        {
            for (int i = 0; i < array_size; i++)
            {
                for (int j = 0; j < array_size - 1; j++)
                {
                    if (Array[j] > Array[j + 1])
                    {
                        ArrayProcessing<type_arr>::swap(Array[j], Array[j + 1]);
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

    template <class type_arr>
    class QuickSort
    {
    public:
        static void quick_sort(type_arr *Array, int left_limit, int right_limit)
        {
            type_arr middle = Array[(left_limit + right_limit) / 2];
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
                    ArrayProcessing<type_arr>::swap(Array[start], Array[finish]);
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
            int min = Array[0], max = Array[0];
            for (int i = 1; i < array_size; i++)
            {
                if (min > Array[i])
                {
                    min = Array[i];
                }
            }
            for (int i = 1; i < array_size; i++)
            {
                if (max < Array[i])
                {
                    max = Array[i];
                }
            }
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
