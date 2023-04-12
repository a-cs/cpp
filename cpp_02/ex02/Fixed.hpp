/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarneir <acarneir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 21:48:34 by acarneir          #+#    #+#             */
/*   Updated: 2023/04/12 00:06:50 by acarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int					rawBits;
		static const int	fractionalBits = 8;
	public:
		Fixed();
		Fixed(Fixed const &obj);
		Fixed(int const num);
		Fixed(float const num);
		~Fixed();
		int		getRawBits( void ) const;
		void 	setRawBits( int const raw );
		float 	toFloat( void ) const;
		int 	toInt( void ) const;

    	Fixed 	&operator=(Fixed const &obj);
		bool	operator>(const Fixed &num) const;
		bool	operator<(const Fixed &num) const;
		bool	operator>=(const Fixed &num) const;
		bool	operator<=(const Fixed &num) const;
		bool	operator==(const Fixed &num) const;
		bool	operator!=(const Fixed &num) const;
		Fixed	operator+(const Fixed &num);
		Fixed	operator-(const Fixed &num);
		Fixed	operator*(const Fixed &num);
		Fixed	operator/(const Fixed &num);
		
		Fixed	&operator++();
		Fixed	operator++(int);
		Fixed	&operator--();
		Fixed	operator--(int);

		static Fixed		&min(Fixed &num1, Fixed &num2);
		static const Fixed	&min(Fixed const &num1, Fixed const &num2);
		static Fixed		&max(Fixed &num1, Fixed &num2);
		static const Fixed	&max(Fixed const &num1, Fixed const &num2);
};

std::ostream &operator<<(std::ostream &o, Fixed const &obj);

#endif