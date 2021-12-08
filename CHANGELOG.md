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

---

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

---

## v1.0.1 (01.10.2021)

#### Bug Fixes:
- When the core of the library was built, everything was checked on arrays with integer element types. As a result, all algorithms using the swap method of the _ArrayProcessing_ class would not work. In addition, the last two algorithms are generally sharpened only for use with an integer type. I fixed all these errors:
    1. Removed template where it is not needed
    2. Fixed the passed type to the swap method of the _ArrayProcessing_ class
    3. In general, I fixed the passed types where they were incorrectly specified

---

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
