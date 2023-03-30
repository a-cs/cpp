/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarneir <acarneir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 21:57:14 by acarneir          #+#    #+#             */
/*   Updated: 2023/03/29 23:25:56 by acarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

Zombie *zombieHorde( int N, std::string name ){
	if(N < 1){
		std::cout << "You can not pass a value to N smaller than 1.\n";
		return NULL;
	}
	Zombie	*zombieHorde = new Zombie[N];
	for(int i = 0; i < N; i++){
		zombieHorde[i].set_name(name);
	}
	return zombieHorde;
	
}