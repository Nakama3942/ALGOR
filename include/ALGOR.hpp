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
 *                               Version: 1.0.0.0                               *
 * ---------------------------------------------------------------------------- *
 * **************************************************************************** *
 * ---------------------------------------------------------------------------- *
 *                                                                              *
 *                              Project Structure:                              *
 * 1. ALGOR_CORE		-> basic structures and functions of the library        *
 * 2. ALGOR_EXCEPTION	-> class for working with exceptions                    *
 * 3. ALGOR_RANDOM		-> own random number generators                         *
 * 4. ALGOR_ARRAY		-> class for working with arrays                        *
 * 5. ALGOR_SORTING		-> sets of sorting methods                              *
 * 6. ALGOR_MATRIX		-> class for working with matrices                      *
 * 7. ALGOR_HEAP		-> class for working with trees                         *
 * 8. ALGOR_LIST		-> class for working with lists                         *
 *                                                                              *
 * ---------------------------------------------------------------------------- *
 * **************************************************************************** */

/*!
  \file
  \brief Бібліотека для обробки та сортування структур даних
  \author Калиновський Валентин
  \version 1.0.0.0
  \date 11.01.2022
  \copyright Copyright © 2021-2022 Kalynovsky Valentin. All rights reserved.
  Licensed under the Apache License, Version 2.0 (the "License")

  \todo розділ ALGOR_MATRIX
  \todo розділ ALGOR_HEAP
  \todo розділ ALGOR_LIST
 */

// TODO Переписати CHANGELOG.md
// TODO Перекласти документацію на англійську мову
// WARNING Дату написания документации указать тогда, когда будет написана документация

#ifndef ALGOR_HPP
#define ALGOR_HPP

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

	using byte1_t = char;
	using byte2_t = short;
	using byte4_t = long;
	using byte8_t = long long;

	using sbit8_t = signed char;
	using sbit16_t = signed short;
	using sbit32_t = signed long;
	using sbit64_t = signed long long;

	using ubit8_t = unsigned char;
	using ubit16_t = unsigned short;
	using ubit32_t = unsigned long;
	using ubit64_t = unsigned long long;

	using fbit32_t = float;
	using fbit64_t = double;
	using fbit128_t = long double;

	using asize_t = ubit32_t;
	using memcell_t = ubit64_t;

	template <typename type_value>
	void swap(type_value &firstNumber, type_value &secondNumber) noexcept;

	template <typename type_value>
	type_value minimum(type_value firstNumber, type_value secondNumber) noexcept;

	template <typename type_value>
	type_value maximum(type_value firstNumber, type_value secondNumber) noexcept;

	memcell_t getMemoryCell(memcell_t right_adjust = 0, memcell_t left_adjust = 0);

	template <typename type_array>
	struct Array
	{
		type_array *array = nullptr;
		asize_t array_size = 0;
	};
	template <typename type_array>
	Array<type_array> *create_struct(const asize_t &SIZE,
									 bool mem_allocation = true);
	template <typename type_array>
	void generate_struct(Array<type_array> *&Array,
						 const sbit64_t &min_limit,
						 const sbit64_t &max_limit,
						 const ubit64_t seed = getMemoryCell(32),
						 const ubit32_t denominator = 1);
	template <typename type_array>
	void remove_struct(Array<type_array> *&Array);

	class Printer
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

	namespace EXCEPTION_SET
	{
		class Exception
		{
		public:
			Exception(ubit16_t CODE, const byte1_t *DETAILS, const byte1_t *EXPLANATION);
			Exception(ubit16_t CODE, const byte1_t *DETAILS);
			Exception(ubit16_t CODE);
			Exception(const byte1_t *DETAILS);
			ubit16_t code();
			const byte1_t *what();
			const byte1_t *why();

		protected:
			ubit16_t CODE;
			const byte1_t *DETAILS;
			const byte1_t *EXPLANATION;
		};

		const byte1_t excep55[] = "The memory cell that stores the size of the data volume can no longer store more. This error can occur in cases when a larger value is required to be written to the cell that can store the variable 0xffffffff, i.e. more than 4 bytes, since the data size storage cell occupies 4 bytes";
		const byte1_t excep101[] = "A division by zero has occurred - an undefined result of the program execution";
		const byte1_t excep254[] = "Position failure - position is missing in the array";
		const byte1_t excep255[] = "Value failure - value is missing in the array";
		const byte1_t excep256[] = "Size failure - resizing error; for example, it can occur when the sizes match when the array is resized, or the new size is greater/less than limits sizes";
		const byte1_t excep400[] = "Geted empty data structure";
		const byte1_t excep404[] = "Search error - item not found";

		class memory_overflow : public Exception
		{
		public:
			memory_overflow();
			memory_overflow(const byte1_t *explanation);
		};

		class division_by_zero : public Exception
		{
		public:
			division_by_zero();
			division_by_zero(const byte1_t *explanation);
		};

		class position_failure : public Exception
		{
		public:
			position_failure();
			position_failure(const byte1_t *explanation);
		};

		class value_failure : public Exception
		{
		public:
			value_failure();
			value_failure(const byte1_t *explanation);
		};

		class size_failure : public Exception
		{
		public:
			size_failure();
			size_failure(const byte1_t *explanation);
		};

		class void_data : public Exception
		{
		public:
			void_data();
			void_data(const byte1_t *explanation);
		};

		class not_found : public Exception
		{
		public:
			not_found();
			not_found(const byte1_t *explanation);
		};
	}

	/* ****+/^^^/+++++-/&/-+-+-+-/&/-+-+-+-/&/-+-+-+-/&/-+-+-+-/&/-+++++/^^^/+**** *
	 * #*****+/^^^/+++++-/+/-+-+                         +-+-/+/-+++++/^^^/+*****# *
	 * #*-*%*-*+                                                         +*-*%*-*# *
	 * %%%%%                       $------------------$                      %%%%% *
	 * -->                             ALGOR_RANDOM                            <-- *
	 * %%%%%                       $------------------$                      %%%%% *
	 * #*-*%*-*+                                                         +*-*%*-*# *
	 * #*****+/^^^/+++++-/+/-+-+                         +-+-/+/-+++++/^^^/+*****# *
	 * ****+/^^^/+++++-/&/-+-+-+-/&/-+-+-+-/&/-+-+-+-/&/-+-+-+-/&/-+++++/^^^/+**** */

	namespace RANDOM
	{
		class LCM
		{
		public:
			LCM(memcell_t seed);
			ubit32_t rand();

		private:
			const ubit64_t a = 0x5851f42d4c957f2d;
			const ubit64_t c = 0x14057b7ef767814f;
			const ubit64_t m = 0xffffffffffffffff;
			memcell_t seed;
		};

		class RC4
		{
		public:
			void crypto_srand(const byte1_t *key, byte4_t ksize);
			void crypto_rand(byte1_t *output, byte4_t size);

		private:
			ubit8_t Sbox[256];
		};

		class MersenneTwister
		{
		public:
			MersenneTwister(byte4_t seed);
			void RandomInit(byte4_t seed);
			sbit32_t rand();
			byte4_t IRandom(byte4_t min, byte4_t max);
			byte4_t IRandomX(byte4_t min, byte4_t max);
			fbit64_t Random();
			ubit32_t BRandom();

		private:
			void Init0(byte4_t seed);

			ubit32_t mersenne_twister[624];
			byte4_t mersenne_twister_index;
			ubit32_t LastInterval;
			ubit32_t RejectionLimit;
		};

		template <class Generator>
		fbit64_t test_random_on_Pearsons_coefficient(ubit32_t left_limit, ubit32_t right_limit);
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
	class ArrayProcessing
	{
	public:
		static type_array minimum(const type_array *Array,
								  const asize_t &array_size);
		static type_array maximum(const type_array *Array,
								  const asize_t &array_size);
		static bool isOrderliness(const type_array *Array,
								  const asize_t &array_size);
		static asize_t distance(type_array *first,
								type_array *last);
		static type_array *lower_bound(type_array *first,
									   type_array *last,
									   const type_array &value);
		static type_array *upper_bound(type_array *first,
									   type_array *last,
									   const type_array &value);
		static void addElement(type_array *&Array,
							   asize_t &array_size,
							   const type_array &value,
							   const asize_t position = 0);
		static void subtractElement(type_array *&Array,
									asize_t &array_size,
									const asize_t position);
		static void subtractValue(type_array *&Array,
								  asize_t &array_size,
								  const type_array &value);
		static void copy(type_array *new_array,
						 const type_array *old_array,
						 const asize_t &size_of_copied,
						 asize_t position_in_new_array = 0,
						 asize_t position_in_old_array = 0);
	};

	template <typename type_array>
	class ArrayBase
	{
	protected:
		ArrayBase(Array<type_array> *&Array);
		ArrayBase(const asize_t &SIZE);
		ArrayBase();

		void verification(Array<type_array> *Array);

		Array<type_array> *ARRAY = nullptr;
	};

	template <typename type_array>
	class ARRAYDATA : public ArrayBase<type_array>
	{
	public:
		ARRAYDATA(Array<type_array> *&Array);
		ARRAYDATA(const asize_t &SIZE);
		~ARRAYDATA();

		enum class ArrayType
		{
			NUMBER = 1,
			STRING = 2
		};

		struct mode : Array<type_array>
		{
			ubit32_t highest_frequency = 0;
		};

		void generatedData(const sbit64_t &min_limit,
						   const sbit64_t &max_limit,
						   const ubit64_t seed = getMemoryCell(32),
						   const ubit32_t denominator = 1);
		void setNewData(Array<type_array> *&Array);
		void setData(Array<type_array> *&Array);
		void cloneNewData(Array<type_array> *&CloningArray);
		void cloneData(Array<type_array> *&CloningArray);

		Array<type_array> *&getData();
		asize_t getSize();
		type_array getValue(const asize_t &position);
		asize_t binary_getPosition(const type_array &required_element);
		Array<asize_t> *lenear_getPosition(const type_array &required_element);
		type_array getMin();
		type_array getMax();

		void reset();
		void resize(const asize_t &NEW_SIZE, const type_array &setElement);
		void replace(const asize_t &position, const type_array &value);
		void reverse();
		void respawn();

		Array<asize_t> *searcherOccurrencesOfSubstring(Array<type_array> *&SUBARRAY,
													   ArrayType ArrType = ArrayType::NUMBER);

		type_array average();
		type_array mediana();
		mode *moda();

		bool operator=(Array<type_array> *&cloningArray);
		bool operator==(Array<type_array> *&anotherArray);
		Array<type_array> *&operator^=(const asize_t &NewSize);
		Array<type_array> *&operator+=(const type_array &addValue);
		Array<type_array> *&operator-=(const type_array &subtractValue);
		Array<type_array> *&operator*=(const type_array &multiplyValue);
		Array<type_array> *&operator/=(const type_array &divideValue);
		Array<type_array> *&operator&=(const type_array &value);
		Array<type_array> *&operator|=(const type_array &value);
		Array<type_array> *&operator!();
		Array<type_array> *&operator<<=(ARRAYDATA<type_array> *&appendingArray);
		Array<type_array> *&operator>>=(ARRAYDATA<type_array> *&appendingArray);

	private:
		void remove();
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
		void Bubble_Sort();
		void Cocktail_Shaker_Sort();
		void Odd_Even_Sort();
		void Comb_Sort();
		void Gnome_Sort();
		void Quick_Sort();
		void Slow_Sort();
		void Stooge_Sort();
		void Bogo_Sort();
		// <<==		Категорія Selection_Sorts	==>>
		void Selection_Sort();
		void Heap_Sort();
		void Cycle_Sort();
		// <<==		Категорія Insertion_Sorts	==>>
		void Insert_Sort();
		void Shell_Sort();
		void Tree_Sort();
		void Library_Sort();
		void Patience_Sort();
		// <<==		Категорія Merge_Sorts		==>>
		void Merge_Sort();
		// <<==		Категорія Concurrent_Sort	==>>
		void Bitonic_Sorter();
		void Batcher_OddEven_MergeSort();
		// <<==		Категорія Hybrid_Sorts		==>>
		void Tim_Sort();
		// <<==		Категорія Other_Sorts		==>>
		void Pancake_Sort();

		// <<==				Classes				==>>

		class BatcherOddEvenMergeSort
		{
		public:
			BatcherOddEvenMergeSort(type_array *array, asize_t asize);
			void batcher_odd_even_merge_sort();

		private:
			type_array *Array;
			asize_t array_size;
		};

		class BitonicSorter
		{
		public:
			BitonicSorter(type_array *array, asize_t asize);
			void bitonic_sorter();

		private:
			type_array *Array;
			asize_t array_size;
		};

		class BogoSort
		{
		public:
			BogoSort(type_array *array, asize_t asize);
			void bogo_sort();

		private:
			type_array *Array;
			asize_t array_size;

			void Shuffle();
		};

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

		class CombSort
		{
		public:
			CombSort(type_array *array, asize_t asize);
			void comb_sort();

		private:
			type_array *Array;
			asize_t array_size;
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

		class GnomeSort
		{
		public:
			GnomeSort(type_array *array, asize_t asize);
			void gnome_sort();

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

			void heapify(type_array *Array,
						 const asize_t &count,
						 const asize_t &array_size);
		};

		class InsertSort
		{
		public:
			InsertSort(type_array *array, asize_t asize);
			void insert_sort();

		private:
			type_array *Array;
			asize_t array_size;
		};

		class LibrarySort
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

		class MergeSort
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

		class OddEvenSort
		{
		public:
			OddEvenSort(type_array *array, asize_t asize);
			void odd_even_sort();

		private:
			type_array *Array;
			asize_t array_size;
		};

		class PancakeSort
		{
		public:
			PancakeSort(type_array *array, asize_t asize);
			void pancake_sort();

		private:
			type_array *Array;
			asize_t array_size;

			asize_t max_index();
			void flip(asize_t index);
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

		class QuickSort
		{
		public:
			QuickSort(type_array *array, asize_t asize);
			void quick_sort();

		private:
			type_array *Array;
			asize_t array_size;

			void recursive_quick_sort(const byte4_t &left_limit,
									  const byte4_t &right_limit);
		};

		class SelectionSort
		{
		public:
			SelectionSort(type_array *array, asize_t asize);
			void selection_sort();

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

		class SlowSort
		{
		public:
			SlowSort(type_array *array, asize_t asize);
			void slow_sort();

		private:
			type_array *Array;
			asize_t array_size;

			void recursive_slow_sort(const asize_t &left_limit,
									 const asize_t &right_limit);
		};

		class StoogeSort
		{
		public:
			StoogeSort(type_array *array, asize_t asize);
			void stooge_sort();

		private:
			type_array *Array;
			asize_t array_size;

			void recursive_stooge_sort(const asize_t &left_limit,
									   const asize_t &right_limit);
		};

		class TimSort
		{
		public:
			TimSort(type_array *array, asize_t asize);
			void tim_sort();

		private:
			type_array *Array;
			asize_t array_size;

			const asize_t RUN = 32;

			void insertionSort(asize_t left_limit, asize_t right_limit);
			void merge(asize_t left_limit, asize_t middle, asize_t right_limit);
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
				type_array data;
				Tree *left, *right;
			};

			Tree *newnode(type_array key);
			Tree *insert(Tree *node, type_array key);
			void store(Tree *root, type_array *Array, asize_t &index);
		};
	};

	class Distribution_Sorts : public ArrayBase<byte8_t>
	{
	public:
		Distribution_Sorts(Array<byte8_t> *&Array);
		void AmericanFlag_Sort();
		void Bead_Sort();
		void Bucket_Sort();
		void Counting_Sort();
		void Interpolation_Sort();
		void Pigeonhole_Sort();
		void Radix_Sort();
		void Flash_Sort();

		class AmericanFlagSort
		{
		public:
			AmericanFlagSort(byte8_t *array, asize_t asize);
			void american_flag_sort();

		private:
			byte8_t *Array;
			asize_t array_size;

			const byte8_t NUMBER_OF_BUCKETS = 10; // 10 for base 10 numbers

			void recursive_american_flag_sort(byte8_t start,
											  byte8_t length,
											  byte8_t divisor);
			byte8_t getMaxNumberOfDigits();
			byte8_t getDigit(byte8_t integer, byte8_t divisor);
		};

		class BeadSort
		{
		public:
			BeadSort(byte8_t *array, asize_t asize);
			void bead_sort();

		private:
			byte8_t *Array, max;
			asize_t array_size;
			ubit8_t *beads;
		};

		class BucketSort
		{
		public:
			BucketSort(byte8_t *array, asize_t asize);
			void bucket_sort();

		private:
			byte8_t *Array, **bucket, min, max, range;
			asize_t array_size, bucket_index, array_index = 0;
		};

		class CountingSort
		{
		public:
			CountingSort(byte8_t *array, asize_t asize);
			void counting_sort();

		private:
			byte8_t *Array, *tempArray, min, max;
			asize_t array_size;
		};

		class FlashSort
		{
		public:
			FlashSort(byte8_t *array, asize_t asize);
			void flash_sort();

		private:
			byte8_t *Array, *L, flash;
			asize_t array_size, min = 0, max = 0, move = 0, j = 0, k;
		};

		class InterpolationSort
		{
		public:
			InterpolationSort(byte8_t *array, asize_t asize);
			void interpolation_sort();

		private:
			byte8_t *Array;
			asize_t array_size;

			const asize_t MIN_SORTABLE_LENGTH = 128;

			byte8_t ifac, temp;
			byte8_t nArray_min, nArray_max, index_min;
			byte8_t *space, *cmp_index, *cum, *hist, *sorted;
			byte8_t ComplexityCount = 0;

			void getMin();
			void getMax();
		};

		class PigeonholeSort
		{
		public:
			PigeonholeSort(byte8_t *array, asize_t asize);
			void pigeonhole_sort();

		private:
			byte8_t *Array, **hole, min, max;
			asize_t array_size, range, count = 0;
		};

		class RadixSort
		{
		public:
			RadixSort(byte8_t *array, asize_t asize);
			void radix_sort();

		private:
			byte8_t *Array, *tempArray, *bucket, exp = 1, bit = 10, max, current;
			asize_t array_size;
		};
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
} // ALGOR namespace end

#endif // ALGOR_HPP
