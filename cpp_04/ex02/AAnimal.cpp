#include "AAnimal.hpp"

AAnimal::AAnimal(): type("AAnimal"){
		std::cout << "AAnimal default constructor called.\n";
}

AAnimal::~AAnimal() {
	std::cout << "AAnimal destructor called.\n";
}

AAnimal::AAnimal(AAnimal const &obj){
	std::cout << "AAnimal copy constructor called.\n";
	*this = obj;
}

AAnimal &AAnimal::operator=(AAnimal const &obj){
	if(this != &obj){
		this->type = obj.getType();
	}
	std::cout << "AAnimal copy assignment operator called.\n";
	return (*this);
}

std::string	AAnimal::getType() const{
	return this->type;
}

void AAnimal::setType(std::string type){
	this->type = type;
}

void AAnimal::makeSound() const{
	std::cout << "*A generic AAnimal sound*\n";
}