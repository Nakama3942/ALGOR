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
## v1.0.2 (16.10.2021)

#### Enhancements:
- This update is aimed at expanding the functionality for processing arrays, and not sorting it (almost). The following is a list of what has been updated in the ArrayProcessing class:
    1. Extended the print() method
    2. Swapped the getMax() and getMin() methods
    3. Added methods
        1. Flip backwards the array - reverse()
        2. Copy - copy()
        3. Finding the sum of elements - sum()
        4. Finding the arithmetic mean - average()
        5. Finding the median - mediana()
        6. Finding a Moda - moda()

#### Bug Fixes:
- And also additionally I:
    - corrected the last typos and mistakes that I missed last time;
    - optimized the counting_sort() method, in which now the finding of the minimum and maximum elements is not copied, but the call to already existing methods is in progress;
    - added license protection and a label that will point to the current version of the library;
    - and lastly updated (corrected) the example of using the library.

---

## v1.0.1 (01.10.2021)

#### Bug Fixes:
- When the core of the library was built, everything was checked on arrays with integer element types. As a result, all algorithms using the swap method of the ArrayProcessing class would not work. In addition, the last two algorithms are generally sharpened only for use with an integer type. I fixed all these errors:
    1. Removed template where it is not needed
    2. Fixed the passed type to the swap method of the ArrayProcessing class
    3. In general, I fixed the passed types where they were incorrectly specified

---

## v1.0.0 (29.09.2021)

#### Release
- A class has been written with methods for generating an array, displaying it on the screen, replacing two elements with places, finding the maximum and minimum number - ArrayProcessing and classes of the following sorting algorithms:
    1. Insertion Sort
    2. Bubble Sort
    3. Shaker Sort
    4. Merge Sort
    5. Pyramid Sort (binary heap)
    6. Quick Sort
    7. Counting Sort (currently the fastest)
    8. Radix Sort
