/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarneir <acarneir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 22:31:37 by acarneir          #+#    #+#             */
/*   Updated: 2023/06/18 21:11:53 by acarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include <string>
#include "Weapon.hpp"

class HumanA
{
	private:
		std::string name;
		Weapon		&weapon;
	public:
		HumanA( std::string name, Weapon &Weapon );
		~HumanA();
		void	attack() const;
};

#endif