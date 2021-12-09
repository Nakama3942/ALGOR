/* **************************************************************************** *
 * ---------------------------------------------------------------------------- *
 *                                                                              *
 * Copyright © 2021 Kalynovsky Valentin. All rights reserved.                   *
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

#ifndef ALGORARRAY_HPP
#define ALGORARRAY_HPP

#include "ALGOR_CORE.hpp"

//#include <iostream> //Иногда используется для тестов
#include <ctime>  //Будет убран после написания рандомизатора
#include <random> //Будет убран после написания рандомизатора
using namespace std;

//После написания будет перенесён в ALGOR_RANDOM.hpp
//class Randomizer
//{
//public:
//};

namespace ArrayProcessing
{
enum ArrayStatus { SORTED, UNSORTED };
enum ArrayType { NUMBER, STRING };
template <typename type_array> void createdStruct(Array<type_array> *&ARRAY, const int &SIZE);
template <typename type_array> void generatedArray(Array<type_array> *&ARRAY, const int &min_limit, const int &max_limit);
template <typename type_array> void swap(type_array &firstNumber, type_array &secondNumber);
template <typename type_array> void getMin(const type_array *Array, const int &array_size, type_array &point_min, ArrayStatus ArrStat = UNSORTED);
template <typename type_array> void getMax(const type_array *Array, const int &array_size, type_array &point_max, ArrayStatus ArrStat = UNSORTED);
template <typename type_array> void getElementsNumber_lenear(Array<type_array> *&ARRAY, const type_array &required_element, Array<int> *&NumberPoints);
template <typename type_array> void getElementNumber_binary(Array<type_array> *&ARRAY, const type_array &required_element, int &number_point);
template <typename type_array> void getElementNumber_binary(Array<type_array> *&ARRAY, const type_array &required_element, int &number_point, int left_limit, int right_limit);
template <typename type_array> void getOccurrencesOfSubstring(Array<type_array> *&ARRAY, Array<type_array> *&SUBARRAY, Array<int> *&Occurrences, ArrayType ArrType = NUMBER);
template <typename type_array> void addElement(Array<type_array> *&ARRAY, const type_array &value);
template <typename type_array> void reverse(Array<type_array> *&ARRAY);
//template <typename type_array> void resize(Array<type_array> *&ARRAY);
template <typename type_array> void copy(type_array *new_array, const type_array *old_array, const int &size_of_copied, int position_in_new_array = 0, int position_in_old_array = 0);
}

namespace ArrayCharacteristic
{
template <typename type_array> void average(Array<type_array> *&ARRAY, type_array &average);
template <typename type_array> void mediana(Array<type_array> *&ARRAY, type_array &mediana);
template <typename type_array> void moda(Array<type_array> *&ARRAY, type_array &most_frequent, int &highest_frequency);
template <typename type_array> void modas(Array<type_array> *&ARRAY, Array<type_array> *&MostFrequents, int &highest_frequency);
}

#endif //ALGORARRAY_HPP
