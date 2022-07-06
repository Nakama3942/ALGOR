#include <iostream>
using std::cin;
using std::cout;

#include "../src/ALGOR.hpp"

int main()
{
	//! [LCM class]
	ALGOR::RANDOM::LCM r(getMemoryCell());
	cout << r.rand() << "\n"; //print 510610997
	//! [LCM class]

	//! [LCM srand]
	ALGOR::RANDOM::LCM r(getMemoryCell()); //or RANDOM::LCM r(time(NULL));
	//! [LCM srand]

	//! [LCM rand]
	cout << r.rand() << "\n"; //print 510610997
	//! [LCM rand]

	//! [RC4 class]
	ALGOR::RANDOM::RC4 rc4;				//Створюю об'єкт ГВЧ
	char key[100];						//Створюю ключ
	rc4.crypto_srand(key, 100);			//Встановлюю ключ
	int BUFSIZe = 100;
	char output[BUFSIZe];				//Створюю масив під результат
	rc4.crypto_rand(output, BUFSIZe);	//Генерую результат
	//! [RC4 class]

	//! [RC4 srand]
	ALGOR::RANDOM::RC4 rc4;				//Створюю об'єкт ГВЧ
	char key[100];						//Створюю ключ
	rc4.crypto_srand(key, 100);			//Встановлюю ключ
	//! [RC4 srand]

	//! [RC4 rand]
	int BUFSIZe = 100;
	char output[BUFSIZe];				//Створюю масив під результат
	rc4.crypto_rand(output, BUFSIZe);	//Генерую результат
	//! [RC4 rand]

	//! [MT class]
	ALGOR::RANDOM::MersenneTwister RanGen(ALGOR::getMemoryCell(32));

	//Заповнюю масив числами від 10 до 100
	for (asize_t i = 0; i < array_size; i++)
	{
		array[i] = RanGen.IRandom(10, 100);
	}
	//! [MT class]

	//! [MT srand]
	ALGOR::RANDOM::MersenneTwister RanGen(ALGOR::getMemoryCell(32));
	//! [MT srand]

	//! [MT reinit]
	RanGen.RandomInit(ALGOR::getMemoryCell(32));
	//! [MT reinit]

	//! [MT rand int]
	array[0] = RanGen.IRandom(10, 100);
	//! [MT rand int]

	//! [MT rand int extend]
	array[0] = RanGen.IRandomX(10, 100);
	//! [MT rand int extend]

	//! [MT rand double]
	array[0] = RanGen.Random();
	//! [MT rand double]

	//! [MT rand bits]
	array[0] = RanGen.BRandom();
	//! [MT rand bits]

	//! [random test]
	cout << ALGOR::RANDOM::tester<ALGOR::RANDOM::LCM>(0, 999999) << "\n";
	cout << ALGOR::RANDOM::tester<ALGOR::RANDOM::MersenneTwister>(0, 999999) << "\n";
	//print 78.6892
	//print 80.2694
	//! [random test]

	cin.get();
	return 0;
}