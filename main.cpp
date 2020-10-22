#include "Header.h"

int main()
{
	// hashing seed factors
	int skaitliukasSPACE = 1; // number of spaces in document + 1
	int maxValue = 1; // ASCII sum of all the characters in document + 1
	int charValue = 1; // Number of characters in document + 1
	int NumberOfLetterA = 1; // Number of letter a in document + 1
	int NumberOfLetterE = 1; // Number of number 1 in document + 1
	int value;
	int pasirinkimas, pasirinkimas2;
	int kolizijos=0;
	time_t start, end;
	std::string arrats[2];
	long long int UniqueHashSeed;
	hashas hashasX;
	std::ifstream fd("poros 1.txt");
	std::string raktas;
	std::cout << "Hashinsim faila(1) ar inputa(2)?" << std::endl;
	std::cin >> pasirinkimas;
	if (pasirinkimas == 1)
	{
		std::cout << "Hashinsim eilutemis(1) ,visa dokumenta(2), poras(3)?" << std::endl;
		std::cin >> pasirinkimas2;
		if (pasirinkimas2 == 2)
		{
			while (!fd.eof())
			{
				skaitliukasSPACE++;
				fd >> raktas;
				//std::cout << raktas << std::endl;
				charValue = charValue + raktas.length();
				value = hashasX.Readingas(raktas);
				NumberOfLetterA = NumberOfLetterA + hashasX.Readingas2(raktas);
				NumberOfLetterE = NumberOfLetterE + hashasX.Readingas3(raktas);
				//std::cout << "Value = " << value << std::endl;
				maxValue = maxValue + value;
			}
			long long int UniqueHashSeed = skaitliukasSPACE * maxValue * charValue + NumberOfLetterA + NumberOfLetterE;
			std::cout << "maxValue = " << maxValue << std::endl;
			std::cout << "skaitliukasSPACE = " << skaitliukasSPACE << std::endl;
			std::cout << "charValue = " << charValue << std::endl;
			std::cout << "NumberOfLetterA = " << NumberOfLetterA << std::endl;
			std::cout << "NumberOfLetterE = " << NumberOfLetterE << std::endl;
			std::cout << std::endl;
			std::cout << "UniqueHashSeed = " << UniqueHashSeed << std::endl;
			auto begin = std::chrono::high_resolution_clock::now();
			std::string ats = hashasX.Hashavimas(UniqueHashSeed, skaitliukasSPACE, maxValue, charValue, NumberOfLetterA, NumberOfLetterE);

			auto end = std::chrono::high_resolution_clock::now();
			std::cout << "HASHAVIMAS UZTRUKO : " << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() << "nanosekundziu " << std::setprecision(4) << std::endl;
			std::cout << "Hash = " << ats << std::endl;
		}
		else if(pasirinkimas2 == 1)
		{
			auto begin = std::chrono::high_resolution_clock::now();
			while (!fd.eof())
			{
				skaitliukasSPACE++;
				std::getline(fd, raktas);
				//std::cout << raktas << std::endl;
				charValue = charValue + raktas.length();
				value = hashasX.Readingas(raktas);
				NumberOfLetterA = NumberOfLetterA + hashasX.Readingas2(raktas);
				NumberOfLetterE = NumberOfLetterE + hashasX.Readingas3(raktas);
				//std::cout << "Value = " << value << std::endl;
				maxValue = maxValue + value;
				UniqueHashSeed = skaitliukasSPACE * maxValue * charValue + NumberOfLetterA + NumberOfLetterE;
				if (UniqueHashSeed <= 0) UniqueHashSeed = abs(UniqueHashSeed);
				std::string ats = hashasX.Hashavimas(UniqueHashSeed, skaitliukasSPACE, maxValue, charValue, NumberOfLetterA, NumberOfLetterE);

				std::cout << "Hash = " << ats << std::endl;
			}
			auto end = std::chrono::high_resolution_clock::now();
			std::cout << "HASHAVIMAS UZTRUKO : " << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() << "nanosekundziu " << std::setprecision(4) << std::endl;
		}
		else if (pasirinkimas2 == 3)
		{
			auto begin = std::chrono::high_resolution_clock::now();
			while (!fd.eof())
			{
				for (int i = 0; i < 2; i++)
				{
					skaitliukasSPACE++;
					std::getline(fd, raktas);
					charValue = charValue + raktas.length();
					value = hashasX.Readingas(raktas);
					NumberOfLetterA = NumberOfLetterA + hashasX.Readingas2(raktas);
					NumberOfLetterE = NumberOfLetterE + hashasX.Readingas3(raktas);
					maxValue = maxValue + value;
					UniqueHashSeed = skaitliukasSPACE * maxValue * charValue + NumberOfLetterA + NumberOfLetterE;
					if (UniqueHashSeed <= 0) UniqueHashSeed = abs(UniqueHashSeed);
					arrats[i] = hashasX.Hashavimas(UniqueHashSeed, skaitliukasSPACE, maxValue, charValue, NumberOfLetterA, NumberOfLetterE);
					std::cout << "Hash = " << arrats[i] << std::endl;
				}
				
			}
			auto end = std::chrono::high_resolution_clock::now();
			std::cout << "HASHAVIMAS UZTRUKO : " << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() << "nanosekundziu " << std::setprecision(4) << std::endl;
			std::cout << "KOLIZIJOS : " << kolizijos << std::endl;
		}
	}
	else {
		int ascii;
		std::string input;
		std::cin >> input;
		ascii = hashasX.Readingas(input);
		charValue = input.length();
		NumberOfLetterA = hashasX.Readingas2(input);
		NumberOfLetterE = hashasX.Readingas3(input);
		long long int UniqueHashSeed = charValue * NumberOfLetterA * NumberOfLetterE;
		std::cout << "charValue = " << charValue << std::endl;
		std::cout << "NumberOfLetterA = " << NumberOfLetterA << std::endl;
		std::cout << "NumberOfLetterE = " << NumberOfLetterE << std::endl;
		std::cout << std::endl;
		std::cout << "UniqueHashSeed = " << UniqueHashSeed << std::endl;
	}
}
