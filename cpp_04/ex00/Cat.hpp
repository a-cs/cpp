
#ifndef CAT_H
# define CAT_H

#include "Animal.hpp"


class Cat: public Animal
{
	public:
		Cat();
		Cat(Cat const &obj);
    	Cat &operator=(Cat const &obj);
		~Cat();

		virtual void	makeSound() const;
};

#endif