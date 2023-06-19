#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): AForm::AForm("PresidentialPardonForm", 25,5), target("no_target"){}


PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &obj): AForm::AForm("PresidentialPardonForm", 25,5){
	this->target = obj.target;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &obj){
	if(this != &obj){
		this->target = obj.getTarget();
	}
	return (*this);
}	

PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm::AForm("PresidentialPardonForm", 25,5), target(target) {}


std::string	PresidentialPardonForm::getTarget() const{
	return this->target;
}

void	PresidentialPardonForm::execute(Bureaucrat const &b) const{
	if(!this->getIsSigned()){
		std::cout << "Bureacrat " << b.getName() << " couldn't execute Form " << this->getName() << " because it isn't signed\n";
		throw PresidentialPardonForm::NotSignedException();
	}
	if(this->getGradeRequiredToExecute() < b.getGrade()){
		std::cout << "Bureacrat " << b.getName() << " couldn't execute Form " << this->getName() << " because it doesn't have a grade high enough\n";
		throw PresidentialPardonForm::GradeTooLowException();
	}
	std::cout << "Bureacrat " << b.getName() << " executed Form " << this->getName() << "\n";
	std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox\n";

}