#include "ScalarConverter.hpp"

int	main( int argc, char *argv[] ) {

	if(argc !=2){
		std::cout << "Invalid arguments, you need to pass one argument\n";
		return 1;
	}

	// std::string str = argv[1];

	ScalarConverter::convert(argv[1]);

	return 0;
}