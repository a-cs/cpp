#include "../include/PmergeMe.hpp"

PmergeMe::PmergeMe():size(0), straggler(-1) {}


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

bool	PmergeMe::hasDuplicates(std::vector<int> v){
	if(std::adjacent_find(v.begin(), v.end()) != v.end())
		return true;
	return false;
}

bool	PmergeMe::validateInput(char **input, int *values){
	std::vector<int>	sortedVector;

	for(int i = 1; input[i]; i++){
		for(int j = 0; input[i][j]; j++)
			if(!isdigit(input[i][j]))
				return false;
		if(strtod(input[i], NULL) > INT_MAX || strtod(input[i], NULL) < 0)
			return false;
		sortedVector.push_back((int)strtod(input[i], NULL));
		values[size++] = (int)strtod(input[i], NULL);
	}

	std::sort(sortedVector.begin(), sortedVector.end());
	if(hasDuplicates(sortedVector))
		return false;

	return true;
}

void PmergeMe::stragglerCatching(int *values){
	if(size % 2 != 0){
		straggler = values[--size];
	}
}

int	PmergeMe::jacobsthal(int n){
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	return jacobsthal(n - 1) + 2 * jacobsthal(n - 2);
}

int PmergeMe::sort(char **input, int *values){

	if(!validateInput(input, values)){
		std::cout << "Error\n";
		return 1;
	}

	std::cout << "\n---- Vector Sort ----";

	fordJohnsonMergeInsertionSort(vec, vecSorted, values);
	std::cout << "FinalSeq size= " << vecSorted.size();
	std::cout << "\n";


	std::cout << "\n\n---- Deque Sort ----";

	fordJohnsonMergeInsertionSort(deq, deqSorted, values);
	std::cout << "FinalSeq size= " << deqSorted.size();
	std::cout << "\n";


	
	return 0;
}