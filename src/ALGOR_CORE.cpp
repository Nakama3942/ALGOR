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

template <typename type_array>
Array<type_array> *ALGOR::create_struct(const asize_t &SIZE,
										bool mem_allocation)
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
void ALGOR::generate_struct(Array<type_array> *&Array,
							const sbit64_t &min_limit,
							const sbit64_t &max_limit,
							const ubit64_t seed,
							const ubit32_t denominator)
{
	if (denominator == 0)
	{
		throw EXCEPTION_SET::division_by_zero("The Denominator variable is designed to convert the generated integer into a"
											  "fractional number or find its part. It's a divisor, so it can't be zero!");
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

template void ALGOR::swap<sbit8_t>(sbit8_t &, sbit8_t &);
template void ALGOR::swap<sbit16_t>(sbit16_t &, sbit16_t &);
template void ALGOR::swap<sbit32_t>(sbit32_t &, sbit32_t &);
template void ALGOR::swap<sbit64_t>(sbit64_t &, sbit64_t &);
template void ALGOR::swap<ubit8_t>(ubit8_t &, ubit8_t &);
template void ALGOR::swap<ubit16_t>(ubit16_t &, ubit16_t &);
template void ALGOR::swap<ubit32_t>(ubit32_t &, ubit32_t &);
template void ALGOR::swap<ubit64_t>(ubit64_t &, ubit64_t &);
template void ALGOR::swap<fbit32_t>(fbit32_t &, fbit32_t &);
template void ALGOR::swap<fbit64_t>(fbit64_t &, fbit64_t &);
template void ALGOR::swap<fbit128_t>(fbit128_t &, fbit128_t &);

template sbit8_t ALGOR::minimum<sbit8_t>(sbit8_t, sbit8_t);
template sbit16_t ALGOR::minimum<sbit16_t>(sbit16_t, sbit16_t);
template sbit32_t ALGOR::minimum<sbit32_t>(sbit32_t, sbit32_t);
template sbit64_t ALGOR::minimum<sbit64_t>(sbit64_t, sbit64_t);
template ubit8_t ALGOR::minimum<ubit8_t>(ubit8_t, ubit8_t);
template ubit16_t ALGOR::minimum<ubit16_t>(ubit16_t, ubit16_t);
template ubit32_t ALGOR::minimum<ubit32_t>(ubit32_t, ubit32_t);
template ubit64_t ALGOR::minimum<ubit64_t>(ubit64_t, ubit64_t);
template fbit32_t ALGOR::minimum<fbit32_t>(fbit32_t, fbit32_t);
template fbit64_t ALGOR::minimum<fbit64_t>(fbit64_t, fbit64_t);
template fbit128_t ALGOR::minimum<fbit128_t>(fbit128_t, fbit128_t);

template sbit8_t ALGOR::maximum<sbit8_t>(sbit8_t, sbit8_t);
template sbit16_t ALGOR::maximum<sbit16_t>(sbit16_t, sbit16_t);
template sbit32_t ALGOR::maximum<sbit32_t>(sbit32_t, sbit32_t);
template sbit64_t ALGOR::maximum<sbit64_t>(sbit64_t, sbit64_t);
template ubit8_t ALGOR::maximum<ubit8_t>(ubit8_t, ubit8_t);
template ubit16_t ALGOR::maximum<ubit16_t>(ubit16_t, ubit16_t);
template ubit32_t ALGOR::maximum<ubit32_t>(ubit32_t, ubit32_t);
template ubit64_t ALGOR::maximum<ubit64_t>(ubit64_t, ubit64_t);
template fbit32_t ALGOR::maximum<fbit32_t>(fbit32_t, fbit32_t);
template fbit64_t ALGOR::maximum<fbit64_t>(fbit64_t, fbit64_t);
template fbit128_t ALGOR::maximum<fbit128_t>(fbit128_t, fbit128_t);

template Array<sbit8_t> *ALGOR::create_struct<sbit8_t>(const asize_t &, bool);
template Array<sbit16_t> *ALGOR::create_struct<sbit16_t>(const asize_t &, bool);
template Array<sbit32_t> *ALGOR::create_struct<sbit32_t>(const asize_t &, bool);
template Array<sbit64_t> *ALGOR::create_struct<sbit64_t>(const asize_t &, bool);
template Array<ubit8_t> *ALGOR::create_struct<ubit8_t>(const asize_t &, bool);
template Array<ubit16_t> *ALGOR::create_struct<ubit16_t>(const asize_t &, bool);
template Array<ubit32_t> *ALGOR::create_struct<ubit32_t>(const asize_t &, bool);
template Array<ubit64_t> *ALGOR::create_struct<ubit64_t>(const asize_t &, bool);
template Array<fbit32_t> *ALGOR::create_struct<fbit32_t>(const asize_t &, bool);
template Array<fbit64_t> *ALGOR::create_struct<fbit64_t>(const asize_t &, bool);
template Array<fbit128_t> *ALGOR::create_struct<fbit128_t>(const asize_t &, bool);

template void ALGOR::generate_struct<sbit8_t>(Array<sbit8_t> *&, const sbit64_t &, const sbit64_t &, const ubit64_t, const ubit32_t);
template void ALGOR::generate_struct<sbit16_t>(Array<sbit16_t> *&, const sbit64_t &, const sbit64_t &, const ubit64_t, const ubit32_t);
template void ALGOR::generate_struct<sbit32_t>(Array<sbit32_t> *&, const sbit64_t &, const sbit64_t &, const ubit64_t, const ubit32_t);
template void ALGOR::generate_struct<sbit64_t>(Array<sbit64_t> *&, const sbit64_t &, const sbit64_t &, const ubit64_t, const ubit32_t);
template void ALGOR::generate_struct<ubit8_t>(Array<ubit8_t> *&, const sbit64_t &, const sbit64_t &, const ubit64_t, const ubit32_t);
template void ALGOR::generate_struct<ubit16_t>(Array<ubit16_t> *&, const sbit64_t &, const sbit64_t &, const ubit64_t, const ubit32_t);
template void ALGOR::generate_struct<ubit32_t>(Array<ubit32_t> *&, const sbit64_t &, const sbit64_t &, const ubit64_t, const ubit32_t);
template void ALGOR::generate_struct<ubit64_t>(Array<ubit64_t> *&, const sbit64_t &, const sbit64_t &, const ubit64_t, const ubit32_t);
template void ALGOR::generate_struct<fbit32_t>(Array<fbit32_t> *&, const sbit64_t &, const sbit64_t &, const ubit64_t, const ubit32_t);
template void ALGOR::generate_struct<fbit64_t>(Array<fbit64_t> *&, const sbit64_t &, const sbit64_t &, const ubit64_t, const ubit32_t);
template void ALGOR::generate_struct<fbit128_t>(Array<fbit128_t> *&, const sbit64_t &, const sbit64_t &, const ubit64_t, const ubit32_t);

template void ALGOR::remove_struct<sbit8_t>(Array<sbit8_t> *&);
template void ALGOR::remove_struct<sbit16_t>(Array<sbit16_t> *&);
template void ALGOR::remove_struct<sbit32_t>(Array<sbit32_t> *&);
template void ALGOR::remove_struct<sbit64_t>(Array<sbit64_t> *&);
template void ALGOR::remove_struct<ubit8_t>(Array<ubit8_t> *&);
template void ALGOR::remove_struct<ubit16_t>(Array<ubit16_t> *&);
template void ALGOR::remove_struct<ubit32_t>(Array<ubit32_t> *&);
template void ALGOR::remove_struct<ubit64_t>(Array<ubit64_t> *&);
template void ALGOR::remove_struct<fbit32_t>(Array<fbit32_t> *&);
template void ALGOR::remove_struct<fbit64_t>(Array<fbit64_t> *&);
template void ALGOR::remove_struct<fbit128_t>(Array<fbit128_t> *&);
