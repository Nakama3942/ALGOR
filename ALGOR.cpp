/* ******************************   ALGOR.cpp   ******************************* *
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
 * **************************************************************************** */

#include "ALGOR.hpp"

using namespace ALGOR;

/* ****+/^^^/+++++-/&/-+-+-+-/&/-+-+-+-/&/-+-+-+-/&/-+-+-+-/&/-+++++/^^^/+**** *
 * #*****+/^^^/+++++-/+/-+-+                         +-+-/+/-+++++/^^^/+*****# *
 * #*-*%*-*+                                                         +*-*%*-*# *
 * %%%%%                       $------------------$                      %%%%% *
 * -->                              ALGOR_CORE                             <-- *
 * %%%%%                       $------------------$                      %%%%% *
 * #*-*%*-*+                                                         +*-*%*-*# *
 * #*****+/^^^/+++++-/+/-+-+                         +-+-/+/-+++++/^^^/+*****# *
 * ****+/^^^/+++++-/&/-+-+-+-/&/-+-+-+-/&/-+-+-+-/&/-+-+-+-/&/-+++++/^^^/+**** */

template<typename type_value>
void ALGOR::CORE<type_value>::swap(type_value &firstNumber, type_value &secondNumber) noexcept
{
	type_value temp = firstNumber;
	firstNumber = secondNumber;
	secondNumber = temp;
}

template<typename type_value>
type_value ALGOR::CORE<type_value>::minimum(type_value firstNumber, type_value secondNumber) noexcept
{
	return firstNumber < secondNumber ? firstNumber : secondNumber;
}

template<typename type_value>
type_value ALGOR::CORE<type_value>::maximum(type_value firstNumber, type_value secondNumber) noexcept
{
	return firstNumber > secondNumber ? firstNumber : secondNumber;
}

memcell_t ALGOR::getMemoryCell()
{
	memcell_t *cells = new memcell_t[10];
	memcell_t *cell = new memcell_t(cells[0]);
	for (ubit32_t i = 1; i < 8; i++)
	{
		*cell >>= (memcell_t)cells[i];
		*cell <<= (memcell_t)cells[i + 1];
		*cell ^= (memcell_t)cells[i + 2];
	}
	return *cell;
}

memcell_t ALGOR::getMemoryCell(memcell_t right_adjust, memcell_t left_adjust)
{
	memcell_t *cells = new memcell_t[10];
	memcell_t *cell = new memcell_t(cells[0]);
	for (ubit32_t i = 1; i < 8; i++)
	{
		*cell >>= (memcell_t)cells[i];
		*cell <<= (memcell_t)cells[i + 1];
		*cell ^= (memcell_t)cells[i + 2];
		if (right_adjust != 0)
		{
			*cell >>= right_adjust;
		}
		if (left_adjust != 0)
		{
			*cell <<= left_adjust;
		}
	}
	return *cell;
}

/* ****+/^^^/+++++-/&/-+-+-+-/&/-+-+-+-/&/-+-+-+-/&/-+-+-+-/&/-+++++/^^^/+**** *
 * #*****+/^^^/+++++-/+/-+-+                         +-+-/+/-+++++/^^^/+*****# *
 * #*-*%*-*+                                                         +*-*%*-*# *
 * %%%%%                      $-------------------$                      %%%%% *
 * -->                           ALGOR_EXCEPTION                           <-- *
 * %%%%%                      $-------------------$                      %%%%% *
 * #*-*%*-*+                                                         +*-*%*-*# *
 * #*****+/^^^/+++++-/+/-+-+                         +-+-/+/-+++++/^^^/+*****# *
 * ****+/^^^/+++++-/&/-+-+-+-/&/-+-+-+-/&/-+-+-+-/&/-+-+-+-/&/-+++++/^^^/+**** */

ALGOR::Exception::Exception(ubit16_t CODE, const char *DETAILS, const char *EXPLANATION)
{
	this->CODE = CODE;
	this->DETAILS = DETAILS;
	this->EXPLANATION = EXPLANATION;
}

ALGOR::Exception::Exception(ubit16_t CODE, const char *DETAILS)
{
	this->CODE = CODE;
	this->DETAILS = DETAILS;
	this->EXPLANATION = "No information given";
}

ALGOR::Exception::Exception(ubit16_t CODE)
{
	this->CODE = CODE;
	this->DETAILS = "No information given";
	this->EXPLANATION = "No information given";
}

ALGOR::Exception::Exception(const char *DETAILS)
{
	this->CODE = 0xffff;
	this->DETAILS = DETAILS;
	this->EXPLANATION = "No information given";
}

ubit16_t ALGOR::Exception::code()
{
	return CODE;
}

const char *ALGOR::Exception::what()
{
	return DETAILS;
}

const char *Exception::why()
{
	return EXPLANATION;
}

ALGOR::memory_overflow::memory_overflow() : Exception(55, "The memory cell that stores the size of the data volume can no longer store more. This error can occur in cases when a larger value is required to be written to the cell that can store the variable 0xffffffff, i.e. more than 4 bytes, since the data size storage cell occupies 4 bytes") {}
ALGOR::memory_overflow::memory_overflow(const char *explanation) : Exception(55, "The memory cell that stores the size of the data volume can no longer store more. This error can occur in cases when a larger value is required to be written to the cell that can store the variable 0xffffffff, i.e. more than 4 bytes, since the data size storage cell occupies 4 bytes", explanation) {}

ALGOR::division_by_zero::division_by_zero() : Exception(101, "A division by zero has occurred - an undefined result of the program execution") {}
ALGOR::division_by_zero::division_by_zero(const char *explanation) : Exception(101, "A division by zero has occurred - an undefined result of the program execution", explanation) {}

ALGOR::position_failure::position_failure() : Exception(254, "Position failure - position is missing in the array") {}
ALGOR::position_failure::position_failure(const char *explanation) : Exception(254, "Position failure - position is missing in the array", explanation) {}

ALGOR::value_failure::value_failure() : Exception(255, "Value failure - value is missing in the array") {}
ALGOR::value_failure::value_failure(const char *explanation) : Exception(255, "Value failure - value is missing in the array", explanation) {}

ALGOR::size_failure::size_failure() : Exception(256, "Size failure - resizing error; for example, it can occur when the sizes match when the array is resized, or the new size is greater/less than limits sizes") {}
ALGOR::size_failure::size_failure(const char *explanation) : Exception(256, "Size failure - resizing error; for example, it can occur when the sizes match when the array is resized, or the new size is greater/less than limits sizes", explanation) {}

ALGOR::void_data::void_data() : Exception(400, "Geted empty data structure") {}
ALGOR::void_data::void_data(const char *explanation) : Exception(400, "Geted empty data structure", explanation) {}

ALGOR::not_found::not_found() : Exception(404, "Search error - item not found") {}
ALGOR::not_found::not_found(const char *explanation) : Exception(404, "Search error - item not found", explanation) {}

/* ****+/^^^/+++++-/&/-+-+-+-/&/-+-+-+-/&/-+-+-+-/&/-+-+-+-/&/-+++++/^^^/+**** *
 * #*****+/^^^/+++++-/+/-+-+                         +-+-/+/-+++++/^^^/+*****# *
 * #*-*%*-*+                                                         +*-*%*-*# *
 * %%%%%                       $------------------$                      %%%%% *
 * -->                             ALGOR_RANDOM                            <-- *
 * %%%%%                       $------------------$                      %%%%% *
 * #*-*%*-*+                                                         +*-*%*-*# *
 * #*****+/^^^/+++++-/+/-+-+                         +-+-/+/-+++++/^^^/+*****# *
 * ****+/^^^/+++++-/&/-+-+-+-/&/-+-+-+-/&/-+-+-+-/&/-+-+-+-/&/-+++++/^^^/+**** */

// int RC4::crypto_entropy()
//{
//     //Collects entropy
//     //WARNING Может быть реализован в Линуксе
//     return 0;
// }

void ALGOR::RC4::crypto_srand(const char *key, int ksize)
{
	ubit8_t j = 0;
	for (int i = 0; i < 256; i++)
	{
		Sbox[i] = i;
	}
	for (int i = 0; i < 256; i++)
	{
		j = j + Sbox[i] + (ubit8_t)key[i % ksize];
		CORE<ubit8_t>::swap(Sbox[i], Sbox[j]);
	}
}

void ALGOR::RC4::crypto_rand(char *output, int size)
{
	ubit8_t i = 0, j = 0, t;
	for (int k = 0; i < size; k++)
	{
		i += 1;
		j += Sbox[i];
		CORE<ubit8_t>::swap(Sbox[i], Sbox[j]);
		t = Sbox[i] + Sbox[j];
		output[k] = (unsigned int)Sbox[t];
	}
}

ALGOR::MersenneTwister::MersenneTwister(int seed)
{
	RandomInit(seed);
	LastInterval = 0;
}

void ALGOR::MersenneTwister::RandomInit(int seed)
{
	Init0(seed);
	for (int i = 0; i < 37; i++)
	{
		BRandom();
	}
}

int ALGOR::MersenneTwister::IRandom(int min, int max)
{
	if (max <= min)
	{
		return max == min ? min : 0x80000000;
	}
	int rand_int = int((double)(ubit32_t)(max - min + 1) * Random() + min);
	if (rand_int > max)
	{
		rand_int = max;
	}
	return rand_int;
}

int ALGOR::MersenneTwister::IRandomX(int min, int max)
{
	if (max <= min)
	{
		return max == min ? min : 0x80000000;
	}
	ubit32_t len_interval; // Length of interval
	ubit64_t long_rbi;	   // Random bits * interval
	ubit32_t iran;		   // long_rbi / 2^32
	ubit32_t remainder;	   // long_rbi % 2^32

	len_interval = ubit32_t(max - min + 1);
	if (len_interval != LastInterval)
	{
		RejectionLimit = ubit32_t(((ubit64_t)1 << 32) / len_interval) * len_interval - 1;
		LastInterval = len_interval;
	}
	do
	{
		long_rbi = (ubit64_t)BRandom() * len_interval;
		iran = (ubit32_t)(long_rbi >> 32);
		remainder = (ubit32_t)long_rbi;
	} while (remainder > RejectionLimit);
	return (sbit32_t)iran + min;
}

double ALGOR::MersenneTwister::Random()
{
	return (double)BRandom() * (1. / (65536. * 65536.));
}

ubit32_t ALGOR::MersenneTwister::BRandom()
{
	ubit32_t resulting_bit;
	if (mersenne_twister_index >= 624)
	{
		const ubit32_t LOWER_MASK = (1LU << 31) - 1;  // Lower bits
		const ubit32_t UPPER_MASK = 0xFFFFFFFF << 31; // Upper bits
		static const ubit32_t mask[2] = {0, 0x9908B0DF};
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

void ALGOR::MersenneTwister::Init0(int seed)
{
	// Basic initialization procedure
	const ubit32_t factor = 1812433253UL;
	mersenne_twister[0] = seed;
	for (mersenne_twister_index = 1; mersenne_twister_index < 624; mersenne_twister_index++)
	{
		mersenne_twister[mersenne_twister_index] = (factor * (mersenne_twister[mersenne_twister_index - 1] ^ (mersenne_twister[mersenne_twister_index - 1] >> 30)) + mersenne_twister_index);
	}
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
type_array ALGOR::ArrayProcessing<type_array>::minimum(const type_array *Array, const asize_t &array_size)
{
	type_array point_min = Array[0];
	for (asize_t i = 1; i < array_size; i++)
	{
		if (point_min > Array[i])
		{
			point_min = Array[i];
		}
	}
	return point_min;
}

template <typename type_array>
type_array ALGOR::ArrayProcessing<type_array>::maximum(const type_array *Array, const asize_t &array_size)
{
	type_array point_max = Array[0];
	for (asize_t i = 1; i < array_size; i++)
	{
		if (point_max < Array[i])
		{
			point_max = Array[i];
		}
	}
	return point_max;
}

template <typename type_array>
bool ALGOR::ArrayProcessing<type_array>::isOrderliness(const type_array *Array, const asize_t &array_size)
{
	for (asize_t i = 0; i < array_size - 1; i++)
	{
		if (Array[i] > Array[i + 1])
		{
			return false;
		}
	}
	return true;
}

template <typename type_array>
asize_t ALGOR::ArrayProcessing<type_array>::distance(type_array *first, type_array *last)
{
	//http://www.cplusplus.com/reference/iterator/distance/?kw=distance
	return last - first;
}

template <typename type_array>
type_array *ALGOR::ArrayProcessing<type_array>::lower_bound(type_array *first, type_array *last, const type_array &value)
{
	//http://www.cplusplus.com/reference/algorithm/lower_bound/
	asize_t count = distance(first, last), step = 0, iterator = 0;
	while (count > 0)
	{
		step = count / 2;
		iterator = step;
		if (first[iterator] < value)
		{
			first = &first[++iterator];
			count -= (step + 1);
		}
		else
		{
			count = step;
		}
	}
	return first;
}

template<typename type_array>
type_array *ArrayProcessing<type_array>::upper_bound(type_array *first, type_array *last, const type_array &value)
{
	//http://www.cplusplus.com/reference/algorithm/upper_bound/
	asize_t count = distance(first, last), step = 0, iterator = 0;
	while (count > 0)
	{
		step = count / 2;
		iterator = step;
		if (!(value < first[iterator]))
		{
			first = &first[++iterator];
			count -= (step + 1);
		}
		else
		{
			count = step;
		}
	}
	return first;
}

template <typename type_array>
void ALGOR::ArrayProcessing<type_array>::addElement(type_array *&Array, asize_t &array_size, const type_array &value, const asize_t position)
{
	array_size++;
	if (array_size > 0xffffffff)
	{
		throw memory_overflow();
	}
	if (array_size == 1)
	{
		Array = new type_array[array_size]{value};
		return;
	}
	type_array *temp_Array = new type_array[array_size];
	for (asize_t i = 0; i < array_size; i++)
	{
		position > i ? temp_Array[i] = Array[i] : (position == i ? temp_Array[i] = value : temp_Array[i] = Array[i - 1]);
	}
	delete[] Array;
	Array = temp_Array;
}

template <typename type_array>
void ALGOR::ArrayProcessing<type_array>::subtractElement(type_array *&Array, asize_t &array_size, const asize_t position)
{
	if (array_size == 0)
	{
		throw void_data();
	}
	if (position >= array_size)
	{
		throw position_failure();
	}
	array_size--;
	if (array_size == 0)
	{
		delete[] Array;
		return;
	}
	type_array *temp_Array = new type_array[array_size];
	for (asize_t i = 0; i < array_size; i++)
	{
		position > i ? temp_Array[i] = Array[i] : temp_Array[i] = Array[i + 1];
	}
	delete[] Array;
	Array = temp_Array;
}

template <typename type_array>
void ALGOR::ArrayProcessing<type_array>::subtractValue(type_array *&Array, asize_t &array_size, const type_array &value)
{
	if (array_size == 0)
	{
		throw void_data();
	}
	ubit32_t deletions_count = 0;
	type_array *temp_Array = new type_array[array_size];
	for (asize_t i = 0; i < array_size; i++)
	{
		Array[i] != value ? temp_Array[i - deletions_count] = Array[i] : deletions_count++;
	}
	if (deletions_count == 0)
	{
		delete[] temp_Array;
		throw value_failure();
	}
	delete[] Array;
	array_size -= deletions_count;
	Array = new type_array[array_size];
	copy(Array, temp_Array, array_size);
	delete[] temp_Array;
}

template <typename type_array>
void ALGOR::ArrayProcessing<type_array>::copy(type_array *new_array, const type_array *old_array, const asize_t &size_of_copied, asize_t position_in_new_array, asize_t position_in_old_array)
{
	for (asize_t i = 0; i < size_of_copied; i++)
	{
		new_array[i + position_in_new_array] = old_array[i + position_in_old_array];
	}
}

template <typename type_array>
Array<type_array> *ALGOR::create_struct(const asize_t &SIZE, bool mem_allocation)
{
	if (SIZE == 0)
	{
		throw void_data();
	}
	Array<type_array> *ARRAY = new Array<type_array>;
	ARRAY->array_size = SIZE;
	if (mem_allocation)
	{
		ARRAY->array = new type_array[SIZE];
	}
	return ARRAY;
}

template <typename type_array>
void ALGOR::remove_struct(Array<type_array> *&Array)
{
	if (Array == nullptr || Array->array == nullptr)
	{
		throw void_data();
	}
	delete[] Array->array;
	delete (Array);
	Array = nullptr;
}

template <typename type_array>
ALGOR::ArrayBase<type_array>::ArrayBase(Array<type_array> *&Array)
{
	verification(Array);
	ARRAY = Array;
}

template <typename type_array>
ALGOR::ArrayBase<type_array>::ArrayBase(const asize_t &SIZE)
{
	ARRAY = create_struct<type_array>(SIZE);
}

template<typename type_array>
ALGOR::ArrayBase<type_array>::ArrayBase() {}

template<typename type_array>
void ALGOR::ArrayBase<type_array>::verification(Array<type_array> *Array)
{
	if (Array == nullptr || Array->array_size == 0 || Array->array == nullptr)
	{
		throw void_data();
	}
}

template <typename type_array>
ALGOR::ARRAYDATA<type_array>::ARRAYDATA(Array<type_array> *&Array) : ArrayBase<type_array>(Array) {}

template <typename type_array>
ALGOR::ARRAYDATA<type_array>::ARRAYDATA(const asize_t &SIZE) : ArrayBase<type_array>(SIZE) {}

template <typename type_array>
void ALGOR::ARRAYDATA<type_array>::generatedData(const sbit64_t &min_limit, const sbit64_t &max_limit, const ubit8_t denominator)
{
	memcell_t cell = getMemoryCell();
	cell >>= 32;
	MersenneTwister RanGen(cell);
	for (asize_t i = 0; i < this->ARRAY->array_size; i++)
	{
		this->ARRAY->array[i] = RanGen.IRandom(min_limit, max_limit) / denominator;
	}
}

template <typename type_array>
void ALGOR::ARRAYDATA<type_array>::setNewData(Array<type_array> *&Array)
{
	this->verification(Array);
	remove();
	this->ARRAY = Array;
}

template <typename type_array>
void ALGOR::ARRAYDATA<type_array>::setData(Array<type_array> *&Array)
{
	this->verification(Array);
	this->ARRAY = Array;
}

template <typename type_array>
void ALGOR::ARRAYDATA<type_array>::cloneData(Array<type_array> *&Array)
{
	this->verification(Array);
	if (Array->array_size != this->ARRAY->array_size)
	{
		remove();
		this->ARRAY = create_struct<type_array>(Array->array_size);
	}
	ArrayProcessing<type_array>::copy(this->ARRAY->array, Array->array, Array->array_size);
}

template <typename type_array>
Array<type_array> *ALGOR::ARRAYDATA<type_array>::getData()
{
	return this->ARRAY;
}

template<typename type_array>
asize_t ARRAYDATA<type_array>::getSize()
{
	return this->ARRAY->array_size;
}

template <typename type_array>
void ALGOR::ARRAYDATA<type_array>::reset()
{
	asize_t SIZE = this->ARRAY->array_size;
	remove();
	this->ARRAY = create_struct<type_array>(SIZE);

}

template <typename type_array>
void ALGOR::ARRAYDATA<type_array>::resize(const asize_t &NEW_SIZE, const type_array &setElement)
{
	if (NEW_SIZE == this->ARRAY->array_size)
	{
		throw size_failure();
	}
	Array<type_array> *OLD_ARRAY = this->ARRAY, *NEW_ARRAY = create_struct<type_array>(NEW_SIZE);
	asize_t min_size = CORE<type_array>::minimum(OLD_ARRAY->array_size, NEW_ARRAY->array_size);
	ArrayProcessing<type_array>::copy(NEW_ARRAY->array, OLD_ARRAY->array, min_size);
	for (asize_t i = OLD_ARRAY->array_size; i < NEW_ARRAY->array_size; i++)
	{
		NEW_ARRAY->array[i] = setElement;
	}
	this->ARRAY = NEW_ARRAY;
	remove_struct<type_array>(OLD_ARRAY);
}

template <typename type_array>
void ALGOR::ARRAYDATA<type_array>::replace(const asize_t &position, const type_array &value)
{
	this->ARRAY->array[position] = value;
}

template <typename type_array>
void ALGOR::ARRAYDATA<type_array>::reverse()
{
	asize_t left_limit = 0, right_limit = this->ARRAY->array_size - 1;
	for (asize_t i = 0; i < this->ARRAY->array_size / 2; i++)
	{
		CORE<type_array>::swap(this->ARRAY->array[left_limit], this->ARRAY->array[right_limit]);
		left_limit++;
		right_limit--;
	}
}

template <typename type_array>
void ALGOR::ARRAYDATA<type_array>::respawn()
{
	type_array min = getMin(), max = getMax();
	reset();
	generatedData(min, max);
}

template <typename type_array>
void ALGOR::ARRAYDATA<type_array>::remove()
{
	remove_struct<type_array>(this->ARRAY);
}

template <typename type_array>
type_array ALGOR::ARRAYDATA<type_array>::getMin()
{
	return ArrayProcessing<type_array>::isOrderliness(this->ARRAY->array, this->ARRAY->array_size) ? this->ARRAY->array[0] : ArrayProcessing<type_array>::minimum(this->ARRAY->array, this->ARRAY->array_size);
}

template <typename type_array>
type_array ALGOR::ARRAYDATA<type_array>::getMax()
{
	return ArrayProcessing<type_array>::isOrderliness(this->ARRAY->array, this->ARRAY->array_size) ? this->ARRAY->array[this->ARRAY->array_size - 1] : ArrayProcessing<type_array>::maximum(this->ARRAY->array, this->ARRAY->array_size);
}

template <typename type_array>
Array<asize_t> *ALGOR::ARRAYDATA<type_array>::lenear_searcher(const type_array &required_element)
{
	Array<asize_t> *NumberPoints = new Array<asize_t>;
	for (asize_t i = 0; i < this->ARRAY->array_size; i++)
	{
		if (required_element == this->ARRAY->array[i])
		{
			ArrayProcessing<asize_t>::addElement(NumberPoints->array, NumberPoints->array_size, i, NumberPoints->array_size);
		}
	}
	if (NumberPoints->array_size == 0)
	{
		throw not_found();
	}
	return NumberPoints;
}

template <typename type_array>
asize_t ALGOR::ARRAYDATA<type_array>::binary_searcher(const type_array &required_element)
{
	asize_t position = ArrayProcessing<type_array>::distance(&this->ARRAY->array[0], ArrayProcessing<type_array>::lower_bound(&this->ARRAY->array[0], &this->ARRAY->array[this->ARRAY->array_size - 1], required_element));
	if(this->ARRAY->array[position] != required_element)
	{
		throw not_found();
	}
	return position;
}

template <typename type_array>
Array<asize_t> *ALGOR::ARRAYDATA<type_array>::searcherOccurrencesOfSubstring(Array<type_array> *&SUBARRAY, ArrayType ArrType)
{
	Array<asize_t> *Occurrences = new Array<asize_t>;
	for (asize_t i = 0; i <= this->ARRAY->array_size - SUBARRAY->array_size; i++)
	{
		for (asize_t j = 0; j < SUBARRAY->array_size; j++)
		{
			if (this->ARRAY->array[i + j] == SUBARRAY->array[j])
			{
				switch (ArrType)
				{
				case ARRAYDATA::ArrayType::NUMBER:
					if (SUBARRAY->array_size - j == 1)
					{
						ArrayProcessing<asize_t>::addElement(Occurrences->array, Occurrences->array_size, i, Occurrences->array_size);
					}
					break;
				case ARRAYDATA::ArrayType::STRING:
					if (SUBARRAY->array_size - j == 2)
					{
						ArrayProcessing<asize_t>::addElement(Occurrences->array, Occurrences->array_size, i, Occurrences->array_size);
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
		throw not_found();
	}
	return Occurrences;
}

template <typename type_array>
type_array ALGOR::ARRAYDATA<type_array>::average()
{
	type_array average = 0;
	for (asize_t i = 0; i < this->ARRAY->array_size; i++)
	{
		average += this->ARRAY->array[i];
	}
	if (this->ARRAY->array_size == 0)
	{
		throw division_by_zero("Any non-empty array can get into the class, or the class itself can create it. However, you can get the array structure from the class and access the data directly. The author has only one explanation: you somehow reset the size of the array through the structure and now the class works with broken data - in the average() method, the division by the size of the array takes place, which became equal to zero...");
	}
	return average / this->ARRAY->array_size;
}

template <typename type_array>
type_array ALGOR::ARRAYDATA<type_array>::mediana()
{
	return this->ARRAY->array_size & 1 ? (this->ARRAY->array[this->ARRAY->array_size / 2]) : (this->ARRAY->array[this->ARRAY->array_size / 2] + this->ARRAY->array[(this->ARRAY->array_size / 2) - 1]) / 2;
}

template <typename type_array>
typename ARRAYDATA<type_array>::mode *ARRAYDATA<type_array>::moda()
{
	//Выделение памяти под данные
	mode *modes = new mode;
	modes->array_size = 1;
	modes->array = new type_array[1];
	ubit32_t current_frequency = 0;

	//Нахождение первого элемента с максимальной частотой
	for (asize_t i = 0; i < this->ARRAY->array_size; i++)
	{
		current_frequency++;
		if (i == this->ARRAY->array_size - 1 || this->ARRAY->array[i] != this->ARRAY->array[i + 1])
		{
			if (modes->highest_frequency < current_frequency)
			{
				modes->highest_frequency = current_frequency;
				modes->array[0] = this->ARRAY->array[i];
			}
			current_frequency = 0;
		}
	}

	//Если все значения уникальны - бросается исключение
	if (modes->highest_frequency == 1)
	{
		delete[] modes->array;
		delete(modes);
		throw value_failure("And to be precise: there is missing value with the maximum frequency. All elements in the array are unique and repeated once, so to save resources and time, an exception is thrown so that the method does not create a copy of the array further");
	}

	//Нахождение всех последующих элементов с этой частотой
	current_frequency = 0;
	for (asize_t i = 0; i < this->ARRAY->array_size; i++)
	{
		if (modes->array[0] == this->ARRAY->array[i])
		{
			for (asize_t j = i + modes->highest_frequency; j < this->ARRAY->array_size; j++)
			{
				current_frequency++;
				if (j == this->ARRAY->array_size - 1 || this->ARRAY->array[j] != this->ARRAY->array[j + 1])
				{
					if (current_frequency == modes->highest_frequency)
					{
						ArrayProcessing<type_array>::addElement(modes->array, modes->array_size, this->ARRAY->array[j], modes->array_size);
					}
					current_frequency = 0;
				}
			}
			break;
		}
	}
	return modes;
}

template <typename type_array>
void ALGOR::ARRAYDATA<type_array>::operator&&(const type_array &value)
{
	ArrayProcessing<type_array>::addElement(this->ARRAY->array, this->ARRAY->array_size, value, this->ARRAY->array_size);
}

template <typename type_array>
void ALGOR::ARRAYDATA<type_array>::operator!()
{
	ArrayProcessing<type_array>::subtractElement(this->ARRAY->array, this->ARRAY->array_size, this->ARRAY->array_size - 1);
}

template <typename type_array>
void ALGOR::ARRAYDATA<type_array>::operator||(const type_array &value)
{
	ArrayProcessing<type_array>::subtractValue(this->ARRAY->array, this->ARRAY->array_size, value);
}

template <typename type_array>
void ALGOR::ARRAYDATA<type_array>::operator<<(ARRAYDATA<type_array> *&appendingArray)
{
	asize_t old_size = this->ARRAY->array_size;
	resize(old_size + appendingArray->getSize(), 1);
	ArrayProcessing<type_array>::copy(this->ARRAY->array, appendingArray->getData()->array, appendingArray->getSize(), old_size);
}

template <typename type_array>
void ALGOR::ARRAYDATA<type_array>::operator>>(ARRAYDATA<type_array> *&appendingArray)
{
	asize_t old_size = appendingArray->getSize();
	appendingArray->resize(old_size + this->ARRAY->array_size, 1);
	ArrayProcessing<type_array>::copy(appendingArray->getData()->array, this->ARRAY->array, this->ARRAY->array_size, old_size);
}

template <typename type_array>
void ALGOR::ARRAYDATA<type_array>::operator+(const asize_t &addSize)
{
	resize(this->ARRAY->array_size + addSize, 1);
}

template <typename type_array>
void ALGOR::ARRAYDATA<type_array>::operator-(const asize_t &subtractSize)
{
	if (subtractSize >= this->ARRAY->array_size)
	{
		throw size_failure("In this case, the size is less than zero. Previously, in this case, the array was simply deleted and the pointer began to point to empty unallocated memory, and there is no and will not be a method for allocating memory in the class. In addition, the security architecture of the ARRAYDATA class does not allow you to store a pointer to an empty memory area. Therefore, now, in this case, deletion of the array is prohibited and this exception is thrown. THE SUBTRACTED ARRAY SIZE MUST NOT BE GREATER THAN OR EQUAL TO THE CURRENT ARRAY SIZE!");
	}
	resize(this->ARRAY->array_size - subtractSize, 1);
}

template <typename type_array>
void ALGOR::ARRAYDATA<type_array>::operator*(const asize_t &multiplySize)
{
	resize(this->ARRAY->array_size * multiplySize, 1);
}

template <typename type_array>
void ALGOR::ARRAYDATA<type_array>::operator/(const asize_t &divideSize)
{
	if (divideSize > this->ARRAY->array_size)
	{
		throw size_failure("In this case, the size is zero. Previously, in this case, the array was simply deleted and the pointer began to point to empty unallocated memory, and there is no and will not be a method for allocating memory in the class. In addition, the security architecture of the ARRAYDATA class does not allow you to store a pointer to an empty memory area. Therefore, now, in this case, deletion of the array is prohibited and this exception is thrown. THE SUBTRACTED ARRAY SIZE MUST NOT BE GREATER THAN OR EQUAL TO THE CURRENT ARRAY SIZE!");
	}
	resize(this->ARRAY->array_size / divideSize, 1);
}

/* ****+/^^^/+++++-/&/-+-+-+-/&/-+-+-+-/&/-+-+-+-/&/-+-+-+-/&/-+++++/^^^/+**** *
 * #*****+/^^^/+++++-/+/-+-+                         +-+-/+/-+++++/^^^/+*****# *
 * #*-*%*-*+                                                         +*-*%*-*# *
 * %%%%%                      $-------------------$                      %%%%% *
 * -->                            ALGOR_SORTING                            <-- *
 * %%%%%                      $-------------------$                      %%%%% *
 * #*-*%*-*+                                                         +*-*%*-*# *
 * #*****+/^^^/+++++-/+/-+-+                         +-+-/+/-+++++/^^^/+*****# *
 * ****+/^^^/+++++-/&/-+-+-+-/&/-+-+-+-/&/-+-+-+-/&/-+-+-+-/&/-+++++/^^^/+**** */

template <typename  type_array>
ALGOR::Comparative_Sorts<type_array>::Comparative_Sorts(Array<type_array> *&Array) : ArrayBase<type_array>(Array) {}

template <typename type_array>
void ALGOR::Comparative_Sorts<type_array>::Bubble_Sort()
{
	BubbleSort *sort = new BubbleSort(this->ARRAY->array, this->ARRAY->array_size);
	sort->bubble_sort();
	delete (sort);
}

template <typename type_array>
void ALGOR::Comparative_Sorts<type_array>::Cocktail_Shaker_Sort()
{
	CocktailShakerSort *sort = new CocktailShakerSort(this->ARRAY->array, this->ARRAY->array_size);
	sort->cocktail_shaker_sort();
	delete (sort);
}

template <typename type_array>
void ALGOR::Comparative_Sorts<type_array>::Odd_Even_Sort()
{
	OddEvenSort *sort = new OddEvenSort(this->ARRAY->array, this->ARRAY->array_size);
	sort->odd_even_sort();
	delete (sort);
}

template <typename type_array>
void ALGOR::Comparative_Sorts<type_array>::Comb_Sort()
{
	CombSort *sort = new CombSort(this->ARRAY->array, this->ARRAY->array_size);
	sort->comb_sort();
	delete (sort);
}

template <typename type_array>
void ALGOR::Comparative_Sorts<type_array>::Gnome_Sort()
{
	GnomeSort *sort = new GnomeSort(this->ARRAY->array, this->ARRAY->array_size);
	sort->gnome_sort();
	delete (sort);
}

template <typename type_array>
void ALGOR::Comparative_Sorts<type_array>::Quick_Sort()
{
	QuickSort *sort = new QuickSort(this->ARRAY->array, this->ARRAY->array_size);
	sort->quick_sort();
	delete (sort);
}

template <typename type_array>
void ALGOR::Comparative_Sorts<type_array>::Slow_Sort()
{
	SlowSort *sort = new SlowSort(this->ARRAY->array, this->ARRAY->array_size);
	sort->slow_sort();
	delete (sort);
}

template <typename type_array>
void ALGOR::Comparative_Sorts<type_array>::Stooge_Sort()
{
	StoogeSort *sort = new StoogeSort(this->ARRAY->array, this->ARRAY->array_size);
	sort->stooge_sort();
	delete (sort);
}

template <typename type_array>
void ALGOR::Comparative_Sorts<type_array>::Bogo_Sort()
{
	BogoSort *sort = new BogoSort(this->ARRAY->array, this->ARRAY->array_size);
	sort->bogo_sort();
	delete (sort);
}

template <typename type_array>
void ALGOR::Comparative_Sorts<type_array>::Selection_Sort()
{
	SelectionSort *sort = new SelectionSort(this->ARRAY->array, this->ARRAY->array_size);
	sort->selection_sort();
	delete (sort);
}

template <typename type_array>
void ALGOR::Comparative_Sorts<type_array>::Heap_Sort()
{
	HeapSort *sort = new HeapSort(this->ARRAY->array, this->ARRAY->array_size);
	sort->heap_sort();
	delete (sort);
}

template <typename type_array>
void ALGOR::Comparative_Sorts<type_array>::Smooth_Sort()
{
	SmoothSort sort(this->ARRAY->array, (int)this->ARRAY->array_size);
	sort.smooth_sort();
}

template <typename type_array>
void ALGOR::Comparative_Sorts<type_array>::Cycle_Sort()
{
	CycleSort *sort = new CycleSort(this->ARRAY->array, this->ARRAY->array_size);
	sort->cycle_sort();
	delete (sort);
}

template <typename type_array>
void ALGOR::Comparative_Sorts<type_array>::Insert_Sort()
{
	InsertSort *sort = new InsertSort(this->ARRAY->array, this->ARRAY->array_size);
	sort->insert_sort();
	delete (sort);
}

template <typename type_array>
void ALGOR::Comparative_Sorts<type_array>::Shell_Sort()
{
	ShellSort *sort = new ShellSort(this->ARRAY->array, this->ARRAY->array_size);
	sort->shell_sort();
	delete (sort);
}

template <typename type_array>
void ALGOR::Comparative_Sorts<type_array>::Tree_Sort()
{
	TreeSort *sort = new TreeSort(this->ARRAY->array, this->ARRAY->array_size);
	sort->tree_sort();
	delete (sort);
}

template <class type_array>
void Comparative_Sorts<type_array>::Library_Sort()
{
	LibrarySort *sort = new LibrarySort(this->ARRAY->array, this->ARRAY->array_size);
	sort->library_sort();
	delete (sort);
}

template <typename type_array>
void ALGOR::Comparative_Sorts<type_array>::Patience_Sort()
{
	PatienceSort *sort = new PatienceSort(this->ARRAY->array, this->ARRAY->array_size);
	sort->patience_sort();
	delete (sort);
}

template <typename type_array>
void ALGOR::Comparative_Sorts<type_array>::Merge_Sort()
{
	MergeSort *sort = new MergeSort(this->ARRAY->array, this->ARRAY->array_size);
	sort->merge_sort();
	delete (sort);
}

template<typename type_array>
void Comparative_Sorts<type_array>::Bitonic_Sorter()
{
	BitonicSorter *sort = new BitonicSorter(this->ARRAY->array, this->ARRAY->array_size);
	sort->bitonic_sorter();
	delete (sort);
}

template<typename type_array>
void Comparative_Sorts<type_array>::Tim_Sort()
{
	TimSort *sort = new TimSort(this->ARRAY->array, this->ARRAY->array_size);
	sort->tim_sort();
	delete (sort);
}

template<typename type_array>
void Comparative_Sorts<type_array>::Pancake_Sort()
{
	PancakeSort *sort = new PancakeSort(this->ARRAY->array, this->ARRAY->array_size);
	sort->pancake_sort();
	delete (sort);
}

template<typename type_array>
Comparative_Sorts<type_array>::BitonicSorter::BitonicSorter(type_array *array, asize_t asize) : Array(array), array_size(asize) {}

template<typename type_array>
void Comparative_Sorts<type_array>::BitonicSorter::bitonic_sorter()
{
	for (asize_t k = 2; k <= array_size; k *= 2)
	{
		for (asize_t j = k / 2; j > 0; j /= 2)
		{
			for (asize_t i = 0; i < array_size; i++)
			{
				asize_t l = i ^ j;
				if (l > i)
				{
					if ( ( ((i & k) == 0) && (Array[i] > Array[l]) ) || ( ((i & k) != 0) && (Array[i] < Array[l]) ) )
					{
						CORE<type_array>::swap(Array[i], Array[l]);
					}
				}
			}
		}
	}
}

template <typename type_array>
ALGOR::Comparative_Sorts<type_array>::BogoSort::BogoSort(type_array *array, asize_t asize) : Array(array), array_size(asize) {}

template <typename type_array>
void ALGOR::Comparative_Sorts<type_array>::BogoSort::bogo_sort()
{
	while (Correct())
	{
		Shuffle();
	}
}

template <typename type_array>
bool ALGOR::Comparative_Sorts<type_array>::BogoSort::Correct()
{
	asize_t size = array_size;
	while (--size > 0)
	{
		if (Array[size - 1] > Array[size])
		{
			return true;
		}
	}
	return false;
}

template <typename type_array>
void ALGOR::Comparative_Sorts<type_array>::BogoSort::Shuffle()
{
	for (asize_t i = 0; i < array_size; i++)
	{
		MersenneTwister RanGen(getMemoryCell());
		CORE<type_array>::swap(Array[i], Array[RanGen.IRandom(0, array_size - 1)]);
	}
}

template <typename type_array>
ALGOR::Comparative_Sorts<type_array>::BubbleSort::BubbleSort(type_array *array, asize_t asize) : Array(array), array_size(asize) {}

template <typename type_array>
void ALGOR::Comparative_Sorts<type_array>::BubbleSort::bubble_sort()
{
	for (asize_t i = 0; i < array_size; i++)
	{
		for (asize_t j = 0; j < array_size - 1; j++)
		{
			if (Array[j] > Array[j + 1])
			{
				CORE<type_array>::swap(Array[j], Array[j + 1]);
			}
		}
	}
}

template <typename type_array>
ALGOR::Comparative_Sorts<type_array>::CocktailShakerSort::CocktailShakerSort(type_array *array, asize_t asize) : Array(array), array_size(asize) {}

template <typename type_array>
void ALGOR::Comparative_Sorts<type_array>::CocktailShakerSort::cocktail_shaker_sort()
{
	asize_t leftMark = 1, rightMark = array_size - 1;
	while (leftMark <= rightMark)
	{
		for (asize_t i = rightMark; i >= leftMark; i--)
		{
			if (Array[i - 1] > Array[i])
			{
				CORE<type_array>::swap(Array[i], Array[i - 1]);
			}
		}
		leftMark++;
		for (asize_t i = leftMark; i <= rightMark; i++)
		{
			if (Array[i - 1] > Array[i])
			{
				CORE<type_array>::swap(Array[i], Array[i - 1]);
			}
		}
		rightMark--;
	}
}

template <typename type_array>
ALGOR::Comparative_Sorts<type_array>::CombSort::CombSort(type_array *array, asize_t asize) : Array(array), array_size(asize) {}

template <class type_array>
void ALGOR::Comparative_Sorts<type_array>::CombSort::comb_sort()
{
	double factor = 1.2473309; //Фактор зменшення
	int step = array_size - 1; //Шаг

	while (step >= 1)
	{
		for (asize_t i = 0; i + step < array_size; i++)
		{
			if (Array[i] > Array[i + step])
			{
				CORE<type_array>::swap(Array[i], Array[i + step]);
			}
		}
		step /= factor;
	}
}

template <typename type_array>
ALGOR::Comparative_Sorts<type_array>::CycleSort::CycleSort(type_array *array, asize_t asize) : Array(array), array_size(asize) {}

template <typename type_array>
void ALGOR::Comparative_Sorts<type_array>::CycleSort::cycle_sort()
{
	for (asize_t cycle_start = 0; cycle_start < array_size; cycle_start++)
	{
		type_array item = Array[cycle_start];

		asize_t pos = cycle_start;
		for (asize_t i = cycle_start + 1; i < array_size; i++)
		{
			if (Array[i] < item)
			{
				pos += 1;
			}
		}
		if (pos == cycle_start)
		{
			continue;
		}
		while (item == Array[pos])
		{
			pos += 1;
		}
		CORE<type_array>::swap(Array[pos], item);

		while (pos != cycle_start)
		{
			pos = cycle_start;
			for (asize_t i = cycle_start + 1; i < array_size; i++)
			{
				if (Array[i] < item)
				{
					pos += 1;
				}
			}
			while (item == Array[pos])
			{
				pos += 1;
			}
			CORE<type_array>::swap(Array[pos], item);
		}
	}
}

template <typename type_array>
ALGOR::Comparative_Sorts<type_array>::GnomeSort::GnomeSort(type_array *array, asize_t asize) : Array(array), array_size(asize) {}

template <typename type_array>
void ALGOR::Comparative_Sorts<type_array>::GnomeSort::gnome_sort()
{
	for (asize_t count = 0; count < array_size; count++)
	{
		asize_t i = 1, j = 2;

		while (i < array_size)
		{
			if (Array[i] > Array[i - 1])
			{
				i = j;
				j++;
			}
			else
			{
				CORE<type_array>::swap(Array[i], Array[i - 1]);
				i--;
				if (i == 0)
				{
					i = j;
					j++;
				}
			}
		}
	}
}

template <typename type_array>
ALGOR::Comparative_Sorts<type_array>::HeapSort::HeapSort(type_array *array, asize_t asize) : Array(array), array_size(asize) {}

template <typename type_array>
void ALGOR::Comparative_Sorts<type_array>::HeapSort::heap_sort()
{
	//Типи int у циклах ЗАЛИШИТИ! Без них не працює!
	for (int right = array_size / 2 - 1; right >= 0; right--)
	{
		heapify(Array, right, array_size);
	}
	for (int i = array_size - 1; i >= 0; i--)
	{
		CORE<type_array>::swap(Array[0], Array[i]);
		heapify(Array, 0, i);
	}
}

template <typename type_array>
void ALGOR::Comparative_Sorts<type_array>::HeapSort::heapify(type_array *Array, const asize_t &count, const asize_t &array_size)
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
		CORE<type_array>::swap(Array[count], Array[large]);
		heapify(Array, large, array_size);
	}
}

template <typename type_array>
ALGOR::Comparative_Sorts<type_array>::InsertSort::InsertSort(type_array *array, asize_t asize) : Array(array), array_size(asize) {}

template <typename type_array>
void ALGOR::Comparative_Sorts<type_array>::InsertSort::insert_sort()
{
	for (asize_t i = 0; i < array_size; i++)
	{
		for (asize_t j = i; j > 0 && Array[j - 1] > Array[j]; j--)
		{
			CORE<type_array>::swap(Array[j - 1], Array[j]);
		}
	}
}

template <class type_array>
Comparative_Sorts<type_array>::LibrarySort::LibrarySort(type_array *array, asize_t asize) : Array(array), array_size(asize) {}

template <class type_array>
void Comparative_Sorts<type_array>::LibrarySort::library_sort()
{
	initialization();
	while (index_pos < array_size)
	{
		binarysearch();
		insertion();
	}
	rebalancing();
	finalization();
}

template <class type_array>
void Comparative_Sorts<type_array>::LibrarySort::initialization()
{
	gaps = new type_array[array_size + 1]{0};
	for (asize_t i = 0; i < 2; i++)
	{
		library[i] = new type_array[array_size + 1]{0};
	}
	numbered = new bool[array_size + 1]{0};
	library[target_lib][0] = Array[0];
}

template <class type_array>
void Comparative_Sorts<type_array>::LibrarySort::binarysearch()
{
	insert = ArrayProcessing<type_array>::distance(library[target_lib], ArrayProcessing<type_array>::lower_bound(library[target_lib], library[target_lib] + lib_size, Array[index_pos]));
}

template <class type_array>
void Comparative_Sorts<type_array>::LibrarySort::insertion()
{
	if (numbered[insert] == true)
	{
		asize_t prov_size = 0, next_target_lib = !target_lib;

		for (asize_t i = 0; i <= array_size; i++)
		{
			if (numbered[i] == true)
			{
				library[next_target_lib][prov_size] = gaps[i];
				prov_size++;
				numbered[i] = false;
			}
			if (i <= lib_size)
			{
				library[next_target_lib][prov_size] = library[target_lib][i];
				prov_size++;
			}
		}

		target_lib = next_target_lib;
		lib_size = prov_size - 1;
	}
	else
	{
		numbered[insert] = true;
		gaps[insert] = Array[index_pos];
		index_pos++;
	}
}

template <class type_array>
void Comparative_Sorts<type_array>::LibrarySort::rebalancing()
{
	for (asize_t i = 0; index_pos_for_output < array_size; i++)
	{
		if (numbered[i] == true)
		{
			Array[index_pos_for_output] = gaps[i];
			index_pos_for_output++;
		}

		if (i < lib_size)
		{
			Array[index_pos_for_output] = library[target_lib][i];
			index_pos_for_output++;
		}
	}
}

template <class type_array>
void Comparative_Sorts<type_array>::LibrarySort::finalization()
{
	delete[] numbered;
	for (asize_t i = 0; i < 2; i++)
	{
		delete[] library[i];
	}
	delete[] gaps;
}

template <typename type_array>
ALGOR::Comparative_Sorts<type_array>::MergeSort::MergeSort(type_array *array, asize_t asize) : Array(array), array_size(asize) {}

template <typename type_array>
void ALGOR::Comparative_Sorts<type_array>::MergeSort::merge_sort()
{
	recursive_merge_sort(0, array_size - 1);
}

template <typename type_array>
void ALGOR::Comparative_Sorts<type_array>::MergeSort::recursive_merge_sort(const asize_t &left_limit, const asize_t &right_limit)
{
	if (left_limit < right_limit)
	{
		asize_t middle = left_limit + (right_limit - left_limit) / 2;
		recursive_merge_sort(left_limit, middle);
		recursive_merge_sort(middle + 1, right_limit);
		merge(left_limit, middle, right_limit);
	}
}

template <typename type_array>
void ALGOR::Comparative_Sorts<type_array>::MergeSort::merge(const asize_t &left_limit, const asize_t &middle_limit, const asize_t &right_limit)
{
	asize_t start = left_limit, finish = middle_limit + 1;
	type_array *tempArray = new type_array[right_limit - left_limit + 1];
	for (asize_t i = left_limit; i <= right_limit; i++)
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
	for (asize_t i = left_limit; i <= right_limit; i++)
	{
		Array[i] = tempArray[i - left_limit];
	}
	delete[] tempArray;
}

template <typename type_array>
ALGOR::Comparative_Sorts<type_array>::OddEvenSort::OddEvenSort(type_array *array, asize_t asize) : Array(array), array_size(asize) {}

template <typename type_array>
void ALGOR::Comparative_Sorts<type_array>::OddEvenSort::odd_even_sort()
{
	for (asize_t i = 0; i < array_size; i++)
	{
		asize_t j;
		i & 1 ? j = 2 : j = 1;
		for (; j < array_size; j += 2)
		{
			if (Array[j] < Array[j - 1])
			{
				CORE<type_array>::swap(Array[j - 1], Array[j]);
			}
		}
	}
}

template<typename type_array>
Comparative_Sorts<type_array>::PancakeSort::PancakeSort(type_array *array, asize_t asize) : Array(array), array_size(asize) {}

template<typename type_array>
void Comparative_Sorts<type_array>::PancakeSort::pancake_sort()
{
	while (array_size > 1)
	{
		asize_t maxIndex = max_index();
		flip(maxIndex);
		flip(--array_size);
	}
}

template<typename type_array>
asize_t Comparative_Sorts<type_array>::PancakeSort::max_index()
{
	asize_t index = 0;
	for (asize_t i = 0; i < array_size; i++)
	{
		if (Array[index] < Array[i])
		{
			index = i;
		}
	}
	return index;
}

template<typename type_array>
void Comparative_Sorts<type_array>::PancakeSort::flip(asize_t index)
{
	asize_t left = 0;
	while (left < index)
	{
		CORE<type_array>::swap(Array[left], Array[index]);
		index--;
		left++;
	}
}

template <typename type_array>
ALGOR::Comparative_Sorts<type_array>::PatienceSort::PatienceSort(type_array *array, asize_t asize) : Array(array), array_size(asize) {}

template <typename type_array>
void ALGOR::Comparative_Sorts<type_array>::PatienceSort::patience_sort()
{
	initialization();

	for (asize_t i = 0; i < array_size; i++)
	{
		for (asize_t j = 0; j < array_size; j++)
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

	for (asize_t i = 0; i < array_size; i++)
	{
		for (asize_t j = 0; j < array_size; j++)
		{
			if (count[j] > 0 && decks[j][count[j] - 1] < min)
			{
				min = decks[j][count[j] - 1];
				pickedRow = j;
			}
		}
		sortedArr[i] = min;
		count[pickedRow]--;

		for (asize_t j = 0; j < array_size; j++)
		{
			if (count[j] > 0)
			{
				min = decks[j][count[j] - 1];
				pickedRow = j;
				break;
			}
		}
	}

	for (asize_t i = 0; i < array_size; i++)
	{
		Array[i] = sortedArr[i];
	}

	finalization();
}

template <typename type_array>
void ALGOR::Comparative_Sorts<type_array>::PatienceSort::initialization()
{
	count = new asize_t[array_size]{0};
	decks = new type_array *[array_size];
	for (asize_t i = 0; i < array_size; i++)
	{
		decks[i] = new type_array[array_size]{0};
	}
	sortedArr = new type_array[array_size]{0};
}

template <typename type_array>
void ALGOR::Comparative_Sorts<type_array>::PatienceSort::finalization()
{
	delete[] sortedArr;
	for (asize_t i = 0; i < array_size; i++)
	{
		delete[] decks[i];
	}
	delete[] decks;
	delete[] count;
}

template <typename type_array>
ALGOR::Comparative_Sorts<type_array>::QuickSort::QuickSort(type_array *array, asize_t asize) : Array(array), array_size(asize) {}

template <typename type_array>
void ALGOR::Comparative_Sorts<type_array>::QuickSort::quick_sort()
{
	recursive_quick_sort(0, array_size - 1);
}

template <typename type_array>
void ALGOR::Comparative_Sorts<type_array>::QuickSort::recursive_quick_sort(const int &left_limit, const int &right_limit)
{
	type_array middle = Array[(left_limit + right_limit) / 2];
	int start = left_limit, finish = right_limit;
	do
	{
		while (Array[start] < middle)
		{
			start++;
		}
		while (Array[finish] > middle)
		{
			finish--;
		}
		if (start <= finish)
		{
			CORE<type_array>::swap(Array[start], Array[finish]);
			start++;
			finish--;
		}
	} while (start < finish);
	if (left_limit < finish)
	{
		recursive_quick_sort(left_limit, finish);
	}
	if (start < right_limit)
	{
		recursive_quick_sort(start, right_limit);
	}
}

template <typename type_array>
ALGOR::Comparative_Sorts<type_array>::SelectionSort::SelectionSort(type_array *array, asize_t asize) : Array(array), array_size(asize) {}

template <typename type_array>
void ALGOR::Comparative_Sorts<type_array>::SelectionSort::selection_sort()
{
	for (asize_t i = 0; i < array_size; i++)
	{
		asize_t min_index = i;
		for (asize_t j = i + 1; j < array_size; j++)
		{
			if (Array[j] < Array[min_index])
			{
				min_index = j;
			}
		}
		if (min_index != i)
		{
			CORE<type_array>::swap(Array[i], Array[min_index]);
		}
	}
}

template <typename type_array>
ALGOR::Comparative_Sorts<type_array>::ShellSort::ShellSort(type_array *array, asize_t asize) : Array(array), array_size(asize) {}

template <typename type_array>
void ALGOR::Comparative_Sorts<type_array>::ShellSort::shell_sort()
{
	for (asize_t step = array_size / 2; step > 0; step /= 2)
	{
		for (asize_t i = step; i < array_size; i++)
		{
			for (int j = (int)i - step; j >= 0 && Array[j] > Array[j + step]; j -= step)
			{
				CORE<type_array>::swap(Array[j], Array[j + step]);
			}
		}
	}
}

template <typename type_array>
ALGOR::Comparative_Sorts<type_array>::SlowSort::SlowSort(type_array *array, asize_t asize) : Array(array), array_size(asize) {}

template <typename type_array>
void ALGOR::Comparative_Sorts<type_array>::SlowSort::slow_sort()
{
	recursive_slow_sort(0, array_size - 1);
}

template <typename type_array>
void ALGOR::Comparative_Sorts<type_array>::SlowSort::recursive_slow_sort(const int &left_limit, const int &right_limit)
{
	if (left_limit >= right_limit)
	{
		return;
	}
	int middle = (left_limit + right_limit) / 2;
	recursive_slow_sort(left_limit, middle);
	recursive_slow_sort(middle + 1, right_limit);
	if (Array[middle] > Array[right_limit])
	{
		CORE<type_array>::swap(Array[middle], Array[right_limit]);
	}
	recursive_slow_sort(left_limit, right_limit - 1);
}

template <typename type_array>
ALGOR::Comparative_Sorts<type_array>::StoogeSort::StoogeSort(type_array *array, asize_t asize) : Array(array), array_size(asize) {}

template <typename type_array>
void ALGOR::Comparative_Sorts<type_array>::StoogeSort::stooge_sort()
{
	recursive_stooge_sort(0, array_size - 1);
}

template <typename type_array>
void ALGOR::Comparative_Sorts<type_array>::StoogeSort::recursive_stooge_sort(const int &left_limit, const int &right_limit)
{
	if (Array[left_limit] > Array[right_limit])
	{
		CORE<type_array>::swap(Array[left_limit], Array[right_limit]);
	}
	if (left_limit + 1 >= right_limit)
	{
		return;
	}

	int k = (int)((right_limit - left_limit + 1) / 3);
	recursive_stooge_sort(left_limit, right_limit - k);
	recursive_stooge_sort(left_limit + k, right_limit);
	recursive_stooge_sort(left_limit, right_limit - k);
}

template<typename type_array>
Comparative_Sorts<type_array>::TimSort::TimSort(type_array *array, asize_t asize) : Array(array), array_size(asize) {}

template<typename type_array>
void Comparative_Sorts<type_array>::TimSort::tim_sort()
{
	for (asize_t i = 0; i < array_size; i += RUN)
	{
		insertionSort(i, CORE<asize_t>::minimum((i + 31), (array_size - 1)));
	}
	for (asize_t size = RUN; size < array_size; size *= 2)
	{
		for (asize_t left = 0; left < array_size; left += 2 * size)
		{
			asize_t middle = left + size - 1;
			asize_t right = CORE<asize_t>::minimum((left + 2 * size - 1), (array_size - 1));
			merge(left, middle, right);
		}
	}
}

template<typename type_array>
void Comparative_Sorts<type_array>::TimSort::insertionSort(asize_t left_limit, asize_t right_limit)
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

template<typename type_array>
void Comparative_Sorts<type_array>::TimSort::merge(asize_t left_limit, asize_t middle, asize_t right_limit)
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

template <typename type_array>
ALGOR::Comparative_Sorts<type_array>::TreeSort::TreeSort(type_array *array, asize_t asize) : Array(array), array_size(asize) {}

template <typename type_array>
void ALGOR::Comparative_Sorts<type_array>::TreeSort::tree_sort()
{
	Tree *root = nullptr;
	root = insert(root, Array[0]);
	for (asize_t i = 1; i < array_size; i++)
	{
		insert(root, Array[i]);
	}
	asize_t index = 0;
	store(root, Array, index);
	delete (root);
}

template <typename type_array>
typename Comparative_Sorts<type_array>::TreeSort::Tree *ALGOR::Comparative_Sorts<type_array>::TreeSort::newnode(int key)
{
	Tree *temp = new Tree;
	temp->data = key;
	temp->left = nullptr;
	temp->right = nullptr;
	return temp;
}

template <typename type_array>
typename Comparative_Sorts<type_array>::TreeSort::Tree *ALGOR::Comparative_Sorts<type_array>::TreeSort::insert(Tree *node, int key)
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

template <typename type_array>
void ALGOR::Comparative_Sorts<type_array>::TreeSort::store(Tree *root, type_array *Array, asize_t &index)
{
	if (root != nullptr)
	{
		store(root->left, Array, index);
		Array[index++] = root->data;
		store(root->right, Array, index);
	}
}

template <typename type_array>
ALGOR::Comparative_Sorts<type_array>::SmoothSort::SmoothSort(type_array *array, int asize) : Array(array), array_size(asize) {}

template <typename type_array>
void ALGOR::Comparative_Sorts<type_array>::SmoothSort::smooth_sort()
{
	make_heap_pool();

	for (int i = array_size - 1; i >= 0; i--)
	{
		int nextPosHeapItemsAmount;
		int posMaxTopElem = findPosMaxElem(curState, i, nextPosHeapItemsAmount);
		if (posMaxTopElem != i)
		{
			CORE<type_array>::swap(Array[i], Array[posMaxTopElem]);
			shiftDown(nextPosHeapItemsAmount, posMaxTopElem);
		}
		PrevState(curState);
	}
}

template <typename type_array>
void ALGOR::Comparative_Sorts<type_array>::SmoothSort::make_heap_pool()
{
	for (int i = 0; i < (int)array_size; i++)
	{
		int posHeapItemsAmount = NextState(curState);
		if (posHeapItemsAmount != -1)
		{
			shiftDown(posHeapItemsAmount, i);
		}
	}
}

template <typename type_array>
int ALGOR::Comparative_Sorts<type_array>::SmoothSort::NextState(int &curState)
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
		if ((next & 3) == 3)
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

template <typename type_array>
void ALGOR::Comparative_Sorts<type_array>::SmoothSort::shiftDown(int posHeapItemsAmount, int indexLastTop)
{
	int posCurNode = indexLastTop;
	while (posHeapItemsAmount > 1)
	{
		int posR = posCurNode - 1;
		int posL = posR - LeoNum[posHeapItemsAmount - 2];
		int posMaxChild = posL;
		int posNextTop = posHeapItemsAmount - 1;
		if (Array[posR] > Array[posL])
		{
			posMaxChild = posR;
			posNextTop = posHeapItemsAmount - 2;
		}
		if (Array[posCurNode] < Array[posMaxChild])
		{
			CORE<type_array>::swap(Array[posCurNode], Array[posMaxChild]);
			posHeapItemsAmount = posNextTop;
			posCurNode = posMaxChild;
		}
		else
		{
			break;
		}
	}
}

template <typename type_array>
int ALGOR::Comparative_Sorts<type_array>::SmoothSort::findPosMaxElem(int curState, int indexLastTop, int &nextPosHeapItemsAmount)
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

template <typename type_array>
void ALGOR::Comparative_Sorts<type_array>::SmoothSort::PrevState(int &curState)
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

Distribution_Sorts::Distribution_Sorts(Array<int> *&Array) : ArrayBase<int>(Array) {}

void Distribution_Sorts::AmericanFlag_Sort()
{
	AmericanFlagSort *sort = new AmericanFlagSort(this->ARRAY->array, this->ARRAY->array_size);
	sort->american_flag_sort();
	delete (sort);
}

void Distribution_Sorts::Bead_Sort()
{
	BeadSort *sort = new BeadSort(this->ARRAY->array, this->ARRAY->array_size);
	sort->bead_sort();
	delete (sort);
}

void Distribution_Sorts::Bucket_Sort()
{
	BucketSort *sort = new BucketSort(this->ARRAY->array, this->ARRAY->array_size);
	sort->bucket_sort();
	delete (sort);
}

void Distribution_Sorts::Counting_Sort()
{
	CountingSort *sort = new CountingSort(this->ARRAY->array, this->ARRAY->array_size);
	sort->counting_sort();
	delete (sort);
}

void Distribution_Sorts::Interpolation_Sort()
{
	InterpolationSort *sort = new InterpolationSort(this->ARRAY->array, this->ARRAY->array_size);
	sort->interpolation_sort();
	delete (sort);
}

void Distribution_Sorts::Pigeonhole_Sort()
{
	PigeonholeSort *sort = new PigeonholeSort(this->ARRAY->array, this->ARRAY->array_size);
	sort->pigeonhole_sort();
	delete (sort);
}

void Distribution_Sorts::Radix_Sort()
{
	RadixSort *sort = new RadixSort(this->ARRAY->array, this->ARRAY->array_size);
	sort->radix_sort();
	delete (sort);
}

void Distribution_Sorts::Flash_Sort()
{
	FlashSort *sort = new FlashSort(this->ARRAY->array, this->ARRAY->array_size);
	sort->flash_sort();
	delete (sort);
}

Distribution_Sorts::AmericanFlagSort::AmericanFlagSort(int *array, asize_t asize) : Array(array), array_size(asize) {}

void Distribution_Sorts::AmericanFlagSort::american_flag_sort()
{
	int max = 1;
	for (int i = 0; i < getMaxNumberOfDigits() - 1; i++)
	{
		max *= 10;
	}
	recursive_american_flag_sort(0, (int)array_size, max);
}

void Distribution_Sorts::AmericanFlagSort::recursive_american_flag_sort(int start, int length, int divisor)
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

	for (int bucket = 0; bucket < NUMBER_OF_BUCKETS; bucket++)
	{
		while (count[bucket] > 0)
		{
			int origin = offset[bucket];
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

int Distribution_Sorts::AmericanFlagSort::getMaxNumberOfDigits()
{
	int count = 1;
	int value = ArrayProcessing<int>::maximum(Array, array_size);
	while (true)
	{
		value /= 10;
		if (value != 0)
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

int Distribution_Sorts::AmericanFlagSort::getDigit(int integer, int divisor)
{
	return (integer / divisor) % 10;
}

Distribution_Sorts::BeadSort::BeadSort(int *array, asize_t asize) : Array(array), array_size(asize) {}

void Distribution_Sorts::BeadSort::bead_sort()
{
	max = ArrayProcessing<int>::maximum(Array, array_size);
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

Distribution_Sorts::BucketSort::BucketSort(int *array, asize_t asize) : Array(array), array_size(asize) {}

void Distribution_Sorts::BucketSort::bucket_sort()
{
	min = ArrayProcessing<int>::minimum(Array, array_size);
	max = ArrayProcessing<int>::maximum(Array, array_size);
	range = (max - min) / (int)array_size;
	range++;

	bucket = new int *[array_size];
	for (asize_t i = 0; i < array_size; i++)
	{
		bucket[i] = new int[1];
		bucket[i][0] = 1;
	}

	for (asize_t i = 0; i < array_size; i++)
	{
		bucket_index = asize_t((Array[i] - min) / range);
		if (bucket_index == array_size)
		{
			bucket_index--;
		}
		push_back(bucket[bucket_index], Array[i]);
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

void Distribution_Sorts::BucketSort::push_back(int *&bucket, const int &value)
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
	int *temp = new int[bucket[0] + 1];
	temp[0] = bucket[0] + 1;
	for (asize_t i = 0; i < (asize_t)bucket[0]; i++)
	{
		i != 0 ? temp[i] = bucket[i] : temp[(asize_t)bucket[0]] = value;
	}
	delete[] bucket;
	bucket = temp;
}

void Distribution_Sorts::BucketSort::bubble_sort(int *bucket)
{
	// NOTE Тимчасова міра, пізніше я більш швидкий підключу та оптимізую
	for (asize_t i = 1; i < (asize_t)bucket[0] - 1; i++)
	{
		for (asize_t j = 1; j < (asize_t)bucket[0] - 1; j++)
		{
			if (bucket[j] > bucket[j + 1])
			{
				CORE<int>::swap(bucket[j], bucket[j + 1]);
			}
		}
	}
}

Distribution_Sorts::CountingSort::CountingSort(int *array, asize_t asize) : Array(array), array_size(asize) {}

void Distribution_Sorts::CountingSort::counting_sort()
{
	min = ArrayProcessing<int>::minimum(Array, array_size);
	max = ArrayProcessing<int>::maximum(Array, array_size);
	tempArray = new int[max - min + 1];
	for (int i = 0; i < max - min + 1; i++)
	{
		tempArray[i] = 0;
	}
	for (unsigned int i = 0; i < array_size; i++)
	{
		tempArray[Array[i] - min] = tempArray[Array[i] - min] + 1;
	}
	for (int i = 0, j = min; j < max + 1; j++)
	{
		while (tempArray[j - min] != 0)
		{
			Array[i] = j;
			tempArray[j - min]--;
			i++;
		}
	}
	delete[] tempArray;
}

Distribution_Sorts::FlashSort::FlashSort(int *array, asize_t asize) : Array(array), array_size(asize) {}

void Distribution_Sorts::FlashSort::flash_sort()
{
	const asize_t m = (int)(0.45 * array_size);

	//Так як m дорівнює розміру, помноженому на 0.45 - то, виходячи з
	//розрахунків, m == 0 тільки при розмірі, рівному 2, 1 чи 0. Якщо
	//розмір == 2 та перший елемент більше другого (так як сортування
	//іде в напрямку збільшення, тому перший елемент має бути найменшим),
	//тоді необхідно змінити ці два елементи місцями - це і є все
	//сортування; інакше (тобто якщо розмір == 1 чи масив з 2 елементів
	//відсортовано (перший елемент менше другого)) - відразу завершати
	//сортування, так як там нічого сортувати. Розмір не може
	//дорівнювати 0, так як конструктор класу викликає верифікацію, де
	//перевіряється масив на пустотність. При всіх інших розмірах
	//(тобто >= 3) m буде дорівнювати 1 чи більше, а тому до k не зможе
	//потрапити значення -1 й викликати помилку.
	if (m == 0)
	{
		if (array_size == 2 && Array[0] > Array[1])
		{
			CORE<int>::swap(Array[0], Array[1]);
		}
		return;
	}

	L = new int[m];

	for (asize_t i = 0; i < array_size; i++)
	{
		if (Array[i] < Array[min])
		{
			min = i;
		}
		if (Array[i] > Array[max])
		{
			max = i;
		}
	}

	//Якщо всі елементи мають одне значення, то при знаходженні
	//константи c1 виникне ділення на 0, а тому треба завчасно робити
	//перевірку і в випадку рівності значень - кидати виключення.
	if (Array[min] == Array[max])
	{
		throw division_by_zero();
	}

	const asize_t c1 = (m - 1) / (Array[max] - Array[min]);

	for (asize_t i = 0; i < m; i++)
	{
		L[i] = 0;
	}
	for (asize_t i = 0; i < array_size; ++i)
	{
		++L[c1 * (Array[i] - min)];
	}
	for (asize_t i = 1; i < m; ++i)
	{
		L[i] = L[i] + L[i - 1];
	}

	CORE<int>::swap(Array[max], Array[0]);

	k = m - 1;

	while (move < array_size - 1)
	{
		while ((int)j > L[k] - 1)
		{
			++j;
			k = c1 * (Array[j] - min);
		}
		flash = Array[j];
		while ((int)j != L[k])
		{
			k = c1 * (flash - Array[min]);
			CORE<int>::swap(Array[L[k] - 1], flash);
			L[k]--;
			move++;
		}
	}

	for (j = 1; j < array_size; j++)
	{
		flash = Array[j];
		int i = j - 1;
		while (i >= 0 && Array[i] > flash)
		{
			Array[i + 1] = Array[i];
			i--;
		}
		Array[i + 1] = flash;
	}
}

Distribution_Sorts::InterpolationSort::InterpolationSort(int *array, asize_t asize) : Array(array), array_size(asize) {}

void Distribution_Sorts::InterpolationSort::interpolation_sort()
{
	getMin();

	if (index_min != 0)
	{
		Array[index_min] = Array[0];
		Array[0] = nArray_min;
	}

	if (array_size >= MIN_SORTABLE_LENGTH)
	{
		getMax();

		ifac = (nArray_max - nArray_min) / (array_size - 1);

		if (ifac <= 0)
		{
			ifac = 1;
		}
		else
		{
			while (((nArray_max - nArray_min) / ifac) > ((int)array_size - 1))
			{
				ifac++;
			}
		}

		space = new int[2 * array_size + 1];

		if (!space)
		{
			return;
		}

		cmp_index = space;
		cum = space + array_size;
		hist = cum + 1;
		sorted = hist;

		for (asize_t i = 0; i <= array_size; i++)
		{
			cum[i] = 0;
		}

		for (int i = array_size; --i >= 0;)
		{
			hist[cmp_index[i] = (Array[i] - nArray_min) / ifac] += 1;
			ComplexityCount++;
		}

		for (asize_t i = 1; i < array_size; i++)
		{
			cum[i] += cum[i - 1];
			ComplexityCount++;
		}

		for (asize_t i = 0; i < array_size; i++)
		{
			cmp_index[i] = cum[cmp_index[i]]++;
			ComplexityCount++;
		}

		for (asize_t i = array_size; i > 0; i--)
		{
			sorted[cmp_index[i - 1]] = Array[i - 1];
			ComplexityCount++;
		}

		ArrayProcessing<int>::copy(Array, sorted, array_size);

		delete[] space;
	}

	for (asize_t i = 1; i < array_size; i++)
	{
		ComplexityCount++;

		if (Array[i] >= Array[i - 1])
		{
			continue;
		}

		temp = Array[i];
		Array[i] = Array[i - 1];

		asize_t j;
		for (j = i - 2; temp < Array[j]; j--)
		{
			Array[j + 1] = Array[j];
		}
		Array[j + 1] = temp;
	}
}

void Distribution_Sorts::InterpolationSort::getMin()
{
	nArray_min = Array[0];
	for (asize_t i = 1; i < array_size; i++)
	{
		if (nArray_min > Array[i])
		{
			nArray_min = Array[i];
			index_min = i;
		}
	}
}

void Distribution_Sorts::InterpolationSort::getMax()
{
	nArray_max = Array[0];
	for (asize_t i = 1; i < array_size; i++)
	{
		if (nArray_max < Array[i])
		{
			nArray_max = Array[i];
		}
	}
}

Distribution_Sorts::PigeonholeSort::PigeonholeSort(int *array, asize_t asize) : Array(array), array_size(asize) {}

void Distribution_Sorts::PigeonholeSort::pigeonhole_sort()
{
	min = ArrayProcessing<int>::minimum(Array, array_size);
	max = ArrayProcessing<int>::maximum(Array, array_size);
	range = (asize_t)max - (asize_t)min + 1;

	hole = new int *[range];
	for (asize_t i = 0; i < range; i++)
	{
		hole[i] = new int[1];
		hole[i][0] = 1;
	}

	for (asize_t i = 0; i < array_size; i++)
	{
		push_back(hole[Array[i] - min], Array[i]);
	}
	for (asize_t i = 0; i < range; i++)
	{
		for (asize_t j = 1; j < (asize_t)hole[i][0]; j++)
		{
			Array[count] = hole[i][j];
			count++;
		}
	}
	for (asize_t i = 0; i < range; i++)
	{
		delete[] hole[i];
	}
	delete[] hole;
}

void Distribution_Sorts::PigeonholeSort::push_back(int *&hole, const int &value)
{
	int *temp = new int[hole[0] + 1];
	temp[0] = hole[0] + 1;
	for (asize_t i = 0; i < (asize_t)hole[0]; i++)
	{
		i != 0 ? temp[i] = hole[i] : temp[(asize_t)hole[0]] = value;
	}
	delete[] hole;
	hole = temp;
}

Distribution_Sorts::RadixSort::RadixSort(int *array, asize_t asize) : Array(array), array_size(asize) {}

void Distribution_Sorts::RadixSort::radix_sort()
{
	max = ArrayProcessing<int>::maximum(Array, array_size);
	tempArray = new int[array_size];
	bucket = new int[bit];
	while (max / exp > 0)
	{
		for (int i = 0; i < bit; i++)
		{
			bucket[i] = 0;
		}
		for (unsigned int i = 0; i < array_size; i++)
		{
			bucket[(Array[i] / exp) % bit]++;
		}
		for (int i = 1; i < bit; i++)
		{
			bucket[i] += bucket[i - 1];
		}
		for (int i = array_size - 1; i >= 0; i--)
		{
			current = (Array[i] % (exp * bit)) / exp;
			bucket[current]--;
			tempArray[bucket[current]] = Array[i];
		}
		for (unsigned int i = 0; i < array_size; i++)
		{
			Array[i] = tempArray[i];
		}
		exp *= bit;
	}
	delete[] bucket;
	delete[] tempArray;
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

// TODO The implementation of the matrices is scheduled to version 3.0.0

/* ****+/^^^/+++++-/&/-+-+-+-/&/-+-+-+-/&/-+-+-+-/&/-+-+-+-/&/-+++++/^^^/+**** *
 * #*****+/^^^/+++++-/+/-+-+                         +-+-/+/-+++++/^^^/+*****# *
 * #*-*%*-*+                                                         +*-*%*-*# *
 * %%%%%                       $------------------$                      %%%%% *
 * -->                              ALGOR_HEAP                             <-- *
 * %%%%%                       $------------------$                      %%%%% *
 * #*-*%*-*+                                                         +*-*%*-*# *
 * #*****+/^^^/+++++-/+/-+-+                         +-+-/+/-+++++/^^^/+*****# *
 * ****+/^^^/+++++-/&/-+-+-+-/&/-+-+-+-/&/-+-+-+-/&/-+-+-+-/&/-+++++/^^^/+**** */

// TODO The implementation of the trees is scheduled to version 4.0.0

/* ****+/^^^/+++++-/&/-+-+-+-/&/-+-+-+-/&/-+-+-+-/&/-+-+-+-/&/-+++++/^^^/+**** *
 * #*****+/^^^/+++++-/+/-+-+                         +-+-/+/-+++++/^^^/+*****# *
 * #*-*%*-*+                                                         +*-*%*-*# *
 * %%%%%                       $------------------$                      %%%%% *
 * -->                              ALGOR_LIST                             <-- *
 * %%%%%                       $------------------$                      %%%%% *
 * #*-*%*-*+                                                         +*-*%*-*# *
 * #*****+/^^^/+++++-/+/-+-+                         +-+-/+/-+++++/^^^/+*****# *
 * ****+/^^^/+++++-/&/-+-+-+-/&/-+-+-+-/&/-+-+-+-/&/-+-+-+-/&/-+++++/^^^/+**** */

// TODO The implementation of the lists is scheduled to version 5.0.0

template class ALGOR::CORE<int>;
template class ALGOR::CORE<float>;
template class ALGOR::CORE<char>;
template class ALGOR::CORE<fbit128_t>;

template class ALGOR::ArrayProcessing<int>;
template class ALGOR::ArrayProcessing<float>;
template class ALGOR::ArrayProcessing<char>;
template class ALGOR::ArrayProcessing<asize_t>;
template class ALGOR::ArrayProcessing<fbit128_t>;

template Array<int> *ALGOR::create_struct<int>(const asize_t &, bool);
template Array<float> *ALGOR::create_struct<float>(const asize_t &, bool);
template Array<char> *ALGOR::create_struct<char>(const asize_t &, bool);
template Array<asize_t> *ALGOR::create_struct<asize_t>(const asize_t &, bool);
template Array<fbit128_t> *ALGOR::create_struct<fbit128_t>(const asize_t &, bool);

template void ALGOR::remove_struct<int>(Array<int> *&);
template void ALGOR::remove_struct<float>(Array<float> *&);
template void ALGOR::remove_struct<char>(Array<char> *&);
template void ALGOR::remove_struct<asize_t>(Array<asize_t> *&);
template void ALGOR::remove_struct<fbit128_t>(Array<fbit128_t> *&);

template class ALGOR::ARRAYDATA<int>;
template class ALGOR::ARRAYDATA<float>;
template class ALGOR::ARRAYDATA<char>;
template class ALGOR::ARRAYDATA<ubit32_t>;
template class ALGOR::ARRAYDATA<fbit128_t>;

template class ALGOR::Comparative_Sorts<int>;
template class ALGOR::Comparative_Sorts<float>;
template class ALGOR::Comparative_Sorts<char>;
template class ALGOR::Comparative_Sorts<fbit128_t>;
