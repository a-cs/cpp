
#ifndef DOG_H
# define DOG_H

#include "Animal.hpp"
#include "Brain.hpp"

class Dog: public Animal
{
	private:
		Brain	*brain;
	public:
		Dog();
		Dog(Dog const &obj);
    	Dog &operator=(Dog const &obj);
		~Dog();

		void	makeSound() const;
		Brain	*getBrain() const;
		void 	setIdea(int index, std::string idea) const;
};

#endif