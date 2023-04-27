
#ifndef CAT_H
# define CAT_H

#include "Animal.hpp"
#include "Brain.hpp"


class Cat: public Animal
{
	private:
		Brain	*brain;
	public:
		Cat();
		Cat(Cat const &obj);
    	Cat &operator=(Cat const &obj);
		~Cat();

		virtual void	makeSound() const;
		Brain			*getBrain() const;
};

#endif