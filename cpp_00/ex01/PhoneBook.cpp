/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarneir <acarneir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 23:56:23 by acarneir          #+#    #+#             */
/*   Updated: 2023/05/15 22:53:00 by acarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>
#include <sstream>

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

	std::cout<< "Adding new contact information.\n";
	contact.first_name = get_input("First Name");
	contact.last_name = get_input("Last Name");
	contact.nickname = get_input("Nickname");
	contact.phone_number = get_input("Phone Number");
	contact.darkest_secret = get_input("Darkest secret");

	if (this->index == 8)
		this->index = 0;
	this->contacts[this->index] = contact;
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

void	PhoneBook::display_contact(Contact contact){
	std::cout << "First Name: " << contact.first_name << "\n";
	std::cout << "Last Name: " << contact.last_name << "\n";
	std::cout << "Nickname: " << contact.nickname << "\n";
	std::cout << "Phone number: " << contact.phone_number << "\n";
	std::cout << "Darkest secret: " << contact.darkest_secret << "\n";
}


void PhoneBook::search(){
	int			i;
	std::string	input;

	if (index == 0 && this->contacts[index].first_name.empty()){
		std::cout<< "No contacts found. Please try again later.\n";
		return ;
	}
	std::cout << std::setw(10) << std::right << "Index" << "|";
	std::cout << std::setw(10) << std::right << "First Name" << "|";
	std::cout << std::setw(10) << std::right << "Last Name" << "|";
	std::cout << std::setw(10) << std::right << "Nickname" << "|";
	std::cout <<"\n";
	for (int i = 0; (i < 8 && !this->contacts[i].first_name.empty()); i++)
		display_line(i, this->contacts[i]);
	std::cout << "Select an index to display the contact information:\n";
	getline(std::cin, input);
	std::stringstream sstr(input);
	sstr >> i;
	while(i < 1 || i > 8 || this->contacts[i - 1].first_name.empty()){
		std::cout << "Invalid index. Please, try again.\n";
		std::cout << "Select an index to see the contact data:\n";
		getline(std::cin, input);
		std::stringstream sstr(input);
		sstr >> i;
	}
	std::cout << "Contact Information:\n";
	display_contact(this->contacts[i - 1]);
	return ;
}

void PhoneBook::run(){
	std::string	input;

	std::cout<< "\033c";
	std::cout<< "Welcome to My Awesome PhoneBook!\n";
	while(!std::cin.eof() && input != "EXIT"){
		std::cout<< "Please, choose an option: ADD, SEARCH, EXIT\n";
		getline(std::cin,input);
		if (input.compare("ADD") == 0)
			add();
		else if (input.compare("SEARCH") == 0)
			search();
		else if (std::cin.eof() || input.compare("EXIT") == 0)
			std::cout<<"Thank you for using My Awesome PhoneBook! Bye Bye!\n";
		else {
			std::cout<<"Invalid option, try again!\n";
		}
	}
}