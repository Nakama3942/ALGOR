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

template <typename type_value>
void ALGOR::swap(type_value &firstNumber, type_value &secondNumber) noexcept
{
	type_value temp = firstNumber;
	firstNumber = secondNumber;
	secondNumber = temp;
}

template <typename type_value>
type_value ALGOR::minimum(type_value firstNumber, type_value secondNumber) noexcept
{
	return firstNumber < secondNumber ? firstNumber : secondNumber;
}

template <typename type_value>
type_value ALGOR::maximum(type_value firstNumber, type_value secondNumber) noexcept
{
	return firstNumber > secondNumber ? firstNumber : secondNumber;
}

memcell_t ALGOR::getMemoryCell(memcell_t right_adjust, memcell_t left_adjust)
{
	memcell_t *cells = new memcell_t[10];
	memcell_t cell = cells[0];
	for (ubit32_t i = 1; i < 8; i++)
	{
		cell >>= (memcell_t)cells[i];
		cell <<= (memcell_t)cells[i + 1];
		cell ^= (memcell_t)cells[i + 2];
		if (right_adjust != 0)
		{
			cell >>= right_adjust;
		}
		if (left_adjust != 0)
		{
			cell <<= left_adjust;
		}
	}
	delete[] cells;
	return cell;
}

template void ALGOR::swap<byte8_t>(byte8_t &, byte8_t &);
template void ALGOR::swap<ubit64_t>(ubit64_t &, ubit64_t &);
template void ALGOR::swap<fbit64_t>(fbit64_t &, fbit64_t &);
template void ALGOR::swap<fbit128_t>(fbit128_t &, fbit128_t &);
template void ALGOR::swap<asize_t>(asize_t &, asize_t &);

template byte8_t ALGOR::minimum<byte8_t>(byte8_t, byte8_t);
template ubit64_t ALGOR::minimum<ubit64_t>(ubit64_t, ubit64_t);
template fbit64_t ALGOR::minimum<fbit64_t>(fbit64_t, fbit64_t);
template fbit128_t ALGOR::minimum<fbit128_t>(fbit128_t, fbit128_t);
template asize_t ALGOR::minimum<asize_t>(asize_t, asize_t);

template byte8_t ALGOR::maximum<byte8_t>(byte8_t, byte8_t);
template ubit64_t ALGOR::maximum<ubit64_t>(ubit64_t, ubit64_t);
template fbit64_t ALGOR::maximum<fbit64_t>(fbit64_t, fbit64_t);
template fbit128_t ALGOR::maximum<fbit128_t>(fbit128_t, fbit128_t);
template asize_t ALGOR::maximum<asize_t>(asize_t, asize_t);

/* ****+/^^^/+++++-/&/-+-+-+-/&/-+-+-+-/&/-+-+-+-/&/-+-+-+-/&/-+++++/^^^/+**** *
 * #*****+/^^^/+++++-/+/-+-+                         +-+-/+/-+++++/^^^/+*****# *
 * #*-*%*-*+                                                         +*-*%*-*# *
 * %%%%%                      $-------------------$                      %%%%% *
 * -->                           ALGOR_EXCEPTION                           <-- *
 * %%%%%                      $-------------------$                      %%%%% *
 * #*-*%*-*+                                                         +*-*%*-*# *
 * #*****+/^^^/+++++-/+/-+-+                         +-+-/+/-+++++/^^^/+*****# *
 * ****+/^^^/+++++-/&/-+-+-+-/&/-+-+-+-/&/-+-+-+-/&/-+-+-+-/&/-+++++/^^^/+**** */

ALGOR::EXCEPTION_SET::Exception::Exception(ubit16_t CODE, const byte1_t *DETAILS, const byte1_t *EXPLANATION)
{
	this->CODE = CODE;
	this->DETAILS = DETAILS;
	this->EXPLANATION = EXPLANATION;
}

ALGOR::EXCEPTION_SET::Exception::Exception(ubit16_t CODE, const byte1_t *DETAILS)
{
	this->CODE = CODE;
	this->DETAILS = DETAILS;
	this->EXPLANATION = "No information given";
}

ALGOR::EXCEPTION_SET::Exception::Exception(ubit16_t CODE)
{
	this->CODE = CODE;
	this->DETAILS = "No information given";
	this->EXPLANATION = "No information given";
}

ALGOR::EXCEPTION_SET::Exception::Exception(const byte1_t *DETAILS)
{
	this->CODE = 0xffff;
	this->DETAILS = DETAILS;
	this->EXPLANATION = "No information given";
}

ubit16_t ALGOR::EXCEPTION_SET::Exception::code()
{
	return CODE;
}

const byte1_t *ALGOR::EXCEPTION_SET::Exception::what()
{
	return DETAILS;
}

const byte1_t *ALGOR::EXCEPTION_SET::Exception::why()
{
	return EXPLANATION;
}

ALGOR::EXCEPTION_SET::memory_overflow::memory_overflow() : Exception(55, excep55) {}
ALGOR::EXCEPTION_SET::memory_overflow::memory_overflow(const byte1_t *explanation) : Exception(55, excep55, explanation) {}

ALGOR::EXCEPTION_SET::division_by_zero::division_by_zero() : Exception(101, excep101) {}
ALGOR::EXCEPTION_SET::division_by_zero::division_by_zero(const byte1_t *explanation) : Exception(101, excep101, explanation) {}

ALGOR::EXCEPTION_SET::position_failure::position_failure() : Exception(254, excep254) {}
ALGOR::EXCEPTION_SET::position_failure::position_failure(const byte1_t *explanation) : Exception(254, excep254, explanation) {}

ALGOR::EXCEPTION_SET::value_failure::value_failure() : Exception(255, excep255) {}
ALGOR::EXCEPTION_SET::value_failure::value_failure(const byte1_t *explanation) : Exception(255, excep255, explanation) {}

ALGOR::EXCEPTION_SET::size_failure::size_failure() : Exception(256, excep256) {}
ALGOR::EXCEPTION_SET::size_failure::size_failure(const byte1_t *explanation) : Exception(256, excep256, explanation) {}

ALGOR::EXCEPTION_SET::void_data::void_data() : Exception(400, excep400) {}
ALGOR::EXCEPTION_SET::void_data::void_data(const byte1_t *explanation) : Exception(400, excep400, explanation) {}

ALGOR::EXCEPTION_SET::not_found::not_found() : Exception(404, excep404) {}
ALGOR::EXCEPTION_SET::not_found::not_found(const byte1_t *explanation) : Exception(404, excep404, explanation) {}

/* ****+/^^^/+++++-/&/-+-+-+-/&/-+-+-+-/&/-+-+-+-/&/-+-+-+-/&/-+++++/^^^/+**** *
 * #*****+/^^^/+++++-/+/-+-+                         +-+-/+/-+++++/^^^/+*****# *
 * #*-*%*-*+                                                         +*-*%*-*# *
 * %%%%%                       $------------------$                      %%%%% *
 * -->                             ALGOR_RANDOM                            <-- *
 * %%%%%                       $------------------$                      %%%%% *
 * #*-*%*-*+                                                         +*-*%*-*# *
 * #*****+/^^^/+++++-/+/-+-+                         +-+-/+/-+++++/^^^/+*****# *
 * ****+/^^^/+++++-/&/-+-+-+-/&/-+-+-+-/&/-+-+-+-/&/-+-+-+-/&/-+++++/^^^/+**** */

ALGOR::RANDOM::LCM::LCM(memcell_t seed)
{
	this->seed = seed;
}

ubit32_t ALGOR::RANDOM::LCM::rand()
{
	seed = (a * seed + c) % m;
	return seed;
}

void ALGOR::RANDOM::RC4::crypto_srand(const byte1_t *key, byte4_t ksize)
{
	ubit8_t j = 0;
	for (byte4_t i = 0; i < 256; i++)
	{
		Sbox[i] = i;
	}
	for (byte4_t i = 0; i < 256; i++)
	{
		j = j + Sbox[i] + (ubit8_t)key[i % ksize];
		swap(Sbox[i], Sbox[j]);
	}
}

void ALGOR::RANDOM::RC4::crypto_rand(byte1_t *output, byte4_t size)
{
	ubit8_t i = 0, j = 0, t;
	for (byte4_t k = 0; i < size; k++)
	{
		i += 1;
		j += Sbox[i];
		swap(Sbox[i], Sbox[j]);
		t = Sbox[i] + Sbox[j];
		output[k] = (ubit32_t)Sbox[t];
	}
}

ALGOR::RANDOM::MersenneTwister::MersenneTwister(byte4_t seed)
{
	RandomInit(seed);
	LastInterval = 0;
}

void ALGOR::RANDOM::MersenneTwister::RandomInit(byte4_t seed)
{
	Init0(seed);
	for (byte4_t i = 0; i < 37; i++)
	{
		BRandom();
	}
}

sbit32_t ALGOR::RANDOM::MersenneTwister::rand()
{
	return IRandom(0x80000000, 0x79999999);
}

byte4_t ALGOR::RANDOM::MersenneTwister::IRandom(byte4_t min, byte4_t max)
{
	if (max <= min)
	{
		return max == min ? min : 0x80000000;
	}
	byte4_t rand_int = byte4_t((fbit64_t)(ubit32_t)(max - min + 1) * Random() + min);
	if (rand_int > max)
	{
		rand_int = max;
	}
	return rand_int;
}

byte4_t ALGOR::RANDOM::MersenneTwister::IRandomX(byte4_t min, byte4_t max)
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

fbit64_t ALGOR::RANDOM::MersenneTwister::Random()
{
	return (fbit64_t)BRandom() * (1. / (65536. * 65536.));
}

ubit32_t ALGOR::RANDOM::MersenneTwister::BRandom()
{
	ubit32_t resulting_bit;
	if (mersenne_twister_index >= 624)
	{
		const ubit32_t LOWER_MASK = (1LU << 31) - 1;  // Lower bits
		const ubit32_t UPPER_MASK = 0xFFFFFFFF << 31; // Upper bits
		static const ubit32_t mask[2] = {0, 0x9908B0DF};
		byte4_t counter;
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

void ALGOR::RANDOM::MersenneTwister::Init0(byte4_t seed)
{
	// Basic initialization procedure
	const ubit32_t factor = 1812433253UL;
	mersenne_twister[0] = seed;
	for (mersenne_twister_index = 1; mersenne_twister_index < 624; mersenne_twister_index++)
	{
		mersenne_twister[mersenne_twister_index] = (factor * (mersenne_twister[mersenne_twister_index - 1] ^ (mersenne_twister[mersenne_twister_index - 1] >> 30)) + mersenne_twister_index);
	}
}

template <class Generator>
fbit64_t ALGOR::RANDOM::test_random_on_Pearsons_coefficient(ubit32_t left_limit, ubit32_t right_limit)
{
	//Створюю об'єкт генератора
	memcell_t cell = getMemoryCell();
	cell >>= 32;
	Generator gen(cell);

	//Генерую масив
	fbit64_t *arr = new fbit64_t[1000000];
	for (ubit32_t i = 0; i < 1000000; i++)
	{
		arr[i] = (left_limit + (gen.rand() % (right_limit - left_limit))) / 1000000.;
	}

	//Створюю 100 піддіапазонів
	fbit64_t *bucket = new fbit64_t[100];
	for (ubit32_t i = 0; i < 100; i++)
	{
		bucket[i] = 0;
	}

	//Розраховую 100 піддіапазонів
	for (ubit32_t i = 0; i < 1000000; i++)
	{
		ubit32_t bucket_index = (ubit32_t)(arr[i] * 100);
		bucket[bucket_index] += 1;
	}

	//Розраховую критерій узгодженості Пірсона та найбільші відхилення
	//в меншу та більшу сторони; записую дані до LOG-файлу
	fbit64_t Pj = 10000;
	fbit64_t pX = 0;
	for (ubit8_t i = 0; i < 100; i++)
	{
		pX += ((bucket[i] - Pj) * (bucket[i] - Pj)) / Pj;
	}

	//Звільняю пам'ять
	delete[] bucket;
	delete[] arr;

	return pX;
}

template fbit64_t ALGOR::RANDOM::test_random_on_Pearsons_coefficient<RANDOM::LCM>(ubit32_t, ubit32_t);
template fbit64_t ALGOR::RANDOM::test_random_on_Pearsons_coefficient<RANDOM::MersenneTwister>(ubit32_t, ubit32_t);

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
	return last - first;
}

template <typename type_array>
type_array *ALGOR::ArrayProcessing<type_array>::lower_bound(type_array *first, type_array *last, const type_array &value)
{
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

template <typename type_array>
type_array *ALGOR::ArrayProcessing<type_array>::upper_bound(type_array *first, type_array *last, const type_array &value)
{
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
	if (array_size == 0xffffffff)
	{
		throw EXCEPTION_SET::memory_overflow();
	}
	array_size++;
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
		throw EXCEPTION_SET::void_data();
	}
	if (position >= array_size)
	{
		throw EXCEPTION_SET::position_failure();
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
		throw EXCEPTION_SET::void_data();
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
		throw EXCEPTION_SET::value_failure();
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
		throw EXCEPTION_SET::void_data();
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
void ALGOR::generate_struct(Array<type_array> *&Array, const sbit64_t &min_limit, const sbit64_t &max_limit, const ubit64_t seed, const ubit32_t denominator)
{
	if (denominator == 0)
	{
		throw EXCEPTION_SET::division_by_zero("The Denominator variable is designed to convert the generated integer into a fractional number or find its part. It's a divisor, so it can't be zero!");
	}
	RANDOM::LCM RanGen(seed);
	for (asize_t i = 0; i < Array->array_size; i++)
	{
		Array->array[i] = (min_limit + (RanGen.rand() % (max_limit - min_limit))) / (fbit32_t)denominator;
	}
}

template <typename type_array>
void ALGOR::remove_struct(Array<type_array> *&Array)
{
	if (Array == nullptr || Array->array == nullptr)
	{
		throw EXCEPTION_SET::void_data();
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

template <typename type_array>
ALGOR::ArrayBase<type_array>::ArrayBase() {}

template <typename type_array>
void ALGOR::ArrayBase<type_array>::verification(Array<type_array> *Array)
{
	if (Array == nullptr || Array->array_size == 0 || Array->array == nullptr)
	{
		throw EXCEPTION_SET::void_data();
	}
}

template <typename type_array>
ALGOR::ARRAYDATA<type_array>::ARRAYDATA(Array<type_array> *&Array) : ArrayBase<type_array>(Array) {}

template <typename type_array>
ALGOR::ARRAYDATA<type_array>::ARRAYDATA(const asize_t &SIZE) : ArrayBase<type_array>(SIZE) {}

template <typename type_array>
ALGOR::ARRAYDATA<type_array>::~ARRAYDATA()
{
	remove();
}

template <typename type_array>
void ALGOR::ARRAYDATA<type_array>::generatedData(const sbit64_t &min_limit, const sbit64_t &max_limit, const ubit64_t seed, const ubit32_t denominator)
{
	generate_struct<type_array>(this->ARRAY, min_limit, max_limit, seed, denominator);
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
void ALGOR::ARRAYDATA<type_array>::cloneNewData(Array<type_array> *&Array)
{
	this->verification(Array);
	remove();
	this->ARRAY = create_struct<type_array>(Array->array_size);
	ArrayProcessing<type_array>::copy(this->ARRAY->array, Array->array, Array->array_size);
}

template <typename type_array>
void ALGOR::ARRAYDATA<type_array>::cloneData(Array<type_array> *&Array)
{
	this->verification(Array);
	this->ARRAY = create_struct<type_array>(Array->array_size);
	ArrayProcessing<type_array>::copy(this->ARRAY->array, Array->array, Array->array_size);
}

template <typename type_array>
Array<type_array> *&ALGOR::ARRAYDATA<type_array>::getData()
{
	return this->ARRAY;
}

template <typename type_array>
asize_t ALGOR::ARRAYDATA<type_array>::getSize()
{
	return this->ARRAY->array_size;
}

template <typename type_array>
type_array ALGOR::ARRAYDATA<type_array>::getValue(const asize_t &position)
{
	if (position >= this->ARRAY->array_size)
	{
		throw EXCEPTION_SET::memory_overflow();
	}
	return this->ARRAY->array[position];
}

template <typename type_array>
asize_t ALGOR::ARRAYDATA<type_array>::binary_getPosition(const type_array &required_element)
{
	asize_t position = ArrayProcessing<type_array>::distance(&this->ARRAY->array[0], ArrayProcessing<type_array>::lower_bound(&this->ARRAY->array[0], &this->ARRAY->array[this->ARRAY->array_size - 1], required_element));
	if (this->ARRAY->array[position] != required_element)
	{
		throw EXCEPTION_SET::not_found();
	}
	return position;
}

template <typename type_array>
Array<asize_t> *ALGOR::ARRAYDATA<type_array>::lenear_getPosition(const type_array &required_element)
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
		throw EXCEPTION_SET::not_found();
	}
	return NumberPoints;
}

template <typename type_array>
type_array ALGOR::ARRAYDATA<type_array>::getMin()
{
	return ArrayProcessing<type_array>::isOrderliness(this->ARRAY->array, this->ARRAY->array_size)
		? this->ARRAY->array[0]
		: ArrayProcessing<type_array>::minimum(this->ARRAY->array, this->ARRAY->array_size);
}

template <typename type_array>
type_array ALGOR::ARRAYDATA<type_array>::getMax()
{
	return ArrayProcessing<type_array>::isOrderliness(this->ARRAY->array, this->ARRAY->array_size)
		? this->ARRAY->array[this->ARRAY->array_size - 1]
		: ArrayProcessing<type_array>::maximum(this->ARRAY->array, this->ARRAY->array_size);
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
		throw EXCEPTION_SET::size_failure();
	}
	Array<type_array> *OLD_ARRAY = this->ARRAY, *NEW_ARRAY = create_struct<type_array>(NEW_SIZE);
	asize_t min_size = minimum(OLD_ARRAY->array_size, NEW_ARRAY->array_size);
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
	//TODO Додати перевірку, чи входить задана позиція у діапазон розміру масиву
	this->ARRAY->array[position] = value;
}

template <typename type_array>
void ALGOR::ARRAYDATA<type_array>::reverse()
{
	asize_t left_limit = 0, right_limit = this->ARRAY->array_size - 1;
	for (asize_t i = 0; i < this->ARRAY->array_size / 2; i++)
	{
		swap(this->ARRAY->array[left_limit], this->ARRAY->array[right_limit]);
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
Array<asize_t> *ALGOR::ARRAYDATA<type_array>::searcherOccurrencesOfSubstring(Array<type_array> *&SUBARRAY, ArrayType ArrType)
{
	Array<asize_t> *Occurrences = new Array<asize_t>;
	for (asize_t i = 0; i <= this->ARRAY->array_size - SUBARRAY->array_size; i++)
	{
		for (asize_t j = 0; j < SUBARRAY->array_size; j++)
		{
			if (this->ARRAY->array[i + j] == SUBARRAY->array[j])
			{
				//Це порівняння замінює старий switch-case та оптимізує алгоритм,
				// прибираючи цей зайвий switch. На заміну я адаптував enum під
				// використання у наступному порівнянні.
				if ((ARRAYDATA::ArrayType)(SUBARRAY->array_size - j) == ArrType)
				{
					ArrayProcessing<asize_t>::addElement(Occurrences->array, Occurrences->array_size, i, Occurrences->array_size);
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
		throw EXCEPTION_SET::not_found();
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
		throw EXCEPTION_SET::division_by_zero("Any non-empty array can get into the class, or the class itself can create it. However, you can get the array structure from the class and access the data directly. The author has only one explanation: you somehow reset the size of the array through the structure and now the class works with broken data - in the average() method, the division by the size of the array takes place, which became equal to zero...");
	}
	return average / this->ARRAY->array_size;
}

template <typename type_array>
type_array ALGOR::ARRAYDATA<type_array>::mediana()
{
	return this->ARRAY->array_size & 1 ? (this->ARRAY->array[this->ARRAY->array_size / 2]) : (this->ARRAY->array[this->ARRAY->array_size / 2] + this->ARRAY->array[(this->ARRAY->array_size / 2) - 1]) / 2;
}

template <typename type_array>
typename ALGOR::ARRAYDATA<type_array>::mode *ALGOR::ARRAYDATA<type_array>::moda()
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
		delete (modes);
		throw EXCEPTION_SET::value_failure("And to be precise: there is missing value with the maximum frequency. All elements in the array are unique and repeated once, so to save resources and time, an exception is thrown so that the method does not create a copy of the array further");
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
bool ALGOR::ARRAYDATA<type_array>::operator=(Array<type_array> *&cloningArray)
{
	if (cloningArray == this->ARRAY)
	{
		return false;
	}
	cloneNewData(cloningArray);
	return true;
}

template <typename type_array>
bool ALGOR::ARRAYDATA<type_array>::operator==(Array<type_array> *&anotherArray)
{
	if (anotherArray == this->ARRAY)
	{
		return true;
	}
	if (anotherArray->array_size == this->ARRAY->array_size)
	{
		for (asize_t i = 0; i < this->ARRAY->array_size; i++)
		{
			if (anotherArray->array[i] != this->ARRAY->array[i])
			{
				break;
			}
			if (i == this->ARRAY->array_size - 1)
			{
				return true;
			}
		}
	}
	return false;
}

template <typename type_array>
Array<type_array> *&ALGOR::ARRAYDATA<type_array>::operator^=(const asize_t &NewSize)
{
	if (NewSize == 0)
	{
		throw EXCEPTION_SET::size_failure("The subtracted array size must not be greater than or equal to the current array size!");
	}
	resize(NewSize, 1);
	return this->ARRAY;
}

template <typename type_array>
Array<type_array> *&ALGOR::ARRAYDATA<type_array>::operator+=(const type_array &addValue)
{
	for (asize_t i = 0; i < this->ARRAY->array_size; i++)
	{
		this->ARRAY->array[i] += addValue;
	}
	return this->ARRAY;
}

template <typename type_array>
Array<type_array> *&ALGOR::ARRAYDATA<type_array>::operator-=(const type_array &subtractValue)
{
	for (asize_t i = 0; i < this->ARRAY->array_size; i++)
	{
		this->ARRAY->array[i] -= subtractValue;
	}
	return this->ARRAY;
}

template <typename type_array>
Array<type_array> *&ALGOR::ARRAYDATA<type_array>::operator*=(const type_array &multiplyValue)
{
	for (asize_t i = 0; i < this->ARRAY->array_size; i++)
	{
		this->ARRAY->array[i] *= multiplyValue;
	}
	return this->ARRAY;
}

template <typename type_array>
Array<type_array> *&ALGOR::ARRAYDATA<type_array>::operator/=(const type_array &divideValue)
{
	for (asize_t i = 0; i < this->ARRAY->array_size; i++)
	{
		this->ARRAY->array[i] /= divideValue;
	}
	return this->ARRAY;
}

template <typename type_array>
Array<type_array> *&ALGOR::ARRAYDATA<type_array>::operator&=(const type_array &value)
{
	ArrayProcessing<type_array>::addElement(this->ARRAY->array, this->ARRAY->array_size, value, this->ARRAY->array_size);
	return this->ARRAY;
}

template <typename type_array>
Array<type_array> *&ALGOR::ARRAYDATA<type_array>::operator|=(const type_array &value)
{
	ArrayProcessing<type_array>::subtractValue(this->ARRAY->array, this->ARRAY->array_size, value);
	return this->ARRAY;
}

template <typename type_array>
Array<type_array> *&ALGOR::ARRAYDATA<type_array>::operator!()
{
	ArrayProcessing<type_array>::subtractElement(this->ARRAY->array, this->ARRAY->array_size, this->ARRAY->array_size - 1);
	return this->ARRAY;
}

template <typename type_array>
Array<type_array> *&ALGOR::ARRAYDATA<type_array>::operator<<=(ARRAYDATA<type_array> *&appendingArray)
{
	asize_t old_size = this->ARRAY->array_size;
	resize(old_size + appendingArray->getSize(), 1);
	ArrayProcessing<type_array>::copy(this->ARRAY->array, appendingArray->getData()->array, appendingArray->getSize(), old_size);
	return this->ARRAY;
}

template <typename type_array>
Array<type_array> *&ALGOR::ARRAYDATA<type_array>::operator>>=(ARRAYDATA<type_array> *&appendingArray)
{
	asize_t old_size = appendingArray->getSize();
	appendingArray->resize(old_size + this->ARRAY->array_size, 1);
	ArrayProcessing<type_array>::copy(appendingArray->getData()->array, this->ARRAY->array, this->ARRAY->array_size, old_size);
	return this->ARRAY;
}

template class ALGOR::ArrayProcessing<byte8_t>;
template class ALGOR::ArrayProcessing<ubit64_t>;
template class ALGOR::ArrayProcessing<fbit64_t>;
template class ALGOR::ArrayProcessing<fbit128_t>;
template class ALGOR::ArrayProcessing<asize_t>;

template Array<byte8_t> *ALGOR::create_struct<byte8_t>(const asize_t &, bool);
template Array<ubit64_t> *ALGOR::create_struct<ubit64_t>(const asize_t &, bool);
template Array<fbit64_t> *ALGOR::create_struct<fbit64_t>(const asize_t &, bool);
template Array<fbit128_t> *ALGOR::create_struct<fbit128_t>(const asize_t &, bool);
template Array<asize_t> *ALGOR::create_struct<asize_t>(const asize_t &, bool);

template void ALGOR::generate_struct<byte8_t>(Array<byte8_t> *&, const sbit64_t &, const sbit64_t &, const ubit64_t, const ubit32_t);
template void ALGOR::generate_struct<ubit64_t>(Array<ubit64_t> *&, const sbit64_t &, const sbit64_t &, const ubit64_t, const ubit32_t);
template void ALGOR::generate_struct<fbit64_t>(Array<fbit64_t> *&, const sbit64_t &, const sbit64_t &, const ubit64_t, const ubit32_t);
template void ALGOR::generate_struct<fbit128_t>(Array<fbit128_t> *&, const sbit64_t &, const sbit64_t &, const ubit64_t, const ubit32_t);
template void ALGOR::generate_struct<asize_t>(Array<asize_t> *&, const sbit64_t &, const sbit64_t &, const ubit64_t, const ubit32_t);

template void ALGOR::remove_struct<byte8_t>(Array<byte8_t> *&);
template void ALGOR::remove_struct<ubit64_t>(Array<ubit64_t> *&);
template void ALGOR::remove_struct<fbit64_t>(Array<fbit64_t> *&);
template void ALGOR::remove_struct<fbit128_t>(Array<fbit128_t> *&);
template void ALGOR::remove_struct<asize_t>(Array<asize_t> *&);

template class ALGOR::ARRAYDATA<byte8_t>;
template class ALGOR::ARRAYDATA<ubit64_t>;
template class ALGOR::ARRAYDATA<fbit64_t>;
template class ALGOR::ARRAYDATA<fbit128_t>;
template class ALGOR::ARRAYDATA<asize_t>;

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
void ALGOR::Comparative_Sorts<type_array>::Library_Sort()
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

template <typename type_array>
void ALGOR::Comparative_Sorts<type_array>::Bitonic_Sorter()
{
	BitonicSorter *sort = new BitonicSorter(this->ARRAY->array, this->ARRAY->array_size);
	sort->bitonic_sorter();
	delete (sort);
}

template <typename type_array>
void ALGOR::Comparative_Sorts<type_array>::Batcher_OddEven_MergeSort()
{
	BatcherOddEvenMergeSort *sort = new BatcherOddEvenMergeSort(this->ARRAY->array, this->ARRAY->array_size);
	sort->batcher_odd_even_merge_sort();
	delete (sort);
}

template <typename type_array>
void ALGOR::Comparative_Sorts<type_array>::Tim_Sort()
{
	TimSort *sort = new TimSort(this->ARRAY->array, this->ARRAY->array_size);
	sort->tim_sort();
	delete (sort);
}

template <typename type_array>
void ALGOR::Comparative_Sorts<type_array>::Pancake_Sort()
{
	PancakeSort *sort = new PancakeSort(this->ARRAY->array, this->ARRAY->array_size);
	sort->pancake_sort();
	delete (sort);
}

template <typename type_array>
ALGOR::Comparative_Sorts<type_array>::BatcherOddEvenMergeSort::BatcherOddEvenMergeSort(type_array *array, asize_t asize) : Array(array), array_size(asize) {}

template <typename type_array>
void ALGOR::Comparative_Sorts<type_array>::BatcherOddEvenMergeSort::batcher_odd_even_merge_sort()
{
	//Працює тільки з масивами, розмір яких 2 у степені N (2, 4, 8, 16, 32, 64...)
	// але якщо значеня у масиві використовуються цілі+, то алгоритм працює з будь-яким розміром
	for (asize_t p = 1; p < array_size; p *= 2)
	{
		for (asize_t k = p; k >= 1; k /= 2)
		{
			for (asize_t j = k % p; j <= array_size - 1 - k; j += 2 * k)
			{
				for (asize_t i = 0; i <= k - 1; i++)
				{
					if ((byte4_t)((i + j) / (p * 2)) == (byte4_t)((i + j + k) / (p * 2)))
					{
						if (Array[i + j] > Array[i + j + k])
						{
							swap(Array[i + j], Array[i + j + k]);
						}
					}
				}
			}
		}
	}
}

template <typename type_array>
ALGOR::Comparative_Sorts<type_array>::BitonicSorter::BitonicSorter(type_array *array, asize_t asize) : Array(array), array_size(asize) {}

template <typename type_array>
void ALGOR::Comparative_Sorts<type_array>::BitonicSorter::bitonic_sorter()
{
	//Працює тільки з масивами, розмір яких 2 у степені N (2, 4, 8, 16, 32, 64...)
	for (asize_t k = 2; k <= array_size; k *= 2)
	{
		for (asize_t j = k / 2; j > 0; j /= 2)
		{
			for (asize_t i = 0; i < array_size; i++)
			{
				asize_t l = i ^ j;
				if (l > i)
				{
					if ((((i & k) == 0) && (Array[i] > Array[l])) || (((i & k) != 0) && (Array[i] < Array[l])))
					{
						swap(Array[i], Array[l]);
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
	while (!ArrayProcessing<type_array>::isOrderliness(Array, array_size))
	{
		Shuffle();
	}
}

template <typename type_array>
void ALGOR::Comparative_Sorts<type_array>::BogoSort::Shuffle()
{
	RANDOM::MersenneTwister RanGen(getMemoryCell(32));
	for (asize_t i = 0; i < array_size; i++)
	{
		swap(Array[i], Array[RanGen.IRandom(0, array_size - 1)]);
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
				swap(Array[j], Array[j + 1]);
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
				swap(Array[i], Array[i - 1]);
			}
		}
		leftMark++;
		for (asize_t i = leftMark; i <= rightMark; i++)
		{
			if (Array[i - 1] > Array[i])
			{
				swap(Array[i], Array[i - 1]);
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
	fbit64_t factor = 1.2473309;	//Фактор зменшення
	ubit32_t step = array_size - 1; //Шаг

	while (step >= 1)
	{
		for (asize_t i = 0; i + step < array_size; i++)
		{
			if (Array[i] > Array[i + step])
			{
				swap(Array[i], Array[i + step]);
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
		swap(Array[pos], item);

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
			swap(Array[pos], item);
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
				swap(Array[i], Array[i - 1]);
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
	for (byte4_t right = array_size / 2 - 1; right >= 0; right--)
	{
		heapify(Array, right, array_size);
	}
	for (byte4_t i = array_size - 1; i >= 0; i--)
	{
		swap(Array[0], Array[i]);
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
		swap(Array[count], Array[large]);
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
			swap(Array[j - 1], Array[j]);
		}
	}
}

template <class type_array>
ALGOR::Comparative_Sorts<type_array>::LibrarySort::LibrarySort(type_array *array, asize_t asize) : Array(array), array_size(asize) {}

template <class type_array>
void ALGOR::Comparative_Sorts<type_array>::LibrarySort::library_sort()
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
void ALGOR::Comparative_Sorts<type_array>::LibrarySort::initialization()
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
void ALGOR::Comparative_Sorts<type_array>::LibrarySort::binarysearch()
{
	insert = ArrayProcessing<type_array>::distance(library[target_lib], ArrayProcessing<type_array>::lower_bound(library[target_lib], library[target_lib] + lib_size, Array[index_pos]));
}

template <class type_array>
void ALGOR::Comparative_Sorts<type_array>::LibrarySort::insertion()
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
void ALGOR::Comparative_Sorts<type_array>::LibrarySort::rebalancing()
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
void ALGOR::Comparative_Sorts<type_array>::LibrarySort::finalization()
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
				swap(Array[j - 1], Array[j]);
			}
		}
	}
}

template <typename type_array>
ALGOR::Comparative_Sorts<type_array>::PancakeSort::PancakeSort(type_array *array, asize_t asize) : Array(array), array_size(asize) {}

template <typename type_array>
void ALGOR::Comparative_Sorts<type_array>::PancakeSort::pancake_sort()
{
	while (array_size > 1)
	{
		asize_t maxIndex = max_index();
		flip(maxIndex);
		flip(--array_size);
	}
}

template <typename type_array>
asize_t ALGOR::Comparative_Sorts<type_array>::PancakeSort::max_index()
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

template <typename type_array>
void ALGOR::Comparative_Sorts<type_array>::PancakeSort::flip(asize_t index)
{
	asize_t left = 0;
	while (left < index)
	{
		swap(Array[left], Array[index]);
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
void ALGOR::Comparative_Sorts<type_array>::QuickSort::recursive_quick_sort(const byte4_t &left_limit, const byte4_t &right_limit)
{
	type_array middle = Array[(left_limit + right_limit) / 2];
	byte4_t start = left_limit, finish = right_limit;
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
			swap(Array[start], Array[finish]);
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
			swap(Array[i], Array[min_index]);
		}
	}
}

template <typename type_array>
ALGOR::Comparative_Sorts<type_array>::ShellSort::ShellSort(type_array *array, asize_t asize) : Array(array), array_size(asize) {}

template <typename type_array>
void ALGOR::Comparative_Sorts<type_array>::ShellSort::shell_sort()
{
	// j = signed, i & step = unsigned; max size = int / 2 = 2 billion
	for (asize_t step = array_size / 2; step > 0; step /= 2)
	{
		for (asize_t i = step; i < array_size; i++)
		{
			for (byte4_t j = i - step; j >= 0 && Array[j] > Array[j + step]; j -= step)
			{
				swap(Array[j], Array[j + step]);
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
void ALGOR::Comparative_Sorts<type_array>::SlowSort::recursive_slow_sort(const asize_t &left_limit, const asize_t &right_limit)
{
	if (left_limit >= right_limit)
	{
		return;
	}
	byte4_t middle = (left_limit + right_limit) / 2;
	recursive_slow_sort(left_limit, middle);
	recursive_slow_sort(middle + 1, right_limit);
	if (Array[middle] > Array[right_limit])
	{
		swap(Array[middle], Array[right_limit]);
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
void ALGOR::Comparative_Sorts<type_array>::StoogeSort::recursive_stooge_sort(const asize_t &left_limit, const asize_t &right_limit)
{
	if (Array[left_limit] > Array[right_limit])
	{
		swap(Array[left_limit], Array[right_limit]);
	}
	if (left_limit + 1 >= right_limit)
	{
		return;
	}

	byte4_t k = (byte4_t)((right_limit - left_limit + 1) / 3);
	recursive_stooge_sort(left_limit, right_limit - k);
	recursive_stooge_sort(left_limit + k, right_limit);
	recursive_stooge_sort(left_limit, right_limit - k);
}

template <typename type_array>
ALGOR::Comparative_Sorts<type_array>::TimSort::TimSort(type_array *array, asize_t asize) : Array(array), array_size(asize) {}

template <typename type_array>
void ALGOR::Comparative_Sorts<type_array>::TimSort::tim_sort()
{
	for (asize_t i = 0; i < array_size; i += RUN)
	{
		insertionSort(i, minimum((i + 31), (array_size - 1)));
	}
	for (asize_t size = RUN; size < array_size; size *= 2)
	{
		for (asize_t left = 0; left < array_size; left += 2 * size)
		{
			asize_t middle = left + size - 1;
			asize_t right = minimum((left + 2 * size - 1), (array_size - 1));
			merge(left, middle, right);
		}
	}
}

template <typename type_array>
void ALGOR::Comparative_Sorts<type_array>::TimSort::insertionSort(asize_t left_limit, asize_t right_limit)
{
	for (asize_t i = left_limit + 1; i <= right_limit; i++)
	{
		type_array temp = Array[i];
		byte4_t j = i - 1;
		while (Array[j] > temp && j >= (byte4_t)left_limit)
		{
			Array[j + 1] = Array[j];
			j--;
		}
		Array[j + 1] = temp;
	}
}

template <typename type_array>
void ALGOR::Comparative_Sorts<type_array>::TimSort::merge(asize_t left_limit, asize_t middle, asize_t right_limit)
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
typename ALGOR::Comparative_Sorts<type_array>::TreeSort::Tree *ALGOR::Comparative_Sorts<type_array>::TreeSort::newnode(type_array key)
{
	Tree *temp = new Tree;
	temp->data = key;
	temp->left = nullptr;
	temp->right = nullptr;
	return temp;
}

template <typename type_array>
typename ALGOR::Comparative_Sorts<type_array>::TreeSort::Tree *ALGOR::Comparative_Sorts<type_array>::TreeSort::insert(Tree *node, type_array key)
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

ALGOR::Distribution_Sorts::Distribution_Sorts(Array<byte8_t> *&Array) : ArrayBase<byte8_t>(Array) {}

void ALGOR::Distribution_Sorts::AmericanFlag_Sort()
{
	AmericanFlagSort *sort = new AmericanFlagSort(this->ARRAY->array, this->ARRAY->array_size);
	sort->american_flag_sort();
	delete (sort);
}

void ALGOR::Distribution_Sorts::Bead_Sort()
{
	BeadSort *sort = new BeadSort(this->ARRAY->array, this->ARRAY->array_size);
	sort->bead_sort();
	delete (sort);
}

void ALGOR::Distribution_Sorts::Bucket_Sort()
{
	BucketSort *sort = new BucketSort(this->ARRAY->array, this->ARRAY->array_size);
	sort->bucket_sort();
	delete (sort);
}

void ALGOR::Distribution_Sorts::Counting_Sort()
{
	CountingSort *sort = new CountingSort(this->ARRAY->array, this->ARRAY->array_size);
	sort->counting_sort();
	delete (sort);
}

void ALGOR::Distribution_Sorts::Interpolation_Sort()
{
	InterpolationSort *sort = new InterpolationSort(this->ARRAY->array, this->ARRAY->array_size);
	sort->interpolation_sort();
	delete (sort);
}

void ALGOR::Distribution_Sorts::Pigeonhole_Sort()
{
	PigeonholeSort *sort = new PigeonholeSort(this->ARRAY->array, this->ARRAY->array_size);
	sort->pigeonhole_sort();
	delete (sort);
}

void ALGOR::Distribution_Sorts::Radix_Sort()
{
	RadixSort *sort = new RadixSort(this->ARRAY->array, this->ARRAY->array_size);
	sort->radix_sort();
	delete (sort);
}

void ALGOR::Distribution_Sorts::Flash_Sort()
{
	FlashSort *sort = new FlashSort(this->ARRAY->array, this->ARRAY->array_size);
	sort->flash_sort();
	delete (sort);
}

ALGOR::Distribution_Sorts::AmericanFlagSort::AmericanFlagSort(byte8_t *array, asize_t asize) : Array(array), array_size(asize) {}

void ALGOR::Distribution_Sorts::AmericanFlagSort::american_flag_sort()
{
	byte8_t max = 1;
	for (byte8_t i = 0; i < getMaxNumberOfDigits() - 1; i++)
	{
		max *= 10;
	}
	recursive_american_flag_sort(0, (byte8_t)array_size, max);
}

void ALGOR::Distribution_Sorts::AmericanFlagSort::recursive_american_flag_sort(byte8_t start, byte8_t length, byte8_t divisor)
{
	byte8_t *count = new byte8_t[NUMBER_OF_BUCKETS]{0};
	byte8_t digit = 0;

	for (byte8_t i = start; i < length; i++)
	{
		byte8_t array_digit = Array[i];
		digit = getDigit(array_digit, divisor);
		count[digit]++;
	}

	byte8_t *offset = new byte8_t[NUMBER_OF_BUCKETS];
	offset[0] = start + 0;
	for (byte8_t i = 1; i < NUMBER_OF_BUCKETS; i++)
	{
		offset[i] = count[i - 1] + offset[i - 1];
	}

	for (byte8_t bucket = 0; bucket < NUMBER_OF_BUCKETS; bucket++)
	{
		while (count[bucket] > 0)
		{
			byte8_t origin = offset[bucket];
			byte8_t from = origin;
			byte8_t num = Array[from];
			Array[from] = -1;
			do
			{
				digit = getDigit(num, divisor);
				byte8_t to = offset[digit]++;
				count[digit]--;
				byte8_t temp = Array[to];
				Array[to] = num;
				num = temp;
				from = to;
			} while (from != origin);
		}
	}
	if (divisor > 1)
	{
		for (byte8_t i = 0; i < NUMBER_OF_BUCKETS; i++)
		{
			byte8_t begin = (i > 0) ? offset[i - 1] : start;
			byte8_t end = offset[i];
			if (end - begin > 1)
			{
				recursive_american_flag_sort(begin, end, divisor / 10);
			}
		}
	}
}

byte8_t ALGOR::Distribution_Sorts::AmericanFlagSort::getMaxNumberOfDigits()
{
	byte8_t count = 1;
	byte8_t value = ArrayProcessing<byte8_t>::maximum(Array, array_size);
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

byte8_t ALGOR::Distribution_Sorts::AmericanFlagSort::getDigit(byte8_t integer, byte8_t divisor)
{
	return (integer / divisor) % 10;
}

ALGOR::Distribution_Sorts::BeadSort::BeadSort(byte8_t *array, asize_t asize) : Array(array), array_size(asize) {}

void ALGOR::Distribution_Sorts::BeadSort::bead_sort()
{
	max = ArrayProcessing<byte8_t>::maximum(Array, array_size);
	beads = new ubit8_t[max * array_size]{0};

	for (asize_t i = 0; i < array_size; i++)
	{
		for (byte8_t j = 0; j < Array[i]; j++)
		{
			beads[i * max + j] = 1;
		}
	}
	for (byte8_t j = 0; j < max; j++)
	{
		byte8_t sum = 0;
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
		byte8_t j = 0;
		for (; j < max && beads[i * max + j]; j++)
			;
		Array[i] = j;
	}

	delete[] beads;
}

ALGOR::Distribution_Sorts::BucketSort::BucketSort(byte8_t *array, asize_t asize) : Array(array), array_size(asize) {}

void ALGOR::Distribution_Sorts::BucketSort::bucket_sort()
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

	min = ArrayProcessing<byte8_t>::minimum(Array, array_size);
	max = ArrayProcessing<byte8_t>::maximum(Array, array_size);
	range = (max - min) / (byte8_t)array_size;
	range++;

	bucket = new byte8_t *[array_size];
	for (asize_t i = 0; i < array_size; i++)
	{
		bucket[i] = new byte8_t[1];
		bucket[i][0] = 1;
	}

	for (asize_t i = 0; i < array_size; i++)
	{
		bucket_index = asize_t((Array[i] - min) / range);
		if (bucket_index == array_size)
		{
			bucket_index--;
		}
		ArrayProcessing<byte8_t>::addElement(bucket[bucket_index], (asize_t &)bucket[bucket_index][0], Array[i], bucket[bucket_index][0]);
	}

	for (asize_t i = 0; i < array_size; i++)
	{
		if (bucket[i][0] > 2)
		{
			CountingSort *sorter = new CountingSort(bucket[i] + 1, bucket[i][0] - 1);
			sorter->counting_sort();
			delete (sorter);
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

ALGOR::Distribution_Sorts::CountingSort::CountingSort(byte8_t *array, asize_t asize) : Array(array), array_size(asize) {}

void ALGOR::Distribution_Sorts::CountingSort::counting_sort()
{
	min = ArrayProcessing<byte8_t>::minimum(Array, array_size);
	max = ArrayProcessing<byte8_t>::maximum(Array, array_size);
	tempArray = new byte8_t[max - min + 1];
	for (byte8_t i = 0; i < max - min + 1; i++)
	{
		tempArray[i] = 0;
	}
	for (asize_t i = 0; i < array_size; i++)
	{
		tempArray[Array[i] - min] = tempArray[Array[i] - min] + 1;
	}
	for (byte8_t i = 0, j = min; j < max + 1; j++)
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

ALGOR::Distribution_Sorts::FlashSort::FlashSort(byte8_t *array, asize_t asize) : Array(array), array_size(asize) {}

void ALGOR::Distribution_Sorts::FlashSort::flash_sort()
{
	const asize_t middle = (byte8_t)(0.45 * array_size);

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
	if (middle == 0)
	{
		if (array_size == 2 && Array[0] > Array[1])
		{
			swap(Array[0], Array[1]);
		}
		return;
	}

	L = new byte8_t[middle];

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
		throw EXCEPTION_SET::division_by_zero();
	}

	const asize_t c1 = (middle - 1) / (Array[max] - Array[min]);

	for (asize_t i = 0; i < middle; i++)
	{
		L[i] = 0;
	}
	for (asize_t i = 0; i < array_size; ++i)
	{
		++L[c1 * (Array[i] - min)];
	}
	for (asize_t i = 1; i < middle; ++i)
	{
		L[i] = L[i] + L[i - 1];
	}

	swap(Array[max], Array[0]);

	k = middle - 1;

	while (move < array_size - 1)
	{
		while ((byte8_t)j > L[k] - 1)
		{
			++j;
			k = c1 * (Array[j] - min);
		}
		flash = Array[j];
		while ((byte8_t)j != L[k])
		{
			k = c1 * (flash - Array[min]);
			swap(Array[L[k] - 1], flash);
			L[k]--;
			move++;
		}
	}

	for (j = 1; j < array_size; j++)
	{
		flash = Array[j];
		byte8_t i = j - 1;
		while (i >= 0 && Array[i] > flash)
		{
			Array[i + 1] = Array[i];
			i--;
		}
		Array[i + 1] = flash;
	}
}

ALGOR::Distribution_Sorts::InterpolationSort::InterpolationSort(byte8_t *array, asize_t asize) : Array(array), array_size(asize) {}

void ALGOR::Distribution_Sorts::InterpolationSort::interpolation_sort()
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
			while (((nArray_max - nArray_min) / ifac) > ((byte8_t)array_size - 1))
			{
				ifac++;
			}
		}

		space = new byte8_t[2 * array_size + 1];

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

		for (byte4_t i = array_size; --i >= 0;)
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

		ArrayProcessing<byte8_t>::copy(Array, sorted, array_size);

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

void ALGOR::Distribution_Sorts::InterpolationSort::getMin()
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

void ALGOR::Distribution_Sorts::InterpolationSort::getMax()
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

ALGOR::Distribution_Sorts::PigeonholeSort::PigeonholeSort(byte8_t *array, asize_t asize) : Array(array), array_size(asize) {}

void ALGOR::Distribution_Sorts::PigeonholeSort::pigeonhole_sort()
{
	min = ArrayProcessing<byte8_t>::minimum(Array, array_size);
	max = ArrayProcessing<byte8_t>::maximum(Array, array_size);
	range = (asize_t)max - (asize_t)min + 1;

	hole = new byte8_t *[range];
	for (asize_t i = 0; i < range; i++)
	{
		hole[i] = new byte8_t[1];
		hole[i][0] = 1;
	}

	for (asize_t i = 0; i < array_size; i++)
	{
		ArrayProcessing<byte8_t>::addElement(hole[Array[i] - min], (asize_t &)hole[Array[i] - min][0], Array[i], hole[Array[i] - min][0]);
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

ALGOR::Distribution_Sorts::RadixSort::RadixSort(byte8_t *array, asize_t asize) : Array(array), array_size(asize) {}

void ALGOR::Distribution_Sorts::RadixSort::radix_sort()
{
	max = ArrayProcessing<byte8_t>::maximum(Array, array_size);
	tempArray = new byte8_t[array_size];
	bucket = new byte8_t[bit];
	while (max / exp > 0)
	{
		for (byte4_t i = 0; i < bit; i++)
		{
			bucket[i] = 0;
		}
		for (asize_t i = 0; i < array_size; i++)
		{
			bucket[(Array[i] / exp) % bit]++;
		}
		for (byte4_t i = 1; i < bit; i++)
		{
			bucket[i] += bucket[i - 1];
		}
		for (byte4_t i = array_size - 1; i >= 0; i--)
		{
			current = (Array[i] % (exp * bit)) / exp;
			bucket[current]--;
			tempArray[bucket[current]] = Array[i];
		}
		for (asize_t i = 0; i < array_size; i++)
		{
			Array[i] = tempArray[i];
		}
		exp *= bit;
	}
	delete[] bucket;
	delete[] tempArray;
}

template class ALGOR::Comparative_Sorts<byte8_t>;
template class ALGOR::Comparative_Sorts<ubit64_t>;
template class ALGOR::Comparative_Sorts<fbit64_t>;
template class ALGOR::Comparative_Sorts<fbit128_t>;
template class ALGOR::Comparative_Sorts<asize_t>;

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
