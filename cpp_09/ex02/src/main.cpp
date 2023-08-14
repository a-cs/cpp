#include "../include/PmergeMe.hpp"

int	main(int argc, char** argv) {
	if(argc == 1){
		std::cout << "Error: No arguments provided\n";
		return 1;
	} else {
		std::cout << "Argc=" << argc <<"\n";
		PmergeMe ppm;
		
		return (ppm.sort(argv));
	}

}