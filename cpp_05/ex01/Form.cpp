#include "Form.hpp"

Form::Form(): name("X"), isSigned(false), gradeRequiredToSign(10), gradeRequiredToExecute(10){
		std::cout << "Form: "	<< getName() << ", was created using default constructor.\n";
}


Form::~Form() {
	std::cout << "Form: "	<< getName() << ", was destroyed.\n";
}

Form::Form(Form const &obj): name(obj.getName()), isSigned(obj.getIsSigned()), gradeRequiredToSign(obj.getGradeRequiredToSign()), gradeRequiredToExecute(obj.getgradeRequiredToExecute()) {
	*this = obj;
	std::cout << "Form: "	<< getName() << ", was copied.\n";
}

Form &Form::operator=(Form const &obj){
	if(this != &obj){
		this->isSigned = obj.getIsSigned();
		const_cast<int &>(this->gradeRequiredToSign) = obj.getGradeRequiredToSign();
	}
	std::cout << "Form copy assignment operator called.\n";
	return (*this);
}	

Form::Form(std::string name, int gradeRequiredToSign, int gradeRequiredToExecute): name(name), isSigned(false), gradeRequiredToSign(gradeRequiredToSign), gradeRequiredToExecute(gradeRequiredToExecute) {
	if(gradeRequiredToSign < 1 || gradeRequiredToExecute < 1)
		throw Form::GradeTooHighException();
	else if(gradeRequiredToSign > 150 || gradeRequiredToExecute > 150)
		throw Form::GradeTooLowException();

	const_cast<std::string &>(this->name) = name;
	this->grade = grade;
	std::cout << "Form: "	<< getName() << " -> Grade: " << getGrade() << " created.\n";
}

std::ostream	&operator<<(std::ostream &o, Form const &f){
	return 		o << "Form: "	<< f.getName() << " with isSigned = " << f.getIsSigned()<< ", gradeRequiredToSign = " << f.getGradeRequiredToSign() << ", gradeRequiredToExecute = " << f.getgradeRequiredToExecute() << ", was created using default constructor.\n";
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

int	Form::getgradeRequiredToExecute() const{
	return this->gradeRequiredToExecute;
}

const char*	Form::GradeTooHighException::what() const throw(){
	return "Grade too high exception.\n";
}

const char*	Form::GradeTooLowException::what() const throw(){
	return "Grade too low exception.\n";
}
