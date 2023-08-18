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
		std::vector<std::pair<int, int> >	vec;
		std::deque<std::pair<int, int> >		deq;
		int									size;
		int									straggler;
		bool 								validateInput(char **input,int *values);
		bool 								hasDuplicates(std::vector<int> v);
		void								stragglerCatching(int *values);
		void								creatingPairs(int *values);
	public:
		PmergeMe();
		PmergeMe(PmergeMe const &obj);
    	PmergeMe &operator=(PmergeMe const &obj);
		~PmergeMe();

		int 	sort(char **input,int *values);

		template < typename Container >
		void printContainerPair(Container& c){
			for (size_t i = 0; i < c.size(); ++i){
				std::cout << "p[" << i << "] = ";
				std::cout << c[i].first << ", " << c[i].second << '\n';
			}
		}

		template < typename Container >
		void sortingPairs(Container& c){
			for (size_t i = 0; i < c.size(); ++i){
				if(c[i].first > c[i].second)
					std::swap(c[i].first, c[i].second);
			};
		}
};

#endif