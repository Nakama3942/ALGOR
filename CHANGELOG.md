# Changelog
<!--
## vX.X.X (DATE)

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

## v2.1.1 (26.03.2022)

#### Enhancements:
- Added SelectionSort and SmoothSort to the Selection_Sorts namespace; ShellSort in Insertion_Sorts and all remaining algorithms with Exchange_Sorts, namely OddEvenSort, CombSort, GnomeSort, SlowSort, StoogeSort and BogoSort. After implementing all the algorithms with Exchange_Sorts, I finally got the opportunity to combine them into one class.

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

## v2.1.0 (11.01.2022)

#### Bug Fixes:
- The remove () method is now private. Now the ARRAYDATA class cannot store a pointer to nullptr, therefore the object will constantly store some kind of array, which will increase the fault tolerance of the ARRAYDATA class.
- Added more checks and now, in case of an error, the program will not crash, but throw exceptions that the programmer can catch.

#### Documenting:
- I started documenting the library. True, the documentation is not yet available and is under development. At the moment, the sorting algorithms are generally undocumented, and everything else is documented at the brief and param levels. All warnings, notes, details, etc. will be described after the completion of the development of the second version of the library, i.e. before version 3.0.0.

#### Enhancements:
- Written class for working with exceptions - Exception. All exceptions that are thrown by the library now throw objects inherited from Exception, which stores information about the error and can return this information at the request of the programmer. The programmer can also create his own exception classes inherited from Exception.

## v2.0.0 (23.12.2021)

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

## v1.1.0 (05.11.2021)

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

## v1.0.2 (16.10.2021)

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

## v1.0.1 (01.10.2021)

#### Bug Fixes:
- When the core of the library was built, everything was checked on arrays with integer element types. As a result, all algorithms using the swap method of the _ArrayProcessing_ class would not work. In addition, the last two algorithms are generally sharpened only for use with an integer type. I fixed all these errors:
    1. Removed template where it is not needed
    2. Fixed the passed type to the swap method of the _ArrayProcessing_ class
    3. In general, I fixed the passed types where they were incorrectly specified

## v1.0.0 (29.09.2021)

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
