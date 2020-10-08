#include "Header.h"

int hashas::Readingas(std::string raktas) {
	int ASCIIValue = 0;
	int ilgis = raktas.length();

	std::string zodis;
	for (int i = 0; i < raktas.length(); i++)
	{
		ASCIIValue = ASCIIValue + (int)raktas[i];
	}
	return ASCIIValue;
}
int hashas::Readingas2(std::string raktas) {
	int NumberOfLetterA = 0;
	for (int i = 0; i < raktas.length(); i++)
	{
		if (raktas[i] == 'A' || raktas[i] == 'a') NumberOfLetterA++;
	}
	return NumberOfLetterA;
}
int hashas::Readingas3(std::string raktas) {
	int NumberOfLetterE = 0;
	for (int i = 0; i < raktas.length(); i++)
	{
		if (raktas[i] == 'E' || raktas[i] == 'e') NumberOfLetterE++;
	}
	return NumberOfLetterE;
}
std::string hashas::Hashavimas(long long int UniqueHashSeed, int skaitliukasSPACE, int maxValue, int charValue, int NumberOfLetterA, int NumberOfNumber1) {
	std::string GalutinisHashas = "";
	std::string Hashavimas[8];
	std::stringstream HexStream;
	HexStream << std::hex << UniqueHashSeed * skaitliukasSPACE;
	Hashavimas[0] = HexStream.str();
	HexStream << std::hex << UniqueHashSeed * maxValue;
	Hashavimas[1] = HexStream.str();
	HexStream << std::hex << UniqueHashSeed * charValue;
	Hashavimas[2] = HexStream.str();
	HexStream << std::hex << UniqueHashSeed * NumberOfLetterA;
	Hashavimas[3] = HexStream.str();
	HexStream << std::hex << UniqueHashSeed * NumberOfNumber1;
	Hashavimas[4] = HexStream.str();
	HexStream << std::hex << UniqueHashSeed / NumberOfNumber1 * NumberOfLetterA / charValue * maxValue / skaitliukasSPACE;
	Hashavimas[5] = HexStream.str();
	HexStream << std::hex << UniqueHashSeed * NumberOfNumber1 / NumberOfLetterA * charValue / maxValue * skaitliukasSPACE;
	Hashavimas[6] = HexStream.str();
	HexStream << std::hex << UniqueHashSeed * NumberOfNumber1 * NumberOfLetterA / charValue / maxValue * skaitliukasSPACE;
	Hashavimas[7] = HexStream.str();
	for (int i = 0; i < 8; i++)
	{
		GalutinisHashas = GalutinisHashas + Hashavimas[i];
	}
	GalutinisHashas = GalutinisHashas.erase(64, GalutinisHashas.length());
	return GalutinisHashas;
}
std::string hashas::Hashavimas2(long long int UniqueHashSeed, int charValue, int NumberOfLetterA, int NumberOfNumber1)
{
	std::string GalutinisHashas = "";
	std::string Hashavimas[8];
	std::stringstream HexStream;
	HexStream << std::hex << UniqueHashSeed * rand() % UniqueHashSeed;
	Hashavimas[0] = HexStream.str();
	HexStream << std::hex << UniqueHashSeed / rand() % UniqueHashSeed;
	Hashavimas[1] = HexStream.str();
	HexStream << std::hex << UniqueHashSeed * rand() % charValue;
	Hashavimas[2] = HexStream.str();
	HexStream << std::hex << UniqueHashSeed * rand() % NumberOfLetterA;
	Hashavimas[3] = HexStream.str();
	HexStream << std::hex << UniqueHashSeed * rand() % NumberOfNumber1;
	Hashavimas[4] = HexStream.str();
	HexStream << std::hex << UniqueHashSeed * rand() % NumberOfNumber1 / rand() % NumberOfLetterA * rand() % charValue;
	Hashavimas[5] = HexStream.str();
	HexStream << std::hex << UniqueHashSeed / rand() % NumberOfNumber1 * rand() % NumberOfLetterA / rand() % charValue;
	Hashavimas[6] = HexStream.str();
	HexStream << std::hex << UniqueHashSeed * rand() % NumberOfNumber1 / rand() % NumberOfLetterA * rand() % charValue;
	Hashavimas[7] = HexStream.str();
	for (int i = 0; i < 8; i++)
	{
		GalutinisHashas = GalutinisHashas + Hashavimas[i];
	}
	GalutinisHashas = GalutinisHashas.erase(64, GalutinisHashas.length());
	return GalutinisHashas;
}