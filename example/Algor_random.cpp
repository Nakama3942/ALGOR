#include <iostream>

#include "../include/ALGOR.hpp"
using namespace ALGOR;

int main()
{
	//! [LCM class]
	ALGOR::RANDOM::LCM rand1(getMemoryCell()); // or ALGOR::RANDOM::LCM r(time(NULL));
	std::cout << rand1.rand() << "\n";
	// >print:> 510610997
	//! [LCM class]

	//! [LCM srand]
	ALGOR::RANDOM::LCM rand2(getMemoryCell()); // or ALGOR::RANDOM::LCM r(time(NULL));
	//! [LCM srand]

	//! [LCM rand]
	std::cout << rand2.rand() << "\n";
	// >print:> 1284370684
	//! [LCM rand]

	//! [RC4 class]
	ALGOR::RANDOM::RC4 rc4_1;				// Creating an RNG object
	char key1[100];							// Creating key
	rc4_1.crypto_srand(key1, 100);			// Key setting
	int BUFSIZe1 = 100;
	char output1[BUFSIZe1];					// Creating an array for the result
	rc4_1.crypto_rand(output1, BUFSIZe1);	// Generating of result
	std::cout << (int*)output1 << "\n";
	// >print:> 0x7afa40
	//! [RC4 class]

	//! [RC4 srand]
	ALGOR::RANDOM::RC4 rc4_2;				// Creating an RNG object
	char key2[100];							// Creating key
	rc4_2.crypto_srand(key2, 100);			// Key setting
	//! [RC4 srand]

	//! [RC4 rand]
	int BUFSIZe2 = 100;
	char output2[BUFSIZe2];					// Creating an array for the result
	rc4_2.crypto_rand(output2, BUFSIZe2);	// Generating of result
	std::cout << (int*)output2 << "\n";
	// >print:> 0x7af9d0
	//! [RC4 rand]

	//! [MT class]
	ALGOR::RANDOM::MersenneTwister RandGen(ALGOR::getMemoryCell(32));
	std::cout << RandGen.IRandom(10, 100) << "\n";
	// >print:> 49
	//! [MT class]

	//! [MT srand]
	ALGOR::RANDOM::MersenneTwister RanGen(ALGOR::getMemoryCell(32));
	//! [MT srand]

	//! [MT reinit]
	RanGen.RandomInit(ALGOR::getMemoryCell(32));
	//! [MT reinit]

	//! [MT rand int]
	std::cout << RanGen.IRandom(10, 100) << "\n";
	// >print:> 63
	//! [MT rand int]

	//! [MT rand int extend]
	std::cout << RanGen.IRandomX(10, 100) << "\n";
	// >print:> 56
	//! [MT rand int extend]

	//! [MT rand double]
	std::cout << RanGen.Random() << "\n";
	// >print:> 0.914341
	//! [MT rand double]

	//! [MT rand bits]
	std::cout << RanGen.BRandom() << "\n";
	// >print:> 2231262266
	//! [MT rand bits]

	//! [random test]
	std::cout << ALGOR::RANDOM::test_random_on_Pearsons_coefficient<ALGOR::RANDOM::LCM>(0, 999999) << "\n";
	std::cout << ALGOR::RANDOM::test_random_on_Pearsons_coefficient<ALGOR::RANDOM::MersenneTwister>(0, 999999) << "\n";
	// >print:> 78.6892
	// >print:> 80.2694
	//! [random test]

	std::cin.get();
	return 0;
}
