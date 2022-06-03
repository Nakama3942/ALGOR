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
void ALGOR::swap(type_value &firstNumber, type_value &secondNumber)
{
	type_value *temp = new type_value(firstNumber);
	firstNumber = secondNumber;
	secondNumber = *temp;
	delete (temp);
}

template <typename type_value>
type_value ALGOR::minimum(type_value firstNumber, type_value secondNumber)
{
	return firstNumber < secondNumber ? firstNumber : secondNumber;
}

template <typename type_value>
type_value ALGOR::maximum(type_value firstNumber, type_value secondNumber)
{
	return firstNumber > secondNumber ? firstNumber : secondNumber;
}

memcell_t ALGOR::getMemoryCell()
{
	memcell_t *cells = new memcell_t[10];
	memcell_t *cell = new memcell_t(cells[0]);
	for (int i = 1; i < 8; i++)
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
	for (int i = 1; i < 8; i++)
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

ALGOR::Exception::Exception(unsigned int CODE, const char *DETAILS)
{
	this->CODE = CODE;
	this->DETAILS = DETAILS;
}

ALGOR::Exception::Exception(unsigned int CODE)
{
	this->CODE = CODE;
	this->DETAILS = "No information given";
}

ALGOR::Exception::Exception(const char *DETAILS)
{
	this->CODE = 0xffffffff;
	this->DETAILS = DETAILS;
}

unsigned int ALGOR::Exception::code()
{
	return CODE;
}

const char *ALGOR::Exception::what()
{
	return DETAILS;
}

ALGOR::memory_overflow::memory_overflow() : Exception(55, "The memory cell that stores the size of the data volume can no longer store more. This error can occur in cases when a larger value is required to be written to the cell that can store the variable 0xffffffff, i.e. more than 4 bytes, since the data size storage cell occupies 4 bytes.") {}

ALGOR::division_by_zero::division_by_zero() : Exception(101, "A division by zero has occurred - an undefined result of the program execution") {}

ALGOR::position_failure::position_failure() : Exception(254, "Position failure - position is missing in the array") {}

ALGOR::value_failure::value_failure() : Exception(255, "Value failure - value is missing in the array") {}

ALGOR::void_data::void_data() : Exception(400, "Geted empty data structure") {}

ALGOR::not_found::not_found() : Exception(404, "Search error - item not found") {}

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
		swap(Sbox[i], Sbox[j]);
	}
}

void ALGOR::RC4::crypto_rand(char *output, int size)
{
	ubit8_t i = 0, j = 0, t;
	for (int k = 0; i < size; k++)
	{
		i += 1;
		j += Sbox[i];
		swap(Sbox[i], Sbox[j]);
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

void ALGOR::array_size_verification(const asize_t &asize)
{
	if (asize == 0)
	{
		throw void_data();
	}
}

template <typename type_array>
type_array ALGOR::ArrayProcessing::minimum(const type_array *Array, const asize_t &array_size)
{
	array_size_verification(array_size);
	type_array point_min = Array[0];
	for (unsigned int i = 1; i < array_size; i++)
	{
		if (point_min > Array[i])
		{
			point_min = Array[i];
		}
	}
	return point_min;
}

template <typename type_array>
type_array ALGOR::ArrayProcessing::maximum(const type_array *Array, const asize_t &array_size)
{
	array_size_verification(array_size);
	type_array point_max = Array[0];
	for (unsigned int i = 1; i < array_size; i++)
	{
		if (point_max < Array[i])
		{
			point_max = Array[i];
		}
	}
	return point_max;
}

template <typename type_array>
bool ALGOR::ArrayProcessing::isOrderliness(const type_array *Array, const asize_t &array_size)
{
	array_size_verification(array_size);
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
asize_t ALGOR::ArrayProcessing::distance(type_array *first, type_array *last)
{
	//http://www.cplusplus.com/reference/iterator/distance/?kw=distance
	return last - first;
}

template <typename type_array>
type_array *ALGOR::ArrayProcessing::lower_bound(type_array *first, type_array *last, const type_array &value)
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
type_array *ArrayProcessing::upper_bound(type_array *first, type_array *last, const type_array &value)
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
void ALGOR::ArrayProcessing::addElement(type_array *&Array, asize_t &array_size, const type_array &value, const unsigned int position)
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
	for (unsigned int i = 0; i < array_size; i++)
	{
		position > i ? temp_Array[i] = Array[i] : (position == i ? temp_Array[i] = value : temp_Array[i] = Array[i - 1]);
	}
	delete[] Array;
	Array = new type_array[array_size];
	copy(Array, temp_Array, array_size);
	delete[] temp_Array;
}

template <typename type_array>
void ALGOR::ArrayProcessing::subtractElement(type_array *&Array, asize_t &array_size, const unsigned int position)
{
	array_size_verification(array_size);
	if (array_size == 1)
	{
		delete[] Array;
		return;
	}
	if (position >= array_size)
	{
		throw position_failure();
	}
	type_array *temp_Array = new type_array[array_size];
	for (unsigned int i = 0; i < array_size; i++)
	{
		position > i ? temp_Array[i] = Array[i] : (position < i ? temp_Array[i - 1] = Array[i] : 0);
	}
	delete[] Array;
	Array = new type_array[array_size--];
	copy(Array, temp_Array, array_size);
	delete[] temp_Array;
}

template <typename type_array>
void ALGOR::ArrayProcessing::subtractValue(type_array *&Array, asize_t &array_size, const type_array &value)
{
	array_size_verification(array_size);
	int counter = 0;
	type_array *temp_Array = new type_array[array_size];
	for (unsigned int i = 0; i < array_size; i++)
	{
		Array[i] != value ? temp_Array[i - counter] = Array[i] : counter++;
	}
	if (counter == 0)
	{
		delete[] temp_Array;
		throw value_failure();
	}
	delete[] Array;
	array_size -= counter;
	Array = new type_array[array_size];
	copy(Array, temp_Array, array_size);
	delete[] temp_Array;
}

template <typename type_array>
void ALGOR::ArrayProcessing::copy(type_array *new_array, const type_array *old_array, const unsigned int &size_of_copied, unsigned int position_in_new_array, unsigned int position_in_old_array)
{
	for (unsigned int i = 0; i < size_of_copied; i++)
	{
		new_array[i + position_in_new_array] = old_array[i + position_in_old_array];
	}
}

template <typename type_array>
Array<type_array> *ALGOR::create_struct(const asize_t &SIZE)
{
	array_size_verification(SIZE);
	Array<type_array> *ARRAY = new Array<type_array>;
	ARRAY->array_size = SIZE;
	ARRAY->array = new type_array[SIZE];
	return ARRAY;
}

template <typename type_array>
void ALGOR::remove_struct(Array<type_array> *&Array)
{
	if (Array == nullptr)
	{
		throw void_data();
	}
	delete[] Array->array;
	delete (Array);
	Array = nullptr;
}

template <typename type_array>
ALGOR::ArrayBase<type_array>::ArrayBase(Array<type_array> *&Array) : ARRAY(Array) { array_size_verification(ARRAY->array_size); }

template <typename type_array>
ALGOR::ArrayBase<type_array>::ArrayBase(const asize_t &SIZE) { ARRAY = create_struct<type_array>(SIZE); }

template <typename type_array>
ALGOR::ArrayBase<type_array>::ArrayBase() {}

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
void ALGOR::ARRAYDATA<type_array>::generatedData(const int &min_limit, const int &max_limit)
{
	memcell_t cell = getMemoryCell();
	cell >>= 32;
	MersenneTwister RanGen(cell);
	for (asize_t i = 0; i < this->ARRAY->array_size; i++)
	{
		this->ARRAY->array[i] = RanGen.IRandom(min_limit, max_limit);
	}
}

template <typename type_array>
void ALGOR::ARRAYDATA<type_array>::setNewData(Array<type_array> *&Array)
{
	array_size_verification(Array->array_size);
	remove();
	this->ARRAY = Array;
}

template <typename type_array>
void ALGOR::ARRAYDATA<type_array>::setData(Array<type_array> *&Array)
{
	array_size_verification(Array->array_size);
	this->ARRAY = Array;
}

template <typename type_array>
void ALGOR::ARRAYDATA<type_array>::cloneData(Array<type_array> *&CloningArray)
{
	array_size_verification(CloningArray->array_size);
	if (CloningArray->array_size != this->ARRAY->array_size)
	{
		remove();
		this->ARRAY = create_struct<type_array>(CloningArray->array_size);
	}
	ArrayProcessing::copy<type_array>(this->ARRAY->array, CloningArray->array, CloningArray->array_size);
}

template <typename type_array>
void ALGOR::ARRAYDATA<type_array>::cloneData(ARRAYDATA<type_array> *&CloningObject)
{
	if (CloningObject->getData()->array_size != this->ARRAY->array_size)
	{
		remove();
		this->ARRAY = create_struct<type_array>(CloningObject->getData()->array_size);
	}
	ArrayProcessing::copy<type_array>(this->ARRAY->array, CloningObject->getData()->array, CloningObject->getData()->array_size);
}

template <typename type_array>
void ALGOR::ARRAYDATA<type_array>::getData(Array<type_array> *&DATA)
{
	DATA = this->ARRAY;
}

template <typename type_array>
Array<type_array> *ALGOR::ARRAYDATA<type_array>::getData()
{
	return this->ARRAY;
}

template <typename type_array>
void ALGOR::ARRAYDATA<type_array>::reset()
{
	asize_t SIZE = this->ARRAY->array_size;
	type_array min = getMin(), max = getMax();
	remove();
	this->ARRAY = create_struct<type_array>(SIZE);
	generatedData(min, max);
}

template <typename type_array>
void ALGOR::ARRAYDATA<type_array>::resize(const asize_t &NEW_SIZE, const type_array &setElement)
{
	Array<type_array> *OLD_ARRAY = this->ARRAY, *NEW_ARRAY = create_struct<type_array>(NEW_SIZE);
	if (OLD_ARRAY->array_size < NEW_ARRAY->array_size)
	{
		ArrayProcessing::copy<type_array>(NEW_ARRAY->array, OLD_ARRAY->array, OLD_ARRAY->array_size);
		for (asize_t i = OLD_ARRAY->array_size; i < NEW_ARRAY->array_size; i++)
		{
			NEW_ARRAY->array[i] = setElement;
		}
	}
	else
	{
		ArrayProcessing::copy<type_array>(NEW_ARRAY->array, OLD_ARRAY->array, NEW_ARRAY->array_size);
	}
	this->ARRAY = NEW_ARRAY;
	remove_struct<type_array>(OLD_ARRAY);
}

template <typename type_array>
void ALGOR::ARRAYDATA<type_array>::replace(const unsigned int &position, const type_array &value)
{
	this->ARRAY->array[position] = value;
}

template <typename type_array>
void ALGOR::ARRAYDATA<type_array>::reverse()
{
	int left_limit = 0, right_limit = this->ARRAY->array_size - 1;
	for (asize_t i = 0; i < this->ARRAY->array_size / 2; i++)
	{
		swap<type_array>(this->ARRAY->array[left_limit], this->ARRAY->array[right_limit]);
		left_limit++;
		right_limit--;
	}
}

template <typename type_array>
void ALGOR::ARRAYDATA<type_array>::respawn()
{
	asize_t size = this->ARRAY->array_size;
	remove();
	this->ARRAY = create_struct<type_array>(size);
}

template <typename type_array>
type_array ALGOR::ARRAYDATA<type_array>::getMin()
{
	return ArrayProcessing::isOrderliness<type_array>(this->ARRAY->array, this->ARRAY->array_size) ? this->ARRAY->array[0] : ArrayProcessing::minimum<type_array>(this->ARRAY->array, this->ARRAY->array_size);
}

template <typename type_array>
type_array ALGOR::ARRAYDATA<type_array>::getMax()
{
	return ArrayProcessing::isOrderliness<type_array>(this->ARRAY->array, this->ARRAY->array_size) ? this->ARRAY->array[this->ARRAY->array_size - 1] : ArrayProcessing::maximum<type_array>(this->ARRAY->array, this->ARRAY->array_size);
}

template <typename type_array>
Array<int> *ALGOR::ARRAYDATA<type_array>::lenear_searcher(const type_array &required_element)
{
	Array<int> *NumberPoints = new Array<int>;
	for (asize_t i = 0; i < this->ARRAY->array_size; i++)
	{
		if (required_element == this->ARRAY->array[i])
		{
			ArrayProcessing::addElement<int>(NumberPoints->array, NumberPoints->array_size, i, NumberPoints->array_size);
		}
	}
	if (NumberPoints->array_size == 0)
	{
		throw not_found();
	}
	return NumberPoints;
}

template <typename type_array>
int ALGOR::ARRAYDATA<type_array>::binary_searcher(const type_array &required_element)
{
	int position = 0;
	binary_searcher(required_element, position, 0, this->ARRAY->array_size - 1);
	return position;
}

template <typename type_array>
void ALGOR::ARRAYDATA<type_array>::binary_searcher(const type_array &required_element, int &number_point, int left_limit, int right_limit)
{
	if (left_limit > right_limit)
	{
		throw not_found();
	}
	int middle = left_limit + (right_limit - left_limit) / 2;
	if (this->ARRAY->array[middle] == required_element)
	{
		number_point = middle;
	}
	if (this->ARRAY->array[middle] > required_element)
	{
		binary_searcher(required_element, number_point, left_limit, middle - 1);
	}
	if (this->ARRAY->array[middle] < required_element)
	{
		binary_searcher(required_element, number_point, middle + 1, right_limit);
	}
}

template <typename type_array>
Array<int> *ALGOR::ARRAYDATA<type_array>::searcherOccurrencesOfSubstring(Array<type_array> *&SUBARRAY, ArrayType ArrType)
{
	Array<int> *Occurrences = new Array<int>;
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
						ArrayProcessing::addElement<int>(Occurrences->array, Occurrences->array_size, i, Occurrences->array_size);
					}
					break;
				case ARRAYDATA::ArrayType::STRING:
					if (SUBARRAY->array_size - j == 2)
					{
						ArrayProcessing::addElement<int>(Occurrences->array, Occurrences->array_size, i, Occurrences->array_size);
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
	for (unsigned int i = 0; i < this->ARRAY->array_size; i++)
	{
		average += this->ARRAY->array[i];
	}
	return average / (type_array)this->ARRAY->array_size;
}

template <typename type_array>
type_array ALGOR::ARRAYDATA<type_array>::mediana()
{
	return this->ARRAY->array_size % 2 == 0 ? (this->ARRAY->array[this->ARRAY->array_size / 2] + this->ARRAY->array[(this->ARRAY->array_size / 2) - 1]) / 2 : (this->ARRAY->array[this->ARRAY->array_size / 2]);
}

template <typename type_array>
type_array ALGOR::ARRAYDATA<type_array>::moda(int &highest_frequency)
{
	type_array most_frequent = 0;
	highest_frequency = 0;
	int current_frequency = 0;
	for (unsigned int i = 0; i < this->ARRAY->array_size; i++)
	{
		current_frequency++;
		if (i == this->ARRAY->array_size - 1 || this->ARRAY->array[i] != this->ARRAY->array[i + 1])
		{
			if (current_frequency > highest_frequency)
			{
				highest_frequency = current_frequency;
				most_frequent = this->ARRAY->array[i];
			}
			current_frequency = 0;
		}
	}
	return most_frequent;
}

template <typename type_array>
Array<type_array> *ALGOR::ARRAYDATA<type_array>::modas(int &highest_frequency)
{
	Array<type_array> *MostFrequents = new Array<type_array>;
	highest_frequency = 0;
	int current_frequency = 0;
	type_array most_frequent = moda(highest_frequency);
	ArrayProcessing::addElement<type_array>(MostFrequents->array, MostFrequents->array_size, most_frequent, MostFrequents->array_size);
	for (asize_t i = 0; i < this->ARRAY->array_size; i++)
	{
		if (most_frequent == this->ARRAY->array[i])
		{
			for (asize_t j = i + highest_frequency; j < this->ARRAY->array_size; j++)
			{
				current_frequency++;
				if (j == this->ARRAY->array_size - 1 || this->ARRAY->array[j] != this->ARRAY->array[j + 1])
				{
					if (current_frequency == highest_frequency)
					{
						ArrayProcessing::addElement<type_array>(MostFrequents->array, MostFrequents->array_size, this->ARRAY->array[j], MostFrequents->array_size);
					}
					current_frequency = 0;
				}
			}
			break;
		}
	}
	return MostFrequents;
}

template <typename type_array>
void ALGOR::ARRAYDATA<type_array>::operator&&(const type_array &value)
{
	ArrayProcessing::addElement<type_array>(this->ARRAY->array, this->ARRAY->array_size, value, this->ARRAY->array_size);
}

template <typename type_array>
void ALGOR::ARRAYDATA<type_array>::operator!()
{
	ArrayProcessing::subtractElement<type_array>(this->ARRAY->array, this->ARRAY->array_size, this->ARRAY->array_size - 1);
}

template <typename type_array>
void ALGOR::ARRAYDATA<type_array>::operator||(const type_array &value)
{
	ArrayProcessing::subtractValue<type_array>(this->ARRAY->array, this->ARRAY->array_size, value);
}

template <typename type_array>
void ALGOR::ARRAYDATA<type_array>::operator<<(ARRAYDATA<type_array> *&appendingArray)
{
	asize_t newSize = this->ARRAY->array_size + appendingArray->getData()->array_size;
	Array<type_array> *temp = create_struct<type_array>(newSize);
	for (asize_t i = 0; i < newSize; i++)
	{
		i < this->ARRAY->array_size ? temp->array[i] = this->ARRAY->array[i] : temp->array[i] = appendingArray->getData()->array[i - this->ARRAY->array_size];
	}
	remove();
	this->ARRAY = create_struct<type_array>(newSize);
	ArrayProcessing::copy<type_array>(this->ARRAY->array, temp->array, newSize);
	remove_struct<type_array>(temp);
}

template <typename type_array>
void ALGOR::ARRAYDATA<type_array>::operator>>(ARRAYDATA<type_array> *&appendingArray)
{
	asize_t newSize = this->ARRAY->array_size + appendingArray->getData()->array_size;
	Array<type_array> *temp = create_struct<type_array>(newSize);
	for (asize_t i = 0; i < newSize; i++)
	{
		i < appendingArray->getData()->array_size ? temp->array[i] = appendingArray->getData()->array[i] : temp->array[i] = this->ARRAY->array[i - appendingArray->getData()->array_size];
	}
	appendingArray->resize(newSize, 1);
	ArrayProcessing::copy<type_array>(appendingArray->getData()->array, temp->array, newSize);
	remove_struct<type_array>(temp);
}

// TODO Optimize operators + - * /

template <typename type_array>
void ALGOR::ARRAYDATA<type_array>::operator+(const asize_t &addSize)
{
	if (this->ARRAY->array_size + addSize > 0xffffffff)
	{
		throw memory_overflow();
	}
	Array<type_array> *temp = create_struct<type_array>(this->ARRAY->array_size);
	ArrayProcessing::copy<type_array>(temp->array, this->ARRAY->array, this->ARRAY->array_size);
	resize(temp->array_size + addSize, 1);
	ArrayProcessing::copy<type_array>(this->ARRAY->array, temp->array, temp->array_size);
	remove_struct<type_array>(temp);
}

template <typename type_array>
void ALGOR::ARRAYDATA<type_array>::operator-(const asize_t &subtractSize)
{
	if (subtractSize >= this->ARRAY->array_size)
	{
		remove();
		return;
	}
	Array<type_array> *temp = create_struct<type_array>(this->ARRAY->array_size);
	ArrayProcessing::copy<type_array>(temp->array, this->ARRAY->array, this->ARRAY->array_size);
	resize(temp->array_size - subtractSize, 1);
	ArrayProcessing::copy<type_array>(this->ARRAY->array, temp->array, this->ARRAY->array_size);
	remove_struct<type_array>(temp);
}

template <typename type_array>
void ALGOR::ARRAYDATA<type_array>::operator*(const asize_t &multiplySize)
{
	if (this->ARRAY->array_size * multiplySize > 0xffffffff)
	{
		throw memory_overflow();
	}
	Array<type_array> *temp = create_struct<type_array>(this->ARRAY->array_size);
	ArrayProcessing::copy<type_array>(temp->array, this->ARRAY->array, this->ARRAY->array_size);
	resize(temp->array_size * multiplySize, 1);
	ArrayProcessing::copy<type_array>(this->ARRAY->array, temp->array, temp->array_size);
	remove_struct<type_array>(temp);
}

template <typename type_array>
void ALGOR::ARRAYDATA<type_array>::operator/(const asize_t &divideSize)
{
	if (divideSize >= this->ARRAY->array_size)
	{
		remove();
		return;
	}
	Array<type_array> *temp = create_struct<type_array>(this->ARRAY->array_size);
	ArrayProcessing::copy<type_array>(temp->array, this->ARRAY->array, this->ARRAY->array_size);
	resize(temp->array_size / divideSize, 1);
	ArrayProcessing::copy<type_array>(this->ARRAY->array, temp->array, this->ARRAY->array_size);
	remove_struct<type_array>(temp);
}

template <typename type_array>
void ALGOR::ARRAYDATA<type_array>::remove()
{
	remove_struct<type_array>(this->ARRAY);
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
Comparative_Sorts<type_array>::BitonicSorter::BitonicSorter(type_array *array, asize_t asize) : Array(array), array_size(asize)
{
	array_size_verification(array_size);
}

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
						swap<type_array>(Array[i], Array[l]);
					}
				}
			}
		}
	}
}

template <typename type_array>
ALGOR::Comparative_Sorts<type_array>::BogoSort::BogoSort(type_array *array, asize_t asize) : Array(array), array_size(asize)
{
	array_size_verification(array_size);
}

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
		swap<type_array>(Array[i], Array[RanGen.IRandom(0, array_size - 1)]);
	}
}

template <typename type_array>
ALGOR::Comparative_Sorts<type_array>::BubbleSort::BubbleSort(type_array *array, asize_t asize) : Array(array), array_size(asize)
{
	array_size_verification(array_size);
}

template <typename type_array>
void ALGOR::Comparative_Sorts<type_array>::BubbleSort::bubble_sort()
{
	for (asize_t i = 0; i < array_size; i++)
	{
		for (asize_t j = 0; j < array_size - 1; j++)
		{
			if (Array[j] > Array[j + 1])
			{
				swap<type_array>(Array[j], Array[j + 1]);
			}
		}
	}
}

template <typename type_array>
ALGOR::Comparative_Sorts<type_array>::CocktailShakerSort::CocktailShakerSort(type_array *array, asize_t asize) : Array(array), array_size(asize)
{
	array_size_verification(array_size);
}

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
				swap<type_array>(Array[i], Array[i - 1]);
			}
		}
		leftMark++;
		for (asize_t i = leftMark; i <= rightMark; i++)
		{
			if (Array[i - 1] > Array[i])
			{
				swap<type_array>(Array[i], Array[i - 1]);
			}
		}
		rightMark--;
	}
}

template <typename type_array>
ALGOR::Comparative_Sorts<type_array>::CombSort::CombSort(type_array *array, asize_t asize) : Array(array), array_size(asize)
{
	array_size_verification(array_size);
}

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
				swap<type_array>(Array[i], Array[i + step]);
			}
		}
		step /= factor;
	}
}

template <typename type_array>
ALGOR::Comparative_Sorts<type_array>::CycleSort::CycleSort(type_array *array, asize_t asize) : Array(array), array_size(asize)
{
	array_size_verification(array_size);
}

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
		swap<type_array>(Array[pos], item);

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
			swap<type_array>(Array[pos], item);
		}
	}
}

template <typename type_array>
ALGOR::Comparative_Sorts<type_array>::GnomeSort::GnomeSort(type_array *array, asize_t asize) : Array(array), array_size(asize)
{
	array_size_verification(array_size);
}

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
				swap<type_array>(Array[i], Array[i - 1]);
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
ALGOR::Comparative_Sorts<type_array>::HeapSort::HeapSort(type_array *array, asize_t asize) : Array(array), array_size(asize)
{
	array_size_verification(array_size);
}

template <typename type_array>
void ALGOR::Comparative_Sorts<type_array>::HeapSort::heap_sort()
{
	//Типи int у циклах ЗАЛИШИТИ! Без них не працює!
	array_size_verification(array_size);
	for (int right = array_size / 2 - 1; right >= 0; right--)
	{
		heapify(Array, right, array_size);
	}
	for (int i = array_size - 1; i >= 0; i--)
	{
		swap<type_array>(Array[0], Array[i]);
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
		swap<type_array>(Array[count], Array[large]);
		heapify(Array, large, array_size);
	}
}

template <typename type_array>
ALGOR::Comparative_Sorts<type_array>::InsertSort::InsertSort(type_array *array, asize_t asize) : Array(array), array_size(asize)
{
	array_size_verification(array_size);
}

template <typename type_array>
void ALGOR::Comparative_Sorts<type_array>::InsertSort::insert_sort()
{
	for (asize_t i = 0; i < array_size; i++)
	{
		for (asize_t j = i; j > 0 && Array[j - 1] > Array[j]; j--)
		{
			swap<type_array>(Array[j - 1], Array[j]);
		}
	}
}

template <class type_array>
Comparative_Sorts<type_array>::LibrarySort::LibrarySort(type_array *array, asize_t asize) : Array(array), array_size(asize)
{
	array_size_verification(array_size);
}

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
	//insert = (asize_t)std::distance(library[target_lib], std::lower_bound(library[target_lib], library[target_lib] + lib_size, Array[index_pos]));
	insert = ArrayProcessing::distance(library[target_lib], ArrayProcessing::lower_bound(library[target_lib], library[target_lib] + lib_size, Array[index_pos]));
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
ALGOR::Comparative_Sorts<type_array>::MergeSort::MergeSort(type_array *array, asize_t asize) : Array(array), array_size(asize)
{
	array_size_verification(array_size);
}

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
ALGOR::Comparative_Sorts<type_array>::OddEvenSort::OddEvenSort(type_array *array, asize_t asize) : Array(array), array_size(asize)
{
	array_size_verification(array_size);
}

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
				swap<type_array>(Array[j - 1], Array[j]);
			}
		}
	}
}

template<typename type_array>
Comparative_Sorts<type_array>::PancakeSort::PancakeSort(type_array *array, asize_t asize) : Array(array), array_size(asize)
{
	array_size_verification(array_size);
}

template<typename type_array>
void Comparative_Sorts<type_array>::PancakeSort::pancake_sort()
{
	while (array_size > 1)
	{
		asize_t maxIndex = max_index();
		flip(maxIndex);
		//flip(array_size - 1);
		flip(--array_size);
		//array_size--;
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
		swap<type_array>(Array[left], Array[index]);
		index--;
		left++;
	}
}

template <typename type_array>
ALGOR::Comparative_Sorts<type_array>::PatienceSort::PatienceSort(type_array *array, asize_t asize) : Array(array), array_size(asize)
{
	array_size_verification(array_size);
}

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
ALGOR::Comparative_Sorts<type_array>::QuickSort::QuickSort(type_array *array, asize_t asize) : Array(array), array_size(asize)
{
	array_size_verification(array_size);
}

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
			swap<type_array>(Array[start], Array[finish]);
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
ALGOR::Comparative_Sorts<type_array>::SelectionSort::SelectionSort(type_array *array, asize_t asize) : Array(array), array_size(asize)
{
	array_size_verification(array_size);
}

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
			swap<type_array>(Array[i], Array[min_index]);
		}
	}
}

template <typename type_array>
ALGOR::Comparative_Sorts<type_array>::ShellSort::ShellSort(type_array *array, asize_t asize) : Array(array), array_size(asize)
{
	array_size_verification(array_size);
}

template <typename type_array>
void ALGOR::Comparative_Sorts<type_array>::ShellSort::shell_sort()
{
	for (asize_t step = array_size / 2; step > 0; step /= 2)
	{
		for (asize_t i = step; i < array_size; i++)
		{
			for (int j = (int)i - step; j >= 0 && Array[j] > Array[j + step]; j -= step)
			{
				swap<type_array>(Array[j], Array[j + step]);
			}
		}
	}
}

template <typename type_array>
ALGOR::Comparative_Sorts<type_array>::SlowSort::SlowSort(type_array *array, asize_t asize) : Array(array), array_size(asize)
{
	array_size_verification(array_size);
}

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
		swap<type_array>(Array[middle], Array[right_limit]);
	}
	recursive_slow_sort(left_limit, right_limit - 1);
}

template <typename type_array>
ALGOR::Comparative_Sorts<type_array>::StoogeSort::StoogeSort(type_array *array, asize_t asize) : Array(array), array_size(asize)
{
	array_size_verification(array_size);
}

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
		swap<type_array>(Array[left_limit], Array[right_limit]);
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
Comparative_Sorts<type_array>::TimSort::TimSort(type_array *array, asize_t asize) : Array(array), array_size(asize)
{
	array_size_verification(array_size);
}

template<typename type_array>
void Comparative_Sorts<type_array>::TimSort::tim_sort()
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
ALGOR::Comparative_Sorts<type_array>::TreeSort::TreeSort(type_array *array, asize_t asize) : Array(array), array_size(asize)
{
	array_size_verification(array_size);
}

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
ALGOR::Comparative_Sorts<type_array>::SmoothSort::SmoothSort(type_array *array, int asize) : Array(array), array_size(asize)
{
	array_size_verification(array_size);
}

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
			swap<type_array>(Array[i], Array[posMaxTopElem]);
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

Distribution_Sorts::AmericanFlagSort::AmericanFlagSort(int *array, asize_t asize) : Array(array), array_size(asize)
{
	array_size_verification(array_size);
}

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
	int value = ArrayProcessing::maximum<int>(Array, array_size);
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

Distribution_Sorts::BeadSort::BeadSort(int *array, asize_t asize) : Array(array), array_size(asize)
{
	array_size_verification(array_size);
}

void Distribution_Sorts::BeadSort::bead_sort()
{
	max = ArrayProcessing::maximum<int>(Array, array_size);
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

Distribution_Sorts::BucketSort::BucketSort(int *array, asize_t asize) : Array(array), array_size(asize)
{
	array_size_verification(array_size);
}

void Distribution_Sorts::BucketSort::bucket_sort()
{
	min = ArrayProcessing::minimum<int>(Array, array_size);
	max = ArrayProcessing::maximum<int>(Array, array_size);
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
				swap<int>(bucket[j], bucket[j + 1]);
			}
		}
	}
}

Distribution_Sorts::CountingSort::CountingSort(int *array, asize_t asize) : Array(array), array_size(asize)
{
	array_size_verification(array_size);
}

void Distribution_Sorts::CountingSort::counting_sort()
{
	min = ArrayProcessing::minimum<int>(Array, array_size);
	max = ArrayProcessing::maximum<int>(Array, array_size);
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

Distribution_Sorts::FlashSort::FlashSort(int *array, asize_t asize) : Array(array), array_size(asize)
{
	array_size_verification(array_size);
}

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
			swap<int>(Array[0], Array[1]);
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

	swap<int>(Array[max], Array[0]);

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
			swap<int>(Array[L[k] - 1], flash);
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

Distribution_Sorts::InterpolationSort::InterpolationSort(int *array, asize_t asize) : Array(array), array_size(asize)
{
	array_size_verification(array_size);
}

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

		ArrayProcessing::copy<int>(Array, sorted, array_size);

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

Distribution_Sorts::PigeonholeSort::PigeonholeSort(int *array, asize_t asize) : Array(array), array_size(asize)
{
	array_size_verification(array_size);
}

void Distribution_Sorts::PigeonholeSort::pigeonhole_sort()
{
	min = ArrayProcessing::minimum<int>(Array, array_size);
	max = ArrayProcessing::maximum<int>(Array, array_size);
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

Distribution_Sorts::RadixSort::RadixSort(int *array, asize_t asize) : Array(array), array_size(asize)
{
	array_size_verification(array_size);
}

void Distribution_Sorts::RadixSort::radix_sort()
{
	max = ArrayProcessing::maximum<int>(Array, array_size);
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

template void ALGOR::swap<int>(int &, int &);
template void ALGOR::swap<float>(float &, float &);
template void ALGOR::swap<char>(char &, char &);

template int ALGOR::minimum<int>(int, int);
template float ALGOR::minimum<float>(float, float);
template char ALGOR::minimum<char>(char, char);

template int ALGOR::maximum<int>(int, int);
template float ALGOR::maximum<float>(float, float);
template char ALGOR::maximum<char>(char, char);

template int ALGOR::ArrayProcessing::minimum<int>(const int *, const asize_t &);
template float ALGOR::ArrayProcessing::minimum<float>(const float *, const asize_t &);
template char ALGOR::ArrayProcessing::minimum<char>(const char *, const asize_t &);

template int ALGOR::ArrayProcessing::maximum<int>(const int *, const asize_t &);
template float ALGOR::ArrayProcessing::maximum<float>(const float *, const asize_t &);
template char ALGOR::ArrayProcessing::maximum<char>(const char *, const asize_t &);

template bool ALGOR::ArrayProcessing::isOrderliness<int>(const int *, const asize_t &);
template bool ALGOR::ArrayProcessing::isOrderliness<float>(const float *, const asize_t &);
template bool ALGOR::ArrayProcessing::isOrderliness<char>(const char *, const asize_t &);

template asize_t ALGOR::ArrayProcessing::distance<int>(int *, int *);
template asize_t ALGOR::ArrayProcessing::distance<float>(float *, float *);
template asize_t ALGOR::ArrayProcessing::distance<char>(char *, char *);

template int *ALGOR::ArrayProcessing::lower_bound<int>(int *, int *, const int &);
template float *ALGOR::ArrayProcessing::lower_bound<float>(float *, float *, const float &);
template char *ALGOR::ArrayProcessing::lower_bound<char>(char *, char *, const char &);

template int *ALGOR::ArrayProcessing::upper_bound<int>(int *, int *, const int &);
template float *ALGOR::ArrayProcessing::upper_bound<float>(float *, float *, const float &);
template char *ALGOR::ArrayProcessing::upper_bound<char>(char *, char *, const char &);

template void ALGOR::ArrayProcessing::addElement<int>(int *&, asize_t &, const int &, const unsigned int);
template void ALGOR::ArrayProcessing::addElement<float>(float *&, asize_t &, const float &, const unsigned int);
template void ALGOR::ArrayProcessing::addElement<char>(char *&, asize_t &, const char &, const unsigned int);

template void ALGOR::ArrayProcessing::subtractElement<int>(int *&, asize_t &, const unsigned int);
template void ALGOR::ArrayProcessing::subtractElement<float>(float *&, asize_t &, const unsigned int);
template void ALGOR::ArrayProcessing::subtractElement<char>(char *&, asize_t &, const unsigned int);

template void ALGOR::ArrayProcessing::subtractValue<int>(int *&, asize_t &, const int &);
template void ALGOR::ArrayProcessing::subtractValue<float>(float *&, asize_t &, const float &);
template void ALGOR::ArrayProcessing::subtractValue<char>(char *&, asize_t &, const char &);

template void ALGOR::ArrayProcessing::copy<int>(int *, const int *, const unsigned int &, unsigned int, unsigned int);
template void ALGOR::ArrayProcessing::copy<float>(float *, const float *, const unsigned int &, unsigned int, unsigned int);
template void ALGOR::ArrayProcessing::copy<char>(char *, const char *, const unsigned int &, unsigned int, unsigned int);

template Array<int> *ALGOR::create_struct<int>(const asize_t &);
template Array<float> *ALGOR::create_struct<float>(const asize_t &);
template Array<char> *ALGOR::create_struct<char>(const asize_t &);

template void ALGOR::remove_struct<int>(Array<int> *&);
template void ALGOR::remove_struct<float>(Array<float> *&);
template void ALGOR::remove_struct<char>(Array<char> *&);

template ALGOR::ArrayBase<int>::ArrayBase(Array<int> *&);
template ALGOR::ArrayBase<float>::ArrayBase(Array<float> *&);
template ALGOR::ArrayBase<char>::ArrayBase(Array<char> *&);

template ALGOR::ArrayBase<int>::ArrayBase(const asize_t &);
template ALGOR::ArrayBase<float>::ArrayBase(const asize_t &);
template ALGOR::ArrayBase<char>::ArrayBase(const asize_t &);

template ALGOR::ArrayBase<int>::ArrayBase();
template ALGOR::ArrayBase<float>::ArrayBase();
template ALGOR::ArrayBase<char>::ArrayBase();

template ALGOR::ARRAYDATA<int>::ARRAYDATA(Array<int> *&);
template ALGOR::ARRAYDATA<float>::ARRAYDATA(Array<float> *&);
template ALGOR::ARRAYDATA<char>::ARRAYDATA(Array<char> *&);

template ALGOR::ARRAYDATA<int>::ARRAYDATA(const asize_t &);
template ALGOR::ARRAYDATA<float>::ARRAYDATA(const asize_t &);
template ALGOR::ARRAYDATA<char>::ARRAYDATA(const asize_t &);

template ALGOR::ARRAYDATA<int>::~ARRAYDATA();
template ALGOR::ARRAYDATA<float>::~ARRAYDATA();
template ALGOR::ARRAYDATA<char>::~ARRAYDATA();

template void ALGOR::ARRAYDATA<int>::generatedData(const int &, const int &);
template void ALGOR::ARRAYDATA<float>::generatedData(const int &, const int &);
template void ALGOR::ARRAYDATA<char>::generatedData(const int &, const int &);

template void ALGOR::ARRAYDATA<int>::setNewData(Array<int> *&);
template void ALGOR::ARRAYDATA<float>::setNewData(Array<float> *&);
template void ALGOR::ARRAYDATA<char>::setNewData(Array<char> *&);

template void ALGOR::ARRAYDATA<int>::setData(Array<int> *&);
template void ALGOR::ARRAYDATA<float>::setData(Array<float> *&);
template void ALGOR::ARRAYDATA<char>::setData(Array<char> *&);

template void ALGOR::ARRAYDATA<int>::cloneData(Array<int> *&);
template void ALGOR::ARRAYDATA<float>::cloneData(Array<float> *&);
template void ALGOR::ARRAYDATA<char>::cloneData(Array<char> *&);

template void ALGOR::ARRAYDATA<int>::cloneData(ARRAYDATA<int> *&);
template void ALGOR::ARRAYDATA<float>::cloneData(ARRAYDATA<float> *&);
template void ALGOR::ARRAYDATA<char>::cloneData(ARRAYDATA<char> *&);

template void ALGOR::ARRAYDATA<int>::getData(Array<int> *&);
template void ALGOR::ARRAYDATA<float>::getData(Array<float> *&);
template void ALGOR::ARRAYDATA<char>::getData(Array<char> *&);

template Array<int> *ALGOR::ARRAYDATA<int>::getData();
template Array<float> *ALGOR::ARRAYDATA<float>::getData();
template Array<char> *ALGOR::ARRAYDATA<char>::getData();

template void ALGOR::ARRAYDATA<int>::reset();
template void ALGOR::ARRAYDATA<float>::reset();
template void ALGOR::ARRAYDATA<char>::reset();

template void ALGOR::ARRAYDATA<int>::resize(const asize_t &, const int &);
template void ALGOR::ARRAYDATA<float>::resize(const asize_t &, const float &);
template void ALGOR::ARRAYDATA<char>::resize(const asize_t &, const char &);

template void ALGOR::ARRAYDATA<int>::replace(const unsigned int &, const int &);
template void ALGOR::ARRAYDATA<float>::replace(const unsigned int &, const float &);
template void ALGOR::ARRAYDATA<char>::replace(const unsigned int &, const char &);

template void ALGOR::ARRAYDATA<int>::reverse();
template void ALGOR::ARRAYDATA<float>::reverse();
template void ALGOR::ARRAYDATA<char>::reverse();

template void ALGOR::ARRAYDATA<int>::respawn();
template void ALGOR::ARRAYDATA<float>::respawn();
template void ALGOR::ARRAYDATA<char>::respawn();

template int ALGOR::ARRAYDATA<int>::getMin();
template float ALGOR::ARRAYDATA<float>::getMin();
template char ALGOR::ARRAYDATA<char>::getMin();

template int ALGOR::ARRAYDATA<int>::getMax();
template float ALGOR::ARRAYDATA<float>::getMax();
template char ALGOR::ARRAYDATA<char>::getMax();

template Array<int> *ALGOR::ARRAYDATA<int>::lenear_searcher(const int &);
template Array<int> *ALGOR::ARRAYDATA<float>::lenear_searcher(const float &);
template Array<int> *ALGOR::ARRAYDATA<char>::lenear_searcher(const char &);

template int ALGOR::ARRAYDATA<int>::binary_searcher(const int &);
template int ALGOR::ARRAYDATA<float>::binary_searcher(const float &);
template int ALGOR::ARRAYDATA<char>::binary_searcher(const char &);

template void ALGOR::ARRAYDATA<int>::binary_searcher(const int &, int &, int, int);
template void ALGOR::ARRAYDATA<float>::binary_searcher(const float &, int &, int, int);
template void ALGOR::ARRAYDATA<char>::binary_searcher(const char &, int &, int, int);

template Array<int> *ALGOR::ARRAYDATA<int>::searcherOccurrencesOfSubstring(Array<int> *&, ArrayType);
template Array<int> *ALGOR::ARRAYDATA<float>::searcherOccurrencesOfSubstring(Array<float> *&, ArrayType);
template Array<int> *ALGOR::ARRAYDATA<char>::searcherOccurrencesOfSubstring(Array<char> *&, ArrayType);

template int ALGOR::ARRAYDATA<int>::average();
template float ALGOR::ARRAYDATA<float>::average();
template char ALGOR::ARRAYDATA<char>::average();

template int ALGOR::ARRAYDATA<int>::mediana();
template float ALGOR::ARRAYDATA<float>::mediana();
template char ALGOR::ARRAYDATA<char>::mediana();

template int ALGOR::ARRAYDATA<int>::moda(int &);
template float ALGOR::ARRAYDATA<float>::moda(int &);
template char ALGOR::ARRAYDATA<char>::moda(int &);

template Array<int> *ALGOR::ARRAYDATA<int>::modas(int &);
template Array<float> *ALGOR::ARRAYDATA<float>::modas(int &);
template Array<char> *ALGOR::ARRAYDATA<char>::modas(int &);

template void ALGOR::ARRAYDATA<int>::operator&&(const int &);
template void ALGOR::ARRAYDATA<float>::operator&&(const float &);
template void ALGOR::ARRAYDATA<char>::operator&&(const char &);

template void ALGOR::ARRAYDATA<int>::operator!();
template void ALGOR::ARRAYDATA<float>::operator!();
template void ALGOR::ARRAYDATA<char>::operator!();

template void ALGOR::ARRAYDATA<int>::operator||(const int &);
template void ALGOR::ARRAYDATA<float>::operator||(const float &);
template void ALGOR::ARRAYDATA<char>::operator||(const char &);

template void ALGOR::ARRAYDATA<int>::operator<<(ARRAYDATA<int> *&);
template void ALGOR::ARRAYDATA<float>::operator<<(ARRAYDATA<float> *&);
template void ALGOR::ARRAYDATA<char>::operator<<(ARRAYDATA<char> *&);

template void ALGOR::ARRAYDATA<int>::operator>>(ARRAYDATA<int> *&);
template void ALGOR::ARRAYDATA<float>::operator>>(ARRAYDATA<float> *&);
template void ALGOR::ARRAYDATA<char>::operator>>(ARRAYDATA<char> *&);

template void ALGOR::ARRAYDATA<int>::operator+(const asize_t &);
template void ALGOR::ARRAYDATA<float>::operator+(const asize_t &);
template void ALGOR::ARRAYDATA<char>::operator+(const asize_t &);

template void ALGOR::ARRAYDATA<int>::operator-(const asize_t &);
template void ALGOR::ARRAYDATA<float>::operator-(const asize_t &);
template void ALGOR::ARRAYDATA<char>::operator-(const asize_t &);

template void ALGOR::ARRAYDATA<int>::operator*(const asize_t &);
template void ALGOR::ARRAYDATA<float>::operator*(const asize_t &);
template void ALGOR::ARRAYDATA<char>::operator*(const asize_t &);

template void ALGOR::ARRAYDATA<int>::operator/(const asize_t &);
template void ALGOR::ARRAYDATA<float>::operator/(const asize_t &);
template void ALGOR::ARRAYDATA<char>::operator/(const asize_t &);

template void ALGOR::ARRAYDATA<int>::remove();
template void ALGOR::ARRAYDATA<float>::remove();
template void ALGOR::ARRAYDATA<char>::remove();

template ALGOR::Comparative_Sorts<int>::Comparative_Sorts(Array<int> *&);
template ALGOR::Comparative_Sorts<float>::Comparative_Sorts(Array<float> *&);
template ALGOR::Comparative_Sorts<char>::Comparative_Sorts(Array<char> *&);

template void ALGOR::Comparative_Sorts<int>::Bubble_Sort();
template void ALGOR::Comparative_Sorts<float>::Bubble_Sort();
template void ALGOR::Comparative_Sorts<char>::Bubble_Sort();

template void ALGOR::Comparative_Sorts<int>::Cocktail_Shaker_Sort();
template void ALGOR::Comparative_Sorts<float>::Cocktail_Shaker_Sort();
template void ALGOR::Comparative_Sorts<char>::Cocktail_Shaker_Sort();

template void ALGOR::Comparative_Sorts<int>::Odd_Even_Sort();
template void ALGOR::Comparative_Sorts<float>::Odd_Even_Sort();
template void ALGOR::Comparative_Sorts<char>::Odd_Even_Sort();

template void ALGOR::Comparative_Sorts<int>::Comb_Sort();
template void ALGOR::Comparative_Sorts<float>::Comb_Sort();
template void ALGOR::Comparative_Sorts<char>::Comb_Sort();

template void ALGOR::Comparative_Sorts<int>::Gnome_Sort();
template void ALGOR::Comparative_Sorts<float>::Gnome_Sort();
template void ALGOR::Comparative_Sorts<char>::Gnome_Sort();

template void ALGOR::Comparative_Sorts<int>::Quick_Sort();
template void ALGOR::Comparative_Sorts<float>::Quick_Sort();
template void ALGOR::Comparative_Sorts<char>::Quick_Sort();

template void ALGOR::Comparative_Sorts<int>::Slow_Sort();
template void ALGOR::Comparative_Sorts<float>::Slow_Sort();
template void ALGOR::Comparative_Sorts<char>::Slow_Sort();

template void ALGOR::Comparative_Sorts<int>::Stooge_Sort();
template void ALGOR::Comparative_Sorts<float>::Stooge_Sort();
template void ALGOR::Comparative_Sorts<char>::Stooge_Sort();

template void ALGOR::Comparative_Sorts<int>::Bogo_Sort();
template void ALGOR::Comparative_Sorts<float>::Bogo_Sort();
template void ALGOR::Comparative_Sorts<char>::Bogo_Sort();

template void ALGOR::Comparative_Sorts<int>::Selection_Sort();
template void ALGOR::Comparative_Sorts<float>::Selection_Sort();
template void ALGOR::Comparative_Sorts<char>::Selection_Sort();

template void ALGOR::Comparative_Sorts<int>::Heap_Sort();
template void ALGOR::Comparative_Sorts<float>::Heap_Sort();
template void ALGOR::Comparative_Sorts<char>::Heap_Sort();

template void ALGOR::Comparative_Sorts<int>::Smooth_Sort();
template void ALGOR::Comparative_Sorts<float>::Smooth_Sort();
template void ALGOR::Comparative_Sorts<char>::Smooth_Sort();

template void ALGOR::Comparative_Sorts<int>::Cycle_Sort();
template void ALGOR::Comparative_Sorts<float>::Cycle_Sort();
template void ALGOR::Comparative_Sorts<char>::Cycle_Sort();

template void ALGOR::Comparative_Sorts<int>::Insert_Sort();
template void ALGOR::Comparative_Sorts<float>::Insert_Sort();
template void ALGOR::Comparative_Sorts<char>::Insert_Sort();

template void ALGOR::Comparative_Sorts<int>::Shell_Sort();
template void ALGOR::Comparative_Sorts<float>::Shell_Sort();
template void ALGOR::Comparative_Sorts<char>::Shell_Sort();

template void ALGOR::Comparative_Sorts<int>::Tree_Sort();
template void ALGOR::Comparative_Sorts<float>::Tree_Sort();
template void ALGOR::Comparative_Sorts<char>::Tree_Sort();

template void ALGOR::Comparative_Sorts<int>::Library_Sort();
template void ALGOR::Comparative_Sorts<float>::Library_Sort();
template void ALGOR::Comparative_Sorts<char>::Library_Sort();

template void ALGOR::Comparative_Sorts<int>::Patience_Sort();
template void ALGOR::Comparative_Sorts<float>::Patience_Sort();
template void ALGOR::Comparative_Sorts<char>::Patience_Sort();

template void ALGOR::Comparative_Sorts<int>::Merge_Sort();
template void ALGOR::Comparative_Sorts<float>::Merge_Sort();
template void ALGOR::Comparative_Sorts<char>::Merge_Sort();

template void ALGOR::Comparative_Sorts<int>::Bitonic_Sorter();
template void ALGOR::Comparative_Sorts<float>::Bitonic_Sorter();
template void ALGOR::Comparative_Sorts<char>::Bitonic_Sorter();

template void ALGOR::Comparative_Sorts<int>::Tim_Sort();
template void ALGOR::Comparative_Sorts<float>::Tim_Sort();
template void ALGOR::Comparative_Sorts<char>::Tim_Sort();

template void ALGOR::Comparative_Sorts<int>::Pancake_Sort();
template void ALGOR::Comparative_Sorts<float>::Pancake_Sort();
template void ALGOR::Comparative_Sorts<char>::Pancake_Sort();

template ALGOR::Comparative_Sorts<int>::BitonicSorter::BitonicSorter(int *, asize_t);
template ALGOR::Comparative_Sorts<float>::BitonicSorter::BitonicSorter(float *, asize_t);
template ALGOR::Comparative_Sorts<char>::BitonicSorter::BitonicSorter(char *, asize_t);

template void ALGOR::Comparative_Sorts<int>::BitonicSorter::bitonic_sorter();
template void ALGOR::Comparative_Sorts<float>::BitonicSorter::bitonic_sorter();
template void ALGOR::Comparative_Sorts<char>::BitonicSorter::bitonic_sorter();

template ALGOR::Comparative_Sorts<int>::BogoSort::BogoSort(int *, asize_t);
template ALGOR::Comparative_Sorts<float>::BogoSort::BogoSort(float *, asize_t);
template ALGOR::Comparative_Sorts<char>::BogoSort::BogoSort(char *, asize_t);

template void ALGOR::Comparative_Sorts<int>::BogoSort::bogo_sort();
template void ALGOR::Comparative_Sorts<float>::BogoSort::bogo_sort();
template void ALGOR::Comparative_Sorts<char>::BogoSort::bogo_sort();

template bool ALGOR::Comparative_Sorts<int>::BogoSort::Correct();
template bool ALGOR::Comparative_Sorts<float>::BogoSort::Correct();
template bool ALGOR::Comparative_Sorts<char>::BogoSort::Correct();

template void ALGOR::Comparative_Sorts<int>::BogoSort::Shuffle();
template void ALGOR::Comparative_Sorts<float>::BogoSort::Shuffle();
template void ALGOR::Comparative_Sorts<char>::BogoSort::Shuffle();

template ALGOR::Comparative_Sorts<int>::BubbleSort::BubbleSort(int *, asize_t);
template ALGOR::Comparative_Sorts<float>::BubbleSort::BubbleSort(float *, asize_t);
template ALGOR::Comparative_Sorts<char>::BubbleSort::BubbleSort(char *, asize_t);

template void ALGOR::Comparative_Sorts<int>::BubbleSort::bubble_sort();
template void ALGOR::Comparative_Sorts<float>::BubbleSort::bubble_sort();
template void ALGOR::Comparative_Sorts<char>::BubbleSort::bubble_sort();

template ALGOR::Comparative_Sorts<int>::CocktailShakerSort::CocktailShakerSort(int *, asize_t);
template ALGOR::Comparative_Sorts<float>::CocktailShakerSort::CocktailShakerSort(float *, asize_t);
template ALGOR::Comparative_Sorts<char>::CocktailShakerSort::CocktailShakerSort(char *, asize_t);

template void ALGOR::Comparative_Sorts<int>::CocktailShakerSort::cocktail_shaker_sort();
template void ALGOR::Comparative_Sorts<float>::CocktailShakerSort::cocktail_shaker_sort();
template void ALGOR::Comparative_Sorts<char>::CocktailShakerSort::cocktail_shaker_sort();

template ALGOR::Comparative_Sorts<int>::CombSort::CombSort(int *, asize_t);
template ALGOR::Comparative_Sorts<float>::CombSort::CombSort(float *, asize_t);
template ALGOR::Comparative_Sorts<char>::CombSort::CombSort(char *, asize_t);

template void ALGOR::Comparative_Sorts<int>::CombSort::comb_sort();
template void ALGOR::Comparative_Sorts<float>::CombSort::comb_sort();
template void ALGOR::Comparative_Sorts<char>::CombSort::comb_sort();

template ALGOR::Comparative_Sorts<int>::CycleSort::CycleSort(int *, asize_t);
template ALGOR::Comparative_Sorts<float>::CycleSort::CycleSort(float *, asize_t);
template ALGOR::Comparative_Sorts<char>::CycleSort::CycleSort(char *, asize_t);

template void ALGOR::Comparative_Sorts<int>::CycleSort::cycle_sort();
template void ALGOR::Comparative_Sorts<float>::CycleSort::cycle_sort();
template void ALGOR::Comparative_Sorts<char>::CycleSort::cycle_sort();

template ALGOR::Comparative_Sorts<int>::GnomeSort::GnomeSort(int *, asize_t);
template ALGOR::Comparative_Sorts<float>::GnomeSort::GnomeSort(float *, asize_t);
template ALGOR::Comparative_Sorts<char>::GnomeSort::GnomeSort(char *, asize_t);

template void ALGOR::Comparative_Sorts<int>::GnomeSort::gnome_sort();
template void ALGOR::Comparative_Sorts<float>::GnomeSort::gnome_sort();
template void ALGOR::Comparative_Sorts<char>::GnomeSort::gnome_sort();

template ALGOR::Comparative_Sorts<int>::HeapSort::HeapSort(int *, asize_t);
template ALGOR::Comparative_Sorts<float>::HeapSort::HeapSort(float *, asize_t);
template ALGOR::Comparative_Sorts<char>::HeapSort::HeapSort(char *, asize_t);

template void ALGOR::Comparative_Sorts<int>::HeapSort::heap_sort();
template void ALGOR::Comparative_Sorts<float>::HeapSort::heap_sort();
template void ALGOR::Comparative_Sorts<char>::HeapSort::heap_sort();

template void ALGOR::Comparative_Sorts<int>::HeapSort::heapify(int *, const asize_t &, const asize_t &);
template void ALGOR::Comparative_Sorts<float>::HeapSort::heapify(float *, const asize_t &, const asize_t &);
template void ALGOR::Comparative_Sorts<char>::HeapSort::heapify(char *, const asize_t &, const asize_t &);

template ALGOR::Comparative_Sorts<int>::InsertSort::InsertSort(int *, asize_t);
template ALGOR::Comparative_Sorts<float>::InsertSort::InsertSort(float *, asize_t);
template ALGOR::Comparative_Sorts<char>::InsertSort::InsertSort(char *, asize_t);

template void ALGOR::Comparative_Sorts<int>::InsertSort::insert_sort();
template void ALGOR::Comparative_Sorts<float>::InsertSort::insert_sort();
template void ALGOR::Comparative_Sorts<char>::InsertSort::insert_sort();

template ALGOR::Comparative_Sorts<int>::LibrarySort::LibrarySort(int *, asize_t);
template ALGOR::Comparative_Sorts<float>::LibrarySort::LibrarySort(float *, asize_t);
template ALGOR::Comparative_Sorts<char>::LibrarySort::LibrarySort(char *, asize_t);

template void ALGOR::Comparative_Sorts<int>::LibrarySort::library_sort();
template void ALGOR::Comparative_Sorts<float>::LibrarySort::library_sort();
template void ALGOR::Comparative_Sorts<char>::LibrarySort::library_sort();

template void ALGOR::Comparative_Sorts<int>::LibrarySort::initialization();
template void ALGOR::Comparative_Sorts<float>::LibrarySort::initialization();
template void ALGOR::Comparative_Sorts<char>::LibrarySort::initialization();

template void ALGOR::Comparative_Sorts<int>::LibrarySort::binarysearch();
template void ALGOR::Comparative_Sorts<float>::LibrarySort::binarysearch();
template void ALGOR::Comparative_Sorts<char>::LibrarySort::binarysearch();

template void ALGOR::Comparative_Sorts<int>::LibrarySort::insertion();
template void ALGOR::Comparative_Sorts<float>::LibrarySort::insertion();
template void ALGOR::Comparative_Sorts<char>::LibrarySort::insertion();

template void ALGOR::Comparative_Sorts<int>::LibrarySort::rebalancing();
template void ALGOR::Comparative_Sorts<float>::LibrarySort::rebalancing();
template void ALGOR::Comparative_Sorts<char>::LibrarySort::rebalancing();

template void ALGOR::Comparative_Sorts<int>::LibrarySort::finalization();
template void ALGOR::Comparative_Sorts<float>::LibrarySort::finalization();
template void ALGOR::Comparative_Sorts<char>::LibrarySort::finalization();

template ALGOR::Comparative_Sorts<int>::MergeSort::MergeSort(int *, asize_t);
template ALGOR::Comparative_Sorts<float>::MergeSort::MergeSort(float *, asize_t);
template ALGOR::Comparative_Sorts<char>::MergeSort::MergeSort(char *, asize_t);

template void ALGOR::Comparative_Sorts<int>::MergeSort::merge_sort();
template void ALGOR::Comparative_Sorts<float>::MergeSort::merge_sort();
template void ALGOR::Comparative_Sorts<char>::MergeSort::merge_sort();

template void ALGOR::Comparative_Sorts<int>::MergeSort::recursive_merge_sort(const asize_t &, const asize_t &);
template void ALGOR::Comparative_Sorts<float>::MergeSort::recursive_merge_sort(const asize_t &, const asize_t &);
template void ALGOR::Comparative_Sorts<char>::MergeSort::recursive_merge_sort(const asize_t &, const asize_t &);

template void ALGOR::Comparative_Sorts<int>::MergeSort::merge(const asize_t &, const asize_t &, const asize_t &);
template void ALGOR::Comparative_Sorts<float>::MergeSort::merge(const asize_t &, const asize_t &, const asize_t &);
template void ALGOR::Comparative_Sorts<char>::MergeSort::merge(const asize_t &, const asize_t &, const asize_t &);

template ALGOR::Comparative_Sorts<int>::OddEvenSort::OddEvenSort(int *, asize_t);
template ALGOR::Comparative_Sorts<float>::OddEvenSort::OddEvenSort(float *, asize_t);
template ALGOR::Comparative_Sorts<char>::OddEvenSort::OddEvenSort(char *, asize_t);

template void ALGOR::Comparative_Sorts<int>::OddEvenSort::odd_even_sort();
template void ALGOR::Comparative_Sorts<float>::OddEvenSort::odd_even_sort();
template void ALGOR::Comparative_Sorts<char>::OddEvenSort::odd_even_sort();

template ALGOR::Comparative_Sorts<int>::PancakeSort::PancakeSort(int *, asize_t);
template ALGOR::Comparative_Sorts<float>::PancakeSort::PancakeSort(float *, asize_t);
template ALGOR::Comparative_Sorts<char>::PancakeSort::PancakeSort(char *, asize_t);

template void ALGOR::Comparative_Sorts<int>::PancakeSort::pancake_sort();
template void ALGOR::Comparative_Sorts<float>::PancakeSort::pancake_sort();
template void ALGOR::Comparative_Sorts<char>::PancakeSort::pancake_sort();

template asize_t ALGOR::Comparative_Sorts<int>::PancakeSort::max_index();
template asize_t ALGOR::Comparative_Sorts<float>::PancakeSort::max_index();
template asize_t ALGOR::Comparative_Sorts<char>::PancakeSort::max_index();

template void ALGOR::Comparative_Sorts<int>::PancakeSort::flip(asize_t);
template void ALGOR::Comparative_Sorts<float>::PancakeSort::flip(asize_t);
template void ALGOR::Comparative_Sorts<char>::PancakeSort::flip(asize_t);

template ALGOR::Comparative_Sorts<int>::PatienceSort::PatienceSort(int *, asize_t);
template ALGOR::Comparative_Sorts<float>::PatienceSort::PatienceSort(float *, asize_t);
template ALGOR::Comparative_Sorts<char>::PatienceSort::PatienceSort(char *, asize_t);

template void ALGOR::Comparative_Sorts<int>::PatienceSort::patience_sort();
template void ALGOR::Comparative_Sorts<float>::PatienceSort::patience_sort();
template void ALGOR::Comparative_Sorts<char>::PatienceSort::patience_sort();

template void ALGOR::Comparative_Sorts<int>::PatienceSort::initialization();
template void ALGOR::Comparative_Sorts<float>::PatienceSort::initialization();
template void ALGOR::Comparative_Sorts<char>::PatienceSort::initialization();

template void ALGOR::Comparative_Sorts<int>::PatienceSort::finalization();
template void ALGOR::Comparative_Sorts<float>::PatienceSort::finalization();
template void ALGOR::Comparative_Sorts<char>::PatienceSort::finalization();

template ALGOR::Comparative_Sorts<int>::QuickSort::QuickSort(int *, asize_t);
template ALGOR::Comparative_Sorts<float>::QuickSort::QuickSort(float *, asize_t);
template ALGOR::Comparative_Sorts<char>::QuickSort::QuickSort(char *, asize_t);

template void ALGOR::Comparative_Sorts<int>::QuickSort::quick_sort();
template void ALGOR::Comparative_Sorts<float>::QuickSort::quick_sort();
template void ALGOR::Comparative_Sorts<char>::QuickSort::quick_sort();

template void ALGOR::Comparative_Sorts<int>::QuickSort::recursive_quick_sort(const int &, const int &);
template void ALGOR::Comparative_Sorts<float>::QuickSort::recursive_quick_sort(const int &, const int &);
template void ALGOR::Comparative_Sorts<char>::QuickSort::recursive_quick_sort(const int &, const int &);

template ALGOR::Comparative_Sorts<int>::SelectionSort::SelectionSort(int *, asize_t);
template ALGOR::Comparative_Sorts<float>::SelectionSort::SelectionSort(float *, asize_t);
template ALGOR::Comparative_Sorts<char>::SelectionSort::SelectionSort(char *, asize_t);

template void ALGOR::Comparative_Sorts<int>::SelectionSort::selection_sort();
template void ALGOR::Comparative_Sorts<float>::SelectionSort::selection_sort();
template void ALGOR::Comparative_Sorts<char>::SelectionSort::selection_sort();

template ALGOR::Comparative_Sorts<int>::ShellSort::ShellSort(int *, asize_t);
template ALGOR::Comparative_Sorts<float>::ShellSort::ShellSort(float *, asize_t);
template ALGOR::Comparative_Sorts<char>::ShellSort::ShellSort(char *, asize_t);

template void ALGOR::Comparative_Sorts<int>::ShellSort::shell_sort();
template void ALGOR::Comparative_Sorts<float>::ShellSort::shell_sort();
template void ALGOR::Comparative_Sorts<char>::ShellSort::shell_sort();

template ALGOR::Comparative_Sorts<int>::SlowSort::SlowSort(int *, asize_t);
template ALGOR::Comparative_Sorts<float>::SlowSort::SlowSort(float *, asize_t);
template ALGOR::Comparative_Sorts<char>::SlowSort::SlowSort(char *, asize_t);

template void ALGOR::Comparative_Sorts<int>::SlowSort::slow_sort();
template void ALGOR::Comparative_Sorts<float>::SlowSort::slow_sort();
template void ALGOR::Comparative_Sorts<char>::SlowSort::slow_sort();

template void ALGOR::Comparative_Sorts<int>::SlowSort::recursive_slow_sort(const int &, const int &);
template void ALGOR::Comparative_Sorts<float>::SlowSort::recursive_slow_sort(const int &, const int &);
template void ALGOR::Comparative_Sorts<char>::SlowSort::recursive_slow_sort(const int &, const int &);

template ALGOR::Comparative_Sorts<int>::StoogeSort::StoogeSort(int *, asize_t);
template ALGOR::Comparative_Sorts<float>::StoogeSort::StoogeSort(float *, asize_t);
template ALGOR::Comparative_Sorts<char>::StoogeSort::StoogeSort(char *, asize_t);

template void ALGOR::Comparative_Sorts<int>::StoogeSort::stooge_sort();
template void ALGOR::Comparative_Sorts<float>::StoogeSort::stooge_sort();
template void ALGOR::Comparative_Sorts<char>::StoogeSort::stooge_sort();

template void ALGOR::Comparative_Sorts<int>::StoogeSort::recursive_stooge_sort(const int &, const int &);
template void ALGOR::Comparative_Sorts<float>::StoogeSort::recursive_stooge_sort(const int &, const int &);
template void ALGOR::Comparative_Sorts<char>::StoogeSort::recursive_stooge_sort(const int &, const int &);

template ALGOR::Comparative_Sorts<int>::TimSort::TimSort(int *, asize_t);
template ALGOR::Comparative_Sorts<float>::TimSort::TimSort(float *, asize_t);
template ALGOR::Comparative_Sorts<char>::TimSort::TimSort(char *, asize_t);

template void ALGOR::Comparative_Sorts<int>::TimSort::tim_sort();
template void ALGOR::Comparative_Sorts<float>::TimSort::tim_sort();
template void ALGOR::Comparative_Sorts<char>::TimSort::tim_sort();

template void ALGOR::Comparative_Sorts<int>::TimSort::insertionSort(asize_t, asize_t);
template void ALGOR::Comparative_Sorts<float>::TimSort::insertionSort(asize_t, asize_t);
template void ALGOR::Comparative_Sorts<char>::TimSort::insertionSort(asize_t, asize_t);

template void ALGOR::Comparative_Sorts<int>::TimSort::merge(asize_t, asize_t, asize_t);
template void ALGOR::Comparative_Sorts<float>::TimSort::merge(asize_t, asize_t, asize_t);
template void ALGOR::Comparative_Sorts<char>::TimSort::merge(asize_t, asize_t, asize_t);

template ALGOR::Comparative_Sorts<int>::TreeSort::TreeSort(int *, asize_t);
template ALGOR::Comparative_Sorts<float>::TreeSort::TreeSort(float *, asize_t);
template ALGOR::Comparative_Sorts<char>::TreeSort::TreeSort(char *, asize_t);

template void ALGOR::Comparative_Sorts<int>::TreeSort::tree_sort();
template void ALGOR::Comparative_Sorts<float>::TreeSort::tree_sort();
template void ALGOR::Comparative_Sorts<char>::TreeSort::tree_sort();

template typename ALGOR::Comparative_Sorts<int>::TreeSort::Tree *Comparative_Sorts<int>::TreeSort::newnode(int);
template typename ALGOR::Comparative_Sorts<float>::TreeSort::Tree *Comparative_Sorts<float>::TreeSort::newnode(int);
template typename ALGOR::Comparative_Sorts<char>::TreeSort::Tree *Comparative_Sorts<char>::TreeSort::newnode(int);

template typename ALGOR::Comparative_Sorts<int>::TreeSort::Tree *Comparative_Sorts<int>::TreeSort::insert(Tree *, int);
template typename ALGOR::Comparative_Sorts<float>::TreeSort::Tree *Comparative_Sorts<float>::TreeSort::insert(Tree *, int);
template typename ALGOR::Comparative_Sorts<char>::TreeSort::Tree *Comparative_Sorts<char>::TreeSort::insert(Tree *, int);

template void ALGOR::Comparative_Sorts<int>::TreeSort::store(Tree *, int *, asize_t &);
template void ALGOR::Comparative_Sorts<float>::TreeSort::store(Tree *, float *, asize_t &);
template void ALGOR::Comparative_Sorts<char>::TreeSort::store(Tree *, char *, asize_t &);

template ALGOR::Comparative_Sorts<int>::SmoothSort::SmoothSort(int *, int);
template ALGOR::Comparative_Sorts<float>::SmoothSort::SmoothSort(float *, int);
template ALGOR::Comparative_Sorts<char>::SmoothSort::SmoothSort(char *, int);

template void ALGOR::Comparative_Sorts<int>::SmoothSort::smooth_sort();
template void ALGOR::Comparative_Sorts<float>::SmoothSort::smooth_sort();
template void ALGOR::Comparative_Sorts<char>::SmoothSort::smooth_sort();

template void ALGOR::Comparative_Sorts<int>::SmoothSort::make_heap_pool();
template void ALGOR::Comparative_Sorts<float>::SmoothSort::make_heap_pool();
template void ALGOR::Comparative_Sorts<char>::SmoothSort::make_heap_pool();

template int ALGOR::Comparative_Sorts<int>::SmoothSort::NextState(int &);
template int ALGOR::Comparative_Sorts<float>::SmoothSort::NextState(int &);
template int ALGOR::Comparative_Sorts<char>::SmoothSort::NextState(int &);

template void ALGOR::Comparative_Sorts<int>::SmoothSort::shiftDown(int, int);
template void ALGOR::Comparative_Sorts<float>::SmoothSort::shiftDown(int, int);
template void ALGOR::Comparative_Sorts<char>::SmoothSort::shiftDown(int, int);

template int ALGOR::Comparative_Sorts<int>::SmoothSort::findPosMaxElem(int, int, int &);
template int ALGOR::Comparative_Sorts<float>::SmoothSort::findPosMaxElem(int, int, int &);
template int ALGOR::Comparative_Sorts<char>::SmoothSort::findPosMaxElem(int, int, int &);

template void ALGOR::Comparative_Sorts<int>::SmoothSort::PrevState(int &);
template void ALGOR::Comparative_Sorts<float>::SmoothSort::PrevState(int &);
template void ALGOR::Comparative_Sorts<char>::SmoothSort::PrevState(int &);
