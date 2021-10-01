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
## v1.0.1 (DATE)

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
