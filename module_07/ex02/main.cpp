#include <iostream>
#include "Array.hpp"
#include "color.hpp"

#define MAX_VAL 750

int main(int, char**)
{
	std::cout << BOLD << "=== TEST 1: Construcción y Llenado ===" << RESET << std::endl;
	Array<int> numbers(MAX_VAL);
	int* mirror = new int[MAX_VAL];
	srand(time(NULL));
	
	std::cout << "Llenando Array y mirror con valores aleatorios..." << std::endl;
	for (int i = 0; i < MAX_VAL; i++)
	{
		const int value = rand();
		numbers[i] = value;
		mirror[i] = value;
	}
	std::cout << BRIGHT_GREEN << "ok." << RESET << "\n" << std::endl;

	//SCOPE
	std::cout << BOLD << "=== TEST 2: Copia Profunda (Prueba de Scope) ===" << RESET << std::endl;
	{
		std::cout << "Creando tmp = numbers..." << std::endl;
		Array<int> tmp = numbers;
		std::cout << "Creando test(tmp)..." << std::endl;
		Array<int> test(tmp);
		std::cout << "Saliendo del scope (los destructores deben ser llamados)..." << std::endl;
	}
	std::cout << BRIGHT_GREEN << "Prueba de scope finalizada." << RESET << "\n" << std::endl;

	std::cout << BOLD << "=== TEST 3: Verificación (Array vs Mirror) ===" << RESET << std::endl;
	for (int i = 0; i < MAX_VAL; i++)
	{
		if (mirror[i] != numbers[i])
		{
			std::cerr << BRIGHT_RED << "Error: ¡no se guardó el mismo valor!" << RESET << std::endl;
			return (1);
		}
	}
	std::cout << BRIGHT_GREEN << "Éxito: Todos los valores coinciden." << RESET << "\n" << std::endl;

	std::cout << BOLD << "=== TEST 4: Excepciones ===" << RESET << std::endl;
	
	std::cout << "Probando índice -2:" << std::endl;
	try
	{
		numbers[-2] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << BRIGHT_RED << "Excepción capturada: " << e.what() << RESET << std::endl;
	}

	std::cout << "Probando índice MAX_VAL (fuera de límites):" << std::endl;
	try
	{
		numbers[MAX_VAL] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << BRIGHT_RED << "Excepción capturada: " << e.what() << RESET << std::endl;
	}
	
	std::cout << "Probando índice válido [8]:" << std::endl;
	try
	{
		std::cout << "Valor antes: " << numbers[8] << std::endl;
		numbers[8] = 0;
		std::cout << "Valor después: " << numbers[8] << std::endl;
		std::cout << BRIGHT_GREEN << "OK." << RESET << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << BRIGHT_RED << "Excepción capturada: " << e.what() << RESET << std::endl;
	}
	std::cout << "\n" << std::endl;

	for (int i = 0; i < MAX_VAL; i++)
	{
		numbers[i] = rand();
	}
	delete [] mirror;
	return (0);
}