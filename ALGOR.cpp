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

/*!
 * \brief Swaps two elements
 * \tparam type_array The type of elements that the array stores. For example int or float
 * \param[in, out] firstNumber First item to replace
 * \param[in, out] secondNumber Second item to replace
 */
template <typename type_array> void swap(type_array &firstNumber, type_array &secondNumber)
{
    type_array *temp = new type_array(firstNumber);
    firstNumber = secondNumber;
    secondNumber = *temp;
    delete (temp);
}

/*!
 * \brief Finds the minimum element in an array by iterating over
 * \tparam type_array The type of elements that the array stores. For example int or float
 * \param[in] Array The array in which to look for the minimum element
 * \param[in] array_size The size of this very array
 * \return type_array
 */
template <typename type_array> type_array minimum(const type_array *Array, const asize_t &array_size)
{
    type_array point_min = Array[0];
    for (unsigned int i = 1; i < array_size; i++)
    {
        if (point_min > Array[i])
        {
            point_min = Array[i];
        }
    }
    return point_min;
}

/*!
 * \brief Finds the maximum element in an array by iterating over
 * \tparam type_array The type of elements that the array stores. For example int or float
 * \param[in] Array The array in which to look for the maximum element
 * \param[in] array_size The size of this very array
 * \return type_array
 */
template <typename type_array> type_array maximum(const type_array *Array, const asize_t &array_size)
{
    type_array point_max = Array[0];
    for (unsigned int i = 1; i < array_size; i++)
    {
        if (point_max < Array[i])
        {
            point_max = Array[i];
        }
    }
    return point_max;
}

/*!
 * \brief Adds a specific value to an array at a specified position
 * \tparam type_array The type of elements that the array stores. For example int or float
 * \param[in, out] Array The array to which the element is added
 * \param[in] array_size The size of this very array
 * \param[in] value The element to add to the array
 * \param[in] position The position at which the element will be added
 */
template <typename type_array> void addElement(type_array *&Array, asize_t &array_size, const type_array &value, const unsigned int position)
{
    array_size++;
    if (array_size == 1)
    {
        Array = new type_array[array_size]{value};
        return;
    }
    type_array *temp_Array = new type_array[array_size];
    for (unsigned int i = 0; i < array_size; i++)
    {
        position > i ? temp_Array[i] = Array[i] : (position == i ? temp_Array[i] = value : temp_Array[i] = Array[i - 1]);
    }
    delete[] Array;
    Array = new type_array[array_size];
    copy<type_array>(Array, temp_Array, array_size);
    delete[] temp_Array;
}

/*!
 * \brief Removes the specified position from the array
 * \tparam type_array The type of elements that the array stores. For example int or float
 * \param[in, out] Array The array in which the position will be deleted
 * \param[in] array_size The size of this very array
 * \param[in] position The position at which the element will be removed
 */
template <typename type_array> void subtractElement(type_array *&Array, asize_t &array_size, const unsigned int position)
{
    if (array_size == 1)
    {
        delete[] Array;
        return;
    }
    if (array_size == 0)
    {
        throw "Массив пустой";
    }
    if (position >= array_size)
    {
        throw "Удаляемая позиция отсутствует в массиве";
    }
    type_array *temp_Array = new type_array[array_size];
    for (unsigned int i = 0; i < array_size; i++)
    {
        position > i ? temp_Array[i] = Array[i] : (position < i ? temp_Array[i - 1] = Array[i] : 0);
    }
    delete[] Array;
    Array = new type_array[array_size--];
    copy<type_array>(Array, temp_Array, array_size);
    delete[] temp_Array;
}

/*!
 * \brief Removes a specific element from all positions in an array
 * \tparam type_array The type of elements that the array stores. For example int or float
 * \param[in, out] Array An array in which all elements that match the given value will be removed
 * \param[in] array_size The size of this very array
 * \param[in] value The value to be removed in the entire array
 */
template <typename type_array> void subtractValue(type_array *&Array, asize_t &array_size, const type_array &value)
{
    int counter = 0;
    type_array *temp_Array = new type_array[array_size];
    for (unsigned int i = 0; i < array_size; i++)
    {
        Array[i] != value ? temp_Array[i - counter] = Array[i] : counter++;
    }
    if (counter == 0)
    {
        delete[] temp_Array;
        throw "Указанный элемент отсутствует";
    }
    delete[] Array;
    array_size -= counter;
    Array = new type_array[array_size];
    copy<type_array>(Array, temp_Array, array_size);
    delete[] temp_Array;
}

/*!
 * \brief Copies an array
 * \tparam type_array The type of elements that the array stores. For example int or float
 * \param[in, out] new_array The array into which the data is copied
 * \param[in] old_array The array from which to copy
 * \param[in] size_of_copied A parameter that indicates how many items to copy
 * \param[in] position_in_new_array The position from which to start writing in the array to which the data is copied
 * \param[in] position_in_old_array The position from which to start reading from the array, from which the data is copied
 */
template <typename type_array> void copy(type_array *new_array, const type_array *old_array, const unsigned int &size_of_copied, unsigned int position_in_new_array, unsigned int position_in_old_array)
{
    for (unsigned int i = 0; i < size_of_copied; i++)
    {
        new_array[i + position_in_new_array] = old_array[i + position_in_old_array];
    }
}

/*!
 * \brief Creates a structure with a pointer to an array
 * \tparam type_array The type of elements that the array stores. For example int or float
 * \param[in] SIZE The size of the array to be created
 * \return Array<type_array>* Pointer to array
 */
template <typename type_array> Array<type_array> *create_struct(const asize_t &SIZE)
{
    Array<type_array> *ARRAY = new Array<type_array>;
    ARRAY->array_size = SIZE;
    ARRAY->array = new type_array[SIZE];
    return ARRAY;
}

/*!
 * \brief Removes an array and structure from heap
 * \tparam type_array The type of elements that the array stores. For example int or float
 * \param[in] Array The array to be deleted
 */
template <typename type_array> void remove_struct(Array<type_array> *&Array)
{
    delete[] Array->array;
    delete (Array);
    Array = nullptr;
}

/*!
 * \brief Construct a new ArrayBase<type_array>::ArrayBase object
 * \details With this creation of an object, both the structure and the object of the class will point to the same array
 * \tparam type_array The type of elements that the array stores. For example int or float
 * \param[in] Array Pointer to a structured array
 */
template<typename type_array> ArrayBase<type_array>::ArrayBase(Array<type_array> *&Array) : ARRAY(Array) {}

/*!
 * \brief Construct a new ArrayBase<type_array>::ArrayBase object
 * \details With such an object creation, memory will be allocated for a new array, the pointer to which will be stored only in the class object
 * \tparam type_array The type of elements that the array stores. For example int or float
 * \param[in] SIZE The size of the array being created
 */
template<typename type_array> ArrayBase<type_array>::ArrayBase(const asize_t &SIZE) { ARRAY = create_struct<type_array>(SIZE); }

/*!
 * \brief Construct a new ArrayBase<type_array>::ArrayBase object
 * \details With this creation of an object, no memory will be allocated for the array. The object will be empty
 * \tparam type_array The type of elements that the array stores. For example int or float
 */
template<typename type_array> ArrayBase<type_array>::ArrayBase() { ARRAY = nullptr; }

//int RC4::crypto_entropy()
//{
//    //Collects entropy
//    //WARNING Может быть реализован в Линуксе
//    return 0;
//}

/*!
 * \brief Set up the key
 * \param[in] key The key to be installed
 * \param[in] ksize Key size
 */
void RC4::crypto_srand(const char *key, int ksize)
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

/*!
 * \brief Generates a value
 * \param[out] output Generates an array of elements
 * \param[in] size Array size
 */
void RC4::crypto_rand(char *output, int size)
{
    uint8_t i = 0, j = 0, t;
    for (int k = 0; i < size; k++)
    {
        i += 1;
        j += Sbox[i];
        swap<uint8_t>(Sbox[i], Sbox[j]);
        t = Sbox[i] + Sbox[j];
        output[k] = (unsigned int)Sbox[t];
    }
}

/*!
 * \brief Construct a new Mersenne Twister::Mersenne Twister object
 * \details Installs the seed
 * \param[in] seed Generation seed
 */
MersenneTwister::MersenneTwister(int seed)
{
    RandomInit(seed);
    LastInterval = 0;
}

/*!
 * \brief Re-seed
 * \param seed Generation seed
 */
void MersenneTwister::RandomInit(int seed)
{
    Init0(seed);
    for (int i = 0; i < 37; i++)
    {
        BRandom();
    }
}

/*!
 * \brief Output random integer
 * \param min The minimum value that can be generated
 * \param max The maximum value that can be generated
 * \return int
 */
int MersenneTwister::IRandom(int min, int max)
{
    if (max <= min)
    {
        return max == min ? min : 0x80000000;
    }
    int rand_int = int((double)(uint32_t)(max - min + 1) * Random() + min);
    if (rand_int > max)
    {
        rand_int = max;
    }
    return rand_int;
}

/*!
 * \brief Output random integer, exact
 * \param min The minimum value that can be generated
 * \param max The maximum value that can be generated
 * \return int
 */
int MersenneTwister::IRandomX(int min, int max)
{
    if (max <= min)
    {
        return max == min ? min : 0x80000000;
    }
    uint32_t len_interval; //Length of interval
    uint64_t long_rbi;     //Random bits * interval
    uint32_t iran;         //long_rbi / 2^32
    uint32_t remainder;    //long_rbi % 2^32

    len_interval = uint32_t(max - min + 1);
    if (len_interval != LastInterval)
    {
        RejectionLimit = uint32_t(((uint64_t)1 << 32) / len_interval) * len_interval - 1;
        LastInterval = len_interval;
    }
    do
    {
        long_rbi = (uint64_t)BRandom() * len_interval;
        iran = (uint32_t)(long_rbi >> 32);
        remainder = (uint32_t)long_rbi;
    } while (remainder > RejectionLimit);
    return (int32_t)iran + min;
}

/*!
 * \brief Output random float
 * \return double
 */
double MersenneTwister::Random()
{
    return (double)BRandom() * (1. / (65536. * 65536.));
}

/*!
 * \brief Output random bits
 * \return uint32_t
 */
uint32_t MersenneTwister::BRandom()
{
    uint32_t resulting_bit;
    if (mersenne_twister_index >= 624)
    {
        const uint32_t LOWER_MASK = (1LU << 31) - 1;  //Lower bits
        const uint32_t UPPER_MASK = 0xFFFFFFFF << 31; //Upper bits
        static const uint32_t mask[2] = {0, 0x9908B0DF};
        int counter;
        for (counter = 0; counter < 624 - 397; counter++)
        {
            resulting_bit = (mersenne_twister[counter] & UPPER_MASK) | (mersenne_twister[counter + 1] & LOWER_MASK);
            mersenne_twister[counter] = mersenne_twister[counter + 397] ^ (resulting_bit >> 1) ^ mask[resulting_bit & 1];
        }
        for (; counter < 624 - 1; counter++)
        {
            resulting_bit = (mersenne_twister[counter] & UPPER_MASK) | (mersenne_twister[counter + 1] & LOWER_MASK);
            mersenne_twister[counter] = mersenne_twister[counter + (397 - 624)] ^ (resulting_bit >> 1) ^ mask[resulting_bit & 1];
        }
        resulting_bit = (mersenne_twister[624 - 1] & UPPER_MASK) | (mersenne_twister[0] & LOWER_MASK);
        mersenne_twister[624 - 1] = mersenne_twister[397 - 1] ^ (resulting_bit >> 1) ^ mask[resulting_bit & 1];
        mersenne_twister_index = 0;
    }
    resulting_bit = mersenne_twister[mersenne_twister_index++];
    resulting_bit ^= resulting_bit >> 11;
    resulting_bit ^= (resulting_bit << 7) & 0x9D2C5680;
    resulting_bit ^= (resulting_bit << 15) & 0xEFC60000;
    resulting_bit ^= resulting_bit >> 18;
    return resulting_bit;
}

void MersenneTwister::Init0(int seed)
{
    //Basic initialization procedure
    const uint32_t factor = 1812433253UL;
    mersenne_twister[0] = seed;
    for (mersenne_twister_index = 1; mersenne_twister_index < 624; mersenne_twister_index++)
    {
        mersenne_twister[mersenne_twister_index] = (factor * (mersenne_twister[mersenne_twister_index - 1] ^ (mersenne_twister[mersenne_twister_index - 1] >> 30)) + mersenne_twister_index);
    }
}

template <typename type_array> void Exchange_Sorts::BubbleSort<type_array>::start_sort()
{
    for (unsigned int i = 0; i < this->ARRAY->array_size; i++)
    {
        for (unsigned int j = 0; j < this->ARRAY->array_size - 1; j++)
        {
            if (this->ARRAY->array[j] > this->ARRAY->array[j + 1])
            {
                swap<type_array>(this->ARRAY->array[j], this->ARRAY->array[j + 1]);
            }
        }
    }
}

template <typename type_array> void Exchange_Sorts::CocktailShakerSort<type_array>::start_sort()
{
    int leftMark = 1, rightMark = this->ARRAY->array_size - 1;
    while (leftMark <= rightMark)
    {
        for (int i = rightMark; i >= leftMark; i--)
        {
            if (this->ARRAY->array[i - 1] > this->ARRAY->array[i])
            {
                swap<type_array>(this->ARRAY->array[i], this->ARRAY->array[i - 1]);
            }
        }
        leftMark++;
        for (int i = leftMark; i <= rightMark; i++)
        {
            if (this->ARRAY->array[i - 1] > this->ARRAY->array[i])
            {
                swap<type_array>(this->ARRAY->array[i], this->ARRAY->array[i - 1]);
            }
        }
        rightMark--;
    }
}

template <typename type_array> void Exchange_Sorts::QuickSort<type_array>::start_sort()
{
    quick_sort(0, this->ARRAY->array_size - 1);
}

template <typename type_array> void Exchange_Sorts::QuickSort<type_array>::quick_sort(const int &left_limit, const int &right_limit)
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
            swap<type_array>(this->ARRAY->array[start], this->ARRAY->array[finish]);
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

template <typename type_array> void Selection_Sorts::HeapSort<type_array>::start_sort()
{
    for (int right = this->ARRAY->array_size / 2 - 1; right >= 0; right--)
    {
        heapify(this->ARRAY->array, right, this->ARRAY->array_size);
    }
    for (int i = this->ARRAY->array_size - 1; i >= 0; i--)
    {
        swap<type_array>(this->ARRAY->array[0], this->ARRAY->array[i]);
        heapify(this->ARRAY->array, 0, i);
    }
}

template <typename type_array> void Selection_Sorts::HeapSort<type_array>::heapify(type_array *Array, const asize_t &count, const asize_t &array_size)
{
    asize_t left = 2 * count + 1, large = count, right = 2 * count + 2;
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
        swap<type_array>(Array[count], Array[large]);
        heapify(Array, large, array_size);
    }
}

template <typename type_array> void Insertion_Sorts::InsertSort<type_array>::start_sort()
{
    for (unsigned int i = 0; i < this->ARRAY->array_size; i++)
    {
        for (int j = i; j > 0 && this->ARRAY->array[j - 1] > this->ARRAY->array[j]; j--)
        {
            swap<type_array>(this->ARRAY->array[j - 1], this->ARRAY->array[j]);
        }
    }
}

template <typename type_array> void Merge_Sorts::MergeSort<type_array>::start_sort()
{
    merge_sort(this->ARRAY->array, 0, this->ARRAY->array_size - 1);
}

template <typename type_array> void Merge_Sorts::MergeSort<type_array>::merge_sort(type_array *Array, const int &left_limit, const int &right_limit)
{
    if (left_limit < right_limit)
    {
        int middle = left_limit + (right_limit - left_limit) / 2;
        merge_sort(Array, left_limit, middle);
        merge_sort(Array, middle + 1, right_limit);
        merge(Array, left_limit, middle, right_limit);
    }
}

template <typename type_array> void Merge_Sorts::MergeSort<type_array>::merge(type_array *Array, const int &left_limit, const int &middle_limit, const int &right_limit)
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

void Noncomparison_Sort::CountingSort::start_sort()
{
    int min = minimum<int>(ARRAY->array, ARRAY->array_size),
        max = maximum<int>(ARRAY->array, ARRAY->array_size);
    int *tempArray = new int[max - min + 1];
    for (int i = 0; i < max - min + 1; i++)
    {
        tempArray[i] = 0;
    }
    for (unsigned int i = 0; i < ARRAY->array_size; i++)
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
    int exp = 1, bit = 10, max = maximum<int>(ARRAY->array, ARRAY->array_size);
    int *tempArray = new int[ARRAY->array_size], *bucket = new int[bit];
    while (max / exp > 0)
    {
        for (int i = 0; i < bit; i++)
        {
            bucket[i] = 0;
        }
        for (unsigned int i = 0; i < ARRAY->array_size; i++)
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
        for (unsigned int i = 0; i < ARRAY->array_size; i++)
        {
            ARRAY->array[i] = tempArray[i];
        }
        exp *= bit;
    }
    delete[] bucket;
    delete[] tempArray;
}

/*!
 * \brief Construct a new arraydata<type array>::arraydata object
 * \details With this creation of an object, both the structure and the object of the class will point to the same array
 * \tparam type_array The type of elements that the array stores. For example int or float
 * \param[in] Array Pointer to a structured array
 */
template<typename type_array> ARRAYDATA<type_array>::ARRAYDATA(Array<type_array> *&Array) : ArrayBase<type_array>(Array) {}

/*!
 * \brief Construct a new arraydata<type array>::arraydata object
 * \details With such an object creation, memory will be allocated for a new array, the pointer to which will be stored only in the class object
 * \tparam type_array The type of elements that the array stores. For example int or float
 * \param[in] SIZE The size of the array being created
 */
template<typename type_array> ARRAYDATA<type_array>::ARRAYDATA(const asize_t &SIZE) : ArrayBase<type_array>(SIZE) {}

/*!
 * \brief Construct a new arraydata<type array>::arraydata object
 * \details With this creation of an object, no memory will be allocated for the array. The object will be empty
 * \tparam type_array The type of elements that the array stores. For example int or float
 */
template<typename type_array> ARRAYDATA<type_array>::ARRAYDATA() : ArrayBase<type_array>() {}

/*!
 * \brief A method that fills the entire array with random values
 * \tparam type_array The type of elements that the array stores. For example int or float
 * \param min_limit The minimum value that can be generated
 * \param max_limit The maximum value that can be generated
 */
template <typename type_array> void ARRAYDATA<type_array>::generatedData(const int &min_limit, const int &max_limit)
{
    RC4 rc4;
    //Key generation (will be used until I come up with an analogue of time(NULL))
    //TODO Think of an analogue time(NULL)
    char key[100];
    //rc4.crypto_entropy(key, 100);
    rc4.crypto_srand(key, 100);
    int BUFSIZe = 100;
    char output[BUFSIZe];
    rc4.crypto_rand(output, BUFSIZe);

    //Substitute the generated key
    MersenneTwister RanGen((uint8_t)output[50]);
    for (unsigned int i = 0; i < this->ARRAY->array_size; i++)
    {
        this->ARRAY->array[i] = RanGen.IRandom(min_limit, max_limit);
    }
}

/*!
 * \brief A method that replaces the previous array with a new one, freeing memory from the previous one
 * \tparam type_array The type of elements that the array stores. For example int or float
 * \param Array An array that will replace the previous one in the object
 */
template <typename type_array> void ARRAYDATA<type_array>::setNewData(Array<type_array> *&Array)
{
    remove();
    this->ARRAY = Array;
}

/*!
 * \brief A method that replaces the previous array with a new one without freeing memory from the previous one
 * \tparam type_array The type of elements that the array stores. For example int or float
 * \param Array An array that will replace the previous one in the object
 */
template <typename type_array> void ARRAYDATA<type_array>::setData(Array<type_array> *&Array)
{
    this->ARRAY = Array;
}

/*!
 * \brief Method that replaces the old array by copying the existing one
 * \tparam type_array The type of elements that the array stores. For example int or float
 * \param CloningArray The array to be copied to the object
 */
template <typename type_array> void ARRAYDATA<type_array>::cloneData(Array<type_array> *&CloningArray)
{
    if (this->ARRAY != nullptr)
    {
        remove();
    }
    this->ARRAY = create_struct<type_array>(CloningArray->array_size);
    copy<type_array>(this->ARRAY->array, CloningArray->array, CloningArray->array_size);
}

/*!
 * \brief A method that replaces an old array by copying an existing one from another object
 * \tparam type_array The type of elements that the array stores. For example int or float
 * \param CloningObject The object from which to copy the array
 */
template <typename type_array> void ARRAYDATA<type_array>::cloneData(ARRAYDATA<type_array> *&CloningObject)
{
    if (this->ARRAY != nullptr)
    {
        remove();
    }
    this->ARRAY = create_struct<type_array>(CloningObject->getData()->array_size);
    copy<type_array>(this->ARRAY->array, CloningObject->getData()->array, CloningObject->getData()->array_size);
}

/*!
 * \brief Gives a pointer to an array
 * \tparam type_array The type of elements that the array stores. For example int or float
 * \param DATA A pointer that will point to the array that is stored in the object
 */
template <typename type_array> void ARRAYDATA<type_array>::getData(Array<type_array> *&DATA)
{
    DATA = this->ARRAY;
}

/*!
 * \brief Returns a pointer to an array
 * \tparam type_array The type of elements that the array stores. For example int or float
 * \return Array<type_array>*
 */
template <typename type_array> Array<type_array> *ARRAYDATA<type_array>::getData()
{
    return this->ARRAY;
}

/*!
 * \brief The method removes the old array, creates a new one with the same characteristics
 *        (size, minimum and maximum limits) and fills it (unlike respawn (), which does
 *        not generate elements).
 * \tparam type_array The type of elements that the array stores. For example int or float
 */
template <typename type_array> void ARRAYDATA<type_array>::reset()
{
    int SIZE = this->ARRAY->array_size;
    type_array min = getMin(), max = getMax();
    remove();
    this->ARRAY = create_struct<type_array>(SIZE);
    generatedData(min, max);
}

/*!
 * \brief Method that resizes the array
 * \tparam type_array The type of elements that the array stores. For example int or float
 * \param NEW_SIZE New array size
 * \param setElement The value with which new cells of the array are filled
 * \warning In the case of increasing the size of the array after copying,
 *          the new cells remain empty and store "garbage" in themselves.
 *          Sometimes, by accident, a programmer can try to get data without
 *          specifying it, as a result of which, in the best case, an incorrect
 *          result will simply be given, and in the worst case, the program may crash.
 *          For this, the setElement parameter was created, but it must be specified
 *          not only in case of an increase in size, but always when calling the method
 *          for prevention. The programmer may not even know the current size
 *          of the array, therefore, he cannot know whether the array will
 *          be increased or decreased.
 */
template <typename type_array> void ARRAYDATA<type_array>::resize(const asize_t &NEW_SIZE, const type_array &setElement)
{
    Array<type_array> *OLD_ARRAY = this->ARRAY, *NEW_ARRAY = create_struct<type_array>(NEW_SIZE);
    if (OLD_ARRAY->array_size < NEW_ARRAY->array_size)
    {
        copy<type_array>(NEW_ARRAY->array, OLD_ARRAY->array, OLD_ARRAY->array_size);
        for (unsigned int i = OLD_ARRAY->array_size; i < NEW_ARRAY->array_size; i++)
        {
            NEW_ARRAY->array[i] = setElement;
        }
    }
    else
    {
        copy<type_array>(NEW_ARRAY->array, OLD_ARRAY->array, NEW_ARRAY->array_size);
    }
    this->ARRAY = NEW_ARRAY;
    remove_struct<type_array>(OLD_ARRAY);
}

/*!
 * \brief Changes the value at the specified position
 * \tparam type_array The type of elements that the array stores. For example int or float
 * \param position The position at which the value changes
 * \param value The value to be placed in the position
 */
template <typename type_array> void ARRAYDATA<type_array>::replace(const unsigned int &position, const type_array &value)
{
    this->ARRAY->array[position - 1] = value;
}

/*!
 * \brief Reverses the array
 * \tparam type_array The type of elements that the array stores. For example int or float
 */
template <typename type_array> void ARRAYDATA<type_array>::reverse()
{
    int left_limit = 0, right_limit = this->ARRAY->array_size - 1;
    for (unsigned int i = 0; i < this->ARRAY->array_size / 2; i++)
    {
        swap<type_array>(this->ARRAY->array[left_limit], this->ARRAY->array[right_limit]);
        left_limit++;
        right_limit--;
    }
}

/*!
 * \brief Removes an array
 * \tparam type_array The type of elements that the array stores. For example int or float
 */
template <typename type_array> void ARRAYDATA<type_array>::remove()
{
    remove_struct<type_array>(this->ARRAY);
}

/*!
 * \brief The method deletes the old array, however, the memory for the new array
 *        is allocated the same size without filling it, unlike reset()
 * \tparam type_array The type of elements that the array stores. For example int or float
 */
template <typename type_array> void ARRAYDATA<type_array>::respawn()
{
    unsigned int size = this->ARRAY->array_size;
    remove();
    this->ARRAY = create_struct<type_array>(size);
}

/*!
 * \brief Optimized method for finding the minimum element
 * \tparam type_array The type of elements that the array stores. For example int or float
 * \param ArrStat Array status
 * \return type_array
 */
template <typename type_array> type_array ARRAYDATA<type_array>::getMin(ArrayStatus ArrStat)
{
    switch (ArrStat)
    {
    case UNSORTED:
        return minimum<type_array>(this->ARRAY->array, this->ARRAY->array_size);
    case SORTED:
        return this->ARRAY->array[0];
    }
    throw -1;
}

/*!
 * \brief Optimized method for finding the maximum element
 * \tparam type_array The type of elements that the array stores. For example int or float
 * \param ArrStat Array status
 * \return type_array
 */
template <typename type_array> type_array ARRAYDATA<type_array>::getMax(ArrayStatus ArrStat)
{
    switch (ArrStat)
    {
    case UNSORTED:
        return maximum<type_array>(this->ARRAY->array, this->ARRAY->array_size);
    case SORTED:
        return this->ARRAY->array[this->ARRAY->array_size - 1];
    }
    throw -1;
}

/*!
 * \brief Linear item search method
 * \details Returns all occurrences of the found value
 * \tparam type_array The type of elements that the array stores. For example int or float
 * \param required_element The value to find
 * \return Array<int>*
 */
template <typename type_array> Array<int> *ARRAYDATA<type_array>::lenear_searcher(const type_array &required_element)
{
    Array<int> *NumberPoints = new Array<int>;
    for (unsigned int i = 0; i < this->ARRAY->array_size; i++)
    {
        if (required_element == this->ARRAY->array[i])
        {
            addElement<int>(NumberPoints->array, NumberPoints->array_size, i, NumberPoints->array_size);
        }
    }
    if (NumberPoints->array_size == 0)
    {
        throw -1;
    }
    return NumberPoints;
}

/*!
 * \brief Binary item search method
 * \details Returns only one position and is only used in sorted arrays
 * \tparam type_array The type of elements that the array stores. For example int or float
 * \param required_element The value to find
 * \return int
 */
template <typename type_array> int ARRAYDATA<type_array>::binary_searcher(const type_array &required_element)
{
    int position = 0;
    binary_searcher(required_element, position, 0, this->ARRAY->array_size - 1);
    return position;
}

template <typename type_array> void ARRAYDATA<type_array>::binary_searcher(const type_array &required_element, int &number_point, int left_limit, int right_limit)
{
    if (left_limit > right_limit)
    {
        throw -1;
    }
    int middle = left_limit + (right_limit - left_limit) / 2;
    if (this->ARRAY->array[middle] == required_element)
    {
        number_point = middle;
    }
    if (this->ARRAY->array[middle] > required_element)
    {
        binary_searcher(required_element, number_point, left_limit, middle - 1);
    }
    if (this->ARRAY->array[middle] < required_element)
    {
        binary_searcher(required_element, number_point, middle + 1, right_limit);
    }
}

/*!
 * \brief Sequence search method that returns all its occurrences
 * \tparam type_array The type of elements that the array stores. For example int or float
 * \param SUBARRAY The substring that is searched for in the main array
 * \param ArrType Array type
 * \return Array<int>*
 */
template <typename type_array> Array<int> *ARRAYDATA<type_array>::searcherOccurrencesOfSubstring(Array<type_array> *&SUBARRAY, ArrayType ArrType)
{
    Array<int> *Occurrences = new Array<int>;
    for (unsigned int i = 0; i <= this->ARRAY->array_size - SUBARRAY->array_size; i++)
    {
        for (unsigned int j = 0; j < SUBARRAY->array_size; j++)
        {
            if (this->ARRAY->array[i + j] == SUBARRAY->array[j])
            {
                switch (ArrType)
                {
                case NUMBER:
                    if (SUBARRAY->array_size - j == 1)
                    {
                        addElement<int>(Occurrences->array, Occurrences->array_size, i, Occurrences->array_size);
                    }
                    break;
                case STRING:
                    if (SUBARRAY->array_size - j == 2)
                    {
                        addElement<int>(Occurrences->array, Occurrences->array_size, i, Occurrences->array_size);
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
    return Occurrences;
}

/*!
 * \brief Method that returns the arithmetic mean of an array
 * \tparam type_array The type of elements that the array stores. For example int or float
 * \return type_array
 */
template <typename type_array> type_array ARRAYDATA<type_array>::average()
{
    if (this->ARRAY->array_size == 0)
    {
        throw "Массив пустой";
    }
    type_array average = 0;
    for (unsigned int i = 0; i < this->ARRAY->array_size; i++)
    {
        average += this->ARRAY->array[i];
    }
    return average / (type_array)this->ARRAY->array_size;
}

/*!
 * \brief Method that returns the median of an array
 * \tparam type_array The type of elements that the array stores. For example int or float
 * \return type_array
 */
template <typename type_array> type_array ARRAYDATA<type_array>::mediana()
{
    if (this->ARRAY->array_size == 0)
    {
        throw "Массив пустой";
    }
    return this->ARRAY->array_size % 2 == 0 ? (this->ARRAY->array[this->ARRAY->array_size / 2] + this->ARRAY->array[(this->ARRAY->array_size / 2) - 1]) / 2 : (this->ARRAY->array[this->ARRAY->array_size / 2]);
}

/*!
 * \brief Method that returns the array mode
 * \tparam type_array The type of elements that the array stores. For example int or float
 * \param highest_frequency An indicator of the frequency of occurrence of an element that is most often found
 * \return type_array
 */
template <typename type_array> type_array ARRAYDATA<type_array>::moda(int &highest_frequency)
{
    if (this->ARRAY->array_size == 0)
    {
        throw "Массив пустой";
    }
    type_array most_frequent = 0;
    highest_frequency = 0;
    int current_frequency = 0;
    for (unsigned int i = 0; i < this->ARRAY->array_size; i++)
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
    return most_frequent;
}

/*!
 * \brief A method that returns all elements with an array mode
 * \tparam type_array The type of elements that the array stores. For example int or float
 * \param highest_frequency An indicator of the frequency of occurrence of elements that are most often found
 * \return Array<type_array>*
 */
template <typename type_array> Array<type_array> *ARRAYDATA<type_array>::modas(int &highest_frequency)
{
    if (this->ARRAY->array_size == 0)
    {
        throw "Массив пустой";
    }
    Array<type_array> *MostFrequents = new Array<type_array>;
    highest_frequency = 0;
    int current_frequency = 0;
    type_array most_frequent = moda(highest_frequency);
    addElement<type_array>(MostFrequents->array, MostFrequents->array_size, most_frequent, MostFrequents->array_size);
    for (unsigned int i = 0; i < this->ARRAY->array_size; i++)
    {
        if (most_frequent == this->ARRAY->array[i])
        {
            for (unsigned int j = i + highest_frequency; j < this->ARRAY->array_size; j++)
            {
                current_frequency++;
                if (j == this->ARRAY->array_size - 1 || this->ARRAY->array[j] != this->ARRAY->array[j + 1])
                {
                    if (current_frequency == highest_frequency)
                    {
                        addElement<type_array>(MostFrequents->array, MostFrequents->array_size, this->ARRAY->array[j], MostFrequents->array_size);
                    }
                    current_frequency = 0;
                }
            }
            break;
        }
    }
    return MostFrequents;
}

/*!
 * \brief Operator adding an element to the end of an array
 * \tparam type_array The type of elements that the array stores. For example int or float
 * \param value The value to add to the end of the array
 */
template <typename type_array> void ARRAYDATA<type_array>::operator&&(const type_array &value)
{
    addElement<type_array>(this->ARRAY->array, this->ARRAY->array_size, value, this->ARRAY->array_size);
}

/*!
 * \brief Operator that removes an element from the end of an array
 * \tparam type_array The type of elements that the array stores. For example int or float
 */
template <typename type_array> void ARRAYDATA<type_array>::operator!()
{
    subtractElement<type_array>(this->ARRAY->array, this->ARRAY->array_size, this->ARRAY->array_size - 1);
}

/*!
 * \brief An operator that removes all elements with a specified value
 * \tparam type_array The type of elements that the array stores. For example int or float
 * \param value The value to be removed
 */
template <typename type_array> void ARRAYDATA<type_array>::operator||(const type_array &value)
{
    subtractValue<type_array>(this->ARRAY->array, this->ARRAY->array_size, value);
}

/*!
 * \brief Operator for merging two arrays in the current object
 * \tparam type_array The type of elements that the array stores. For example int or float
 * \param appendingArray An array to attach from another object
 */
template <typename type_array> void ARRAYDATA<type_array>::operator<<(ARRAYDATA<type_array> *&appendingArray)
{
    unsigned int newSize = this->ARRAY->array_size + appendingArray->getData()->array_size;
    Array<type_array> *temp = create_struct<type_array>(newSize);
    for (unsigned int i = 0; i < newSize; i++)
    {
        i < this->ARRAY->array_size ? temp->array[i] = this->ARRAY->array[i] : temp->array[i] = appendingArray->getData()->array[i - this->ARRAY->array_size];
    }
    remove();
    this->ARRAY = create_struct<type_array>(newSize);
    copy<type_array>(this->ARRAY->array, temp->array, newSize);
    remove_struct<type_array>(temp);
}

/*!
 * \brief Operator for merging two arrays in a received object
 * \tparam type_array The type of elements that the array stores. For example int or float
 * \param appendingArray An array from another object to which the current array will be passed
 */
template <typename type_array> void ARRAYDATA<type_array>::operator>>(ARRAYDATA<type_array> *&appendingArray)
{
    unsigned int newSize = this->ARRAY->array_size + appendingArray->getData()->array_size;
    Array<type_array> *temp = create_struct<type_array>(newSize);
    for (unsigned int i = 0; i < newSize; i++)
    {
        i < appendingArray->getData()->array_size ? temp->array[i] = appendingArray->getData()->array[i] : temp->array[i] = this->ARRAY->array[i - appendingArray->getData()->array_size];
    }
    appendingArray->resize(newSize, 1);
    copy<type_array>(appendingArray->getData()->array, temp->array, newSize);
    remove_struct<type_array>(temp);
}

//TODO Optimize operators + - * /

/*!
 * \brief Operator for increasing an array by a specific size
 * \tparam type_array The type of elements that the array stores. For example int or float
 * \param addSize Parameter indicating how much to increase the array
 */
template <typename type_array> void ARRAYDATA<type_array>::operator+(const asize_t &addSize)
{
    if (this->ARRAY->array_size + addSize > 0xffffffff)
    {
        throw "Переполнение памяти";
    }
    Array<type_array> *temp = create_struct<type_array>(this->ARRAY->array_size);
    copy<type_array>(temp->array, this->ARRAY->array, this->ARRAY->array_size);
    resize(temp->array_size + addSize, 1);
    copy<type_array>(this->ARRAY->array, temp->array, temp->array_size);
    remove_struct<type_array>(temp);
}

/*!
 * \brief Operator for decreasing an array by a specific size
 * \tparam type_array The type of elements that the array stores. For example int or float
 * \param subtractSize Parameter indicating how much to reduce the array
 */
template <typename type_array> void ARRAYDATA<type_array>::operator-(const asize_t &subtractSize)
{
    if (subtractSize >= this->ARRAY->array_size)
    {
        remove();
        return;
    }
    Array<type_array> *temp = create_struct<type_array>(this->ARRAY->array_size);
    copy<type_array>(temp->array, this->ARRAY->array, this->ARRAY->array_size);
    resize(temp->array_size - subtractSize, 1);
    copy<type_array>(this->ARRAY->array, temp->array, this->ARRAY->array_size);
    remove_struct<type_array>(temp);
}

/*!
 * \brief Operator for increasing an array by several times
 * \tparam type_array The type of elements that the array stores. For example int or float
 * \param multiplySize Parameter indicating how many times to increase the array
 */
template <typename type_array> void ARRAYDATA<type_array>::operator*(const asize_t &multiplySize)
{
    if (this->ARRAY->array_size * multiplySize > 0xffffffff)
    {
        throw "Переполнение памяти";
    }
    Array<type_array> *temp = create_struct<type_array>(this->ARRAY->array_size);
    copy<type_array>(temp->array, this->ARRAY->array, this->ARRAY->array_size);
    resize(temp->array_size * multiplySize, 1);
    copy<type_array>(this->ARRAY->array, temp->array, temp->array_size);
    remove_struct<type_array>(temp);
}

/*!
 * \brief Operator for decreasing an array by some times
 * \tparam type_array The type of elements that the array stores. For example int or float
 * \param divideSize Параметр, указывающий, во сколько раз следует уменьшить массив
 */
template <typename type_array> void ARRAYDATA<type_array>::operator/(const asize_t &divideSize)
{
    if (divideSize >= this->ARRAY->array_size)
    {
        remove();
        return;
    }
    Array<type_array> *temp = create_struct<type_array>(this->ARRAY->array_size);
    copy<type_array>(temp->array, this->ARRAY->array, this->ARRAY->array_size);
    resize(temp->array_size / divideSize, 1);
    copy<type_array>(this->ARRAY->array, temp->array, this->ARRAY->array_size);
    remove_struct<type_array>(temp);
}

template void swap<int>(int &, int &);
template void swap<float>(float &, float &);
template void swap<char>(char &, char &);

template int minimum<int>(const int *, const asize_t &);
template float minimum<float>(const float *, const asize_t &);
template char minimum<char>(const char *, const asize_t &);

template int maximum<int>(const int *, const asize_t &);
template float maximum<float>(const float *, const asize_t &);
template char maximum<char>(const char *, const asize_t &);

template void addElement<int>(int *&, asize_t &, const int &, const unsigned int);
template void addElement<float>(float *&, asize_t &, const float &, const unsigned int);
template void addElement<char>(char *&, asize_t &, const char &, const unsigned int);

template void subtractElement<int>(int *&, asize_t &, const unsigned int);
template void subtractElement<float>(float *&, asize_t &, const unsigned int);
template void subtractElement<char>(char *&, asize_t &, const unsigned int);

template void subtractValue<int>(int *&, asize_t &, const int &);
template void subtractValue<float>(float *&, asize_t &, const float &);
template void subtractValue<char>(char *&, asize_t &, const char &);

template void copy<int>(int *, const int *, const unsigned int &, unsigned int, unsigned int);
template void copy<float>(float *, const float *, const unsigned int &, unsigned int, unsigned int);
template void copy<char>(char *, const char *, const unsigned int &, unsigned int, unsigned int);

template Array<int> *create_struct<int>(const asize_t &);
template Array<float> *create_struct<float>(const asize_t &);
template Array<char> *create_struct<char>(const asize_t &);

template void remove_struct<int>(Array<int> *&);
template void remove_struct<float>(Array<float> *&);
template void remove_struct<char>(Array<char> *&);

template ArrayBase<int>::ArrayBase(Array<int> *&);
template ArrayBase<float>::ArrayBase(Array<float> *&);
template ArrayBase<char>::ArrayBase(Array<char> *&);

template ArrayBase<int>::ArrayBase(const asize_t &);
template ArrayBase<float>::ArrayBase(const asize_t &);
template ArrayBase<char>::ArrayBase(const asize_t &);

template ArrayBase<int>::ArrayBase();
template ArrayBase<float>::ArrayBase();
template ArrayBase<char>::ArrayBase();

template void Exchange_Sorts::BubbleSort<int>::start_sort();
template void Exchange_Sorts::BubbleSort<float>::start_sort();
template void Exchange_Sorts::BubbleSort<char>::start_sort();

template void Exchange_Sorts::CocktailShakerSort<int>::start_sort();
template void Exchange_Sorts::CocktailShakerSort<float>::start_sort();
template void Exchange_Sorts::CocktailShakerSort<char>::start_sort();

template void Exchange_Sorts::QuickSort<int>::start_sort();
template void Exchange_Sorts::QuickSort<float>::start_sort();
template void Exchange_Sorts::QuickSort<char>::start_sort();

template void Exchange_Sorts::QuickSort<int>::quick_sort(const int &, const int &);
template void Exchange_Sorts::QuickSort<float>::quick_sort(const int &, const int &);
template void Exchange_Sorts::QuickSort<char>::quick_sort(const int &, const int &);

template void Selection_Sorts::HeapSort<int>::start_sort();
template void Selection_Sorts::HeapSort<float>::start_sort();
template void Selection_Sorts::HeapSort<char>::start_sort();

template void Selection_Sorts::HeapSort<int>::heapify(int *, const asize_t &, const asize_t &);
template void Selection_Sorts::HeapSort<float>::heapify(float *, const asize_t &, const asize_t &);
template void Selection_Sorts::HeapSort<char>::heapify(char *, const asize_t &, const asize_t &);

template void Insertion_Sorts::InsertSort<int>::start_sort();
template void Insertion_Sorts::InsertSort<float>::start_sort();
template void Insertion_Sorts::InsertSort<char>::start_sort();

template void Merge_Sorts::MergeSort<int>::start_sort();
template void Merge_Sorts::MergeSort<float>::start_sort();
template void Merge_Sorts::MergeSort<char>::start_sort();

template void Merge_Sorts::MergeSort<int>::merge_sort(int *, const int &, const int &);
template void Merge_Sorts::MergeSort<float>::merge_sort(float *, const int &, const int &);
template void Merge_Sorts::MergeSort<char>::merge_sort(char *, const int &, const int &);

template void Merge_Sorts::MergeSort<int>::merge(int *, const int &, const int &, const int &);
template void Merge_Sorts::MergeSort<float>::merge(float *, const int &, const int &, const int &);
template void Merge_Sorts::MergeSort<char>::merge(char *, const int &, const int &, const int &);

template ARRAYDATA<int>::ARRAYDATA(Array<int> *&);
template ARRAYDATA<float>::ARRAYDATA(Array<float> *&);
template ARRAYDATA<char>::ARRAYDATA(Array<char> *&);

template ARRAYDATA<int>::ARRAYDATA(const asize_t &);
template ARRAYDATA<float>::ARRAYDATA(const asize_t &);
template ARRAYDATA<char>::ARRAYDATA(const asize_t &);

template ARRAYDATA<int>::ARRAYDATA();
template ARRAYDATA<float>::ARRAYDATA();
template ARRAYDATA<char>::ARRAYDATA();

template void ARRAYDATA<int>::generatedData(const int &, const int &);
template void ARRAYDATA<float>::generatedData(const int &, const int &);
template void ARRAYDATA<char>::generatedData(const int &, const int &);

template void ARRAYDATA<int>::setNewData(Array<int> *&);
template void ARRAYDATA<float>::setNewData(Array<float> *&);
template void ARRAYDATA<char>::setNewData(Array<char> *&);

template void ARRAYDATA<int>::setData(Array<int> *&);
template void ARRAYDATA<float>::setData(Array<float> *&);
template void ARRAYDATA<char>::setData(Array<char> *&);

template void ARRAYDATA<int>::cloneData(Array<int> *&);
template void ARRAYDATA<float>::cloneData(Array<float> *&);
template void ARRAYDATA<char>::cloneData(Array<char> *&);

template void ARRAYDATA<int>::cloneData(ARRAYDATA<int> *&);
template void ARRAYDATA<float>::cloneData(ARRAYDATA<float> *&);
template void ARRAYDATA<char>::cloneData(ARRAYDATA<char> *&);

template void ARRAYDATA<int>::getData(Array<int> *&);
template void ARRAYDATA<float>::getData(Array<float> *&);
template void ARRAYDATA<char>::getData(Array<char> *&);

template Array<int> *ARRAYDATA<int>::getData();
template Array<float> *ARRAYDATA<float>::getData();
template Array<char> *ARRAYDATA<char>::getData();

template void ARRAYDATA<int>::reset();
template void ARRAYDATA<float>::reset();
template void ARRAYDATA<char>::reset();

template void ARRAYDATA<int>::resize(const asize_t &, const int &);
template void ARRAYDATA<float>::resize(const asize_t &, const float &);
template void ARRAYDATA<char>::resize(const asize_t &, const char &);

template void ARRAYDATA<int>::replace(const unsigned int &, const int &);
template void ARRAYDATA<float>::replace(const unsigned int &, const float &);
template void ARRAYDATA<char>::replace(const unsigned int &, const char &);

template void ARRAYDATA<int>::reverse();
template void ARRAYDATA<float>::reverse();
template void ARRAYDATA<char>::reverse();

template void ARRAYDATA<int>::remove();
template void ARRAYDATA<float>::remove();
template void ARRAYDATA<char>::remove();

template void ARRAYDATA<int>::respawn();
template void ARRAYDATA<float>::respawn();
template void ARRAYDATA<char>::respawn();

template int ARRAYDATA<int>::getMin(ArrayStatus);
template float ARRAYDATA<float>::getMin(ArrayStatus);
template char ARRAYDATA<char>::getMin(ArrayStatus);

template int ARRAYDATA<int>::getMax(ArrayStatus);
template float ARRAYDATA<float>::getMax(ArrayStatus);
template char ARRAYDATA<char>::getMax(ArrayStatus);

template Array<int> *ARRAYDATA<int>::lenear_searcher(const int &);
template Array<int> *ARRAYDATA<float>::lenear_searcher(const float &);
template Array<int> *ARRAYDATA<char>::lenear_searcher(const char &);

template int ARRAYDATA<int>::binary_searcher(const int &);
template int ARRAYDATA<float>::binary_searcher(const float &);
template int ARRAYDATA<char>::binary_searcher(const char &);

template void ARRAYDATA<int>::binary_searcher(const int &, int &, int, int);
template void ARRAYDATA<float>::binary_searcher(const float &, int &, int, int);
template void ARRAYDATA<char>::binary_searcher(const char &, int &, int, int);

template Array<int> *ARRAYDATA<int>::searcherOccurrencesOfSubstring(Array<int> *&, ArrayType);
template Array<int> *ARRAYDATA<float>::searcherOccurrencesOfSubstring(Array<float> *&, ArrayType);
template Array<int> *ARRAYDATA<char>::searcherOccurrencesOfSubstring(Array<char> *&, ArrayType);

template int ARRAYDATA<int>::average();
template float ARRAYDATA<float>::average();
template char ARRAYDATA<char>::average();

template int ARRAYDATA<int>::mediana();
template float ARRAYDATA<float>::mediana();
template char ARRAYDATA<char>::mediana();

template int ARRAYDATA<int>::moda(int &);
template float ARRAYDATA<float>::moda(int &);
template char ARRAYDATA<char>::moda(int &);

template Array<int> *ARRAYDATA<int>::modas(int &);
template Array<float> *ARRAYDATA<float>::modas(int &);
template Array<char> *ARRAYDATA<char>::modas(int &);

template void ARRAYDATA<int>::operator&&(const int &);
template void ARRAYDATA<float>::operator&&(const float &);
template void ARRAYDATA<char>::operator&&(const char &);

template void ARRAYDATA<int>::operator!();
template void ARRAYDATA<float>::operator!();
template void ARRAYDATA<char>::operator!();

template void ARRAYDATA<int>::operator||(const int &);
template void ARRAYDATA<float>::operator||(const float &);
template void ARRAYDATA<char>::operator||(const char &);

template void ARRAYDATA<int>::operator<<(ARRAYDATA<int> *&);
template void ARRAYDATA<float>::operator<<(ARRAYDATA<float> *&);
template void ARRAYDATA<char>::operator<<(ARRAYDATA<char> *&);

template void ARRAYDATA<int>::operator>>(ARRAYDATA<int> *&);
template void ARRAYDATA<float>::operator>>(ARRAYDATA<float> *&);
template void ARRAYDATA<char>::operator>>(ARRAYDATA<char> *&);

template void ARRAYDATA<int>::operator+(const asize_t &);
template void ARRAYDATA<float>::operator+(const asize_t &);
template void ARRAYDATA<char>::operator+(const asize_t &);

template void ARRAYDATA<int>::operator-(const asize_t &);
template void ARRAYDATA<float>::operator-(const asize_t &);
template void ARRAYDATA<char>::operator-(const asize_t &);

template void ARRAYDATA<int>::operator*(const asize_t &);
template void ARRAYDATA<float>::operator*(const asize_t &);
template void ARRAYDATA<char>::operator*(const asize_t &);

template void ARRAYDATA<int>::operator/(const asize_t &);
template void ARRAYDATA<float>::operator/(const asize_t &);
template void ARRAYDATA<char>::operator/(const asize_t &);
