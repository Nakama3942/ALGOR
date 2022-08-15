#include <iostream>
using std::cin;
using std::cout;

#include "../include/ALGOR.hpp"
using namespace ALGOR;

int main()
{
	//! [LCM class]
	ALGOR::RANDOM::LCM rand1(getMemoryCell()); //or ALGOR::RANDOM::LCM r(time(NULL));
	cout << rand1.rand() << "\n";
	//print 510610997
	//! [LCM class]

	//! [LCM srand]
	ALGOR::RANDOM::LCM rand2(getMemoryCell()); //or ALGOR::RANDOM::LCM r(time(NULL));
	//! [LCM srand]

	//! [LCM rand]
	cout << rand2.rand() << "\n";
	//print 1284370684
	//! [LCM rand]

	//! [RC4 class]
	ALGOR::RANDOM::RC4 rc4_1;				//Створюю об'єкт ГВЧ
	char key1[100];							//Створюю ключ
	rc4_1.crypto_srand(key1, 100);			//Встановлюю ключ
	int BUFSIZe1 = 100;
	char output1[BUFSIZe1];					//Створюю масив під результат
	rc4_1.crypto_rand(output1, BUFSIZe1);	//Генерую результат
	cout << (int*)output1 << "\n";
	//print 0x7afa40
	//! [RC4 class]

	//! [RC4 srand]
	ALGOR::RANDOM::RC4 rc4_2;				//Створюю об'єкт ГВЧ
	char key2[100];							//Створюю ключ
	rc4_2.crypto_srand(key2, 100);			//Встановлюю ключ
	//! [RC4 srand]

	//! [RC4 rand]
	int BUFSIZe2 = 100;
	char output2[BUFSIZe2];					//Створюю масив під результат
	rc4_2.crypto_rand(output2, BUFSIZe2);	//Генерую результат
	cout << (int*)output2 << "\n";
	//print 0x7af9d0
	//! [RC4 rand]

	//! [MT class]
	ALGOR::RANDOM::MersenneTwister RandGen(ALGOR::getMemoryCell(32));
	cout << RandGen.IRandom(10, 100) << "\n";
	//print 49
	//! [MT class]

	//! [MT srand]
	ALGOR::RANDOM::MersenneTwister RanGen(ALGOR::getMemoryCell(32));
	//! [MT srand]

	//! [MT reinit]
	RanGen.RandomInit(ALGOR::getMemoryCell(32));
	//! [MT reinit]

	//! [MT rand int]
	cout << RanGen.IRandom(10, 100) << "\n";
	//print 63
	//! [MT rand int]

	//! [MT rand int extend]
	cout << RanGen.IRandomX(10, 100) << "\n";
	//print 56
	//! [MT rand int extend]

	//! [MT rand double]
	cout << RanGen.Random() << "\n";
	//print 0.914341
	//! [MT rand double]

	//! [MT rand bits]
	cout << RanGen.BRandom() << "\n";
	//print 2231262266
	//! [MT rand bits]

	//! [random test]
	cout << ALGOR::RANDOM::test_random_on_Pearsons_coefficient<ALGOR::RANDOM::LCM>(0, 999999) << "\n";
	cout << ALGOR::RANDOM::test_random_on_Pearsons_coefficient<ALGOR::RANDOM::MersenneTwister>(0, 999999) << "\n";
	//print 78.6892
	//print 80.2694
	//! [random test]

	cin.get();
	return 0;
}
