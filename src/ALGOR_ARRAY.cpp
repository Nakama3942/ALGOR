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

#include "../include/ALGOR.hpp"

using namespace ALGOR;

template <typename type_array>
type_array ALGOR::ArrayProcessing<type_array>::minimum(const type_array *Array,
													   const asize_t &array_size)
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
type_array ALGOR::ArrayProcessing<type_array>::maximum(const type_array *Array,
													   const asize_t &array_size)
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
bool ALGOR::ArrayProcessing<type_array>::isOrderliness(const type_array *Array,
													   const asize_t &array_size)
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
asize_t ALGOR::ArrayProcessing<type_array>::distance(type_array *first,
													 type_array *last)
{
	return last - first;
}

template <typename type_array>
type_array *ALGOR::ArrayProcessing<type_array>::lower_bound(type_array *first,
															type_array *last,
															const type_array &value)
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
type_array *ALGOR::ArrayProcessing<type_array>::upper_bound(type_array *first,
															type_array *last,
															const type_array &value)
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
void ALGOR::ArrayProcessing<type_array>::addElement(type_array *&Array,
													asize_t &array_size,
													const type_array &value,
													const asize_t position)
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
void ALGOR::ArrayProcessing<type_array>::subtractElement(type_array *&Array,
														 asize_t &array_size,
														 const asize_t position)
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
void ALGOR::ArrayProcessing<type_array>::subtractValue(type_array *&Array,
													   asize_t &array_size,
													   const type_array &value)
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
void ALGOR::ArrayProcessing<type_array>::copy(type_array *new_array,
											  const type_array *old_array,
											  const asize_t &size_of_copied,
											  asize_t position_in_new_array,
											  asize_t position_in_old_array)
{
	for (asize_t i = 0; i < size_of_copied; i++)
	{
		new_array[i + position_in_new_array] = old_array[i + position_in_old_array];
	}
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
void ALGOR::ARRAYDATA<type_array>::generatedData(const sbit64_t &min_limit,
												 const sbit64_t &max_limit,
												 const ubit64_t seed,
												 const ubit32_t denominator)
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
	asize_t position = ArrayProcessing<type_array>::distance(
		&this->ARRAY->array[0],
		ArrayProcessing<type_array>::lower_bound(
			&this->ARRAY->array[0],
			&this->ARRAY->array[this->ARRAY->array_size - 1],
			required_element
		)
	);
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
			ArrayProcessing<asize_t>::addElement(
				NumberPoints->array,
				NumberPoints->array_size,
				i,
				NumberPoints->array_size
			);
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
void ALGOR::ARRAYDATA<type_array>::resize(const asize_t &NEW_SIZE,
										  const type_array &setElement)
{
	if (NEW_SIZE == this->ARRAY->array_size || NEW_SIZE == 0)
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
void ALGOR::ARRAYDATA<type_array>::replace(const asize_t &position,
										   const type_array &value)
{
	if (position >= this->ARRAY->array_size)
	{
		throw EXCEPTION_SET::position_failure();
	}
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
Array<asize_t> *ALGOR::ARRAYDATA<type_array>::searcherOccurrencesOfSubstring(Array<type_array> *&SUBARRAY,
																			 ArrayType ArrType)
{
	Array<asize_t> *Occurrences = new Array<asize_t>;
	for (asize_t i = 0; i <= this->ARRAY->array_size - SUBARRAY->array_size; i++)
	{
		for (asize_t j = 0; j < SUBARRAY->array_size; j++)
		{
			if (this->ARRAY->array[i + j] == SUBARRAY->array[j])
			{
				if ((ARRAYDATA::ArrayType)(SUBARRAY->array_size - j) == ArrType)
				{
					ArrayProcessing<asize_t>::addElement(
						Occurrences->array,
						Occurrences->array_size,
						i,
						Occurrences->array_size
					);
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
		throw EXCEPTION_SET::division_by_zero("Any non-empty array can get into the class, or the class itself can create it."
											  "However, you can get the array structure from the class and access the data"
											  "directly. The author has only one explanation: you somehow reset the size of"
											  "the array through the structure and now the class works with broken data - in"
											  "the average() method, the division by the size of the array takes place, which"
											  "became equal to zero...");
	}
	return average / this->ARRAY->array_size;
}

template <typename type_array>
type_array ALGOR::ARRAYDATA<type_array>::mediana()
{
	return (
		this->ARRAY->array_size & 1
			? (this->ARRAY->array[this->ARRAY->array_size / 2])
			: (this->ARRAY->array[this->ARRAY->array_size / 2] + this->ARRAY->array[(this->ARRAY->array_size / 2) - 1]) / 2
	);
}

template <typename type_array>
typename ALGOR::ARRAYDATA<type_array>::mode *ALGOR::ARRAYDATA<type_array>::moda()
{
	//Виділення пам'яті під данні
	mode *modes = new mode;
	modes->array_size = 1;
	modes->array = new type_array[1];
	ubit32_t current_frequency = 0;

	//Пошук першого елементу з максимальною частотою
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

	//Якщо всі значення унікальні - кидається виключення
	if (modes->highest_frequency == 1)
	{
		delete[] modes->array;
		delete (modes);
		throw EXCEPTION_SET::value_failure("And to be precise: there is missing value with the maximum frequency. All"
										   "elements in the array are unique and repeated once, so to save resources and time,"
										   "an exception is thrown so that the method does not create a copy of the array"
										   "further");
	}

	//Пошук всіх наступних елементів з цією частотою
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
						ArrayProcessing<type_array>::addElement(
							modes->array,
							modes->array_size,
							this->ARRAY->array[j],
							modes->array_size
						);
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
	if (divideValue == 0)
	{
		throw EXCEPTION_SET::division_by_zero();
	}
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
	ArrayProcessing<type_array>::copy(
		this->ARRAY->array,
		appendingArray->getData()->array,
		appendingArray->getSize(),
		old_size
	);
	return this->ARRAY;
}

template <typename type_array>
Array<type_array> *&ALGOR::ARRAYDATA<type_array>::operator>>=(ARRAYDATA<type_array> *&appendingArray)
{
	asize_t old_size = appendingArray->getSize();
	appendingArray->resize(old_size + this->ARRAY->array_size, 1);
	ArrayProcessing<type_array>::copy(
		appendingArray->getData()->array,
		this->ARRAY->array,
		this->ARRAY->array_size,
		old_size
	);
	return this->ARRAY;
}

template <typename type_array>
void ALGOR::ARRAYDATA<type_array>::remove()
{
	remove_struct<type_array>(this->ARRAY);
}

template class ALGOR::ArrayProcessing<sbit8_t>;
template class ALGOR::ArrayProcessing<sbit16_t>;
template class ALGOR::ArrayProcessing<sbit32_t>;
template class ALGOR::ArrayProcessing<sbit64_t>;
template class ALGOR::ArrayProcessing<ubit8_t>;
template class ALGOR::ArrayProcessing<ubit16_t>;
template class ALGOR::ArrayProcessing<ubit32_t>;
template class ALGOR::ArrayProcessing<ubit64_t>;
template class ALGOR::ArrayProcessing<fbit32_t>;
template class ALGOR::ArrayProcessing<fbit64_t>;
template class ALGOR::ArrayProcessing<fbit128_t>;

template class ALGOR::ArrayBase<sbit8_t>;
template class ALGOR::ArrayBase<sbit16_t>;
template class ALGOR::ArrayBase<sbit32_t>;
template class ALGOR::ArrayBase<sbit64_t>;
template class ALGOR::ArrayBase<ubit8_t>;
template class ALGOR::ArrayBase<ubit16_t>;
template class ALGOR::ArrayBase<ubit32_t>;
template class ALGOR::ArrayBase<ubit64_t>;
template class ALGOR::ArrayBase<fbit32_t>;
template class ALGOR::ArrayBase<fbit64_t>;
template class ALGOR::ArrayBase<fbit128_t>;

template class ALGOR::ARRAYDATA<sbit8_t>;
template class ALGOR::ARRAYDATA<sbit16_t>;
template class ALGOR::ARRAYDATA<sbit32_t>;
template class ALGOR::ARRAYDATA<sbit64_t>;
template class ALGOR::ARRAYDATA<ubit8_t>;
template class ALGOR::ARRAYDATA<ubit16_t>;
template class ALGOR::ARRAYDATA<ubit32_t>;
template class ALGOR::ARRAYDATA<ubit64_t>;
template class ALGOR::ARRAYDATA<fbit32_t>;
template class ALGOR::ARRAYDATA<fbit64_t>;
template class ALGOR::ARRAYDATA<fbit128_t>;
