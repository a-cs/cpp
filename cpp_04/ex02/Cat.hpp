
#ifndef CAT_H
# define CAT_H

#include "AAnimal.hpp"
#include "Brain.hpp"


class Cat: public AAnimal
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