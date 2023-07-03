#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>

Base * generate(void){
	int value = rand();
	if(value % 3 == 0){
		std::cout << "Generating Class A\n";
		return new A();
	}
	else if(value % 3 == 1){
		std::cout << "Generating Class B\n";
		return new B();
	}
	else{
		std::cout << "Generating Class C\n";
		return new C();
	}
}

void identify(Base* p){
	if(dynamic_cast<A*>(p) != NULL)
		std::cout << "Object of type A\n";
	else if(dynamic_cast<B*>(p) != NULL)
		std::cout << "Object of type B\n";
	else if(dynamic_cast<C*>(p) != NULL)
		std::cout << "Object of type C\n";
	else
		std::cout << "Object is not derived from Base Class\n";
}

void identify(Base& p){
	try{
		A &ptr = dynamic_cast<A&>(p);
		std::cout << &ptr  << " -> References an Object of type A\n";
		return ;
	}
	catch(std::exception &e){
		std::cout << "Error: "<< e.what() << "\nFailed cast to Class A\n";
	}

	try{
		B &ptr = dynamic_cast<B&>(p);
		std::cout << &ptr  << " -> References an Object of type B\n";
		return ;
	}
	catch(std::exception &e){
		std::cout << "Error: "<< e.what() << "\nFailed cast to Class B\n";
	}

	try{
		C &ptr = dynamic_cast<C&>(p);
		std::cout << &ptr  << " -> References an Object of type C\n";
		return ;
	}
	catch(std::exception &e){
		std::cout << "Error: "<< e.what() << "\nFailed cast to Class C\n";
	}
	std::cout << "References an Object that is not derived from Base Class\n";
}


int	main( void) {
	std::srand(2);

	std::cout << "---------Generating objects---------\n";
	Base	*baseA = generate();
	Base	*baseB = generate();
	Base	*baseC = generate();
	Base	*base = new Base();


	std::cout << "\n---------Identifying objects---------\n";
	identify(baseA);
	identify(baseB);
	identify(baseC);
	identify(base);

	std::cout << "\n---------Identifying objects using reference---------\n";

	identify(*baseA);
	identify(*baseB);
	identify(*baseC);
	identify(*base);
	
	delete baseA;
	delete baseB;
	delete baseC;
	delete base;

	return 0;
}