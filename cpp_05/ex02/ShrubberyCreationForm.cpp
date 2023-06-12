#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(): AForm::AForm("ShrubberyCreationForm", 145,137), target("no_target"){}


ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &obj): AForm::AForm("ShrubberyCreationForm", 145,137){
	this->target = obj.target;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &obj){
	if(this != &obj){
		this->target = obj.getTarget();
	}
	return (*this);
}	

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm::AForm("ShrubberyCreationForm", 145,137), target(target) {}


std::string	ShrubberyCreationForm::getTarget() const{
	return this->target;
}

void	ShrubberyCreationForm::execute(Bureaucrat const &b) const{
	if(!this->getIsSigned()){
		std::cout << "Bureacrat " << b.getName() << " couldn't execute Form " << this->getName() << " because it isn't signed\n";
		throw ShrubberyCreationForm::NotSignedException();
	}
	if(this->getGradeRequiredToExecute() < b.getGrade()){
		std::cout << "Bureacrat " << b.getName() << " couldn't execute Form " << this->getName() << " because it doesn't have a grade high enough\n";
		throw ShrubberyCreationForm::GradeTooLowException();
	}
	std::cout << "Bureacrat " << b.getName() << " executed Form " << this->getName() << "\n";
	std::ofstream file((this->target + "_shrubbery").c_str());
	file << 
	"\
       _-_\n\
    /~~   ~~\\\n\
 /~~         ~~\\\n\
{               }\n\
 \\\\  _-     -_  /\n\
   ~  \\\\ //  ~\n\
	   | |\n\
       | |\n\
      // \\\\\n\
	";
	file.close();
}