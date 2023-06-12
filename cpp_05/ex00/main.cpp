#include "Bureaucrat.hpp"

int	main( void ) {

	Bureaucrat	john("John", 1);
	Bureaucrat	mary("Mary", 150);
	Bureaucrat	james("James", 10);

	std::cout << john;
	try {
		john.incrementGrade();
	}
	catch (std::exception & e) {
		std::cout << e.what();
	}

	std::cout << mary;
	try {
		mary.decrementGrade();
	}
	catch (std::exception & e) {
		std::cout << e.what();
	}

	std::cout << james;
	try {
		james.incrementGrade();
	}
	catch (std::exception & e) {
		std::cout << e.what();
	}


	std::cout << james;
	try {
		james.decrementGrade();
	}
	catch (std::exception & e) {
		std::cout << e.what();
	}
	std::cout << james;

	try {
		Bureaucrat	gradeTooHigh("John", 0);
	}
	catch (std::exception & e) {
		std::cout << e.what();
	}
	try {
		Bureaucrat	gradeTooLow("Mary", 151);
	}
	catch (std::exception & e) {
		std::cout << e.what();
	}

	return 0;
}