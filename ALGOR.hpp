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
 *                               Version: 2.2-dev                               *
 * ---------------------------------------------------------------------------- *
 * **************************************************************************** *
 * ---------------------------------------------------------------------------- *
 *                                                                              *
 *                              Project Structure:                              *
 * 1. SETTINGS - including components to compile                                *
 * 2. ALGOR_CORE - basic structures and functions of the library       (ALWAYS) *
 * 3. ALGOR_EXCEPTION - class for working with exceptions              (ALWAYS) *
 * 4. ALGOR_RANDOM - own random number generators                      (ALWAYS) *
 * 5. ALGOR_ARRAY - class for working with arrays                      (ARRAYS) *
 * 6. ALGOR_SORTING - sets of sorting methods                          (ARRAYS) *
 * 7. ALGOR_MATRIX - class for working with matrices        (ADDITION & MATRIX) *
 * 8. ALGOR_HEAP - class for working with trees               (ADDITION & HEAP) *
 * 9. ALGOR_LIST - class for working with lists               (ADDITION & LIST) *
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

// WARNING Перепровірити код, де у якості максимального значання задається
// 0xffffffff, так як для int найменшим є 0x80000000, то число представляє собою
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

#define ARRAYS 1

#define ADDITION 0
#define MATRIX 0
#define HEAP 0
#define LIST 0

#define STANDARDS_SWITCH 0

namespace ALGOR
{
	/* ****+/^^^/+++++-/&/-+-+-+-/&/-+-+-+-/&/-+-+-+-/&/-+-+-+-/&/-+++++/^^^/+**** *
	 * #*****+/^^^/+++++-/+/-+-+                         +-+-/+/-+++++/^^^/+*****# *
	 * #*-*%*-*+                                                         +*-*%*-*# *
	 * %%%%%                       $------------------$                      %%%%% *
	 * -->                              ALGOR_CORE                             <-- *
	 * %%%%%                       $------------------$                      %%%%% *
	 * #*-*%*-*+                                                         +*-*%*-*# *
	 * #*****+/^^^/+++++-/+/-+-+                         +-+-/+/-+++++/^^^/+*****# *
	 * ****+/^^^/+++++-/&/-+-+-+-/&/-+-+-+-/&/-+-+-+-/&/-+-+-+-/&/-+++++/^^^/+**** */

	using sbit8_t = signed char;			///< Alias for signed char
	using sbit16_t = signed short;			///< Alias for signed short
	using sbit32_t = signed long;			///< Alias for signed long
	using sbit64_t = signed long long;		///< Alias for signed long long

	using ubit8_t = unsigned char;			///< Alias for unsigned char
	using ubit16_t = unsigned short;		///< Alias for unsigned short
	using ubit32_t = unsigned long;			///< Alias for unsigned long
	using ubit64_t = unsigned long long;	///< Alias for unsigned long long

	using fbit32_t = float;					///< Alias for float
	using fbit64_t = double;				///< Alias for double

	using asize_t = unsigned long;			///< Alias for specifying the type "array size"
	using memcell_t = unsigned long long;	///< Alias for calculated memory cell

	template <typename type_value>
	void swap(type_value &firstNumber, type_value &secondNumber);
	template <typename type_value>
	type_value minimum(type_value firstNumber, type_value secondNumber);
	template <typename type_value>
	type_value maximum(type_value firstNumber, type_value secondNumber);

	memcell_t getMemoryCell(); //Заместо time(NULL)
	memcell_t getMemoryCell(memcell_t right_adjust, memcell_t left_adjust);

	template <typename type>
	class Printer // Template interface
	{
	public:
		virtual void print() = 0;
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
		unsigned int CODE;		///< Exception encoding
		const char *DETAILS;	///< Exception details
	};

	class memory_overflow : public Exception
	{
	public:
		memory_overflow();
	};

	class division_by_zero : public Exception
	{
	public:
		division_by_zero();
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
		ubit8_t Sbox[256];
	};

	class MersenneTwister
	{
	public:
		MersenneTwister(int seed);
		void RandomInit(int seed);
		int IRandom(int min, int max);
		int IRandomX(int min, int max);
		double Random();
		ubit32_t BRandom();

	private:
		void Init0(int seed);
		ubit32_t mersenne_twister[624]; // State vector
		int mersenne_twister_index;		// Index into mersenne_twister
		ubit32_t LastInterval;			// Last interval length for IRandomX
		ubit32_t RejectionLimit;		// Rejection limit used by IRandomX
	};

#if ARRAYS == 1
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
	class ArrayProcessing
	{
	public:
		static type_array minimum(const type_array *Array,
								  const asize_t &array_size);
		static type_array maximum(const type_array *Array,
								  const asize_t &array_size);
		static bool isOrderliness(const type_array *Array,
								  const asize_t &array_size);
		static void addElement(type_array *&Array,
							   asize_t &array_size,
							   const type_array &value,
							   const unsigned int position = 0);
		static void subtractElement(type_array *&Array,
									asize_t &array_size,
									const unsigned int position);
		static void subtractValue(type_array *&Array,
								  asize_t &array_size,
								  const type_array &value);
		static void copy(type_array *new_array,
						 const type_array *old_array,
						 const unsigned int &size_of_copied,
						 unsigned int position_in_new_array = 0,
						 unsigned int position_in_old_array = 0);
	};

	template <typename type_array>
	struct Array
	{
		type_array *array = nullptr;
		asize_t array_size = 0;
	};
	template <typename type_array>
	Array<type_array> *create_struct(const asize_t &SIZE);
	template <typename type_array>
	void remove_struct(Array<type_array> *&Array);

	template <typename type_array>
	class ArrayBase
	{
	protected:
		ArrayBase(Array<type_array> *&Array);
		ArrayBase(const asize_t &SIZE);
		ArrayBase();

		Array<type_array> *ARRAY = nullptr; ///< Pointer to a structure storing an array
	};

	template <typename type_array>
	class ARRAYDATA : public ArrayBase<type_array>
	{
	public:
		ARRAYDATA(Array<type_array> *&Array);
		ARRAYDATA(const asize_t &SIZE);
		~ARRAYDATA();

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

		type_array getMin();
		type_array getMax();

		Array<int> *lenear_searcher(const type_array &required_element);
		int binary_searcher(const type_array &required_element);
		Array<int> *searcherOccurrencesOfSubstring(Array<type_array> *&SUBARRAY,
												   ArrayType ArrType = ArrayType::NUMBER);

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
		void binary_searcher(const type_array &required_element,
							 int &number_point,
							 int left_limit,
							 int right_limit);
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

	template <typename type_array>
	class Comparative_Sorts : public ArrayBase<type_array>
	{
	public:
		Comparative_Sorts(Array<type_array> *&Array);
		// <<==		Категорія Exchange_Sorts	==>>
		void Bubble_Sort();			// №	 2
		void Cocktail_Shaker_Sort();	// №	 3
		void Odd_Even_Sort();			// №	10
		void Comb_Sort();				// №	 4
		void Gnome_Sort();				// №	 6
		void Quick_Sort();				// №	12
		void Slow_Sort();				// №	15
		void Stooge_Sort();			// №	17
		void Bogo_Sort();				// №	 1
		// <<==		Категорія Selection_Sorts	==>>
		void Selection_Sort();			// №	13
		void Heap_Sort();				// №	 7
		void Smooth_Sort();			// №	16 //FIXME на момент тесту все одно не сортує
		void Cycle_Sort();				// №	 5
		// <<==		Категорія Insertion_Sorts	==>>
		void Insert_Sort();			// №	 8
		void Shell_Sort();				// №	14
		void Tree_Sort();				// №	18
		void Patience_Sort();			// №	11
		// <<==		Категорія Merge_Sorts		==>>
		void Merge_Sort();				// №	 9
		// <<==				Classes				==>>
		class BogoSort //Категорія Exchange_Sorts
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

		class BubbleSort //Категорія Exchange_Sorts
		{
		public:
			BubbleSort(type_array *array, asize_t asize);
			void bubble_sort();

		private:
			type_array *Array;
			asize_t array_size;
		};

		class CocktailShakerSort //Категорія Exchange_Sorts
		{
		public:
			CocktailShakerSort(type_array *array, asize_t asize);
			void cocktail_shaker_sort();

		private:
			type_array *Array;
			asize_t array_size;
		};

		class CombSort //Категорія Exchange_Sorts
		{
		public:
			CombSort(type_array *array, asize_t asize);
			void comb_sort();

		private:
			type_array *Array;
			asize_t array_size;
		};

		class CycleSort //Категорія Selection_Sorts
		{
		public:
			CycleSort(type_array *array, asize_t asize);
			void cycle_sort();

		private:
			type_array *Array;
			asize_t array_size;
		};

		class GnomeSort //Категорія Exchange_Sorts
		{
		public:
			GnomeSort(type_array *array, asize_t asize);
			void gnome_sort();

		private:
			type_array *Array;
			asize_t array_size;
		};

		class HeapSort //Категорія Selection_Sorts
		{
		public:
			HeapSort(type_array *array, asize_t asize);
			void heap_sort();

		private:
			type_array *Array;
			asize_t array_size;
			void heapify(type_array *Array,
						 const asize_t &count,
						 const asize_t &array_size);
		};

		class InsertSort //Категорія Insertion_Sorts
		{
		public:
			InsertSort(type_array *array, asize_t asize);
			void insert_sort();

		private:
			type_array *Array;
			asize_t array_size;
		};

		class MergeSort //Категорія Merge_Sorts
		{
		public:
			MergeSort(type_array *array, asize_t asize);
			void merge_sort();

		private:
			type_array *Array;
			asize_t array_size;

			void recursive_merge_sort(const asize_t &left_limit,
									  const asize_t &right_limit);
			void merge(const asize_t &left_limit,
					   const asize_t &middle_limit,
					   const asize_t &right_limit);
		};

		class OddEvenSort //Категорія Exchange_Sorts
		{
		public:
			OddEvenSort(type_array *array, asize_t asize);
			void odd_even_sort();

		private:
			type_array *Array;
			asize_t array_size;
		};

		class PatienceSort //Категорія Insertion_Sorts
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

		class QuickSort //Категорія Exchange_Sorts
		{
		public:
			QuickSort(type_array *array, asize_t asize);
			void quick_sort();

		private:
			type_array *Array;
			asize_t array_size;
			void recursive_quick_sort(const int &left_limit,
									  const int &right_limit);
		};

		class SelectionSort //Категорія Selection_Sorts
		{
		public:
			SelectionSort(type_array *array, asize_t asize);
			void selection_sort();

		private:
			type_array *Array;
			asize_t array_size;
		};

		class ShellSort //Категорія Insertion_Sorts
		{
		public:
			ShellSort(type_array *array, asize_t asize);
			void shell_sort();

		private:
			type_array *Array;
			asize_t array_size;
		};

		class SlowSort //Категорія Exchange_Sorts
		{
		public:
			SlowSort(type_array *array, asize_t asize);
			void slow_sort();

		private:
			type_array *Array;
			asize_t array_size;
			void recursive_slow_sort(const int &left_limit,
									 const int &right_limit);
		};

		class StoogeSort //Категорія Exchange_Sorts
		{
		public:
			StoogeSort(type_array *array, asize_t asize);
			void stooge_sort();

		private:
			type_array *Array;
			asize_t array_size;
			void recursive_stooge_sort(const int &left_limit,
									   const int &right_limit);
		};

		class TreeSort //Категорія Insertion_Sorts
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

	private:
		class SmoothSort //Категорія Selection_Sorts
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
			int LeoNum[44] = {1, 1, 3, 5, 9, 15, 25, 41, 67, 109, 177, 287, 465,
							  753, 1219, 1973, 3193, 5167, 8361, 13529, 21891,
							  35421, 57313, 92735, 150049, 242785, 392835, 635621,
							  1028457, 1664079, 2692537, 4356617, 7049155, 11405773,
							  18454929, 29860703, 48315633, 78176337, 126491971,
							  204668309, 331160281, 535828591, 866988873, 1402817465};
			int curState;
			void make_heap_pool();
			int NextState(int &curState);
			void shiftDown(int posHeapItemsAmount,
						   int indexLastTop);
			int findPosMaxElem(int curState,
							   int indexLastTop,
							   int &nextPosHeapItemsAmount);
			void PrevState(int &curState);
		};
	};

	class Distribution_Sorts : public ArrayBase<int>
	{
	public:
		Distribution_Sorts(Array<int> *&Array);
		void AmericanFlag_Sort();		// №	1
		void Bead_Sort();				// №	2
		void Bucket_Sort();			// №	3
		void Counting_Sort();			// №	4
		void Flash_Sort();				// №	5
		void Interpolation_Sort();	// №	6
		void Pigeonhole_Sort();		// №	7
		void Radix_Sort();				// №	8

		class AmericanFlagSort
		{
		public:
			// https://github.com/phishman3579/java-algorithms-implementation/blob/master/src/com/jwetherell/algorithms/sorts/AmericanFlagSort.java
			AmericanFlagSort(int *array, asize_t asize);
			void american_flag_sort();

		private:
			int *Array;
			asize_t array_size;

			const int NUMBER_OF_BUCKETS = 10; // 10 for base 10 numbers

			void recursive_american_flag_sort(int start,
											  int length,
											  int divisor);
			int getMaxNumberOfDigits();
			int getDigit(int integer, int divisor);
		};

		class BeadSort
		{
		public:
			BeadSort(int *array, asize_t asize);
			void bead_sort();

		private:
			int *Array, max;
			asize_t array_size;

			unsigned char *beads;
		};

		class BucketSort
		{
		public:
			// https://github.com/TheAlgorithms/C-Plus-Plus/blob/master/sorting/bucket_sort.cpp
			BucketSort(int *array, asize_t asize);
			void bucket_sort();

		private:
			int *Array, **bucket, min, max, range;
			asize_t array_size, bucket_index, array_index = 0;

			void push_back(int *&bucket, const int &value);
			void bubble_sort(int *bucket);
		};

		class CountingSort
		{
		public:
			CountingSort(int *array, asize_t asize);
			void counting_sort();

		private:
			int *Array, *tempArray, min, max;
			asize_t array_size;
		};

		class FlashSort
		{
		public:
			// https://javascript.algorithmexamples.com/web/Sorts/flashSort.html
			FlashSort(int *array, asize_t asize);
			void flash_sort();

		private:
			int *Array, *L, flash;
			asize_t array_size, min = 0, max = 0, move = 0, j = 0, k;
		};

		class InterpolationSort
		{
		public:
			// https://github.com/aniketsatarkar/Sorting-Algorithms-in-C/blob/master/InterpolationSort.h
			InterpolationSort(int *array, asize_t asize);
			void interpolation_sort();

		private:
			int *Array;
			asize_t array_size;

			const asize_t MIN_SORTABLE_LENGTH = 128;

			int ifac, temp;
			int nArray_min, nArray_max, index_min;
			int *space, *cmp_index, *cum, *hist, *sorted;
			int ComplexityCount = 0;

			void getMin();
			void getMax();
		};

		class PigeonholeSort
		{
		public:
			PigeonholeSort(int *array, asize_t asize);
			void pigeonhole_sort();

		private:
			int *Array, **hole, min, max;
			asize_t array_size, range, count = 0;

			void push_back(int *&hole, const int &value);
		};

		class RadixSort
		{
		public:
			RadixSort(int *array, asize_t asize);
			void radix_sort();

		private:
			int *Array, *tempArray, *bucket, exp = 1, bit = 10, max, current;
			asize_t array_size;
		};
	};

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
									swap<int>(Array[i], Array[l]);
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
					insertionSort(i, minimum<asize_t>((i + 31), (array_size - 1)));
				}
				for (asize_t size = RUN; size < array_size; size *= 2)
				{
					for (asize_t left = 0; left < array_size; left += 2 * size)
					{
						asize_t middle = left + size - 1;
						asize_t right = minimum<asize_t>((left + 2 * size - 1), (array_size - 1));
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
					swap<type_array>(Array[left], Array[index]);
					index--;
					left++;
				}
			}
		};

		// class SpaghettiSort{};
	}
#endif // ARRAYS

#if ADDITION == 1

#if MATRIX == 1
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
#endif // MATRIX

#if HEAP == 1
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
#endif // HEAP

#if LIST == 1
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
#endif // LIST

#endif // ADDITION
} // ALGOR namespace end

#if STANDARDS_SWITCH == 1

/* ****+/^^^/+++++-/&/-+-+-+-/&/-+-+-+-/&/-+-+-+-/&/-+-+-+-/&/-+++++/^^^/+**** *
 * #*****+/^^^/+++++-/+/-+-+                         +-+-/+/-+++++/^^^/+*****# *
 * #*-*%*-*+                                                         +*-*%*-*# *
 * %%%%%                       $------------------$                      %%%%% *
 * -->                               STANDART                              <-- *
 * %%%%%                       $------------------$                      %%%%% *
 * #*-*%*-*+                                                         +*-*%*-*# *
 * #*****+/^^^/+++++-/+/-+-+                         +-+-/+/-+++++/^^^/+*****# *
 * ****+/^^^/+++++-/&/-+-+-+-/&/-+-+-+-/&/-+-+-+-/&/-+-+-+-/&/-+++++/^^^/+**** */

#include <iterator>
using namespace std;

template <class type_array> // NOTE Тут може бути й клас - треба тестувати
class st_SortingAlgorithms : public ALGOR::ArrayBase<type_array>
{
public:
	st_SortingAlgorithms(ALGOR::Array<type_array> *&Array);
	void Library_Sort();

	// class ProportionExtendSort //Категорія Exchange_Sorts

	// class CartesianTreeSort //Категорія Selection_Sorts

	// class TournamentSort //Категорія Selection_Sorts

	// class WeakHeapSort //Категорія Selection_Sorts

	// class SplaySort //Категорія Insertion_Sorts

	class LibrarySort //Категорія Insertion_Sorts
	{
	public:
		LibrarySort(type_array *array, ALGOR::asize_t asize);
		void library_sort();

	private:
		type_array *Array;
		ALGOR::asize_t array_size;

		type_array *gaps, *library[2];
		ALGOR::asize_t lib_size = 0, index_pos = 0, insert, index_pos_for_output = 0;
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

	// class ProxmapSort{}; //Категорія Distribution_Sorts
};
#endif // STANDARDS_SWITCH

#endif // ALGOR_HPP
