#include "Bureaucrat.hpp"

int	main( void ) {

	Bureaucrat	john("John", 1);
	Bureaucrat	mary("Mary", 150);
	Bureaucrat	james("James", 11);
	Form		f("42B", 11,11);

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
		mary.signForm(f);
	}
	catch (std::exception & e) {
		std::cout << e.what();
	}

	std::cout << f;

	try {
		james.signForm(f);
	}
	catch (std::exception & e) {
		std::cout << e.what();
	}

	std::cout << f;

	return 0;
}