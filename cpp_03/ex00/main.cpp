#include "ClapTrap.hpp"
#include <iostream>

int	main( void ) {
	ClapTrap pikachu("Pikachu");
	ClapTrap squirtle("Squirtle");
	ClapTrap unknown;

	pikachu.setAtackDamage(3);
	squirtle.setAtackDamage(1);

	pikachu.attack(squirtle.getName());
	squirtle.takeDamage(pikachu.getAtackDamage());

	for(int i = 0; i < 5; i++){
		squirtle.attack(pikachu.getName());
		pikachu.takeDamage(squirtle.getAtackDamage());
	}

	pikachu.beRepaired(3);

	for(int i = 0; i < 6; i++){
		squirtle.attack(pikachu.getName());
		if(squirtle.getEnergyPoints() > 0)
			pikachu.takeDamage(squirtle.getAtackDamage());
	}

	for(int i = 0; i < 4; i++){
		pikachu.attack(squirtle.getName());
		squirtle.takeDamage(pikachu.getAtackDamage());
	}
	
	return 0;
}