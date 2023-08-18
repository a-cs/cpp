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

void PmergeMe::creatingPairs(int *values){
	for(int i = 0; i < size; i += 2){
		std::cout<< "isize = " << i << "\n";
		std::pair<int, int> newPair(values[i], values[i + 1]);
		vec.push_back(newPair);
		deq.push_back(newPair);
	}
}

int PmergeMe::sort(char **input, int *values){

	if(!validateInput(input, values)){
		std::cout << "Error\n";
		return 1;
	}

	std::cout<< "size = " << size << "\n";
	std::cout<< "straggler = " << straggler << "\n";
	for(int i = 0; i < size; i++){
		std::cout << values[i] << " ";
	}

	stragglerCatching(values);

	std::cout<< "\nsize = " << size << "\n";
	std::cout<< "straggler = " << straggler << "\n";

	creatingPairs(values);

	std::cout << "\n\nVec Pairs\n";

	for (size_t i = 0; i < vec.size(); ++i){
    	std::cout << "p[" << i << "] = ";
		std::cout << vec[i].first << ", " << vec[i].second << '\n';
	}
	
	std::cout << "\n\nDec Pairs\n";

	for (size_t i = 0; i < deq.size(); ++i){
    	std::cout << "p[" << i << "] = ";
		std::cout << deq[i].first << ", " << deq[i].second << '\n';
	}


	


	
	return 0;
}