/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarneir <acarneir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 22:05:09 by acarneir          #+#    #+#             */
/*   Updated: 2023/03/29 22:06:57 by acarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

int	main(void) {
	Zombie *zombie = new Zombie;
	zombie->set_name("foo");
	zombie->announce();
	delete zombie;

	Zombie *zombie2 = newZombie("bar");
	zombie2->announce();
	delete zombie2;

	randomChump("baz");
	return (0);
}