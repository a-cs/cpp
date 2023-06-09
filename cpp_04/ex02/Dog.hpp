
#ifndef DOG_H
# define DOG_H

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog: public AAnimal
{
	private:
		Brain	*brain;
	public:
		Dog();
		Dog(Dog const &obj);
    	Dog &operator=(Dog const &obj);
		~Dog();

		void	makeSound() const;
		Brain			*getBrain() const;
};

#endif