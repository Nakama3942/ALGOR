/* ******************************   ALGOR.hpp   ******************************* *
 * ---------------------------------------------------------------------------- *
 *                                                                              *
 * Copyright © 2021-2022 Kalynovsky Valentin. All rights reserved.              *
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
 *                              Version: 2.1.0-dev                              *
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
 *                                                                              *
 * ---------------------------------------------------------------------------- *
 * **************************************************************************** */

/*!
 * \file
 * \brief Library for processing arrays and sorting them
 * \author Kalynovsky Valentin
 * \version 2.1.0
 * \date 11.01.2022
 * \copyright Copyright © 2021-2022 Kalynovsky Valentin. All rights reserved. Licensed under the Apache License, Version 2.0 (the "License")
 */

#ifndef ALGOR_HPP
#define ALGOR_HPP

#include <ctime>

/* ****+/^^^/+++++-/&/-+-+-+-/&/-+-+-+-/&/-+-+-+-/&/-+-+-+-/&/-+++++/^^^/+**** *
 * #*****+/^^^/+++++-/+/-+-+                         +-+-/+/-+++++/^^^/+*****# *
 * #*-*%*-*+                                                         +*-*%*-*# *
 * %%%%%                       $------------------$                      %%%%% *
 * -->                              ALGOR_CORE                             <-- *
 * %%%%%                       $------------------$                      %%%%% *
 * #*-*%*-*+                                                         +*-*%*-*# *
 * #*****+/^^^/+++++-/+/-+-+                         +-+-/+/-+++++/^^^/+*****# *
 * ****+/^^^/+++++-/&/-+-+-+-/&/-+-+-+-/&/-+-+-+-/&/-+-+-+-/&/-+++++/^^^/+**** */

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

template <typename type_array>
class ArrayBase
{
public:
    ArrayBase(Array<type_array> *&Array);
    ArrayBase(const asize_t &SIZE);
    ArrayBase();

protected:
    Array<type_array> *ARRAY = nullptr; ///< Pointer to a structure storing an array
};

/* ****+/^^^/+++++-/&/-+-+-+-/&/-+-+-+-/&/-+-+-+-/&/-+-+-+-/&/-+++++/^^^/+**** *
 * #*****+/^^^/+++++-/+/-+-+                         +-+-/+/-+++++/^^^/+*****# *
 * #*-*%*-*+                                                         +*-*%*-*# *
 * %%%%%                      $-------------------$                      %%%%% *
 * -->                           ALGOR_EXCEPTION                           <-- *
 * %%%%%                      $-------------------$                      %%%%% *
 * #*-*%*-*+                                                         +*-*%*-*# *
 * #*****+/^^^/+++++-/+/-+-+                         +-+-/+/-+++++/^^^/+*****# *
 * ****+/^^^/+++++-/&/-+-+-+-/&/-+-+-+-/&/-+-+-+-/&/-+-+-+-/&/-+++++/^^^/+**** */

class Exception
{
public:
    Exception(unsigned int CODE, const char *DETAILS);
    Exception(unsigned int CODE);
    Exception(const char *DETAILS);
    unsigned int code();
    const char *what();

protected:
    unsigned int CODE;   ///< Exception encoding
    const char *DETAILS; ///< Exception details
};

class memory_overflow : public Exception
{
public:
    memory_overflow();
};

class position_failure : public Exception
{
public:
    position_failure();
};

class value_failure : public Exception
{
public:
    value_failure();
};

class void_data : public Exception
{
public:
    void_data();
};

class not_found : public Exception
{
public:
    not_found();
};

/* ****+/^^^/+++++-/&/-+-+-+-/&/-+-+-+-/&/-+-+-+-/&/-+-+-+-/&/-+++++/^^^/+**** *
 * #*****+/^^^/+++++-/+/-+-+                         +-+-/+/-+++++/^^^/+*****# *
 * #*-*%*-*+                                                         +*-*%*-*# *
 * %%%%%                       $------------------$                      %%%%% *
 * -->                             ALGOR_RANDOM                            <-- *
 * %%%%%                       $------------------$                      %%%%% *
 * #*-*%*-*+                                                         +*-*%*-*# *
 * #*****+/^^^/+++++-/+/-+-+                         +-+-/+/-+++++/^^^/+*****# *
 * ****+/^^^/+++++-/&/-+-+-+-/&/-+-+-+-/&/-+-+-+-/&/-+-+-+-/&/-+++++/^^^/+**** */

class RC4
{
public:
    //int crypto_entropy();
    void crypto_srand(const char *key, int ksize);
    void crypto_rand(char *output, int size);

private:
    uint8_t Sbox[256];
};

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

/* ****+/^^^/+++++-/&/-+-+-+-/&/-+-+-+-/&/-+-+-+-/&/-+-+-+-/&/-+++++/^^^/+**** *
 * #*****+/^^^/+++++-/+/-+-+                         +-+-/+/-+++++/^^^/+*****# *
 * #*-*%*-*+                                                         +*-*%*-*# *
 * %%%%%                      $-------------------$                      %%%%% *
 * -->                            ALGOR_SORTING                            <-- *
 * %%%%%                      $-------------------$                      %%%%% *
 * #*-*%*-*+                                                         +*-*%*-*# *
 * #*****+/^^^/+++++-/+/-+-+                         +-+-/+/-+++++/^^^/+*****# *
 * ****+/^^^/+++++-/&/-+-+-+-/&/-+-+-+-/&/-+-+-+-/&/-+-+-+-/&/-+++++/^^^/+**** */

template <class type_array> //NOTE Тут може бути й клас - треба тестувати
class Exchange_Sorts : public ArrayBase<type_array>
{
public:
	Exchange_Sorts(Array<type_array> *&Array) : ArrayBase<type_array>(Array){};
	void Bubble_Sort();
	void Cocktail_Shaker_Sort();
	void Odd_Even_Sort();
	void Comb_Sort();
	void Gnome_Sort();
	//void Propotion_Extend_Sort();
	void Quick_Sort();
	void Slow_Sort();
	void Stooge_Sort();
	void Bogo_Sort();
private:
	void Recursive_Quick_Sort(const int &left_limit, const int &right_limit);
	void Recursive_Slow_Sort(const int &left_limit, const int &right_limit);
	void Recursive_Stooge_Sort(const int &left_limit, const int &right_limit);
	bool Correct();
	void Shuffle();
};

namespace Selection_Sorts
{
	template <class type_array> //NOTE Скоріше тут буде тип - треба тестувати
	class SelectionSort
	{
	public:
		static void selection_sort(type_array *Array, int array_size)
		{
			for(int i = 0; i < array_size; i++)
			{
				int min_index = i;

				for(int j = i + 1; j < array_size; j++)
				{
					if(Array[j] < Array[min_index])
					{
						min_index = j;
					}
				}

				if(min_index != i)
				{
					swap<type_array>(Array[i], Array[min_index]);
				}
			}
		}
	};

    template <typename type_array>
    class HeapSort : public ArrayBase<type_array>
    {
    public:
        HeapSort(Array<type_array> *&Array) : ArrayBase<type_array>(Array){};
        void start_sort();

    private:
        void heapify(type_array *Array, const asize_t &count, const asize_t &array_size);
    };

	template <class type_array> //NOTE Скоріше тут буде тип - треба тестувати
	class SmoothSort
	{
	public:
		//Исходник: http://cppalgo.blogspot.com/2010/10/smoothsort.html
		SmoothSort(type_array *Array, int array_size)
		{
			this->Array = Array;
			this->array_size = array_size;
		}
		void smooth_sort()
		{
			make_heap_pool();

			for (int i = array_size - 1; i >= 0; i--)
			{
				int nextPosHeapItemsAmount;
				int posMaxTopElem = findPosMaxElem(curState, i, nextPosHeapItemsAmount);
				if (posMaxTopElem != i)
				{
					swap<type_array>(Array[i], Array[posMaxTopElem]);
					shiftDown(nextPosHeapItemsAmount, posMaxTopElem);
				}
				PrevState(curState);
			}
		}
	private:
		type_array *Array;
		int array_size;
		int LeoNum[44] = {1, 1, 3, 5, 9, 15, 25, 41, 67, 109, 177, 287, 465, 753, 1219, 1973, 3193, 5167, 8361, 13529, 21891, 35421, 57313, 92735, 150049, 242785, 392835, 635621, 1028457, 1664079, 2692537, 4356617, 7049155, 11405773, 18454929, 29860703, 48315633, 78176337, 126491971, 204668309, 331160281, 535828591, 866988873, 1402817465};
		int curState;
		int NextState(int &curState)
		{
			int posNewTop = -1;

			if ((curState & 7) == 5)
			{
				curState += 3;
				posNewTop = 3;
			}
			else
			{
				int next = curState;
				int pos = 0;
				while (next && (next & 3) != 3)
				{
					next >>= 1;
					pos++;
				}
				if ((next&3) == 3)
				{
					curState += 1 << pos;
					posNewTop = pos + 2;
				}
				else if (curState & 1)
				{
					curState |= 2;
				}
				else
				{
					curState |= 1;
				}
			}
			return posNewTop;
		}
		void PrevState(int &curState)
		{
			if ((curState & 15) == 8)
			{
				curState -= 3;
			}
			else if (curState & 1)
			{
				if ((curState & 3) == 3)
				{
					curState ^= 2;
				}
				else
				{
					curState ^= 1;
				}
			}
			else
			{
				int prev = curState;
				int pos = 0;
				while (prev && !(prev & 1))
				{
					prev >>= 1;
					pos++;
				}
				if (prev)
				{
					curState ^= 1 << pos;
					curState |= 1 << (pos - 1);
					curState |= 1 << (pos - 2);
				}
				else
				{
					curState = 0;
				}
			}
		}
		void shiftDown(int posHeapItemsAmount, int indexLastTop)
		{
			int posCurNode = indexLastTop;
			while (posHeapItemsAmount > 1)
			{
				int posR = posCurNode - 1;
				int posL = posR - LeoNum[posHeapItemsAmount-2];
				int posMaxChild = posL;
				int posNextTop = posHeapItemsAmount - 1;
				if (Array[posR] > Array[posL])
				{
					posMaxChild = posR;
					posNextTop = posHeapItemsAmount- 2;
				}
				if (Array[posCurNode] < Array[posMaxChild])
				{
					swap<type_array>(Array[posCurNode], Array[posMaxChild]);
					posHeapItemsAmount = posNextTop;
					posCurNode = posMaxChild;
				}
				else
				{
					break;
				}
			}
		}
		void make_heap_pool()
		{
			for (int i = 0; i < array_size; i++)
			{
				int posHeapItemsAmount = NextState(curState);
				if (posHeapItemsAmount != -1)
				{
					shiftDown(posHeapItemsAmount, i);
				}
			}
		}
		int findPosMaxElem(int curState, int indexLastTop, int &nextPosHeapItemsAmount)
		{
			int pos = 0;

			while (!(curState & 1))
			{
				curState >>= 1;
				pos++;
			}

			int posMaxTopElem = indexLastTop;
			nextPosHeapItemsAmount = pos;
			int curTopElem = indexLastTop - LeoNum[pos];
			curState >>= 1;
			pos++;

			while (curState)
			{
				if (curState & 1)
				{
					if (Array[curTopElem] > Array[posMaxTopElem])
					{
						posMaxTopElem = curTopElem;
						nextPosHeapItemsAmount = pos;
					}
					curTopElem -= LeoNum[pos];
				}
				curState >>= 1;
				pos++;
			}

			return posMaxTopElem;
		}
	};

	//class CartesianTreeSort{};

	//class TournamentSort

	//class CycleSort

	//class WeakHeapSort
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

	template <class type_array> //NOTE Скоріше тут буде тип - треба тестувати
	class ShellSort
	{
	public:
		static void shell_sort(type_array *Array, int array_size)
		{
			for (int step = array_size / 2; step > 0; step /= 2) {
				for (int i = step; i < array_size; i++)
				{
					for (int j = i - step; j >= 0 && Array[j] > Array[j + step]; j -= step)
					{
						swap<type_array>(Array[j], Array[j + step]);
					}
				}
			}
		}
	};

	//class SplaySort

	//class TreeSort{};

    //class LibrarySort{};

	//class PatienceSort{};
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

	//class CascadeMergeSort

	//class TreeSort{};

	//class OscillatingMergeSort

	//class PolyphaseMergeSort
}

namespace Distribution_Sort
{
	//class AmericanFlagSort

	//class BeadSort{};

	//class BucketSort{};

	//class BurstSort{};

    class CountingSort : public ArrayBase<int>
    {
    public:
        CountingSort(Array<int> *&Array) : ArrayBase<int>(Array){};
        void start_sort();
    };

	//class InterpolationSort

	//class PigeonholeSort{};

	//class ProxmapSort{};

    class RadixSort : public ArrayBase<int>
    {
    public:
        RadixSort(Array<int> *&Array) : ArrayBase<int>(Array){};
        void start_sort();
    };

	//class FlashSort{};
}

namespace Concurrent_Sort
{
	//class BitonicSorter{};

	//class BatcherOddEvenMergeSort{};

	//class PairwiseSortingNetwork{};

	//class SampleSort{};
}

namespace Hybrid_Sorts
{
	//class BlockMergeSort{};

	//class KirkpatrickReischSort

    //class TimSort{};

    //class IntroSort{};

    //class SpreadSort{};

	//class MergeInsertionSort{};
}

namespace Other_Sorts
{
	//class TopologicalSort{};

    //class PancakeSort{};

    //class SpaghettiSort{};
}

/* ****+/^^^/+++++-/&/-+-+-+-/&/-+-+-+-/&/-+-+-+-/&/-+-+-+-/&/-+++++/^^^/+**** *
 * #*****+/^^^/+++++-/+/-+-+                         +-+-/+/-+++++/^^^/+*****# *
 * #*-*%*-*+                                                         +*-*%*-*# *
 * %%%%%                      $-------------------$                      %%%%% *
 * -->                             ALGOR_ARRAY                             <-- *
 * %%%%%                      $-------------------$                      %%%%% *
 * #*-*%*-*+                                                         +*-*%*-*# *
 * #*****+/^^^/+++++-/+/-+-+                         +-+-/+/-+++++/^^^/+*****# *
 * ****+/^^^/+++++-/&/-+-+-+-/&/-+-+-+-/&/-+-+-+-/&/-+-+-+-/&/-+++++/^^^/+**** */

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
    ~ARRAYDATA();

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
    void remove();
    void binary_searcher(const type_array &required_element, int &number_point, int left_limit, int right_limit);
};

/* ****+/^^^/+++++-/&/-+-+-+-/&/-+-+-+-/&/-+-+-+-/&/-+-+-+-/&/-+++++/^^^/+**** *
 * #*****+/^^^/+++++-/+/-+-+                         +-+-/+/-+++++/^^^/+*****# *
 * #*-*%*-*+                                                         +*-*%*-*# *
 * %%%%%                       $------------------$                      %%%%% *
 * -->                             ALGOR_MATRIX                            <-- *
 * %%%%%                       $------------------$                      %%%%% *
 * #*-*%*-*+                                                         +*-*%*-*# *
 * #*****+/^^^/+++++-/+/-+-+                         +-+-/+/-+++++/^^^/+*****# *
 * ****+/^^^/+++++-/&/-+-+-+-/&/-+-+-+-/&/-+-+-+-/&/-+-+-+-/&/-+++++/^^^/+**** */

//class Matrix
//{
//public:
//    Matrix();
//protected:
//};

/* ****+/^^^/+++++-/&/-+-+-+-/&/-+-+-+-/&/-+-+-+-/&/-+-+-+-/&/-+++++/^^^/+**** *
 * #*****+/^^^/+++++-/+/-+-+                         +-+-/+/-+++++/^^^/+*****# *
 * #*-*%*-*+                                                         +*-*%*-*# *
 * %%%%%                       $------------------$                      %%%%% *
 * -->                              ALGOR_HEAP                             <-- *
 * %%%%%                       $------------------$                      %%%%% *
 * #*-*%*-*+                                                         +*-*%*-*# *
 * #*****+/^^^/+++++-/+/-+-+                         +-+-/+/-+++++/^^^/+*****# *
 * ****+/^^^/+++++-/&/-+-+-+-/&/-+-+-+-/&/-+-+-+-/&/-+-+-+-/&/-+++++/^^^/+**** */

//class Heap
//{
//public:
//    Heap();
//protected:
//};

/* ****+/^^^/+++++-/&/-+-+-+-/&/-+-+-+-/&/-+-+-+-/&/-+-+-+-/&/-+++++/^^^/+**** *
 * #*****+/^^^/+++++-/+/-+-+                         +-+-/+/-+++++/^^^/+*****# *
 * #*-*%*-*+                                                         +*-*%*-*# *
 * %%%%%                       $------------------$                      %%%%% *
 * -->                              ALGOR_LIST                             <-- *
 * %%%%%                       $------------------$                      %%%%% *
 * #*-*%*-*+                                                         +*-*%*-*# *
 * #*****+/^^^/+++++-/+/-+-+                         +-+-/+/-+++++/^^^/+*****# *
 * ****+/^^^/+++++-/&/-+-+-+-/&/-+-+-+-/&/-+-+-+-/&/-+-+-+-/&/-+++++/^^^/+**** */

//class List
//{
//public:
//    List();
//protected:
//};

#endif //ALGOR_HPP
