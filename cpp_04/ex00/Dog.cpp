#include "Dog.hpp"

Dog::Dog(){
	this->type = "Dog";
	std::cout << this->type << " default constructor called.\n";
}

Dog::~Dog() {
	std::cout << this->type << " destructor called.\n";
}

Dog::Dog(Dog const &obj): Animal(obj){
	std::cout << this->type << " copy constructor called.\n";
	*this = obj;
}

Dog &Dog::operator=(Dog const &obj){
	if(this != &obj){
		this->type = obj.getType();
	}
	std::cout << this->type << " copy assignment operator called.\n";
	return (*this);
}

void Dog::makeSound() const{
	std::cout << "Woof woof!\n";
}