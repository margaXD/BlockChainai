#include "Header.h"

int main()
{
	// hashing seed factors
	int skaitliukasSPACE = 1; // number of spaces in document + 1
	int maxValue = 1; // ASCII sum of all the characters in document + 1
	int charValue = 1; // Number of characters in document + 1
	int NumberOfLetterA = 1; // Number of letter a in document + 1
	int NumberOfLetterE = 1; // Number of number 1 in document + 1
	std::string pasirinkimas;
	int value;
	hashas hashasX;
	std::ifstream fd("random file.txt");
	std::string raktas;
	std::cout << "Hashinsim faila ar inputa?" << std::endl;
	std::cin >> pasirinkimas;
	if (pasirinkimas == "faila") {
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
		std::string ats = hashasX.Hashavimas(UniqueHashSeed, skaitliukasSPACE, maxValue, charValue, NumberOfLetterA, NumberOfLetterE);
		std::cout << "Hash = " << ats << std::endl;


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
		std::string ats = hashasX.Hashavimas2(UniqueHashSeed, charValue, NumberOfLetterA, NumberOfLetterE);
		std::cout << "Hash = " << ats << std::endl;
	}
}
