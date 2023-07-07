#include "../include/easyfind.hpp"
#include <vector>

int	main() {
	std::vector<int>			vec;
	std::vector<int>::iterator	it;

	for(int i = 0; i < 10; i++)
		vec.push_back(i);
	
	std::cout << "---------Finding value---------" << std::endl;
	it = easyfind(vec, 4);
	std::cout << *it << std::endl;

	std::cout << "---------Invalid value---------" << std::endl;
	try{
		easyfind(vec, 42);
	} catch(std::exception &e){
		std::cout << "Error: " << e.what() <<std::endl;
	}

	return 0;
}