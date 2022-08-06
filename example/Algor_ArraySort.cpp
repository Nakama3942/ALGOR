#include <iostream>
using std::cin;
using std::cout;

#include "../src/ALGOR.hpp"

int main()
{
	ALGOR::Array<long long> *arr = ALGOR::create_struct(12);
	generate_struct(arr, 1, 100);
	
	//! [Comparative_Sorts constructor]
	Comparative_Sorts<long long> *sort = new Comparative_Sorts<long long>(arr);
	//! [Comparative_Sorts constructor]
	//! [Comparative_Sorts Bubble_Sort]
	sort->Bubble_Sort();
	//! [Comparative_Sorts Bubble_Sort]
	//! [Comparative_Sorts Cocktail_Shaker_Sort]
	sort->Cocktail_Shaker_Sort();
	//! [Comparative_Sorts Cocktail_Shaker_Sort]
	//! [Comparative_Sorts Odd_Even_Sort]
	sort->Odd_Even_Sort();
	//! [Comparative_Sorts Odd_Even_Sort]
	//! [Comparative_Sorts Comb_Sort]
	sort->Comb_Sort();
	//! [Comparative_Sorts Comb_Sort]
	//! [Comparative_Sorts Gnome_Sort]
	sort->Gnome_Sort();
	//! [Comparative_Sorts Gnome_Sort]
	//! [Comparative_Sorts Quick_Sort]
	sort->Quick_Sort();
	//! [Comparative_Sorts Quick_Sort]
	//! [Comparative_Sorts Slow_Sort]
	sort->Slow_Sort();
	//! [Comparative_Sorts Slow_Sort]
	//! [Comparative_Sorts Stooge_Sort]
	sort->Stooge_Sort();
	//! [Comparative_Sorts Stooge_Sort]
	//! [Comparative_Sorts Bogo_Sort]
	sort->Bogo_Sort();
	//! [Comparative_Sorts Bogo_Sort]
	//! [Comparative_Sorts Selection_Sort]
	sort->Selection_Sort();
	//! [Comparative_Sorts Selection_Sort]
	//! [Comparative_Sorts Heap_Sort]
	sort->Heap_Sort();
	//! [Comparative_Sorts Heap_Sort]
	//! [Comparative_Sorts Cycle_Sort]
	sort->Cycle_Sort();
	//! [Comparative_Sorts Cycle_Sort]
	//! [Comparative_Sorts Insert_Sort]
	sort->Insert_Sort();
	//! [Comparative_Sorts Insert_Sort]
	//! [Comparative_Sorts Shell_Sort]
	sort->Shell_Sort();
	//! [Comparative_Sorts Shell_Sort]
	//! [Comparative_Sorts Tree_Sort]
	sort->Tree_Sort();
	//! [Comparative_Sorts Tree_Sort]
	//! [Comparative_Sorts Library_Sort]
	sort->Library_Sort();
	//! [Comparative_Sorts Library_Sort]
	//! [Comparative_Sorts Patience_Sort]
	sort->Patience_Sort();
	//! [Comparative_Sorts Patience_Sort]
	//! [Comparative_Sorts Merge_Sort]
	sort->Merge_Sort();
	//! [Comparative_Sorts Merge_Sort]
	//! [Comparative_Sorts Bitonic_Sorter]
	sort->Bitonic_Sorter();
	//! [Comparative_Sorts Bitonic_Sorter]
	//! [Comparative_Sorts Batcher_OddEven_MergeSort]
	sort->Batcher_OddEven_MergeSort();
	//! [Comparative_Sorts Batcher_OddEven_MergeSort]
	//! [Comparative_Sorts Tim_Sort]
	sort->Tim_Sort();
	//! [Comparative_Sorts Tim_Sort]
	//! [Comparative_Sorts Pancake_Sort]
	sort->Pancake_Sort();
	//! [Comparative_Sorts Pancake_Sort]
	
	//! [Comparative_Sorts BatcherOddEvenMergeSort]
	Comparative_Sorts<long long>::BatcherOddEvenMergeSort *sort;
	sort = new Comparative_Sorts<long long>::BatcherOddEvenMergeSort(ArrayStruct->array, ArrayStruct->array_size);
	sort->batcher_odd_even_merge_sort();
	//! [Comparative_Sorts BatcherOddEvenMergeSort]
	
	//! [Comparative_Sorts BitonicSorter]
	Comparative_Sorts<long long>::BitonicSorter *sort;
	sort = new Comparative_Sorts<long long>::BitonicSorter(ArrayStruct->array, ArrayStruct->array_size);
	sort->bitonic_sorter();
	//! [Comparative_Sorts BitonicSorter]
	
	//! [Comparative_Sorts BogoSort]
	Comparative_Sorts<long long>::BogoSort *sort;
	sort = new Comparative_Sorts<long long>::BogoSort(ArrayStruct->array, ArrayStruct->array_size);
	sort->bogo_sort();
	//! [Comparative_Sorts BogoSort]
	
	//! [Comparative_Sorts BubbleSort]
	Comparative_Sorts<long long>::BubbleSort *sort;
	sort = new Comparative_Sorts<long long>::BubbleSort(ArrayStruct->array, ArrayStruct->array_size);
	sort->bubble_sort();
	//! [Comparative_Sorts BubbleSort]
	
	//! [Comparative_Sorts CocktailShakerSort]
	Comparative_Sorts<long long>::CocktailShakerSort *sort;
	sort = new Comparative_Sorts<long long>::CocktailShakerSort(ArrayStruct->array, ArrayStruct->array_size);
	sort->cocktail_shaker_sort();
	//! [Comparative_Sorts CocktailShakerSort]
	
	//! [Comparative_Sorts CombSort]
	Comparative_Sorts<long long>::CombSort *sort;
	sort = new Comparative_Sorts<long long>::CombSort(ArrayStruct->array, ArrayStruct->array_size);
	sort->comb_sort();
	//! [Comparative_Sorts CombSort]
	
	//! [Comparative_Sorts CycleSort]
	Comparative_Sorts<long long>::CycleSort *sort;
	sort = new Comparative_Sorts<long long>::CycleSort(ArrayStruct->array, ArrayStruct->array_size);
	sort->cycle_sort();
	//! [Comparative_Sorts CycleSort]
	
	//! [Comparative_Sorts GnomeSort]
	Comparative_Sorts<long long>::GnomeSort *sort;
	sort = new Comparative_Sorts<long long>::GnomeSort(ArrayStruct->array, ArrayStruct->array_size);
	sort->gnome_sort();
	//! [Comparative_Sorts GnomeSort]
	
	//! [Comparative_Sorts HeapSort]
	Comparative_Sorts<long long>::HeapSort *sort;
	sort = new Comparative_Sorts<long long>::HeapSort(ArrayStruct->array, ArrayStruct->array_size);
	sort->heap_sort();
	//! [Comparative_Sorts HeapSort]
	
	//! [Comparative_Sorts InsertSort]
	Comparative_Sorts<long long>::InsertSort *sort;
	sort = new Comparative_Sorts<long long>::InsertSort(ArrayStruct->array, ArrayStruct->array_size);
	sort->insert_sort();
	//! [Comparative_Sorts InsertSort]
	
	//! [Comparative_Sorts LibrarySort]
	Comparative_Sorts<long long>::LibrarySort *sort;
	sort = new Comparative_Sorts<long long>::LibrarySort(ArrayStruct->array, ArrayStruct->array_size);
	sort->library_sort();
	//! [Comparative_Sorts LibrarySort]
	
	//! [Comparative_Sorts MergeSort]
	Comparative_Sorts<long long>::MergeSort *sort;
	sort = new Comparative_Sorts<long long>::MergeSort(ArrayStruct->array, ArrayStruct->array_size);
	sort->merge_sort();
	//! [Comparative_Sorts MergeSort]
	
	//! [Comparative_Sorts OddEvenSort]
	Comparative_Sorts<long long>::OddEvenSort *sort;
	sort = new Comparative_Sorts<long long>::OddEvenSort(ArrayStruct->array, ArrayStruct->array_size);
	sort->odd_even_sort();
	//! [Comparative_Sorts OddEvenSort]
	
	//! [Comparative_Sorts PancakeSort]
	Comparative_Sorts<long long>::PancakeSort *sort;
	sort = new Comparative_Sorts<long long>::PancakeSort(ArrayStruct->array, ArrayStruct->array_size);
	sort->batcher_odd_even_merge_sort();
	//! [Comparative_Sorts PancakeSort]
	
	//! [Comparative_Sorts PatienceSort]
	Comparative_Sorts<long long>::PatienceSort *sort;
	sort = new Comparative_Sorts<long long>::PatienceSort(ArrayStruct->array, ArrayStruct->array_size);
	sort->patience_sort();
	//! [Comparative_Sorts PatienceSort]
	
	//! [Comparative_Sorts QuickSort]
	Comparative_Sorts<long long>::QuickSort *sort;
	sort = new Comparative_Sorts<long long>::QuickSort(ArrayStruct->array, ArrayStruct->array_size);
	sort->quick_sort();
	//! [Comparative_Sorts QuickSort]
	
	//! [Comparative_Sorts SelectionSort]
	Comparative_Sorts<long long>::SelectionSort *sort;
	sort = new Comparative_Sorts<long long>::SelectionSort(ArrayStruct->array, ArrayStruct->array_size);
	sort->selection_sort();
	//! [Comparative_Sorts SelectionSort]
	
	//! [Comparative_Sorts ShellSort]
	Comparative_Sorts<long long>::ShellSort *sort;
	sort = new Comparative_Sorts<long long>::ShellSort(ArrayStruct->array, ArrayStruct->array_size);
	sort->shell_sort();
	//! [Comparative_Sorts ShellSort]
	
	//! [Comparative_Sorts SlowSort]
	Comparative_Sorts<long long>::SlowSort *sort;
	sort = new Comparative_Sorts<long long>::SlowSort(ArrayStruct->array, ArrayStruct->array_size);
	sort->slow_sort();
	//! [Comparative_Sorts SlowSort]
	
	//! [Comparative_Sorts StoogeSort]
	Comparative_Sorts<long long>::StoogeSort *sort;
	sort = new Comparative_Sorts<long long>::StoogeSort(ArrayStruct->array, ArrayStruct->array_size);
	sort->stooge_sort();
	//! [Comparative_Sorts StoogeSort]
	
	//! [Comparative_Sorts TimSort]
	Comparative_Sorts<long long>::TimSort *sort;
	sort = new Comparative_Sorts<long long>::TimSort(ArrayStruct->array, ArrayStruct->array_size);
	sort->tim_sort();
	//! [Comparative_Sorts TimSort]
	
	//! [Comparative_Sorts TreeSort]
	Comparative_Sorts<long long>::TreeSort *sort;
	sort = new Comparative_Sorts<long long>::TreeSort(ArrayStruct->array, ArrayStruct->array_size);
	sort->tree_sort();
	//! [Comparative_Sorts TreeSort]

	cin.get();
	return 0;
}