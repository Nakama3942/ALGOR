# CHANGELOG
<!--
Copyright © 2021-2022 Kalynovsky Valentin. All rights reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

   http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
-->
<!--
## vX.X.X.X (DATE)

#### Bug Fixes:
- [# XXX](https : / / github . com / XXX) DESCRIPTION

#### Invalid Fixed:
- [# XXX](https : / / github . com / XXX) DESCRIPTION

#### Documenting:
- [# XXX](https : / / github . com / XXX) DESCRIPTION

#### Duplicating:
- [# XXX](https : / / github . com / XXX) DESCRIPTION

#### Enhancements:
- [# XXX](https : / / github . com / XXX) DESCRIPTION

---
-->

## v1.0.0.0 (29.08.2022)

> *Everything in the world is documented*...

### Documenting:
- Fully documented in every detail all functionality of the library down to the smallest details!
- Many examples have been written that describe the entire functionality of the library in detail.
- Rewritten README.md: added many important details like Licenses, Library building, etc.
- Added explanatory gifs to README.md.
- Rewrote CHANGELOG.md: removed a lot of unnecessary text that only gets in the way.
- Created a site with documentation and added a link to the repository.

### Enhancements:
- The file structure of the project was redistributed:
	- Header files are located in the *include* subdirectory;
	- Implementation files are located in the *src* subdirectory;
	- Test files are located in the *test* subdirectory;
	- Image files are located in the *img* subdirectory;
	- Example files are located in the *example* subdirectory;
	- Documentation files are located in the *docs* subdirectory;
	- Build files are located in the *build* subdirectory;
- The files of implementations are distributed again, each according to its own category;
- Optimized **searcherOccurrencesOfSubstring()** method;
- A new **cloneData()** method was implemented (more precisely, the old **cloneData()** was renamed to **cloneNewData()** and a new **cloneData()** with a different implementation was added);
- A convenient library assembly system was created for Windows and Linux platforms (makefile and test.sh);
- Now all the functionality is compiled under **any types** (due to which the compilation time and weight of the library increased).

---

## v0.1.3.0 (24.06.2022)

> _Brought the structure of the project to the final form_...

### Invalid Fixed:
- Replaced broken *SmoothSort* with *BatcherOddEvenMergeSort*.

### Documenting:
- Returned all documentation back to the hider. Preparation for writing the documentation is underway.
- CHANGELOG has been rewritten according to the new design style.

### Enhancements:
- Added:
	- A separate array generation function used by the class;
	- New getters: **getPosition()** and **getValue()**;
	- The Linear Congruent Method of the PRNG and the function of testing Randomizers for the uniformity of number generation, which uses the Pearson consistency criterion;
	- New operators: ^=, =, ==;
- Optimized:
	- **swap()**;
	- **resize()** (heavily optimized);
- Replaced by:
	- Implementation of **reset()** and **respawn()** methods in places;
	- Binary search (now it is similar to the binary search that was implemented for _LibrarySort_);
- Rewritten:
	- All standard types for declared aliases;
	- A giant piece of code, replacing forced compilation of *methods* with forced compilation of *classes*;
	- Defined types with which functions and classes will now be compiled (_**byte8_t** == long long int_, _**ubit64_t** == unsigned long long int_, _**fbit64_t** == double_, _* *fbit128_t** == long double_, _**asize_t** == unsigned int_);
	- Completely rewrote the old operators (even the purpose of some was replaced);
- Testing:
	- Separate programs for testing the library were written;
	- All sorting algorithms have been fully tested;
- Array check:
	- The verification function has been finalized: now it is a method of the base class of arrays, which is used when saving to an object of the data class;
- Combined:
	- All basic functions to the base class, rewriting them under static methods;
	- The **moda()** and **modas()** methods to one method, as they have been created their own struct and both now return a pointer to that struct, and the second method uses the first (method) and some distributes the result (so what's the point in this, if they are combined - nothing will change);
	- All exceptions in the *EXCEPTION_SET* namespace;
	- All Randomizers in the *RANDOM* namespace;
	- Both categories (classes) of sorting in the *SORTING* namespace;
- Rerelease:
	- Versions of releases have been replaced (now the release of the library *v1.0.0.0* will take place only after the completion of full documentation).

---

## v0.1.2.1 (03.06.2022)

> *Filled with knowledge of pointers*...
<!-- filled - преисполнился (от мема "Я настолько преисполнился в своём познании...") -->

### Enhancements:
- Added new features:
	1. **array_size_verification()** - creates an exception if the array is empty (that is, its size is zero);
	2. **distance()** - returns the distance between the beginning and end of the specified array range;
	3. **lower_bound()** - returns a pointer to the first occurrence of the specified value in the specified range (the array must be sorted; the function is similar to a binary search);
	4. **upper_bound()** - returns a pointer to the first occurrence of the next value after the specified value in the given range (array must be sorted; function similar to binary search).
- Completed:
	- Sorting algorithm **Bitonic_Sorter** from the category *ConcurrentSort*;
	- Sorting algorithm **Tim_Sort** from the category *HybridSorts*;
	- Sorting algorithm **Pancake_Sort** from the category *OtherSorts*;
	- Sorting algorithm **Library_Sort** from the *InsertionSorts* category.
- Removed settings: since there is no longer a section with standard libraries (for **Library_Sort** own **distance()** and **lower_bound()** were implemented) - there is no longer a purpose to divide the project into sections that can be included and exclude for compilation.
- Ten unimplemented sorting algorithms that are not planned to be implemented in the near future:
	1. **BatcherOddEvenMergeSort** from *ConcurrentSort*;
	2. **PairwiseSortingNetwork** from *ConcurrentSort*;
	3. **SampleSort** from *ConcurrentSort*;
	4. **BlockMergeSort** from *HybridSorts*;
	5. **KirkpatrickReischSort** from *HybridSorts*;
	6. **IntroSort** from *HybridSorts*;
	7. **SpreadSort** from *HybridSorts*;
	8. **MergeInsertionSort** from *HybridSorts*;
	9. **TopologicalSort** from *OtherSorts*;
	10. **SpaghettiSort** from *OtherSorts*.

---

## v0.1.2.0 (15.04.2022)

> *The idea of a global namespace for the entire project was considered*...

### Enhancements:
- Since v0.0.0.1, only **CountingSort** and **RadixSort** have been implemented from the *Distribution_Sorts* category. Finally, the last group of algorithms that were present from the beginning was completed. The update implemented **AmericanFlagSort**, **BeadSort**, **BucketSort**, **FlashSort**, **InterpolationSort**, **PigeonholeSort** and deprecated **BurstSort** and **ProxmapSort**.
- With the implementation of this category, came up with a function to replace **time(NULL)** (well, finally) and also redefined **minimum()** and **maximum()** functions - now they return not only the smallest/largest number found in the array, but also the smallest/largest of the two given values. The proliferation of non-array functions led to the separation of core functions into array-related and non-array functions. The latter remained in the core, while the former moved to the array processing division, and since base sorting classes (such as categories) inherit from the array base class, the array processing division as a whole moved from "under" the sorting algorithms section to "above" the sorting section.
- All general classes of sorting algorithms, which can sort not only int-arrays, have been combined into one class. There are now only two classes of sorting algorithms in the Sorting Algorithms subsection: those that support any type of array, and those that only work with int arrays. Temporarily, at the time of implementation of the latest categories of sorting algorithms, the last three classes with the next three updates will be released as separate classes, but after that it is planned to merge them with the first class.
- And, finally, the settings system has been improved. Now the library core, exceptions, and randomizers cannot be disabled for the compiler, but the array handling and sorting subsections can now be disabled. It will also be possible to enable and disable additional algorithms and data structures that will be implemented in the future. At the end of the releases with the implementation of the sorting algorithms, it is planned to return to **LibrarySort** and still implement its own analogues **std::distance()** and **std::lower_bound()** to return this algorithm to the library permanently and grant full access to it. If this can be done, it will be possible to completely abandon the subdivision with standard libraries (which was the initial idea of the project), if a few more sorting algorithms do not get there...
- Implemented a global namespace for the entire library. All functionality has been added to this namespace. Since some function names are similar to the names of standard std functions, it is impossible to use both namespaces at the same time!

Now it is impossible to use:
```cpp
using namespace std;
using namespace ALGOR;
```
It is independent of order. All you have to do is choose one of them!This is the completion of the development of the project structure!

---

## v0.1.1.4 (04.04.2022)

> _Completed the fourth category of sorting algorithms_...

### Enhancements:
— The author tried to familiarize himself with **CascadeMergeSort**, **OscillatingMergeSort** and **PolyphaseMergeSort**, but there is almost no information about them (even on Wikipedia). It was decided to abandon these algorithms and it turned out that there is only one algorithm in this category that has already been implemented. It was rewritten under the new standard.

---

## v0.1.1.3 (01.04.2022)

> _Completed the third category of sorting algorithms_...

### Enhancements:
- Implemented the following sorting algorithms: **TreeSort**, **PatienceSort** and **LibrarySort** and combined them with **InsertSort** (except **LibrarySort**) into one class.
- Since **LibrarySort** cannot do without standard <s>libraries (distance() and lower_bound() functions are used)</s>, it was decided to make it a separate class. This complicated the structure and division of the library into two options - with standard libraries and without them.
- Settings will now be located at the top of the header. Depending on the value of #define STANDARDS_SWITCH, the library will be compiled with or without these algorithms (which require standard libraries). "0" - without libraries, "1" - with libraries.
- Had to put some standard functions in the Core class to avoid conflicts, just in case the programmer uses the standard libraries section.

---

## v0.1.1.2 (30.03.2022)

> _Completed the second category of sorting algorithms_...

### Enhancements:
- The following sorting algorithm has been implemented: **CycleSort**; combined them together with **HeapSort** (four algorithms in total) into one class - *Selection_Sorts*.
- It was decided to abandon the **CartesianTreeSort**, **TournamentSort**, **WeakHeapSort** algorithms due to their very complex implementation and lack of implementation examples. Maybe someday I will implement them...

---

## v0.1.1.1 (26.03.2022)

> _Completed the first category of sorting algorithms_...

### Enhancements:
- Added **SelectionSort** and **SmoothSort** to the *Selection_Sorts* namespace; **ShellSort** in *Insertion_Sorts* and all remaining algorithms from *Exchange_Sorts* namely **OddEvenSort**, **CombSort**, **GnomeSort**, **SlowSort**, **StoogeSort** and **BogoSort**. After implementing all the algorithms with *Exchange_Sorts*, it was finally possible to combine them into one class.

Now you do NOT need to write a long command to call, for example
```cpp
Selection_Sorts::HeapSort<int> *sort = new Selection_Sorts::HeapSort<int>(ArrayStruct);
sort->start_sort();
```
not like before for all other namespaces. Now it is enough to enter the
```cpp
Exchange_Sorts<int> *sort = new Exchange_Sorts<int>(ArrayStruct);
sort->Stooge_Sort(); // Or some other
```
As you can see, it is now enough to create an object of the class and choose the desired sorting algorithm.

---

## v0.1.1.0 (11.01.2022)

> *Rethinking data storage security*...

### Bug Fixes:
- The **remove()** method is now private. Now the ARRAYDATA class cannot store a pointer to nullptr, so the object will always store some kind of array, which will increase the fault tolerance of the ARRAYDATA class.
- Added more checks and now, in case of an error, the program will not crash with a runtime error, but will throw exceptions that can be caught by the programmer.

### Documentation:
- The library began to be documented. True, the documentation is not yet available and is at the stage of development. Sorting algorithms are currently undocumented, and everything else is documented at the brief and param level. All warnings, notes, details, etc. will be described after the development of the library release is complete, i.e. before the v1.0.0.0 release.

### Enhancements:
- A class for working with exceptions has been written - Exception. All exceptions that the library throws now throw objects inherited from Exception , which stores information about the error and can return that information when requested by the programmer. A programmer can also create his own exception classes that inherit from Exception.

---

## v0.1.0.0 (23.12.2021)

> _Created a large class with giant data formatting capabilities in arrays_...

### Enhancements:
- It is difficult to say which functions have been rewritten, renamed, and which are truly new. Therefore, the update will be described as follows:
	- Removed:
		1. The **ArrayProcessing** class with all its methods, but the functionality and algorithms are not trashed, but rewritten to new methods and functions.
	- New structure of the project:
		1. *ALGOR_CORE*
		2. *ALGOR_EXCEPTION* (will be released in v0.1.1.0)
		3. *ALGOR_RANDOM*
		4. *AlGOR_SORTING* (the functionality will be expanded in versions v0.1.1.1 - v0.1.1.X)
		5. *AlGOR_ARRAY*
		6. *ALGOR_MATRIX* (will be released from version v1.0.0.0)
		7. *AlGOR_HEAP* (will be released from version v2.0.0.0)
		8. *AlGOR_LIST* (will be released from version v3.0.0.0)
	- New classes:
		1. *RC4* - a simple cryptographic randomizer (its functionality will be further expanded);
		2. *MersenneTwister* - extended randomizer (its functionality will be further expanded);
		3. *ARRAYDATA* - class for working with arrays.
	- ARRAYDATA functionality:
		1. **Constructors** - accept the structure or size of the array when creating an object;
		2. **generatedData()** - generates array elements;
		3. **setNewData()** - deletes the old array and stores a pointer to the new one;
		4. **setData()** - saves a pointer to a new array without deleting the old one;
		5. **cloneData()** - copies (clones) the array;
		6. **getData()** - sets/returns a pointer to the array;
		7. **reset()** - deletes the old array, creates a new one with the same size and fills it in the same range;
		8. **resize()** - changes the size of the array;
		9. **replace()** - changes the element in the specified position to the specified value;
		10. **reverse()** - reverses the array;
		11. **remove()** - removes the array;
		12. **respawn()** is analogous to **reset()**, only at the end it does not fill the array with elements, but leaves it empty;
		13. **getMin()** - returns the minimum value of the array (optimized method);
		14. **getMax()** - returns the maximum value of the array (optimized method);
		15. **lenear_searcher()** - returns all occurrences of the searched element;
		16. **binary_searcher()** - returns the occurrence of the required element in the sorted array;
		17. **searcherOccurrencesOfSubstring()** - returns all occurrences of a substring;
		18. **average()** - returns the arithmetic average for all elements of the array;
		19. **mediana()** - returns the median of the array;
		20. **moda()** - returns the first occurrence of the mod;
		21. **modas()** - returns all occurrences of the mod;
		22. **operator&&()** - adds an element to the end of the array;
		23. **operator!()** - removes an element from the end of the array;
		24. **operator||()** - removes all elements from the array that correspond to the given value;
		25. **operator<<()** - combines two arrays in the current object;
		26. **operator>>()** - combines two arrays in the specified object;
		27. **operator+()** - increases the size of the array by the given size;
		28. **operator-()** - reduces the size of the array by the given size;
		29. **operator*()** - increases the size of the array several times by the given size;
		30. **operator/()** - reduces the size of the array several times by the specified size.
	- New main features:
		1. **swap()** - swaps two elements;
		2. **minimum()** - returns the minimum value of the array by iteration;
		3. **maximum()** - returns the maximum value of the array by iteration;
		4. **addElement()** - adds the specified value to the specified position;
		5. **subtractElement()** - removes the element in the specified position;
		6. **subtractValue()** - removes all elements that correspond to the specified value;
		7. **copy()** - copies elements from one array to another;
		8. **create_struct()** - creates a structure and returns a pointer to it;
		9. **remove_struct()** - removes the structure.
	- New types:
		1. **int8_t, int16_t, int32_t, int64_t** (taken from stdint);
		2. **uint8_t, uint16_t, uint32_t, uint64_t** (taken from stdint);
		3. **asize_t** - "array size type" - native type for defining the "array size" type.

---

## v0.0.1.0 (05.11.2021)

> _Formation of the first structure of the project_...

### Bug Fixes:
- Optimized methods **getMin()** and **getMax()**.

### Enhancements:
- The generator was planned to be introduced in this update, but its implementation has been delayed. Instead, a new structure for working with data (arrays) has been implemented and the functionality of the *ArrayProcessing* class has been further expanded.
- A plan has been drawn up, which other sorting algorithms are planned to be implemented in the next updates.
- New structure:
	1. Now the array and its size are stored in the same structure. This is for convenience.
	2. The *ArrayProcessing* class itself is now outside the namespace, and the namespace itself has been split into several new ones. Each namespace will contain specific sorting algorithms.
	3. Now the template type is specified for each method of the *ArrayProcessing* class.
- New array processing methods:
	1. **getElementsNumber_lenear()** - linear element search (finds all locations of a given element in any array);
	2. **getElementNumber_binary()** - binary element search (finds the first location of a given element in a sorted array);
	3. **getOccurrencesOfSubstring()** - search for a sequence of elements (will be required for strings, but can be used for any type of numbers, such as int or float; returns all places where this sequence starts in the main array);
	4. **addElement()** - adding an element to the array (initially expands it by one, and then writes the required value in the last place);
	5. **generatedStruct()** - generator of structures (receives the declared structure and the desired size of the array, saves the size and declares the array with the required size);
	6. **modas()** - find mods (unlike **moda()**, which finds the location of only the first element, which is the most common, it finds all elements with the same frequency).
- Removed methods:
	1. **print()**;
	2. **sum()**.
- Updated example to comply with new library standards for working with arrays.

---

## v0.0.0.3 (16.10.2021)

> _Added some new methods_...

### Bug Fixes:
- Fixed typos and errors that were missed last time;
- The **Counting_Sort** algorithm has been optimized, in which the finding of the minimum and maximum elements is now not copied, but already existing methods are called;
- Added a License and a mark that will indicate the current version of the library;
- And, finally, the library usage example has been updated (corrected).

### Enhancements:
- The functionality of the **print()** method has been expanded;
- Changed **getMax()** and **getMin()** methods;
- Added methods:
	1. **reverse()** - reversing an array;
	2. **copy()** - copying an array;
	3. **sum()** - finds the sum of array elements;
	4. **average()** - finds the average of the array;
	5. **mediana()** - finds the median of the array;
	6. **moda()** - finds the mode of the array.

---

## v0.0.0.2 (01.10.2021)

> _Minor edits_...

### Bug Fixes:
- Made 3 edits:
	1. Removed the template where it is not needed;
	2. Fixed the transferred type to method **swap()** class*ArrayProcessing*;
	3. In general, the types of transmitted are corrected, where they were incorrectly indicated.

---

## v0.0.0.1 (29.09.2021)

> *It should have been a simple job that contains only sorting algorithms*...

### Release
- Written class *ArrayProcessing* with methods:
	1. **generatedArray()** - generating of the array;
	2. **swap()** - replacing two items in places;
	3. **print()** - displaying array on the screen;
	4. **getMax()** and **getMin()** - searching the maximum and minimum element.
- And classes of next sorting algorithms:
	1. **Insert_Sort**;
	2. **Bubble_Sort**;
	3. **Cocktail_Shaker_Sort**;
	4. **Merge_Sort**;
	5.  **Heap_Sort**;
	6. **Quick_Sort**;
	7. **Counting_Sort** (at the moment the fastest);
	8. **Radix_Sort**.