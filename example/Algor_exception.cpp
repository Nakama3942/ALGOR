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
	//! [exception code details explanation class]
	try
	{
		throw ALGOR::EXCEPTION_SET::Exception(55, "details", "explanation");
	}
	catch (ALGOR::EXCEPTION_SET::Exception ex)
	{
		std::cout << "Code: " << ex.code() << ";\n" << ex.what() << "\n-> " << ex.why() << "\n";
	}
	// >print:>
	//   Code: 55;
	//   details
	//   -> explanation
	//! [exception code details explanation class]

	//! [exception code details explanation]
	throw ALGOR::EXCEPTION_SET::Exception(100, "details", "explanation");
	//! [exception code details explanation]

	//! [exception code details]
	throw ALGOR::EXCEPTION_SET::Exception(100, "details");
	//! [exception code details]

	//! [exception code]
	throw ALGOR::EXCEPTION_SET::Exception(100);
	//! [exception code]

	//! [exception details]
	throw ALGOR::EXCEPTION_SET::Exception("details");
	//! [exception details]

	//! [exception catch code]
	try
	{
		throw ALGOR::EXCEPTION_SET::Exception(100);
	}
	catch (ALGOR::EXCEPTION_SET::Exception ex)
	{
		std::cout << ex.code() << "\n";
		// >print:> 100
	}
	//! [exception catch code]

	//! [exception catch details]
	try
	{
		throw ALGOR::EXCEPTION_SET::Exception(100, "details");
	}
	catch (ALGOR::EXCEPTION_SET::Exception ex)
	{
		std::cout << ex.what() << "\n";
		// >print:> "details"
	}
	//! [exception catch details]

	//! [exception catch explanation]
	try
	{
		throw ALGOR::EXCEPTION_SET::Exception(100, "details", "explanation");
	}
	catch (ALGOR::EXCEPTION_SET::Exception ex)
	{
		std::cout << ex.why() << "\n";
		// >print:> "explanation"
	}
	//! [exception catch explanation]

	//! [exception memory_overflow]
	throw ALGOR::EXCEPTION_SET::memory_overflow();
	//! [exception memory_overflow]

	//! [exception memory_overflow explanation]
	throw ALGOR::EXCEPTION_SET::memory_overflow("explanation");
	//! [exception memory_overflow explanation]

	//! [exception division_by_zero]
	throw ALGOR::EXCEPTION_SET::division_by_zero();
	//! [exception division_by_zero]

	//! [exception division_by_zero explanation]
	throw ALGOR::EXCEPTION_SET::division_by_zero("explanation");
	//! [exception division_by_zero explanation]

	//! [exception position_failure]
	throw ALGOR::EXCEPTION_SET::position_failure();
	//! [exception position_failure]

	//! [exception position_failure explanation]
	throw ALGOR::EXCEPTION_SET::position_failure("explanation");
	//! [exception position_failure explanation]

	//! [exception value_failure]
	throw ALGOR::EXCEPTION_SET::value_failure();
	//! [exception value_failure]

	//! [exception value_failure explanation]
	throw ALGOR::EXCEPTION_SET::value_failure("explanation");
	//! [exception value_failure explanation]

	//! [exception size_failure]
	throw ALGOR::EXCEPTION_SET::size_failure();
	//! [exception size_failure]

	//! [exception size_failure explanation]
	throw ALGOR::EXCEPTION_SET::size_failure("explanation");
	//! [exception size_failure explanation]

	//! [exception void_data]
	throw ALGOR::EXCEPTION_SET::void_data();
	//! [exception void_data]

	//! [exception void_data explanation]
	throw ALGOR::EXCEPTION_SET::void_data("explanation");
	//! [exception void_data explanation]

	//! [exception not_found]
	throw ALGOR::EXCEPTION_SET::not_found();
	//! [exception not_found]

	//! [exception not_found explanation]
	throw ALGOR::EXCEPTION_SET::not_found("explanation");
	//! [exception not_found explanation]

	std::cin.get();
	return 0;
}
