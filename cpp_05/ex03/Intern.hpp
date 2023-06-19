#ifndef INTERN_HPP
# define INTERN_HPP

#include <iostream>
#include <exception>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class AForm;

class Intern
{
	private:
		AForm *createShrubberyCreationForm(std::string target);
		AForm *createRobotomyRequestForm(std::string target);
		AForm *createPresidentialPardonForm(std::string target);

	public:
		Intern();
		Intern(Intern const &obj);
    	Intern &operator=(Intern const &obj);
		~Intern();

		AForm	*makeForm(std::string formName, std::string formTarget);
};

#endif