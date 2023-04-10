/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarneir <acarneir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 22:35:11 by acarneir          #+#    #+#             */
/*   Updated: 2023/04/09 23:17:14 by acarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed() {
	std::cout << "Default constructor called\n";
	this->rawBits = 0;
}

Fixed::Fixed(int const num) {
	std::cout << "Int constructor called\n";
	this->rawBits = num << this->fractionalBits;
}

Fixed::Fixed(float const num){
	std::cout << "Float constructor called\n";
	this->rawBits = roundf(num * (1 << this->fractionalBits));
}

Fixed::~Fixed() {
	std::cout << "Destructor called\n";
}

Fixed::Fixed(Fixed const &obj){
	std::cout << "Copy constructor called\n";
	*this = obj;
}

Fixed &Fixed::operator=(Fixed const &obj){
	std::cout << "Copy assignment operator called\n";
	if(this != &obj)
		this->rawBits = obj.getRawBits();
	return (*this);
}

int Fixed::getRawBits( void ) const{
	return this->rawBits;
}

void Fixed::setRawBits( int const raw ){
	this->rawBits = raw;
}

float Fixed::toFloat( void ) const{
	return (float)this->rawBits / (float)(1 << this->fractionalBits);
}

int Fixed::toInt( void ) const{
	return this->rawBits >> this->fractionalBits;
}

std::ostream &operator<<(std::ostream &o, Fixed const &obj){
	return (o << obj.toFloat());
}
