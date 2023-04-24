
#ifndef ANIMAL_H
# define ANIMAL_H

#include <iostream>

class Animal
{
	protected:
		std::string	type;
	public:
		Animal();
		Animal(Animal const &obj);
    	Animal &operator=(Animal const &obj);
		~Animal();

		std::string		getType() const;
		void			setType(std::string);

		virtual void	makeSound() const;
};

#endif