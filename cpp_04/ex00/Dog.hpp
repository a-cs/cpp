
#ifndef DOG_H
# define DOG_H

#include "Animal.hpp"


class Dog: public Animal
{
	public:
		Dog();
		Dog(Dog const &obj);
    	Dog &operator=(Dog const &obj);
		~Dog();

		void	makeSound() const;
};

#endif