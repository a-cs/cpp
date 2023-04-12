/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarneir <acarneir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 21:48:28 by acarneir          #+#    #+#             */
/*   Updated: 2023/04/12 00:14:29 by acarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() {
	this->rawBits = 0;
}

Fixed::Fixed(int const num) {
	this->rawBits = num << this->fractionalBits;
}

Fixed::Fixed(float const num){
	this->rawBits = roundf(num * (1 << this->fractionalBits));
}

Fixed::~Fixed() {
}

Fixed::Fixed(Fixed const &obj){
	*this = obj;
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

Fixed &Fixed::operator=(Fixed const &obj){
	if(this != &obj)
		this->rawBits = obj.getRawBits();
	return (*this);
}

bool	Fixed::operator>(const Fixed &num) const{
	return this->getRawBits() > num.getRawBits();
}

bool	Fixed::operator<(const Fixed &num) const{
	return this->getRawBits() < num.getRawBits();
}

bool	Fixed::operator>=(const Fixed &num) const{
	return this->getRawBits() >= num.getRawBits();
}

bool	Fixed::operator<=(const Fixed &num) const{
	return this->getRawBits() <= num.getRawBits();
}

bool	Fixed::operator==(const Fixed &num) const{
	return this->getRawBits() == num.getRawBits();
}

bool	Fixed::operator!=(const Fixed &num) const{
	return this->getRawBits() != num.getRawBits();
}

Fixed	Fixed::operator+(const Fixed &num){
	Fixed	result;
	
	result.setRawBits(this->getRawBits() + num.getRawBits());
	return result;
}

Fixed	Fixed::operator-(const Fixed &num){
	Fixed	result;
	
	result.setRawBits(this->getRawBits() - num.getRawBits());
	return result;
}

Fixed	Fixed::operator*(const Fixed &num){
	Fixed	result(this->toFloat() * num.toFloat());
	return result;
}

Fixed	Fixed::operator/(const Fixed &num){
	Fixed	result(this->toFloat() / num.toFloat());
	return result;
}

Fixed	&Fixed::operator++(){
	this->rawBits++;
	return *this;
}

Fixed	Fixed::operator++(int){
	Fixed	copy = *this;
	
	++*this;
	return copy;
}

Fixed	&Fixed::operator--(){
	this->rawBits--;
	return *this;
}

Fixed	Fixed::operator--(int){
	Fixed	copy = *this;
	
	--*this;
	return copy;
}

Fixed		&Fixed::min(Fixed &num1, Fixed &num2){
	if(num1 < num2)
		return num1;
	return num2;
}

Fixed const &Fixed::min(Fixed const &num1, Fixed const &num2){
	if(num1 < num2)
		return num1;
	return num2;
}

Fixed		&Fixed::max(Fixed &num1, Fixed &num2){
	if(num1 > num2)
		return num1;
	return num2;
}

Fixed const &Fixed::max(Fixed const &num1,Fixed const &num2){
	if(num1 > num2)
		return num1;
	return num2;
}
