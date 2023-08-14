#include "../include/PmergeMe.hpp"

PmergeMe::PmergeMe() {}


PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(PmergeMe const &obj){
	*this = obj;
}

PmergeMe &PmergeMe::operator=(PmergeMe const &obj){
	if(this != &obj){
		this->vec = obj.vec;
		this->deq = obj.deq;
	}
	return (*this);
}

bool	PmergeMe::validateInput(char **input){
	for(int i = 1; input[i]; i++){
		for(int j = 0; input[i][j]; j++)
			if(!isdigit(input[i][j]))
				return false;
		if(strtod(input[i], NULL) > INT_MAX || strtod(input[i], NULL) < 0)
			return false;
	}
	return true;
}

int PmergeMe::sort(char **input){

	if(!validateInput(input)){
		std::cout << "Error\n";
		return 1;
	}
	
	return 0;
}