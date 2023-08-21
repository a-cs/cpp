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

		template < typename Container >
		void mergeSort(Container& c){
			if (c.size() <= 1)
				return;
			Container left, right;
			int mid = c.size() / 2;
			typename Container::iterator itOriginal = c.begin();
			for (int i = 0; i < mid; i++, ++itOriginal)
				left.push_back(*itOriginal);
			for (int i = mid; i < (int)c.size(); i++, ++itOriginal)
				right.push_back(*itOriginal);
			mergeSort(left);
			mergeSort(right);

			merge(c, left, right);
		}

		template < typename Container >
		void merge(Container& c, Container& left, Container& right){
			typename Container::iterator itOriginal(c.begin()), itLeft(left.begin()), itRight(right.begin());

			while (itLeft!= left.end() && itRight!= right.end()){
				if (itLeft->second < itRight->second){
					*itOriginal = *itLeft;
					++itOriginal;
					++itLeft;
				} else {
					*itOriginal = *itRight;
					++itOriginal;
					++itRight;
				}
			}
			while (itLeft != left.end()){
				*itOriginal = *itLeft;
				++itOriginal;
				++itLeft;
			}
			while (itRight!= right.end()){
				*itOriginal = *itRight;
				++itOriginal;
				++itRight;
			}
		}
};

#endif