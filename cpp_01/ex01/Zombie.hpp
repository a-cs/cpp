/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarneir <acarneir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 23:11:27 by acarneir          #+#    #+#             */
/*   Updated: 2023/03/29 23:16:16 by acarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
# define ZOMBIE_H

#include <string>

class Zombie
{
	private:
		std::string name;
	public:
		Zombie();
		Zombie( std::string name );
		~Zombie();
		void		announce( void );
		void		set_name(std::string);
		std::string	get_name( void );
};

Zombie* zombieHorde( int N, std::string name );

#endif