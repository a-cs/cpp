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

Cat::Cat(Cat const &obj): Animal(obj){
	std::cout << this->type << " copy constructor called.\n";
	*this = obj;
}

Cat &Cat::operator=(Cat const &obj){
	if(this != &obj){
		this->type = obj.getType();
		this->brain = new Brain(*obj.brain);
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

void Cat::setIdea(int index, std::string idea) const{
	this->brain->ideas[index] = idea;
}