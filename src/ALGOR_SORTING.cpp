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

template <typename type_array>
ALGOR::Comparative_Sorts<type_array>::Comparative_Sorts(Array<type_array> *&Array) : ArrayBase<type_array>(Array) {}

template <typename type_array>
void ALGOR::Comparative_Sorts<type_array>::Bubble_Sort()
{
	BubbleSort *sort = new BubbleSort(this->ARRAY->array, this->ARRAY->array_size);
	sort->bubble_sort();
	delete (sort);
}

template <typename type_array>
void ALGOR::Comparative_Sorts<type_array>::Cocktail_Shaker_Sort()
{
	CocktailShakerSort *sort = new CocktailShakerSort(this->ARRAY->array, this->ARRAY->array_size);
	sort->cocktail_shaker_sort();
	delete (sort);
}

template <typename type_array>
void ALGOR::Comparative_Sorts<type_array>::Odd_Even_Sort()
{
	OddEvenSort *sort = new OddEvenSort(this->ARRAY->array, this->ARRAY->array_size);
	sort->odd_even_sort();
	delete (sort);
}

template <typename type_array>
void ALGOR::Comparative_Sorts<type_array>::Comb_Sort()
{
	CombSort *sort = new CombSort(this->ARRAY->array, this->ARRAY->array_size);
	sort->comb_sort();
	delete (sort);
}

template <typename type_array>
void ALGOR::Comparative_Sorts<type_array>::Gnome_Sort()
{
	GnomeSort *sort = new GnomeSort(this->ARRAY->array, this->ARRAY->array_size);
	sort->gnome_sort();
	delete (sort);
}

template <typename type_array>
void ALGOR::Comparative_Sorts<type_array>::Quick_Sort()
{
	QuickSort *sort = new QuickSort(this->ARRAY->array, this->ARRAY->array_size);
	sort->quick_sort();
	delete (sort);
}

template <typename type_array>
void ALGOR::Comparative_Sorts<type_array>::Slow_Sort()
{
	SlowSort *sort = new SlowSort(this->ARRAY->array, this->ARRAY->array_size);
	sort->slow_sort();
	delete (sort);
}

template <typename type_array>
void ALGOR::Comparative_Sorts<type_array>::Stooge_Sort()
{
	StoogeSort *sort = new StoogeSort(this->ARRAY->array, this->ARRAY->array_size);
	sort->stooge_sort();
	delete (sort);
}

template <typename type_array>
void ALGOR::Comparative_Sorts<type_array>::Bogo_Sort()
{
	BogoSort *sort = new BogoSort(this->ARRAY->array, this->ARRAY->array_size);
	sort->bogo_sort();
	delete (sort);
}

template <typename type_array>
void ALGOR::Comparative_Sorts<type_array>::Selection_Sort()
{
	SelectionSort *sort = new SelectionSort(this->ARRAY->array, this->ARRAY->array_size);
	sort->selection_sort();
	delete (sort);
}

template <typename type_array>
void ALGOR::Comparative_Sorts<type_array>::Heap_Sort()
{
	HeapSort *sort = new HeapSort(this->ARRAY->array, this->ARRAY->array_size);
	sort->heap_sort();
	delete (sort);
}

template <typename type_array>
void ALGOR::Comparative_Sorts<type_array>::Cycle_Sort()
{
	CycleSort *sort = new CycleSort(this->ARRAY->array, this->ARRAY->array_size);
	sort->cycle_sort();
	delete (sort);
}

template <typename type_array>
void ALGOR::Comparative_Sorts<type_array>::Insert_Sort()
{
	InsertSort *sort = new InsertSort(this->ARRAY->array, this->ARRAY->array_size);
	sort->insert_sort();
	delete (sort);
}

template <typename type_array>
void ALGOR::Comparative_Sorts<type_array>::Shell_Sort()
{
	ShellSort *sort = new ShellSort(this->ARRAY->array, this->ARRAY->array_size);
	sort->shell_sort();
	delete (sort);
}

template <typename type_array>
void ALGOR::Comparative_Sorts<type_array>::Tree_Sort()
{
	TreeSort *sort = new TreeSort(this->ARRAY->array, this->ARRAY->array_size);
	sort->tree_sort();
	delete (sort);
}

template <class type_array>
void ALGOR::Comparative_Sorts<type_array>::Library_Sort()
{
	LibrarySort *sort = new LibrarySort(this->ARRAY->array, this->ARRAY->array_size);
	sort->library_sort();
	delete (sort);
}

template <typename type_array>
void ALGOR::Comparative_Sorts<type_array>::Patience_Sort()
{
	PatienceSort *sort = new PatienceSort(this->ARRAY->array, this->ARRAY->array_size);
	sort->patience_sort();
	delete (sort);
}

template <typename type_array>
void ALGOR::Comparative_Sorts<type_array>::Merge_Sort()
{
	MergeSort *sort = new MergeSort(this->ARRAY->array, this->ARRAY->array_size);
	sort->merge_sort();
	delete (sort);
}

template <typename type_array>
void ALGOR::Comparative_Sorts<type_array>::Bitonic_Sorter()
{
	BitonicSorter *sort = new BitonicSorter(this->ARRAY->array, this->ARRAY->array_size);
	sort->bitonic_sorter();
	delete (sort);
}

template <typename type_array>
void ALGOR::Comparative_Sorts<type_array>::Batcher_OddEven_MergeSort()
{
	BatcherOddEvenMergeSort *sort = new BatcherOddEvenMergeSort(this->ARRAY->array, this->ARRAY->array_size);
	sort->batcher_odd_even_merge_sort();
	delete (sort);
}

template <typename type_array>
void ALGOR::Comparative_Sorts<type_array>::Tim_Sort()
{
	TimSort *sort = new TimSort(this->ARRAY->array, this->ARRAY->array_size);
	sort->tim_sort();
	delete (sort);
}

template <typename type_array>
void ALGOR::Comparative_Sorts<type_array>::Pancake_Sort()
{
	PancakeSort *sort = new PancakeSort(this->ARRAY->array, this->ARRAY->array_size);
	sort->pancake_sort();
	delete (sort);
}

template <typename type_array>
ALGOR::Comparative_Sorts<type_array>::BatcherOddEvenMergeSort::BatcherOddEvenMergeSort(type_array *array, asize_t asize)
	: Array(array), array_size(asize) {}

template <typename type_array>
void ALGOR::Comparative_Sorts<type_array>::BatcherOddEvenMergeSort::batcher_odd_even_merge_sort()
{
	for (asize_t p = 1; p < array_size; p *= 2)
	{
		for (asize_t k = p; k >= 1; k /= 2)
		{
			for (asize_t j = k % p; j <= array_size - 1 - k; j += 2 * k)
			{
				for (asize_t i = 0; i <= k - 1; i++)
				{
					if ((byte4_t)((i + j) / (p * 2)) == (byte4_t)((i + j + k) / (p * 2)))
					{
						if (Array[i + j] > Array[i + j + k])
						{
							swap(Array[i + j], Array[i + j + k]);
						}
					}
				}
			}
		}
	}
}

template <typename type_array>
ALGOR::Comparative_Sorts<type_array>::BitonicSorter::BitonicSorter(type_array *array, asize_t asize)
	: Array(array), array_size(asize) {}

template <typename type_array>
void ALGOR::Comparative_Sorts<type_array>::BitonicSorter::bitonic_sorter()
{
	for (asize_t k = 2; k <= array_size; k *= 2)
	{
		for (asize_t j = k / 2; j > 0; j /= 2)
		{
			for (asize_t i = 0; i < array_size; i++)
			{
				asize_t l = i ^ j;
				if (l > i)
				{
					if (
						(
							((i & k) == 0) && (Array[i] > Array[l])
						) || (
							((i & k) != 0) && (Array[i] < Array[l])
						)
					)
					{
						swap(Array[i], Array[l]);
					}
				}
			}
		}
	}
}

template <typename type_array>
ALGOR::Comparative_Sorts<type_array>::BogoSort::BogoSort(type_array *array, asize_t asize)
	: Array(array), array_size(asize) {}

template <typename type_array>
void ALGOR::Comparative_Sorts<type_array>::BogoSort::bogo_sort()
{
	while (!ArrayProcessing<type_array>::isOrderliness(Array, array_size))
	{
		Shuffle();
	}
}

template <typename type_array>
void ALGOR::Comparative_Sorts<type_array>::BogoSort::Shuffle()
{
	RANDOM::MersenneTwister RanGen(getMemoryCell(32));
	for (asize_t i = 0; i < array_size; i++)
	{
		swap(Array[i], Array[RanGen.IRandom(0, array_size - 1)]);
	}
}

template <typename type_array>
ALGOR::Comparative_Sorts<type_array>::BubbleSort::BubbleSort(type_array *array, asize_t asize)
	: Array(array), array_size(asize) {}

template <typename type_array>
void ALGOR::Comparative_Sorts<type_array>::BubbleSort::bubble_sort()
{
	for (asize_t i = 0; i < array_size; i++)
	{
		for (asize_t j = 0; j < array_size - 1; j++)
		{
			if (Array[j] > Array[j + 1])
			{
				swap(Array[j], Array[j + 1]);
			}
		}
	}
}

template <typename type_array>
ALGOR::Comparative_Sorts<type_array>::CocktailShakerSort::CocktailShakerSort(type_array *array, asize_t asize)
	: Array(array), array_size(asize) {}

template <typename type_array>
void ALGOR::Comparative_Sorts<type_array>::CocktailShakerSort::cocktail_shaker_sort()
{
	asize_t leftMark = 1, rightMark = array_size - 1;
	while (leftMark <= rightMark)
	{
		for (asize_t i = rightMark; i >= leftMark; i--)
		{
			if (Array[i - 1] > Array[i])
			{
				swap(Array[i], Array[i - 1]);
			}
		}
		leftMark++;
		for (asize_t i = leftMark; i <= rightMark; i++)
		{
			if (Array[i - 1] > Array[i])
			{
				swap(Array[i], Array[i - 1]);
			}
		}
		rightMark--;
	}
}

template <typename type_array>
ALGOR::Comparative_Sorts<type_array>::CombSort::CombSort(type_array *array, asize_t asize)
	: Array(array), array_size(asize) {}

template <class type_array>
void ALGOR::Comparative_Sorts<type_array>::CombSort::comb_sort()
{
	fbit64_t factor = 1.2473309;	//Фактор зменшення
	ubit32_t step = array_size - 1;	//Шаг

	while (step >= 1)
	{
		for (asize_t i = 0; i + step < array_size; i++)
		{
			if (Array[i] > Array[i + step])
			{
				swap(Array[i], Array[i + step]);
			}
		}
		step /= factor;
	}
}

template <typename type_array>
ALGOR::Comparative_Sorts<type_array>::CycleSort::CycleSort(type_array *array, asize_t asize)
	: Array(array), array_size(asize) {}

template <typename type_array>
void ALGOR::Comparative_Sorts<type_array>::CycleSort::cycle_sort()
{
	for (asize_t cycle_start = 0; cycle_start < array_size; cycle_start++)
	{
		type_array item = Array[cycle_start];

		asize_t pos = cycle_start;
		for (asize_t i = cycle_start + 1; i < array_size; i++)
		{
			if (Array[i] < item)
			{
				pos += 1;
			}
		}
		if (pos == cycle_start)
		{
			continue;
		}
		while (item == Array[pos])
		{
			pos += 1;
		}
		swap(Array[pos], item);

		while (pos != cycle_start)
		{
			pos = cycle_start;
			for (asize_t i = cycle_start + 1; i < array_size; i++)
			{
				if (Array[i] < item)
				{
					pos += 1;
				}
			}
			while (item == Array[pos])
			{
				pos += 1;
			}
			swap(Array[pos], item);
		}
	}
}

template <typename type_array>
ALGOR::Comparative_Sorts<type_array>::GnomeSort::GnomeSort(type_array *array, asize_t asize)
	: Array(array), array_size(asize) {}

template <typename type_array>
void ALGOR::Comparative_Sorts<type_array>::GnomeSort::gnome_sort()
{
	for (asize_t count = 0; count < array_size; count++)
	{
		asize_t i = 1, j = 2;

		while (i < array_size)
		{
			if (Array[i] > Array[i - 1])
			{
				i = j;
				j++;
			}
			else
			{
				swap(Array[i], Array[i - 1]);
				i--;
				if (i == 0)
				{
					i = j;
					j++;
				}
			}
		}
	}
}

template <typename type_array>
ALGOR::Comparative_Sorts<type_array>::HeapSort::HeapSort(type_array *array, asize_t asize)
	: Array(array), array_size(asize) {}

template <typename type_array>
void ALGOR::Comparative_Sorts<type_array>::HeapSort::heap_sort()
{
	for (byte4_t right = array_size / 2 - 1; right >= 0; right--)
	{
		heapify(Array, right, array_size);
	}
	for (byte4_t i = array_size - 1; i >= 0; i--)
	{
		swap(Array[0], Array[i]);
		heapify(Array, 0, i);
	}
}

template <typename type_array>
void ALGOR::Comparative_Sorts<type_array>::HeapSort::heapify(type_array *Array,
															 const asize_t &count,
															 const asize_t &array_size)
{
	asize_t left = 2 * count + 1, large = count, right = 2 * count + 2;
	if (left < array_size && Array[left] > Array[large])
	{
		large = left;
	}
	if (right < array_size && Array[right] > Array[large])
	{
		large = right;
	}
	if (large != count)
	{
		swap(Array[count], Array[large]);
		heapify(Array, large, array_size);
	}
}

template <typename type_array>
ALGOR::Comparative_Sorts<type_array>::InsertSort::InsertSort(type_array *array, asize_t asize)
	: Array(array), array_size(asize) {}

template <typename type_array>
void ALGOR::Comparative_Sorts<type_array>::InsertSort::insert_sort()
{
	for (asize_t i = 0; i < array_size; i++)
	{
		for (asize_t j = i; j > 0 && Array[j - 1] > Array[j]; j--)
		{
			swap(Array[j - 1], Array[j]);
		}
	}
}

template <class type_array>
ALGOR::Comparative_Sorts<type_array>::LibrarySort::LibrarySort(type_array *array, asize_t asize)
	: Array(array), array_size(asize) {}

template <class type_array>
void ALGOR::Comparative_Sorts<type_array>::LibrarySort::library_sort()
{
	initialization();
	while (index_pos < array_size)
	{
		binarysearch();
		insertion();
	}
	rebalancing();
	finalization();
}

template <class type_array>
void ALGOR::Comparative_Sorts<type_array>::LibrarySort::initialization()
{
	gaps = new type_array[array_size + 1]{0};
	for (asize_t i = 0; i < 2; i++)
	{
		library[i] = new type_array[array_size + 1]{0};
	}
	numbered = new bool[array_size + 1]{0};
	library[target_lib][0] = Array[0];
}

template <class type_array>
void ALGOR::Comparative_Sorts<type_array>::LibrarySort::binarysearch()
{
	insert = ArrayProcessing<type_array>::distance(
		library[target_lib],
		ArrayProcessing<type_array>::lower_bound(
			library[target_lib],
			library[target_lib] + lib_size,
			Array[index_pos]
		)
	);
}

template <class type_array>
void ALGOR::Comparative_Sorts<type_array>::LibrarySort::insertion()
{
	if (numbered[insert] == true)
	{
		asize_t prov_size = 0, next_target_lib = !target_lib;

		for (asize_t i = 0; i <= array_size; i++)
		{
			if (numbered[i] == true)
			{
				library[next_target_lib][prov_size] = gaps[i];
				prov_size++;
				numbered[i] = false;
			}
			if (i <= lib_size)
			{
				library[next_target_lib][prov_size] = library[target_lib][i];
				prov_size++;
			}
		}

		target_lib = next_target_lib;
		lib_size = prov_size - 1;
	}
	else
	{
		numbered[insert] = true;
		gaps[insert] = Array[index_pos];
		index_pos++;
	}
}

template <class type_array>
void ALGOR::Comparative_Sorts<type_array>::LibrarySort::rebalancing()
{
	for (asize_t i = 0; index_pos_for_output < array_size; i++)
	{
		if (numbered[i] == true)
		{
			Array[index_pos_for_output] = gaps[i];
			index_pos_for_output++;
		}

		if (i < lib_size)
		{
			Array[index_pos_for_output] = library[target_lib][i];
			index_pos_for_output++;
		}
	}
}

template <class type_array>
void ALGOR::Comparative_Sorts<type_array>::LibrarySort::finalization()
{
	delete[] numbered;
	for (asize_t i = 0; i < 2; i++)
	{
		delete[] library[i];
	}
	delete[] gaps;
}

template <typename type_array>
ALGOR::Comparative_Sorts<type_array>::MergeSort::MergeSort(type_array *array, asize_t asize)
	: Array(array), array_size(asize) {}

template <typename type_array>
void ALGOR::Comparative_Sorts<type_array>::MergeSort::merge_sort()
{
	recursive_merge_sort(0, array_size - 1);
}

template <typename type_array>
void ALGOR::Comparative_Sorts<type_array>::MergeSort::recursive_merge_sort(const asize_t &left_limit,
																		   const asize_t &right_limit)
{
	if (left_limit < right_limit)
	{
		asize_t middle = left_limit + (right_limit - left_limit) / 2;
		recursive_merge_sort(left_limit, middle);
		recursive_merge_sort(middle + 1, right_limit);
		merge(left_limit, middle, right_limit);
	}
}

template <typename type_array>
void ALGOR::Comparative_Sorts<type_array>::MergeSort::merge(const asize_t &left_limit,
															const asize_t &middle_limit,
															const asize_t &right_limit)
{
	asize_t start = left_limit, finish = middle_limit + 1;
	type_array *tempArray = new type_array[right_limit - left_limit + 1];
	for (asize_t i = left_limit; i <= right_limit; i++)
	{
		if ((start <= middle_limit) && ((finish > right_limit) || (Array[start] < Array[finish])))
		{
			tempArray[i - left_limit] = Array[start];
			start++;
		}
		else
		{
			tempArray[i - left_limit] = Array[finish];
			finish++;
		}
	}
	for (asize_t i = left_limit; i <= right_limit; i++)
	{
		Array[i] = tempArray[i - left_limit];
	}
	delete[] tempArray;
}

template <typename type_array>
ALGOR::Comparative_Sorts<type_array>::OddEvenSort::OddEvenSort(type_array *array, asize_t asize)
	: Array(array), array_size(asize) {}

template <typename type_array>
void ALGOR::Comparative_Sorts<type_array>::OddEvenSort::odd_even_sort()
{
	for (asize_t i = 0; i < array_size; i++)
	{
		asize_t j;
		i & 1 ? j = 2 : j = 1;
		for (; j < array_size; j += 2)
		{
			if (Array[j] < Array[j - 1])
			{
				swap(Array[j - 1], Array[j]);
			}
		}
	}
}

template <typename type_array>
ALGOR::Comparative_Sorts<type_array>::PancakeSort::PancakeSort(type_array *array, asize_t asize)
	: Array(array), array_size(asize) {}

template <typename type_array>
void ALGOR::Comparative_Sorts<type_array>::PancakeSort::pancake_sort()
{
	while (array_size > 1)
	{
		asize_t maxIndex = max_index();
		flip(maxIndex);
		flip(--array_size);
	}
}

template <typename type_array>
asize_t ALGOR::Comparative_Sorts<type_array>::PancakeSort::max_index()
{
	asize_t index = 0;
	for (asize_t i = 0; i < array_size; i++)
	{
		if (Array[index] < Array[i])
		{
			index = i;
		}
	}
	return index;
}

template <typename type_array>
void ALGOR::Comparative_Sorts<type_array>::PancakeSort::flip(asize_t index)
{
	asize_t left = 0;
	while (left < index)
	{
		swap(Array[left], Array[index]);
		index--;
		left++;
	}
}

template <typename type_array>
ALGOR::Comparative_Sorts<type_array>::PatienceSort::PatienceSort(type_array *array, asize_t asize)
	: Array(array), array_size(asize) {}

template <typename type_array>
void ALGOR::Comparative_Sorts<type_array>::PatienceSort::patience_sort()
{
	initialization();

	for (asize_t i = 0; i < array_size; i++)
	{
		for (asize_t j = 0; j < array_size; j++)
		{
			if (count[j] == 0 || (count[j] > 0 && decks[j][count[j] - 1] >= Array[i]))
			{
				decks[j][count[j]] = Array[i];
				count[j]++;
				break;
			}
		}
	}

	min = decks[0][count[0] - 1];
	pickedRow = 0;

	for (asize_t i = 0; i < array_size; i++)
	{
		for (asize_t j = 0; j < array_size; j++)
		{
			if (count[j] > 0 && decks[j][count[j] - 1] < min)
			{
				min = decks[j][count[j] - 1];
				pickedRow = j;
			}
		}
		sortedArr[i] = min;
		count[pickedRow]--;

		for (asize_t j = 0; j < array_size; j++)
		{
			if (count[j] > 0)
			{
				min = decks[j][count[j] - 1];
				pickedRow = j;
				break;
			}
		}
	}

	for (asize_t i = 0; i < array_size; i++)
	{
		Array[i] = sortedArr[i];
	}

	finalization();
}

template <typename type_array>
void ALGOR::Comparative_Sorts<type_array>::PatienceSort::initialization()
{
	count = new asize_t[array_size]{0};
	decks = new type_array *[array_size];
	for (asize_t i = 0; i < array_size; i++)
	{
		decks[i] = new type_array[array_size]{0};
	}
	sortedArr = new type_array[array_size]{0};
}

template <typename type_array>
void ALGOR::Comparative_Sorts<type_array>::PatienceSort::finalization()
{
	delete[] sortedArr;
	for (asize_t i = 0; i < array_size; i++)
	{
		delete[] decks[i];
	}
	delete[] decks;
	delete[] count;
}

template <typename type_array>
ALGOR::Comparative_Sorts<type_array>::QuickSort::QuickSort(type_array *array, asize_t asize)
	: Array(array), array_size(asize) {}

template <typename type_array>
void ALGOR::Comparative_Sorts<type_array>::QuickSort::quick_sort()
{
	recursive_quick_sort(0, array_size - 1);
}

template <typename type_array>
void ALGOR::Comparative_Sorts<type_array>::QuickSort::recursive_quick_sort(const byte4_t &left_limit,
																		   const byte4_t &right_limit)
{
	type_array middle = Array[(left_limit + right_limit) / 2];
	byte4_t start = left_limit, finish = right_limit;
	do
	{
		while (Array[start] < middle)
		{
			start++;
		}
		while (Array[finish] > middle)
		{
			finish--;
		}
		if (start <= finish)
		{
			swap(Array[start], Array[finish]);
			start++;
			finish--;
		}
	} while (start < finish);
	if (left_limit < finish)
	{
		recursive_quick_sort(left_limit, finish);
	}
	if (start < right_limit)
	{
		recursive_quick_sort(start, right_limit);
	}
}

template <typename type_array>
ALGOR::Comparative_Sorts<type_array>::SelectionSort::SelectionSort(type_array *array, asize_t asize)
	: Array(array), array_size(asize) {}

template <typename type_array>
void ALGOR::Comparative_Sorts<type_array>::SelectionSort::selection_sort()
{
	for (asize_t i = 0; i < array_size; i++)
	{
		asize_t min_index = i;
		for (asize_t j = i + 1; j < array_size; j++)
		{
			if (Array[j] < Array[min_index])
			{
				min_index = j;
			}
		}
		if (min_index != i)
		{
			swap(Array[i], Array[min_index]);
		}
	}
}

template <typename type_array>
ALGOR::Comparative_Sorts<type_array>::ShellSort::ShellSort(type_array *array, asize_t asize)
	: Array(array), array_size(asize) {}

template <typename type_array>
void ALGOR::Comparative_Sorts<type_array>::ShellSort::shell_sort()
{
	for (asize_t step = array_size / 2; step > 0; step /= 2)
	{
		for (asize_t i = step; i < array_size; i++)
		{
			for (byte4_t j = i - step; j >= 0 && Array[j] > Array[j + step]; j -= step)
			{
				swap(Array[j], Array[j + step]);
			}
		}
	}
}

template <typename type_array>
ALGOR::Comparative_Sorts<type_array>::SlowSort::SlowSort(type_array *array, asize_t asize)
	: Array(array), array_size(asize) {}

template <typename type_array>
void ALGOR::Comparative_Sorts<type_array>::SlowSort::slow_sort()
{
	recursive_slow_sort(0, array_size - 1);
}

template <typename type_array>
void ALGOR::Comparative_Sorts<type_array>::SlowSort::recursive_slow_sort(const asize_t &left_limit,
																		 const asize_t &right_limit)
{
	if (left_limit >= right_limit)
	{
		return;
	}
	byte4_t middle = (left_limit + right_limit) / 2;
	recursive_slow_sort(left_limit, middle);
	recursive_slow_sort(middle + 1, right_limit);
	if (Array[middle] > Array[right_limit])
	{
		swap(Array[middle], Array[right_limit]);
	}
	recursive_slow_sort(left_limit, right_limit - 1);
}

template <typename type_array>
ALGOR::Comparative_Sorts<type_array>::StoogeSort::StoogeSort(type_array *array, asize_t asize)
	: Array(array), array_size(asize) {}

template <typename type_array>
void ALGOR::Comparative_Sorts<type_array>::StoogeSort::stooge_sort()
{
	recursive_stooge_sort(0, array_size - 1);
}

template <typename type_array>
void ALGOR::Comparative_Sorts<type_array>::StoogeSort::recursive_stooge_sort(const asize_t &left_limit,
																			 const asize_t &right_limit)
{
	if (Array[left_limit] > Array[right_limit])
	{
		swap(Array[left_limit], Array[right_limit]);
	}
	if (left_limit + 1 >= right_limit)
	{
		return;
	}

	byte4_t k = (byte4_t)((right_limit - left_limit + 1) / 3);
	recursive_stooge_sort(left_limit, right_limit - k);
	recursive_stooge_sort(left_limit + k, right_limit);
	recursive_stooge_sort(left_limit, right_limit - k);
}

template <typename type_array>
ALGOR::Comparative_Sorts<type_array>::TimSort::TimSort(type_array *array, asize_t asize)
	: Array(array), array_size(asize) {}

template <typename type_array>
void ALGOR::Comparative_Sorts<type_array>::TimSort::tim_sort()
{
	for (asize_t i = 0; i < array_size; i += RUN)
	{
		insertionSort(i, minimum((i + 31), (array_size - 1)));
	}
	for (asize_t size = RUN; size < array_size; size *= 2)
	{
		for (asize_t left = 0; left < array_size; left += 2 * size)
		{
			asize_t middle = left + size - 1;
			asize_t right = minimum((left + 2 * size - 1), (array_size - 1));
			merge(left, middle, right);
		}
	}
}

template <typename type_array>
void ALGOR::Comparative_Sorts<type_array>::TimSort::insertionSort(asize_t left_limit,
																  asize_t right_limit)
{
	for (asize_t i = left_limit + 1; i <= right_limit; i++)
	{
		type_array temp = Array[i];
		byte4_t j = i - 1;
		while (Array[j] > temp && j >= (byte4_t)left_limit)
		{
			Array[j + 1] = Array[j];
			j--;
		}
		Array[j + 1] = temp;
	}
}

template <typename type_array>
void ALGOR::Comparative_Sorts<type_array>::TimSort::merge(asize_t left_limit,
														  asize_t middle,
														  asize_t right_limit)
{
	asize_t len1 = middle - left_limit + 1, len2 = right_limit - middle;
	asize_t *left = new asize_t[len1], *right = new asize_t[len2];

	for (asize_t i = 0; i < len1; i++)
	{
		left[i] = Array[left_limit + i];
	}
	for (asize_t i = 0; i < len2; i++)
	{
		right[i] = Array[middle + 1 + i];
	}

	asize_t i = 0, j = 0, k = left_limit;

	while (i < len1 && j < len2)
	{
		if (left[i] <= right[j])
		{
			Array[k] = left[i];
			i++;
		}
		else
		{
			Array[k] = right[j];
			j++;
		}
		k++;
	}
	while (i < len1)
	{
		Array[k] = left[i];
		k++;
		i++;
	}
	while (j < len2)
	{
		Array[k] = right[j];
		k++;
		j++;
	}

	delete[] left;
	delete[] right;
}

template <typename type_array>
ALGOR::Comparative_Sorts<type_array>::TreeSort::TreeSort(type_array *array, asize_t asize)
	: Array(array), array_size(asize) {}

template <typename type_array>
void ALGOR::Comparative_Sorts<type_array>::TreeSort::tree_sort()
{
	Tree *root = nullptr;
	root = insert(root, Array[0]);
	for (asize_t i = 1; i < array_size; i++)
	{
		insert(root, Array[i]);
	}
	asize_t index = 0;
	store(root, Array, index);
	delete (root);
}

template <typename type_array>
typename ALGOR::Comparative_Sorts<type_array>::TreeSort::Tree
	*ALGOR::Comparative_Sorts<type_array>::TreeSort::newnode(type_array key)
{
	Tree *temp = new Tree;
	temp->data = key;
	temp->left = nullptr;
	temp->right = nullptr;
	return temp;
}

template <typename type_array>
typename ALGOR::Comparative_Sorts<type_array>::TreeSort::Tree
	*ALGOR::Comparative_Sorts<type_array>::TreeSort::insert(Tree *node,
															type_array key)
{
	if (node == nullptr)
	{
		return newnode(key);
	}
	if (key < node->data)
	{
		node->left = insert(node->left, key);
	}
	else
	{
		node->right = insert(node->right, key);
	}
	return node;
}

template <typename type_array>
void ALGOR::Comparative_Sorts<type_array>::TreeSort::store(Tree *root,
														   type_array *Array,
														   asize_t &index)
{
	if (root != nullptr)
	{
		store(root->left, Array, index);
		Array[index++] = root->data;
		store(root->right, Array, index);
	}
}

ALGOR::Distribution_Sorts::Distribution_Sorts(Array<byte8_t> *&Array)
	: ArrayBase<byte8_t>(Array) {}

void ALGOR::Distribution_Sorts::AmericanFlag_Sort()
{
	AmericanFlagSort *sort = new AmericanFlagSort(this->ARRAY->array, this->ARRAY->array_size);
	sort->american_flag_sort();
	delete (sort);
}

void ALGOR::Distribution_Sorts::Bead_Sort()
{
	BeadSort *sort = new BeadSort(this->ARRAY->array, this->ARRAY->array_size);
	sort->bead_sort();
	delete (sort);
}

void ALGOR::Distribution_Sorts::Bucket_Sort()
{
	BucketSort *sort = new BucketSort(this->ARRAY->array, this->ARRAY->array_size);
	sort->bucket_sort();
	delete (sort);
}

void ALGOR::Distribution_Sorts::Counting_Sort()
{
	CountingSort *sort = new CountingSort(this->ARRAY->array, this->ARRAY->array_size);
	sort->counting_sort();
	delete (sort);
}

void ALGOR::Distribution_Sorts::Interpolation_Sort()
{
	InterpolationSort *sort = new InterpolationSort(this->ARRAY->array, this->ARRAY->array_size);
	sort->interpolation_sort();
	delete (sort);
}

void ALGOR::Distribution_Sorts::Pigeonhole_Sort()
{
	PigeonholeSort *sort = new PigeonholeSort(this->ARRAY->array, this->ARRAY->array_size);
	sort->pigeonhole_sort();
	delete (sort);
}

void ALGOR::Distribution_Sorts::Radix_Sort()
{
	RadixSort *sort = new RadixSort(this->ARRAY->array, this->ARRAY->array_size);
	sort->radix_sort();
	delete (sort);
}

void ALGOR::Distribution_Sorts::Flash_Sort()
{
	FlashSort *sort = new FlashSort(this->ARRAY->array, this->ARRAY->array_size);
	sort->flash_sort();
	delete (sort);
}

ALGOR::Distribution_Sorts::AmericanFlagSort::AmericanFlagSort(byte8_t *array, asize_t asize)
	: Array(array), array_size(asize) {}

void ALGOR::Distribution_Sorts::AmericanFlagSort::american_flag_sort()
{
	byte8_t max = 1;
	for (byte8_t i = 0; i < getMaxNumberOfDigits() - 1; i++)
	{
		max *= 10;
	}
	recursive_american_flag_sort(0, (byte8_t)array_size, max);
}

void ALGOR::Distribution_Sorts::AmericanFlagSort::recursive_american_flag_sort(byte8_t start,
																			   byte8_t length,
																			   byte8_t divisor)
{
	byte8_t *count = new byte8_t[NUMBER_OF_BUCKETS]{0};
	byte8_t digit = 0;

	for (byte8_t i = start; i < length; i++)
	{
		byte8_t array_digit = Array[i];
		digit = getDigit(array_digit, divisor);
		count[digit]++;
	}

	byte8_t *offset = new byte8_t[NUMBER_OF_BUCKETS];
	offset[0] = start + 0;
	for (byte8_t i = 1; i < NUMBER_OF_BUCKETS; i++)
	{
		offset[i] = count[i - 1] + offset[i - 1];
	}

	for (byte8_t bucket = 0; bucket < NUMBER_OF_BUCKETS; bucket++)
	{
		while (count[bucket] > 0)
		{
			byte8_t origin = offset[bucket];
			byte8_t from = origin;
			byte8_t num = Array[from];
			Array[from] = -1;
			do
			{
				digit = getDigit(num, divisor);
				byte8_t to = offset[digit]++;
				count[digit]--;
				byte8_t temp = Array[to];
				Array[to] = num;
				num = temp;
				from = to;
			} while (from != origin);
		}
	}
	if (divisor > 1)
	{
		for (byte8_t i = 0; i < NUMBER_OF_BUCKETS; i++)
		{
			byte8_t begin = (i > 0) ? offset[i - 1] : start;
			byte8_t end = offset[i];
			if (end - begin > 1)
			{
				recursive_american_flag_sort(begin, end, divisor / 10);
			}
		}
	}
}

byte8_t ALGOR::Distribution_Sorts::AmericanFlagSort::getMaxNumberOfDigits()
{
	byte8_t count = 1;
	byte8_t value = ArrayProcessing<byte8_t>::maximum(Array, array_size);
	while (true)
	{
		value /= 10;
		if (value != 0)
		{
			count++;
		}
		else
		{
			break;
		}
	}
	return count;
}

byte8_t ALGOR::Distribution_Sorts::AmericanFlagSort::getDigit(byte8_t integer,
															  byte8_t divisor)
{
	return (integer / divisor) % 10;
}

ALGOR::Distribution_Sorts::BeadSort::BeadSort(byte8_t *array, asize_t asize)
	: Array(array), array_size(asize) {}

void ALGOR::Distribution_Sorts::BeadSort::bead_sort()
{
	max = ArrayProcessing<byte8_t>::maximum(Array, array_size);
	beads = new ubit8_t[max * array_size]{0};

	for (asize_t i = 0; i < array_size; i++)
	{
		for (byte8_t j = 0; j < Array[i]; j++)
		{
			beads[i * max + j] = 1;
		}
	}
	for (byte8_t j = 0; j < max; j++)
	{
		byte8_t sum = 0;
		for (asize_t i = 0; i < array_size; i++)
		{
			sum += beads[i * max + j];
			beads[i * max + j] = 0;
		}
		for (asize_t i = array_size - sum; i < array_size; i++)
		{
			beads[i * max + j] = 1;
		}
	}
	for (asize_t i = 0; i < array_size; i++)
	{
		byte8_t j = 0;
		for (; j < max && beads[i * max + j]; j++)
			;
		Array[i] = j;
	}

	delete[] beads;
}

ALGOR::Distribution_Sorts::BucketSort::BucketSort(byte8_t *array, asize_t asize)
	: Array(array), array_size(asize) {}

void ALGOR::Distribution_Sorts::BucketSort::bucket_sort()
{
	min = ArrayProcessing<byte8_t>::minimum(Array, array_size);
	max = ArrayProcessing<byte8_t>::maximum(Array, array_size);
	range = (max - min) / (byte8_t)array_size;
	range++;

	bucket = new byte8_t *[array_size];
	for (asize_t i = 0; i < array_size; i++)
	{
		bucket[i] = new byte8_t[1];
		bucket[i][0] = 1;
	}

	for (asize_t i = 0; i < array_size; i++)
	{
		bucket_index = asize_t((Array[i] - min) / range);
		if (bucket_index == array_size)
		{
			bucket_index--;
		}
		ArrayProcessing<byte8_t>::addElement(
			bucket[bucket_index],
			(asize_t &)bucket[bucket_index][0],
			Array[i],
			bucket[bucket_index][0]
		);
	}

	for (asize_t i = 0; i < array_size; i++)
	{
		if (bucket[i][0] > 2)
		{
			CountingSort *sorter = new CountingSort(bucket[i] + 1, bucket[i][0] - 1);
			sorter->counting_sort();
			delete (sorter);
		}
	}

	for (asize_t i = 0; i < array_size; i++)
	{
		for (asize_t j = 1; j < (asize_t)bucket[i][0]; j++)
		{
			Array[array_index++] = bucket[i][j];
		}
	}

	for (asize_t i = 0; i < array_size; i++)
	{
		delete[] bucket[i];
	}
	delete[] bucket;
}

ALGOR::Distribution_Sorts::CountingSort::CountingSort(byte8_t *array, asize_t asize)
	: Array(array), array_size(asize) {}

void ALGOR::Distribution_Sorts::CountingSort::counting_sort()
{
	min = ArrayProcessing<byte8_t>::minimum(Array, array_size);
	max = ArrayProcessing<byte8_t>::maximum(Array, array_size);
	tempArray = new byte8_t[max - min + 1];
	for (byte8_t i = 0; i < max - min + 1; i++)
	{
		tempArray[i] = 0;
	}
	for (asize_t i = 0; i < array_size; i++)
	{
		tempArray[Array[i] - min] = tempArray[Array[i] - min] + 1;
	}
	for (byte8_t i = 0, j = min; j < max + 1; j++)
	{
		while (tempArray[j - min] != 0)
		{
			Array[i] = j;
			tempArray[j - min]--;
			i++;
		}
	}
	delete[] tempArray;
}

ALGOR::Distribution_Sorts::FlashSort::FlashSort(byte8_t *array, asize_t asize)
	: Array(array), array_size(asize) {}

void ALGOR::Distribution_Sorts::FlashSort::flash_sort()
{
	const asize_t middle = (byte8_t)(0.45 * array_size);

	//Так як m дорівнює розміру, помноженому на 0.45 - то, виходячи з
	//розрахунків, m == 0 тільки при розмірі, рівному 2, 1 чи 0. Якщо
	//розмір == 2 та перший елемент більше другого (так як сортування
	//іде в напрямку збільшення, тому перший елемент має бути найменшим),
	//тоді необхідно змінити ці два елементи місцями - це і є все
	//сортування; інакше (тобто якщо розмір == 1 чи масив з 2 елементів
	//відсортовано (перший елемент менше другого)) - відразу завершати
	//сортування, так як там нічого сортувати. Розмір не може
	//дорівнювати 0, так як конструктор класу викликає верифікацію, де
	//перевіряється масив на пустотність. При всіх інших розмірах
	//(тобто >= 3) m буде дорівнювати 1 чи більше, а тому до k не зможе
	//потрапити значення -1 й викликати помилку.
	if (middle == 0)
	{
		if (array_size == 2 && Array[0] > Array[1])
		{
			swap(Array[0], Array[1]);
		}
		return;
	}

	L = new byte8_t[middle];

	for (asize_t i = 0; i < array_size; i++)
	{
		if (Array[i] < Array[min])
		{
			min = i;
		}
		if (Array[i] > Array[max])
		{
			max = i;
		}
	}

	//Якщо всі елементи мають одне значення, то при знаходженні
	//константи c1 виникне ділення на 0, а тому треба завчасно робити
	//перевірку і в випадку рівності значень - кидати виключення.
	if (Array[min] == Array[max])
	{
		throw EXCEPTION_SET::division_by_zero();
	}

	const asize_t c1 = (middle - 1) / (Array[max] - Array[min]);

	for (asize_t i = 0; i < middle; i++)
	{
		L[i] = 0;
	}
	for (asize_t i = 0; i < array_size; ++i)
	{
		++L[c1 * (Array[i] - min)];
	}
	for (asize_t i = 1; i < middle; ++i)
	{
		L[i] = L[i] + L[i - 1];
	}

	swap(Array[max], Array[0]);

	k = middle - 1;

	while (move < array_size - 1)
	{
		while ((byte8_t)j > L[k] - 1)
		{
			++j;
			k = c1 * (Array[j] - min);
		}
		flash = Array[j];
		while ((byte8_t)j != L[k])
		{
			k = c1 * (flash - Array[min]);
			swap(Array[L[k] - 1], flash);
			L[k]--;
			move++;
		}
	}

	for (j = 1; j < array_size; j++)
	{
		flash = Array[j];
		byte8_t i = j - 1;
		while (i >= 0 && Array[i] > flash)
		{
			Array[i + 1] = Array[i];
			i--;
		}
		Array[i + 1] = flash;
	}
}

ALGOR::Distribution_Sorts::InterpolationSort::InterpolationSort(byte8_t *array, asize_t asize)
	: Array(array), array_size(asize) {}

void ALGOR::Distribution_Sorts::InterpolationSort::interpolation_sort()
{
	getMin();

	if (index_min != 0)
	{
		Array[index_min] = Array[0];
		Array[0] = nArray_min;
	}

	if (array_size >= MIN_SORTABLE_LENGTH)
	{
		getMax();

		ifac = (nArray_max - nArray_min) / (array_size - 1);

		if (ifac <= 0)
		{
			ifac = 1;
		}
		else
		{
			while (((nArray_max - nArray_min) / ifac) > ((byte8_t)array_size - 1))
			{
				ifac++;
			}
		}

		space = new byte8_t[2 * array_size + 1];

		if (!space)
		{
			return;
		}

		cmp_index = space;
		cum = space + array_size;
		hist = cum + 1;
		sorted = hist;

		for (asize_t i = 0; i <= array_size; i++)
		{
			cum[i] = 0;
		}

		for (byte4_t i = array_size; --i >= 0;)
		{
			hist[cmp_index[i] = (Array[i] - nArray_min) / ifac] += 1;
			ComplexityCount++;
		}

		for (asize_t i = 1; i < array_size; i++)
		{
			cum[i] += cum[i - 1];
			ComplexityCount++;
		}

		for (asize_t i = 0; i < array_size; i++)
		{
			cmp_index[i] = cum[cmp_index[i]]++;
			ComplexityCount++;
		}

		for (asize_t i = array_size; i > 0; i--)
		{
			sorted[cmp_index[i - 1]] = Array[i - 1];
			ComplexityCount++;
		}

		ArrayProcessing<byte8_t>::copy(Array, sorted, array_size);

		delete[] space;
	}

	for (asize_t i = 1; i < array_size; i++)
	{
		ComplexityCount++;

		if (Array[i] >= Array[i - 1])
		{
			continue;
		}

		temp = Array[i];
		Array[i] = Array[i - 1];

		asize_t j;
		for (j = i - 2; temp < Array[j]; j--)
		{
			Array[j + 1] = Array[j];
		}
		Array[j + 1] = temp;
	}
}

void ALGOR::Distribution_Sorts::InterpolationSort::getMin()
{
	nArray_min = Array[0];
	for (asize_t i = 1; i < array_size; i++)
	{
		if (nArray_min > Array[i])
		{
			nArray_min = Array[i];
			index_min = i;
		}
	}
}

void ALGOR::Distribution_Sorts::InterpolationSort::getMax()
{
	nArray_max = Array[0];
	for (asize_t i = 1; i < array_size; i++)
	{
		if (nArray_max < Array[i])
		{
			nArray_max = Array[i];
		}
	}
}

ALGOR::Distribution_Sorts::PigeonholeSort::PigeonholeSort(byte8_t *array, asize_t asize)
	: Array(array), array_size(asize) {}

void ALGOR::Distribution_Sorts::PigeonholeSort::pigeonhole_sort()
{
	min = ArrayProcessing<byte8_t>::minimum(Array, array_size);
	max = ArrayProcessing<byte8_t>::maximum(Array, array_size);
	range = (asize_t)max - (asize_t)min + 1;

	hole = new byte8_t *[range];
	for (asize_t i = 0; i < range; i++)
	{
		hole[i] = new byte8_t[1];
		hole[i][0] = 1;
	}

	for (asize_t i = 0; i < array_size; i++)
	{
		ArrayProcessing<byte8_t>::addElement(
			hole[Array[i] - min],
			(asize_t &)hole[Array[i] - min][0],
			Array[i],
			hole[Array[i] - min][0]
		);
	}
	for (asize_t i = 0; i < range; i++)
	{
		for (asize_t j = 1; j < (asize_t)hole[i][0]; j++)
		{
			Array[count] = hole[i][j];
			count++;
		}
	}

	for (asize_t i = 0; i < range; i++)
	{
		delete[] hole[i];
	}
	delete[] hole;
}

ALGOR::Distribution_Sorts::RadixSort::RadixSort(byte8_t *array, asize_t asize)
	: Array(array), array_size(asize) {}

void ALGOR::Distribution_Sorts::RadixSort::radix_sort()
{
	max = ArrayProcessing<byte8_t>::maximum(Array, array_size);
	tempArray = new byte8_t[array_size];
	bucket = new byte8_t[bit];
	while (max / exp > 0)
	{
		for (byte4_t i = 0; i < bit; i++)
		{
			bucket[i] = 0;
		}
		for (asize_t i = 0; i < array_size; i++)
		{
			bucket[(Array[i] / exp) % bit]++;
		}
		for (byte4_t i = 1; i < bit; i++)
		{
			bucket[i] += bucket[i - 1];
		}
		for (byte4_t i = array_size - 1; i >= 0; i--)
		{
			current = (Array[i] % (exp * bit)) / exp;
			bucket[current]--;
			tempArray[bucket[current]] = Array[i];
		}
		for (asize_t i = 0; i < array_size; i++)
		{
			Array[i] = tempArray[i];
		}
		exp *= bit;
	}
	delete[] bucket;
	delete[] tempArray;
}

template class ALGOR::Comparative_Sorts<sbit8_t>;
template class ALGOR::Comparative_Sorts<sbit16_t>;
template class ALGOR::Comparative_Sorts<sbit32_t>;
template class ALGOR::Comparative_Sorts<sbit64_t>;
template class ALGOR::Comparative_Sorts<ubit8_t>;
template class ALGOR::Comparative_Sorts<ubit16_t>;
template class ALGOR::Comparative_Sorts<ubit32_t>;
template class ALGOR::Comparative_Sorts<ubit64_t>;
template class ALGOR::Comparative_Sorts<fbit32_t>;
template class ALGOR::Comparative_Sorts<fbit64_t>;
template class ALGOR::Comparative_Sorts<fbit128_t>;
