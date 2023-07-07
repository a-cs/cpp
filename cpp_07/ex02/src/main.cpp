#include "../include/Array.hpp"

int main()
{
	std::cout << "---------Testing with int array---------" << std::endl;
	Array<int> intArray(10);
	for (unsigned int i = 0; i < intArray.size(); i++) {
		intArray[i] = i;
		std::cout  << intArray[i] << std::endl;
	}

	std::cout << "\n\n---------Testing with char array---------" << std::endl;
	Array<char> charArray(5);
	for (unsigned int i = 0; i < charArray.size(); i++) {
		charArray[i] = 65 + i;
		std::cout  << charArray[i] << std::endl;
	}

	std::cout << "\n\n---------Accessing element with index---------" << std::endl;
	std::cout << "intArray[4]: " << intArray[4] << std::endl;
	std::cout << "charArray[2]: " << charArray[2] << std::endl;

	std::cout << "\n\n---------Accessing Invalid Index---------" << std::endl;
	try {
		std::cout << intArray[11] << std::endl;
	} catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return (0);
}