/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarneir <acarneir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 22:00:22 by acarneir          #+#    #+#             */
/*   Updated: 2023/03/30 22:19:58 by acarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(void) {
	std::string	string = "HI THIS IS BRAIN";
	std::string	*stringPTR = &string;
	std::string &stringREF = string;
	
	std::cout << "String memory address: " << &string << "\n";
	std::cout << "Pointer memory address: " << stringPTR << "\n";
	std::cout << "Reference memory address: " << &stringREF << "\n";

	std::cout << "\nString value: " << string << "\n";
	std::cout << "Pointer pointed value: " << *stringPTR << "\n";
	std::cout << "Reference pointed value: " << stringREF << "\n";
	return (0);
}