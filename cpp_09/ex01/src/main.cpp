#include "../include/RPN.hpp"

int	main(int argc, char** argv) {
	if(argc != 2){
		std::cout << "Error\n";
		return 1;
	} else {
		RPN rpn;
		
		return (rpn.calculate(argv[1]));
	}

}