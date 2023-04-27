#include "Brain.hpp"

Brain::Brain(){
		std::cout << "Brain default constructor called.\n";
		for(int i = 0; i < 100; i++)
			this->ideas[i]= (i % 2 == 0) ? "Eat": "Sleep";
}

Brain::~Brain() {
	std::cout << "Brain destructor called.\n";
}

Brain::Brain(Brain const &obj){
	std::cout << "Brain copy constructor called.\n";
	*this = obj;
}

Brain &Brain::operator=(Brain const &obj){
	if(this != &obj){
		for(int i = 0; i < 100; i++)
			this->ideas[i] = obj.ideas[i];
	}
	std::cout << "Brain copy assignment operator called.\n";
	return (*this);
}

std::string	Brain::getIdea(int index) const{
	return this->ideas[index];
}