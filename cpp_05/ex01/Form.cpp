#include "Form.hpp"

Form::Form(): name("X"), isSigned(false), gradeRequiredToSign(10), gradeRequiredToExecute(10){
		std::cout << "Form: "	<< getName() << ", was created using default constructor.\n";
}


Form::~Form() {
	std::cout << "Form: "	<< getName() << ", was destroyed.\n";
}

Form::Form(Form const &obj){
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

Form::Form(const std::string name, int grade){
	if(grade < 1)
		throw Form::GradeTooHighException();
	else if(grade > 150)
		throw Form::GradeTooLowException();

	const_cast<std::string &>(this->name) = name;
	this->grade = grade;
	std::cout << "Form: "	<< getName() << " -> Grade: " << getGrade() << " created.\n";
}

std::ostream	&operator<<(std::ostream &o, Form const &f){
	return 		std::cout << "Form: "	<< getName() << " with isSigned = " << getIsSigned()<< ", gradeRequiredToSign = " << getGradeRequiredToSign() << ", gradeRequiredToExecute = " << getgradeRequiredToExecute() << ", was created using default constructor.\n";
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
