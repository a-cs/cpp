#include "Animal.hpp"

Animal::Animal(): type("Animal"){
		std::cout << "Animal default constructor called.\n";
}

Animal::~Animal() {
	std::cout << "Animal destructor called.\n";
}

Animal::Animal(Animal const &obj){
	std::cout << "Animal copy constructor called.\n";
	*this = obj;
}

Animal &Animal::operator=(Animal const &obj){
	if(this != &obj){
		this->type = obj.getType();
	}
	std::cout << "Animal copy assignment operator called.\n";
	return (*this);
}

std::string	Animal::getType() const{
	return this->type;
}

void Animal::setType(std::string type){
	this->type = type;
}

void Animal::makeSound() const{
	std::cout << "*A generic animal sound*\n";
}