# The history of adding new functionality by Committes
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
### Importance
1. namespaces
2. typedefs
3. functions
4. operators
5. enumerations
6. structures
7. classes
8. interfaces
9. variables

## v1.0.0.0

### commit a2f550

#### functions
- ALGOR::ARRAYDATA::cloneData(Array<type_array> *&)

## v0.1.3.0

### commit d66e53

#### namespaces
- ALGOR::RANDOM
#### variables
- ALGOR::EXCEPTION_SET::excep55
- ALGOR::EXCEPTION_SET::excep101
- ALGOR::EXCEPTION_SET::excep254
- ALGOR::EXCEPTION_SET::excep255
- ALGOR::EXCEPTION_SET::excep256
- ALGOR::EXCEPTION_SET::excep400
- ALGOR::EXCEPTION_SET::excep404

### commit 2cdff0

#### namespaces
- ALGOR::EXCEPTION_SET

### commit 98b663

#### functions
- ALGOR::Comparative_Sorts::Batcher_OddEven_MergeSort()
#### classes
- ALGOR::Comparative_Sorts::BatcherOddEvenMergeSort

### commit b50b4a

#### typedefs
- ALGOR::byte1_t
- ALGOR::byte2_t
- ALGOR::byte4_t
- ALGOR::byte8_t

### commit ca0704

#### functions
- ALGOR::RANDOM::LCM::LCM(memcell_t)
- ALGOR::RANDOM::LCM::rand()
- ALGOR::RANDOM::MersenneTwister::rand()
- ALGOR::RANDOM::test_random_on_Pearsons_coefficient(ubit32_t, ubit32_t)
- ALGOR::ARRAYDATA::generatedData(const sbit64_t &, const sbit64_t &, const ubit64_t, const ubit32_t)
#### classes
- ALGOR::RANDOM::LCM
#### variables
- ALGOR::RANDOM::LCM::a
- ALGOR::RANDOM::LCM::c
- ALGOR::RANDOM::LCM::m
- ALGOR::RANDOM::LCM::seed

### commit 5a7ff3

#### functions
- ALGOR::ARRAYDATA::getValue(const asize_t &)

### commit 045729

#### operators
- ALGOR::ARRAYDATA::operator=(Array<type_array> *&)
- ALGOR::ARRAYDATA::operator==(Array<type_array> *&)
- ALGOR::ARRAYDATA::operator^=(const asize_t &)

### commit 828901

#### functions
- ALGOR::ARRAYDATA::getSize()

### commit 391fff

#### structures
- ALGOR::ARRAYDATA::mode
#### variables
- ALGOR::ARRAYDATA::mode::highest_frequency

### commit 2c6408

#### functions
- ALGOR::EXCEPTION_SET::Exception::Exception(ubit16_t, const byte1_t *, const byte1_t *)
- ALGOR::EXCEPTION_SET::Exception::why()
- ALGOR::EXCEPTION_SET::memory_overflow::memory_overflow(const byte1_t *)
- ALGOR::EXCEPTION_SET::division_by_zero::division_by_zero(const byte1_t *)
- ALGOR::EXCEPTION_SET::position_failure::position_failure(const byte1_t *)
- ALGOR::EXCEPTION_SET::value_failure::value_failure(const byte1_t *)
- ALGOR::EXCEPTION_SET::size_failure::size_failure()
- ALGOR::EXCEPTION_SET::size_failure::size_failure(const byte1_t *)
- ALGOR::EXCEPTION_SET::void_data::void_data(const byte1_t *)
- ALGOR::EXCEPTION_SET::not_found::not_found(const byte1_t *)
#### classes
- ALGOR::EXCEPTION_SET::size_failure
#### variables
- ALGOR::EXCEPTION_SET::Exception::EXPLANATION

### commit b6349a

#### typedefs
- ALGOR::fbit128_t

## v0.1.2.1

### commit d94012

#### functions
- ALGOR::ArrayProcessing::upper_bound(type_array *, type_array *, const type_array &)

### commit ffc19f

#### functions
- ALGOR::ArrayProcessing::distance(type_array *, type_array *)
- ALGOR::ArrayProcessing::lower_bound(type_array *, type_array *, const type_array &)
- ALGOR::Comparative_Sorts::Bitonic_Sorter()
- ALGOR::Comparative_Sorts::Tim_Sort()
- ALGOR::Comparative_Sorts::Pancake_Sort()

## v0.1.2.0

### commit 52d263

#### functions
- ALGOR::Comparative_Sorts::Comparative_Sorts(Array<type_array> *&)
#### classes
- ALGOR::Comparative_Sorts

### commit 1981d6

#### typedefs
- ALGOR::fbit32_t
- ALGOR::fbit64_t
#### classes
- ALGOR::ArrayProcessing

### commit 2fa93b

#### namespaces
- ALGOR
#### functions
- ALGOR::Printer::print()
- ALGOR::ArrayProcessing::isOrderliness(const type_array *, const asize_t &)
#### interfaces
- ALGOR::Printer

### commit 197603

#### functions
- ALGOR::Distribution_Sorts::Distribution_Sorts(Array<byte8_t> *&)
- ALGOR::Distribution_Sorts::AmericanFlag_Sort()
- ALGOR::Distribution_Sorts::Bead_Sort()
- ALGOR::Distribution_Sorts::Bucket_Sort()
- ALGOR::Distribution_Sorts::Counting_Sort()
- ALGOR::Distribution_Sorts::Interpolation_Sort()
- ALGOR::Distribution_Sorts::Pigeonhole_Sort()
- ALGOR::Distribution_Sorts::Radix_Sort()
- ALGOR::Distribution_Sorts::Flash_Sort()
#### classes
- ALGOR::Distribution_Sorts

### commit d74cc1

#### functions
- ALGOR::EXCEPTION_SET::division_by_zero::division_by_zero()
#### classes
- ALGOR::EXCEPTION_SET::division_by_zero
- ALGOR::Distribution_Sorts::FlashSort

### commit d3274a

#### classes
- ALGOR::Distribution_Sorts::InterpolationSort

### commit f6f6fe

#### classes
- ALGOR::Distribution_Sorts::AmericanFlagSort

## v0.1.1.4

### commit b19f70

#### functions
- ALGOR::Comparative_Sorts::Merge_Sort()
#### classes
- ALGOR::Distribution_Sorts::BeadSort
- ALGOR::Distribution_Sorts::BucketSort

### commit 090b06

#### functions
- ALGOR::minimum(type_value, type_value)
- ALGOR::maximum(type_value, type_value)
#### classes
- ALGOR::Comparative_Sorts::TimSort
- ALGOR::Distribution_Sorts::PigeonholeSort

## v0.1.1.3

### commit f81852

#### functions
- ALGOR::Comparative_Sorts::Insert_Sort()
- ALGOR::Comparative_Sorts::Shell_Sort()
- ALGOR::Comparative_Sorts::Tree_Sort()
- ALGOR::Comparative_Sorts::Patience_Sort()

### commit b4cdc9

#### typedefs
- ALGOR::memcell_t
#### functions
- ALGOR::getMemoryCell(memcell_t, memcell_t)
- ALGOR::Comparative_Sorts::Library_Sort()
#### classes
- ALGOR::Comparative_Sorts::LibrarySort

## v0.1.1.2

### commit 28f51f

#### functions
- ALGOR::Comparative_Sorts::Selection_Sort()
- ALGOR::Comparative_Sorts::Heap_Sort()
- ALGOR::Comparative_Sorts::Cycle_Sort()

### commit 343e40

#### structures
- ALGOR::Comparative_Sorts::TreeSort::Tree
#### classes
- ALGOR::Comparative_Sorts::PatienceSort
- ALGOR::Comparative_Sorts::TreeSort

### commit 46c223

#### functions
- ALGOR::Comparative_Sorts::Bubble_Sort()
- ALGOR::Comparative_Sorts::Cocktail_Shaker_Sort()
- ALGOR::Comparative_Sorts::Odd_Even_Sort()
- ALGOR::Comparative_Sorts::Comb_Sort()
- ALGOR::Comparative_Sorts::Gnome_Sort()
- ALGOR::Comparative_Sorts::Quick_Sort()
- ALGOR::Comparative_Sorts::Slow_Sort()
- ALGOR::Comparative_Sorts::Stooge_Sort()
- ALGOR::Comparative_Sorts::Bogo_Sort()

### commit 303e5b

#### classes
- ALGOR::Comparative_Sorts::BitonicSorter
- ALGOR::Comparative_Sorts::PancakeSort

### commit 49dffe

#### classes
- ALGOR::Comparative_Sorts::CycleSort

## v0.1.1.1

### commit 800c0d

#### classes
- ALGOR::Comparative_Sorts::ShellSort
- ALGOR::Comparative_Sorts::SlowSort

### commit f338fc

#### classes
- ALGOR::Comparative_Sorts::BogoSort
- ALGOR::Comparative_Sorts::CombSort
- ALGOR::Comparative_Sorts::GnomeSort
- ALGOR::Comparative_Sorts::OddEvenSort
- ALGOR::Comparative_Sorts::SelectionSort
- ALGOR::Comparative_Sorts::StoogeSort

## v0.1.1.0

### commit bce6b6

#### functions
- ALGOR::EXCEPTION_SET::memory_overflow::memory_overflow()
- ALGOR::ARRAYDATA::~ARRAYDATA()
#### classes
- ALGOR::EXCEPTION_SET::memory_overflow

### commit 8bbf75

#### functions
- ALGOR::EXCEPTION_SET::position_failure::position_failure()
- ALGOR::EXCEPTION_SET::value_failure::value_failure()
- ALGOR::ArrayBase::verification(Array<type_array> *)
#### classes
- ALGOR::EXCEPTION_SET::position_failure
- ALGOR::EXCEPTION_SET::value_failure

### commit c62e85

#### functions
- ALGOR::EXCEPTION_SET::Exception::Exception(ubit16_t, const byte1_t *)
- ALGOR::EXCEPTION_SET::Exception::Exception(ubit16_t)
- ALGOR::EXCEPTION_SET::Exception::Exception(const byte1_t *)
- ALGOR::EXCEPTION_SET::Exception::code()
- ALGOR::EXCEPTION_SET::Exception::what()
- ALGOR::EXCEPTION_SET::void_data::void_data()
- ALGOR::EXCEPTION_SET::not_found::not_found()
#### classes
- ALGOR::EXCEPTION_SET::Exception
- ALGOR::EXCEPTION_SET::void_data
- ALGOR::EXCEPTION_SET::not_found
#### variables
- ALGOR::EXCEPTION_SET::Exception::CODE
- ALGOR::EXCEPTION_SET::Exception::DETAILS

## v0.1.0.0

### commit 89658e

#### typedefs
- ALGOR::asize_t

### commit 0d3195

#### typedefs
- ALGOR::sbit8_t
- ALGOR::sbit16_t
- ALGOR::sbit32_t
- ALGOR::sbit64_t
- ALGOR::ubit8_t
- ALGOR::ubit16_t
- ALGOR::ubit32_t
- ALGOR::ubit64_t

### commit 88415c

#### functions
- ALGOR::RANDOM::RC4::crypto_srand(const byte1_t *, byte4_t)
- ALGOR::RANDOM::RC4::crypto_rand(byte1_t *, byte4_t)
- ALGOR::RANDOM::MersenneTwister::MersenneTwister(byte4_t)
- ALGOR::RANDOM::MersenneTwister::RandomInit(byte4_t)
- ALGOR::RANDOM::MersenneTwister::IRandom(byte4_t, byte4_t)
- ALGOR::RANDOM::MersenneTwister::IRandomX(byte4_t, byte4_t)
- ALGOR::RANDOM::MersenneTwister::Random()
- ALGOR::RANDOM::MersenneTwister::BRandom()
- ALGOR::RANDOM::MersenneTwister::Init0(byte4_t)
#### classes
- ALGOR::RANDOM::RC4
- ALGOR::RANDOM::MersenneTwister
#### variables
- ALGOR::RANDOM::RC4::Sbox
- ALGOR::RANDOM::MersenneTwister::mersenne_twister
- ALGOR::RANDOM::MersenneTwister::mersenne_twister_index
- ALGOR::RANDOM::MersenneTwister::LastInterval
- ALGOR::RANDOM::MersenneTwister::RejectionLimit

### commit dd5d42

#### functions
- ALGOR::ARRAYDATA::cloneNewData(Array<type_array> *&)
- ALGOR::ARRAYDATA::replace(const asize_t &, const type_array &)
- ALGOR::ARRAYDATA::respawn()
#### operators
- ALGOR::ARRAYDATA::operator*=(const type_array &)
- ALGOR::ARRAYDATA::operator/=(const type_array &)
- ALGOR::ARRAYDATA::operator&=(const type_array &)
- ALGOR::ARRAYDATA::operator|=(const type_array &)
- ALGOR::ARRAYDATA::operator!()
- ALGOR::ARRAYDATA::operator<<=(ARRAYDATA<type_array> *&)
- ALGOR::ARRAYDATA::operator>>=(ARRAYDATA<type_array> *&)

### commit 37cab7

#### functions
- ALGOR::ArrayProcessing::subtractElement(type_array *&, asize_t &, const asize_t)
- ALGOR::ArrayProcessing::subtractValue(type_array *&, asize_t &, const type_array &)

### commit 1f2a4f

#### functions
- ALGOR::ARRAYDATA::setNewData(Array<type_array> *&)
- ALGOR::ARRAYDATA::setData(Array<type_array> *&)
- ALGOR::ARRAYDATA::reset()
- ALGOR::ARRAYDATA::operator+=(const type_array &)
- ALGOR::ARRAYDATA::operator-=(const type_array &)

### commit 1d50a2

#### functions
- ALGOR::ArrayBase::ArrayBase(const asize_t &)
- ALGOR::ARRAYDATA::ARRAYDATA(const asize_t &)

### commit 48aa64

#### functions
- ALGOR::remove_struct(Array<type_array> *&)
- ALGOR::ArrayBase::ArrayBase()
- ALGOR::ARRAYDATA::ARRAYDATA(Array<type_array> *&)
- ALGOR::ARRAYDATA::getData()
- ALGOR::ARRAYDATA::getMin()
- ALGOR::ARRAYDATA::getMax()
- ALGOR::ARRAYDATA::remove()

### commit 46b2fa

#### functions
- ALGOR::ARRAYDATA::resize(const asize_t &, const type_array &)

### commit 6efeb8

#### functions
- ALGOR::ArrayBase::ArrayBase(Array<type_array> *&)
#### classes
- ALGOR::ArrayBase
#### variables
- ALGOR::ArrayBase::ARRAY

### commit 85698d

#### functions
- ALGOR::create_struct(const asize_t &, bool)
#### enumerations
- ALGOR::ARRAYDATA::ArrayType
#### variables
- ALGOR::ARRAYDATA::ArrayType::NUMBER
- ALGOR::ARRAYDATA::ArrayType::STRING

## v0.0.1.0

### commit 979bf4

#### structures
- ALGOR::Array
#### variables
- ALGOR::Array::array
- ALGOR::Array::array_size

### commit e37003

#### functions
- ALGOR::ArrayProcessing::addElement(type_array *&, asize_t &, const type_array &, const asize_t)
- ALGOR::ARRAYDATA::searcherOccurrencesOfSubstring(Array<type_array> *&, ArrayType)

### commit 0c1496

#### functions
- ALGOR::ARRAYDATA::binary_getPosition(const type_array &)
- ALGOR::ARRAYDATA::lenear_getPosition(const type_array &)

## v0.0.0.3

### commit 1a11a0

#### functions
- ALGOR::ArrayProcessing::copy(type_array *, const type_array *, const asize_t &, asize_t, asize_t)
- ALGOR::ARRAYDATA::average()
- ALGOR::ARRAYDATA::mediana()
- ALGOR::ARRAYDATA::moda()

### commit 05d8b0

#### functions
- ALGOR::ARRAYDATA::reverse()

## v0.0.0.1

#### functions
- ALGOR::swap(type_value &, type_value &)
- ALGOR::ArrayProcessing::minimum(const type_array *, const asize_t &)
- ALGOR::ArrayProcessing::maximum(const type_array *, const asize_t &)
- ALGOR::generate_struct(Array<type_array> *&, const sbit64_t &, const sbit64_t &, const ubit64_t, const ubit32_t)
#### classes
- ALGOR::ARRAYDATA
- ALGOR::Comparative_Sorts::BubbleSort
- ALGOR::Comparative_Sorts::CocktailShakerSort
- ALGOR::Comparative_Sorts::HeapSort
- ALGOR::Comparative_Sorts::InsertSort
- ALGOR::Comparative_Sorts::MergeSort
- ALGOR::Comparative_Sorts::QuickSort
- ALGOR::Distribution_Sorts::CountingSort
- ALGOR::Distribution_Sorts::RadixSort
