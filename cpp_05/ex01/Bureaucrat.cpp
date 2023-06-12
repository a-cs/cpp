#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): name("Unknown"), grade(150){
		// std::cout << "Bureaucrat: "	<< getName() << " -> Grade: " << getGrade() << " created using default constructor.\n";
}


Bureaucrat::~Bureaucrat() {
	// std::cout << "Bureaucrat: "	<< getName() << " -> Grade: " << getGrade() << " destroyed.\n";
}

Bureaucrat::Bureaucrat(Bureaucrat const &obj){
	*this = obj;
	// std::cout << "Bureaucrat: "	<< getName() << " -> Grade: " << getGrade() << " copied.\n";
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &obj){
	if(this != &obj){
		const_cast<std::string &>(this->name) = obj.getName();
		this->grade = obj.getGrade();
	}
	// std::cout << "Bureaucrat copy assignment operator called.\n";
	return (*this);
}	

Bureaucrat::Bureaucrat(const std::string name, int grade){
	if(grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if(grade > 150)
		throw Bureaucrat::GradeTooLowException();

	const_cast<std::string &>(this->name) = name;
	this->grade = grade;
	// std::cout << "Bureaucrat: "	<< getName() << " -> Grade: " << getGrade() << " created.\n";
}


std::string	Bureaucrat::getName() const{
	return this->name;
}

int	Bureaucrat::getGrade() const{
	return this->grade;
}

void	Bureaucrat::incrementGrade(){
	std::cout << "Incrementing grade of Bureaucrat: "	<< getName() << ".\n";
	if(this->grade == 1)
		throw Bureaucrat::GradeTooHighException();
	this->grade--;
};
void	Bureaucrat::decrementGrade(){
	std::cout << "Decrementing grade of Bureaucrat: "	<< getName() << ".\n";
	if(this->grade == 150)
		throw Bureaucrat::GradeTooLowException();
	this->grade++;
};

void	Bureaucrat::signForm(Form &f){
	f.beSigned(*this);
}

const char*	Bureaucrat::GradeTooHighException::what() const throw(){
	return "Grade too high exception.\n";
}

const char*	Bureaucrat::GradeTooLowException::what() const throw(){
	return "Grade too low exception.\n";
}

std::ostream	&operator<<(std::ostream &o, Bureaucrat const &b){
	return o << "Bureaucrat: "	<< b.getName() << " -> Grade: " << b.getGrade() << ".\n";	
}