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
		std::deque<std::pair<int, int> >	deq;
		int									size;
		int									straggler;
		bool 								validateInput(char **input,int *values);
		bool 								hasDuplicates(std::vector<int> v);
		void								stragglerCatching(int *values);
		void								creatingPairs(int *values);
		int									jacobsthal(int n);
		bool								valExists(const std::vector<int>& vec, int val);
	public:
		PmergeMe();
		PmergeMe(PmergeMe const &obj);
    	PmergeMe &operator=(PmergeMe const &obj);
		~PmergeMe();

		int 	sort(char **input,int *values);

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

			std::cout << "pend size = " << c.size() <<"\n";
			
			while (jacobsthal(jacobIndex) < (int)c.size() - 1) {
				jacobsthalSeq.insert(jacobsthalSeq.begin() + i, jacobsthal(jacobIndex));
				jacobIndex += 1;
				i++;
			}
			return jacobsthalSeq;
		}

		template < typename Container >
		void createSequence(Container& c, std::string type){
			int					i = 0;
			int					iter = 0;
			std::vector<int>	seq;
			std::vector<int>	pend;
			std::vector<int>	indexSeq;

			if (type == "deque"){
				std::deque<int> seq;
				std::deque<int> pend;
				std::deque<int> indexSeq;
			}

			typename Container::iterator it(c.begin());

			while (it!= c.end()){
				seq.insert(seq.begin() + i, it->second);
				pend.insert(pend.begin() + i, it->first);
				it++;
				i++;
			}
			std::cout << "Seq = ";
			printContainer(seq);
			std::cout << "\nPend = ";
			printContainer(pend);
			std::cout <<"\n";

			indexSeq.insert(indexSeq.begin(), 1);


			std::vector<int> jacobsthalSequence = createJacobsthalSequence(pend);
			std::cout << "jacobsthalSequence = ";
			printContainer(jacobsthalSequence);
			std::cout <<"\n";

			while (iter <= (int)pend.size()){
				int item;
				if (jacobsthalSequence.size() != 0){
					indexSeq.push_back(jacobsthalSequence[0]);
					item = pend.at(jacobsthalSequence[0] - 1);
					std::cout << "j - iter = " << iter << " ,item = " << item;
					std::cout << " jacobsthalSequence = ";
					printContainer(jacobsthalSequence);
					std::cout <<"\n";
					jacobsthalSequence.erase(jacobsthalSequence.begin());
				} else {
					std::cout << "iter = " << iter << "\n";
					if (valExists(indexSeq, iter))
						iter++;
					item = (iter - 1 <= 0) ? pend.at(0) : pend.at(iter - 1);
					indexSeq.push_back(iter);
					std::cout << "iter = " << iter << " ,item = " << item;
				}
				std::vector<int>::iterator it_s = std::lower_bound(seq.begin(), seq.end(), item);
				int insertIndex = std::distance(seq.begin(), it_s);
				std::cout << " insertIndex = " << insertIndex;
				std::cout << " indexSeq = ";
				printContainer(indexSeq);
				seq.insert(seq.begin() + insertIndex, item);
				std::cout << " seq = ";
				printContainer(seq);
				std::cout <<"\n";
				iter++;
			}


			std::cout << "FinalSeq = ";
			printContainer(seq);
			std::cout << "\nPend = ";
			printContainer(pend);
			std::cout <<"\n";


			if (straggler != -1){
				std::vector<int>::iterator it_s = std::lower_bound(seq.begin(), seq.end(), straggler);
				int insertIndex = std::distance(seq.begin(), it_s);
				seq.insert(seq.begin() + insertIndex, straggler);
			}

			std::cout << "FinalSeq = ";
			printContainer(seq);
			std::cout << "\nPend = ";
			printContainer(pend);
			std::cout <<"\n";
		}
};

#endif