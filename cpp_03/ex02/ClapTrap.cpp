#include "ClapTrap.hpp"

ClapTrap::ClapTrap():
	name("Unknown"), hitPoints(10), energyPoints(10), atackDamage(0) {
		std::cout << "ClapTrap " << this->name << " default constructor called.\n";
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap " << this->name << " destructor called.\n";
}

ClapTrap::ClapTrap(std::string name):
	name(name), hitPoints(10), energyPoints(10), atackDamage(0){
		std::cout << "ClapTrap " << this->name << " constructor called.\n";
}

ClapTrap::ClapTrap(ClapTrap const &obj){
	std::cout << "ClapTrap copy constructor called.\n";
	*this = obj;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &obj){
	if(this != &obj){
		this->name = obj.getName();
		this->hitPoints = obj.getHitPoints();
		this->energyPoints = obj.getEnergyPoints();
		this->atackDamage = obj.getAtackDamage();
	}
	std::cout << "ClapTrap " << this->name << " copy assignment operator called.\n";
	return (*this);
}

std::string	ClapTrap::getName() const{
	return this->name;
}

int	ClapTrap::getHitPoints() const{
	return this->hitPoints;
}

int	ClapTrap::getEnergyPoints() const{
	return this->energyPoints;
}

int	ClapTrap::getAtackDamage() const{
	return this->atackDamage;
}

void ClapTrap::setName(std::string name){
	this->name = name;
}

void ClapTrap::setHitPoints(int hitPoints){
	this->hitPoints = hitPoints;
}

void ClapTrap::setEnergyPoints(int energyPoints){
	this->energyPoints = energyPoints;
}

void ClapTrap::setAtackDamage(int energyPoints){
	this->atackDamage = energyPoints;
}

void ClapTrap::attack(const std::string& target){
	if(this->energyPoints > 0 && this->hitPoints > 0){
		this->energyPoints--;
		std::cout << "ClapTrap " << this->name << " attacks "<< target << 
		", causing " << std::to_string(this->atackDamage) << 
		" points of damage!\n";
	}
	else {
		std::cout << "ClapTrap " << this->name << " could not attack "<< 
		target << ".\n";
	}
}

void ClapTrap::takeDamage(unsigned int amount){
	if(this->hitPoints > 0){
		this->hitPoints -= amount;
		if(this->hitPoints > 0){
			std::cout << "ClapTrap " << this->name << " has taken "<<
			std::to_string(amount) << " points of damage! The current hit points is "<< this->hitPoints <<".\n";
		}
		else {
			std::cout << "ClapTrap " << this->name << " has taken "<<
			std::to_string(amount) << " points of damage! " << this->name << " died.\n";
		}
	}
	else {
		std::cout << "ClapTrap " << this->name << " is dead.\n";
	}
}

void ClapTrap::beRepaired(unsigned int amount){
	if(this->energyPoints > 0 && this->hitPoints > 0){
		this->energyPoints--;
		this->hitPoints += amount;
		std::cout << "ClapTrap " << this->name << " was repaired, recovering "<<
		std::to_string(amount) << " hit points! The current hit points is "<< this->hitPoints <<".\n";
	}
	else {
		std::cout << "ClapTrap " << this->name << " could not be repaired.\n";
	}
}
