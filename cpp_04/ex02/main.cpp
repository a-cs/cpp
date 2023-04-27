#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int	main( void ) {

	// AAnimal invalidAnimal = new AAnimal();
	int 	size = 6;
	AAnimal *animals[size];
	
	
	std::cout << "-----Creating Animals-----\n";

	for(int i = 0; i < size/2; i++)
		animals[i] = new Dog();
	for(int i = size/2; i < size; i++)
		animals[i] = new Cat();


	std::cout << "\n\n-----Deleting Animals-----\n";
	for(int i = 0; i < size; i++)
		delete animals[i];

	return 0;
}