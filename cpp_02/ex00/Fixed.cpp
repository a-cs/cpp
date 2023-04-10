/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarneir <acarneir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 20:51:47 by acarneir          #+#    #+#             */
/*   Updated: 2023/04/09 22:23:32 by acarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed() {
	std::cout << "Default constructor called\n";
	this->rawBits = 0;
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
	std::cout << "getRawBits member function called\n";
	return this->rawBits;
}

void Fixed::setRawBits( int const raw ){
	std::cout << "setRawBits member function called\n";
	this->rawBits = raw;
}
