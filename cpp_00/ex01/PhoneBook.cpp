/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarneir <acarneir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 23:56:23 by acarneir          #+#    #+#             */
/*   Updated: 2023/03/22 00:15:30 by acarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>

PhoneBook::PhoneBook() {}
PhoneBook::~PhoneBook() {}

std::string PhoneBook::get_input(std::string str){
	std::string	input;

	std::cout << "Please provide the " << str << ": \n";
	getline(std::cin,input);
	while (input.empty())
	{
		std::cout << "The " << str << " can not be null\n";
		std::cout << "Please provide the " << str << ":\n";
		getline(std::cin,input);
	}
	return input;
}

void PhoneBook::add(){
	Contact contact;

	//bug ao dar add em + de 16 char
	std::cout<< "Adding new contact information.\n";
	contact.first_name = get_input("First Name");
	contact.last_name = get_input("Last Name");
	contact.nickname = get_input("Nickname");
	contact.phone_number = get_input("Phone Number");
	//testar se é apenas numeros?
	contact.darkest_secret = get_input("Darkest secret");

	if (this->index == 8)
		this->index = 0;
	this->contacts[this->index] = contact;
	// this->contacts[this->index].first_name = contact.first_name;
	// this->contacts[this->index].last_name = contact.last_name;
	// this->contacts[this->index].nickname = contact.nickname;
	// this->contacts[this->index].phone_number = contact.phone_number;
	// this->contacts[this->index].darkest_secret = contact.darkest_secret;
	this->index++;
}

std::string PhoneBook::trucate(std::string str){
	std::string truncated_str;

	if (str.length() > 10)
		return str.substr(0, 9) + ".";
	return str;
}

void	PhoneBook::display_line(int index, Contact contact){
	std::cout << std::setw(10) << std::right << index + 1 << "|";
	std::cout << std::setw(10) << std::right << trucate(contact.first_name) << "|";
	std::cout << std::setw(10) << std::right << trucate(contact.last_name) << "|";
	std::cout << std::setw(10) << std::right << trucate(contact.nickname) << "|";
	std::cout <<"\n";
}


void PhoneBook::search(){
	if (index == 0 && this->contacts[index].first_name.empty()){
		std::cout<< "No contacts found. Please try again later.\n";
		return ;
	}
	std::cout << std::setw(10) << std::right << "Index" << "|";
	std::cout << std::setw(10) << std::right << "First Name" << "|";
	std::cout << std::setw(10) << std::right << "Last Name" << "|";
	std::cout << std::setw(10) << std::right << "Nickname" << "|";
	std::cout <<"\n";
	for (int i = 0; i < 8; i++)
		display_line(i, this->contacts[i]);
	return ;
}

void PhoneBook::run(){
	std::string	input;

	std::cout<< "\033c";
	std::cout<< "Welcome to My Awesome PhoneBook!\n";
	while(input != "EXIT"){	
		std::cout<< "Please, choose an option: ADD, SEARCH, EXIT\n";
		getline(std::cin,input);
		// std::cout << "input.compare('ADD') == 0 " << (input.compare("ADD") == 0) << "\n";
		if (input.compare("ADD") == 0)
			add();
		else if (input.compare("SEARCH") == 0)
			search();
		else if (input.compare("EXIT") == 0)
			std::cout<<"Thank you for using My Awesome PhoneBook! Bye Bye!\n";
		//bug loop infinito no crtl + d
		else {
			// std::cout<< input << "|\n";
			// input="ABC";
			// std::cout<< input << "|\n";
			std::cout<<"Invalid option, try again!\n";
		}
	}
	exit(0);
}