#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm: public AForm
{
	private:
		std::string	target;
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(PresidentialPardonForm const &obj);
    	PresidentialPardonForm &operator=(PresidentialPardonForm const &obj);
		virtual ~PresidentialPardonForm();

		std::string		getTarget() const;
		void	execute(Bureaucrat const &b) const;
};

#endif