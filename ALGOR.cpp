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

void verification(const asize_t &array_size)
{
	if (array_size == 0)
	{
		throw void_data();
	}
}

/* ****+/^^^/+++++-/&/-+-+-+-/&/-+-+-+-/&/-+-+-+-/&/-+-+-+-/&/-+++++/^^^/+**** *
 * #*****+/^^^/+++++-/+/-+-+                         +-+-/+/-+++++/^^^/+*****# *
 * #*-*%*-*+                                                         +*-*%*-*# *
 * %%%%%                       $------------------$                      %%%%% *
 * -->                              ALGOR_CORE                             <-- *
 * %%%%%                       $------------------$                      %%%%% *
 * #*-*%*-*+                                                         +*-*%*-*# *
 * #*****+/^^^/+++++-/+/-+-+                         +-+-/+/-+++++/^^^/+*****# *
 * ****+/^^^/+++++-/&/-+-+-+-/&/-+-+-+-/&/-+-+-+-/&/-+-+-+-/&/-+++++/^^^/+**** */

memcell_t getMemoryCell()
{
	memcell_t *cells = new memcell_t[10];
	memcell_t *cell = new memcell_t(cells[0]);
	for (int i = 1; i < 10; i++)
	{
		*cell >>= (memcell_t)cells[i];
		*cell <<= (memcell_t)cells[i + 1];
		*cell ^= (memcell_t)cells[i + 2];
	}
	return *cell;
}

memcell_t getMemoryCell(memcell_t right_adjust, memcell_t left_adjust)
{
	memcell_t *cells = new memcell_t[10];
	memcell_t *cell = new memcell_t(cells[0]);
	for (int i = 1; i < 10; i++)
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

template <typename type_array>
void Core<type_array>::swap(type_array &firstNumber, type_array &secondNumber)
{
	type_array temp = firstNumber;
	firstNumber = secondNumber;
	secondNumber = temp;
}

template <typename type_array>
type_array Core<type_array>::minimum(const type_array *Array, const asize_t &array_size)
{
	verification(array_size);
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
type_array Core<type_array>::minimum(type_array firstNumber, type_array secondNumber)
{
	return firstNumber < secondNumber ? firstNumber : secondNumber;
}

template <typename type_array>
type_array Core<type_array>::maximum(const type_array *Array, const asize_t &array_size)
{
	verification(array_size);
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
type_array Core<type_array>::maximum(type_array firstNumber, type_array secondNumber)
{
	return firstNumber > secondNumber ? firstNumber : secondNumber;
}

template <typename type_array>
void Core<type_array>::addElement(type_array *&Array, asize_t &array_size, const type_array &value, const unsigned int position)
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
void Core<type_array>::subtractElement(type_array *&Array, asize_t &array_size, const unsigned int position)
{
	verification(array_size);
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
void Core<type_array>::subtractValue(type_array *&Array, asize_t &array_size, const type_array &value)
{
	verification(array_size);
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
void Core<type_array>::copy(type_array *new_array, const type_array *old_array, const unsigned int &size_of_copied, unsigned int position_in_new_array, unsigned int position_in_old_array)
{
	for (unsigned int i = 0; i < size_of_copied; i++)
	{
		new_array[i + position_in_new_array] = old_array[i + position_in_old_array];
	}
}

template <typename type_array>
Array<type_array> *create_struct(const asize_t &SIZE)
{
	verification(SIZE);
	Array<type_array> *ARRAY = new Array<type_array>;
	ARRAY->array_size = SIZE;
	ARRAY->array = new type_array[SIZE];
	return ARRAY;
}

template <typename type_array>
void remove_struct(Array<type_array> *&Array)
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
ArrayBase<type_array>::ArrayBase(Array<type_array> *&Array) : ARRAY(Array) { verification(ARRAY->array_size); }

template <typename type_array>
ArrayBase<type_array>::ArrayBase(const asize_t &SIZE) { ARRAY = create_struct<type_array>(SIZE); }

template <typename type_array>
ArrayBase<type_array>::ArrayBase() {}

/* ****+/^^^/+++++-/&/-+-+-+-/&/-+-+-+-/&/-+-+-+-/&/-+-+-+-/&/-+++++/^^^/+**** *
 * #*****+/^^^/+++++-/+/-+-+                         +-+-/+/-+++++/^^^/+*****# *
 * #*-*%*-*+                                                         +*-*%*-*# *
 * %%%%%                      $-------------------$                      %%%%% *
 * -->                           ALGOR_EXCEPTION                           <-- *
 * %%%%%                      $-------------------$                      %%%%% *
 * #*-*%*-*+                                                         +*-*%*-*# *
 * #*****+/^^^/+++++-/+/-+-+                         +-+-/+/-+++++/^^^/+*****# *
 * ****+/^^^/+++++-/&/-+-+-+-/&/-+-+-+-/&/-+-+-+-/&/-+-+-+-/&/-+++++/^^^/+**** */

Exception::Exception(unsigned int CODE, const char *DETAILS)
{
	this->CODE = CODE;
	this->DETAILS = DETAILS;
}

Exception::Exception(unsigned int CODE)
{
	this->CODE = CODE;
	this->DETAILS = "No information given";
}

Exception::Exception(const char *DETAILS)
{
	this->CODE = 0xffffffff;
	this->DETAILS = DETAILS;
}

unsigned int Exception::code()
{
	return CODE;
}

const char *Exception::what()
{
	return DETAILS;
}

memory_overflow::memory_overflow() : Exception(55, "The memory cell that stores the size of the data"
												   "volume can no longer store more. This error can"
												   "occur in cases when a larger value is required"
												   "to be written to the cell that can store the"
												   "variable 0xffffffff, i.e. more than 4 bytes, since"
												   "the data size storage cell occupies 4 bytes.")
{
}

position_failure::position_failure() : Exception(254, "Position failure - position is missing in the array") {}

value_failure::value_failure() : Exception(255, "Value failure - value is missing in the array") {}

void_data::void_data() : Exception(400, "Geted empty data structure") {}

not_found::not_found() : Exception(404, "Search error - item not found") {}

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

void RC4::crypto_srand(const char *key, int ksize)
{
	uint8_t j = 0;
	for (int i = 0; i < 256; i++)
	{
		Sbox[i] = i;
	}
	for (int i = 0; i < 256; i++)
	{
		j = j + Sbox[i] + (uint8_t)key[i % ksize];
		Core<uint8_t>::swap(Sbox[i], Sbox[j]);
	}
}

void RC4::crypto_rand(char *output, int size)
{
	uint8_t i = 0, j = 0, t;
	for (int k = 0; i < size; k++)
	{
		i += 1;
		j += Sbox[i];
		Core<uint8_t>::swap(Sbox[i], Sbox[j]);
		t = Sbox[i] + Sbox[j];
		output[k] = (unsigned int)Sbox[t];
	}
}

MersenneTwister::MersenneTwister(int seed)
{
	RandomInit(seed);
	LastInterval = 0;
}

void MersenneTwister::RandomInit(int seed)
{
	Init0(seed);
	for (int i = 0; i < 37; i++)
	{
		BRandom();
	}
}

int MersenneTwister::IRandom(int min, int max)
{
	if (max <= min)
	{
		return max == min ? min : 0x80000000;
	}
	int rand_int = int((double)(uint32_t)(max - min + 1) * Random() + min);
	if (rand_int > max)
	{
		rand_int = max;
	}
	return rand_int;
}

int MersenneTwister::IRandomX(int min, int max)
{
	if (max <= min)
	{
		return max == min ? min : 0x80000000;
	}
	uint32_t len_interval; // Length of interval
	uint64_t long_rbi;	   // Random bits * interval
	uint32_t iran;		   // long_rbi / 2^32
	uint32_t remainder;	   // long_rbi % 2^32

	len_interval = uint32_t(max - min + 1);
	if (len_interval != LastInterval)
	{
		RejectionLimit = uint32_t(((uint64_t)1 << 32) / len_interval) * len_interval - 1;
		LastInterval = len_interval;
	}
	do
	{
		long_rbi = (uint64_t)BRandom() * len_interval;
		iran = (uint32_t)(long_rbi >> 32);
		remainder = (uint32_t)long_rbi;
	} while (remainder > RejectionLimit);
	return (int32_t)iran + min;
}

double MersenneTwister::Random()
{
	return (double)BRandom() * (1. / (65536. * 65536.));
}

uint32_t MersenneTwister::BRandom()
{
	uint32_t resulting_bit;
	if (mersenne_twister_index >= 624)
	{
		const uint32_t LOWER_MASK = (1LU << 31) - 1;  // Lower bits
		const uint32_t UPPER_MASK = 0xFFFFFFFF << 31; // Upper bits
		static const uint32_t mask[2] = {0, 0x9908B0DF};
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

void MersenneTwister::Init0(int seed)
{
	// Basic initialization procedure
	const uint32_t factor = 1812433253UL;
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
 * -->                            ALGOR_SORTING                            <-- *
 * %%%%%                      $-------------------$                      %%%%% *
 * #*-*%*-*+                                                         +*-*%*-*# *
 * #*****+/^^^/+++++-/+/-+-+                         +-+-/+/-+++++/^^^/+*****# *
 * ****+/^^^/+++++-/&/-+-+-+-/&/-+-+-+-/&/-+-+-+-/&/-+-+-+-/&/-+++++/^^^/+**** */

template <class type_array>
Exchange_Sorts<type_array>::Exchange_Sorts(Array<type_array> *&Array) : ArrayBase<type_array>(Array) {}

template <class type_array>
void Exchange_Sorts<type_array>::Bubble_Sort()
{
	BubbleSort *sort = new BubbleSort(this->ARRAY->array, this->ARRAY->array_size);
	sort->bubble_sort();
	delete (sort);
}

template <class type_array>
void Exchange_Sorts<type_array>::Cocktail_Shaker_Sort()
{
	CocktailShakerSort *sort = new CocktailShakerSort(this->ARRAY->array, this->ARRAY->array_size);
	sort->cocktail_shaker_sort();
	delete (sort);
}

template <class type_array>
void Exchange_Sorts<type_array>::Odd_Even_Sort()
{
	OddEvenSort *sort = new OddEvenSort(this->ARRAY->array, this->ARRAY->array_size);
	sort->odd_even_sort();
	delete (sort);
}

template <class type_array>
void Exchange_Sorts<type_array>::Comb_Sort()
{
	CombSort *sort = new CombSort(this->ARRAY->array, this->ARRAY->array_size);
	sort->comb_sort();
	delete (sort);
}

template <class type_array>
void Exchange_Sorts<type_array>::Gnome_Sort()
{
	GnomeSort *sort = new GnomeSort(this->ARRAY->array, this->ARRAY->array_size);
	sort->gnome_sort();
	delete (sort);
}

template <class type_array>
void Exchange_Sorts<type_array>::Quick_Sort()
{
	QuickSort *sort = new QuickSort(this->ARRAY->array, this->ARRAY->array_size);
	sort->quick_sort();
	delete (sort);
}

template <class type_array>
void Exchange_Sorts<type_array>::Slow_Sort()
{
	SlowSort *sort = new SlowSort(this->ARRAY->array, this->ARRAY->array_size);
	sort->slow_sort();
	delete (sort);
}

template <class type_array>
void Exchange_Sorts<type_array>::Stooge_Sort()
{
	StoogeSort *sort = new StoogeSort(this->ARRAY->array, this->ARRAY->array_size);
	sort->stooge_sort();
	delete (sort);
}

template <class type_array>
void Exchange_Sorts<type_array>::Bogo_Sort()
{
	BogoSort *sort = new BogoSort(this->ARRAY->array, this->ARRAY->array_size);
	sort->bogo_sort();
	delete (sort);
}

template <class type_array>
Exchange_Sorts<type_array>::BubbleSort::BubbleSort(type_array *array, asize_t asize) : Array(array), array_size(asize) {}

template <class type_array>
void Exchange_Sorts<type_array>::BubbleSort::bubble_sort()
{
	// verification(array_size);
	for (asize_t i = 0; i < array_size; i++)
	{
		for (asize_t j = 0; j < array_size - 1; j++)
		{
			if (Array[j] > Array[j + 1])
			{
				Core<type_array>::swap(Array[j], Array[j + 1]);
			}
		}
	}
}

template <class type_array>
Exchange_Sorts<type_array>::CocktailShakerSort::CocktailShakerSort(type_array *array, asize_t asize) : Array(array), array_size(asize) {}

template <class type_array>
void Exchange_Sorts<type_array>::CocktailShakerSort::cocktail_shaker_sort()
{
	// verification(array_size);
	asize_t leftMark = 1, rightMark = array_size - 1;
	while (leftMark <= rightMark)
	{
		for (asize_t i = rightMark; i >= leftMark; i--)
		{
			if (Array[i - 1] > Array[i])
			{
				Core<type_array>::swap(Array[i], Array[i - 1]);
			}
		}
		leftMark++;
		for (asize_t i = leftMark; i <= rightMark; i++)
		{
			if (Array[i - 1] > Array[i])
			{
				Core<type_array>::swap(Array[i], Array[i - 1]);
			}
		}
		rightMark--;
	}
}

template <class type_array>
Exchange_Sorts<type_array>::OddEvenSort::OddEvenSort(type_array *array, asize_t asize) : Array(array), array_size(asize) {}

template <class type_array>
void Exchange_Sorts<type_array>::OddEvenSort::odd_even_sort()
{
	for (asize_t i = 0; i < array_size; i++)
	{
		asize_t j;
		i & 1 ? j = 2 : j = 1;
		for (; j < array_size; j += 2)
		{
			if (Array[j] < Array[j - 1])
			{
				Core<type_array>::swap(Array[j - 1], Array[j]);
			}
		}
	}
}

template <class type_array>
Exchange_Sorts<type_array>::CombSort::CombSort(type_array *array, asize_t asize) : Array(array), array_size(asize) {}

template <class type_array>
void Exchange_Sorts<type_array>::CombSort::comb_sort()
{
	double factor = 1.2473309; //Фактор зменшення
	int step = array_size - 1; //Шаг

	while (step >= 1)
	{
		for (asize_t i = 0; i + step < array_size; i++)
		{
			if (Array[i] > Array[i + step])
			{
				Core<type_array>::swap(Array[i], Array[i + step]);
			}
		}
		step /= factor;
	}
}

template <class type_array>
Exchange_Sorts<type_array>::GnomeSort::GnomeSort(type_array *array, asize_t asize) : Array(array), array_size(asize) {}

template <class type_array>
void Exchange_Sorts<type_array>::GnomeSort::gnome_sort()
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
				Core<type_array>::swap(Array[i], Array[i - 1]);
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

template <class type_array>
Exchange_Sorts<type_array>::QuickSort::QuickSort(type_array *array, asize_t asize) : Array(array), array_size(asize) {}

template <class type_array>
void Exchange_Sorts<type_array>::QuickSort::quick_sort()
{
	// verification(array_size);
	recursive_quick_sort(0, array_size - 1);
}

template <class type_array>
void Exchange_Sorts<type_array>::QuickSort::recursive_quick_sort(const int &left_limit, const int &right_limit)
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
			Core<type_array>::swap(Array[start], Array[finish]);
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

template <class type_array>
Exchange_Sorts<type_array>::SlowSort::SlowSort(type_array *array, asize_t asize) : Array(array), array_size(asize) {}

template <class type_array>
void Exchange_Sorts<type_array>::SlowSort::slow_sort()
{
	recursive_slow_sort(0, array_size - 1);
}

template <class type_array>
void Exchange_Sorts<type_array>::SlowSort::recursive_slow_sort(const int &left_limit, const int &right_limit)
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
		Core<type_array>::swap(Array[middle], Array[right_limit]);
	}
	recursive_slow_sort(left_limit, right_limit - 1);
}

template <class type_array>
Exchange_Sorts<type_array>::StoogeSort::StoogeSort(type_array *array, asize_t asize) : Array(array), array_size(asize) {}

template <class type_array>
void Exchange_Sorts<type_array>::StoogeSort::stooge_sort()
{
	recursive_stooge_sort(0, array_size - 1);
}

template <class type_array>
void Exchange_Sorts<type_array>::StoogeSort::recursive_stooge_sort(const int &left_limit, const int &right_limit)
{
	if (Array[left_limit] > Array[right_limit])
	{
		Core<type_array>::swap(Array[left_limit], Array[right_limit]);
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

template <class type_array>
Exchange_Sorts<type_array>::BogoSort::BogoSort(type_array *array, asize_t asize) : Array(array), array_size(asize) {}

template <class type_array>
void Exchange_Sorts<type_array>::BogoSort::bogo_sort()
{
	while (Correct())
	{
		Shuffle();
	}
}

template <class type_array>
bool Exchange_Sorts<type_array>::BogoSort::Correct()
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

template <class type_array>
void Exchange_Sorts<type_array>::BogoSort::Shuffle()
{
	for (asize_t i = 0; i < array_size; i++)
	{
		MersenneTwister RanGen(getMemoryCell());
		Core<type_array>::swap(Array[i], Array[RanGen.IRandom(0, array_size - 1)]);
	}
}

template <class type_array>
Selection_Sorts<type_array>::Selection_Sorts(Array<type_array> *&Array) : ArrayBase<type_array>(Array) {}

template <class type_array>
void Selection_Sorts<type_array>::Selection_Sort()
{
	SelectionSort *sort = new SelectionSort(this->ARRAY->array, this->ARRAY->array_size);
	sort->selection_sort();
	delete (sort);
}

template <class type_array>
void Selection_Sorts<type_array>::Heap_Sort()
{
	HeapSort *sort = new HeapSort(this->ARRAY->array, this->ARRAY->array_size);
	sort->heap_sort();
	delete (sort);
}

template <class type_array>
void Selection_Sorts<type_array>::Smooth_Sort()
{
	SmoothSort sort(this->ARRAY->array, (int)this->ARRAY->array_size);
	sort.smooth_sort();
}

template <class type_array>
void Selection_Sorts<type_array>::Cycle_Sort()
{
	CycleSort *sort = new CycleSort(this->ARRAY->array, this->ARRAY->array_size);
	sort->cycle_sort();
	delete (sort);
}

template <class type_array>
Selection_Sorts<type_array>::SelectionSort::SelectionSort(type_array *array, asize_t asize) : Array(array), array_size(asize) {}

template <class type_array>
void Selection_Sorts<type_array>::SelectionSort::selection_sort()
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
			Core<type_array>::swap(Array[i], Array[min_index]);
		}
	}
}

template <class type_array>
Selection_Sorts<type_array>::HeapSort::HeapSort(type_array *array, asize_t asize) : Array(array), array_size(asize) {}

template <class type_array>
void Selection_Sorts<type_array>::HeapSort::heap_sort()
{
	//Типи int у циклах ЗАЛИШИТИ! Без них не працює!
	verification(array_size);
	for (int right = array_size / 2 - 1; right >= 0; right--)
	{
		heapify(Array, right, array_size);
	}
	for (int i = array_size - 1; i >= 0; i--)
	{
		Core<type_array>::swap(Array[0], Array[i]);
		heapify(Array, 0, i);
	}
}

template <class type_array>
void Selection_Sorts<type_array>::HeapSort::heapify(type_array *Array, const asize_t &count, const asize_t &array_size)
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
		Core<type_array>::swap(Array[count], Array[large]);
		heapify(Array, large, array_size);
	}
}

template <class type_array>
Selection_Sorts<type_array>::SmoothSort::SmoothSort(type_array *array, int asize) : Array(array), array_size(asize) {}

template <class type_array>
void Selection_Sorts<type_array>::SmoothSort::smooth_sort()
{
	make_heap_pool();

	for (int i = array_size - 1; i >= 0; i--)
	{
		int nextPosHeapItemsAmount;
		int posMaxTopElem = findPosMaxElem(curState, i, nextPosHeapItemsAmount);
		if (posMaxTopElem != i)
		{
			Core<type_array>::swap(Array[i], Array[posMaxTopElem]);
			shiftDown(nextPosHeapItemsAmount, posMaxTopElem);
		}
		PrevState(curState);
	}
}

template <class type_array>
void Selection_Sorts<type_array>::SmoothSort::make_heap_pool()
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

template <class type_array>
int Selection_Sorts<type_array>::SmoothSort::NextState(int &curState)
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

template <class type_array>
void Selection_Sorts<type_array>::SmoothSort::shiftDown(int posHeapItemsAmount, int indexLastTop)
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
			Core<type_array>::swap(Array[posCurNode], Array[posMaxChild]);
			posHeapItemsAmount = posNextTop;
			posCurNode = posMaxChild;
		}
		else
		{
			break;
		}
	}
}

template <class type_array>
int Selection_Sorts<type_array>::SmoothSort::findPosMaxElem(int curState, int indexLastTop, int &nextPosHeapItemsAmount)
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

template <class type_array>
void Selection_Sorts<type_array>::SmoothSort::PrevState(int &curState)
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

template <class type_array>
Selection_Sorts<type_array>::CycleSort::CycleSort(type_array *array, asize_t asize) : Array(array), array_size(asize) {}

template <class type_array>
void Selection_Sorts<type_array>::CycleSort::cycle_sort()
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
		Core<type_array>::swap(Array[pos], item);

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
			Core<type_array>::swap(Array[pos], item);
		}
	}
}

template <class type_array>
Insertion_Sorts<type_array>::Insertion_Sorts(Array<type_array> *&Array) : ArrayBase<type_array>(Array) {}

template <class type_array>
void Insertion_Sorts<type_array>::Insert_Sort()
{
	InsertSort *sort = new InsertSort(this->ARRAY->array, this->ARRAY->array_size);
	sort->insert_sort();
	delete (sort);
}

template <class type_array>
void Insertion_Sorts<type_array>::Shell_Sort()
{
	ShellSort *sort = new ShellSort(this->ARRAY->array, this->ARRAY->array_size);
	sort->shell_sort();
	delete (sort);
}

template <class type_array>
void Insertion_Sorts<type_array>::Tree_Sort()
{
	TreeSort *sort = new TreeSort(this->ARRAY->array, this->ARRAY->array_size);
	sort->tree_sort();
	delete (sort);
}

template <class type_array>
void Insertion_Sorts<type_array>::Patience_Sort()
{
	PatienceSort *sort = new PatienceSort(this->ARRAY->array, this->ARRAY->array_size);
	sort->patience_sort();
	delete (sort);
}

template <class type_array>
Insertion_Sorts<type_array>::InsertSort::InsertSort(type_array *array, asize_t asize) : Array(array), array_size(asize) {}

template <class type_array>
void Insertion_Sorts<type_array>::InsertSort::insert_sort()
{
	// verification(array_size);
	for (asize_t i = 0; i < array_size; i++)
	{
		for (asize_t j = i; j > 0 && Array[j - 1] > Array[j]; j--)
		{
			Core<type_array>::swap(Array[j - 1], Array[j]);
		}
	}
}

template <class type_array>
Insertion_Sorts<type_array>::ShellSort::ShellSort(type_array *array, asize_t asize) : Array(array), array_size(asize) {}

template <class type_array>
void Insertion_Sorts<type_array>::ShellSort::shell_sort()
{
	for (asize_t step = array_size / 2; step > 0; step /= 2)
	{
		for (asize_t i = step; i < array_size; i++)
		{
			for (int j = (int)i - step; j >= 0 && Array[j] > Array[j + step]; j -= step)
			{
				Core<type_array>::swap(Array[j], Array[j + step]);
			}
		}
	}
}

template <class type_array>
Insertion_Sorts<type_array>::TreeSort::TreeSort(type_array *array, asize_t asize) : Array(array), array_size(asize) {}

template <class type_array>
void Insertion_Sorts<type_array>::TreeSort::tree_sort()
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

template <class type_array>
typename Insertion_Sorts<type_array>::TreeSort::Tree *Insertion_Sorts<type_array>::TreeSort::newnode(int key)
{
	Tree *temp = new Tree;
	temp->data = key;
	temp->left = nullptr;
	temp->right = nullptr;
	return temp;
}

template <class type_array>
typename Insertion_Sorts<type_array>::TreeSort::Tree *Insertion_Sorts<type_array>::TreeSort::insert(Tree *node, int key)
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

template <class type_array>
void Insertion_Sorts<type_array>::TreeSort::store(Tree *root, type_array *Array, asize_t &index)
{
	if (root != nullptr)
	{
		store(root->left, Array, index);
		Array[index++] = root->data;
		store(root->right, Array, index);
	}
}

template <class type_array>
Insertion_Sorts<type_array>::PatienceSort::PatienceSort(type_array *array, asize_t asize) : Array(array), array_size(asize) {}

template <class type_array>
void Insertion_Sorts<type_array>::PatienceSort::patience_sort()
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

template <class type_array>
void Insertion_Sorts<type_array>::PatienceSort::initialization()
{
	count = new asize_t[array_size]{0};
	decks = new type_array *[array_size];
	for (asize_t i = 0; i < array_size; i++)
	{
		decks[i] = new type_array[array_size]{0};
	}
	sortedArr = new type_array[array_size]{0};
}

template <class type_array>
void Insertion_Sorts<type_array>::PatienceSort::finalization()
{
	delete[] sortedArr;
	for (asize_t i = 0; i < array_size; i++)
	{
		delete[] decks[i];
	}
	delete[] decks;
	delete[] count;
}

template <class type_array>
Merge_Sorts<type_array>::Merge_Sorts(Array<type_array> *&Array) : ArrayBase<type_array>(Array) {}

template <class type_array>
void Merge_Sorts<type_array>::Merge_Sort()
{
	MergeSort *sort = new MergeSort(this->ARRAY->array, this->ARRAY->array_size);
	sort->merge_sort();
	delete (sort);
}

template <class type_array>
Merge_Sorts<type_array>::MergeSort::MergeSort(type_array *array, asize_t asize) : Array(array), array_size(asize) {}

template <class type_array>
void Merge_Sorts<type_array>::MergeSort::merge_sort()
{
	// verification(array_size);
	recursive_merge_sort(0, array_size - 1);
}

template <class type_array>
void Merge_Sorts<type_array>::MergeSort::recursive_merge_sort(const asize_t &left_limit, const asize_t &right_limit)
{
	if (left_limit < right_limit)
	{
		asize_t middle = left_limit + (right_limit - left_limit) / 2;
		recursive_merge_sort(left_limit, middle);
		recursive_merge_sort(middle + 1, right_limit);
		merge(left_limit, middle, right_limit);
	}
}

template <class type_array>
void Merge_Sorts<type_array>::MergeSort::merge(const asize_t &left_limit, const asize_t &middle_limit, const asize_t &right_limit)
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

// void Distribution_Sorts::CountingSort::start_sort()
//{

//}

// void Distribution_Sorts::RadixSort::start_sort()
//{

//}

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
ARRAYDATA<type_array>::ARRAYDATA(Array<type_array> *&Array) : ArrayBase<type_array>(Array) {}

template <typename type_array>
ARRAYDATA<type_array>::ARRAYDATA(const asize_t &SIZE) : ArrayBase<type_array>(SIZE) {}

template <typename type_array>
ARRAYDATA<type_array>::~ARRAYDATA()
{
	remove();
}

template <typename type_array>
void ARRAYDATA<type_array>::generatedData(const int &min_limit, const int &max_limit)
{
	MersenneTwister RanGen(getMemoryCell());
	for (asize_t i = 0; i < this->ARRAY->array_size; i++)
	{
		this->ARRAY->array[i] = RanGen.IRandom(min_limit, max_limit);
	}
}

template <typename type_array>
void ARRAYDATA<type_array>::setNewData(Array<type_array> *&Array)
{
	verification(Array->array_size);
	remove();
	this->ARRAY = Array;
}

template <typename type_array>
void ARRAYDATA<type_array>::setData(Array<type_array> *&Array)
{
	verification(Array->array_size);
	this->ARRAY = Array;
}

template <typename type_array>
void ARRAYDATA<type_array>::cloneData(Array<type_array> *&CloningArray)
{
	verification(CloningArray->array_size);
	if (CloningArray->array_size != this->ARRAY->array_size)
	{
		remove();
		this->ARRAY = create_struct<type_array>(CloningArray->array_size);
	}
	Core<type_array>::copy(this->ARRAY->array, CloningArray->array, CloningArray->array_size);
}

template <typename type_array>
void ARRAYDATA<type_array>::cloneData(ARRAYDATA<type_array> *&CloningObject)
{
	if (CloningObject->getData()->array_size != this->ARRAY->array_size)
	{
		remove();
		this->ARRAY = create_struct<type_array>(CloningObject->getData()->array_size);
	}
	Core<type_array>::copy(this->ARRAY->array, CloningObject->getData()->array, CloningObject->getData()->array_size);
}

template <typename type_array>
void ARRAYDATA<type_array>::getData(Array<type_array> *&DATA)
{
	DATA = this->ARRAY;
}

template <typename type_array>
Array<type_array> *ARRAYDATA<type_array>::getData()
{
	return this->ARRAY;
}

template <typename type_array>
void ARRAYDATA<type_array>::reset()
{
	asize_t SIZE = this->ARRAY->array_size;
	type_array min = getMin(), max = getMax();
	remove();
	this->ARRAY = create_struct<type_array>(SIZE);
	generatedData(min, max);
}

template <typename type_array>
void ARRAYDATA<type_array>::resize(const asize_t &NEW_SIZE, const type_array &setElement)
{
	Array<type_array> *OLD_ARRAY = this->ARRAY, *NEW_ARRAY = create_struct<type_array>(NEW_SIZE);
	if (OLD_ARRAY->array_size < NEW_ARRAY->array_size)
	{
		Core<type_array>::copy(NEW_ARRAY->array, OLD_ARRAY->array, OLD_ARRAY->array_size);
		for (asize_t i = OLD_ARRAY->array_size; i < NEW_ARRAY->array_size; i++)
		{
			NEW_ARRAY->array[i] = setElement;
		}
	}
	else
	{
		Core<type_array>::copy(NEW_ARRAY->array, OLD_ARRAY->array, NEW_ARRAY->array_size);
	}
	this->ARRAY = NEW_ARRAY;
	remove_struct<type_array>(OLD_ARRAY);
}

template <typename type_array>
void ARRAYDATA<type_array>::replace(const unsigned int &position, const type_array &value)
{
	this->ARRAY->array[position] = value;
}

template <typename type_array>
void ARRAYDATA<type_array>::reverse()
{
	int left_limit = 0, right_limit = this->ARRAY->array_size - 1;
	for (asize_t i = 0; i < this->ARRAY->array_size / 2; i++)
	{
		Core<type_array>::swap(this->ARRAY->array[left_limit], this->ARRAY->array[right_limit]);
		left_limit++;
		right_limit--;
	}
}

template <typename type_array>
void ARRAYDATA<type_array>::respawn()
{
	asize_t size = this->ARRAY->array_size;
	remove();
	this->ARRAY = create_struct<type_array>(size);
}

template <typename type_array>
type_array ARRAYDATA<type_array>::getMin(ArrayStatus ArrStat)
{
	switch (ArrStat)
	{
	case ARRAYDATA::ArrayStatus::UNSORTED:
		return Core<type_array>::minimum(this->ARRAY->array, this->ARRAY->array_size);
	case ARRAYDATA::ArrayStatus::SORTED:
		return this->ARRAY->array[0];
	}
	throw value_failure();
}

template <typename type_array>
type_array ARRAYDATA<type_array>::getMax(ArrayStatus ArrStat)
{
	switch (ArrStat)
	{
	case ARRAYDATA::ArrayStatus::UNSORTED:
		return Core<type_array>::maximum(this->ARRAY->array, this->ARRAY->array_size);
	case ARRAYDATA::ArrayStatus::SORTED:
		return this->ARRAY->array[this->ARRAY->array_size - 1];
	}
	throw value_failure();
}

template <typename type_array>
Array<int> *ARRAYDATA<type_array>::lenear_searcher(const type_array &required_element)
{
	Array<int> *NumberPoints = new Array<int>;
	for (asize_t i = 0; i < this->ARRAY->array_size; i++)
	{
		if (required_element == this->ARRAY->array[i])
		{
			Core<int>::addElement(NumberPoints->array, NumberPoints->array_size, i, NumberPoints->array_size);
		}
	}
	if (NumberPoints->array_size == 0)
	{
		throw not_found();
	}
	return NumberPoints;
}

template <typename type_array>
int ARRAYDATA<type_array>::binary_searcher(const type_array &required_element)
{
	int position = 0;
	binary_searcher(required_element, position, 0, this->ARRAY->array_size - 1);
	return position;
}

template <typename type_array>
void ARRAYDATA<type_array>::binary_searcher(const type_array &required_element, int &number_point, int left_limit, int right_limit)
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
Array<int> *ARRAYDATA<type_array>::searcherOccurrencesOfSubstring(Array<type_array> *&SUBARRAY, ArrayType ArrType)
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
						Core<int>::addElement(Occurrences->array, Occurrences->array_size, i, Occurrences->array_size);
					}
					break;
				case ARRAYDATA::ArrayType::STRING:
					if (SUBARRAY->array_size - j == 2)
					{
						Core<int>::addElement(Occurrences->array, Occurrences->array_size, i, Occurrences->array_size);
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
type_array ARRAYDATA<type_array>::average()
{
	type_array average = 0;
	for (unsigned int i = 0; i < this->ARRAY->array_size; i++)
	{
		average += this->ARRAY->array[i];
	}
	return average / (type_array)this->ARRAY->array_size;
}

template <typename type_array>
type_array ARRAYDATA<type_array>::mediana()
{
	return this->ARRAY->array_size % 2 == 0 ? (this->ARRAY->array[this->ARRAY->array_size / 2] + this->ARRAY->array[(this->ARRAY->array_size / 2) - 1]) / 2 : (this->ARRAY->array[this->ARRAY->array_size / 2]);
}

template <typename type_array>
type_array ARRAYDATA<type_array>::moda(int &highest_frequency)
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
Array<type_array> *ARRAYDATA<type_array>::modas(int &highest_frequency)
{
	Array<type_array> *MostFrequents = new Array<type_array>;
	highest_frequency = 0;
	int current_frequency = 0;
	type_array most_frequent = moda(highest_frequency);
	Core<type_array>::addElement(MostFrequents->array, MostFrequents->array_size, most_frequent, MostFrequents->array_size);
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
						Core<type_array>::addElement(MostFrequents->array, MostFrequents->array_size, this->ARRAY->array[j], MostFrequents->array_size);
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
void ARRAYDATA<type_array>::operator&&(const type_array &value)
{
	Core<type_array>::addElement(this->ARRAY->array, this->ARRAY->array_size, value, this->ARRAY->array_size);
}

template <typename type_array>
void ARRAYDATA<type_array>::operator!()
{
	Core<type_array>::subtractElement(this->ARRAY->array, this->ARRAY->array_size, this->ARRAY->array_size - 1);
}

template <typename type_array>
void ARRAYDATA<type_array>::operator||(const type_array &value)
{
	Core<type_array>::subtractValue(this->ARRAY->array, this->ARRAY->array_size, value);
}

template <typename type_array>
void ARRAYDATA<type_array>::operator<<(ARRAYDATA<type_array> *&appendingArray)
{
	asize_t newSize = this->ARRAY->array_size + appendingArray->getData()->array_size;
	Array<type_array> *temp = create_struct<type_array>(newSize);
	for (asize_t i = 0; i < newSize; i++)
	{
		i < this->ARRAY->array_size ? temp->array[i] = this->ARRAY->array[i] : temp->array[i] = appendingArray->getData()->array[i - this->ARRAY->array_size];
	}
	remove();
	this->ARRAY = create_struct<type_array>(newSize);
	Core<type_array>::copy(this->ARRAY->array, temp->array, newSize);
	remove_struct<type_array>(temp);
}

template <typename type_array>
void ARRAYDATA<type_array>::operator>>(ARRAYDATA<type_array> *&appendingArray)
{
	asize_t newSize = this->ARRAY->array_size + appendingArray->getData()->array_size;
	Array<type_array> *temp = create_struct<type_array>(newSize);
	for (asize_t i = 0; i < newSize; i++)
	{
		i < appendingArray->getData()->array_size ? temp->array[i] = appendingArray->getData()->array[i] : temp->array[i] = this->ARRAY->array[i - appendingArray->getData()->array_size];
	}
	appendingArray->resize(newSize, 1);
	Core<type_array>::copy(appendingArray->getData()->array, temp->array, newSize);
	remove_struct<type_array>(temp);
}

// TODO Optimize operators + - * /

template <typename type_array>
void ARRAYDATA<type_array>::operator+(const asize_t &addSize)
{
	if (this->ARRAY->array_size + addSize > 0xffffffff)
	{
		throw memory_overflow();
	}
	Array<type_array> *temp = create_struct<type_array>(this->ARRAY->array_size);
	Core<type_array>::copy(temp->array, this->ARRAY->array, this->ARRAY->array_size);
	resize(temp->array_size + addSize, 1);
	Core<type_array>::copy(this->ARRAY->array, temp->array, temp->array_size);
	remove_struct<type_array>(temp);
}

template <typename type_array>
void ARRAYDATA<type_array>::operator-(const asize_t &subtractSize)
{
	if (subtractSize >= this->ARRAY->array_size)
	{
		remove();
		return;
	}
	Array<type_array> *temp = create_struct<type_array>(this->ARRAY->array_size);
	Core<type_array>::copy(temp->array, this->ARRAY->array, this->ARRAY->array_size);
	resize(temp->array_size - subtractSize, 1);
	Core<type_array>::copy(this->ARRAY->array, temp->array, this->ARRAY->array_size);
	remove_struct<type_array>(temp);
}

template <typename type_array>
void ARRAYDATA<type_array>::operator*(const asize_t &multiplySize)
{
	if (this->ARRAY->array_size * multiplySize > 0xffffffff)
	{
		throw memory_overflow();
	}
	Array<type_array> *temp = create_struct<type_array>(this->ARRAY->array_size);
	Core<type_array>::copy(temp->array, this->ARRAY->array, this->ARRAY->array_size);
	resize(temp->array_size * multiplySize, 1);
	Core<type_array>::copy(this->ARRAY->array, temp->array, temp->array_size);
	remove_struct<type_array>(temp);
}

template <typename type_array>
void ARRAYDATA<type_array>::operator/(const asize_t &divideSize)
{
	if (divideSize >= this->ARRAY->array_size)
	{
		remove();
		return;
	}
	Array<type_array> *temp = create_struct<type_array>(this->ARRAY->array_size);
	Core<type_array>::copy(temp->array, this->ARRAY->array, this->ARRAY->array_size);
	resize(temp->array_size / divideSize, 1);
	Core<type_array>::copy(this->ARRAY->array, temp->array, this->ARRAY->array_size);
	remove_struct<type_array>(temp);
}

template <typename type_array>
void ARRAYDATA<type_array>::remove()
{
	remove_struct<type_array>(this->ARRAY);
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

/* ****+/^^^/+++++-/&/-+-+-+-/&/-+-+-+-/&/-+-+-+-/&/-+-+-+-/&/-+++++/^^^/+**** *
 * #*****+/^^^/+++++-/+/-+-+                         +-+-/+/-+++++/^^^/+*****# *
 * #*-*%*-*+                                                         +*-*%*-*# *
 * %%%%%                    $-----------------------$                    %%%%% *
 * -->                         Forced  compilation                         <-- *
 * %%%%%                    $-----------------------$                    %%%%% *
 * #*-*%*-*+                                                         +*-*%*-*# *
 * #*****+/^^^/+++++-/+/-+-+                         +-+-/+/-+++++/^^^/+*****# *
 * ****+/^^^/+++++-/&/-+-+-+-/&/-+-+-+-/&/-+-+-+-/&/-+-+-+-/&/-+++++/^^^/+**** */

template void Core<int>::swap(int &, int &);
template void Core<float>::swap(float &, float &);
template void Core<char>::swap(char &, char &);

template int Core<int>::minimum(const int *, const asize_t &);
template float Core<float>::minimum(const float *, const asize_t &);
template char Core<char>::minimum(const char *, const asize_t &);

template int Core<int>::minimum(int, int);
template float Core<float>::minimum(float, float);
template char Core<char>::minimum(char, char);

template int Core<int>::maximum(const int *, const asize_t &);
template float Core<float>::maximum(const float *, const asize_t &);
template char Core<char>::maximum(const char *, const asize_t &);

template int Core<int>::maximum(int, int);
template float Core<float>::maximum(float, float);
template char Core<char>::maximum(char, char);

template void Core<int>::addElement(int *&, asize_t &, const int &, const unsigned int);
template void Core<float>::addElement(float *&, asize_t &, const float &, const unsigned int);
template void Core<char>::addElement(char *&, asize_t &, const char &, const unsigned int);

template void Core<int>::subtractElement(int *&, asize_t &, const unsigned int);
template void Core<float>::subtractElement(float *&, asize_t &, const unsigned int);
template void Core<char>::subtractElement(char *&, asize_t &, const unsigned int);

template void Core<int>::subtractValue(int *&, asize_t &, const int &);
template void Core<float>::subtractValue(float *&, asize_t &, const float &);
template void Core<char>::subtractValue(char *&, asize_t &, const char &);

template void Core<int>::copy(int *, const int *, const unsigned int &, unsigned int, unsigned int);
template void Core<float>::copy(float *, const float *, const unsigned int &, unsigned int, unsigned int);
template void Core<char>::copy(char *, const char *, const unsigned int &, unsigned int, unsigned int);

template Array<int> *create_struct<int>(const asize_t &);
template Array<float> *create_struct<float>(const asize_t &);
template Array<char> *create_struct<char>(const asize_t &);

template void remove_struct<int>(Array<int> *&);
template void remove_struct<float>(Array<float> *&);
template void remove_struct<char>(Array<char> *&);

template ArrayBase<int>::ArrayBase(Array<int> *&);
template ArrayBase<float>::ArrayBase(Array<float> *&);
template ArrayBase<char>::ArrayBase(Array<char> *&);

template ArrayBase<int>::ArrayBase(const asize_t &);
template ArrayBase<float>::ArrayBase(const asize_t &);
template ArrayBase<char>::ArrayBase(const asize_t &);

template ArrayBase<int>::ArrayBase();
template ArrayBase<float>::ArrayBase();
template ArrayBase<char>::ArrayBase();

template Exchange_Sorts<int>::Exchange_Sorts(Array<int> *&);
template Exchange_Sorts<float>::Exchange_Sorts(Array<float> *&);
template Exchange_Sorts<char>::Exchange_Sorts(Array<char> *&);

template void Exchange_Sorts<int>::Bubble_Sort();
template void Exchange_Sorts<float>::Bubble_Sort();
template void Exchange_Sorts<char>::Bubble_Sort();

template void Exchange_Sorts<int>::Cocktail_Shaker_Sort();
template void Exchange_Sorts<float>::Cocktail_Shaker_Sort();
template void Exchange_Sorts<char>::Cocktail_Shaker_Sort();

template void Exchange_Sorts<int>::Odd_Even_Sort();
template void Exchange_Sorts<float>::Odd_Even_Sort();
template void Exchange_Sorts<char>::Odd_Even_Sort();

template void Exchange_Sorts<int>::Comb_Sort();
template void Exchange_Sorts<float>::Comb_Sort();
template void Exchange_Sorts<char>::Comb_Sort();

template void Exchange_Sorts<int>::Gnome_Sort();
template void Exchange_Sorts<float>::Gnome_Sort();
template void Exchange_Sorts<char>::Gnome_Sort();

template void Exchange_Sorts<int>::Quick_Sort();
template void Exchange_Sorts<float>::Quick_Sort();
template void Exchange_Sorts<char>::Quick_Sort();

template void Exchange_Sorts<int>::Slow_Sort();
template void Exchange_Sorts<float>::Slow_Sort();
template void Exchange_Sorts<char>::Slow_Sort();

template void Exchange_Sorts<int>::Stooge_Sort();
template void Exchange_Sorts<float>::Stooge_Sort();
template void Exchange_Sorts<char>::Stooge_Sort();

template void Exchange_Sorts<int>::Bogo_Sort();
template void Exchange_Sorts<float>::Bogo_Sort();
template void Exchange_Sorts<char>::Bogo_Sort();

template Exchange_Sorts<int>::BubbleSort::BubbleSort(int *, asize_t);
template Exchange_Sorts<float>::BubbleSort::BubbleSort(float *, asize_t);
template Exchange_Sorts<char>::BubbleSort::BubbleSort(char *, asize_t);

template void Exchange_Sorts<int>::BubbleSort::bubble_sort();
template void Exchange_Sorts<float>::BubbleSort::bubble_sort();
template void Exchange_Sorts<char>::BubbleSort::bubble_sort();

template Exchange_Sorts<int>::CocktailShakerSort::CocktailShakerSort(int *, asize_t);
template Exchange_Sorts<float>::CocktailShakerSort::CocktailShakerSort(float *, asize_t);
template Exchange_Sorts<char>::CocktailShakerSort::CocktailShakerSort(char *, asize_t);

template void Exchange_Sorts<int>::CocktailShakerSort::cocktail_shaker_sort();
template void Exchange_Sorts<float>::CocktailShakerSort::cocktail_shaker_sort();
template void Exchange_Sorts<char>::CocktailShakerSort::cocktail_shaker_sort();

template Exchange_Sorts<int>::OddEvenSort::OddEvenSort(int *, asize_t);
template Exchange_Sorts<float>::OddEvenSort::OddEvenSort(float *, asize_t);
template Exchange_Sorts<char>::OddEvenSort::OddEvenSort(char *, asize_t);

template void Exchange_Sorts<int>::OddEvenSort::odd_even_sort();
template void Exchange_Sorts<float>::OddEvenSort::odd_even_sort();
template void Exchange_Sorts<char>::OddEvenSort::odd_even_sort();

template Exchange_Sorts<int>::CombSort::CombSort(int *, asize_t);
template Exchange_Sorts<float>::CombSort::CombSort(float *, asize_t);
template Exchange_Sorts<char>::CombSort::CombSort(char *, asize_t);

template void Exchange_Sorts<int>::CombSort::comb_sort();
template void Exchange_Sorts<float>::CombSort::comb_sort();
template void Exchange_Sorts<char>::CombSort::comb_sort();

template Exchange_Sorts<int>::GnomeSort::GnomeSort(int *, asize_t);
template Exchange_Sorts<float>::GnomeSort::GnomeSort(float *, asize_t);
template Exchange_Sorts<char>::GnomeSort::GnomeSort(char *, asize_t);

template void Exchange_Sorts<int>::GnomeSort::gnome_sort();
template void Exchange_Sorts<float>::GnomeSort::gnome_sort();
template void Exchange_Sorts<char>::GnomeSort::gnome_sort();

template Exchange_Sorts<int>::QuickSort::QuickSort(int *, asize_t);
template Exchange_Sorts<float>::QuickSort::QuickSort(float *, asize_t);
template Exchange_Sorts<char>::QuickSort::QuickSort(char *, asize_t);

template void Exchange_Sorts<int>::QuickSort::quick_sort();
template void Exchange_Sorts<float>::QuickSort::quick_sort();
template void Exchange_Sorts<char>::QuickSort::quick_sort();

template void Exchange_Sorts<int>::QuickSort::recursive_quick_sort(const int &, const int &);
template void Exchange_Sorts<float>::QuickSort::recursive_quick_sort(const int &, const int &);
template void Exchange_Sorts<char>::QuickSort::recursive_quick_sort(const int &, const int &);

template Exchange_Sorts<int>::SlowSort::SlowSort(int *, asize_t);
template Exchange_Sorts<float>::SlowSort::SlowSort(float *, asize_t);
template Exchange_Sorts<char>::SlowSort::SlowSort(char *, asize_t);

template void Exchange_Sorts<int>::SlowSort::slow_sort();
template void Exchange_Sorts<float>::SlowSort::slow_sort();
template void Exchange_Sorts<char>::SlowSort::slow_sort();

template void Exchange_Sorts<int>::SlowSort::recursive_slow_sort(const int &, const int &);
template void Exchange_Sorts<float>::SlowSort::recursive_slow_sort(const int &, const int &);
template void Exchange_Sorts<char>::SlowSort::recursive_slow_sort(const int &, const int &);

template Exchange_Sorts<int>::StoogeSort::StoogeSort(int *, asize_t);
template Exchange_Sorts<float>::StoogeSort::StoogeSort(float *, asize_t);
template Exchange_Sorts<char>::StoogeSort::StoogeSort(char *, asize_t);

template void Exchange_Sorts<int>::StoogeSort::stooge_sort();
template void Exchange_Sorts<float>::StoogeSort::stooge_sort();
template void Exchange_Sorts<char>::StoogeSort::stooge_sort();

template void Exchange_Sorts<int>::StoogeSort::recursive_stooge_sort(const int &, const int &);
template void Exchange_Sorts<float>::StoogeSort::recursive_stooge_sort(const int &, const int &);
template void Exchange_Sorts<char>::StoogeSort::recursive_stooge_sort(const int &, const int &);

template Exchange_Sorts<int>::BogoSort::BogoSort(int *, asize_t);
template Exchange_Sorts<float>::BogoSort::BogoSort(float *, asize_t);
template Exchange_Sorts<char>::BogoSort::BogoSort(char *, asize_t);

template void Exchange_Sorts<int>::BogoSort::bogo_sort();
template void Exchange_Sorts<float>::BogoSort::bogo_sort();
template void Exchange_Sorts<char>::BogoSort::bogo_sort();

template bool Exchange_Sorts<int>::BogoSort::Correct();
template bool Exchange_Sorts<float>::BogoSort::Correct();
template bool Exchange_Sorts<char>::BogoSort::Correct();

template void Exchange_Sorts<int>::BogoSort::Shuffle();
template void Exchange_Sorts<float>::BogoSort::Shuffle();
template void Exchange_Sorts<char>::BogoSort::Shuffle();

template Selection_Sorts<int>::Selection_Sorts(Array<int> *&);
template Selection_Sorts<float>::Selection_Sorts(Array<float> *&);
template Selection_Sorts<char>::Selection_Sorts(Array<char> *&);

template void Selection_Sorts<int>::Selection_Sort();
template void Selection_Sorts<float>::Selection_Sort();
template void Selection_Sorts<char>::Selection_Sort();

template void Selection_Sorts<int>::Heap_Sort();
template void Selection_Sorts<float>::Heap_Sort();
template void Selection_Sorts<char>::Heap_Sort();

template void Selection_Sorts<int>::Smooth_Sort();
template void Selection_Sorts<float>::Smooth_Sort();
template void Selection_Sorts<char>::Smooth_Sort();

template void Selection_Sorts<int>::Cycle_Sort();
template void Selection_Sorts<float>::Cycle_Sort();
template void Selection_Sorts<char>::Cycle_Sort();

template Selection_Sorts<int>::SelectionSort::SelectionSort(int *, asize_t);
template Selection_Sorts<float>::SelectionSort::SelectionSort(float *, asize_t);
template Selection_Sorts<char>::SelectionSort::SelectionSort(char *, asize_t);

template void Selection_Sorts<int>::SelectionSort::selection_sort();
template void Selection_Sorts<float>::SelectionSort::selection_sort();
template void Selection_Sorts<char>::SelectionSort::selection_sort();

template Selection_Sorts<int>::HeapSort::HeapSort(int *, asize_t);
template Selection_Sorts<float>::HeapSort::HeapSort(float *, asize_t);
template Selection_Sorts<char>::HeapSort::HeapSort(char *, asize_t);

template void Selection_Sorts<int>::HeapSort::heap_sort();
template void Selection_Sorts<float>::HeapSort::heap_sort();
template void Selection_Sorts<char>::HeapSort::heap_sort();

template void Selection_Sorts<int>::HeapSort::heapify(int *, const asize_t &, const asize_t &);
template void Selection_Sorts<float>::HeapSort::heapify(float *, const asize_t &, const asize_t &);
template void Selection_Sorts<char>::HeapSort::heapify(char *, const asize_t &, const asize_t &);

template Selection_Sorts<int>::SmoothSort::SmoothSort(int *, int);
template Selection_Sorts<float>::SmoothSort::SmoothSort(float *, int);
template Selection_Sorts<char>::SmoothSort::SmoothSort(char *, int);

template void Selection_Sorts<int>::SmoothSort::smooth_sort();
template void Selection_Sorts<float>::SmoothSort::smooth_sort();
template void Selection_Sorts<char>::SmoothSort::smooth_sort();

template void Selection_Sorts<int>::SmoothSort::make_heap_pool();
template void Selection_Sorts<float>::SmoothSort::make_heap_pool();
template void Selection_Sorts<char>::SmoothSort::make_heap_pool();

template int Selection_Sorts<int>::SmoothSort::NextState(int &);
template int Selection_Sorts<float>::SmoothSort::NextState(int &);
template int Selection_Sorts<char>::SmoothSort::NextState(int &);

template void Selection_Sorts<int>::SmoothSort::shiftDown(int, int);
template void Selection_Sorts<float>::SmoothSort::shiftDown(int, int);
template void Selection_Sorts<char>::SmoothSort::shiftDown(int, int);

template int Selection_Sorts<int>::SmoothSort::findPosMaxElem(int, int, int &);
template int Selection_Sorts<float>::SmoothSort::findPosMaxElem(int, int, int &);
template int Selection_Sorts<char>::SmoothSort::findPosMaxElem(int, int, int &);

template void Selection_Sorts<int>::SmoothSort::PrevState(int &);
template void Selection_Sorts<float>::SmoothSort::PrevState(int &);
template void Selection_Sorts<char>::SmoothSort::PrevState(int &);

template Selection_Sorts<int>::CycleSort::CycleSort(int *, asize_t);
template Selection_Sorts<float>::CycleSort::CycleSort(float *, asize_t);
template Selection_Sorts<char>::CycleSort::CycleSort(char *, asize_t);

template void Selection_Sorts<int>::CycleSort::cycle_sort();
template void Selection_Sorts<float>::CycleSort::cycle_sort();
template void Selection_Sorts<char>::CycleSort::cycle_sort();

template Insertion_Sorts<int>::Insertion_Sorts(Array<int> *&);
template Insertion_Sorts<float>::Insertion_Sorts(Array<float> *&);
template Insertion_Sorts<char>::Insertion_Sorts(Array<char> *&);

template void Insertion_Sorts<int>::Insert_Sort();
template void Insertion_Sorts<float>::Insert_Sort();
template void Insertion_Sorts<char>::Insert_Sort();

template void Insertion_Sorts<int>::Shell_Sort();
template void Insertion_Sorts<float>::Shell_Sort();
template void Insertion_Sorts<char>::Shell_Sort();

template void Insertion_Sorts<int>::Tree_Sort();
template void Insertion_Sorts<float>::Tree_Sort();
template void Insertion_Sorts<char>::Tree_Sort();

template void Insertion_Sorts<int>::Patience_Sort();
template void Insertion_Sorts<float>::Patience_Sort();
template void Insertion_Sorts<char>::Patience_Sort();

template Insertion_Sorts<int>::InsertSort::InsertSort(int *, asize_t);
template Insertion_Sorts<float>::InsertSort::InsertSort(float *, asize_t);
template Insertion_Sorts<char>::InsertSort::InsertSort(char *, asize_t);

template void Insertion_Sorts<int>::InsertSort::insert_sort();
template void Insertion_Sorts<float>::InsertSort::insert_sort();
template void Insertion_Sorts<char>::InsertSort::insert_sort();

template Insertion_Sorts<int>::ShellSort::ShellSort(int *, asize_t);
template Insertion_Sorts<float>::ShellSort::ShellSort(float *, asize_t);
template Insertion_Sorts<char>::ShellSort::ShellSort(char *, asize_t);

template void Insertion_Sorts<int>::ShellSort::shell_sort();
template void Insertion_Sorts<float>::ShellSort::shell_sort();
template void Insertion_Sorts<char>::ShellSort::shell_sort();

template Insertion_Sorts<int>::TreeSort::TreeSort(int *, asize_t);
template Insertion_Sorts<float>::TreeSort::TreeSort(float *, asize_t);
template Insertion_Sorts<char>::TreeSort::TreeSort(char *, asize_t);

template void Insertion_Sorts<int>::TreeSort::tree_sort();
template void Insertion_Sorts<float>::TreeSort::tree_sort();
template void Insertion_Sorts<char>::TreeSort::tree_sort();

template typename Insertion_Sorts<int>::TreeSort::Tree *Insertion_Sorts<int>::TreeSort::newnode(int);
template typename Insertion_Sorts<float>::TreeSort::Tree *Insertion_Sorts<float>::TreeSort::newnode(int);
template typename Insertion_Sorts<char>::TreeSort::Tree *Insertion_Sorts<char>::TreeSort::newnode(int);

template typename Insertion_Sorts<int>::TreeSort::Tree *Insertion_Sorts<int>::TreeSort::insert(Tree *, int);
template typename Insertion_Sorts<float>::TreeSort::Tree *Insertion_Sorts<float>::TreeSort::insert(Tree *, int);
template typename Insertion_Sorts<char>::TreeSort::Tree *Insertion_Sorts<char>::TreeSort::insert(Tree *, int);

template void Insertion_Sorts<int>::TreeSort::store(Tree *, int *, asize_t &);
template void Insertion_Sorts<float>::TreeSort::store(Tree *, float *, asize_t &);
template void Insertion_Sorts<char>::TreeSort::store(Tree *, char *, asize_t &);

template Insertion_Sorts<int>::PatienceSort::PatienceSort(int *, asize_t);
template Insertion_Sorts<float>::PatienceSort::PatienceSort(float *, asize_t);
template Insertion_Sorts<char>::PatienceSort::PatienceSort(char *, asize_t);

template void Insertion_Sorts<int>::PatienceSort::patience_sort();
template void Insertion_Sorts<float>::PatienceSort::patience_sort();
template void Insertion_Sorts<char>::PatienceSort::patience_sort();

template void Insertion_Sorts<int>::PatienceSort::initialization();
template void Insertion_Sorts<float>::PatienceSort::initialization();
template void Insertion_Sorts<char>::PatienceSort::initialization();

template void Insertion_Sorts<int>::PatienceSort::finalization();
template void Insertion_Sorts<float>::PatienceSort::finalization();
template void Insertion_Sorts<char>::PatienceSort::finalization();

template Merge_Sorts<int>::Merge_Sorts(Array<int> *&);
template Merge_Sorts<float>::Merge_Sorts(Array<float> *&);
template Merge_Sorts<char>::Merge_Sorts(Array<char> *&);

template void Merge_Sorts<int>::Merge_Sort();
template void Merge_Sorts<float>::Merge_Sort();
template void Merge_Sorts<char>::Merge_Sort();

template Merge_Sorts<int>::MergeSort::MergeSort(int *, asize_t);
template Merge_Sorts<float>::MergeSort::MergeSort(float *, asize_t);
template Merge_Sorts<char>::MergeSort::MergeSort(char *, asize_t);

template void Merge_Sorts<int>::MergeSort::merge_sort();
template void Merge_Sorts<float>::MergeSort::merge_sort();
template void Merge_Sorts<char>::MergeSort::merge_sort();

template void Merge_Sorts<int>::MergeSort::recursive_merge_sort(const asize_t &, const asize_t &);
template void Merge_Sorts<float>::MergeSort::recursive_merge_sort(const asize_t &, const asize_t &);
template void Merge_Sorts<char>::MergeSort::recursive_merge_sort(const asize_t &, const asize_t &);

template void Merge_Sorts<int>::MergeSort::merge(const asize_t &, const asize_t &, const asize_t &);
template void Merge_Sorts<float>::MergeSort::merge(const asize_t &, const asize_t &, const asize_t &);
template void Merge_Sorts<char>::MergeSort::merge(const asize_t &, const asize_t &, const asize_t &);

template ARRAYDATA<int>::ARRAYDATA(Array<int> *&);
template ARRAYDATA<float>::ARRAYDATA(Array<float> *&);
template ARRAYDATA<char>::ARRAYDATA(Array<char> *&);

template ARRAYDATA<int>::ARRAYDATA(const asize_t &);
template ARRAYDATA<float>::ARRAYDATA(const asize_t &);
template ARRAYDATA<char>::ARRAYDATA(const asize_t &);

template ARRAYDATA<int>::~ARRAYDATA();
template ARRAYDATA<float>::~ARRAYDATA();
template ARRAYDATA<char>::~ARRAYDATA();

template void ARRAYDATA<int>::generatedData(const int &, const int &);
template void ARRAYDATA<float>::generatedData(const int &, const int &);
template void ARRAYDATA<char>::generatedData(const int &, const int &);

template void ARRAYDATA<int>::setNewData(Array<int> *&);
template void ARRAYDATA<float>::setNewData(Array<float> *&);
template void ARRAYDATA<char>::setNewData(Array<char> *&);

template void ARRAYDATA<int>::setData(Array<int> *&);
template void ARRAYDATA<float>::setData(Array<float> *&);
template void ARRAYDATA<char>::setData(Array<char> *&);

template void ARRAYDATA<int>::cloneData(Array<int> *&);
template void ARRAYDATA<float>::cloneData(Array<float> *&);
template void ARRAYDATA<char>::cloneData(Array<char> *&);

template void ARRAYDATA<int>::cloneData(ARRAYDATA<int> *&);
template void ARRAYDATA<float>::cloneData(ARRAYDATA<float> *&);
template void ARRAYDATA<char>::cloneData(ARRAYDATA<char> *&);

template void ARRAYDATA<int>::getData(Array<int> *&);
template void ARRAYDATA<float>::getData(Array<float> *&);
template void ARRAYDATA<char>::getData(Array<char> *&);

template Array<int> *ARRAYDATA<int>::getData();
template Array<float> *ARRAYDATA<float>::getData();
template Array<char> *ARRAYDATA<char>::getData();

template void ARRAYDATA<int>::reset();
template void ARRAYDATA<float>::reset();
template void ARRAYDATA<char>::reset();

template void ARRAYDATA<int>::resize(const asize_t &, const int &);
template void ARRAYDATA<float>::resize(const asize_t &, const float &);
template void ARRAYDATA<char>::resize(const asize_t &, const char &);

template void ARRAYDATA<int>::replace(const unsigned int &, const int &);
template void ARRAYDATA<float>::replace(const unsigned int &, const float &);
template void ARRAYDATA<char>::replace(const unsigned int &, const char &);

template void ARRAYDATA<int>::reverse();
template void ARRAYDATA<float>::reverse();
template void ARRAYDATA<char>::reverse();

template void ARRAYDATA<int>::respawn();
template void ARRAYDATA<float>::respawn();
template void ARRAYDATA<char>::respawn();

template int ARRAYDATA<int>::getMin(ArrayStatus);
template float ARRAYDATA<float>::getMin(ArrayStatus);
template char ARRAYDATA<char>::getMin(ArrayStatus);

template int ARRAYDATA<int>::getMax(ArrayStatus);
template float ARRAYDATA<float>::getMax(ArrayStatus);
template char ARRAYDATA<char>::getMax(ArrayStatus);

template Array<int> *ARRAYDATA<int>::lenear_searcher(const int &);
template Array<int> *ARRAYDATA<float>::lenear_searcher(const float &);
template Array<int> *ARRAYDATA<char>::lenear_searcher(const char &);

template int ARRAYDATA<int>::binary_searcher(const int &);
template int ARRAYDATA<float>::binary_searcher(const float &);
template int ARRAYDATA<char>::binary_searcher(const char &);

template void ARRAYDATA<int>::binary_searcher(const int &, int &, int, int);
template void ARRAYDATA<float>::binary_searcher(const float &, int &, int, int);
template void ARRAYDATA<char>::binary_searcher(const char &, int &, int, int);

template Array<int> *ARRAYDATA<int>::searcherOccurrencesOfSubstring(Array<int> *&, ArrayType);
template Array<int> *ARRAYDATA<float>::searcherOccurrencesOfSubstring(Array<float> *&, ArrayType);
template Array<int> *ARRAYDATA<char>::searcherOccurrencesOfSubstring(Array<char> *&, ArrayType);

template int ARRAYDATA<int>::average();
template float ARRAYDATA<float>::average();
template char ARRAYDATA<char>::average();

template int ARRAYDATA<int>::mediana();
template float ARRAYDATA<float>::mediana();
template char ARRAYDATA<char>::mediana();

template int ARRAYDATA<int>::moda(int &);
template float ARRAYDATA<float>::moda(int &);
template char ARRAYDATA<char>::moda(int &);

template Array<int> *ARRAYDATA<int>::modas(int &);
template Array<float> *ARRAYDATA<float>::modas(int &);
template Array<char> *ARRAYDATA<char>::modas(int &);

template void ARRAYDATA<int>::operator&&(const int &);
template void ARRAYDATA<float>::operator&&(const float &);
template void ARRAYDATA<char>::operator&&(const char &);

template void ARRAYDATA<int>::operator!();
template void ARRAYDATA<float>::operator!();
template void ARRAYDATA<char>::operator!();

template void ARRAYDATA<int>::operator||(const int &);
template void ARRAYDATA<float>::operator||(const float &);
template void ARRAYDATA<char>::operator||(const char &);

template void ARRAYDATA<int>::operator<<(ARRAYDATA<int> *&);
template void ARRAYDATA<float>::operator<<(ARRAYDATA<float> *&);
template void ARRAYDATA<char>::operator<<(ARRAYDATA<char> *&);

template void ARRAYDATA<int>::operator>>(ARRAYDATA<int> *&);
template void ARRAYDATA<float>::operator>>(ARRAYDATA<float> *&);
template void ARRAYDATA<char>::operator>>(ARRAYDATA<char> *&);

template void ARRAYDATA<int>::operator+(const asize_t &);
template void ARRAYDATA<float>::operator+(const asize_t &);
template void ARRAYDATA<char>::operator+(const asize_t &);

template void ARRAYDATA<int>::operator-(const asize_t &);
template void ARRAYDATA<float>::operator-(const asize_t &);
template void ARRAYDATA<char>::operator-(const asize_t &);

template void ARRAYDATA<int>::operator*(const asize_t &);
template void ARRAYDATA<float>::operator*(const asize_t &);
template void ARRAYDATA<char>::operator*(const asize_t &);

template void ARRAYDATA<int>::operator/(const asize_t &);
template void ARRAYDATA<float>::operator/(const asize_t &);
template void ARRAYDATA<char>::operator/(const asize_t &);

template void ARRAYDATA<int>::remove();
template void ARRAYDATA<float>::remove();
template void ARRAYDATA<char>::remove();

/* ****+/^^^/+++++-/&/-+-+-+-/&/-+-+-+-/&/-+-+-+-/&/-+-+-+-/&/-+++++/^^^/+**** *
 * #*****+/^^^/+++++-/+/-+-+                         +-+-/+/-+++++/^^^/+*****# *
 * #*-*%*-*+                                                         +*-*%*-*# *
 * %%%%%                       $------------------$                      %%%%% *
 * -->                               STANDART                              <-- *
 * %%%%%                       $------------------$                      %%%%% *
 * #*-*%*-*+                                                         +*-*%*-*# *
 * #*****+/^^^/+++++-/+/-+-+                         +-+-/+/-+++++/^^^/+*****# *
 * ****+/^^^/+++++-/&/-+-+-+-/&/-+-+-+-/&/-+-+-+-/&/-+-+-+-/&/-+++++/^^^/+**** */

#if STANDARDS_SWITCH == 1

template <class type_array>
st_SortingAlgorithms<type_array>::st_SortingAlgorithms(Array<type_array> *&Array) : ArrayBase<type_array>(Array)
{
}

template <class type_array>
void st_SortingAlgorithms<type_array>::Library_Sort()
{
	LibrarySort *sort = new LibrarySort(this->ARRAY->array, this->ARRAY->array_size);
	sort->library_sort();
	delete (sort);
}

template <class type_array>
st_SortingAlgorithms<type_array>::LibrarySort::LibrarySort(type_array *array, asize_t asize) : Array(array), array_size(asize) {}

template <class type_array>
void st_SortingAlgorithms<type_array>::LibrarySort::library_sort()
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
void st_SortingAlgorithms<type_array>::LibrarySort::initialization()
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
void st_SortingAlgorithms<type_array>::LibrarySort::binarysearch()
{
	insert = (asize_t)std::distance(library[target_lib], std::lower_bound(library[target_lib], library[target_lib] + lib_size, Array[index_pos]));
}

template <class type_array>
void st_SortingAlgorithms<type_array>::LibrarySort::insertion()
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
void st_SortingAlgorithms<type_array>::LibrarySort::rebalancing()
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
void st_SortingAlgorithms<type_array>::LibrarySort::finalization()
{
	delete[] numbered;
	for (asize_t i = 0; i < 2; i++)
	{
		delete[] library[i];
	}
	delete[] gaps;
}

template st_SortingAlgorithms<int>::st_SortingAlgorithms(Array<int> *&);
template st_SortingAlgorithms<float>::st_SortingAlgorithms(Array<float> *&);
template st_SortingAlgorithms<char>::st_SortingAlgorithms(Array<char> *&);

template void st_SortingAlgorithms<int>::Library_Sort();
template void st_SortingAlgorithms<float>::Library_Sort();
template void st_SortingAlgorithms<char>::Library_Sort();

template st_SortingAlgorithms<int>::LibrarySort::LibrarySort(int *, asize_t);
template st_SortingAlgorithms<float>::LibrarySort::LibrarySort(float *, asize_t);
template st_SortingAlgorithms<char>::LibrarySort::LibrarySort(char *, asize_t);

template void st_SortingAlgorithms<int>::LibrarySort::library_sort();
template void st_SortingAlgorithms<float>::LibrarySort::library_sort();
template void st_SortingAlgorithms<char>::LibrarySort::library_sort();

template void st_SortingAlgorithms<int>::LibrarySort::initialization();
template void st_SortingAlgorithms<float>::LibrarySort::initialization();
template void st_SortingAlgorithms<char>::LibrarySort::initialization();

template void st_SortingAlgorithms<int>::LibrarySort::binarysearch();
template void st_SortingAlgorithms<float>::LibrarySort::binarysearch();
template void st_SortingAlgorithms<char>::LibrarySort::binarysearch();

template void st_SortingAlgorithms<int>::LibrarySort::insertion();
template void st_SortingAlgorithms<float>::LibrarySort::insertion();
template void st_SortingAlgorithms<char>::LibrarySort::insertion();

template void st_SortingAlgorithms<int>::LibrarySort::rebalancing();
template void st_SortingAlgorithms<float>::LibrarySort::rebalancing();
template void st_SortingAlgorithms<char>::LibrarySort::rebalancing();

template void st_SortingAlgorithms<int>::LibrarySort::finalization();
template void st_SortingAlgorithms<float>::LibrarySort::finalization();
template void st_SortingAlgorithms<char>::LibrarySort::finalization();

#endif // STANDARDS_SWITCH
