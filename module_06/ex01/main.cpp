#include "Serializer.hpp"
#include "color.hpp"
#include <iostream>

int main()
{
	Data myData;
	myData.id = 42;
	myData.name = "Test Data";
	myData.value = 3.14159;

	std::cout << BRIGHT_GREEN << "---- Original Data content ----" << RESET << std::endl;
	std::cout << "ID=" << myData.id << std::endl
			  << "Name=" << myData.name << std::endl
			  << "Value=" << myData.value << std::endl;
	std::cout << "Address: " << BRIGHT_GREEN << &myData << RESET << std::endl;

	std::cout << BRIGHT_GREEN << "\n---- Serializer ----" << RESET << std::endl;
	uintptr_t raw = Serializer::serialize(&myData);
	std::cout << "Serialized value (uintptr_t): " << raw << std::endl;

	Data* deserializedData = Serializer::deserialize(raw);
	std::cout << "Deserialized Data address: " << BRIGHT_GREEN << deserializedData << RESET << std::endl;
	std::cout << BRIGHT_GREEN << "---- Data content ----" << RESET << std::endl;
	std::cout << "ID=" << myData.id << std::endl
			  << "Name=" << myData.name << std::endl
			  << "Value=" << myData.value << std::endl;

	return (0);
}
