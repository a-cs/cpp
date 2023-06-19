#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"



int	main( void ) {

	Bureaucrat	john("John", 5);
	Bureaucrat	mary("Mary", 150);
	Bureaucrat	james("James", 11);
	Intern		intern;
	AForm		*s;
	AForm		*r;
	AForm		*p;
	AForm		*i;

	s = intern.makeForm("shrubbery creation", "shrubbery target");
	r = intern.makeForm("robotomy request", "robotomy target");
	p = intern.makeForm("presidential pardon", "presidential target");
	i = intern.makeForm("invalid form", "invalid target");

	if(i != NULL){
		try{
			i->beSigned(john);
		}
		catch(std::exception & e){
			std::cout << e.what();
		}
	}
	else {
		std::cout << "Invalid form is NULL.\n";
	}

	try {
		mary.executeForm(*s);
	}
	catch (std::exception & e) {
		std::cout << e.what();
	}

	std::cout << *s;

	try {
		james.signForm(*s);
		james.signForm(*r);
		james.signForm(*p);
	}
	catch (std::exception & e) {
		std::cout << e.what();
	}

	try {
		mary.executeForm(*s);
	}
	catch (std::exception & e) {
		std::cout << e.what();
	}

	try {
		james.executeForm(*s);
	}
	catch (std::exception & e) {
		std::cout << e.what();
	}
	delete s;

	try {
		james.executeForm(*r);
	}
	catch (std::exception & e) {
		std::cout << e.what();
	}
	delete r;

	try {
		john.executeForm(*p);
	}
	catch (std::exception & e) {
		std::cout << e.what();
	}
	delete p;

	return 0;
}