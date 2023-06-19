
#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

class Animal
{
	protected:
		std::string	type;
	public:
		Animal();
		Animal(Animal const &obj);
    	Animal &operator=(Animal const &obj);
		virtual ~Animal();

		std::string		getType() const;
		void			setType(std::string);

		virtual void	makeSound() const;
};

#endif