# CHANGELOG

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

<!--
## v1.0.0.0 (DATE) <- 「Very very big documenting」

~~Planned old tag 2.4.0~~

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

## v0.1.3.0 (24.06.2022) <- 「Completed develop arrays structuring and library core」

> _Brought the structure of the project to the final form_...

#### Invalid Fixed:
- Replaced broken _SmoothSort_ on _BatcherOddEvenMergeSort_.

#### Documenting:
- Returned all documentation back to the header. I am preparing to write documentation;
- Rewrote CHANGELOG for a new design style.

#### Enhancements:
- Added:
	- Added a separate array generation function used by the Array class;
	- Added new Getters: **getPosition()** and **getValue()**;
	- Added a Linear Congruent Pseudo-Random Number Generation Method and a Randomizers Testing Function for Uniformity of number generation using Pearson Consistency Criterion;

- Optimized:
	- Optimized the **swap()** function;
	- Strongly optimized the **resize()** method;

- Replaced:
	- Replaced implementations of **reset()** and **respawn()** methods with opposite ones;
	- Replaced binary search (now it is similar to the binary search that was implemented for _LibrarySort_);

- Rewrited:
	- Rewrote all standard types to declared aliases;
	- Rewrote the giant part of the code, replacing the forced compilation of methods with the forced compilation of classes;
	- Decided with the types with which functions and classes will now be compiled (_**byte8_t** == long long int_, _**ubit64_t** == unsigned long long int_, _**fbit64_t** == double_, _**fbit128_t** == long double_, _**asize_t** == unsigned int_);
	- Completely rewrote the old operators (in some even changed the purpose) and added new ones: ^=, =, ==;

- Testing:
	- Wrote separate programs for testing the library;
	- Completely tested all sorting algorithms;

- Array verification:
	- The verification function has been finalized: it is now the base array class method used when saving to a data class object;

- Merged:
	- Merged all basic functions into a basic class, rewriting them in static methods;
	- Merged the **moda()** and **modas()** methods into one method, since I created their own structure for them and they both now point to this structure, and the second method uses the first and a little spreads the result (so what is the point if you combine them - nothing will change);
	- Merged all exceptions into the namespace *EXCEPTION_SET*;
	- Merged all Randomizers into the namespace *RANDOM*;
	- Merged both categories (classes) of sorts into the namespace *SORTING*;

- Rereleased:
	- Replaced versions of releases (now the release of the version _1.0.0.0_ library will take place only after the completion of full documentation).

~~Planned old tag 2.3.0~~

<!--
## v0.1.3.0 (24.06.2022) <- 2.3.0

#### Invalid Fixed:
- Замінив непрацюючий _SmoothSort_ на _BatcherOddEvenMergeSort_.

#### Documenting:
- Повернув усе документування назад у хідер. Готуюсь до написання документації;
- Переписав CHANGELOG під новий стиль оформлення.

#### Enhancements:
- Add:
	- Додав окрему функцію генерування масивів, яку використовує клас;
	- Додав нові Ґеттери: **getPosition()** та **getValue()**;
	- Додав Лінійний Конґруентний Метод ГПСЧ та функцію тестування Рандомізаторів на рівномірність генерування чисел, використовуючи критерій узгодженості Пірсона;

- Optimize:
	- Оптимізував функцію **swap()**;
	- Сильно оптимізував метод **resize()**;

- Replace:
	- Замінив реалізації методів **reset()** та **respawn()** місцями;
	- Замінив бінарний пошук (тепер він схожий на той бінарний пошук, що було реалізовано для _LibrarySort_);

- Rewrite:
	- Переписав усі стандартні типи на оголошені аліаси;
	- Переписав гігантську частину коду, замінивши примусову компіляцію методів на примусову компіляцію класів;
	- Визначився з типами, з якими тепер будуть компілюватися функції та класи (_byte8_t == long long int_, _ubit64_t == unsigned long long int_, _fbit64_t == double_, _fbit128_t == long double_, _asize_t == unsigned int_);
	- Повністю переписав старі оператори (у деяких змінив навіть призначення) та додав нових: ^=, =, ==;

- Testing:
	- Написав окремі програми для тестування бібліотеки;
	- Повністю протестував всі алгоритми сортування;

- Array verification:
	- Функція верифікації доведена до остаточного виду: тепер це метод базового класу масивів, що використовується при збереженні до об'єкту класу данних;

- Merged:
	- Об'єднав усі базові функції до базового класу, переписавши їх під статичні методи;
	- Об'єднав методи *moda()* та *modas()* до одного методу, так як я створив для них їх власну структуру й обидві вони тепер повертають вказівник на цю структуру, а другий метод використовує перший і трохи поширює результат (так який у цьому сенс, якщо їх об'єднати - нічого не зміниться);
	- Об'єднав усі виключення в простір імен *EXCEPTION_SET*;
	- Об'єднав усі Рандомізатори в простір імен *RANDOM*;
	- Об'єднав обидві категорії (класи) сортувань в простір імен *SORTING*;

- Rerelease:
	- Замінив версії релізів (тепер реліз бібліотеки версії _1.0.0.0_ відбудеться тільки після завершення повного документування).
-->

---

## v0.1.2.1 (03.06.2022) <- 「Completed sorting algorithms」

> _Completed the last sixth, seventh and eighth categories of sorting algorithms ahead of schedule and was filled in the knowledge of the pointers_...
<!-- filled - преисполнился (от мема "Я настолько преисполнился в своём познании...") -->

#### Enhancements:
- I forgot that at the beginning of sorting updates I sometimes made simple algorithms from the following categories of sorting algorithms. I thought I had only 26 sorting algorithms, forgetting about the 3 sorting algorithms that have already been implemented but not rewritten to the latest version of the design standard, and the algorithm that uses two standard functions. I'm just tired and wanted to release 30-35 sorting algorithms, and only 26 officially completed algorithms, ie I have 4-9 algorithms left to implement from a list of 10 unrealized algorithms. Remembering that I have 4 implemented but not completed algorithms, I just get 30 algorithms, which I planned. I decided to stop there. To implement the **Library_Sort** sorting algorithm, I needed to write my own implementations of the standard **distance()** and **lower_bound()** functions. I've tried to do it before, but I didn't succeed then. I then spent two days on it. Time passed, I learned a lot and I decided to try to write these functions again. And to my great surprise, I wrote their implementation for the first time. Then I tested these functions, made available the hidden function **verification()**, which I called **array_size_verification()**. And in the end I decided to implement a function similar to **lower_bound()**, namely **upper_bound()**. In result:
	- I am implementing new features:
		1. **array_size_verification()** - throws an exception if the array is empty (its size is zero)
		2. **distance()** - returns the distance between the beginning and end of the specified array range
		3. **lower_bound()** - returns the pointer to the first occurrence of the specified value in the specified range (the array must be sorted; the function is similar to binary search)
		4. **upper_bound()** - returns the pointer to the first occurrence of the next value after the specified in the specified range (the array must be sorted; a function similar to binary search)
	- I finished:
		- **Bitonic_Sorter** sorting algorithm from category _ConcurrentSort_
		- **Tim_Sort** sorting algorithm from category _HybridSorts_
		- **Pancake_Sort** sorting algorithm from category _OtherSorts_
		- **Library_Sort** sorting algorithm from category _InsertionSorts_
	- I deleted the settings: since I no longer have a partition with standard libraries - I no longer have a goal to divide the project into partitions, which can be included and disabled for compilation.
- I will note that sorting algorithms were already implemented at the time of release of the v2.0.0 update, and therefore the ten that remained to be implemented after the release of that update will no longer be implemented. Ten unrealized sorting algorithms: **BatcherOddEvenMergeSort** from _ConcurrentSort_, **PairwiseSortingNetwork** from _ConcurrentSort_, **SampleSort** from _ConcurrentSort_, **BlockMergeSort** from _HybridSorts_, **KirkpatrickReischSort** from _HybridSorts_, **IntroSort** from _HybridSorts_, **SpreadSort** from _HybridSorts_, **MergeInsertionSort** from _HybridSorts_, **TopologicalSort** from _OtherSorts_, **SpaghettiSort** from _OtherSorts_. I'm just tired of it. I want something new.

~~Old tag 2.2.1~~

---

## v0.1.2.0 (15.04.2022) <- 「namespace ALGOR & Comparative_Sorts & Distribution_Sorts」

> _After completing the fifth category of sorting algorithms, I thinked about the global namespace of the whole project_...

#### Enhancements:
- Since version 1.0.0, only _CountingSort_ and _RadixSort_ have been implemented from the Distribution_Sorts category. Finally, I completed the last group of those algorithms that were present from the very beginning. I've implemented _AmericanFlagSort_, _BeadSort_, _BucketSort_, _FlashSort_, _InterpolationSort_, _PigeonholeSort_ and deprecated _BurstSort_ and _ProxmapSort_. It remains for me to implement the 3 remaining categories that have not been implemented from the very beginning and to this day in no way at all: Concurrent_Sort, Hybrid_Sorts and Other_Sorts.
- With the implementation of this category, I came up with a function that is designed to replace **time(NULL)** (well, finally), and also redefined the **minimum()** and **maximum()** functions - now they return not only the smallest/largest number found in the array, but also just the smallest/largest of two given values. The proliferation of non-array functions led to the splitting of functions from the kernel into array-related and non-array-releated functions. The latter remained in the core, while the former moved to the array processing subsection, and since the base sorting classes (such as categories) are inherited from the base array class, the array processing subsection as a whole moved from the subsection of sorting algorithms to the oversubsection of sortings.
- Then I combined all the general classes of sorting algorithms that can sort not only int-arrays into one class. Now in the subsection of sorting algorithms there are only two classes of sorting algorithms: those that support any type of arrays and only int-arrays. Temporarily, at the time of the implementation of the last categories of sorting algorithms, the last three classes with the subsequent three updates will be released in separate classes, but after that it is planned to merge them with the first class.
- And finally, I finalized the settings system. Now the library core, exceptions and randomizers cannot be turned off for the compiler, however, it is already possible to turn off the array processing and sorting subsections. It will also be possible to turn on and off for compilation subsequent algorithms and data structures that will be implemented in the future. At the end of releases with implementations of sorting algorithms, I plan to return to LibrarySort and still implement my own analogues of **std::distance()** and **std::lower_bound()** to return this algorithm to the library permanently and give full access to him. If I manage to pull it off - I can completely abandon the subsection with standard libraries (which was the original idea of the project), if a few more sorting algorithms do not get there...
- I almost forgot - since a new project structure was introduced in v2.1.3, we can assume that now it has been completely finalized. Then LibrarySort was added, and in order to avoid name conflicts, I had to return the basic functions to the class. However, now I have added the entire library in general to my own ALGOR namespace (as in version 1.0.0 it was with SortingAlgorithms, in which the ArrayProcessing class was nested with static methods and 8 sorting algorithms (3 from Exchange_Sorts, 1 from Selection_Sorts, 1 from Insertion_Sorts, 1 from Merge_Sorts and 2 from Distribution_Sorts) - this is very similar to the structure from this version). I moved the basic functions outside the core class, and this class remained to store the basic array processing functions and moved to the array processing subsection. Now, in order to use my library, you either need to constantly specify the ALGOR namespace identifier or declare it the main one at the beginning of the project and use std to a minimum, for example, to print text to the console or use functionality whose is not in my library.

Now it is not possible to use:
```cpp
using namespace std;
using namespace ALGOR;
```
It does not depend on the order. You only need to choose one of them! This is the completion of structural renewal.

~~Old tag 2.2.0~~

---

## v0.1.1.4 (04.04.2022) <- 「Merge_Sorts」

> _Completed the fourth category of sorting algorithms_...

#### Enhancements:
- I tried to read _CascadeMergeSort_, _OscillatingMergeSort_ and _PolyphaseMergeSort_, but there is almost no information on them (even on Wikipedia). I decided to abandon these algorithms and it turned out that in this category there is only one algorithm that has already been implemented. I rewrote it to a new standard and released a new release.

~~Old tag 2.1.4~~

---

## v0.1.1.3 (01.04.2022) <- 「Insertion_Sorts」

> _Completed the third category of sorting algorithms_...

#### Enhancements:
- I implemented the following sorting algorithms: _TreeSort_, _PatienceSort_ and _LibrarySort_ and combined them with _InsertSort_ (except _LibrarySort_) into one class. Since I can't do without the standard libraries in _LibrarySort_, I decided to make it a separate class. This has complicated the structure and division of the library into two versions - with and without standard libraries. There will now be settings on top of the header. Depending on the value of #define STANDARDS_SWITCH, the library will be compiled with or without these algorithms, which require standard libraries. "0" - without libraries, "1" - with libraries. Since the library was originally conceived as a clean project without the use of any standard or any other library - I am not going to further develop this area. This section will collect some sorting algorithms that these standard libraries require and no more. Everything else I will have to implement myself. Since there are already a lot of implemented sorting algorithms, I can afford it. It is possible that in the future, due to the introduction of a system of settings, the structure of the project will become increasingly complex. Of course, I will not release this product with standard libraries, but I will leave them in case of need. If a programmer needs exactly the algorithm that uses standard libraries - he can always download the repository and build a library with the necessary settings.
- In case the programmer used a section with standard libraries, I had to place some of the standard functions in the Core class to avoid conflicts.

~~Old tag 2.1.3~~

---

## v0.1.1.2 (30.03.2022) <- 「Selection_Sorts」

> _Completed the second category of sorting algorithms_...

#### Enhancements:
- Made the following sorting algorithms: _CycleSort_; combined them together with Heap_Sort (only four algorithms) into one class - Selection_Sorts.
- I refused _CartesianTreeSort_, _TournamentSort_, _WeakHeapSort_ due to their very complicated implementation and lack of templates. Maybe someday I will implement them.
- I will not mention all other algorithms yet, because they are not yet ready for use. When their category of algorithms is prepared, then I will remember them.

~~Old tag 2.1.2~~

---

## v0.1.1.1 (26.03.2022) <- 「Exchange_Sorts」

> _Completed the first category of sorting algorithms_...

#### Enhancements:
- Added _SelectionSort_ and _SmoothSort_ to the Selection_Sorts namespace; _ShellSort_ in Insertion_Sorts and all remaining algorithms with Exchange_Sorts, namely _OddEvenSort_, _CombSort_, _GnomeSort_, _SlowSort_, _StoogeSort_ and _BogoSort_. After implementing all the algorithms with Exchange_Sorts, I finally got the opportunity to combine them into one class.

Now, to call, you do NOT need to write a long command like
```cpp
Selection_Sorts::HeapSort<int> *sort = new Selection_Sorts::HeapSort<int>(ArrayStruct);
sort->start_sort();
```
as is still required for all other namespaces. Now it is enough to enter the ensuing command
```cpp
Exchange_Sorts<int> *sort = new Exchange_Sorts<int>(ArrayStruct);
sort->Stooge_Sort(); // Or some other
```
As you can see, now it is enough to create a class object and select the desired sorting algorithm in it. Now you do not need, as before, to select a class in the namespace, and start sorting already in it.

~~Old tag 2.1.1~~

---

## v0.1.1.0 (11.01.2022) <- 「Exception & Safety」

> _I thinked about the security of data storage_...

#### Bug Fixes:
- The **remove()** method is now private. Now the ARRAYDATA class cannot store a pointer to nullptr, therefore the object will constantly store some kind of array, which will increase the fault tolerance of the ARRAYDATA class.
- Added more checks and now, in case of an error, the program will not crash, but throw exceptions that the programmer can catch.

#### Documenting:
- I started documenting the library. True, the documentation is not yet available and is under development. At the moment, the sorting algorithms are generally undocumented, and everything else is documented at the brief and param levels. All warnings, notes, details, etc. will be described after the completion of the development of the second version of the library, i.e. before v3.0.0.

#### Enhancements:
- Written class for working with exceptions - Exception. All exceptions that are thrown by the library now throw objects inherited from Exception, which stores information about the error and can return this information at the request of the programmer. The programmer can also create his own exception classes inherited from Exception.

~~Old tag 2.1.0~~

---

## v0.1.0.0 (23.12.2021) <- 「Dynamization & Globalization」

> _Create a large class with giant data formatting capabilities in arrays_...

#### Enhancements:
- This is the largest update compared to previous versions. I finally implemented what I had planned from the very beginning, but for which I then two months ago did not have enough experience. I finally decided to split the original header into several. Of course, before that I decided what I want to implement in my library in the future. These were six sections: _Core_ (or _Base_) - the base on which everything else will be based; _Randomizer_ - own implementation of the randomizer (needed to get rid of any plug-in library); _Arrays_ - functions for working with arrays; _Sorting_ - sorting algorithms; _Trees_; _Lists_. As it is already clear, one of the goals was set: "To get rid of any plug-in library - my development should be unique and written only in pure C++ (in the future, assembly language inserts may appear)." True, later, in order to optimize and get rid of errors, another class was planned for working with exceptions, it was planned to implement matrices along with trees and lists, and in general the order changed slightly. And, finally, only at this stage did I understand how it is still possible to implement what I wanted to do two months ago. I rewrote the functions from the namespace for working with arrays into a class and began to extend its methods. A base class has been created, from which all sorting methods and the array processing class are inherited. Yes, sorting algorithms are now also described in the class. In the future, I will rebuild the architecture of the sorting classes, but this does not apply to this update. With the gigantic classification, problems appeared in the form of architecture. The library continues to support the use of not only classes but also structures. To do this, I also implemented basic functions that can be used when working with a structure, and on which most of the methods from the class are built, and some are even used in sorting classes. I ended up with a new library architecture. Further, based on the accumulated knowledge, I was able to separate the implementation from the declaration. I began to separate the implementation into separate .cpp files. Later, all the headers were combined into one common header, and all the implementation files were combined into one file with the implementation. So I was finally able to separate the implementation from the announcement - something that I had planned two months ago, but could not do then.
- I have implemented what I had planned for this update: completely rebuild the architecture and syntax of the library. Now it's even easier to use. In addition to the new architecture, I have implemented aliases for some types.
- Which functions have been rewritten, renamed, and which are truly new, it's hard to say. Therefore, I will describe this update like this:
	- Removed:
		1. The _ArrayProcessing_ class with all its methods, but the functionality and algorithms are not thrown away, but rewritten into new methods and functions
	- New project structure:
		1. _ALGOR_CORE_ ✔
		2. _ALGOR_EXCEPTION_ ⧖ (will be released in version 2.1.0)
		3. _ALGOR_RANDOM_ ✔
		4. _AlGOR_SORTING_ ✔ (The functionality will be expanded from versions 2.1.1 to 2.1.X)
		5. _AlGOR_ARRAY_ ✔
		6. _ALGOR_MATRIX_ ⧖ (will be released in version 2.2.0)
		7. _AlGOR_HEAP_ ⧖ (will be released in version 3.0.0)
		8. _AlGOR_LIST_ ⧖ (will be released in version 4.0.0)
	- New classes:
		1. _RC4_ - a simple cryptographic randomizer (its functionality will be further expanded)
		2. _MersenneTwister_ - an advanced randomizer (its functionality will be further expanded)
		3. _ARRAYDATA_ - a class for working with an array
	- Everyone knows how to work with randomizers. Sorting hasn't changed much. I will describe the ARRAYDATA class:
		1. **Constructors** that accept either structure, array size, or void
		2. **generatedData()** - generates array elements
		3. **setNewData()** - removes the old array and stores the pointer to the new one
		4. **setData()** - saves a pointer to a new array without deleting the old one
		5. **cloneData()** - copies an array
		6. **getData()** - sets/returns a pointer to an array
		7. **reset()** - deletes the old array, creates a new one with the same size and fills it in the same range
		8. **resize()** - resizes an array
		9. **replace()** - changes the element at the specified position by the specified value
		10. **reverse()** - reverses the array
		11. **remove()** - removes an array
		12. **respawn()** - analogue of **reset()**, only at the end it does not fill the array with elements - it leaves it empty
		13. **getMin()** - returns the minimum value of the array (optimized method)
		14. **getMax()** - returns the maximum value of the array (optimized method)
		15. **lenear_searcher()** - returns all occurrences of the element you are looking for
		16. **binary_searcher()** - returns the occurrence of the desired element in a sorted array
		17. **searcherOccurrencesOfSubstring()** - returns all occurrences of a substring
		18. **average()** - returns the arithmetic average of all array elements
		19. **mediana()** - returns the median of an array
		20. **moda()** - returns the first occurrence of a mod
		21. **modas()** - returns all occurrences of a mod
		22. **operator&&** - adds an element to the end of the array
		23. **operator!** - removes an element from the end of the array
		24. **operator||** - removes all elements from the array that match the specified value
		25. **operator<<** - merges two arrays in the current object
		26. **operator>>** - merges two arrays in the specified object
		27. **operator+** - increases the size of the array by the specified size
		28. **operator-** - decreases the size of the array by the specified size
		29. **operator*** - increases the size of the array several times by the specified size
		30. **operator/** - decreases the size of the array several times by the specified size
	- New basic features:
		1. **swap()** - swaps two elements
		2. **minimum()** - returns the minimum value of an array by iteration
		3. **maximum()** - returns the maximum value of an array by iteration
		4. **addElement()** - adds the specified value to the specified position
		5. **subtractElement()** - removes the element at the specified position
		6. **subtractValue()** - removes all elements that match the specified value
		7. **copy()** - copies elements from one array to another
		8. **create_struct()** - creates a structure and returns a pointer to it
		9. **remove_struct()** - removes structure
	- New types:
		1. **int8_t, int16_t, int32_t, int64_t** (taken from stdint)
		2. **uint8_t, uint16_t, uint32_t, uint64_t** (taken from stdint)
		3. **asize_t** - "array size type" - native type for specifying the type "array size"
- I got a lot of new experiences working on this update.

~~Old tag 2.0.0~~

---

## v0.0.1.0 (05.11.2021) <- 「Structuring」

> _Formation of the first structure of the project_...

#### Bug Fixes:
- The **getMin()** and **getMax()** methods have been optimized. Now, with large array sizes, there is no need to wait for the algorithm to go through each element of the array, if it is clear that the smallest element in the sorted array will be the first, and the largest will be the last. In these cases, it is sufficient to indicate whether the array is sorted.

#### Enhancements:
- In this update, it was planned to implement a generator, but its implementation was delayed. Instead, I implemented a new structure for working with data (arrays) and further expanded the functionality of the _ArrayProcessing_ class. In addition, for the next updates, I laid down a plan for what other sorting algorithms are planned to be implemented.
- New structure:
	1. Now the array and its size are stored in one structure. This is for convenience. Now you don't need to create 100 arrays and remember their size. And what if they are also lost... Or get confused. Now it is enough to declare a structure instead of an array and generate it (structure) by setting its size. Now you do not need to remember the size of the array, since it is now always next to it, and in most methods of processing an array, it is enough just to transfer the desired structure, but not always. There are several methods, as well as all sorting algorithms, that do not require a structure, but an array and its size separately. In this case, when calling the method, you do not need to remember in which variable the size of some array is stored. Now it is enough to simply refer to the required fields of the structure in which the required array is stored. Everything is nicely structured. In terms of study, it will now be easier to figure out which array size is associated with which array. At the same time, those who do not know can learn to pass structures to functions.
	2. The _ArrayProcessing_ class itself is now out of the namespace, and the namespace itself has been split into several. Each namespace will contain certain sorting algorithms. This is necessary so that you can understand what type of sorting the sorting algorithm belongs to.
	3. All the same class _ArrayProcessing_ now does not have its template type defined. Now the template type is specified for each of its methods.
- New methods for processing arrays:
	1. Linear search for an element (finds all locations of that element) - **getElementsNumber_lenear()**
	2. Binary search for an element (finds the location of an element in a sorted array) - **getElementNumber_binary()**
	3. Search for a sequence of elements (will be needed for strings, but can be used on any types of numbers such as int or float; returns all the location where this sequence begins in the main array) - **getOccurrencesOfSubstring()**
	4. Adding an element to an array (first expands it by one, and then writes the desired value to the last place) - **addElement()**
	5. Generator of structures (receives the declared structure and the desired size of the array, saved the size and declares the array with the desired size) - **generatedStruct()**
	6. Search for mods (unlike moda(), which finds the location of only the first element, which is most common, it finds all elements with this same frequency) - **modas()**
- Removed methods:
	1. **print()**
	2. **sum()**
- I also updated the example to follow the new standards of the library for working with arrays, and now everything is structured in the example itself: now each function is responsible for explaining its library method and is called from the main function. This is done to make it easier to understand this library. From now on it will be more difficult to get confused.

~~Old tag 1.1.0~~

---

## v0.0.0.3 (16.10.2021) <- 「Extending ArrayProcessing functionality」

> _Added some new methods_...

#### Bug Fixes:
- And also additionally I:
	- corrected the last typos and mistakes that I missed last time;
	- optimized the counting_sort() method, in which now the finding of the minimum and maximum elements is not copied, but the call to already existing methods is in progress;
	- added license protection and a label that will point to the current version of the library;
	- and lastly updated (corrected) the example of using the library.

#### Enhancements:
- This update is aimed at expanding the functionality for processing arrays, and not sorting it (almost). The following is a list of what has been updated in the _ArrayProcessing_ class:
	1. Extended the **print()** method
	2. Swapped the **getMax()** and **getMin()** methods
	3. Added methods
		1. Flip backwards the array - **reverse()**
		2. Copy - **copy()**
		3. Finding the sum of elements - **sum()**
		4. Finding the arithmetic mean - **average()**
		5. Finding the median - **mediana()**
		6. Finding a Moda - **moda()**

~~Old tag 1.0.2~~

---

## v0.0.0.2 (01.10.2021) <- 「Fixes」

> _Minor edits_...

#### Bug Fixes:
- When the core of the library was built, everything was checked on arrays with integer element types. As a result, all algorithms using the swap method of the _ArrayProcessing_ class would not work. In addition, the last two algorithms are generally sharpened only for use with an integer type. I fixed all these errors:
	1. Removed template where it is not needed
	2. Fixed the passed type to the swap method of the _ArrayProcessing_ class
	3. In general, I fixed the passed types where they were incorrectly specified

~~Old tag 1.0.1~~

---

## v0.0.0.1 (29.09.2021) <- Alpha-release

#### Release
- A class has been written with methods for generating an array, displaying it on the screen, replacing two elements with places, finding the maximum and minimum number - _ArrayProcessing_ and classes of the following sorting algorithms:
	1. Insertion Sort
	2. Bubble Sort
	3. Shaker Sort
	4. Merge Sort
	5. Pyramid Sort (binary heap)
	6. Quick Sort
	7. Counting Sort (currently the fastest)
	8. Radix Sort

~~Old tag 1.0.0~~
