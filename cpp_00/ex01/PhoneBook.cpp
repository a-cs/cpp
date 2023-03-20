/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarneir <acarneir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 23:56:23 by acarneir          #+#    #+#             */
/*   Updated: 2023/03/20 00:39:49 by acarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>

PhoneBook::PhoneBook() {}
PhoneBook::~PhoneBook() {}

std::string PhoneBook::get_input(std::string str){
	std::string	input;

	std::cout << "\nPlease provide the " << str << ": ";
	getline(std::cin,input);
	while (input.empty())
	{
		std::cout << "\nThe " << str << " can not be null";
		std::cout << "\nPlease provide the " << str << ": ";
		getline(std::cin,input);
	}
	return input;
}

void PhoneBook::add_contact(){
	Contact contact;

	std::cout<< "\nPlease, insert the new contact information:\n";
	contact.first_name = get_input("First Name");
	contact.last_name = get_input("Last Name");
	contact.nickname = get_input("Nickname");
	contact.phone_number = get_input("Phone Number");
	//testar se é apenas numeros?
	contact.darkest_secret = get_input("Darkest secret");

	if(this->index == 8)
		this->index = 0;
	this->contacts[index].first_name = contact.first_name;
	this->contacts[index].last_name = contact.last_name;
	this->contacts[index].nickname = contact.nickname;
	this->contacts[index].phone_number = contact.phone_number;
	this->contacts[index].darkest_secret = contact.darkest_secret;
	this->index++;
}

void PhoneBook::run(){
	std::string	input;

	std::cout<< "\n\nWelcome to My Awesome PhoneBook!\n\n\n";
	while(input != "EXIT"){	
		std::cout<< "Choose an option: ADD, SEARCH, EXIT\n";
		getline(std::cin,input);
		// std::cout << "input.compare('ADD') == 0 " << (input.compare("ADD") == 0) << "\n";
		if(input.compare("ADD") == 0)
			add_contact();
		else if(input.compare("SEARCH") == 0)
			std::cout<<"SEARCH was chosen\n";
		else if(input.compare("EXIT") == 0)
			std::cout<<"Thank you for using My Awesome PhoneBook! Bye Bye!\n";
		else
			std::cout<<"Invalid option, try again!\n";
	}
	exit(0);
}