#include "Dog.hpp"

Dog::Dog(){
	this->type = "Dog";
	std::cout << this->type << " default constructor called.\n";
	this->brain = new Brain();
}

Dog::~Dog() {
	std::cout << this->type << " destructor called.\n";
	delete this->brain;
}

Dog::Dog(Dog const &obj): Animal(obj){
	std::cout << this->type << " copy constructor called.\n";
	*this = obj;
}

Dog &Dog::operator=(Dog const &obj){
	if(this != &obj){
		this->type = obj.getType();
		this->brain = new Brain(*obj.brain);
	}
	std::cout << this->type << " copy assignment operator called.\n";
	return (*this);
}

void Dog::makeSound() const{
	std::cout << "Meow!\n";
}

Brain	*Dog::getBrain() const{
	return this->brain;
}

void Dog::setIdea(int index, std::string idea) const{
	this->brain->ideas[index] = idea;
}