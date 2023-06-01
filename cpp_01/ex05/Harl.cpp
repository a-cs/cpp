/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarneir <acarneir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 21:30:06 by acarneir          #+#    #+#             */
/*   Updated: 2023/05/31 23:22:03 by acarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

Harl::Harl(){}

Harl::~Harl(){}

void Harl::debug( void ){
	std::cout << "[ DEBUG ]\nI love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!\n";
}

void Harl::info( void ) {
	std::cout << "[ INFO ]\nI cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n";
}

void Harl::warning( void ) {
	std::cout << "[ WARNING ]\nI think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month.\n";
}

void Harl::error( void ) {
	std::cout << "[ ERROR ]\nThis is unacceptable! I want to speak to the manager now.\n";
}

void	Harl::complain( std::string level ){
	std::string	option[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*fp[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	for(int i=0; i < 4; i++){
		if(option[i] == level)
			return (this->*fp[i])();
	}
	return (this->*fp[3])();
}
