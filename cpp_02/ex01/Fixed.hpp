/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarneir <acarneir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 22:35:17 by acarneir          #+#    #+#             */
/*   Updated: 2023/04/09 23:14:13 by acarneir         ###   ########.fr       */
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
    	Fixed &operator=(Fixed const &obj);
		~Fixed();
		int getRawBits( void ) const;
		void setRawBits( int const raw );
		float toFloat( void ) const;
		int toInt( void ) const;
};

std::ostream &operator<<(std::ostream &o, Fixed const &obj);

#endif