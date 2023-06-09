#include "WrongCat.hpp"

WrongCat::WrongCat(){
	this->type = "WrongCat";
	std::cout << this->type << " default constructor called.\n";
}

WrongCat::~WrongCat() {
	std::cout << this->type << " destructor called.\n";
}

WrongCat::WrongCat(WrongCat const &obj): WrongAnimal(obj){
	std::cout << this->type << " copy constructor called.\n";
	*this = obj;
}

WrongCat &WrongCat::operator=(WrongCat const &obj){
	if(this != &obj){
		this->type = obj.getType();
	}
	std::cout << this->type << " copy assignment operator called.\n";
	return (*this);
}

void WrongCat::makeSound() const{
	std::cout << "Roar!\n";
}