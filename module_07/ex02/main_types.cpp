#include <iostream>
#include <string>
#include "Array.hpp"
#include "color.hpp"

// Una clase simple para probar 
class Awesome
{
	private:
		int _n;
	public:
		Awesome(void) : _n(42) { return; }
		int get(void) const { return this->_n; }
};

std::ostream & operator<<(std::ostream & o, Awesome const & rhs)
{
	o << rhs.get();
	return (o);
}

int main()
{
	std::cout << BOLD << "=== TEST 1: Array de Strings ===" << RESET << std::endl;
	try
	{
		Array<std::string> strArray(3);
		
		std::cout << "Inicializando strings..." << std::endl;
		strArray[0] = "ohh";
		strArray[1] = "Madrid";
		strArray[2] = "42";

		std::cout << "Imprimiendo contenido:" << std::endl;
		for (unsigned int i = 0; i < strArray.size(); i++) {
			std::cout << "strArray[" << i << "] = " << strArray[i] << std::endl;
		}
		
		std::cout << "Probando excepción de string:" << std::endl;
		std::cout << strArray[5] << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << BRIGHT_RED << "Excepción capturada: " << e.what() << RESET << std::endl;
	}

	std::cout << BOLD << "=== TEST 2: Array de Chars ===" << RESET << std::endl;
	try
	{
		Array<char> charArray(5);
		std::string texto = "ABCDE";

		for (unsigned int i = 0; i < charArray.size(); i++)
		{
			charArray[i] = texto[i];
		}

		std::cout << "Contenido charArray: ";
		for (unsigned int i = 0; i < charArray.size(); i++)
		{
			std::cout << charArray[i] << " ";
		}
		std::cout << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}


	std::cout << BOLD << "=== TEST 3: Array de Clases Personalizadas (Awesome) ===" << RESET << std::endl;
	try
	{
		Array<Awesome> awesomeArray(3);
		
		std::cout << "Imprimiendo objetos Awesome :" << std::endl;
		for (unsigned int i = 0; i < awesomeArray.size(); i++)
		{
			std::cout << "awesomeArray[" << i << "] = " << awesomeArray[i] << std::endl;
		}
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << BRIGHT_GREEN << "Test de Clases completado." << RESET << std::endl;

	return (0);
}
