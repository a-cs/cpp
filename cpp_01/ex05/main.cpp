/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarneir <acarneir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 21:24:29 by acarneir          #+#    #+#             */
/*   Updated: 2023/05/31 23:17:11 by acarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

int	main(void) {
	Harl	harl;

	std::string	option[5] = {"DEBUG", "INFO", "WARNING", "ERROR", "INVALID"};
	for(int i=0; i < 5; i++){
		std::cout << "Option[" << i <<"] = "<<option[i]<<"\n";
		harl.complain(option[i]);
	}
	return (0);
}