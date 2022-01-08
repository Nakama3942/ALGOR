/* ******************************   ALGOR.hpp   ******************************* *
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
 *                                Version: 2.0.0                                *
 * ---------------------------------------------------------------------------- *
 * **************************************************************************** *
 * ---------------------------------------------------------------------------- *
 *                                                                              *
 *                              Project Structure:                              *
 * 1. ALGOR_CORE - basic structures and functions of the library                *
 * 2. ALGOR_EXCEPTION - class for working with exceptions                       *
 * 3. ALGOR_RANDOM - own random number generators                               *
 * 4. AlGOR_SORTING - set of sorting methods                                    *
 * 5. AlGOR_ARRAY - class for working with arrays                               *
 * 6. ALGOR_MATRIX - class for working with matrices                            *
 * 7. AlGOR_HEAP - class for working with trees                                 *
 * 8. AlGOR_LIST - class for working with lists                                 *
 * 9. ALGOR_DOCUMENTATION - Documentation Libraries                             *
 *                                                                              *
 * ---------------------------------------------------------------------------- *
 * **************************************************************************** */

/*!
 * \file
 * \brief Library for processing arrays and sorting them 
 * \author Kalynovsky Valentin
 * \version 2.0.0
 * \date 23.12.2021
 * \copyright Copyright © 2021 Kalynovsky Valentin. All rights reserved. Licensed under the Apache License, Version 2.0 (the "License")
 */

#ifndef ALGOR_HPP
#define ALGOR_HPP

//ALGOR_CORE

using int8_t = signed char; ///< Alias for signed char
using int16_t = short;      ///< Alias for short
using int32_t = int;        ///< Alias for int
using int64_t = long long;  ///< Alias for long long

using uint8_t = unsigned char;       ///< Alias for unsigned char
using uint16_t = unsigned short;     ///< Alias for unsigned short
using uint32_t = unsigned int;       ///< Alias for unsigned int
using uint64_t = unsigned long long; ///< Alias for unsigned long long

using asize_t = unsigned int; ///< Alias for specifying the type "array size"

template <typename type_array>
void swap(type_array &firstNumber, type_array &secondNumber);
template <typename type_array>
type_array minimum(const type_array *Array, const asize_t &array_size);
template <typename type_array>
type_array maximum(const type_array *Array, const asize_t &array_size);
template <typename type_array>
void addElement(type_array *&Array, asize_t &array_size, const type_array &value, const unsigned int position = 0);
template <typename type_array>
void subtractElement(type_array *&Array, asize_t &array_size, const unsigned int position);
template <typename type_array>
void subtractValue(type_array *&Array, asize_t &array_size, const type_array &value);
template <typename type_array>
void copy(type_array *new_array, const type_array *old_array, const unsigned int &size_of_copied, unsigned int position_in_new_array = 0, unsigned int position_in_old_array = 0);

/*!
 * \brief A structure that mimics an array. Designed to store a pointer to a dynamic array and its size
 * \tparam type_array The type of elements that the array stores. For example int or float
 */
template <typename type_array>
struct Array
{
    type_array *array;
    asize_t array_size = 0;
};
template <typename type_array>
Array<type_array> *create_struct(const asize_t &SIZE);
template <typename type_array>
void remove_struct(Array<type_array> *&Array);

/*!
 * \brief The base class, which is organized for working with arrays - memory allocation, storage, deletion
 * \tparam type_array The type of elements that the array stores. For example int or float
 */
template <typename type_array>
class ArrayBase
{
public:
    ArrayBase(Array<type_array> *&Array);
    ArrayBase(const asize_t &SIZE);
    ArrayBase();

protected:
    Array<type_array> *ARRAY; ///< Pointer to a structure storing an array
};

//ALGOR_EXCEPTION

/*!
 * \brief Class for working with exceptions
 * 
 */
class Exception
{
public:
    Exception(unsigned int CODE, const char *MESSAGE, const char *DETAILS);
    Exception(unsigned int CODE, const char *MESSAGE);
    Exception(unsigned int CODE);
    Exception(const char *MESSAGE);
    unsigned int code();
    const char *what();
    const char *details();

protected:
    unsigned int CODE;   ///< Exception encoding
    const char *MESSAGE; ///< Message exception
    const char *DETAILS; ///< Exception details
};

/*!
 * \brief void_data exception class
 * 
 */
class void_data : public Exception
{
public:
    void_data();
};

/*!
 * \brief not_found exception class
 * 
 */
class not_found : public Exception
{
public:
    not_found();
};

//ALGOR_RANDOM

/*!
 * \brief Simple crypto-strong generator
 * \note Taken from the link https://www.youtube.com/watch?v=PQlZI-QoM2A
 */
class RC4
{
public:
    //int crypto_entropy();
    void crypto_srand(const char *key, int ksize);
    void crypto_rand(char *output, int size);

private:
    uint8_t Sbox[256];
};

/*!
 * \brief Advanced generator based on Marsen primes
 * \note Source URL: www.agner.org/random
 */
class MersenneTwister
{
public:
    MersenneTwister(int seed);
    void RandomInit(int seed);
    int IRandom(int min, int max);
    int IRandomX(int min, int max);
    double Random();
    uint32_t BRandom();

private:
    void Init0(int seed);
    uint32_t mersenne_twister[624]; //State vector
    int mersenne_twister_index;     //Index into mersenne_twister
    uint32_t LastInterval;          //Last interval length for IRandomX
    uint32_t RejectionLimit;        //Rejection limit used by IRandomX
};

//ALGOR_SORTING

namespace Exchange_Sorts
{
    template <typename type_array>
    class BubbleSort : public ArrayBase<type_array>
    {
    public:
        BubbleSort(Array<type_array> *&Array) : ArrayBase<type_array>(Array){};
        void start_sort();
    };

    template <typename type_array>
    class CocktailShakerSort : public ArrayBase<type_array>
    {
    public:
        CocktailShakerSort(Array<type_array> *&Array) : ArrayBase<type_array>(Array){};
        void start_sort();
    };

    //class OddevenSort{};

    //class CombSort{};

    //class GnomeSort{};

    template <typename type_array>
    class QuickSort : public ArrayBase<type_array>
    {
    public:
        QuickSort(Array<type_array> *&Array) : ArrayBase<type_array>(Array){};
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

    template <typename type_array>
    class HeapSort : public ArrayBase<type_array>
    {
    public:
        HeapSort(Array<type_array> *&Array) : ArrayBase<type_array>(Array){};
        void start_sort();

    private:
        void heapify(type_array *Array, const asize_t &count, const asize_t &array_size);
    };

    //class SmoothSort{};
}

namespace Insertion_Sorts
{
    template <typename type_array>
    class InsertSort : public ArrayBase<type_array>
    {
    public:
        InsertSort(Array<type_array> *&Array) : ArrayBase<type_array>(Array){};
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
    template <typename type_array>
    class MergeSort : public ArrayBase<type_array>
    {
    public:
        MergeSort(Array<type_array> *&Array) : ArrayBase<type_array>(Array){};
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
        CountingSort(Array<int> *&Array) : ArrayBase<int>(Array){};
        void start_sort();
    };

    //class BucketSort{};

    class RadixSort : public ArrayBase<int>
    {
    public:
        RadixSort(Array<int> *&Array) : ArrayBase<int>(Array){};
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

//ALGOR_ARRAY

enum ArrayStatus /// Set of array statuses
{
    SORTED,  ///< Indicates that the array is sorted
    UNSORTED ///< Indicates that the array is unsorted
};
enum ArrayType /// A set of array types
{
    NUMBER, ///< Indicates that the array stores numbers
    STRING  ///< Indicates that the array stores strings
};

template <typename type_array>
class ARRAYDATA : public ArrayBase<type_array>
{
public:
    ARRAYDATA(Array<type_array> *&Array);
    ARRAYDATA(const asize_t &SIZE);
    ARRAYDATA();

    void generatedData(const int &min_limit, const int &max_limit);
    void setNewData(Array<type_array> *&Array);
    void setData(Array<type_array> *&Array);
    void cloneData(Array<type_array> *&CloningArray);
    void cloneData(ARRAYDATA<type_array> *&CloningObject);
    void getData(Array<type_array> *&DATA);
    Array<type_array> *getData();

    void reset();
    void resize(const asize_t &NEW_SIZE, const type_array &setElement);
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

    void operator&&(const type_array &value);
    void operator!();
    void operator||(const type_array &value);
    void operator<<(ARRAYDATA<type_array> *&appendingArray);
    void operator>>(ARRAYDATA<type_array> *&appendingArray);
    void operator+(const asize_t &addSize);
    void operator-(const asize_t &subtractSize);
    void operator*(const asize_t &multiplySize);
    void operator/(const asize_t &divideSize);

private:
    void binary_searcher(const type_array &required_element, int &number_point, int left_limit, int right_limit);
};

//ALGOR_MATRIX

//ALGOR_HEAP

//ALGOR_LIST

//ALGOR_DOCUMENTATION

/*!
 * \class ARRAYDATA
 * \brief Array processing
 * \details This is the main class for working with arrays, the tasks of which
 *          are storing a pointer to an array, the ability to create, delete, modify it,
 *          calculate characteristics, etc.
 * \tparam type_array The type of elements that the array stores. For example int or float
 */
/*!
 * \fn ARRAYDATA<type_array>::ARRAYDATA(Array<type_array> *&Array) 
 * \brief Construct a new arraydata<type array>::arraydata object
 * \details With this creation of an object, both the structure and the object of the class will point to the same array
 * \tparam type_array The type of elements that the array stores. For example int or float
 * \param[in] Array Pointer to a structured array
 */
/*!
 * \fn ARRAYDATA<type_array>::ARRAYDATA(const asize_t &SIZE)
 * \brief Construct a new arraydata<type array>::arraydata object
 * \details With such an object creation, memory will be allocated for a new array, the pointer to which will be stored only in the class object
 * \tparam type_array The type of elements that the array stores. For example int or float
 * \param[in] SIZE The size of the array being created
 */
/*!
 * \fn ARRAYDATA<type_array>::ARRAYDATA()
 * \brief Construct a new arraydata<type array>::arraydata object
 * \details With this creation of an object, no memory will be allocated for the array. The object will be empty
 * \tparam type_array The type of elements that the array stores. For example int or float
 */
/*!
 * \fn void ARRAYDATA<type_array>::generatedData(const int &min_limit, const int &max_limit)
 * \brief A method that fills the entire array with random values
 * \tparam type_array The type of elements that the array stores. For example int or float
 * \param min_limit The minimum value that can be generated
 * \param max_limit The maximum value that can be generated
 */
/*!
 * \fn void ARRAYDATA<type_array>::setNewData(Array<type_array> *&Array)
 * \brief A method that replaces the previous array with a new one, freeing memory from the previous one
 * \tparam type_array The type of elements that the array stores. For example int or float
 * \param Array An array that will replace the previous one in the object
 */
/*!
 * \fn void ARRAYDATA<type_array>::setData(Array<type_array> *&Array)
 * \brief A method that replaces the previous array with a new one without freeing memory from the previous one
 * \tparam type_array The type of elements that the array stores. For example int or float
 * \param Array An array that will replace the previous one in the object
 */

#endif //ALGOR_HPP
