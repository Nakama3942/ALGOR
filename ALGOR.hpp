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
 * \file
 * \brief Library for processing arrays and sorting them
 * \author Kalynovsky Valentin
 * \version 2.1.0
 * \date 11.01.2022
 * \copyright Copyright © 2021-2022 Kalynovsky Valentin. All rights reserved. Licensed under the Apache License, Version 2.0 (the "License")
 */
 
// WARNING Дату написания документации указать тогда, когда будет написана документация

// WARNING Перепровірити код, де у якості максимального значання задається
// 0xffffffff, так як для int найменшим є 0x80000000, то число представляє собою
//-1 для типу int. Обов'язково необхідно перевірити код усюди, де використовуються
//шістнадцятковий код

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
	using fbit128_t = long double;

	using asize_t = ubit32_t;				///< Alias for specifying the type "array size"
	using memcell_t = ubit64_t;				///< Alias for calculated memory cell

	template <typename type_value>
	class CORE
	{
	public:
		static void swap(type_value &firstNumber, type_value &secondNumber) noexcept;
		static type_value minimum(type_value firstNumber, type_value secondNumber) noexcept;
		static type_value maximum(type_value firstNumber, type_value secondNumber) noexcept;
	};

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
		Exception(ubit16_t CODE, const char *DETAILS, const char *EXPLANATION);
		Exception(ubit16_t CODE, const char *DETAILS);
		Exception(ubit16_t CODE);
		Exception(const char *DETAILS);
		ubit16_t code();
		const char *what();
		const char *why();

	protected:
		ubit16_t CODE;				///< Exception encoding
		const char *DETAILS;		///< Exception details
		const char *EXPLANATION;	///< Exception explanation
	};

	class memory_overflow : public Exception
	{
	public:
		memory_overflow();
		memory_overflow(const char *explanation);
	};

	class division_by_zero : public Exception
	{
	public:
		division_by_zero();
		division_by_zero(const char *explanation);
	};

	class position_failure : public Exception
	{
	public:
		position_failure();
		position_failure(const char *explanation);
	};

	class value_failure : public Exception
	{
	public:
		value_failure();
		value_failure(const char *explanation);
	};

	class size_failure : public Exception
	{
	public:
		size_failure();
		size_failure(const char *explanation);
	};

	class void_data : public Exception
	{
	public:
		void_data();
		void_data(const char *explanation);
	};

	class not_found : public Exception
	{
	public:
		not_found();
		not_found(const char *explanation);
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

	class LCM
	{
	public:
		//LCM = LinearCongruentMethod
		//Source: https://en.wikipedia.org/wiki/Linear_congruential_generator
		//Paragraph: Parameters in common use
		//Table row: MMIX by Donald Knuth
		LCM(ubit32_t seed);
		ubit32_t rand();
	private:
		const ubit64_t a = 0x5851f42d4c957f2d; //6`364`136`223`846`793`005
		const ubit64_t c = 0x14057b7ef767814f; //1`442`695`040`888`963`407
		const ubit64_t m = 0xffffffffffffffff; //18`446`744`073`709`551`615
		ubit32_t seed;
	};

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
		sbit32_t rand();
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

	template <class Generator>
	fbit64_t tester(ubit32_t left_limit, ubit32_t right_limit);

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
	struct Array
	{
		type_array *array = nullptr;
		asize_t array_size = 0;
	};
	template <typename type_array>
	Array<type_array> *create_struct(const asize_t &SIZE, bool mem_allocation = true);
	template <typename type_array>
	void generate_struct(type_array *&Array, asize_t &array_size, const sbit64_t &min_limit, const sbit64_t &max_limit, const ubit8_t denominator = 1);
	template <typename type_array>
	void remove_struct(Array<type_array> *&Array);

	template <typename type_array>
	class ArrayBase
	{
	protected:
		ArrayBase(Array<type_array> *&Array);
		ArrayBase(const asize_t &SIZE);
		ArrayBase();

		void verification(Array<type_array> *Array);

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

		struct mode : Array<type_array>
		{
			ubit32_t highest_frequency = 0;
		};

		void generatedData(const sbit64_t &min_limit, const sbit64_t &max_limit, const ubit8_t denominator = 1);
		void setNewData(Array<type_array> *&Array);
		void setData(Array<type_array> *&Array);
		void cloneData(Array<type_array> *&CloningArray);
		Array<type_array> *getData();
		asize_t getSize();
		Array<asize_t> *getPosition(const type_array &value);
		type_array getValue(const asize_t &position);

		void reset();
		void resize(const asize_t &NEW_SIZE, const type_array &setElement);
		void replace(const asize_t &position, const type_array &value);
		void reverse();
		void respawn();

		type_array getMin();
		type_array getMax();

		Array<asize_t> *lenear_searcher(const type_array &required_element);
		asize_t binary_searcher(const type_array &required_element);
		Array<asize_t> *searcherOccurrencesOfSubstring(Array<type_array> *&SUBARRAY,
													   ArrayType ArrType = ArrayType::NUMBER);

		type_array average();
		type_array mediana();
		mode *moda();

		bool operator=(Array<type_array> *&cloningArray);
		bool operator==(Array<type_array> *&anotherArray);
		Array<type_array> *operator^=(const asize_t &NewSize);
		Array<type_array> *operator+=(const type_array &addValue);
		Array<type_array> *operator-=(const type_array &subtractValue);
		Array<type_array> *operator*=(const type_array &multiplyValue);
		Array<type_array> *operator/=(const type_array &divideValue);
		Array<type_array> *operator&=(const type_array &value);
		Array<type_array> *operator|=(const type_array &value);
		Array<type_array> *operator!();
		Array<type_array> *operator<<=(ARRAYDATA<type_array> *&appendingArray);
		Array<type_array> *operator>>=(ARRAYDATA<type_array> *&appendingArray);

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

	/* ****+/^^^/+++++-/&/-+-+-+-/&/-+-+-+-/&/-+-+-+-/&/-+-+-+-/&/-+++++/^^^/+**** *
	 *                      Список нереалізованих алгоритмів:                      *
	 * 1)  ProportionExtendSort		Категорія Exchange_Sorts                       *
	 * 2)  CartesianTreeSort		Категорія Selection_Sorts                      *
	 * 3)  TournamentSort			Категорія Selection_Sorts                      *
	 * 4)  WeakHeapSort				Категорія Selection_Sorts                      *
	 * 5)  SplaySort				Категорія Insertion_Sorts                      *
	 * 6)  CascadeMergeSort			Категорія Merge_Sorts                          *
	 * 7)  OscillatingMergeSort		Категорія Merge_Sorts                          *
	 * 8)  PolyphaseMergeSort		Категорія Merge_Sorts                          *
	 * 9)  BurstSort				Категорія Distribution_Sorts                   *
	 * 10) ProxmapSort				Категорія Distribution_Sorts                   *
	 * 11) BatcherOddEvenMergeSort	Категорія Concurrent_Sort                      *
	 * 12) PairwiseSortingNetwork	Категорія Concurrent_Sort                      *
	 * 13) SampleSort				Категорія Concurrent_Sort                      *
	 * 14) BlockMergeSort			Категорія Hybrid_Sorts                         *
	 * 15) KirkpatrickReischSort	Категорія Hybrid_Sorts                         *
	 * 16) IntroSort				Категорія Hybrid_Sorts                         *
	 * 17) SpreadSort				Категорія Hybrid_Sorts                         *
	 * 18) MergeInsertionSort		Категорія Hybrid_Sorts                         *
	 * 19) TopologicalSort			Категорія Other_Sorts                          *
	 * 20) SpaghettiSort			Категорія Other_Sorts                          *
	 * ****+/^^^/+++++-/&/-+-+-+-/&/-+-+-+-/&/-+-+-+-/&/-+-+-+-/&/-+++++/^^^/+**** */

	template <typename type_array>
	class Comparative_Sorts : public ArrayBase<type_array>
	{
	public:
		Comparative_Sorts(Array<type_array> *&Array);

		// <<==		Категорія Exchange_Sorts	==>>
		void Bubble_Sort();				// №	 3
		void Cocktail_Shaker_Sort();	// №	 4
		void Odd_Even_Sort();			// №	12
		void Comb_Sort();				// №	 5
		void Gnome_Sort();				// №	 7
		void Quick_Sort();				// №	15
		void Slow_Sort();				// №	18
		void Stooge_Sort();				// №	20
		void Bogo_Sort();				// №	 2

		// <<==		Категорія Selection_Sorts	==>>
		void Selection_Sort();			// №	16
		void Heap_Sort();				// №	 8
		void Smooth_Sort();				// №	19 //FIXME на момент тесту все одно не сортує
		void Cycle_Sort();				// №	 6

		// <<==		Категорія Insertion_Sorts	==>>
		void Insert_Sort();				// №	 9
		void Shell_Sort();				// №	17
		void Tree_Sort();				// №	22
		void Library_Sort();			// №	10
		void Patience_Sort();			// №	14

		// <<==		Категорія Merge_Sorts		==>>
		void Merge_Sort();				// №	11

		// <<==		Категорія Concurrent_Sort	==>>
		void Bitonic_Sorter();			// №	 1

		// <<==		Категорія Hybrid_Sorts		==>>
		void Tim_Sort();				// №	21

		// <<==		Категорія Other_Sorts		==>>
		void Pancake_Sort();			// №	13

		// <<==				Classes				==>>
		class BitonicSorter //Категорія Concurrent_Sort
		{
		public:
			BitonicSorter(type_array *array, asize_t asize);
			void bitonic_sorter();

		private:
			type_array *Array;
			asize_t array_size;
		};

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

		class PancakeSort //Категорія Other_Sorts
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

		class TimSort //Категорія Hybrid_Sorts
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
		void AmericanFlag_Sort();	// №	1
		void Bead_Sort();			// №	2
		void Bucket_Sort();			// №	3
		void Counting_Sort();		// №	4
		void Flash_Sort();			// №	5
		void Interpolation_Sort();	// №	6
		void Pigeonhole_Sort();		// №	7
		void Radix_Sort();			// №	8

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
