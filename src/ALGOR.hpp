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
 *                             Version: 1.0.0.0-dev                             *
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
 * \brief Бібліотека для обробки та сортування структур даних.
 * \author Калиновський Валентин
 * \version 1.0.0.0
 * \date 11.01.2022
 * \copyright Copyright © 2021-2022 Kalynovsky Valentin. All rights reserved.
   Licensed under the Apache License, Version 2.0 (the "License")
 */

// WARNING Дату написания документации указать тогда, когда будет написана документация
// WARNING Подивитися й додати \throw у документації, де вони пропущені

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
		static type_array minimum(const type_array *Array, const asize_t &array_size);
		static type_array maximum(const type_array *Array, const asize_t &array_size);
		static bool isOrderliness(const type_array *Array, const asize_t &array_size);
		static asize_t distance(type_array *first, type_array *last);
		static type_array *lower_bound(type_array *first, type_array *last, const type_array &value);
		static type_array *upper_bound(type_array *first, type_array *last, const type_array &value);
		static void addElement(type_array *&Array, asize_t &array_size, const type_array &value, const asize_t position = 0);
		static void subtractElement(type_array *&Array, asize_t &array_size, const asize_t position);
		static void subtractValue(type_array *&Array, asize_t &array_size, const type_array &value);
		static void copy(type_array *new_array, const type_array *old_array, const asize_t &size_of_copied, asize_t position_in_new_array = 0, asize_t position_in_old_array = 0);
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
	void generate_struct(Array<type_array> *&Array, const sbit64_t &min_limit, const sbit64_t &max_limit, const ubit64_t seed = getMemoryCell(32), const ubit32_t denominator = 1);
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

		Array<type_array> *ARRAY = nullptr;
	};

	template <typename type_array>
	class ARRAYDATA : public ArrayBase<type_array>
	{
	public:
		ARRAYDATA(Array<type_array> *&Array);
		ARRAYDATA(const asize_t &SIZE);
		~ARRAYDATA(); //Не документується

		enum class ArrayType
		{
			NUMBER = 1,
			STRING = 2
		};

		struct mode : Array<type_array>
		{
			ubit32_t highest_frequency = 0;
		};

		void generatedData(const sbit64_t &min_limit, const sbit64_t &max_limit, const ubit64_t seed = getMemoryCell(32), const ubit32_t denominator = 1);
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

		/*!
		   \fn ALGOR::ARRAYDATA::reset()
		   \brief Метод збросу данних
		   \details Метод видаляє масив із пам'яті й виділяє заново пам'ять під
		   новий масив без його заповнення. У результаті масив буде спустошено
		   до нульових данних.
		   \since v0.1.0.0 commit 1f2a4f
		   \test
		   \snippet Algor_ArrayData.cpp ARRAYDATA reset
		 */
		void reset();
		/*!
		   \fn ALGOR::ARRAYDATA::resize(const asize_t &, const type_array &)
		   \brief Метод, який змінює розмір масиву
		   \details Насправді, метод створює новий масив нового розміру і копіює
		   у нього старий масив. Якщо масив стає більше - нові комірки заповнюються
		   заданим значенням, інакше - останні значення відкидаються. Потім
		   пам'ять від старого масиву звільняється, а вказівник починає вказувати
		   на новий масив.
		   \throw ALGOR::EXCEPTION_SET::size_failure
		   \param[in] NEW_SIZE Новий розмір масиву
		   \param[in] setElement Значення, яким заповнюються нові клітинки масиву (у
		   випадку збільшення масиву)
		   \warning У разі збільшення розміру масиву після копіювання нові комірки
		   залишаються порожніми і зберігають у собі «сміття». Іноді програміст
		   випадково може спробувати отримати дані без їх вказівки, в результаті
		   чого в кращому випадку буде просто виданий некоректний результат, а в
		   гіршому - програма може вийти з ладу. Для цього був створений параметр
		   setElement, але його потрібно вказувати не тільки при збільшенні розміру,
		   а завжди при виклику методу для профілактики. Програміст може навіть
		   не знати поточного розміру масиву, отже, він не може знати, чи буде масив
		   збільшено чи зменшено.
		   \since v0.1.0.0 commit 1d50a2
		   \test
		   \snippet Algor_ArrayData.cpp ARRAYDATA resize
		 */
		void resize(const asize_t &NEW_SIZE, const type_array &setElement);
		/*!
		   \fn ALGOR::ARRAYDATA::replace(const asize_t &, const type_array &)
		   \brief Змінює значення по вказаній позиції
		   \param[in] position Позиція, у якій змінюється значення
		   \param[in] value Значення, яке буде розміщено в позиції
		   \since v0.1.0.0 commit dd5d42
		   \test
		   \snippet Algor_ArrayData.cpp ARRAYDATA replace
		 */
		void replace(const asize_t &position, const type_array &value);
		/*!
		   \fn ALGOR::ARRAYDATA::reverse()
		   \brief Перевертає масив
		   \since v0.0.0.3 commit 05d8b0
		   \test
		   \snippet Algor_ArrayData.cpp ARRAYDATA reverse
		 */
		void reverse();
		/*!
		   \fn ALGOR::ARRAYDATA::respawn()
		   \brief Метод збросу та перегенерації данних
		   \details Метод розширює ALGOR::ARRAYDATA::reset, а саме додатково зберігає
		   діапазон значень масиву і після збросу даних, заново їх генерує.
		   \since v0.1.0.0 commit dd5d42
		   \test
		   \snippet Algor_ArrayData.cpp ARRAYDATA respawn
		 */
		void respawn();

		/*!
		\brief Sequence search method that returns all its occurrences
		\tparam type_array The type of elements that the array stores. For example int or float
		\param SUBARRAY The substring that is searched for in the main array
		\param ArrType Array type
		\return Array<int>*
		*/
		Array<asize_t> *searcherOccurrencesOfSubstring(Array<type_array> *&SUBARRAY, ArrayType ArrType = ArrayType::NUMBER);

		/*!
		\brief Method that returns the arithmetic mean of an array
		\tparam type_array The type of elements that the array stores. For example int or float
		\return type_array
		*/
		type_array average();
		/*!
		\brief Method that returns the median of an array
		\tparam type_array The type of elements that the array stores. For example int or float
		\return type_array
		*/
		type_array mediana();
		/*!
		\brief A method that returns all elements with an array mode
		\tparam type_array The type of elements that the array stores. For example int or float
		\param highest_frequency An indicator of the frequency of occurrence of elements that are most often found
		\return Array<type_array>*
		*/
		mode *moda();

		///-
		bool operator=(Array<type_array> *&cloningArray);
		///-
		bool operator==(Array<type_array> *&anotherArray);
		///-
		Array<type_array> *&operator^=(const asize_t &NewSize);
		/*!
		\brief Operator for increasing an array by a specific size
		\tparam type_array The type of elements that the array stores. For example int or float
		\param addSize Parameter indicating how much to increase the array
		*/
		Array<type_array> *&operator+=(const type_array &addValue);
		/*!
		\brief Operator for decreasing an array by a specific size
		\tparam type_array The type of elements that the array stores. For example int or float
		\param subtractSize Parameter indicating how much to reduce the array
		*/
		Array<type_array> *&operator-=(const type_array &subtractValue);
		/*!
		\brief Operator for increasing an array by several times
		\tparam type_array The type of elements that the array stores. For example int or float
		\param multiplySize Parameter indicating how many times to increase the array
		*/
		Array<type_array> *&operator*=(const type_array &multiplyValue);
		/*!
		\brief Operator for decreasing an array by some times
		\tparam type_array The type of elements that the array stores. For example int or float
		\param divideSize Параметр, указывающий, во сколько раз следует уменьшить массив
		*/
		Array<type_array> *&operator/=(const type_array &divideValue);
		/*!
		\brief Operator adding an element to the end of an array
		\tparam type_array The type of elements that the array stores. For example int or float
		\param value The value to add to the end of the array
		*/
		Array<type_array> *&operator&=(const type_array &value);
		/*!
		\brief An operator that removes all elements with a specified value
		\tparam type_array The type of elements that the array stores. For example int or float
		\param value The value to be removed
		*/
		Array<type_array> *&operator|=(const type_array &value);
		/*!
		\brief Operator that removes an element from the end of an array
		\tparam type_array The type of elements that the array stores. For example int or float
		*/
		Array<type_array> *&operator!();
		/*!
		\brief Operator for merging two arrays in the current object
		\tparam type_array The type of elements that the array stores. For example int or float
		\param appendingArray An array to attach from another object
		*/
		Array<type_array> *&operator<<=(ARRAYDATA<type_array> *&appendingArray);
		/*!
		\brief Operator for merging two arrays in a received object
		\tparam type_array The type of elements that the array stores. For example int or float
		\param appendingArray An array from another object to which the current array will be passed
		*/
		Array<type_array> *&operator>>=(ARRAYDATA<type_array> *&appendingArray);

	private:
		/*!
		   \fn ALGOR::ARRAYDATA::remove()
		   \brief Видаляє масив
		   \warning Метод є приватним, щоб уникнути випадків, коли програміст
		   звільнив пам'ять з-під масиву і звертається до пустих данних чи намагається
		   проводити над ними якісь зміни.
		   \since v0.1.0.0 commit 1d50a2
		 */
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
	 * 2)  Smooth_Sort				Категорія Selection_Sorts                      *
	 * 3)  CartesianTreeSort		Категорія Selection_Sorts                      *
	 * 4)  TournamentSort			Категорія Selection_Sorts                      *
	 * 5)  WeakHeapSort				Категорія Selection_Sorts                      *
	 * 6)  SplaySort				Категорія Insertion_Sorts                      *
	 * 7)  CascadeMergeSort			Категорія Merge_Sorts                          *
	 * 8)  OscillatingMergeSort		Категорія Merge_Sorts                          *
	 * 9)  PolyphaseMergeSort		Категорія Merge_Sorts                          *
	 * 10) BurstSort				Категорія Distribution_Sorts                   *
	 * 11) ProxmapSort				Категорія Distribution_Sorts                   *
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
		void Bubble_Sort();			 // №	 4	/цілі+ цілі- цілі+- дрібні+ дрібні- дрібні+-
		void Cocktail_Shaker_Sort(); // №	 5	/цілі+ цілі- цілі+- дрібні+ дрібні- дрібні+-
		void Odd_Even_Sort();		 // №	13	/цілі+ цілі- цілі+- дрібні+ дрібні- дрібні+-
		void Comb_Sort();			 // №	 6	/цілі+ цілі- цілі+- дрібні+ дрібні- дрібні+-
		void Gnome_Sort();			 // №	 8	/цілі+ цілі- цілі+- дрібні+ дрібні- дрібні+-
		void Quick_Sort();			 // №	16	/цілі+ цілі- цілі+- дрібні+ дрібні- дрібні+-
		void Slow_Sort();			 // №	19	/цілі+ цілі- цілі+- дрібні+ дрібні- дрібні+-
		void Stooge_Sort();			 // №	20	/цілі+ цілі- цілі+- дрібні+ дрібні- дрібні+-
		void Bogo_Sort();			 // №	 3	/цілі+ цілі- цілі+- дрібні+ дрібні- дрібні+-
		// <<==		Категорія Selection_Sorts	==>>
		void Selection_Sort(); // №	17	/цілі+ цілі- цілі+- дрібні+ дрібні- дрібні+-
		void Heap_Sort();	   // №	 9	/цілі+ цілі- цілі+- дрібні+ дрібні- дрібні+-
		void Cycle_Sort();	   // №	 7	/цілі+ цілі- цілі+- дрібні+ дрібні- дрібні+-
		// <<==		Категорія Insertion_Sorts	==>>
		void Insert_Sort();	  // №	10	/цілі+ цілі- цілі+- дрібні+ дрібні- дрібні+-
		void Shell_Sort();	  // №	18	/цілі+ цілі- цілі+- дрібні+ дрібні- дрібні+-
		void Tree_Sort();	  // №	22	/цілі+ цілі- цілі+- дрібні+ дрібні- дрібні+-
		void Library_Sort();  // №	11	/цілі+ цілі- цілі+- дрібні+ дрібні- дрібні+-
		void Patience_Sort(); // №	15	/цілі+ цілі- цілі+- дрібні+ дрібні- дрібні+-
		// <<==		Категорія Merge_Sorts		==>>
		void Merge_Sort(); // №	12	/цілі+ цілі- цілі+- дрібні+ дрібні- дрібні+-
		// <<==		Категорія Concurrent_Sort	==>>
		void Bitonic_Sorter();			  // №	 2	/цілі+ цілі- цілі+- дрібні+ дрібні- дрібні+-
		void Batcher_OddEven_MergeSort(); // №	 1	/цілі+ цілі- цілі+- дрібні+ дрібні- дрібні+-
		// <<==		Категорія Hybrid_Sorts		==>>
		void Tim_Sort(); // №	21	/цілі+ цілі- цілі+- дрібні+ дрібні- дрібні+-
		// <<==		Категорія Other_Sorts		==>>
		void Pancake_Sort(); // №	14	/цілі+ цілі- цілі+- дрібні+ дрібні- дрібні+-

		// <<==				Classes				==>>
		class BatcherOddEvenMergeSort //Категорія Concurrent_Sort
		{
		public:
			BatcherOddEvenMergeSort(type_array *array, asize_t asize);
			void batcher_odd_even_merge_sort();

		private:
			type_array *Array;
			asize_t array_size;
		};

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

			void recursive_quick_sort(const byte4_t &left_limit,
									  const byte4_t &right_limit);
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

			void recursive_slow_sort(const asize_t &left_limit,
									 const asize_t &right_limit);
		};

		class StoogeSort //Категорія Exchange_Sorts
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
		void AmericanFlag_Sort();  // №	1	/цілі+ ; вилітає
		void Bead_Sort();		   // №	2	/цілі+ ; обрізає
		void Bucket_Sort();		   // №	3	/цілі+ цілі- цілі+-
		void Counting_Sort();	   // №	4	/цілі+ цілі- цілі+-
		void Flash_Sort();		   // №	5	/цілі+ цілі- цілі+-
		void Interpolation_Sort(); // №	6	/цілі+ цілі- цілі+-
		void Pigeonhole_Sort();	   // №	7	/цілі+ цілі- цілі+-
		void Radix_Sort();		   // №	8	/цілі+ ; не сортує

		class AmericanFlagSort
		{
		public:
			// https://github.com/phishman3579/java-algorithms-implementation/blob/master/src/com/jwetherell/algorithms/sorts/AmericanFlagSort.java
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
			// https://github.com/TheAlgorithms/C-Plus-Plus/blob/master/sorting/bucket_sort.cpp
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
			// https://javascript.algorithmexamples.com/web/Sorts/flashSort.html
			FlashSort(byte8_t *array, asize_t asize);
			void flash_sort();

		private:
			byte8_t *Array, *L, flash;
			asize_t array_size, min = 0, max = 0, move = 0, j = 0, k;
		};

		class InterpolationSort
		{
		public:
			// https://github.com/aniketsatarkar/Sorting-Algorithms-in-C/blob/master/InterpolationSort.h
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
