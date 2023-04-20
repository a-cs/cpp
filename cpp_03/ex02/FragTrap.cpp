#include "FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap() {
		this->name ="Unknown";
		this->hitPoints = 100;
		this->energyPoints = 100;
		this->atackDamage = 30;
		std::cout << "FragTrap " << this->name << " default constructor called.\n";
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap " << this->name << " destructor called.\n";
}

FragTrap::FragTrap(std::string name): ClapTrap(name){
	this->name = name;
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->atackDamage = 30;
	std::cout << "FragTrap " << this->name << " constructor called.\n";
}

FragTrap::FragTrap(FragTrap const &obj){
	std::cout << "FragTrap copy constructor called.\n";
	*this = obj;
}

FragTrap &FragTrap::operator=(FragTrap const &obj){
	if(this != &obj){
		this->name = obj.getName();
		this->hitPoints = obj.getHitPoints();
		this->energyPoints = obj.getEnergyPoints();
		this->atackDamage = obj.getAtackDamage();
	}
	std::cout << "FragTrap " << this->name << " copy assignment operator called.\n";
	return (*this);
}



void FragTrap::highFivesGuys(void){
	std::cout << "FragTrap " << this->name << " requests high five.\n";
}