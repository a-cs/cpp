#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <list>

class RPN
{
	private:
		std::list<char> inputElementsList;
		bool 			validateInput(std::string input);
	public:
		RPN();
		RPN(RPN const &obj);
		RPN &operator=(RPN const &obj);
		~RPN();

		int 	calculate(std::string input);
};

#endif