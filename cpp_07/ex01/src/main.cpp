#include "../include/iter.hpp"

int	main() {
	int		intArr[4]  = { 4, 2, 1, 3};
	const char	charArr[3]  = { 'a', 'b', 'c'};

	std::cout << "---------Testing with int array---------" << std::endl;
	iter(intArr, 4, print);

	std::cout << "\n---------Testing with const char array---------" << std::endl;
	iter(charArr, 3, print);

	return 0;
}