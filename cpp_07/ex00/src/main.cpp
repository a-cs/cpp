#include "../include/whatever.hpp"

int	main() {
	int a = 4;
	int b = 2;

	std::cout << "---------Testing with ints---------" << std::endl;
	std::cout << "a = " << a << " and b = " << b << std::endl;
	::swap(a,b);
	std::cout << "a = " << a << " and b = " << b << std::endl;
	std::cout << "min("<< a <<", " << b << ") = " << ::min(a, b) << std::endl;
	std::cout << "max("<< a <<", " << b << ") = " << ::max(a, b) << std::endl;

	std::string str1 = "abc";
	std::string str2 = "xyz";
	std::cout << "\n\n---------Testing with strings---------" << std::endl;
	std::cout << "str1 = " << str1 << " and str2 = " << str2 << std::endl;
	::swap(str1,str2);
	std::cout << "str1 = " << str1 << " and str2 = " << str2 << std::endl;
	std::cout << "min('"<< str1 <<"', '" << str2 << "') = " << ::min(str1, str2) << std::endl;
	std::cout << "max('"<< str1 <<"', '" << str2 << "') = " << ::max(str1, str2) << std::endl;
	return 0;
}