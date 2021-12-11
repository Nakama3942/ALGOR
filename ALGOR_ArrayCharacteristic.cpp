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

#include "ALGOR.hpp"

template<typename type_array>
void ArrayCharacteristic::average(Array<type_array> *&ARRAY, type_array &average)
{
    average = 0;
    for (int i = 0; i < ARRAY->array_size; i++)
    {
        average += ARRAY->array[i];
    }
    average = average / ARRAY->array_size;
}
template void ArrayCharacteristic::average<int>(Array<int> *&, int &);
template void ArrayCharacteristic::average<float>(Array<float> *&, float &);
template void ArrayCharacteristic::average<char>(Array<char> *&, char &);

template<typename type_array>
void ArrayCharacteristic::mediana(Array<type_array> *&ARRAY, type_array &mediana)
{
    ARRAY->array_size % 2 == 0 ? mediana = (ARRAY->array[ARRAY->array_size / 2] + ARRAY->array[(ARRAY->array_size / 2) - 1]) / 2 : mediana = (ARRAY->array[ARRAY->array_size / 2]);
}
template void ArrayCharacteristic::mediana<int>(Array<int> *&, int &);
template void ArrayCharacteristic::mediana<float>(Array<float> *&, float &);
template void ArrayCharacteristic::mediana<char>(Array<char> *&, char &);

template<typename type_array>
void ArrayCharacteristic::moda(Array<type_array> *&ARRAY, type_array &most_frequent, int &highest_frequency)
{
    highest_frequency = 0;
    int current_frequency = 0;
    for (int i = 0; i < ARRAY->array_size; i++)
    {
        current_frequency++;
        if (i == ARRAY->array_size - 1 || ARRAY->array[i] != ARRAY->array[i + 1])
        {
            if (current_frequency > highest_frequency)
            {
                highest_frequency = current_frequency;
                most_frequent = ARRAY->array[i];
            }
            current_frequency = 0;
        }
    }
}
template void ArrayCharacteristic::moda<int>(Array<int> *&, int &, int &);
template void ArrayCharacteristic::moda<float>(Array<float> *&, float &, int &);
template void ArrayCharacteristic::moda<char>(Array<char> *&, char &, int &);

template<typename type_array>
void ArrayCharacteristic::modas(Array<type_array> *&ARRAY, Array<type_array> *&MostFrequents, int &highest_frequency)
{
    type_array most_frequent;
    MostFrequents->array_size = 0, highest_frequency = 0;
    int current_frequency = 0;
    moda<type_array>(ARRAY, most_frequent, highest_frequency);
    ArrayProcessing::addElement<type_array>(MostFrequents, most_frequent);
    for (int i = 0; i < ARRAY->array_size; i++)
    {
        if (most_frequent == ARRAY->array[i])
        {
            for (int j = i + highest_frequency; j < ARRAY->array_size; j++)
            {
                current_frequency++;
                if (j == ARRAY->array_size - 1 || ARRAY->array[j] != ARRAY->array[j + 1])
                {
                    if (current_frequency == highest_frequency)
                    {
                        ArrayProcessing::addElement<type_array>(MostFrequents, ARRAY->array[j]);
                    }
                    current_frequency = 0;
                }
            }
            break;
        }
    }
}
template void ArrayCharacteristic::modas<int>(Array<int> *&, Array<int> *&, int &);
template void ArrayCharacteristic::modas<float>(Array<float> *&, Array<float> *&, int &);
template void ArrayCharacteristic::modas<char>(Array<char> *&, Array<char> *&, int &);
