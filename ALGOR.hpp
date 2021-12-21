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
 * 2. ALGOR_EXCEPTION - класс для работы с исключениями                         *
 * 3. ALGOR_RANDOM - собственный генератор случайных чисел                      *
 * 4. AlGOR_ARRAY - класс для работы с массивами                                *
 * 5. AlGOR_SORTING - Набор методов сортировок                                  *
 * 6. AlGOR_HEAP - класс для работы с деревьями                                 *
 * 7. AlGOR_LIST - класс для работы со списками                                 *
 *                                                                              *
 * ---------------------------------------------------------------------------- *
 * **************************************************************************** */

#ifndef ALGOR_HPP
#define ALGOR_HPP

#include "ALGOR_global.h"

//#include <iostream> //Иногда используется для тестов
//#include <ctime>  //Будет убран после написания рандомизатора
//#include <random> //Будет убран после написания рандомизатора
//using namespace std;

//ALGOR_CORE

template <typename type_array> void swap(type_array &firstNumber, type_array &secondNumber);
template <typename type_array> type_array minimum(const type_array *Array, const unsigned int &array_size);
template <typename type_array> type_array maximum(const type_array *Array, const unsigned int &array_size);
template <typename type_array> void addElement(type_array *&Array, unsigned int &array_size, const type_array &value, const unsigned int position = 0);
template <typename type_array> void subtractElement(type_array *&Array, unsigned int &array_size, const unsigned int position);
template <typename type_array> void subtractValue(type_array *&Array, unsigned int &array_size, const type_array &value);
template <typename type_array> void copy(type_array *new_array, const type_array *old_array, const unsigned int &size_of_copied, unsigned int position_in_new_array = 0, unsigned int position_in_old_array = 0);

template <typename type_array> struct Array { type_array *array; unsigned int array_size = 0; };
template <typename type_array> Array<type_array> *create_struct(const unsigned int &SIZE);
template <typename type_array> void remove_struct(Array<type_array> *&Array);

template <typename type_array> class ArrayBase
{
public:
    ArrayBase(Array<type_array> *&Array) : ARRAY(Array) {}
    ArrayBase(const unsigned int &SIZE) { ARRAY = create_struct<type_array>(SIZE); }
    ArrayBase() { ARRAY = nullptr; }
protected:
    Array<type_array> *ARRAY;
};

//ALGOR_EXCEPTION

//class Excep
//{
//public:
//};

//ALGOR_RANDOM

//class Randomizer
//{
//public:
//};

//RC4 (взят по ссылке https://www.youtube.com/watch?v=PQlZI-QoM2A)
#include <stdint.h>
static uint8_t Sbox[256];

void crypto_srand(const char *key, int ksize)
{
    uint8_t j = 0;
    for (int i = 0; i < 256; i++)
    {
        Sbox[i] = i;
    }
    for (int i = 0; i < 256; i++)
    {
        j = j + Sbox[i] + (uint8_t)key[i % ksize];
        swap<uint8_t>(Sbox[i], Sbox[j]);
    }
}

void crypto_rand(char *output, int size)
{
    uint8_t i = 0, j = 0;
    uint8_t t;
    for (int k = 0; i < size; k++)
    {
        i += 1;
        j += Sbox[i];
        swap<uint8_t>(Sbox[i], Sbox[j]);
        t = Sbox[i] + Sbox[j];
        output[k] = (unsigned int)Sbox[t];
    }
}

//int crypto_entropy(char *output, int size)
//{
//    //code
//    return 0;
//}

/*     */

//Следующий класс был взят по ссылке https://www.agner.org/random/
// во втором загрузочном пакете ("Uniform random number generators in C++").
//Характеристика: File name: randomc.zip, size: 471048, last modified: 2014-Jun-14

class CRandomMersenne {                // Encapsulate random number generator
#define MERS_N   624
#define MERS_M   397
#define MERS_R   31
#define MERS_U   11
#define MERS_S   7
#define MERS_T   15
#define MERS_L   18
#define MERS_A   0x9908B0DF
#define MERS_B   0x9D2C5680
#define MERS_C   0xEFC60000

public:
   CRandomMersenne(int seed)         // Constructor
   {
       RandomInit(seed); LastInterval = 0;
   }
   void RandomInit(int seed)          // Re-seed
   {
       // Initialize and seed
       Init0(seed);

       // Randomize some more
       for (int i = 0; i < 37; i++) BRandom();
   }
   void RandomInitByArray(int const seeds[], int NumSeeds) // Seed by more than 32 bits
   {
       // Seed by more than 32 bits
       int i, j, k;

       // Initialize
       Init0(19650218);

       if (NumSeeds <= 0) return;

       // Randomize mt[] using whole seeds[] array
       i = 1;  j = 0;
       k = (MERS_N > NumSeeds ? MERS_N : NumSeeds);
       for (; k; k--) {
           mt[i] = (mt[i] ^ ((mt[i-1] ^ (mt[i-1] >> 30)) * 1664525UL)) + (uint32_t)seeds[j] + j;
           i++; j++;
           if (i >= MERS_N) {mt[0] = mt[MERS_N-1]; i=1;}
           if (j >= NumSeeds) j=0;}
       for (k = MERS_N-1; k; k--) {
           mt[i] = (mt[i] ^ ((mt[i-1] ^ (mt[i-1] >> 30)) * 1566083941UL)) - i;
           if (++i >= MERS_N) {mt[0] = mt[MERS_N-1]; i=1;}}
       mt[0] = 0x80000000UL;  // MSB is 1; assuring non-zero initial array

       // Randomize some more
       mti = 0;
       for (int i = 0; i <= MERS_N; i++) BRandom();
   }
   int IRandom (int min, int max)     // Output random integer
   {
       // Output random integer in the interval min <= x <= max
       // Relative error on frequencies < 2^-32
       if (max <= min) {
           if (max == min) return min; else return 0x80000000;
       }
       // Multiply interval with random and truncate
       int r = int((double)(uint32_t)(max - min + 1) * Random() + min);
       if (r > max) r = max;
       return r;
   }
   int IRandomX(int min, int max)     // Output random integer, exact
   {
       // Output random integer in the interval min <= x <= max
       // Each output value has exactly the same probability.
       // This is obtained by rejecting certain bit values so that the number
       // of possible bit values is divisible by the interval length
       if (max <= min) {
          if (max == min) return min; else return 0x80000000;
       }
       // 64 bit integers available. Use multiply and shift method
       uint32_t interval;                    // Length of interval
       uint64_t longran;                     // Random bits * interval
       uint32_t iran;                        // Longran / 2^32
       uint32_t remainder;                   // Longran % 2^32

       interval = uint32_t(max - min + 1);
       if (interval != LastInterval) {
          // Interval length has changed. Must calculate rejection limit
          // Reject when remainder >= 2^32 / interval * interval
          // RLimit will be 0 if interval is a power of 2. No rejection then
          RLimit = uint32_t(((uint64_t)1 << 32) / interval) * interval - 1;
          LastInterval = interval;
       }
       do { // Rejection loop
          longran  = (uint64_t)BRandom() * interval;
          iran = (uint32_t)(longran >> 32);
          remainder = (uint32_t)longran;
       } while (remainder > RLimit);
       // Convert back to signed and return result
       return (int32_t)iran + min;
   }
   double Random()                    // Output random float
   {
       // Output random float number in the interval 0 <= x < 1
       // Multiply by 2^(-32)
       return (double)BRandom() * (1./(65536.*65536.));
   }
   uint32_t BRandom()                 // Output random bits
   {
       // Generate 32 random bits
       uint32_t y;

       if (mti >= MERS_N) {
           // Generate MERS_N words at one time
           const uint32_t LOWER_MASK = (1LU << MERS_R) - 1;       // Lower MERS_R bits
           const uint32_t UPPER_MASK = 0xFFFFFFFF << MERS_R;      // Upper (32 - MERS_R) bits
           static const uint32_t mag01[2] = {0, MERS_A};

           int kk;
           for (kk=0; kk < MERS_N-MERS_M; kk++) {
              y = (mt[kk] & UPPER_MASK) | (mt[kk+1] & LOWER_MASK);
              mt[kk] = mt[kk+MERS_M] ^ (y >> 1) ^ mag01[y & 1];}

           for (; kk < MERS_N-1; kk++) {
              y = (mt[kk] & UPPER_MASK) | (mt[kk+1] & LOWER_MASK);
              mt[kk] = mt[kk+(MERS_M-MERS_N)] ^ (y >> 1) ^ mag01[y & 1];}

           y = (mt[MERS_N-1] & UPPER_MASK) | (mt[0] & LOWER_MASK);
           mt[MERS_N-1] = mt[MERS_M-1] ^ (y >> 1) ^ mag01[y & 1];
           mti = 0;
       }
       y = mt[mti++];

       // Tempering (May be omitted):
       y ^=  y >> MERS_U;
       y ^= (y << MERS_S) & MERS_B;
       y ^= (y << MERS_T) & MERS_C;
       y ^=  y >> MERS_L;

       return y;
   }
private:
   void Init0(int seed)               // Basic initialization procedure
   {
       // Seed generator
       const uint32_t factor = 1812433253UL;
       mt[0]= seed;
       for (mti=1; mti < MERS_N; mti++) {
           mt[mti] = (factor * (mt[mti-1] ^ (mt[mti-1] >> 30)) + mti);
       }
   }
   uint32_t mt[MERS_N];                // State vector
   int mti;                            // Index into mt
   uint32_t LastInterval;              // Last interval length for IRandomX
   uint32_t RLimit;                    // Rejection limit used by IRandomX
};

//ALGOR_ARRAY

enum ArrayStatus { SORTED, UNSORTED };
enum ArrayType { NUMBER, STRING };

template<typename type_array> class ARRAYDATA : public ArrayBase<type_array>
{
public:
    ARRAYDATA(Array<type_array> *&Array) : ArrayBase<type_array>(Array) {}
    ARRAYDATA(const unsigned int &SIZE) : ArrayBase<type_array>(SIZE) {}
    ARRAYDATA() : ArrayBase<type_array>() {}

    void generatedData(const int &min_limit, const int &max_limit);
    void setNewData(Array<type_array> *&Array);
    void setData(Array<type_array> *&Array);
    void cloneData(Array<type_array> *&CloningArray);
    void cloneData(ARRAYDATA<type_array> *&CloningObject);
    void getData(Array<type_array> *&DATA);
    Array<type_array> *getData();

    void reset();
    void resize(const unsigned int &NEW_SIZE, const type_array &setElement);
    void replace(const unsigned int &position, const type_array &value);
    void reverse();
    void remove();
    void respawn();

    type_array getMin(ArrayStatus ArrStat = UNSORTED);
    type_array getMax(ArrayStatus ArrStat = UNSORTED);

    Array<int> *lenear_searcher(const type_array &required_element);
    int binary_searcher(const type_array &required_element);
    Array<int> *searcherOccurrencesOfSubstring(Array<type_array> *&SUBARRAY, ArrayType ArrType = NUMBER);

    type_array average();
    type_array mediana();
    type_array moda(int &highest_frequency);
    Array<type_array> *modas(int &highest_frequency);

    void operator&& (const type_array &value); //Оператор для добавления в конец массива
    void operator! (); //Оператор для удаления из конца массива
    void operator|| (const type_array &value); //Оператор для удаления указанного значения
    void operator<< (ARRAYDATA<type_array> *&appendingArray); //Оператор для слияния двух массивов в текущем объекте
    void operator>> (ARRAYDATA<type_array> *&appendingArray); //Оператор для слияния двух массивов в принятом объекте
    void operator+ (const unsigned int &addSize); //Оператор для увеличения массива на конкретный размер
    void operator- (const unsigned int &subtractSize); //Оператор для уменьшения массива на конкретный размер
    void operator* (const unsigned int &multiplySize); //Оператор для увеличения массива во сколько-то раз
    void operator/ (const unsigned int &divideSize); //Оператор для уменьшения массива во сколько-то раз

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
