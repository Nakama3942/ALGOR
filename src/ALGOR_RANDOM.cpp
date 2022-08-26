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
		mersenne_twister[mersenne_twister_index] = (
			factor * (
				mersenne_twister[mersenne_twister_index - 1] ^ (
					mersenne_twister[mersenne_twister_index - 1] >> 30
				)
			) + mersenne_twister_index
		);
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
