
#ifndef DOG_HPP
# define DOG_HPP

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
		Brain	*getBrain() const;
		void 	setIdea(int index, std::string idea) const;
};

#endif