
#ifndef FRAGTRAP_H
# define FRAGTRAP_H

#include <iostream>
#include "ClapTrap.hpp"

class FragTrap: public ClapTrap
{
	public:
		FragTrap();
		FragTrap(std::string);
		FragTrap(FragTrap const &obj);
    	FragTrap &operator=(FragTrap const &obj);
		~FragTrap();

		void	highFivesGuys(void);

};

#endif