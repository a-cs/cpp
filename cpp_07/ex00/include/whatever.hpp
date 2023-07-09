#ifndef WHATEVER_HPP
# define WHATEVER_HPP

#include <iostream>

template <typename T>
void	swap(T &a, T &b){
	T temp = a;
	a = b;
	b = temp;
}

template <typename T>
T const	&min(T &a, T &b){
	return a < b ? a : b;
}

template <typename T>
T const	&max(T &a, T &b){
	return a > b ? a : b;
}

#endif