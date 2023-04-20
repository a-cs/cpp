#include "ScavTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap() {
		this->name ="Unknown";
		this->hitPoints = 100;
		this->energyPoints = 50;
		this->atackDamage = 20;
		std::cout << "ScavTrap " << this->name << " default constructor called.\n";
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap " << this->name << " destructor called.\n";
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name){
	this->name = name;
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->atackDamage = 20;
	std::cout << "ScavTrap " << this->name << " constructor called.\n";
}

ScavTrap::ScavTrap(ScavTrap const &obj){
	std::cout << "ScavTrap copy constructor called.\n";
	*this = obj;
}

ScavTrap &ScavTrap::operator=(ScavTrap const &obj){
	if(this != &obj){
		this->name = obj.getName();
		this->hitPoints = obj.getHitPoints();
		this->energyPoints = obj.getEnergyPoints();
		this->atackDamage = obj.getAtackDamage();
	}
	std::cout << "ScavTrap " << this->name << " copy assignment operator called.\n";
	return (*this);
}

void ScavTrap::attack(const std::string& target){
	if(this->energyPoints > 0 && this->hitPoints > 0){
		this->energyPoints--;
		std::cout << "ScavTrap " << this->name << " attacks "<< target << 
		", causing " << std::to_string(this->atackDamage) << 
		" points of damage!\n";
	}
	else {
		std::cout << "ScavTrap " << this->name << " could not attack "<< 
		target << ".\n";
	}
}



void ScavTrap::guardGate(void){
	std::cout << "ScavTrap " << this->name << " is now in Gatekeeper mode.\n";
}