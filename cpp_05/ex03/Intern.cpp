#include "Intern.hpp"

Intern::Intern(){}


Intern::~Intern() {}

Intern::Intern(Intern const &obj){
	*this = obj;
}

Intern &Intern::operator=(Intern const &obj){
	(void)obj;
	return (*this);
}

AForm	*Intern::createShrubberyCreationForm(std::string target){
	return new ShrubberyCreationForm(target);
}

AForm	*Intern::createRobotomyRequestForm(std::string target){
	return new RobotomyRequestForm(target);
}

AForm	*Intern::createPresidentialPardonForm(std::string target){
	return new PresidentialPardonForm(target);
}

AForm	*Intern::makeForm(std::string formName, std::string formTarget){
	std::string	cmd[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	
	AForm		*(Intern::*func[3])(std::string target) = {
		&Intern::createShrubberyCreationForm,
		&Intern::createRobotomyRequestForm,
		&Intern::createPresidentialPardonForm
	};
	
	for(int i = 0; i < 3; i++){
		if(formName == cmd[i]){
			std::cout << "Intern creates " << formName << "\n";
			return (this->*func[i])(formTarget);
		}
	}

	std::cout << "The value \"" << formName << "\" is an invalid form name\n";
	return (NULL);
}