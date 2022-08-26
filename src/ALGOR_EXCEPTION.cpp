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
