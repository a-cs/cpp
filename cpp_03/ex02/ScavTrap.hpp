
#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap: public ClapTrap
{
	public:
		ScavTrap();
		ScavTrap(std::string);
		ScavTrap(ScavTrap const &obj);
    	ScavTrap &operator=(ScavTrap const &obj);
		~ScavTrap();

		void	attack(const std::string& target);
		void	guardGate();

};

#endif