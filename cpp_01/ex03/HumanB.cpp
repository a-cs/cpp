/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarneir <acarneir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 22:57:34 by acarneir          #+#    #+#             */
/*   Updated: 2023/05/31 22:29:36 by acarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include <iostream>

HumanB::~HumanB(){};

HumanB::HumanB( std::string name){
	this->name = name;
	this->weapon = NULL;
}

void	HumanB::attack() const{
	if(this->weapon)
		std::cout << this->name << " attacks with their " << this->weapon->getType() << "\n";
	else
		std::cout << this->name << " tried to attack without a weapon\n";
}

void	HumanB::setWeapon(Weapon &weapon){
	this->weapon = &weapon;
}