#include "ScavTrap.hpp"
#include <iostream>

int	main( void ) {
	ScavTrap pikachu("Pikachu");
	ClapTrap squirtle("Squirtle");
	ScavTrap unknown;

	// pikachu.setAtackDamage(3);
	// squirtle.setAtackDamage(1);

	pikachu.attack(squirtle.getName());
	squirtle.takeDamage(pikachu.getAtackDamage());

	unknown.attack(pikachu.getName());
	pikachu.takeDamage(unknown.getAtackDamage());
	
	pikachu.guardGate();

	pikachu.beRepaired(10);
	
	return 0;
}