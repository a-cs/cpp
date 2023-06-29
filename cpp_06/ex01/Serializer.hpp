#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include <iostream>
#include <stdint.h>

struct Data
{
	std::string name;
	int			age;
};


class Serializer
{
	private:
		Serializer();
		Serializer(Serializer const &obj);
    	Serializer &operator=(Serializer const &obj);


	public:
		~Serializer();

		static	uintptr_t 	serialize(Data* ptr);
		static	Data* 		deserialize(uintptr_t raw);

};

std::ostream	&operator<<(std::ostream &o, Data const &d);


#endif