#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm: public AForm
{
	private:
		std::string	target;
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(ShrubberyCreationForm const &obj);
    	ShrubberyCreationForm &operator=(ShrubberyCreationForm const &obj);
		virtual ~ShrubberyCreationForm();

		std::string		getTarget() const;
		void	execute(Bureaucrat const &b) const;
};

#endif