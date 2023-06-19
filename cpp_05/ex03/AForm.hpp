#ifndef AFORM_HPP
# define AFORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		std::string const	name;
		bool				isSigned;
		const int			gradeRequiredToSign;
		const int			gradeRequiredToExecute;
	public:
		AForm();
		AForm(std::string name, int gradeRequiredToSign, int gradeRequiredToExecute);
		AForm(AForm const &obj);
    	AForm &operator=(AForm const &obj);
		virtual	~AForm();

		std::string		getName() const;
		bool			getIsSigned() const;
		int				getGradeRequiredToSign() const;
		int				getGradeRequiredToExecute() const;

		void			beSigned(Bureaucrat const &b);
		virtual	void	execute(Bureaucrat const &b) const = 0;


	class GradeTooHighException : public std::exception {
		const char *what () const throw ();
	};

	class GradeTooLowException: public std::exception {
		const char *what () const throw ();
	};

	class NotSignedException: public std::exception {
		const char *what () const throw ();
	};
};

std::ostream	&operator<<(std::ostream &o, AForm const &f);

#endif