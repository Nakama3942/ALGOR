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

#ifndef ALGOR_HPP
#define ALGOR_HPP

/*!
  \namespace ALGOR
  \brief Глобальний простір імен усього проекту
  \version v0.1.1.4 commit 2fa93b
  \since v0.1.2.0
  \details Призначений для зберігання усього реалізованого функціоналу проекту.
  Краще не використовувати разом з std, інакше можуть виникнути конфлікти.
 */
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

	/*!
	  \brief Аліас для char <em>(1 байт)</em>.
	  \version v0.1.2.1 commit b50b4a
	  \since v0.1.3.0
	  \details Зазвичай використовується для задання типу строк. Може зберігати
	  число від <b>0</b> до <b>255</b>, або від <b>-128</b> до <b>+127</b>.
	  \note Якщо цей тип дійсно використовується для строк, то не забувайте
	  вказувати "*" (вказівник) перед назвою імені строки, так як цей тип
	  не замінює повністю char на string. Це лише звичайний аліас.
	 */
	using byte1_t = char;
	/*!
	  \brief Аліас для short <em>(2 байти)</em>.
	  \version v0.1.2.1 commit b50b4a
	  \since v0.1.3.0
	  \details Зазвичай використовується при зберіганні коротких чисел
	  від <b>0</b> до <b>65'535</b>, або від <b>-32'768</b> до <b>+32'767</b>.
	 */
	using byte2_t = short;
	/*!
	  \brief Аліас для long <em>(4 байти)</em>.
	  \version v0.1.2.1 commit b50b4a
	  \since v0.1.3.0
	  \details Зазвичай використовується при зберіганні чисел. Може
	  зберігати від <b>0</b> до <b>4'294'967'295</b>, або від <b>-2'147'483'648</b>
	  до <b>+2'147'483'647</b>.
	  \note Також ним можна повноцінно замінити тип int, так як він теж
	  розрахований на 4 байти. Але якщо програму запустити на комп'ютері
	  з процесором intel i386 чи більш ранішим, то під int буде виділятися усього
	  2 байти і на тих процесорах int є аліасом для short. Через таке розпливчате
	  поняття типу int він ніде у бібліотеці не використовується, а використовуються
	  чіткі типи типу short чи long.
	 */
	using byte4_t = long;
	/*!
	  \brief Аліас для long long <em>(8 байтів)</em>.
	  \version v0.1.2.1 commit b50b4a
	  \since v0.1.3.0
	  \details Є розширенням типу long у два рази і розрахований під числа від <b>0</b>
	  до <b>18'446'744'073'709'551'615</b>, або від <b>-9'223'372'036'854'775'808</b>
	  до <b>+9'223'372'036'854'775'807</b>.
	 */
	using byte8_t = long long;
	/*!
	  \brief Аліас для signed char <em>(1 байт)</em>.
	  \version v0.0.1.0 commit 0d3195
	  \since v0.1.0.0
	  \details Аналогічно звичайному char, але може приймати значення тільки
	  від <b>-128</b> до <b>+127</b>.
	 */
	using sbit8_t = signed char;
	/*!
	  \brief Аліас для signed short <em>(2 байти)</em>.
	  \version v0.0.1.0 commit 0d3195
	  \since v0.1.0.0
	  \details Аналогічно звичайному short, але може приймати значення тільки
	  від <b>-32'768</b> до <b>+32'767</b>.
	 */
	using sbit16_t = signed short;
	/*!
	  \brief Аліас для signed long <em>(4 байти)</em>.
	  \version v0.0.1.0 commit 0d3195
	  \since v0.1.0.0
	  \details Аналогічно звичайному long, але може приймати значення тільки
	  від <b>-2'147'483'648</b> до <b>+2'147'483'647</b>.
	 */
	using sbit32_t = signed long;
	/*!
	  \brief Аліас для signed long long <em>(8 байтів)</em>.
	  \version v0.0.1.0 commit 0d3195
	  \since v0.1.0.0
	  \details Аналогічно звичайному long long, але може приймати значення тільки
	  від <b>-9'223'372'036'854'775'808</b> до <b>+9'223'372'036'854'775'807</b>.
	 */
	using sbit64_t = signed long long;
	/*!
	  \brief Аліас для unsigned char <em>(1 байт)</em>.
	  \version v0.0.1.0 commit 0d3195
	  \since v0.1.0.0
	  \details Аналогічно звичайному char і на відміну від signed char може
	  приймати значення тільки від <b>0</b> до <b>255</b>.
	 */
	using ubit8_t = unsigned char;
	/*!
	  \brief Аліас для unsigned short <em>(2 байти)</em>.
	  \version v0.0.1.0 commit 0d3195
	  \since v0.1.0.0
	  \details Аналогічно звичайному short і на відміну від signed short може
	  приймати значення тільки від <b>0</b> до <b>65'535</b>.
	 */
	using ubit16_t = unsigned short;
	/*!
	  \brief Аліас для unsigned long <em>(4 байти)</em>.
	  \version v0.0.1.0 commit 0d3195
	  \since v0.1.0.0
	  \details Аналогічно звичайному long і на відміну від signed long може
	  приймати значення тільки від <b>0</b> до <b>4'294'967'295</b>.
	 */
	using ubit32_t = unsigned long;
	/*!
	  \brief Аліас для unsigned long long <em>(8 байтів)</em>.
	  \version v0.0.1.0 commit 0d3195
	  \since v0.1.0.0
	  \details Аналогічно звичайному long long і на відміну від signed long long
	  може приймати значення тільки від <b>0</b> до <b>18'446'744'073'709'551'615</b>.
	 */
	using ubit64_t = unsigned long long;
	/*!
	  \brief Аліас для float <em>(4 байти)</em>.
	  \version v0.1.1.4 commit 1981d6
	  \since v0.1.2.0
	  \details На відміну від всіх попередніх типів, що можуть зберігати тільки
	  цілі числа, тип \a float може зберігати числа з плаваючою комою. У
	  комірку можна записати як додатні, так і від'ємні числа. Можливий діапазон
	  зберігаємих чисел від <b>+/-3.4E-38</b> до <b>3.4E+38</b>.
	 */
	using fbit32_t = float;
	/*!
	  \brief Аліас для double <em>(8 байтів)</em>.
	  \version v0.1.1.4 commit 1981d6
	  \since v0.1.2.0
	  \details Розширює тип \a float, збільшуючи точність та розмір у два рази.
	  Можливий діапазон зберігаємих чисел від <b>+/-1.7E-308</b> до <b>1.7E+308</b>.
	 */
	using fbit64_t = double;
	/*!
	  \brief Аліас для long double <em>(16 байт)</em>.
	  \version v0.1.2.1 commit b6349a
	  \since v0.1.3.0
	  \details Розширює тип \a double, збільшуючи точність та розмір іще у два
	  рази.
	 */
	using fbit128_t = long double;
	/*!
	  \brief Псевдонім для визначення типу <em>"розмір массиву"</em>.
	  \version v0.0.1.0 commit 89658e
	  \since v0.1.0.0
	  \details Зазвичай цей тип використовується, коли треба вказати розмір масиву
	  чи позицію у масиві. Так як нумерація починається з 0 і не існує від'ємних
	  розмірів масивів чи номерів позицій, можна поточнити тип з <a>int</a> до
	  <a>unsigned int</a>. До того ж не завжди вистачає <b>65'535</b> комірок масиву.
	  Іноді потрібно більше, наприклад, мільйон чи мільярд. Більше мільярда нема
	  сенсу створювати структури даних тому ідеальним вибором серед <a>short</a>,
	  <a>long</a> та <a>long long</a> є <a>long</a>. Саме тому <a>asize_t</a> є
	  аліасом до <a>ubit32_t</a>.
	 */
	using asize_t = ubit32_t;
	/*!
	  \brief Псевдонім для обчислюваної <em>комірки пам'яті</em>.
	  \version v0.1.1.2 commit b4cdc9
	  \since v0.1.1.3
	  \details використовується тільки у функції \a getMemoryCell(). Є службовим типом
	  і замість нього краще використовувати \a ubit64_t.
	 */
	using memcell_t = ubit64_t;

	/*!
	  \class
	  \brief Ядро бібліотеки, базовий клас, зо зберігає головні функції, що найчастіше використовуються
	  \
	 */
	template <typename type_value>
	class CORE
	{
	public:
		//		/*!
		//		   \fn
		//		\brief Swaps two elements
		//		\tparam type_array The type of elements that the array stores. For example int or float
		//		\param[in, out] firstNumber First item to replace
		//		\param[in, out] secondNumber Second item to replace
		//		\example {lineno}
		//			CORE<long long>::swap(array[i], array[j]);
		//		*/
		/*!
		   \brief swap
		   \param firstNumber
		   \param secondNumber
		 */
		static void swap(type_value &firstNumber, type_value &secondNumber) noexcept;

		///-
		static type_value minimum(type_value firstNumber, type_value secondNumber) noexcept;

		///-
		static type_value maximum(type_value firstNumber, type_value secondNumber) noexcept;
	};

	///-
	memcell_t getMemoryCell(memcell_t right_adjust = 0, memcell_t left_adjust = 0); //Заместо time(NULL)

	///-
	template <typename type>
	class Printer // Template interface
	{
	public:
		/*!
		   \brief print
		 */
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

	///-
	namespace EXCEPTION_SET
	{
		/*!
		\brief Class for working with exceptions
		*/
		class Exception
		{
		public:
			/*!
			\brief Construct a new Exception::Exception object
			\details Takes full detailed information on exclusion
			\param CODE Exception encoding
			\param MESSAGE Message exception
			\param DETAILS Exception details
			*/
			Exception(ubit16_t CODE, const byte1_t *DETAILS, const byte1_t *EXPLANATION);
			/*!
			\brief Construct a new Exception::Exception object
			\details Accepts basic exception information
			\param CODE Exception encoding
			\param MESSAGE Message exception
			*/
			Exception(ubit16_t CODE, const byte1_t *DETAILS);
			/*!
			\brief Construct a new Exception::Exception object
			\details Takes cordivity of exception
			\param CODE Exception encoding
			*/
			Exception(ubit16_t CODE);
			/*!
			\brief Construct a new Exception::Exception object
			\details Accepts an exception message
			\param MESSAGE Message exception
			*/
			Exception(const byte1_t *DETAILS);
			/*!
			\brief Returns exclusion encoding
			\return <unsigned int> - exception encoding
			*/
			ubit16_t code();
			/*!
			\brief Returns an exception message
			\return <const char*> - message exception
			*/
			const byte1_t *what();
			/*!
			\brief Returns exception details
			\return <const char*> - exception details
			*/
			const byte1_t *why();

		protected:
			ubit16_t CODE;				///< Exception encoding
			const byte1_t *DETAILS;		///< Exception details
			const byte1_t *EXPLANATION; ///< Exception explanation
		};

		const byte1_t excep55[] = "The memory cell that stores the size of the data volume can no longer store more. This error can occur in cases when a larger value is required to be written to the cell that can store the variable 0xffffffff, i.e. more than 4 bytes, since the data size storage cell occupies 4 bytes";
		const byte1_t excep101[] = "A division by zero has occurred - an undefined result of the program execution";
		const byte1_t excep254[] = "Position failure - position is missing in the array";
		const byte1_t excep255[] = "Value failure - value is missing in the array";
		const byte1_t excep256[] = "Size failure - resizing error; for example, it can occur when the sizes match when the array is resized, or the new size is greater/less than limits sizes";
		const byte1_t excep400[] = "Geted empty data structure";
		const byte1_t excep404[] = "Search error - item not found";

		///-
		class memory_overflow : public Exception
		{
		public:
			///-
			memory_overflow();
			///-
			memory_overflow(const byte1_t *explanation);
		};

		///-
		class division_by_zero : public Exception
		{
		public:
			///-
			division_by_zero();
			///-
			division_by_zero(const byte1_t *explanation);
		};

		///-
		class position_failure : public Exception
		{
		public:
			///-
			position_failure();
			///-
			position_failure(const byte1_t *explanation);
		};

		///-
		class value_failure : public Exception
		{
		public:
			///-
			value_failure();
			///-
			value_failure(const byte1_t *explanation);
		};

		///-
		class size_failure : public Exception
		{
		public:
			///-
			size_failure();
			///-
			size_failure(const byte1_t *explanation);
		};

		/*!
		\brief void_data exception class
		*/
		class void_data : public Exception
		{
		public:
			/*!
			\brief Construct a new void data::void data object
			\details Geted empty data structure
			*/
			void_data();
			///-
			void_data(const byte1_t *explanation);
		};

		/*!
		\brief not_found exception class
		*/
		class not_found : public Exception
		{
		public:
			/*!
			\brief Construct a new not found::not found object
			\details Search error - item not found
			*/
			not_found();
			///-
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

	///-
	namespace RANDOM
	{
		///-
		class LCM
		{
		public:
			// LCM = LinearCongruentMethod
			// Source: https://en.wikipedia.org/wiki/Linear_congruential_generator
			// Paragraph: Parameters in common use
			// Table row: MMIX by Donald Knuth
			///-
			LCM(memcell_t seed);
			///-
			ubit32_t rand();

		private:
			const ubit64_t a = 0x5851f42d4c957f2d; // 6`364`136`223`846`793`005
			const ubit64_t c = 0x14057b7ef767814f; // 1`442`695`040`888`963`407
			const ubit64_t m = 0xffffffffffffffff; // 18`446`744`073`709`551`615
			memcell_t seed;
		};

		/*!
		\brief Simple crypto-strong generator
		\note Taken from the link https://www.youtube.com/watch?v=PQlZI-QoM2A
		*/
		class RC4
		{
		public:
			/*!
			\brief Set up the key
			\param[in] key The key to be installed
			\param[in] ksize Key size
			*/
			void crypto_srand(const byte1_t *key, byte4_t ksize);
			/*!
			\brief Generates a value
			\param[out] output Generates an array of elements
			\param[in] size Array size
			*/
			void crypto_rand(byte1_t *output, byte4_t size);

		private:
			ubit8_t Sbox[256];
		};

		/*!
		\brief Advanced generator based on Marsen primes
		\note Source URL: www.agner.org/random
		*/
		class MersenneTwister
		{
		public:
			/*!
			\brief Construct a new Mersenne Twister::Mersenne Twister object
			\details Installs the seed
			\param[in] seed Generation seed
			*/
			MersenneTwister(byte4_t seed);
			///-
			sbit32_t rand();
			/*!
			\brief Re-seed
			\param seed Generation seed
			*/
			void RandomInit(byte4_t seed);
			/*!
			\brief Output random integer
			\param min The minimum value that can be generated
			\param max The maximum value that can be generated
			\return int
			*/
			byte4_t IRandom(byte4_t min, byte4_t max);
			/*!
			\brief Output random integer, exact
			\param min The minimum value that can be generated
			\param max The maximum value that can be generated
			\return int
			*/
			byte4_t IRandomX(byte4_t min, byte4_t max);
			/*!
			\brief Output random float
			\return double
			*/
			fbit64_t Random();
			/*!
			\brief Output random bits
			\return uint32_t
			*/
			ubit32_t BRandom();

		private:
			///-
			void Init0(byte4_t seed);
			ubit32_t mersenne_twister[624]; /// State vector
			byte4_t mersenne_twister_index; /// Index into mersenne_twister
			ubit32_t LastInterval;			/// Last interval length for IRandomX
			ubit32_t RejectionLimit;		/// Rejection limit used by IRandomX
		};

		///-
		template <class Generator>
		fbit64_t tester(ubit32_t left_limit, ubit32_t right_limit);
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

	///-
	template <typename type_array>
	class ArrayProcessing
	{
	public:
		/*!
		\brief Finds the minimum element in an array by iterating over
		\tparam type_array The type of elements that the array stores. For example int or float
		\param[in] Array The array in which to look for the minimum element
		\param[in] array_size The size of this very array
		\throw void_data Transferred an empty array
		\return type_array
		*/
		static type_array minimum(const type_array *Array, const asize_t &array_size);

		/*!
		\brief Finds the maximum element in an array by iterating over
		\tparam type_array The type of elements that the array stores. For example int or float
		\param[in] Array The array in which to look for the maximum element
		\param[in] array_size The size of this very array
		\throw void_data Transferred an empty array
		\return type_array
		*/
		static type_array maximum(const type_array *Array, const asize_t &array_size);

		///-
		static bool isOrderliness(const type_array *Array, const asize_t &array_size);

		///-
		static asize_t distance(type_array *first, type_array *last);

		///-
		static type_array *lower_bound(type_array *first, type_array *last, const type_array &value);

		///-
		static type_array *upper_bound(type_array *first, type_array *last, const type_array &value);

		/*!
		\brief Adds a specific value to an array at a specified position
		\tparam type_array The type of elements that the array stores. For example int or float
		\param[in, out] Array The array to which the element is added
		\param[in] array_size The size of this very array
		\param[in] value The element to add to the array
		\param[in] position The position at which the element will be added
		*/
		static void addElement(type_array *&Array, asize_t &array_size, const type_array &value, const asize_t position = 0);

		/*!
		\brief Removes the specified position from the array
		\tparam type_array The type of elements that the array stores. For example int or float
		\param[in, out] Array The array in which the position will be deleted
		\param[in] array_size The size of this very array
		\param[in] position The position at which the element will be removed
		*/
		static void subtractElement(type_array *&Array, asize_t &array_size, const asize_t position);

		/*!
		\brief Removes a specific element from all positions in an array
		\tparam type_array The type of elements that the array stores. For example int or float
		\param[in, out] Array An array in which all elements that match the given value will be removed
		\param[in] array_size The size of this very array
		\param[in] value The value to be removed in the entire array
		*/
		static void subtractValue(type_array *&Array, asize_t &array_size, const type_array &value);

		/*!
		\brief Copies an array
		\tparam type_array The type of elements that the array stores. For example int or float
		\param[in, out] new_array The array into which the data is copied
		\param[in] old_array The array from which to copy
		\param[in] size_of_copied A parameter that indicates how many items to copy
		\param[in] position_in_new_array The position from which to start writing in the array to which the data is copied
		\param[in] position_in_old_array The position from which to start reading from the array, from which the data is copied
		*/
		static void copy(type_array *new_array, const type_array *old_array, const asize_t &size_of_copied, asize_t position_in_new_array = 0, asize_t position_in_old_array = 0);
	};

	/*!
	\brief A structure that mimics an array. Designed to store a pointer to a dynamic array and its size
	\tparam type_array The type of elements that the array stores. For example int or float
	*/
	template <typename type_array>
	struct Array
	{
		type_array *array = nullptr;
		asize_t array_size = 0;
	};

	/*!
	\fn Array<type_array> *create_struct(const asize_t &SIZE)
	\brief Creates a structure with a pointer to an array
	\tparam type_array The type of elements that the array stores. For example int or float
	\param[in] SIZE The size of the array to be created
	\return Array<type_array>* Pointer to array
	*/
	template <typename type_array>
	Array<type_array> *create_struct(const asize_t &SIZE, bool mem_allocation = true);

	///-
	template <typename type_array>
	void generate_struct(type_array *&Array, asize_t &array_size, const sbit64_t &min_limit, const sbit64_t &max_limit, const ubit32_t denominator = 1);

	/*!
	\fn void remove_struct(Array<type_array> *&Array)
	\brief Removes an array and structure from heap
	\tparam type_array The type of elements that the array stores. For example int or float
	\param[in] Array The array to be deleted
	*/
	template <typename type_array>
	void remove_struct(Array<type_array> *&Array);

	/*!
	\brief The base class, which is organized for working with arrays - memory allocation, storage, deletion
	\tparam type_array The type of elements that the array stores. For example int or float
	*/
	template <typename type_array>
	class ArrayBase
	{
	protected:
		/*!
		\brief Construct a new ArrayBase<type_array>::ArrayBase object
		\details With this creation of an object, both the structure and the object of the class will point to the same array
		\tparam type_array The type of elements that the array stores. For example int or float
		\param[in] Array Pointer to a structured array
		*/
		ArrayBase(Array<type_array> *&Array);
		/*!
		\brief Construct a new ArrayBase<type_array>::ArrayBase object
		\details With such an object creation, memory will be allocated for a new array, the pointer to which will be stored only in the class object
		\tparam type_array The type of elements that the array stores. For example int or float
		\param[in] SIZE The size of the array being created
		*/
		ArrayBase(const asize_t &SIZE);
		/*!
		\fn ArrayBase<type_array>::ArrayBase()
		\brief Construct a new ArrayBase<type_array>::ArrayBase object
		\details With this creation of an object, no memory will be allocated for the array. The object will be empty
		\tparam type_array The type of elements that the array stores. For example int or float
		*/
		ArrayBase();

		///-
		void verification(Array<type_array> *Array);

		Array<type_array> *ARRAY = nullptr; ///< Pointer to a structure storing an array
	};

	/*!
	\brief Array processing
	\details This is the main class for working with arrays, the tasks of which
			 are storing a pointer to an array, the ability to create, delete, modify it,
			 calculate characteristics, etc.
	\tparam type_array The type of elements that the array stores. For example int or float
	*/
	template <typename type_array>
	class ARRAYDATA : public ArrayBase<type_array>
	{
	public:
		/*!
		\brief Construct a new arraydata<type array>::arraydata object
		\details With this creation of an object, both the structure and the object of the class will point to the same array. An example of an array object announcement:
		\code
		Array<int> *arr = create_struct(12);
		ARRAYDATA<int> *array = new ARRAYDATA<int>(arr);
		\endcode
		\tparam type_array The type of elements that the array stores. For example int or float
		\param[in] Array Pointer to a structured array
		*/
		ARRAYDATA(Array<type_array> *&Array);
		/*!
		\brief Construct a new arraydata<type array>::arraydata object
		\details With such an object creation, memory will be allocated for a new array, the pointer to which will be stored only in the class object. An example of an array object announcement:
		\code
		ARRAYDATA<int> *array = new ARRAYDATA<int>(12);
		\endcode
		\tparam type_array The type of elements that the array stores. For example int or float
		\param[in] SIZE The size of the array being created
		*/
		ARRAYDATA(const asize_t &SIZE);
		///-
		~ARRAYDATA();

		enum class ArrayType /// A set of array types
		{
			NUMBER, ///< Indicates that the array stores numbers
			STRING	///< Indicates that the array stores strings
		};

		///-
		struct mode : Array<type_array>
		{
			ubit32_t highest_frequency = 0;
		};

		/*!
		\brief A method that fills the entire array with random values
		\code
		array->generatedData(1, 100);
		\endcode
		\tparam type_array The type of elements that the array stores. For example int or float
		\param min_limit The minimum value that can be generated
		\param max_limit The maximum value that can be generated
		*/
		void generatedData(const sbit64_t &min_limit, const sbit64_t &max_limit, const ubit32_t denominator = 1);
		/*!
		\brief A method that replaces the previous array with a new one, freeing memory from the previous one
		\tparam type_array The type of elements that the array stores. For example int or float
		\param Array An array that will replace the previous one in the object
		*/
		void setNewData(Array<type_array> *&Array);
		/*!
		\brief A method that replaces the previous array with a new one without freeing memory from the previous one
		\tparam type_array The type of elements that the array stores. For example int or float
		\param Array An array that will replace the previous one in the object
		*/
		void setData(Array<type_array> *&Array);
		/*!
		\brief Method that replaces the old array by copying the existing one
		\tparam type_array The type of elements that the array stores. For example int or float
		\param CloningArray The array to be copied to the object
		*/
		void cloneData(Array<type_array> *&CloningArray);
		/*!
		\brief Returns a pointer to an array
		\tparam type_array The type of elements that the array stores. For example int or float
		\return Array<type_array>*
		*/
		Array<type_array> *getData();
		///-
		asize_t getSize();
		///-
		Array<asize_t> *getPosition(const type_array &value);
		///-
		type_array getValue(const asize_t &position);

		/*!
		\brief The method removes the old array, creates a new one with the same characteristics
			   (size, minimum and maximum limits) and fills it (unlike respawn (), which does
			   not generate elements).
		\tparam type_array The type of elements that the array stores. For example int or float
		*/
		void reset();
		/*!
		\fn void ARRAYDATA<type_array>::resize(const asize_t &NEW_SIZE, const type_array &setElement)
		\brief Method that resizes the array
		\tparam type_array The type of elements that the array stores. For example int or float
		\param NEW_SIZE New array size
		\param setElement The value with which new cells of the array are filled
		\warning In the case of increasing the size of the array after copying,
				 the new cells remain empty and store "garbage" in themselves.
				 Sometimes, by accident, a programmer can try to get data without
				 specifying it, as a result of which, in the best case, an incorrect
				 result will simply be given, and in the worst case, the program may crash.
				 For this, the setElement parameter was created, but it must be specified
				 not only in case of an increase in size, but always when calling the method
				 for prevention. The programmer may not even know the current size
				 of the array, therefore, he cannot know whether the array will
				 be increased or decreased.
		*/
		void resize(const asize_t &NEW_SIZE, const type_array &setElement);
		/*!
		\brief Changes the value at the specified position
		\tparam type_array The type of elements that the array stores. For example int or float
		\param position The position at which the value changes
		\param value The value to be placed in the position
		*/
		void replace(const asize_t &position, const type_array &value);
		/*!
		\brief Reverses the array
		\tparam type_array The type of elements that the array stores. For example int or float
		*/
		void reverse();
		/*!
		\brief The method deletes the old array, however, the memory for the new array
			   is allocated the same size without filling it, unlike reset()
		\tparam type_array The type of elements that the array stores. For example int or float
		*/
		void respawn();

		/*!
		\brief Optimized method for finding the minimum element
		\tparam type_array The type of elements that the array stores. For example int or float
		\param ArrStat Array status
		\return type_array
		*/
		type_array getMin();
		/*!
		\brief Optimized method for finding the maximum element
		\tparam type_array The type of elements that the array stores. For example int or float
		\param ArrStat Array status
		\return type_array
		*/
		type_array getMax();

		/*!
		\brief Linear item search method
		\details Returns all occurrences of the found value
		\tparam type_array The type of elements that the array stores. For example int or float
		\param required_element The value to find
		\return Array<int>*
		*/
		Array<asize_t> *lenear_searcher(const type_array &required_element);
		/*!
		\brief Binary item search method
		\details Returns only one position and is only used in sorted arrays. It is used to
				 facilitate the programmer's work so that the method does not need to pass a bunch
				 of parameters that are needed in the algorithm, but the launch is always carried
				 out by passing the same values.
		\tparam type_array The type of elements that the array stores. For example int or float
		\param required_element The value to find
		\return int
		*/
		asize_t binary_searcher(const type_array &required_element);
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
		Array<type_array> *operator^=(const asize_t &NewSize);
		/*!
		\brief Operator for increasing an array by a specific size
		\tparam type_array The type of elements that the array stores. For example int or float
		\param addSize Parameter indicating how much to increase the array
		*/
		Array<type_array> *operator+=(const type_array &addValue);
		/*!
		\brief Operator for decreasing an array by a specific size
		\tparam type_array The type of elements that the array stores. For example int or float
		\param subtractSize Parameter indicating how much to reduce the array
		*/
		Array<type_array> *operator-=(const type_array &subtractValue);
		/*!
		\brief Operator for increasing an array by several times
		\tparam type_array The type of elements that the array stores. For example int or float
		\param multiplySize Parameter indicating how many times to increase the array
		*/
		Array<type_array> *operator*=(const type_array &multiplyValue);
		/*!
		\brief Operator for decreasing an array by some times
		\tparam type_array The type of elements that the array stores. For example int or float
		\param divideSize Параметр, указывающий, во сколько раз следует уменьшить массив
		*/
		Array<type_array> *operator/=(const type_array &divideValue);
		/*!
		\brief Operator adding an element to the end of an array
		\tparam type_array The type of elements that the array stores. For example int or float
		\param value The value to add to the end of the array
		*/
		Array<type_array> *operator&=(const type_array &value);
		/*!
		\brief An operator that removes all elements with a specified value
		\tparam type_array The type of elements that the array stores. For example int or float
		\param value The value to be removed
		*/
		Array<type_array> *operator|=(const type_array &value);
		/*!
		\brief Operator that removes an element from the end of an array
		\tparam type_array The type of elements that the array stores. For example int or float
		*/
		Array<type_array> *operator!();
		/*!
		\brief Operator for merging two arrays in the current object
		\tparam type_array The type of elements that the array stores. For example int or float
		\param appendingArray An array to attach from another object
		*/
		Array<type_array> *operator<<=(ARRAYDATA<type_array> *&appendingArray);
		/*!
		\brief Operator for merging two arrays in a received object
		\tparam type_array The type of elements that the array stores. For example int or float
		\param appendingArray An array from another object to which the current array will be passed
		*/
		Array<type_array> *operator>>=(ARRAYDATA<type_array> *&appendingArray);

	private:
		/*!
		\brief Removes an array
		\tparam type_array The type of elements that the array stores. For example int or float
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

	namespace SORTING
	{
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
	}

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
