#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <stdlib.h>
#include <climits>
#include <algorithm>

class PmergeMe
{
	private:
		std::vector<int>	vec;
		std::deque<int>		deq;
		bool 			validateInput(char **input);
		bool 			hasDuplicates(std::vector<int> v);
	public:
		PmergeMe();
		PmergeMe(PmergeMe const &obj);
    	PmergeMe &operator=(PmergeMe const &obj);
		~PmergeMe();

		int 	sort(char **input);
};

#endif