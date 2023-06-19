
#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
	protected:
		std::string	name;
		int			hitPoints;
		int			energyPoints;
		int			atackDamage;
	public:
		ClapTrap();
		ClapTrap(std::string);
		ClapTrap(ClapTrap const &obj);
    	ClapTrap &operator=(ClapTrap const &obj);
		~ClapTrap();

		std::string	getName() const;
		int			getHitPoints() const;
		int			getEnergyPoints() const;
		int			getAtackDamage() const;

		void	setName(std::string);
		void	setHitPoints(int);
		void	setEnergyPoints(int);
		void	setAtackDamage(int);

		void		attack(const std::string& target);
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);

};

#endif