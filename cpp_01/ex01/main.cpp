/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarneir <acarneir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 23:11:07 by acarneir          #+#    #+#             */
/*   Updated: 2023/03/29 23:44:23 by acarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

int	main(void) {
	int	N = 5;

	Zombie	*horde= zombieHorde(N, "Horde");
	for(int i = 0; i < N; i++){
		std::cout << "I = " << i << " - ";
		horde[i].announce();
	}
	delete[] horde;

	N = -1;
	std::cout << "N = " << N << " -> ";
	Zombie	*horde2= zombieHorde(N, "Horde");
	N = 0;
	std::cout << "N = " << N << " -> ";
	Zombie	*horde3= zombieHorde(N, "Horde");
	// for(int i = 0; i < N; i++){
	// 	std::cout << "I = " << i << " - ";
	// 	horde2[i].announce();
	// }
	// delete[] horde2;
	return (0);
}