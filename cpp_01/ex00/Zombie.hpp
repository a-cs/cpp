/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarneir <acarneir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 22:07:56 by acarneir          #+#    #+#             */
/*   Updated: 2023/06/18 21:11:53 by acarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

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

Zombie *newZombie( std::string name );
void randomChump( std::string name );

#endif