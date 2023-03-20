/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarneir <acarneir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 23:13:51 by acarneir          #+#    #+#             */
/*   Updated: 2023/03/19 23:54:35 by acarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(){}
Contact::~Contact(){}

Contact::Contact(std::string first_name, std::string last_name,
		std::string nickname, std::string phone_number,
		std::string darkest_secret){
	this->first_name = first_name;
	this->last_name = last_name;
	this->nickname = nickname;
	this->phone_number = phone_number;
	this->darkest_secret = darkest_secret;
}