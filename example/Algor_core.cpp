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

#include <iostream>

#include "../include/ALGOR.hpp"
using namespace ALGOR;

int main()
{
	long value1 = 5, value2 = 10;

	//! [swap]
	ALGOR::swap<long>(value1, value2);
	std::cout << value2 << "\n";
	// >print:> 5
	//! [swap]

	//! [minimum]
	std::cout << ALGOR::minimum<long>(value1, value2) << "\n";
	// >print:> 5
	//! [minimum]

	//! [maximum]
	std::cout << ALGOR::maximum<long>(value1, value2) << "\n";
	// >print:> 10
	//! [maximum]

	//! [mem]
	std::cout << ALGOR::getMemoryCell() << "\n";
	// >print:> 185214324139604
	//! [mem]

	//! [array struct]
	ALGOR::Array<long> *arr;
	//! [array struct]
	//! [create_struct]
	try
	{
		arr = ALGOR::create_struct<long>(10);
	}
	catch (ALGOR::EXCEPTION_SET::Exception ex)
	{
		std::cout << "\n\nCode: " << ex.code() << ";\n" << ex.what() << "\n-> " << ex.why() << "\n\n";
	}
	// The data is not taken from the output, but from the debugger console
	// arr = @0x1a1700
	//! [create_struct]
	//! [generate_struct]
	try
	{
		ALGOR::generate_struct<long>(arr, 1, 12);
	}
	catch (ALGOR::EXCEPTION_SET::Exception ex)
	{
		std::cout << "\n\nCode: " << ex.code() << ";\n" << ex.what() << "\n-> " << ex.why() << "\n\n";
	}
	// The data is not taken from the output, but from the debugger console
	// arr->array = {9 9 7 7 4 7 2 7 2 9}
	//! [generate_struct]
	//! [remove_struct]
	try
	{
		ALGOR::remove_struct<long>(arr);
	}
	catch (ALGOR::EXCEPTION_SET::Exception ex)
	{
		std::cout << "\n\nCode: " << ex.code() << ";\n" << ex.what() << "\n-> " << ex.why() << "\n\n";
	}
	// The data is not taken from the output, but from the debugger console
	// arr = 0x0
	//! [remove_struct]

	std::cin.get();
	return 0;
}
