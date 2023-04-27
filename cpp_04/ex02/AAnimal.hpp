
#ifndef AANIMAL_H
# define AANIMAL_H

#include <iostream>

class AAnimal
{
	protected:
		std::string	type;
	public:
		AAnimal();
		AAnimal(AAnimal const &obj);
    	AAnimal &operator=(AAnimal const &obj);
		virtual ~AAnimal() = 0;

		std::string		getType() const;
		void			setType(std::string);

		virtual void	makeSound() const = 0;
};

#endif