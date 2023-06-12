#ifndef BUREAUCRAT_H
# define BUREAUCRAT_H

#include <iostream>
#include <exception>
#include "Form.hpp"

class Form;

class Bureaucrat
{
	private:
		std::string const	name;
		int	grade;
	public:
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(Bureaucrat const &obj);
    	Bureaucrat &operator=(Bureaucrat const &obj);
		~Bureaucrat();

		std::string		getName() const;
		int				getGrade() const;

		void			incrementGrade();
		void			decrementGrade();
		void			signForm(Form &f);

	class GradeTooHighException: public std::exception {
		const char *what () const throw ();
	};

	class GradeTooLowException: public std::exception {
		const char *what () const throw ();
	};
};

std::ostream	&operator<<(std::ostream &o, Bureaucrat const &b);

#endif