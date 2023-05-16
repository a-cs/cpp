#include "Bureaucrat.hpp"

int	main( void ) {

	Bureaucrat	joao("João", 1);
	Bureaucrat	maria("Maria", 150);
	Bureaucrat	jose("José", 10);

	std::cout << joao;
	try {
		joao.incrementGrade();
	}
	catch (std::exception & e) {
		std::cout << e.what();
	}

	std::cout << maria;
	try {
		maria.decrementGrade();
	}
	catch (std::exception & e) {
		std::cout << e.what();
	}

	std::cout << jose;
	try {
		jose.incrementGrade();
	}
	catch (std::exception & e) {
		std::cout << e.what();
	}


	std::cout << jose;
	try {
		jose.decrementGrade();
	}
	catch (std::exception & e) {
		std::cout << e.what();
	}
	std::cout << jose;


	return 0;
}