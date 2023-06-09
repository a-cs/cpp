
#ifndef WRONGCAT_H
# define WRONGCAT_H

#include "WrongAnimal.hpp"


class WrongCat: public WrongAnimal
{
	public:
		WrongCat();
		WrongCat(WrongCat const &obj);
    	WrongCat &operator=(WrongCat const &obj);
		~WrongCat();

		void	makeSound() const;
};

#endif