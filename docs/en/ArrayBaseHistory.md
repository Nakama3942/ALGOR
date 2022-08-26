# History of the array Base class (class ArrayBase) or Gray Cardinal in ALGOR
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
Unlike other classes, the ALGOR::ArrayBase class has the most varied and interesting history. Its evolution took place 4 commits in a row and from the first implementation it carried a slightly different meaning of its existence...

## Prehistory

As you know, with the beginning of the "Titanic Breakup" (*commit 85698d*) many classes were created, and all implemented material was divided into sections and transferred to one or another file responsible for the required section. And then these sections begin to be divided into announcements and implementations. But such a scheme was not very convenient and all files with announcements began to be combined into one, and files with implementations into a second file. This resulted in me being able to reclassify the library from static to dynamic (which I had planned from the start) and implement the project structure a bit better. Commit *6efeb8* became the last unifying commit, after which only two raw files will remain: declarations and implementations.

## First Committee 6efeb8 V0.1.0.0 ("Improving Sorting Classes")

I already planned to implement all sorting algorithms and prepared their categorization. Then I noticed that all algorithms work with arrays (captain obvious), so why write a private array structure field in each class, if you can implement a base class with this field and simply inherit from it. It will take up less space... That's how this base class appeared. It was called SortingBase, had one constructor and a field for storing a pointer to the array structure. This was his whole task...

## Second Committee 46b2fa V0.1.0.0 ("Classification")

Actually, there was one commit missed between the first and the second, but it only replaced the example... Now to the point. At the time of the previous commit *6efeb8* ArrayProcessing was already split: ArrayCharacteristic was separated from it. At the time of the current commit, the ArrayGetter forked. At that time, I did not plan to combine them back into one single class, as was the case before. And most importantly, I renamed the base class from SortingBase to ArrayData. And no, it is in no way related to the modern ARRAYDATA... The story will be more interesting...

## Third Committe 48aa64 V0.1.0.0 ("Classification - Continue")

Then I came up with the following scheme:
> And what if I combine these classes back into a single class, but now the methods will not be static and used as functions from the namespace, but will be full-fledged methods for which you need to create an object of the class? You have to experiment! But what about those functions used by sorting algorithms? I'll move them out of the Array section and into the Core section!

So I singled out:
	- swap (which is now ALGOR::swap)
	- minimum (which is now ALGOR::ArrayProcessing::minimum)
	- maximum (which is now ALGOR::ArrayProcessing::maximum)
	- addElement (which is now ALGOR::ArrayProcessing::addElement)
	- copy (which is now ALGOR::ArrayProcessing::copy)

I don't remember why the last two features were removed then, but it makes sense now that it was a good decision back then.

Everything else I combined back into one single class. And then it became clear that I can do the same as with sorting algorithms: inherit from the base class of arrays and use a ready-made constructor and a storage field for a pointer to the array structure. In short, I realized that creating an array base class was a very good and versatile idea! That is why the base class was renamed in the last commit, and the new class is still called ArrayProcessing. Everything is logical: the base class stores a pointer to the array structure, so it is Data, and the big class with processing methods is Processing...

## Fourth Committe 1d50a2 V0.1.0.0 ("Final typing")

The last chapter with a climax and plot twist. And yes, we have a basic class; there is a class for working with arrays, inherited from our class; and there are classes of sorting algorithms that are also inherited from our class... What can this happen? And the whole thing is that after the previous commit, I compared the class names for sorting algorithms and thought the following:
> And does this name really fit the base class? It would be more logical to inherit from the base class in the literal sense, rather than from a class that may have additional functionality. After all, if the class will be called ArrayData, it may mean that not only data is stored there, but there may be some methods of processing it...

I felt the same doubt when I applied this picture to the array processing class:
> ArrayData class can have some functionality and ArrayProcessing can extend it...

I could do this and leave the methods I moved to the core in the base class, but then how do I give access to the swap function? Illogically.

And here I decided to rename the classes for the second time: the base class was called ArrayBase, and ArrayProcessing was called ARRAYDATA. Yes! Exactly! Modern names have nothing to do with the old ones! And everything fell into place... Everything is logical... ArrayBase will only store ready-made constructors and a field for a pointer to an array structure, ARRAYDATA inherits from the base class and extends it with methods for handling arrays, and sorting algorithm classes inherit from the base class so that they can sort these arrays.

## Our times (V1.0.0)

After that, there were many more changes... I'll start with the less interesting. With the expansion of the number of implemented sorting algorithms, I realized that it is not so convenient to work with these algorithms as they are implemented now. I combined the classes in each category into one class that holds the inner classes. Then these classes of categories will be combined into one class and only a class with algorithms working with any data and a class of algorithms working only with int will remain. And those classes that were inherited and became internal are now not inherited from the base class, but store the array itself and its size separately from each other, and if necessary, the programmer can create an object of the algorithm itself and pass it directly to it the array and size, and can create a category object and pass a pointer to the structure. Now the categories themselves are inherited...

Let's return to the functions. As I said, 5 functions were isolated, 4 of which work only with arrays... So why were they isolated. Over time, minimum (namely ALGOR::minimum) and maximum (namely ALGOR::maximum) function overloads appeared, getMemoryCell (now ALGOR::getMemoryCell) appeared. Apart from these, all other functions were related to arrays... Then I split them, where part (swap, minimum, maximum and getMemoryCell) remained the core, and all others revived the very first ArrayProcessing in the array section.

## Result

So we have that modern ArrayProcessing has nothing in common with the original ArrayProcessing with which the library was created. But it (the original ArrayProcessing) did not fade into Oblivion... It evolved into a multifunctional ARRAYDATA. And it was the basic class ArrayBase that led to these changes, which was originally supposed to be just a code abbreviation for sorting algorithms. And as we can see, modern internal classes each save the array and its size by themselves without using the ArrayBase written for them. Everything has changed. <del>Santa Barbara smokes nervously on the sidelines...</del>

## Graph
<!--The image is not displayed on Hithabi.This readme is configured under documentation.Doxygen is working perfectly and the image documentation website is displayed-->
<img src="ArrayProcessingFamilyTree.png" width="950px;" alt=""/>