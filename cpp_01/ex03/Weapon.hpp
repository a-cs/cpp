/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarneir <acarneir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 22:24:22 by acarneir          #+#    #+#             */
/*   Updated: 2023/03/30 22:33:01 by acarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_H
# define WEAPON_H

#include <string>

class Weapon
{
	private:
		std::string type;
	public:
		Weapon();
		~Weapon();
		Weapon( std::string type );
		const std::string	&getType(void);
		void				setType(std::string);
};

#endif