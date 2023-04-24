#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal():type("WorngAnimal"){
		std::cout << "WrongAnimal default constructor called.\n";
}

WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal destructor called.\n";
}

WrongAnimal::WrongAnimal(WrongAnimal const &obj){
	std::cout << "WrongAnimal copy constructor called.\n";
	*this = obj;
}

WrongAnimal &WrongAnimal::operator=(WrongAnimal const &obj){
	if(this != &obj){
		this->type = obj.getType();
	}
	std::cout << "WrongAnimal copy assignment operator called.\n";
	return (*this);
}

std::string	WrongAnimal::getType() const{
	return this->type;
}

void WrongAnimal::setType(std::string type){
	this->type = type;
}

void WrongAnimal::makeSound() const{
	std::cout << "*A generic wrong animal sound*\n";
}