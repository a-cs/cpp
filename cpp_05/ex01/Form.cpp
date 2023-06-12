#include "Form.hpp"

Form::Form(): name("X"), isSigned(false), gradeRequiredToSign(10), gradeRequiredToExecute(10){}


Form::~Form() {}

Form::Form(Form const &obj): name(obj.getName()), isSigned(obj.getIsSigned()), gradeRequiredToSign(obj.getGradeRequiredToSign()), gradeRequiredToExecute(obj.getGradeRequiredToExecute()) {
	*this = obj;
}

Form &Form::operator=(Form const &obj){
	if(this != &obj){
		this->isSigned = obj.getIsSigned();
		const_cast<std::string &>(this->name) = obj.getName();
		const_cast<int &>(this->gradeRequiredToSign) = obj.getGradeRequiredToSign();
		const_cast<int &>(this->gradeRequiredToExecute) = obj.getGradeRequiredToExecute();
	}
	return (*this);
}	

Form::Form(std::string name, int gradeRequiredToSign, int gradeRequiredToExecute): name(name), isSigned(false), gradeRequiredToSign(gradeRequiredToSign), gradeRequiredToExecute(gradeRequiredToExecute) {
	if(gradeRequiredToSign < 1 || gradeRequiredToExecute < 1)
		throw Form::GradeTooHighException();
	else if(gradeRequiredToSign > 150 || gradeRequiredToExecute > 150)
		throw Form::GradeTooLowException();
}

std::ostream	&operator<<(std::ostream &o, Form const &f){
	return 		o << "Form: "	<< f.getName() << " with isSigned = " << f.getIsSigned() << ", gradeRequiredToSign = " << f.getGradeRequiredToSign() << ", gradeRequiredToExecute = " << f.getGradeRequiredToExecute() << "\n";
}


std::string	Form::getName() const{
	return this->name;
}

bool	Form::getIsSigned() const{
	return this->isSigned;
}

int	Form::getGradeRequiredToSign() const{
	return this->gradeRequiredToSign;
}

int	Form::getGradeRequiredToExecute() const{
	return this->gradeRequiredToExecute;
}

void	Form::beSigned(Bureaucrat const &b){
	if(this->gradeRequiredToSign < b.getGrade()){
		std::cout << "Bureacrat " << b.getName() << " couldn't sign Form " << this->getName() << " because it doesn't have a grade high enough\n";
		throw Form::GradeTooLowException();
	}
	this->isSigned = true;
	std::cout << "Bureacrat " << b.getName() << " signed Form " << this->getName() << "\n";
}

const char*	Form::GradeTooHighException::what() const throw(){
	return "Grade too high exception.\n";
}

const char*	Form::GradeTooLowException::what() const throw(){
	return "Grade too low exception.\n";
}
