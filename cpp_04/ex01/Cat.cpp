#include "Cat.hpp"

Cat::Cat(){
	this->type = "Cat";
	std::cout << this->type << " default constructor called.\n";
	this->brain = new Brain();
}

Cat::~Cat() {
	std::cout << this->type << " destructor called.\n";
	delete this->brain;
}

Cat::Cat(Cat const &obj){
	std::cout << this->type << " copy constructor called.\n";
	*this = obj;
}

Cat &Cat::operator=(Cat const &obj){
	if(this != &obj){
		this->type = obj.getType();
	}
	std::cout << this->type << " copy assignment operator called.\n";
	return (*this);
}

void Cat::makeSound() const{
	std::cout << "Meow!\n";
}

Brain	*Cat::getBrain() const{
	return this->brain;
}