/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarneir <acarneir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 23:11:21 by acarneir          #+#    #+#             */
/*   Updated: 2023/03/29 23:11:23 by acarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(){}

Zombie::Zombie( std::string name ) {
	this->name = name;
}

Zombie::~Zombie(){
	std::cout << this->get_name() << " has died!\n";
}

void Zombie::announce(void){
	std::cout << this->get_name() << ": BraiiiiiiinnnzzzZ...\n";
}

std::string	Zombie::get_name(){
	return this->name;
}

void	Zombie::set_name(std::string name){
	this->name = name;
}