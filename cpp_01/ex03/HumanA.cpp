/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarneir <acarneir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 22:31:32 by acarneir          #+#    #+#             */
/*   Updated: 2023/03/30 22:55:15 by acarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include <iostream>

HumanA::~HumanA(){};

HumanA::HumanA( std::string name, Weapon &weapon ) : weapon(weapon){
	this->name = name;
}

void	HumanA::attack() const{
	std::cout << this->name << " attacks with their " << this->weapon.getType() << "\n";
}