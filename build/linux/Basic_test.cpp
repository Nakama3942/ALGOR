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

#include "/usr/include/ALGOR.hpp"
using namespace ALGOR;

#include <iostream>
using std::cout;

int main()
{
	ARRAYDATA<long long> *array = new ARRAYDATA<long long>(10);
	array->generatedData(10, 100);
	Array<long long> *arr = array->getData();
	for (int i = 0; i < array->getSize(); i++) cout << arr->array[i] << " ";
	cout << "\n";

	return 0;
}
