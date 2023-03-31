/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarneir <acarneir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 22:24:43 by acarneir          #+#    #+#             */
/*   Updated: 2023/03/30 22:29:34 by acarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include <iostream>

Weapon::Weapon(){}
Weapon::~Weapon(){}

Weapon::Weapon( std::string type ) {
	this->type = type;
}

const std::string	&Weapon::getType(void){
	return this->type;
}

void	Weapon::setType(std::string type){
	this->type = type;

}