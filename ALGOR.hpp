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

//WARNING Перепровірити код, де у якості максимального значання задається
//0xffffffff, так як для int найменшим є 0x80000000, то число представляє собою
//-1 для типу int. Обов'язково необхідно перевірити код усюди, де використовуються
//шістнадцятковий код

#ifndef ALGOR_HPP
#define ALGOR_HPP

/* ****+/^^^/+++++-/&/-+-+-+-/&/-+-+-+-/&/-+-+-+-/&/-+-+-+-/&/-+++++/^^^/+**** *
 * #*****+/^^^/+++++-/+/-+-+                         +-+-/+/-+++++/^^^/+*****# *
 * #*-*%*-*+                                                         +*-*%*-*# *
 * %%%%%                       $------------------$                      %%%%% *
 * -->                               SETTINGS                              <-- *
 * %%%%%                       $------------------$                      %%%%% *
 * #*-*%*-*+                                                         +*-*%*-*# *
 * #*****+/^^^/+++++-/+/-+-+                         +-+-/+/-+++++/^^^/+*****# *
 * ****+/^^^/+++++-/&/-+-+-+-/&/-+-+-+-/&/-+-+-+-/&/-+-+-+-/&/-+++++/^^^/+**** */

#define STANDARDS_SWITCH 0

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
using memcell_t = long long;  //Тип, хранящий расчитаную ячейку памяти

memcell_t getMemoryCell(); //Заместо time(NULL)
memcell_t getMemoryCell(memcell_t right_adjust, memcell_t left_adjust);

template <typename type_array>
class Core
{
public:
	static void swap(type_array &firstNumber, type_array &secondNumber);
	static type_array minimum(const type_array *Array, const asize_t &array_size);
	static type_array minimum(type_array firstNumber, type_array secondNumber);
	static type_array maximum(const type_array *Array, const asize_t &array_size);
	static type_array maximum(type_array firstNumber, type_array secondNumber);
	static void addElement(type_array *&Array, asize_t &array_size, const type_array &value, const unsigned int position = 0);
	static void subtractElement(type_array *&Array, asize_t &array_size, const unsigned int position);
	static void subtractValue(type_array *&Array, asize_t &array_size, const type_array &value);
	static void copy(type_array *new_array, const type_array *old_array, const unsigned int &size_of_copied, unsigned int position_in_new_array = 0, unsigned int position_in_old_array = 0);
};

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

template <class type_array> // NOTE Тут може бути й клас - треба тестувати
class Insertion_Sorts : public ArrayBase<type_array>
{
public:
	Insertion_Sorts(Array<type_array> *&Array);
	void Insert_Sort();
	void Shell_Sort();
	void Tree_Sort();
	void Patience_Sort();

	class InsertSort
	{
	public:
		InsertSort(type_array *array, asize_t asize);
		void insert_sort();

	private:
		type_array *Array;
		asize_t array_size;
	};

	class ShellSort
	{
	public:
		ShellSort(type_array *array, asize_t asize);
		void shell_sort();

	private:
		type_array *Array;
		asize_t array_size;
	};

	class TreeSort
	{
	public:
		TreeSort(type_array *array, asize_t asize);
		void tree_sort();

	private:
		type_array *Array;
		asize_t array_size;

		struct Tree
		{
			int data;
			Tree *left, *right;
		};

		Tree *newnode(int key);
		Tree *insert(Tree *node, int key);
		void store(Tree *root, type_array *Array, asize_t &index);
	};

	class PatienceSort
	{
	public:
		PatienceSort(type_array *array, asize_t asize);
		void patience_sort();

	private:
		type_array *Array;
		asize_t array_size;

		asize_t *count, pickedRow;
		type_array **decks, *sortedArr, min;

		void initialization();
		void finalization();
	};
};

template <class type_array> // NOTE Тут може бути й клас - треба тестувати
class Merge_Sorts : public ArrayBase<type_array>
{
public:
	Merge_Sorts(Array<type_array> *&Array);
	void Merge_Sort();

	class MergeSort : public ArrayBase<type_array>
	{
	public:
		MergeSort(type_array *array, asize_t asize);
		void merge_sort();

	private:
		type_array *Array;
		asize_t array_size;

		void recursive_merge_sort(const asize_t &left_limit, const asize_t &right_limit);
		void merge(const asize_t &left_limit, const asize_t &middle_limit, const asize_t &right_limit);
	};
};

namespace Distribution_Sorts
{
	class AmericanFlagSort
	{
	public:
		//https://github.com/phishman3579/java-algorithms-implementation/blob/master/src/com/jwetherell/algorithms/sorts/AmericanFlagSort.java
		// WARNING Працює тільки з масивами типу int
		AmericanFlagSort(int *array, asize_t asize) : Array(array), array_size(asize) {}
		void american_flag_sort()
		{
			int numberOfDigits = getMaxNumberOfDigits(); // Max number of digits
			int max = 1;
			for (int i = 0; i < numberOfDigits - 1; i++)
			{
				max *= 10;
			}
			recursive_american_flag_sort(0, (int)array_size, max);
		}
	private:
		int *Array;
		asize_t array_size;

		const int NUMBER_OF_BUCKETS = 10; // 10 for base 10 numbers

		void recursive_american_flag_sort(int start, int length, int divisor)
		{
			int *count = new int[NUMBER_OF_BUCKETS]{0};
			int digit = 0;

			for (int i = start; i < (int)length; i++)
			{
				int array_digit = Array[i];
				digit = getDigit(array_digit, divisor);
				count[digit]++;
			}

			int *offset = new int[NUMBER_OF_BUCKETS];
			offset[0] = start + 0;
			for (int i = 1; i < NUMBER_OF_BUCKETS; i++)
			{
				offset[i] = count[i - 1] + offset[i - 1];
			}

			for (int b = 0; b < NUMBER_OF_BUCKETS; b++)
			{
				while (count[b] > 0)
				{
					int origin = offset[b];
					int from = origin;
					int num = Array[from];
					Array[from] = -1;
					do
					{
						digit = getDigit(num, divisor);
						int to = offset[digit]++;
						count[digit]--;
						int temp = Array[to];
						Array[to] = num;
						num = temp;
						from = to;
					} while (from != origin);
				}
			}
			if (divisor > 1)
			{
				for (int i = 0; i < NUMBER_OF_BUCKETS; i++)
				{
					int begin = (i > 0) ? offset[i - 1] : start;
					int end = offset[i];
					if (end - begin > 1)
					{
						recursive_american_flag_sort(begin, end, divisor / 10);
					}
				}
			}
		}
		int getMaxNumberOfDigits()
		{
			int count = 1;
			int value = Core<int>::maximum(Array, array_size);
			while(true)
			{
				value /= 10;
				if(value != 0)
				{
					count++;
				}
				else
				{
					break;
				}
			}
			return count;
		}
		int getDigit(int integer, int divisor)
		{
			return (integer / divisor) % 10;
		}
	};

	class BeadSort
	{
	public:
		// WARNING Працює тільки з масивами типу int
		BeadSort(int *array, asize_t asize) : Array(array), array_size(asize) {}
		void bead_sort()
		{
			max = Core<int>::maximum(Array, array_size);
			beads = new unsigned char[max * array_size]{0};

			for (asize_t i = 0; i < array_size; i++)
			{
				for (int j = 0; j < Array[i]; j++)
				{
					beads[i * max + j] = 1;
				}
			}
			for (int j = 0; j < max; j++)
			{
				int sum = 0;
				for (asize_t i = 0; i < array_size; i++)
				{
					sum += beads[i * max + j];
					beads[i * max + j] = 0;
				}
				for (asize_t i = array_size - sum; i < array_size; i++)
				{
					beads[i * max + j] = 1;
				}
			}
			for (asize_t i = 0; i < array_size; i++)
			{
				int j = 0;
				for (; j < max && beads[i * max + j]; j++)
					;
				Array[i] = j;
			}

			delete[] beads;
		}

	private:
		int *Array, max;
		asize_t array_size;

		unsigned char *beads;
	};

	template <class type_array> // NOTE Тут може бути й клас - треба тестувати
	class BucketSort
	{
	public:
		// https://github.com/TheAlgorithms/C-Plus-Plus/blob/master/sorting/bucket_sort.cpp
		BucketSort(type_array *array, asize_t asize) : Array(array), array_size(asize) {}
		void bucket_sort()
		{
			min = Core<type_array>::getMin(Array, array_size);
			max = Core<type_array>::getMax(Array, array_size);
			range = (max - min) / array_size;

			bucket = new type_array *[array_size];
			for (asize_t i = 0; i < array_size; i++)
			{
				bucket[i] = new type_array[1];
				bucket[i][0] = 1;
			}

			for (asize_t i = 0; i < array_size; i++)
			{
				bucket_index = asize_t((Array[i] - min) / range);
				if (bucket_index == array_size)
				{
					bucket_index--;
				}
				bucket[bucket_index] = push_back(bucket[bucket_index], Array[i]);
			}

			for (asize_t i = 0; i < array_size; i++)
			{
				if (bucket[i][0] > 2)
				{
					bubble_sort(bucket[i]);
				}
			}

			for (asize_t i = 0; i < array_size; i++)
			{
				for (asize_t j = 1; j < (asize_t)bucket[i][0]; j++)
				{
					Array[array_index++] = bucket[i][j];
				}
			}

			for (asize_t i = 0; i < array_size; i++)
			{
				delete[] bucket[i];
			}
			delete[] bucket;
		}

	private:
		type_array *Array, **bucket, min, max, range;
		asize_t array_size, bucket_index, array_index = 0;

		type_array *push_back(type_array *bucket, type_array value)
		{
			//Суть алгоритму наступна: я не можу створити структуру структур через
			//невиразну помилку, яка незрозуміло звідки береться (в інших місцях
			//коду все працює - воно не хоче тільки тут працювати чомусь) й
			//у окремих змінних зберігати не вийде, оскільки постає питання: скільки
			//їх потрібно? Отже треба буде оголошувати окремий масив для зберігання
			//розмірів кожного підмасиву. Це запарно, тому я вирішив вписати їх у
			//самі підмасиви (хоча потім може виникнути плутанина в інших місцях
			//коду). Так як люди рахують з одиниці, а комп'ютери з нуля - я вирішив
			//зберігати розмір у нульовій позиції, а так як для зберігання самого
			//розміру тепер теж потрібна пам'ять у масиві - він (розмір) завжди
			//буде більшим на одиницю. Наприклад, при розмірі масиву 6 там,
			//насправді, масив складається з 5 елементів.
			//Цей метод працює наступним чином: він дивиться розмір поданого
			//підмасиву й створює тимчасовий масив, розмір якого на одиницю більше
			//підмасиву; потім він (розмір) записується на нульове місце й так як у
			//підмасиві на 1 елемент менше, ніж було зазначено, зі збільшенням
			//тимчасово масиву різниця стане у два елементи. Тому для полегшення
			//розуміння коду я вирішив у циклі використовувати оригінальний
			//розмір, а під нульовим елементом можна уявити новий елемент. Тобто, у
			//масиві з 5 елементів (насправді їх 4) нульовий елемент можна замінити
			//новим й почати їх записувати у тимчасовий масив, який на одиницю
			//більше (насправді, він тепер вміщує тих самих 5 елементів),
			//починаючи не з нульового, а з першого номера. Що відбувається
			//насправді? Спочатку у тимчасовий масив зазначається його розмір,
			//потім на останню комірку заноситься нове значення й потім
			//переносяться всі інші елементи з підмасиву до тимчасового
			//масиву. Ось і все. Коли тимчасовий масив сформовано, пам'ять від
			//старого звільняється й повертається адреса на тимчасовий масив. Тепер
			//тимчасовий і є підмасивом. Все просто.
			type_array *temp = new type_array[bucket[0] + 1];
			temp[0] = bucket[0] + 1;
			for (asize_t i = 0; i < (asize_t)bucket[0]; i++)
			{
				i != 0 ? temp[i] = bucket[i] : temp[bucket[0]] = value;
			}
			delete[] bucket;
			return temp;
		}
		void bubble_sort(type_array *bucket)
		{
			// NOTE Тимчасова міра, пізніше я більш швидкий підключу та оптимізую
			for (asize_t i = 1; i < (asize_t)bucket[0] - 1; i++)
			{
				for (asize_t j = 1; j < (asize_t)bucket[0] - 1; j++)
				{
					if (bucket[j] > bucket[j + 1])
					{
						Core<type_array>::swap(bucket[j], bucket[j + 1]);
					}
				}
			}
		}
	};

	class CountingSort : public ArrayBase<int>
	{
	public:
		// WARNING Працює тільки з масивами типу int
		CountingSort(Array<int> *&Array) : ArrayBase<int>(Array){};
		void start_sort();
	};

	// class InterpolationSort

	template <class type_array> // NOTE Тут може бути й клас - треба тестувати
	class PigeonholeSort
	{
	public:
		// WARNING Не тестувався на float, але цей алгоритм знаходиться
		//у категорії, що підтримує тільки int значення
		PigeonholeSort(type_array *array, asize_t asize) : Array(array), array_size(asize) {}
		void pigeonhole_sort()
		{
			min = Core<type_array>::minimum(Array, array_size);
			max = Core<type_array>::maximum(Array, array_size);
			range = (asize_t)max - (asize_t)min + 1;
			hole = new type_array[range]{0};

			for (asize_t i = 0; i < array_size; i++)
			{
				hole[Array[i] - min] = Array[i];
			}
			for (asize_t i = 0; i < range; i++)
			{
				while (hole[i] != '\0')
				{
					Array[count] = hole[i];
					hole[i] = {};
					count++;
				}
			}
			delete[] hole;
		}

	private:
		type_array *Array, *hole, min, max;
		asize_t array_size, range, count = 0;
	};

	// class ProxmapSort{};

	class RadixSort : public ArrayBase<int>
	{
	public:
		// WARNING Працює тільки з масивами типу int
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
								Core<type_array>::swap(Array[i], Array[l]);
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

	template <class type_array> // NOTE Тут може бути й клас - треба тестувати
	class TimSort
	{
	public:
		TimSort(type_array *array, asize_t asize) : Array(array), array_size(asize) {}
		void tim_sort()
		{
			for (asize_t i = 0; i < array_size; i += RUN)
			{
				insertionSort(i, Core<asize_t>::minimum((i + 31), (array_size - 1)));
			}
			for (asize_t size = RUN; size < array_size; size *= 2)
			{
				for (asize_t left = 0; left < array_size; left += 2 * size)
				{
					asize_t middle = left + size - 1;
					asize_t right = Core<asize_t>::minimum((left + 2 * size - 1), (array_size - 1));
					merge(left, middle, right);
				}
			}
		}

	private:
		type_array *Array;
		asize_t array_size;

		const asize_t RUN = 32;

		void insertionSort(asize_t left_limit, asize_t right_limit)
		{
			for (asize_t i = left_limit + 1; i <= right_limit; i++)
			{
				type_array temp = Array[i];
				int j = i - 1;
				while (Array[j] > temp && j >= (int)left_limit)
				{
					Array[j + 1] = Array[j];
					j--;
				}
				Array[j + 1] = temp;
			}
		}
		void merge(asize_t left_limit, asize_t middle, asize_t right_limit)
		{
			asize_t len1 = middle - left_limit + 1, len2 = right_limit - middle;
			asize_t *left = new asize_t[len1], *right = new asize_t[len2];

			for (asize_t i = 0; i < len1; i++)
			{
				left[i] = Array[left_limit + i];
			}
			for (asize_t i = 0; i < len2; i++)
			{
				right[i] = Array[middle + 1 + i];
			}

			asize_t i = 0, j = 0, k = left_limit;

			while (i < len1 && j < len2)
			{
				if (left[i] <= right[j])
				{
					Array[k] = left[i];
					i++;
				}
				else
				{
					Array[k] = right[j];
					j++;
				}
				k++;
			}
			while (i < len1)
			{
				Array[k] = left[i];
				k++;
				i++;
			}
			while (j < len2)
			{
				Array[k] = right[j];
				k++;
				j++;
			}

			delete[] left;
			delete[] right;
		}
	};

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
				Core<type_array>::swap(Array[left], Array[index]);
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

/* ****+/^^^/+++++-/&/-+-+-+-/&/-+-+-+-/&/-+-+-+-/&/-+-+-+-/&/-+++++/^^^/+**** *
 * #*****+/^^^/+++++-/+/-+-+                         +-+-/+/-+++++/^^^/+*****# *
 * #*-*%*-*+                                                         +*-*%*-*# *
 * %%%%%                       $------------------$                      %%%%% *
 * -->                               STANDART                              <-- *
 * %%%%%                       $------------------$                      %%%%% *
 * #*-*%*-*+                                                         +*-*%*-*# *
 * #*****+/^^^/+++++-/+/-+-+                         +-+-/+/-+++++/^^^/+*****# *
 * ****+/^^^/+++++-/&/-+-+-+-/&/-+-+-+-/&/-+-+-+-/&/-+-+-+-/&/-+++++/^^^/+**** */

#if STANDARDS_SWITCH == 0
#pragma message("Compilation, which was conceived by the author")
#elif STANDARDS_SWITCH == 1
#pragma message("Compilation that includes the standard libraries")
#include <iterator>
using namespace std;

template <class type_array> // NOTE Тут може бути й клас - треба тестувати
class st_SortingAlgorithms : public ArrayBase<type_array>
{
public:
	st_SortingAlgorithms(Array<type_array> *&Array);
	void Library_Sort();

	// class ProportionExtendSort //Категорія Exchange_Sorts

	// class CartesianTreeSort //Категорія Selection_Sorts

	// class TournamentSort //Категорія Selection_Sorts

	// class WeakHeapSort //Категорія Selection_Sorts

	// class SplaySort //Категорія Insertion_Sorts

	class LibrarySort //Категорія Insertion_Sorts
	{
	public:
		LibrarySort(type_array *array, asize_t asize);
		void library_sort();

	private:
		type_array *Array;
		asize_t array_size;

		type_array *gaps, *library[2];
		asize_t lib_size = 0, index_pos = 0, insert, index_pos_for_output = 0;
		bool target_lib = false, *numbered;

		void initialization();
		void binarysearch();
		void insertion();
		void rebalancing();
		void finalization();
	};

	// class CascadeMergeSort //Категорія Merge_Sorts

	// class OscillatingMergeSort //Категорія Merge_Sorts

	// class PolyphaseMergeSort //Категорія Merge_Sorts

	// class BurstSort{}; //Категорія Distribution_Sorts
};

#endif // STANDARDS_SWITCH

#endif // ALGOR_HPP
