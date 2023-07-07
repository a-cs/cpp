#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename T>
class Array
{
	private:
		T				*array;
		unsigned int	n;
	public:
		Array(): array(0), n(0){};
		Array(unsigned int n): array(new T[n]), n(n){};
		Array(Array const &obj){
			*this = obj;
		};
    	Array &operator=(Array const &obj){
			if(this != &obj){
				this->array = new T[obj.n()];
				this->n = obj.n;
				for(unsigned int i = 0; i < this->n; i++)
					this->array[i] = obj.array[i];
			}
			return (*this);
		};
		~Array(){
			if(this->array)
				delete[] this->array;
		};
		T &operator[](unsigned int i){
			if(i >= this->n){
				throw std::out_of_range("Index is out of range");
			}
			return this->array[i];
		};


		unsigned int	size() const {
			return n;
		};

};

#endif