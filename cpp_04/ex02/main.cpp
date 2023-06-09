#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int	main( void ) {

	int 	size = 2;
	AAnimal *animals[size];

	
	std::cout << "-----Creating Animals-----\n";

	for(int i = 0; i < size/2; i++)
		animals[i] = new Dog();
	for(int i = size/2; i < size; i++)
		animals[i] = new Cat();


	std::cout << "\n\n-----Testing deep copy-----\n";
	Cat *cat = (Cat *)animals[size-1];
	Cat copyCat(*cat);
	std::cout << "\n----After setting a different value for copy-----\n";
	copyCat.setIdea(1, "rest");
	std::cout << "Cat>	" << cat->getBrain()->getIdea(1) << "\n";
	std::cout << "Copy> 	" << copyCat.getBrain()->getIdea(1) << "\n";

	std::cout << "\n\n-----Deleting Animals-----\n";
	for(int i = 0; i < size; i++)
		delete animals[i];
	return 0;
}