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
using int16_t = short;		///< Alias for short
using int32_t = int;		///< Alias for int
using int64_t = long long;	///< Alias for long long

using uint8_t = unsigned char;		 ///< Alias for unsigned char
using uint16_t = unsigned short;	 ///< Alias for unsigned short
using uint32_t = unsigned int;		 ///< Alias for unsigned int
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
	unsigned int CODE;	 ///< Exception encoding
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
	// int crypto_entropy();
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
	uint32_t mersenne_twister[624]; // State vector
	int mersenne_twister_index;		// Index into mersenne_twister
	uint32_t LastInterval;			// Last interval length for IRandomX
	uint32_t RejectionLimit;		// Rejection limit used by IRandomX
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

template <class type_array> // NOTE Тут може бути й клас - треба тестувати
class Exchange_Sorts : public ArrayBase<type_array>
{
public:
	Exchange_Sorts(Array<type_array> *&Array);
	void Bubble_Sort();
	void Cocktail_Shaker_Sort();
	void Odd_Even_Sort();
	void Comb_Sort();
	void Gnome_Sort();
	void Quick_Sort();
	void Slow_Sort();
	void Stooge_Sort();
	void Bogo_Sort();

	class BubbleSort
	{
	public:
		BubbleSort(type_array *array, asize_t asize);
		void bubble_sort();

	private:
		type_array *Array;
		asize_t array_size;
	};

	class CocktailShakerSort
	{
	public:
		CocktailShakerSort(type_array *array, asize_t asize);
		void cocktail_shaker_sort();

	private:
		type_array *Array;
		asize_t array_size;
	};

	class OddEvenSort
	{
	public:
		OddEvenSort(type_array *array, asize_t asize);
		void odd_even_sort();

	private:
		type_array *Array;
		asize_t array_size;
	};

	class CombSort
	{
	public:
		CombSort(type_array *array, asize_t asize);
		void comb_sort();

	private:
		type_array *Array;
		asize_t array_size;
	};

	class GnomeSort
	{
	public:
		GnomeSort(type_array *array, asize_t asize);
		void gnome_sort();

	private:
		type_array *Array;
		asize_t array_size;
	};

	class QuickSort
	{
	public:
		QuickSort(type_array *array, asize_t asize);
		void quick_sort();

	private:
		type_array *Array;
		asize_t array_size;
		void recursive_quick_sort(const int &left_limit, const int &right_limit);
	};

	class SlowSort
	{
	public:
		SlowSort(type_array *array, asize_t asize);
		void slow_sort();

	private:
		type_array *Array;
		asize_t array_size;
		void recursive_slow_sort(const int &left_limit, const int &right_limit);
	};

	class StoogeSort
	{
	public:
		StoogeSort(type_array *array, asize_t asize);
		void stooge_sort();

	private:
		type_array *Array;
		asize_t array_size;
		void recursive_stooge_sort(const int &left_limit, const int &right_limit);
	};

	class BogoSort
	{
	public:
		BogoSort(type_array *array, asize_t asize);
		void bogo_sort();

	private:
		type_array *Array;
		asize_t array_size;
		bool Correct();
		void Shuffle();
	};
};

template <class type_array> // NOTE Тут може бути й клас - треба тестувати
class Selection_Sorts : public ArrayBase<type_array>
{
public:
	Selection_Sorts(Array<type_array> *&Array);
	void Selection_Sort();
	void Heap_Sort();
	void Smooth_Sort();
	void Cycle_Sort();

	class SelectionSort
	{
	public:
		SelectionSort(type_array *array, asize_t asize);
		void selection_sort();

	private:
		type_array *Array;
		asize_t array_size;
	};

	class HeapSort
	{
	public:
		HeapSort(type_array *array, asize_t asize);
		void heap_sort();

	private:
		type_array *Array;
		asize_t array_size;
		void heapify(type_array *Array, const asize_t &count, const asize_t &array_size);
	};

	class CycleSort
	{
	public:
		CycleSort(type_array *array, asize_t asize);
		void cycle_sort();

	private:
		type_array *Array;
		asize_t array_size;
	};

private:
	class SmoothSort
	{
	public:
		//Сирці: http://cppalgo.blogspot.com/2010/10/smoothsort.html
		// WARNING Алгоритм не хоче працювати при динамічному виділенні пам'яті:
		//з'являється помилка сегментації, а при статичному оголошенні все працює.
		//Щоб користувач Не міг динамічно оголосити об'єкт даного класу, я вимушено
		//закрив цей клас, щоб його можна було використати тільки через метод
		//зовнішнього класу
		// WARNING Алгоритм протестовано тільки на масиві з int числами. З іншими
		//типами алгоритм може не працювати
		SmoothSort(type_array *array, int asize);
		void smooth_sort();

	private:
		type_array *Array;
		int array_size;
		int LeoNum[44] = {1, 1, 3, 5, 9, 15, 25, 41, 67, 109, 177, 287, 465, 753, 1219, 1973, 3193, 5167, 8361, 13529, 21891, 35421, 57313, 92735, 150049, 242785, 392835, 635621, 1028457, 1664079, 2692537, 4356617, 7049155, 11405773, 18454929, 29860703, 48315633, 78176337, 126491971, 204668309, 331160281, 535828591, 866988873, 1402817465};
		int curState;
		void make_heap_pool();
		int NextState(int &curState);
		void shiftDown(int posHeapItemsAmount, int indexLastTop);
		int findPosMaxElem(int curState, int indexLastTop, int &nextPosHeapItemsAmount);
		void PrevState(int &curState);
	};
};

namespace Insertion_Sorts
{
	template <typename type_array>
	class InsertSort : public ArrayBase<type_array>
	{
	public:
		InsertSort(Array<type_array> *&Array) : ArrayBase<type_array>(Array){};
		void start_sort();
	};

	template <class type_array> // NOTE Скоріше тут буде тип - треба тестувати
	class ShellSort
	{
	public:
		static void shell_sort(type_array *Array, int array_size)
		{
			for (int step = array_size / 2; step > 0; step /= 2)
			{
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

	template <class type_array> // NOTE Тут може бути й клас - треба тестувати
	class TreeSort
	{
	public:
		static void tree_sort(type_array *Array, int array_size)
		{
			Tree *root = nullptr;
			root = insert(root, Array[0]);
			for (int i = 1; i < array_size; i++)
			{
				insert(root, Array[i]);
			}
			int index = 0;
			store(root, Array, index);
		}

	private:
		struct Tree
		{
			int data;
			Tree *left, *right;
		};
		static Tree *newnode(int key)
		{
			Tree *temp = new Tree;
			temp->data = key;
			temp->left = nullptr;
			temp->right = nullptr;
			return temp;
		}
		static Tree *insert(Tree *node, int key)
		{
			if (node == nullptr)
			{
				return newnode(key);
			}
			if (key < node->data)
			{
				node->left = insert(node->left, key);
			}
			else
			{
				node->right = insert(node->right, key);
			}
			return node;
		}
		static void store(Tree *root, int *Array, int &index)
		{
			if (root != nullptr)
			{
				store(root->left, Array, index);
				Array[index++] = root->data;
				store(root->right, Array, index);
			}
		}
	};

	// class LibrarySort{};

	template <class type_array> // NOTE Тут може бути й клас - треба тестувати
	class PatienceSort
	{
	public:
		static void patience_sort(type_array *Array, int array_size)
		{
			int *count = new int[array_size]{0}, pickedRow;
			type_array **decks = new type_array *[array_size], *sortedArr = new type_array[array_size], min;
			for (int i = 0; i < array_size; i++)
			{
				decks[i] = new type_array[array_size];
			}

			for (int i = 0; i < array_size; i++)
			{
				for (int j = 0; j < array_size; j++)
				{
					if (count[j] == 0 || (count[j] > 0 && decks[j][count[j] - 1] >= Array[i]))
					{
						decks[j][count[j]] = Array[i];
						count[j]++;
						break;
					}
				}
			}

			min = decks[0][count[0] - 1];
			pickedRow = 0;

			for (int i = 0; i < array_size; i++)
			{
				for (int j = 0; j < array_size; j++)
				{
					if (count[j] > 0 && decks[j][count[j] - 1] < min)
					{
						min = decks[j][count[j] - 1];
						pickedRow = j;
					}
				}
				sortedArr[i] = min;
				count[pickedRow]--;

				for (int j = 0; j < array_size; j++)
				{
					if (count[j] > 0)
					{
						min = decks[j][count[j] - 1];
						pickedRow = j;
						break;
					}
				}
			}

			for (int i = 0; i < array_size; i++)
			{
				Array[i] = sortedArr[i];
			}

			delete[] sortedArr;
			for (int i = 0; i < array_size; i++)
			{
				delete[] decks[i];
			}
			delete[] decks;
			delete[] count;
		}
	};
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

	// class CascadeMergeSort

	// class OscillatingMergeSort

	// class PolyphaseMergeSort
}

namespace Distribution_Sort
{
	// class AmericanFlagSort

	// class BeadSort{};

	// class BucketSort{};

	// class BurstSort{};

	class CountingSort : public ArrayBase<int>
	{
	public:
		CountingSort(Array<int> *&Array) : ArrayBase<int>(Array){};
		void start_sort();
	};

	// class InterpolationSort

	// class PigeonholeSort{};

	// class ProxmapSort{};

	class RadixSort : public ArrayBase<int>
	{
	public:
		RadixSort(Array<int> *&Array) : ArrayBase<int>(Array){};
		void start_sort();
	};

	// class FlashSort{};
}

namespace Concurrent_Sort
{
	template <class type_array> // NOTE Тут може бути й клас - треба тестувати
	class BitonicSorter
	{
	public:
		static void bitonic_sorter(type_array *Array, int array_size)
		{
			for (int k = 2; k <= array_size; k *= 2)
			{
				for (int j = k / 2; j > 0; j /= 2)
				{
					for (int i = 0; i < array_size; i++)
					{
						int l = i ^ j;
						if (l > i)
						{
							if ((((i & k) == 0) && (Array[i] > Array[l])) || (((i & k) != 0) && (Array[i] < Array[l])))
							{
								swap<type_array>(Array[i], Array[l]);
							}
						}
					}
				}
			}
		}
	};

	// class BatcherOddEvenMergeSort{};

	// class PairwiseSortingNetwork{};

	// class SampleSort{};
}

namespace Hybrid_Sorts
{
	// class BlockMergeSort{};

	// class KirkpatrickReischSort

	// class TimSort{};

	// class IntroSort{};

	// class SpreadSort{};

	// class MergeInsertionSort{};
}

namespace Other_Sorts
{
	// class TopologicalSort{};

	template <class type_array> // NOTE Тут може бути й клас - треба тестувати
	class PancakeSort
	{
	public:
		static void pancake_sort(type_array *Array, int array_size)
		{
			while (array_size > 1)
			{
				int maxIndex = max_index(Array, array_size);
				flip(Array, maxIndex);
				flip(Array, array_size - 1);
				array_size--;
			}
		}

	private:
		static int max_index(type_array *Array, int array_size)
		{
			int index = 0;
			for (int i = 0; i < array_size; i++)
			{
				if (Array[index] < Array[i])
				{
					index = i;
				}
			}
			return index;
		}
		static void flip(type_array *Array, int index)
		{
			int left = 0;
			while (left < index)
			{
				swap<type_array>(Array[left], Array[index]);
				index--;
				left++;
			}
		}
	};

	// class SpaghettiSort{};
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

template <typename type_array>
class ARRAYDATA : public ArrayBase<type_array>
{
public:
	ARRAYDATA(Array<type_array> *&Array);
	ARRAYDATA(const asize_t &SIZE);
	~ARRAYDATA();

	enum class ArrayStatus /// Set of array statuses
	{
		SORTED,	 ///< Indicates that the array is sorted
		UNSORTED ///< Indicates that the array is unsorted
	};
	enum class ArrayType /// A set of array types
	{
		NUMBER, ///< Indicates that the array stores numbers
		STRING	///< Indicates that the array stores strings
	};

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

	type_array getMin(ArrayStatus ArrStat = ArrayStatus::UNSORTED);
	type_array getMax(ArrayStatus ArrStat = ArrayStatus::UNSORTED);

	Array<int> *lenear_searcher(const type_array &required_element);
	int binary_searcher(const type_array &required_element);
	Array<int> *searcherOccurrencesOfSubstring(Array<type_array> *&SUBARRAY, ArrayType ArrType = ArrayType::NUMBER);

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

// class Matrix
//{
// public:
//     Matrix();
// protected:
// };

/* ****+/^^^/+++++-/&/-+-+-+-/&/-+-+-+-/&/-+-+-+-/&/-+-+-+-/&/-+++++/^^^/+**** *
 * #*****+/^^^/+++++-/+/-+-+                         +-+-/+/-+++++/^^^/+*****# *
 * #*-*%*-*+                                                         +*-*%*-*# *
 * %%%%%                       $------------------$                      %%%%% *
 * -->                              ALGOR_HEAP                             <-- *
 * %%%%%                       $------------------$                      %%%%% *
 * #*-*%*-*+                                                         +*-*%*-*# *
 * #*****+/^^^/+++++-/+/-+-+                         +-+-/+/-+++++/^^^/+*****# *
 * ****+/^^^/+++++-/&/-+-+-+-/&/-+-+-+-/&/-+-+-+-/&/-+-+-+-/&/-+++++/^^^/+**** */

// class Heap
//{
// public:
//     Heap();
// protected:
// };

/* ****+/^^^/+++++-/&/-+-+-+-/&/-+-+-+-/&/-+-+-+-/&/-+-+-+-/&/-+++++/^^^/+**** *
 * #*****+/^^^/+++++-/+/-+-+                         +-+-/+/-+++++/^^^/+*****# *
 * #*-*%*-*+                                                         +*-*%*-*# *
 * %%%%%                       $------------------$                      %%%%% *
 * -->                              ALGOR_LIST                             <-- *
 * %%%%%                       $------------------$                      %%%%% *
 * #*-*%*-*+                                                         +*-*%*-*# *
 * #*****+/^^^/+++++-/+/-+-+                         +-+-/+/-+++++/^^^/+*****# *
 * ****+/^^^/+++++-/&/-+-+-+-/&/-+-+-+-/&/-+-+-+-/&/-+-+-+-/&/-+++++/^^^/+**** */

// class List
//{
// public:
//     List();
// protected:
// };

#endif // ALGOR_HPP
