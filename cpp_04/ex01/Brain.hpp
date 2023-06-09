
#ifndef BRAIN_H
# define BRAIN_H

#include <iostream>

class Brain
{
	public:
		std::string	ideas[100];
		Brain();
		Brain(Brain const &obj);
    	Brain &operator=(Brain const &obj);
		virtual ~Brain();

		std::string		getIdea(int) const;
};

#endif