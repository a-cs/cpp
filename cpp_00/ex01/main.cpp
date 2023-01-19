/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarneir <acarneir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 23:26:59 by acarneir          #+#    #+#             */
/*   Updated: 2023/01/19 00:02:38 by acarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(void){
	std::string	input;

	std::cout<< "\n\nWelcome to My Awesome Phonebook!\n\n\n";
	while(input != "EXIT"){	
		std::cout<< "Choose an option: ADD, SEARCH, EXIT\n";
		getline(std::cin,input);
		// std::cout << "input.compare('ADD') == 0 " << (input.compare("ADD") == 0) << "\n";
		if(input.compare("ADD") == 0)
			std::cout<<"ADD was chosen\n";
		else if(input.compare("SEARCH") == 0)
			std::cout<<"SEARCH was chosen\n";
		else if(input.compare("EXIT") == 0)
			std::cout<<"Thank you for using My Awesome Phonebook! Bye Bye!\n";
		else
			std::cout<<"Invalid option, try again!\n";
	}
	return 0;
}