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

double	PmergeMe::timeNow() {
	struct timeval	timeval;

	gettimeofday(&timeval, NULL);
	return ((timeval.tv_sec * 1000) + (timeval.tv_usec * 0.001));
}

void	PmergeMe::printResult(char **input, double vecTime, double deqTime) {
	size_t	limit;

	vecSorted.size() > 10 ? limit = 10 : limit = vecSorted.size();
	std::cout << "Before: ";
	for (size_t i = 1; i < limit + 1; i++)
		std::cout << input[i] << " ";
	if (vecSorted.size() > 10)
		std::cout << "[...]";
	std::cout << "\nAfter:  ";
	for (size_t i = 0; i < limit; i++)
		std::cout << this->vecSorted[i] << " ";
	if (vecSorted.size() > 10)
		std::cout << "[...]";
	std::cout << "\nTime to process a range of " << vecSorted.size() << " elements with std::vector : " << vecTime << " us" << std::endl;
	std::cout << "Time to process a range of " << deqSorted.size() << " elements with std::deque  : " << deqTime << " us" << std::endl;
}

int PmergeMe::sort(char **input, int *values){
	double	vecTime;
	double	deqTime;

	if(!validateInput(input, values)){
		std::cout << "Error\n";
		return 1;
	}

	vecTime = timeNow();
	fordJohnsonMergeInsertionSort(vec, vecSorted, values);
	vecTime = timeNow() - vecTime;

	deqTime = timeNow();
	fordJohnsonMergeInsertionSort(deq, deqSorted, values);
	deqTime = timeNow()- deqTime;

	printResult(input,vecTime, deqTime);

	
	return 0;
}