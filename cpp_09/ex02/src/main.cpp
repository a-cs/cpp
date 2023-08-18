#include "../include/PmergeMe.hpp"

int	main(int argc, char** argv) {
	int values[argc - 1];

	if(argc == 1){
		std::cout << "Error: No arguments provided\n";
		return 1;
	} else {
		std::cout << "Argc=" << argc <<"\n";
		PmergeMe ppm;
		
		return (ppm.sort(argv, values));
	}

}