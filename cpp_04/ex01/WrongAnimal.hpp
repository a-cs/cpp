
#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

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

		void	makeSound() const;
};

#endif