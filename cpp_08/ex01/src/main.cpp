#include "../include/Span.hpp"

int	main() {
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << "---------Testing longest and shortets Span---------" << std::endl;
	std::cout << "ShortestSpan: " << sp.shortestSpan() << std::endl;
	std::cout << "LongestSpan: " << sp.longestSpan() << std::endl;

	std::cout << "\n---------Testing longest and shortets Span2---------" << std::endl;
	Span sp2 = Span(3);
	sp2.addNumber(63);
	sp2.addNumber(21);
	sp2.addNumber(42);
	std::cout << "ShortestSpan: " << sp2.shortestSpan() << std::endl;
	std::cout << "LongestSpan: " << sp2.longestSpan() << std::endl;

	std::cout << "\n---------Testing exceptions---------" << std::endl;
	try {
		sp.addNumber(2);
	} catch (std::exception &e) {
		std::cout <<"Error: "<< e.what() << std::endl;;
	}

	Span smallestSpan = Span(1);
	smallestSpan.addNumber(10);
	try {
		std::cout << smallestSpan.longestSpan() << std::endl;
	} catch (std::exception &e) {
		std::cout <<"Error: " << e.what() << std::endl;;
	}

	try {
		std::cout << smallestSpan.shortestSpan() << std::endl;
	} catch (std::exception &e) {
		std::cout <<"Error: " << e.what() << std::endl;;
	}


	std::cout << "\n---------Testing Fill next 10000 available position with 42---------" << std::endl;
	Span fillSpan = Span(10000);
	fillSpan.fillNextAvailablePositionsWithValue(10000, 42);
	std::cout << "ShortestSpan: " << fillSpan.shortestSpan() << std::endl;
	std::cout << "LongestSpan: " << fillSpan.longestSpan() << std::endl;

	std::cout << "\n---------Testing exception with Fill next---------" << std::endl;

	try {
		fillSpan.fillNextAvailablePositionsWithValue(10001, 42);
	} catch (std::exception &e) {
		std::cout <<"Error: " << e.what() << std::endl;;
	}
	return 0;
}