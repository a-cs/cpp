#include "AForm.hpp"

AForm::AForm(): name("X"), isSigned(false), gradeRequiredToSign(10), gradeRequiredToExecute(10){}


AForm::~AForm() {}

AForm::AForm(AForm const &obj): name(obj.getName()), isSigned(obj.getIsSigned()), gradeRequiredToSign(obj.getGradeRequiredToSign()), gradeRequiredToExecute(obj.getGradeRequiredToExecute()) {
	*this = obj;
}

AForm &AForm::operator=(AForm const &obj){
	if(this != &obj){
		this->isSigned = obj.getIsSigned();
		const_cast<std::string &>(this->name) = obj.getName();
		const_cast<int &>(this->gradeRequiredToSign) = obj.getGradeRequiredToSign();
		const_cast<int &>(this->gradeRequiredToExecute) = obj.getGradeRequiredToExecute();
	}
	return (*this);
}	

AForm::AForm(std::string name, int gradeRequiredToSign, int gradeRequiredToExecute): name(name), isSigned(false), gradeRequiredToSign(gradeRequiredToSign), gradeRequiredToExecute(gradeRequiredToExecute) {
	if(gradeRequiredToSign < 1 || gradeRequiredToExecute < 1)
		throw AForm::GradeTooHighException();
	else if(gradeRequiredToSign > 150 || gradeRequiredToExecute > 150)
		throw AForm::GradeTooLowException();
}

std::ostream	&operator<<(std::ostream &o, AForm const &f){
	return 		o << "Form: "	<< f.getName() << " with isSigned = " << f.getIsSigned() << ", gradeRequiredToSign = " << f.getGradeRequiredToSign() << ", gradeRequiredToExecute = " << f.getGradeRequiredToExecute() << "\n";
}


std::string	AForm::getName() const{
	return this->name;
}

bool	AForm::getIsSigned() const{
	return this->isSigned;
}

int	AForm::getGradeRequiredToSign() const{
	return this->gradeRequiredToSign;
}

int	AForm::getGradeRequiredToExecute() const{
	return this->gradeRequiredToExecute;
}

void	AForm::beSigned(Bureaucrat const &b){
	if(this->gradeRequiredToSign < b.getGrade()){
		std::cout << "Bureacrat " << b.getName() << " couldn't sign Form " << this->getName() << " because it doesn't have a grade high enough\n";
		throw AForm::GradeTooLowException();
	}
	this->isSigned = true;
	std::cout << "Bureacrat " << b.getName() << " signed Form " << this->getName() << "\n";
}

void	AForm::execute(Bureaucrat const &b) const{
	if(!this->isSigned){
		std::cout << "Bureacrat " << b.getName() << " couldn't execute Form " << this->getName() << " because it isn't signed\n";
		throw AForm::NotSignedException();
	}
	if(this->gradeRequiredToExecute < b.getGrade()){
		std::cout << "Bureacrat " << b.getName() << " couldn't execute Form " << this->getName() << " because it doesn't have a grade high enough\n";
		throw AForm::GradeTooLowException();
	}
	std::cout << "Bureacrat " << b.getName() << " executed Form " << this->getName() << "\n";
}

const char*	AForm::GradeTooHighException::what() const throw(){
	return "Grade too high exception.\n";
}

const char*	AForm::GradeTooLowException::what() const throw(){
	return "Grade too low exception.\n";
}

const char*	AForm::NotSignedException::what() const throw(){
	return "Form is not signed.\n";
}