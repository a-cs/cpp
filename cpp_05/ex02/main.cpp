#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

int	main( void ) {

	Bureaucrat					john("John", 1);
	Bureaucrat					mary("Mary", 150);
	Bureaucrat					james("James", 11);
	ShrubberyCreationForm		s("home");

	try {
		mary.executeForm(s);
	}
	catch (std::exception & e) {
		std::cout << e.what();
	}

	std::cout << s;

	try {
		james.signForm(s);
	}
	catch (std::exception & e) {
		std::cout << e.what();
	}

	try {
		mary.executeForm(s);
	}
	catch (std::exception & e) {
		std::cout << e.what();
	}

	try {
		james.executeForm(s);
	}
	catch (std::exception & e) {
		std::cout << e.what();
	}

	// std::cout << s;

	return 0;
}