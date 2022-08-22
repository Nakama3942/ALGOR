#include <iostream>

#include "../include/ALGOR.hpp"
using namespace ALGOR;

int main()
{
	ALGOR::Array<long> *arr = ALGOR::create_struct<long>(16);
	//! [Comparative_Sorts constructor]
	ALGOR::Comparative_Sorts<long> *comp_sort = new ALGOR::Comparative_Sorts<long>(arr);
	//! [Comparative_Sorts constructor]

	ALGOR::generate_struct<long>(arr, 1, 100);
	//! [Comparative_Sorts Bubble_Sort]
	comp_sort->Bubble_Sort();
	// The data is not taken from the output, but from the debugger console
	// Before sorting
	// arr->array = {20 86 29 29 37 73 57 7 57 86 37 89 29 77 11 78}
	// After sorting
	// arr->array = {7 11 20 29 29 29 37 37 57 57 73 77 78 86 86 89}
	//! [Comparative_Sorts Bubble_Sort]

	ALGOR::generate_struct<long>(arr, 1, 100);
	//! [Comparative_Sorts Cocktail_Shaker_Sort]
	comp_sort->Cocktail_Shaker_Sort();
	// The data is not taken from the output, but from the debugger console
	// Before sorting
	// arr->array = {20 86 29 29 37 73 57 7 57 86 37 89 29 77 11 78}
	// After sorting
	// arr->array = {7 11 20 29 29 29 37 37 57 57 73 77 78 86 86 89}
	//! [Comparative_Sorts Cocktail_Shaker_Sort]

	ALGOR::generate_struct<long>(arr, 1, 100);
	//! [Comparative_Sorts Odd_Even_Sort]
	comp_sort->Odd_Even_Sort();
	// The data is not taken from the output, but from the debugger console
	// Before sorting
	// arr->array = {20 86 29 29 37 73 57 7 57 86 37 89 29 77 11 78}
	// After sorting
	// arr->array = {7 11 20 29 29 29 37 37 57 57 73 77 78 86 86 89}
	//! [Comparative_Sorts Odd_Even_Sort]

	ALGOR::generate_struct<long>(arr, 1, 100);
	//! [Comparative_Sorts Comb_Sort]
	comp_sort->Comb_Sort();
	// The data is not taken from the output, but from the debugger console
	// Before sorting
	// arr->array = {20 86 29 29 37 73 57 7 57 86 37 89 29 77 11 78}
	// After sorting
	// arr->array = {7 11 20 29 29 29 37 37 57 57 73 77 78 86 86 89}
	//! [Comparative_Sorts Comb_Sort]

	ALGOR::generate_struct<long>(arr, 1, 100);
	//! [Comparative_Sorts Gnome_Sort]
	comp_sort->Gnome_Sort();
	// The data is not taken from the output, but from the debugger console
	// Before sorting
	// arr->array = {20 86 29 29 37 73 57 7 57 86 37 89 29 77 11 78}
	// After sorting
	// arr->array = {7 11 20 29 29 29 37 37 57 57 73 77 78 86 86 89}
	//! [Comparative_Sorts Gnome_Sort]

	ALGOR::generate_struct<long>(arr, 1, 100);
	//! [Comparative_Sorts Quick_Sort]
	comp_sort->Quick_Sort();
	// The data is not taken from the output, but from the debugger console
	// Before sorting
	// arr->array = {20 86 29 29 37 73 57 7 57 86 37 89 29 77 11 78}
	// After sorting
	// arr->array = {7 11 20 29 29 29 37 37 57 57 73 77 78 86 86 89}
	//! [Comparative_Sorts Quick_Sort]

	ALGOR::generate_struct<long>(arr, 1, 100);
	//! [Comparative_Sorts Slow_Sort]
	comp_sort->Slow_Sort();
	// The data is not taken from the output, but from the debugger console
	// Before sorting
	// arr->array = {20 86 29 29 37 73 57 7 57 86 37 89 29 77 11 78}
	// After sorting
	// arr->array = {7 11 20 29 29 29 37 37 57 57 73 77 78 86 86 89}
	//! [Comparative_Sorts Slow_Sort]

	ALGOR::generate_struct<long>(arr, 1, 100);
	//! [Comparative_Sorts Stooge_Sort]
	comp_sort->Stooge_Sort();
	// The data is not taken from the output, but from the debugger console
	// Before sorting
	// arr->array = {20 86 29 29 37 73 57 7 57 86 37 89 29 77 11 78}
	// After sorting
	// arr->array = {7 11 20 29 29 29 37 37 57 57 73 77 78 86 86 89}
	//! [Comparative_Sorts Stooge_Sort]

	ALGOR::generate_struct<long>(arr, 1, 100);
	//! [Comparative_Sorts Bogo_Sort]
	//sort->Bogo_Sort(); // It is better not to use it
	// The data is not taken from the output, but from the debugger console
	// Before sorting
	// arr->array = {34 33 21}
	// After sorting
	// arr->array = {21 33 34}
	//! [Comparative_Sorts Bogo_Sort]

	ALGOR::generate_struct<long>(arr, 1, 100);
	//! [Comparative_Sorts Selection_Sort]
	comp_sort->Selection_Sort();
	// The data is not taken from the output, but from the debugger console
	// Before sorting
	// arr->array = {20 86 29 29 37 73 57 7 57 86 37 89 29 77 11 78}
	// After sorting
	// arr->array = {7 11 20 29 29 29 37 37 57 57 73 77 78 86 86 89}
	//! [Comparative_Sorts Selection_Sort]

	ALGOR::generate_struct<long>(arr, 1, 100);
	//! [Comparative_Sorts Heap_Sort]
	comp_sort->Heap_Sort();
	// The data is not taken from the output, but from the debugger console
	// Before sorting
	// arr->array = {20 86 29 29 37 73 57 7 57 86 37 89 29 77 11 78}
	// After sorting
	// arr->array = {7 11 20 29 29 29 37 37 57 57 73 77 78 86 86 89}
	//! [Comparative_Sorts Heap_Sort]

	ALGOR::generate_struct<long>(arr, 1, 100);
	//! [Comparative_Sorts Cycle_Sort]
	comp_sort->Cycle_Sort();
	// The data is not taken from the output, but from the debugger console
	// Before sorting
	// arr->array = {20 86 29 29 37 73 57 7 57 86 37 89 29 77 11 78}
	// After sorting
	// arr->array = {7 11 20 29 29 29 37 37 57 57 73 77 78 86 86 89}
	//! [Comparative_Sorts Cycle_Sort]

	ALGOR::generate_struct<long>(arr, 1, 100);
	//! [Comparative_Sorts Insert_Sort]
	comp_sort->Insert_Sort();
	// The data is not taken from the output, but from the debugger console
	// Before sorting
	// arr->array = {20 86 29 29 37 73 57 7 57 86 37 89 29 77 11 78}
	// After sorting
	// arr->array = {7 11 20 29 29 29 37 37 57 57 73 77 78 86 86 89}
	//! [Comparative_Sorts Insert_Sort]

	ALGOR::generate_struct<long>(arr, 1, 100);
	//! [Comparative_Sorts Shell_Sort]
	comp_sort->Shell_Sort();
	// The data is not taken from the output, but from the debugger console
	// Before sorting
	// arr->array = {20 86 29 29 37 73 57 7 57 86 37 89 29 77 11 78}
	// After sorting
	// arr->array = {7 11 20 29 29 29 37 37 57 57 73 77 78 86 86 89}
	//! [Comparative_Sorts Shell_Sort]

	ALGOR::generate_struct<long>(arr, 1, 100);
	//! [Comparative_Sorts Tree_Sort]
	comp_sort->Tree_Sort();
	// The data is not taken from the output, but from the debugger console
	// Before sorting
	// arr->array = {20 86 29 29 37 73 57 7 57 86 37 89 29 77 11 78}
	// After sorting
	// arr->array = {7 11 20 29 29 29 37 37 57 57 73 77 78 86 86 89}
	//! [Comparative_Sorts Tree_Sort]

	ALGOR::generate_struct<long>(arr, 1, 100);
	//! [Comparative_Sorts Library_Sort]
	comp_sort->Library_Sort();
	// The data is not taken from the output, but from the debugger console
	// Before sorting
	// arr->array = {20 86 29 29 37 73 57 7 57 86 37 89 29 77 11 78}
	// After sorting
	// arr->array = {7 11 20 29 29 29 37 37 57 57 73 77 78 86 86 89}
	//! [Comparative_Sorts Library_Sort]

	ALGOR::generate_struct<long>(arr, 1, 100);
	//! [Comparative_Sorts Patience_Sort]
	comp_sort->Patience_Sort();
	// The data is not taken from the output, but from the debugger console
	// Before sorting
	// arr->array = {20 86 29 29 37 73 57 7 57 86 37 89 29 77 11 78}
	// After sorting
	// arr->array = {7 11 20 29 29 29 37 37 57 57 73 77 78 86 86 89}
	//! [Comparative_Sorts Patience_Sort]

	ALGOR::generate_struct<long>(arr, 1, 100);
	//! [Comparative_Sorts Merge_Sort]
	comp_sort->Merge_Sort();
	// The data is not taken from the output, but from the debugger console
	// Before sorting
	// arr->array = {20 86 29 29 37 73 57 7 57 86 37 89 29 77 11 78}
	// After sorting
	// arr->array = {7 11 20 29 29 29 37 37 57 57 73 77 78 86 86 89}
	//! [Comparative_Sorts Merge_Sort]

	ALGOR::generate_struct<long>(arr, 1, 100);
	//! [Comparative_Sorts Bitonic_Sorter]
	comp_sort->Bitonic_Sorter();
	// The data is not taken from the output, but from the debugger console
	// Before sorting
	// arr->array = {20 86 29 29 37 73 57 7 57 86 37 89 29 77 11 78}
	// After sorting
	// arr->array = {7 11 20 29 29 29 37 37 57 57 73 77 78 86 86 89}
	//! [Comparative_Sorts Bitonic_Sorter]

	ALGOR::generate_struct<long>(arr, 1, 100);
	//! [Comparative_Sorts Batcher_OddEven_MergeSort]
	comp_sort->Batcher_OddEven_MergeSort();
	// The data is not taken from the output, but from the debugger console
	// Before sorting
	// arr->array = {20 86 29 29 37 73 57 7 57 86 37 89 29 77 11 78}
	// After sorting
	// arr->array = {7 11 20 29 29 29 37 37 57 57 73 77 78 86 86 89}
	//! [Comparative_Sorts Batcher_OddEven_MergeSort]

	ALGOR::generate_struct<long>(arr, 1, 100);
	//! [Comparative_Sorts Tim_Sort]
	comp_sort->Tim_Sort();
	// The data is not taken from the output, but from the debugger console
	// Before sorting
	// arr->array = {20 86 29 29 37 73 57 7 57 86 37 89 29 77 11 78}
	// After sorting
	// arr->array = {7 11 20 29 29 29 37 37 57 57 73 77 78 86 86 89}
	//! [Comparative_Sorts Tim_Sort]

	ALGOR::generate_struct<long>(arr, 1, 100);
	//! [Comparative_Sorts Pancake_Sort]
	comp_sort->Pancake_Sort();
	// The data is not taken from the output, but from the debugger console
	// Before sorting
	// arr->array = {20 86 29 29 37 73 57 7 57 86 37 89 29 77 11 78}
	// After sorting
	// arr->array = {7 11 20 29 29 29 37 37 57 57 73 77 78 86 86 89}
	//! [Comparative_Sorts Pancake_Sort]

	ALGOR::generate_struct<long>(arr, 1, 100);
	//! [Comparative_Sorts BatcherOddEvenMergeSort]
	Comparative_Sorts<long>::BatcherOddEvenMergeSort *boem_sort;
	boem_sort = new Comparative_Sorts<long>::BatcherOddEvenMergeSort(arr->array, arr->array_size);
	boem_sort->batcher_odd_even_merge_sort();
	delete (boem_sort);
	// The data is not taken from the output, but from the debugger console
	// Before sorting
	// arr->array = {20 86 29 29 37 73 57 7 57 86 37 89 29 77 11 78}
	// After sorting
	// arr->array = {7 11 20 29 29 29 37 37 57 57 73 77 78 86 86 89}
	//! [Comparative_Sorts BatcherOddEvenMergeSort]

	ALGOR::generate_struct<long>(arr, 1, 100);
	//! [Comparative_Sorts BitonicSorter]
	Comparative_Sorts<long>::BitonicSorter *bit_sort;
	bit_sort = new Comparative_Sorts<long>::BitonicSorter(arr->array, arr->array_size);
	bit_sort->bitonic_sorter();
	delete (bit_sort);
	// The data is not taken from the output, but from the debugger console
	// Before sorting
	// arr->array = {20 86 29 29 37 73 57 7 57 86 37 89 29 77 11 78}
	// After sorting
	// arr->array = {7 11 20 29 29 29 37 37 57 57 73 77 78 86 86 89}
	//! [Comparative_Sorts BitonicSorter]

	ALGOR::generate_struct<long>(arr, 1, 100);
	//! [Comparative_Sorts BogoSort]
	Comparative_Sorts<long>::BogoSort *bogo_sort;
	bogo_sort = new Comparative_Sorts<long>::BogoSort(arr->array, arr->array_size);
	//bogo_sort->bogo_sort();  //Краще його не використовувати
	delete (bogo_sort);
	// The data is not taken from the output, but from the debugger console
	// Before sorting
	// arr->array = {34 33 21}
	// After sorting
	// arr->array = {21 33 34}
	//! [Comparative_Sorts BogoSort]

	ALGOR::generate_struct<long>(arr, 1, 100);
	//! [Comparative_Sorts BubbleSort]
	Comparative_Sorts<long>::BubbleSort *bubb_sort;
	bubb_sort = new Comparative_Sorts<long>::BubbleSort(arr->array, arr->array_size);
	bubb_sort->bubble_sort();
	delete (bubb_sort);
	// The data is not taken from the output, but from the debugger console
	// Before sorting
	// arr->array = {20 86 29 29 37 73 57 7 57 86 37 89 29 77 11 78}
	// After sorting
	// arr->array = {7 11 20 29 29 29 37 37 57 57 73 77 78 86 86 89}
	//! [Comparative_Sorts BubbleSort]

	ALGOR::generate_struct<long>(arr, 1, 100);
	//! [Comparative_Sorts CocktailShakerSort]
	Comparative_Sorts<long>::CocktailShakerSort *shak_sort;
	shak_sort = new Comparative_Sorts<long>::CocktailShakerSort(arr->array, arr->array_size);
	shak_sort->cocktail_shaker_sort();
	delete (shak_sort);
	// The data is not taken from the output, but from the debugger console
	// Before sorting
	// arr->array = {20 86 29 29 37 73 57 7 57 86 37 89 29 77 11 78}
	// After sorting
	// arr->array = {7 11 20 29 29 29 37 37 57 57 73 77 78 86 86 89}
	//! [Comparative_Sorts CocktailShakerSort]

	ALGOR::generate_struct<long>(arr, 1, 100);
	//! [Comparative_Sorts CombSort]
	Comparative_Sorts<long>::CombSort *comb_sort;
	comb_sort = new Comparative_Sorts<long>::CombSort(arr->array, arr->array_size);
	comb_sort->comb_sort();
	delete (comb_sort);
	// The data is not taken from the output, but from the debugger console
	// Before sorting
	// arr->array = {20 86 29 29 37 73 57 7 57 86 37 89 29 77 11 78}
	// After sorting
	// arr->array = {7 11 20 29 29 29 37 37 57 57 73 77 78 86 86 89}
	//! [Comparative_Sorts CombSort]

	ALGOR::generate_struct<long>(arr, 1, 100);
	//! [Comparative_Sorts CycleSort]
	Comparative_Sorts<long>::CycleSort *cycl_sort;
	cycl_sort = new Comparative_Sorts<long>::CycleSort(arr->array, arr->array_size);
	cycl_sort->cycle_sort();
	delete (cycl_sort);
	// The data is not taken from the output, but from the debugger console
	// Before sorting
	// arr->array = {20 86 29 29 37 73 57 7 57 86 37 89 29 77 11 78}
	// After sorting
	// arr->array = {7 11 20 29 29 29 37 37 57 57 73 77 78 86 86 89}
	//! [Comparative_Sorts CycleSort]

	ALGOR::generate_struct<long>(arr, 1, 100);
	//! [Comparative_Sorts GnomeSort]
	Comparative_Sorts<long>::GnomeSort *gnom_sort;
	gnom_sort = new Comparative_Sorts<long>::GnomeSort(arr->array, arr->array_size);
	gnom_sort->gnome_sort();
	delete (gnom_sort);
	// The data is not taken from the output, but from the debugger console
	// Before sorting
	// arr->array = {20 86 29 29 37 73 57 7 57 86 37 89 29 77 11 78}
	// After sorting
	// arr->array = {7 11 20 29 29 29 37 37 57 57 73 77 78 86 86 89}
	//! [Comparative_Sorts GnomeSort]

	ALGOR::generate_struct<long>(arr, 1, 100);
	//! [Comparative_Sorts HeapSort]
	Comparative_Sorts<long>::HeapSort *heap_sort;
	heap_sort = new Comparative_Sorts<long>::HeapSort(arr->array, arr->array_size);
	heap_sort->heap_sort();
	delete (heap_sort);
	// The data is not taken from the output, but from the debugger console
	// Before sorting
	// arr->array = {20 86 29 29 37 73 57 7 57 86 37 89 29 77 11 78}
	// After sorting
	// arr->array = {7 11 20 29 29 29 37 37 57 57 73 77 78 86 86 89}
	//! [Comparative_Sorts HeapSort]

	ALGOR::generate_struct<long>(arr, 1, 100);
	//! [Comparative_Sorts InsertSort]
	Comparative_Sorts<long>::InsertSort *ins_sort;
	ins_sort = new Comparative_Sorts<long>::InsertSort(arr->array, arr->array_size);
	ins_sort->insert_sort();
	delete (ins_sort);
	// The data is not taken from the output, but from the debugger console
	// Before sorting
	// arr->array = {20 86 29 29 37 73 57 7 57 86 37 89 29 77 11 78}
	// After sorting
	// arr->array = {7 11 20 29 29 29 37 37 57 57 73 77 78 86 86 89}
	//! [Comparative_Sorts InsertSort]

	ALGOR::generate_struct<long>(arr, 1, 100);
	//! [Comparative_Sorts LibrarySort]
	Comparative_Sorts<long>::LibrarySort *libr_sort;
	libr_sort = new Comparative_Sorts<long>::LibrarySort(arr->array, arr->array_size);
	libr_sort->library_sort();
	delete (libr_sort);
	// The data is not taken from the output, but from the debugger console
	// Before sorting
	// arr->array = {20 86 29 29 37 73 57 7 57 86 37 89 29 77 11 78}
	// After sorting
	// arr->array = {7 11 20 29 29 29 37 37 57 57 73 77 78 86 86 89}
	//! [Comparative_Sorts LibrarySort]

	ALGOR::generate_struct<long>(arr, 1, 100);
	//! [Comparative_Sorts MergeSort]
	Comparative_Sorts<long>::MergeSort *merg_sort;
	merg_sort = new Comparative_Sorts<long>::MergeSort(arr->array, arr->array_size);
	merg_sort->merge_sort();
	delete (merg_sort);
	// The data is not taken from the output, but from the debugger console
	// Before sorting
	// arr->array = {20 86 29 29 37 73 57 7 57 86 37 89 29 77 11 78}
	// After sorting
	// arr->array = {7 11 20 29 29 29 37 37 57 57 73 77 78 86 86 89}
	//! [Comparative_Sorts MergeSort]

	ALGOR::generate_struct<long>(arr, 1, 100);
	//! [Comparative_Sorts OddEvenSort]
	Comparative_Sorts<long>::OddEvenSort *odev_sort;
	odev_sort = new Comparative_Sorts<long>::OddEvenSort(arr->array, arr->array_size);
	odev_sort->odd_even_sort();
	delete (odev_sort);
	// The data is not taken from the output, but from the debugger console
	// Before sorting
	// arr->array = {20 86 29 29 37 73 57 7 57 86 37 89 29 77 11 78}
	// After sorting
	// arr->array = {7 11 20 29 29 29 37 37 57 57 73 77 78 86 86 89}
	//! [Comparative_Sorts OddEvenSort]

	ALGOR::generate_struct<long>(arr, 1, 100);
	//! [Comparative_Sorts PancakeSort]
	Comparative_Sorts<long>::PancakeSort *panc_sort;
	panc_sort = new Comparative_Sorts<long>::PancakeSort(arr->array, arr->array_size);
	panc_sort->pancake_sort();
	delete (panc_sort);
	// The data is not taken from the output, but from the debugger console
	// Before sorting
	// arr->array = {20 86 29 29 37 73 57 7 57 86 37 89 29 77 11 78}
	// After sorting
	// arr->array = {7 11 20 29 29 29 37 37 57 57 73 77 78 86 86 89}
	//! [Comparative_Sorts PancakeSort]

	ALGOR::generate_struct<long>(arr, 1, 100);
	//! [Comparative_Sorts PatienceSort]
	Comparative_Sorts<long>::PatienceSort *pat_sort;
	pat_sort = new Comparative_Sorts<long>::PatienceSort(arr->array, arr->array_size);
	pat_sort->patience_sort();
	delete (pat_sort);
	// The data is not taken from the output, but from the debugger console
	// Before sorting
	// arr->array = {20 86 29 29 37 73 57 7 57 86 37 89 29 77 11 78}
	// After sorting
	// arr->array = {7 11 20 29 29 29 37 37 57 57 73 77 78 86 86 89}
	//! [Comparative_Sorts PatienceSort]

	ALGOR::generate_struct<long>(arr, 1, 100);
	//! [Comparative_Sorts QuickSort]
	Comparative_Sorts<long>::QuickSort *quic_sort;
	quic_sort = new Comparative_Sorts<long>::QuickSort(arr->array, arr->array_size);
	quic_sort->quick_sort();
	delete (quic_sort);
	// The data is not taken from the output, but from the debugger console
	// Before sorting
	// arr->array = {20 86 29 29 37 73 57 7 57 86 37 89 29 77 11 78}
	// After sorting
	// arr->array = {7 11 20 29 29 29 37 37 57 57 73 77 78 86 86 89}
	//! [Comparative_Sorts QuickSort]

	ALGOR::generate_struct<long>(arr, 1, 100);
	//! [Comparative_Sorts SelectionSort]
	Comparative_Sorts<long>::SelectionSort *sel_sort;
	sel_sort = new Comparative_Sorts<long>::SelectionSort(arr->array, arr->array_size);
	sel_sort->selection_sort();
	delete (sel_sort);
	// The data is not taken from the output, but from the debugger console
	// Before sorting
	// arr->array = {20 86 29 29 37 73 57 7 57 86 37 89 29 77 11 78}
	// After sorting
	// arr->array = {7 11 20 29 29 29 37 37 57 57 73 77 78 86 86 89}
	//! [Comparative_Sorts SelectionSort]

	ALGOR::generate_struct<long>(arr, 1, 100);
	//! [Comparative_Sorts ShellSort]
	Comparative_Sorts<long>::ShellSort *shel_sort;
	shel_sort = new Comparative_Sorts<long>::ShellSort(arr->array, arr->array_size);
	shel_sort->shell_sort();
	delete (shel_sort);
	// The data is not taken from the output, but from the debugger console
	// Before sorting
	// arr->array = {20 86 29 29 37 73 57 7 57 86 37 89 29 77 11 78}
	// After sorting
	// arr->array = {7 11 20 29 29 29 37 37 57 57 73 77 78 86 86 89}
	//! [Comparative_Sorts ShellSort]

	ALGOR::generate_struct<long>(arr, 1, 100);
	//! [Comparative_Sorts SlowSort]
	Comparative_Sorts<long>::SlowSort *slow_sort;
	slow_sort = new Comparative_Sorts<long>::SlowSort(arr->array, arr->array_size);
	slow_sort->slow_sort();
	delete (slow_sort);
	// The data is not taken from the output, but from the debugger console
	// Before sorting
	// arr->array = {20 86 29 29 37 73 57 7 57 86 37 89 29 77 11 78}
	// After sorting
	// arr->array = {7 11 20 29 29 29 37 37 57 57 73 77 78 86 86 89}
	//! [Comparative_Sorts SlowSort]

	ALGOR::generate_struct<long>(arr, 1, 100);
	//! [Comparative_Sorts StoogeSort]
	Comparative_Sorts<long>::StoogeSort *stog_sort;
	stog_sort = new Comparative_Sorts<long>::StoogeSort(arr->array, arr->array_size);
	stog_sort->stooge_sort();
	delete (stog_sort);
	// The data is not taken from the output, but from the debugger console
	// Before sorting
	// arr->array = {20 86 29 29 37 73 57 7 57 86 37 89 29 77 11 78}
	// After sorting
	// arr->array = {7 11 20 29 29 29 37 37 57 57 73 77 78 86 86 89}
	//! [Comparative_Sorts StoogeSort]

	ALGOR::generate_struct<long>(arr, 1, 100);
	//! [Comparative_Sorts TimSort]
	Comparative_Sorts<long>::TimSort *tim_sort;
	tim_sort = new Comparative_Sorts<long>::TimSort(arr->array, arr->array_size);
	tim_sort->tim_sort();
	delete (tim_sort);
	// The data is not taken from the output, but from the debugger console
	// Before sorting
	// arr->array = {20 86 29 29 37 73 57 7 57 86 37 89 29 77 11 78}
	// After sorting
	// arr->array = {7 11 20 29 29 29 37 37 57 57 73 77 78 86 86 89}
	//! [Comparative_Sorts TimSort]

	ALGOR::generate_struct<long>(arr, 1, 100);
	//! [Comparative_Sorts TreeSort]
	Comparative_Sorts<long>::TreeSort *tr_sort;
	tr_sort = new Comparative_Sorts<long>::TreeSort(arr->array, arr->array_size);
	tr_sort->tree_sort();
	delete (tr_sort);
	// The data is not taken from the output, but from the debugger console
	// Before sorting
	// arr->array = {20 86 29 29 37 73 57 7 57 86 37 89 29 77 11 78}
	// After sorting
	// arr->array = {7 11 20 29 29 29 37 37 57 57 73 77 78 86 86 89}
	//! [Comparative_Sorts TreeSort]

	ALGOR::ARRAYDATA<long long> *clas_arr = new ALGOR::ARRAYDATA<long long>(16);
	//! [Distribution_Sorts constructor]
	ALGOR::Distribution_Sorts *dist_sort = new ALGOR::Distribution_Sorts(clas_arr->getData());
	//! [Distribution_Sorts constructor]

	clas_arr->generatedData(1, 100);
	//! [Distribution_Sorts AmericanFlag_Sort]
	dist_sort->AmericanFlag_Sort();
	// The data is not taken from the output, but from the debugger console
	// Before sorting
	// arr->array = {20 86 29 29 37 73 57 7 57 86 37 89 29 77 11 78}
	// After sorting
	// arr->array = {7 11 20 29 29 29 37 37 57 57 73 77 78 86 86 89}
	//! [Distribution_Sorts AmericanFlag_Sort]

	clas_arr->generatedData(1, 100);
	//! [Distribution_Sorts Bead_Sort]
	dist_sort->Bead_Sort();
	// The data is not taken from the output, but from the debugger console
	// Before sorting
	// arr->array = {20 86 29 29 37 73 57 7 57 86 37 89 29 77 11 78}
	// After sorting
	// arr->array = {7 11 20 29 29 29 37 37 57 57 73 77 78 86 86 89}
	//! [Distribution_Sorts Bead_Sort]

	clas_arr->generatedData(1, 100);
	//! [Distribution_Sorts Bucket_Sort]
	dist_sort->Bucket_Sort();
	// The data is not taken from the output, but from the debugger console
	// Before sorting
	// arr->array = {20 86 29 29 37 73 57 7 57 86 37 89 29 77 11 78}
	// After sorting
	// arr->array = {7 11 20 29 29 29 37 37 57 57 73 77 78 86 86 89}
	//! [Distribution_Sorts Bucket_Sort]

	clas_arr->generatedData(1, 100);
	//! [Distribution_Sorts Counting_Sort]
	dist_sort->Counting_Sort();
	// The data is not taken from the output, but from the debugger console
	// Before sorting
	// arr->array = {20 86 29 29 37 73 57 7 57 86 37 89 29 77 11 78}
	// After sorting
	// arr->array = {7 11 20 29 29 29 37 37 57 57 73 77 78 86 86 89}
	//! [Distribution_Sorts Counting_Sort]

	clas_arr->generatedData(1, 100);
	//! [Distribution_Sorts Flash_Sort]
	dist_sort->Flash_Sort();
	// The data is not taken from the output, but from the debugger console
	// Before sorting
	// arr->array = {20 86 29 29 37 73 57 7 57 86 37 89 29 77 11 78}
	// After sorting
	// arr->array = {7 11 20 29 29 29 37 37 57 57 73 77 78 86 86 89}
	//! [Distribution_Sorts Flash_Sort]

	clas_arr->generatedData(1, 100);
	//! [Distribution_Sorts Interpolation_Sort]
	dist_sort->Interpolation_Sort();
	// The data is not taken from the output, but from the debugger console
	// Before sorting
	// arr->array = {20 86 29 29 37 73 57 7 57 86 37 89 29 77 11 78}
	// After sorting
	// arr->array = {7 11 20 29 29 29 37 37 57 57 73 77 78 86 86 89}
	//! [Distribution_Sorts Interpolation_Sort]

	clas_arr->generatedData(1, 100);
	//! [Distribution_Sorts Pigeonhole_Sort]
	dist_sort->Pigeonhole_Sort();
	// The data is not taken from the output, but from the debugger console
	// Before sorting
	// arr->array = {20 86 29 29 37 73 57 7 57 86 37 89 29 77 11 78}
	// After sorting
	// arr->array = {7 11 20 29 29 29 37 37 57 57 73 77 78 86 86 89}
	//! [Distribution_Sorts Pigeonhole_Sort]

	clas_arr->generatedData(1, 100);
	//! [Distribution_Sorts Radix_Sort]
	dist_sort->Radix_Sort();
	// The data is not taken from the output, but from the debugger console
	// Before sorting
	// arr->array = {20 86 29 29 37 73 57 7 57 86 37 89 29 77 11 78}
	// After sorting
	// arr->array = {7 11 20 29 29 29 37 37 57 57 73 77 78 86 86 89}
	//! [Distribution_Sorts Radix_Sort]

	clas_arr->generatedData(1, 100);
	//! [Distribution_Sorts AmericanFlagSort]
	Distribution_Sorts::AmericanFlagSort *af_sort;
	af_sort = new Distribution_Sorts::AmericanFlagSort(clas_arr->getData()->array, clas_arr->getSize());
	af_sort->american_flag_sort();
	delete (af_sort);
	// The data is not taken from the output, but from the debugger console
	// Before sorting
	// arr->array = {20 86 29 29 37 73 57 7 57 86 37 89 29 77 11 78}
	// After sorting
	// arr->array = {7 11 20 29 29 29 37 37 57 57 73 77 78 86 86 89}
	//! [Distribution_Sorts AmericanFlagSort]

	clas_arr->generatedData(1, 100);
	//! [Distribution_Sorts BeadSort]
	Distribution_Sorts::BeadSort *bead_sort;
	bead_sort = new Distribution_Sorts::BeadSort(clas_arr->getData()->array, clas_arr->getSize());
	bead_sort->bead_sort();
	delete (bead_sort);
	// The data is not taken from the output, but from the debugger console
	// Before sorting
	// arr->array = {20 86 29 29 37 73 57 7 57 86 37 89 29 77 11 78}
	// After sorting
	// arr->array = {7 11 20 29 29 29 37 37 57 57 73 77 78 86 86 89}
	//! [Distribution_Sorts BeadSort]

	clas_arr->generatedData(1, 100);
	//! [Distribution_Sorts BucketSort]
	Distribution_Sorts::BucketSort *buck_sort;
	buck_sort = new Distribution_Sorts::BucketSort(clas_arr->getData()->array, clas_arr->getSize());
	buck_sort->bucket_sort();
	delete (buck_sort);
	// The data is not taken from the output, but from the debugger console
	// Before sorting
	// arr->array = {20 86 29 29 37 73 57 7 57 86 37 89 29 77 11 78}
	// After sorting
	// arr->array = {7 11 20 29 29 29 37 37 57 57 73 77 78 86 86 89}
	//! [Distribution_Sorts BucketSort]

	clas_arr->generatedData(1, 100);
	//! [Distribution_Sorts CountingSort]
	Distribution_Sorts::CountingSort *coun_sort;
	coun_sort = new Distribution_Sorts::CountingSort(clas_arr->getData()->array, clas_arr->getSize());
	coun_sort->counting_sort();
	delete (coun_sort);
	// The data is not taken from the output, but from the debugger console
	// Before sorting
	// arr->array = {20 86 29 29 37 73 57 7 57 86 37 89 29 77 11 78}
	// After sorting
	// arr->array = {7 11 20 29 29 29 37 37 57 57 73 77 78 86 86 89}
	//! [Distribution_Sorts CountingSort]

	clas_arr->generatedData(1, 100);
	//! [Distribution_Sorts FlashSort]
	Distribution_Sorts::FlashSort *flas_sort;
	flas_sort = new Distribution_Sorts::FlashSort(clas_arr->getData()->array, clas_arr->getSize());
	flas_sort->flash_sort();
	delete (flas_sort);
	// The data is not taken from the output, but from the debugger console
	// Before sorting
	// arr->array = {20 86 29 29 37 73 57 7 57 86 37 89 29 77 11 78}
	// After sorting
	// arr->array = {7 11 20 29 29 29 37 37 57 57 73 77 78 86 86 89}
	//! [Distribution_Sorts FlashSort]

	clas_arr->generatedData(1, 100);
	//! [Distribution_Sorts InterpolationSort]
	Distribution_Sorts::InterpolationSort *int_sort;
	int_sort = new Distribution_Sorts::InterpolationSort(clas_arr->getData()->array, clas_arr->getSize());
	int_sort->interpolation_sort();
	delete (int_sort);
	// The data is not taken from the output, but from the debugger console
	// Before sorting
	// arr->array = {20 86 29 29 37 73 57 7 57 86 37 89 29 77 11 78}
	// After sorting
	// arr->array = {7 11 20 29 29 29 37 37 57 57 73 77 78 86 86 89}
	//! [Distribution_Sorts InterpolationSort]

	clas_arr->generatedData(1, 100);
	//! [Distribution_Sorts PigeonholeSort]
	Distribution_Sorts::PigeonholeSort *pig_sort;
	pig_sort = new Distribution_Sorts::PigeonholeSort(clas_arr->getData()->array, clas_arr->getSize());
	pig_sort->pigeonhole_sort();
	delete (pig_sort);
	// The data is not taken from the output, but from the debugger console
	// Before sorting
	// arr->array = {20 86 29 29 37 73 57 7 57 86 37 89 29 77 11 78}
	// After sorting
	// arr->array = {7 11 20 29 29 29 37 37 57 57 73 77 78 86 86 89}
	//! [Distribution_Sorts PigeonholeSort]

	clas_arr->generatedData(1, 100);
	//! [Distribution_Sorts RadixSort]
	Distribution_Sorts::RadixSort *rad_sort;
	rad_sort = new Distribution_Sorts::RadixSort(clas_arr->getData()->array, clas_arr->getSize());
	rad_sort->radix_sort();
	delete (rad_sort);
	// The data is not taken from the output, but from the debugger console
	// Before sorting
	// arr->array = {20 86 29 29 37 73 57 7 57 86 37 89 29 77 11 78}
	// After sorting
	// arr->array = {7 11 20 29 29 29 37 37 57 57 73 77 78 86 86 89}
	//! [Distribution_Sorts RadixSort]

	delete (dist_sort);
	delete (comp_sort);
	ALGOR::remove_struct<long>(arr);

	std::cin.get();
	return 0;
}
