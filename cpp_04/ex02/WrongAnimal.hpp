
#ifndef WRONGANIMAL_H
# define WRONGANIMAL_H

#include <iostream>

class WrongAnimal
{
	protected:
		std::string	type;
	public:
		WrongAnimal();
		WrongAnimal(WrongAnimal const &obj);
    	WrongAnimal &operator=(WrongAnimal const &obj);
		virtual ~WrongAnimal();

		std::string		getType() const;
		void			setType(std::string);

		virtual void	makeSound() const;
};

#endif