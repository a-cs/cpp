
#ifndef CAT_HPP
# define CAT_HPP

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

		void	makeSound() const;
		Brain	*getBrain() const;
		void 	setIdea(int index, std::string idea) const;
};

#endif