
#ifndef Bureaucrat_H
# define Bureaucrat_H

#include <iostream>
#include <exception>

class Bureaucrat
{
	protected:
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

		class GradeTooHighException : public std::exception {
			const char *what () const throw ();
		};

		class GradeTooLowException: public std::exception {
			const char *what () const throw ();
		};
};

std::ostream	&operator<<(std::ostream &o, Bureaucrat const &b);

#endif