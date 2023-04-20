#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

int	main( void ) {
	FragTrap pikachu("Pikachu");
	ClapTrap squirtle("Squirtle");
	ScavTrap unknown;

	// pikachu.setAtackDamage(3);
	// squirtle.setAtackDamage(1);

	pikachu.attack(squirtle.getName());
	squirtle.takeDamage(pikachu.getAtackDamage());

	unknown.attack(pikachu.getName());
	pikachu.takeDamage(unknown.getAtackDamage());

	unknown.guardGate();
	
	pikachu.highFivesGuys();

	pikachu.beRepaired(10);
	
	return 0;
}