#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

class Span
{
	private:
		unsigned int		n;
		std::vector<int>	vec;
	public:
		Span();
		Span(unsigned int n);
		Span(Span const &obj);
    	Span &operator=(Span const &obj);
		~Span();

		void	addNumber(int number);
		int		shortestSpan();
		int		longestSpan();
		void	fillNextAvailablePositionsWithValue(unsigned int pos, int value);
};

#endif