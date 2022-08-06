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

	cin.get();
	return 0;
}