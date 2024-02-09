#include <iostream>
#include "races.h";

int main()
{
	Dwarf dwarf;

	std::cout << "\tDwarf\n-:=]==============[=:-";

	std::cout << "\nHP\t";
	for (uint16_t i = 0; i < dwarf.getMaxHP(); i++) {
		std::cout << "[" << (char)254u << "]";
	}

	std::cout << "\nATK\t";
	for (uint16_t i = 0; i < dwarf.getMaxHP(); i++) {
		std::cout << "[" << (char)254u << "]";
	}

	std::cout << "\nSTR\t";
	for (uint16_t i = 0; i < dwarf.getMaxHP(); i++) {
		std::cout << "[" << (char)254u << "]";
	}

	std::cout << "\nINT\t";
	for (uint16_t i = 0; i < dwarf.getMaxHP(); i++) {
		std::cout << "[" << (char)254u << "]";
	}

	std::cout << "\n-:=]==============[=:-";

	return 0;
}

