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
