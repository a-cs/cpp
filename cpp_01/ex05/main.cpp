/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarneir <acarneir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 21:24:29 by acarneir          #+#    #+#             */
/*   Updated: 2023/04/05 22:52:56 by acarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

int	main(int argc, char **argv) {
	Harl	harl;

	if (argc !=2){
		std::cout << "You should pass only 1 arguments.\nYou must choose between the following option:\nDEBUG, INFO, WARNING or ERROR.\n";
		return 1;
	}
	harl.complain(argv[1]);
	return (0);
}