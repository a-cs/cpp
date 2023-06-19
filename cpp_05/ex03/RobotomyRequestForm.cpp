#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(): AForm::AForm("RobotomyRequestForm", 72,45), target("no_target"){}


RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &obj): AForm::AForm("RobotomyRequestForm", 72,45){
	this->target = obj.target;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &obj){
	if(this != &obj){
		this->target = obj.getTarget();
	}
	return (*this);
}	

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm::AForm("RobotomyRequestForm", 72,45), target(target) {}


std::string	RobotomyRequestForm::getTarget() const{
	return this->target;
}

void	RobotomyRequestForm::execute(Bureaucrat const &b) const{
	if(!this->getIsSigned()){
		std::cout << "Bureacrat " << b.getName() << " couldn't execute Form " << this->getName() << " because it isn't signed\n";
		throw RobotomyRequestForm::NotSignedException();
	}
	if(this->getGradeRequiredToExecute() < b.getGrade()){
		std::cout << "Bureacrat " << b.getName() << " couldn't execute Form " << this->getName() << " because it doesn't have a grade high enough\n";
		throw RobotomyRequestForm::GradeTooLowException();
	}
	std::cout << "Bureacrat " << b.getName() << " executed Form " << this->getName() << "\n";
	std::cout << "Bzzzz. Bzzzz. Bzzzz.\n";
	// srand(42);
	if(rand() % 2)
		std::cout << this->getTarget() << " has been robotomized successfully\n";
	else
		std::cout << "Robotomy has failed\n";
}