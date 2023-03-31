/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarneir <acarneir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 22:57:28 by acarneir          #+#    #+#             */
/*   Updated: 2023/03/30 23:16:30 by acarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_H
# define HUMANB_H

#include <string>
#include "Weapon.hpp"

class HumanB
{
	private:
		std::string name;
		Weapon		*weapon;
	public:
		HumanB( std::string name);
		~HumanB();
		void	attack() const;
		void	setWeapon(Weapon &weapon);
};

#endif