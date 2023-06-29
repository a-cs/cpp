#include "Serializer.hpp"

Serializer::Serializer(){
}


Serializer::~Serializer() {
}

Serializer::Serializer(Serializer const &obj){
	*this = obj;
}

Serializer &Serializer::operator=(Serializer const &obj){
	(void)obj;
	return (*this);
}


uintptr_t 	Serializer::serialize(Data* ptr){
	return(reinterpret_cast<uintptr_t>(ptr));
}

Data* 		Serializer::deserialize(uintptr_t raw){
	return(reinterpret_cast<Data*>(raw));
}

std::ostream	&operator<<(std::ostream &o, Data const &d){
	o << "Data content:\nName: " << d.name << "\nAge: " << d.age <<"\n";
	return o;
}
