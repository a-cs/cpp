#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <stdlib.h>
#include <climits>
#include <algorithm>
#include <sys/time.h>

class PmergeMe
{
	private:
		std::vector<std::pair<int, int> >	vec;
		std::deque<std::pair<int, int> >	deq;
		std::vector<int>					vecSorted;
		std::deque<int>						deqSorted;
		int									size;
		int									straggler;
		bool 								validateInput(char **input,int *values);
		bool 								hasDuplicates(std::vector<int> v);
		void								stragglerCatching(int *values);
		void								creatingPairs(int *values);
		int									jacobsthal(int n);
		bool								valExists(const std::vector<int>& vec, int val);
		double								timeNow();
		void								printResult(char **input, double timeVec, double timeDeq);

		template < typename Container >
		void printContainer(Container& c){
			for (size_t i = 0; i < c.size(); ++i){
				std::cout << c[i] << ", ";;
			}
		}

		template < typename Container >
		void printContainerPair(Container& c){
			for (size_t i = 0; i < c.size(); ++i){
				std::cout << "p[" << i << "] = ";
				std::cout << c[i].first << ", " << c[i].second << '\n';
			}
		}

		template < typename Container >
		void creatingPairs(int *values, Container& c){
			for(int i = 0; i < size; i += 2){
				std::pair<int, int> newPair(values[i], values[i + 1]);
				c.push_back(newPair);
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

		template < typename Container >
		Container createJacobsthalSequence(Container& c){
			int			i = 0;
			int			jacobIndex = 3;
			Container	jacobsthalSeq;
			
			while (jacobsthal(jacobIndex) < (int)c.size() - 1) {
				jacobsthalSeq.insert(jacobsthalSeq.begin() + i, jacobsthal(jacobIndex));
				jacobIndex += 1;
				i++;
			}
			return jacobsthalSeq;
		}

		template <  typename Container>
		bool valExists(Container& c, int val){
			for (int i = 0; i < (int)c.size(); i++)
				if (c[i] == val){
					return true;
				}
			return false;
		}

		template < typename ContainerPair, typename Container>
		void createSequence(ContainerPair& cPair, Container& c){
			int			i = 0;
			int			iter = 0;
			int			item;
			Container	seq;
			Container	pend;
			Container	indexSeq;

			typename ContainerPair::iterator it(cPair.begin());

			while (it!= cPair.end()){
				seq.insert(seq.begin() + i, it->second);
				pend.insert(pend.begin() + i, it->first);
				it++;
				i++;
			}

			if(size < 4){
				if(size >= 2)
					seq.push_back(pend.at(0));
				if(straggler != -1)
					seq.push_back(straggler);
				std::sort(seq.begin(), seq.end());
			}
			else {
				seq.insert(seq.begin(), pend.at(0));
				indexSeq.push_back(0);
				indexSeq.push_back(1);
				Container jacobsthalSequence = createJacobsthalSequence(pend);

				while (jacobsthalSequence.size() != 0){
					indexSeq.push_back(jacobsthalSequence[0]);
					item = pend.at(jacobsthalSequence[0] - 1);
					jacobsthalSequence.erase(jacobsthalSequence.begin());
					typename Container::iterator itPos = std::lower_bound(seq.begin(), seq.end(), item);
					int insertIndex = std::distance(seq.begin(), itPos);
					seq.insert(seq.begin() + insertIndex, item);
				}

				while (iter <= (int)pend.size()){
					while(valExists(indexSeq, iter))
						iter++;
					item = (iter - 1 <= 0) ? pend.at(0) : pend.at(iter - 1);
					indexSeq.push_back(iter);
					typename Container::iterator itPos = std::lower_bound(seq.begin(), seq.end(), item);
					int insertIndex = std::distance(seq.begin(), itPos);
					seq.insert(seq.begin() + insertIndex, item);
					iter++;
				}

				if (straggler != -1){
					typename Container::iterator itPos = std::lower_bound(seq.begin(), seq.end(), straggler);
					int insertIndex = std::distance(seq.begin(), itPos);
					seq.insert(seq.begin() + insertIndex, straggler);
				}
			}
			c = seq;
		}

		template < typename ContainerPair, typename Container>
		void fordJohnsonMergeInsertionSort(ContainerPair& cPair, Container& cSorted, int *values){
			stragglerCatching(values);
			creatingPairs(values, cPair);
			sortingPairs(cPair);
			mergeSort(cPair);
			createSequence(cPair, cSorted);
		}
	public:
		PmergeMe();
		PmergeMe(PmergeMe const &obj);
    	PmergeMe &operator=(PmergeMe const &obj);
		~PmergeMe();

		int 	sort(char **input,int *values);
};

#endif