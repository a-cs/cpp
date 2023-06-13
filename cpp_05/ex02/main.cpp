#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"



int	main( void ) {

	Bureaucrat					john("John", 5);
	Bureaucrat					mary("Mary", 150);
	Bureaucrat					james("James", 11);
	ShrubberyCreationForm		s("home");
	RobotomyRequestForm			r("R2D2");
	PresidentialPardonForm		p("C3PO");

	try {
		mary.executeForm(s);
	}
	catch (std::exception & e) {
		std::cout << e.what();
	}

	std::cout << s;

	try {
		james.signForm(s);
		james.signForm(r);
		james.signForm(p);
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

	try {
		james.executeForm(r);
	}
	catch (std::exception & e) {
		std::cout << e.what();
	}

	try {
		john.executeForm(p);
	}
	catch (std::exception & e) {
		std::cout << e.what();
	}

	return 0;
}