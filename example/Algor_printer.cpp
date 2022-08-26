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

//! [printer]
template <typename type_array>
class printer : public ALGOR::Printer
{
public:
	void setData(ALGOR::Array<type_array> **ARRAY)
	{
		Array = ARRAY;
	}
	void print() override
	{
		for (asize_t i = 0; i < (*Array)->array_size; i++)
		{
			std::cout << " " << (*Array)->array[i];
		}
		std::cout << "\n";
	}

private:
	ALGOR::Array<type_array> **Array;
};
//! [printer]

int main()
{
	//! [print]
	// Creating an array structure and generating data
	ALGOR::Array<long> *D = create_struct<long>(10);
	generate_struct<long>(D, 10, 1000);

	// Creating a printer object and passing it a reference to the structure
	printer<long> pr;
	pr.setData(&D);

	// Outputting data
	pr.print();
	// >print:> 597 104 23 150 491 594 495 428 875 382

	// Don't forget to free data at the end of the program
	remove_struct<long>(D);
	//! [print]

	std::cin.get();
	return 0;
}
