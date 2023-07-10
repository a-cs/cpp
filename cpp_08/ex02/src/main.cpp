#include "../include/MutantStack.hpp"
#include <list>

int	main() {
	{
		MutantStack<int>	mstack;

		std::cout << "---------Testing with MutantStack---------" << std::endl;

		mstack.push(5);
		mstack.push(17);
		std::cout << "Last element: " << mstack.top() << std::endl;
		mstack.pop();
		std::cout << "Size: "<< mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);
		mstack.push(42);
		mstack.push(21);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		std::cout << "Printing values:" << std::endl;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
	}
	{
		std::cout << "\n\n---------Testing with List---------" << std::endl;

		std::list<int>	list;
		list.push_back(5);
		list.push_back(17);
		std::cout << "Last element: " << list.back() << std::endl;
		list.pop_back();
		std::cout << "Size: " << list.size() << std::endl;
		list.push_back(3);
		list.push_back(5);
		list.push_back(737);
		list.push_back(0);
		list.push_back(42);
		list.push_back(21);
		std::list<int>::iterator it = list.begin();
		std::list<int>::iterator ite = list.end();
		++it;
		--it;
		std::cout << "Printing values:" << std::endl;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
	}

	return 0;
}