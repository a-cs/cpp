
#ifndef FORM_H
# define FORM_H

#include "Bureaucrat.hpp"

class Form
{
	private:
		std::string const	name;
		bool				isSigned;
		const int			gradeRequiredToSign;
		const int			gradeRequiredToExecute;
	public:
		Form();
		Form(std::string name, int gradeRequiredToSign, int gradeRequiredToExecute);
		Form(Form const &obj);
    	Form &operator=(Form const &obj);
		~Form();

		std::string		getName() const;
		bool			getIsSigned() const;
		int				getGradeRequiredToSign() const;
		int				getgradeRequiredToExecute() const;

		void			beSigned(Bureaucrat const B);


		class GradeTooHighException : public std::exception {
			const char *what () const throw ();
		};

		class GradeTooLowException: public std::exception {
			const char *what () const throw ();
		};
};

std::ostream	&operator<<(std::ostream &o, Form const &f);

#endif