#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <stdlib.h>
#include <climits>

class PmergeMe
{
	private:
		std::vector<int>	vec;
		std::deque<int>		deq;
		bool 			validateInput(char **input);
	public:
		PmergeMe();
		PmergeMe(PmergeMe const &obj);
    	PmergeMe &operator=(PmergeMe const &obj);
		~PmergeMe();

		int 	sort(char **input);
};

#endif