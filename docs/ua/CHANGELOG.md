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
## v1.0.0.0 (29.08.2022)

> *Задокументовано усе на світі*...

### Документування:
- Повністю у всіх деталях задокументовано увесь функціонал бібліотеки до найменших деталей!
- Написано багато прикладів, що описують увесь функціонал бібліотеки у всіх деталях.
- Переписано README.md: дописано багато важливих деталей типу Ліценції, Збірки бібліотеки тощо.
- Додані пояснюючі гіфки до README.md.
- Переписано CHANGELOG.md: прибрано багато зайвого непотрібного тексту, що тільки заважає.
- Створено сайт з документацією та додано посилання до репозиторію.

### Покращення:
- Було перерозподілено файлову структуру проекту:
	- Файли заголовків розташовуються у піддиректорії *include*;
	- Файли реалізацій розташовуються у піддиректорії *src*;
	- Файли тестів розташовуються у піддиректорії *test*;
	- Файли зображень розташовуються у піддиректорії *img*;
	- Файли прикладів розташовуються у піддиректорії *example*;
	- Файли документації розташовуються у піддиректорії *docs*;
	- Файли збірки розташовуються у піддиректорії *build*;
- Файли реалізацій знову розподілено кожен за своєю категорією;
- Оптимізовано метод **searcherOccurrencesOfSubstring()**;
- Реалізовано новий метод **cloneData()** (точніше, старий **cloneData()** було перейменовано на **cloneNewData()** і додано новий **cloneData()** з іншою реалізацією);
- Створено зручну систему збірки бібліотеки під платформи Windows та Linux (makefile та test.sh);
- Тепер увесь функціонал компілюється під **будь-які типи** (через що збільшено час на компіляцію та вагу бібліотеки).

---

## v0.1.3.0 (24.06.2022)

> *Доведено структуру проекту до остаточного вигляду*...

### Виправлення непрацездатного функціоналу:
- Замінено непрацюючий *SmoothSort* на *BatcherOddEvenMergeSort*.

### Документування:
- Повернено усе документування назад у хідер. Йде підготовка до написання документації.
- CHANGELOG переписано під новий стиль оформлення.

### Покращення:
- Додано:
	- Окрему функцію генерування масивів, яку використовує клас;
	- Нові ґеттери: **getPosition()** та **getValue()**;
	- Лінійний Конґруентний Метод ГПСЧ та функцію тестування Рандомізаторів на рівномірність генерування чисел, що використовує критерій узгодженості Пірсона;
	- Нові оператори: ^=, =, ==;
- Оптимізовано:
	- **swap()**;
	- **resize()** (сильно оптимізував);
- Замінено:
	- Реалізації методів **reset()** та **respawn()** місцями;
	- Бінарний пошук (тепер він схожий на той бінарний пошук, що було реалізовано для _LibrarySort_);
- Переписано:
	- Усі стандартні типи на оголошені аліаси;
	- Гігантську частину коду, замінивши примусову компіляцію *методів* на примусову компіляцію *класів*;
	- Визначено типи, з якими тепер будуть компілюватися функції та класи (_**byte8_t** == long long int_, _**ubit64_t** == unsigned long long int_, _**fbit64_t** == double_, _**fbit128_t** == long double_, _**asize_t** == unsigned int_);
	- Повністю переписав старі оператори (у деяких замінено навіть призначення);
- Тестування:
	- Написано окремі програми для тестування бібліотеки;
	- Повністю протестовано всі алгоритми сортування;
- Перевірка масиву:
	- Функція верифікації доведена до остаточного вигляду: тепер це метод базового класу масивів, що використовується при збереженні до об'єкту класу данних;
- Об'єднано:
	- Усі базові функції до базового класу, переписавши їх під статичні методи;
	- Методи **moda()** та **modas()** до одного методу, так як було створено для них їх власну структуру й обидві вони тепер повертають вказівник на цю структуру, а другий метод використовує перший (метод) і трохи поширює результат (так який у цьому сенс, якщо їх об'єднати - нічого не зміниться);
	- Усі виключення в простір імен *EXCEPTION_SET*;
	- Усі Рандомізатори в простір імен *RANDOM*;
	- Обидві категорії (класи) сортувань в простір імен *SORTING*;
- Ререліз:
	- Замінено версії релізів (тепер реліз бібліотеки *v1.0.0.0* відбудеться тільки після завершення повного документування).

---

## v0.1.2.1 (03.06.2022)

> *"Прєісполнился в познаніі" вказівників*...

### Покращення:
- Додано нові функції:
	1. **array_size_verification()** - створює виняток, якщо масив порожній (тобто його розмір дорівнює нулю);
	2. **distance()** - повертає відстань між початком і кінцем вказаного діапазону масиву;
	3. **lower_bound()** - повертає вказівник на перше входження вказаного значення у заданому діапазоні (масив потрібно відсортувати; функція схожа на двійковий пошук);
	4. **upper_bound()** - повертає вказівник на перше входження наступного значення після вказаного значення у заданому діапазоні (масив потрібно відсортувати; функція, схожа на двійковий пошук).
- Завершено:
	- Алгоритм сортування **Bitonic_Sorter** з категорії *ConcurrentSort*;
	- Алгоритм сортування **Tim_Sort** з категорії *HybridSorts*;
	- Алгоритм сортування **Pancake_Sort** з категорії *OtherSorts*;
	- Алгоритм сортування **Library_Sort** з категорії *InsertionSorts*.
- Видалено налаштування: оскільки більше немає розділу зі стандартними бібліотеками (для **Library_Sort** було реалізовано власні **distance()** та **lower_bound()**) - більше немає мети ділити проект на розділи, які можна включити і виключити на компіляцію.
- Десять нереалізованих алгоритмів сортування, які не планується реалізовувати найближчим часом:
	1. **BatcherOddEvenMergeSort** з *ConcurrentSort*;
	2. **PairwiseSortingNetwork** з *ConcurrentSort*;
	3. **SampleSort** з *ConcurrentSort*;
	4. **BlockMergeSort** з *HybridSorts*;
	5. **KirkpatrickReischSort** з *HybridSorts*;
	6. **IntroSort** з *HybridSorts*;
	7. **SpreadSort** з *HybridSorts*;
	8. **MergeInsertionSort** з *HybridSorts*;
	9. **TopologicalSort** з *OtherSorts*;
	10. **SpaghettiSort** з *OtherSorts*.

---

## v0.1.2.0 (15.04.2022)

> *Була обдумана ідея про глобальний простір імен усього проекту*...

### Покращення:
- Починаючи з версії v0.0.0.1, лише **CountingSort** та **RadixSort** були реалізовані з категорії *Distribution_Sorts*. Нарешті було завершено останню групу тих алгоритмів, які були присутні з самого початку. У оновленні було реалізовано **AmericanFlagSort**, **BeadSort**, **BucketSort**, **FlashSort**, **InterpolationSort**, **PigeonholeSort** і відмовлено від **BurstSort** та **ProxmapSort**.
- З реалізацією цієї категорії було придумано функцію, яка призначена для заміни **time(NULL)** (ну, нарешті), а також перевизначив функції **minimum()** і **maximum()** - тепер вони повертають не тільки найменше/найбільше число, знайдене в масиві, а й найменше/найбільше з двох заданих значень. Поширення функцій, не пов'язаних із масивом, призвело до розділення функцій з ядра на функції, пов'язані з масивами та не пов'язані з масивами. Останній залишився в ядрі, тоді як перший перемістився до підрозділу обробки масивів, а оскільки базові класи сортування (наприклад, категорії) успадковані від базового класу масиву, підрозділ обробки масиву в цілому перемістився з "під" розділу алгоритмів сортування на "над" розділ сортування.
- Об'єднано в один клас усі загальні класи алгоритмів сортування, які можуть сортувати не тільки int-масиви. Тепер у підрозділі алгоритмів сортування є лише два класи алгоритмів сортування: ті, що підтримують будь-які типи масивів, і ті, що працюють тільки з int-масивами. Тимчасово, на момент впровадження останніх категорій алгоритмів сортування, три останні класи з наступними трьома оновленнями будуть випущені окремими класами, але після цього планується об'єднати їх з першим класом.
- І, нарешті, доопрацьовано систему налаштувань. Тепер ядро бібліотеки, винятки та рандомайзери не можна вимкнути для компілятора, проте вже можна вимкнути підсекції обробки та сортування масивів. Також можна буде вмикати та вимикати на компіляцію додаткові алгоритми та структури даних, які будуть реалізовані в майбутньому. Наприкінці випусків із реалізацією алгоритмів сортування планується повернутися до **LibrarySort** і все одно реалізувати власні аналоги **std::distance()** і **std::lower_bound()**, щоб повернути цей алгоритм до бібліотеки на постійно і надати до нього повний доступ. Якщо це вдасться зробити - можна буде повністю відмовитися від підрозділу зі стандартними бібліотеками (що було початковою ідеєю проекту), якщо туди не потрапить ще кілька алгоритмів сортуваннь...
- Було реалізовано глобальний простір імен для усієї бібліотеки. Весь функціонал було додано до цього простору імен. Так як деякі назви функцій схожі з назвами стандартних функцій std, обидва простори імен використовувати однеочасно неможливо!

Тепер неможливо використовувати:
```cpp
using namespace std;
using namespace ALGOR;
```
Це не залежить від порядку. Потрібно лише вибрати один з них! Це завершення розробки структури проекту!

---

## v0.1.1.4 (04.04.2022)

> *Завершено четверту категорію алгоритмів сортування*...

### Покращення:
— Автор спробував ознайомитись з **CascadeMergeSort**, **OscillatingMergeSort** та **PolyphaseMergeSort**, але інформації про них майже немає (навіть у Вікіпедії). Було вирішено відмовитися від цих алгоритмів і виявилося, що в цій категорії є тільки один алгоритм, який вже реалізований. Його було переписано під новий стандарт.

---

## v0.1.1.3 (01.04.2022)

> *Завершено третю категорію алгоритмів сортування*...

### Покращення:
- Реалізовано наступні алгоритми сортування: **TreeSort**, **PatienceSort** та **LibrarySort** та об'єднав їх із **InsertSort** (окрім **LibrarySort**) в один клас.
- Оскільки у **LibrarySort** неможливо обійтися без стандартних бібліотек <s>(використовуються функції distance() та lower_bound())</s>, вирішено зробити його окремим класом. Це ускладнило структуру та поділ бібліотеки на два варіанти - із стандартними бібліотеками та без них.
- Тепер у верхній частині заголовка будуть розташовані налаштування. Залежно від значення #define STANDARDS_SWITCH, бібліотека буде скомпільована з цими алгоритмами (що потребують стандартних бібліотек) або без них. "0" - без бібліотек, "1" - з бібліотеками.
- На випадок, якщо програміст буде використовувати розділ зі стандартними бібліотеками, довелося розмістити деякі стандартні функції в класі Core, щоб уникнути конфліктів.

---

## v0.1.1.2 (30.03.2022)

> *Завершено другу категорію алгоритмів сортування*...

### Покращення:
- Реалізовано наступний алгоритм сортування: **CycleSort**; об'єднано їх разом з **HeapSort** (всього чотири алгоритми) в один клас - *Selection_Sorts*.
- Від алгоритмів **CartesianTreeSort**, **TournamentSort**, **WeakHeapSort** було вирішено відмовитись через їх дуже складну реалізацію та відсутність прикладів реалізацій. Можливо, колись я їх реалізую...

---

## v0.1.1.1 (26.03.2022)

> *Завершено першу категорію алгоритмів сортування*...

### Покращення:
- До простору імен *Selection_Sorts* додано **SelectionSort** та **SmoothSort**; **ShellSort** у *Insertion_Sorts* та всі алгоритми, що залишилися з *Exchange_Sorts*, а саме **OddEvenSort**, **CombSort**, **GnomeSort**, **SlowSort**, **StoogeSort** та **BogoSort**. Після реалізації всіх алгоритмів з *Exchange_Sorts* нарешті отримано можливість об'єднати їх в один клас.

Тепер для виклику НЕ потрібно писати довгу команду, наприклад
```cpp
Selection_Sorts::HeapSort<int> *sort = new Selection_Sorts::HeapSort<int>(ArrayStruct);
sort->start_sort();
```
як треба було раніше для всіх інших просторів імен. Тепер достатньо ввести наступну команду
```cpp
Exchange_Sorts<int> *sort = new Exchange_Sorts<int>(ArrayStruct);
sort->Stooge_Sort(); // Or some other
```
Як видно, тепер достатньо створити об'єкт класу і вибрати в ньому потрібний алгоритм сортування.

---

## v0.1.1.0 (11.01.2022)

> *Переосмислено безпеку зберігання даних*...

### Виправлення помилок:
- Метод **remove()** тепер приватний. Тепер клас ARRAYDATA не може зберігати вказівник на nullptr, тому об'єкт буде постійно зберігати якийсь масив, що підвищить відмовостійкість класу ARRAYDATA.
- Додано більше перевірок і тепер, у разі помилки, програма не буде аварійно завершуватись з помилкою виконання, а викидатиме винятки, які може зловити програміст.

### Документування:
- Бібліотека почала документуватись. Правда, документації ще немає і знаходиться на стадії розробки. На даний момент алгоритми сортування недокументовані, а все інше задокументовано на рівні brief та param. Усі попередження, примітки, деталі тощо будуть описані після завершення розробки релізу бібліотеки, тобто до релізу v1.0.0.0.

### Покращення:
- Написано клас для роботи з винятками - Exception. Усі винятки, які створює бібліотека, тепер викидають об'єкти, успадковані від Exception, який зберігає інформацію про помилку і може повернути цю інформацію на запит програміста. Програміст також може створити власні класи винятків, успадковані від Exception.

---

## v0.1.0.0 (23.12.2021)

> *Створення великого класу із гігантськими можливостями форматування даних у масивах*...

### Покращення:
- Які функції переписані, перейменовані, а які по-справжньому нові, сказати важко. Тому оновлення буде описано так:
	- Видалено:
		1. Клас **ArrayProcessing** з усіма його методами, але функціональність і алгоритми не викидаються на сміття, а переписуються на нові методи та функції.
	- Нова структура проекту:
		1. *ALGOR_CORE*
		2. *ALGOR_EXCEPTION* (буде випущено у версії v0.1.1.0)
		3. *ALGOR_RANDOM*
		4. *AlGOR_SORTING* (функціонал буде розширено у версіях v0.1.1.1 - v0.1.1.X)
		5. *AlGOR_ARRAY*
		6. *ALGOR_MATRIX* (почне випускатись з версії v1.0.0.0)
		7. *AlGOR_HEAP* (почне випускатись з версії v2.0.0.0)
		8. *AlGOR_LIST* (почне випускатись з версії v3.0.0.0)
	- Нові класи:
		1. *RC4* - простий криптографічний рандомайзер (його функціональність буде додатково розширена);
		2. *MersenneTwister* - розширений рандомайзер (його функціональність буде додатково розширена);
		3. *ARRAYDATA* - клас для роботи з масивами.
	- Функціонал ARRAYDATA:
		1. **Constructors** - приймають структуру або розмір масиву при створенні об'єкта;
		2. **generatedData()** - генерує елементи масиву;
		3. **setNewData()** - видаляє старий масив і зберігає покажчик на новий;
		4. **setData()** - зберігає покажчик на новий масив, не видаляючи старий;
		5. **cloneData()** - копіює (клонує) масив;
		6. **getData()** - встановлює/повертає покажчик на масив;
		7. **reset()** - видаляє старий масив, створює новий з таким же розміром і заповнює його в тому самому діапазоні;
		8. **resize()** - змінює розмір масиву;
		9. **replace()** - змінює елемент у вказаній позиції на вказане значення;
		10. **reverse()** - розвертає масив;
		11. **remove()** - видаляє масив;
		12. **respawn()** - аналог **reset()**, тільки в кінці він не заповнює масив елементами, а залишає його порожнім;
		13. **getMin()** - повертає мінімальне значення масиву (оптимізований метод);
		14. **getMax()** - повертає максимальне значення масиву (оптимізований метод);
		15. **lenear_searcher()** - повертає всі входження елемента, який шукається;
		16. **binary_searcher()** - повертає входження потрібного елемента в відсортованому масиві;
		17. **searcherOccurrencesOfSubstring()** - повертає всі входження підрядка;
		18. **average()** - повертає середнє арифметичне для всіх елементів масиву;
		19. **mediana()** - повертає медіану масиву;
		20. **moda()** - повертає перше входження моди;
		21. **modas()** - повертає всі входження моди;
		22. **оператор&&()** - додає елемент в кінець масиву;
		23. **оператор!()** - видаляє елемент з кінця масиву;
		24. **оператор||()** - видаляє всі елементи з масиву, які відповідають заданому значенню;
		25. **оператор<<()** - об'єднує два масиви в поточному об'єкті;
		26. **оператор>>()** - об'єднує два масиви в зазначеному об'єкті;
		27. **оператор+()** - збільшує розмір масиву на заданий розмір;
		28. **оператор-()** - зменшує розмір масиву на заданий розмір;
		29. **оператор*()** - збільшує розмір масиву в кілька разів на заданий розмір;
		30. **оператор/()** - зменшує розмір масиву в кілька разів на заданий розмір.
	- Нові головні функції:
		1. **swap()** - міняє місцями два елементи;
		2. **minimum()** - повертає мінімальне значення масиву шляхом ітерації;
		3. **maximum()** - повертає максимальне значення масиву шляхом ітерації;
		4. **addElement()** - додає вказане значення до вказаної позиції;
		5. **subtractElement()** - видаляє елемент у вказаній позиції;
		6. **subtractValue()** - видаляє всі елементи, які відповідають вказаному значенню;
		7. **copy()** - копіює елементи з одного масиву в інший;
		8. **create_struct()** - створює структуру та повертає вказівник на неї;
		9. **remove_struct()** - видаляє структуру.
	- Нові типи:
		1. **int8_t, int16_t, int32_t, int64_t** (взято з stdint);
		2. **uint8_t, uint16_t, uint32_t, uint64_t** (взято з stdint);
		3. **asize_t** - "тип розміру масиву" - рідний тип для визначення типу "розмір масиву".

---

## v0.0.1.0 (05.11.2021)

> *Формування першої структури проекту*...

### Виправлення помилок:
- Оптимізовано методи **getMin()** і **getMax()**.

### Покращення:
- У цьому оновленні планувалося впровадити генератор, але його впровадження затягнулося. Замість цього реалізовано нову структуру для роботи з даними (масивами) і додатково розширено функціональність класу *ArrayProcessing*.
- Складено план, які ще алгоритми сортування планується впровадити у наступних оновленнях.
- Нова структура:
	1. Тепер масив і його розмір зберігаються в одній структурі. Це потрібно для зручності.
	2. Сам клас *ArrayProcessing* тепер поза межами простору імен, а сам простір імен було розділено на декілька нових. Кожен простір імен міститиме певні алгоритми сортування.
	3. Тепер тип шаблону вказується для кожного з методів класу *ArrayProcessing*.
- Нові методи обробки масивів:
	1. **getElementsNumber_lenear()** - лінійний пошук елемента (знаходить усі розташування заданого елемента у будь-якому масиві);
	2. **getElementNumber_binary()** - двійковий пошук елемента (знаходить перше розташування заданого елемента в відсортованому масиві);
	3. **getOccurrencesOfSubstring()** - пошук послідовності елементів (буде потрібно для рядків, але може використовуватися для будь-яких типів чисел, таких як int або float; повертає всі місця, де ця послідовність починається в головному масиві);
	4. **addElement()** - додавання елемента до масиву (спочатку розширює його на одиницю, а потім записує потрібне значення в останнє місце);
	5. **generatedStruct()** - генератор структур (отримує оголошену структуру і бажаний розмір масиву, зберігає розмір і оголошує масив з потрібним розміром);
	6. **modas()** - пошук мод (на відміну від **moda()**, який знаходить розташування лише першого елемента, який є найбільш поширеним, він знаходить усі елементи з такою ж частотою).
- Вилучені методи:
	1. **print()**;
	2. **sum()**.
— Оновлено приклад, щоб дотримуватись нових стандартів бібліотеки для роботи з масивами.

---

## v0.0.0.3 (16.10.2021)

> *Додано кілька нових методів*...

### Виправлення помилок:
- Виправлено останні опечатки та помилки, які було пропущено минулого разу;
- Оптимізовано алгоритм **Counting_Sort**, в якому тепер не копіюється знаходження мінімального та максимального елементів, а виконується виклик вже існуючих методів;
- Додано Ліцензію та позначку, яка вказуватиме на поточну версію бібліотеки;
- І, нарешті, оновлено (виправлено) приклад використання бібліотеки.

### Покращення:
- Розширено функціонал методу **print()**;
- Змінено місцями методи **getMax()** і **getMin()**;
- Додано методи:
	1. **reverse()** - розвертає масив;
	2. **copy()** - копіює масив;
	3. **sum()** - знаходить суму елементів масиву;
	4. **average()** - знаходить середнє арифметичне масиву;
	5. **mediana()** - знаходить медіану масиву;
	6. **moda()** - знаходить моду масиву.

---

## v0.0.0.2 (01.10.2021)

> *Дрібні правки*...

### Виправлення помилок:
- Зроблено 3 правки:
	1. Видалено шаблон там, де він не потрібен;
	2. Виправлено переданий тип до методу **swap()** класу *ArrayProcessing*;
	3. Загалом, виправлено типи, що передаються, де вони були неправильно зазначені.

---

## v0.0.0.1 (29.09.2021)

> *Це мала бути проста робота, що містить лише алгоритми сортування*...

### Реліз
- Написано клас *ArrayProcessing* з методами:
	1. **generatedArray()** - генерування масиву;
	2. **swap()** - заміна двох елементів місцями;
	3. **print()** - відображення масиву на екрані;
	4. **getMax()** та **getMin()** - знаходження максимального та мінімального елемента.
- Та класи наступних алгоритмів сортування:
	1. **Insert_Sort**;
	2. **Bubble_Sort**;
	3. **Cocktail_Shaker_Sort**;
	4. **Merge_Sort**;
	5.  **Heap_Sort**;
	6. **Quick_Sort**;
	7. **Counting_Sort** (на даний момент найшвидший);
	8. **Radix_Sort**.