#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <cstdlib>

class RobotomyRequestForm: public AForm
{
	private:
		std::string	target;
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(RobotomyRequestForm const &obj);
    	RobotomyRequestForm &operator=(RobotomyRequestForm const &obj);
		virtual ~RobotomyRequestForm();

		std::string		getTarget() const;
		void	execute(Bureaucrat const &b) const;
};

#endif