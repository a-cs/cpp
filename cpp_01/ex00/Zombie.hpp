/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarneir <acarneir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 22:07:56 by acarneir          #+#    #+#             */
/*   Updated: 2023/03/27 22:20:25 by acarneir         ###   ########.fr       */
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
	~Zombie();
	void		announce( void );
	void		set_name(std::string);
	std::string	get_name( void );
};


#endif