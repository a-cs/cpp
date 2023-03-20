/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarneir <acarneir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 23:10:11 by acarneir          #+#    #+#             */
/*   Updated: 2023/03/19 23:53:18 by acarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
# define CONTACT_H

#include <string>

class Contact {
	public:
		std::string first_name;
		std::string last_name;
		std::string nickname;
		std::string phone_number;
		std::string darkest_secret;

		Contact();
		~Contact();
		Contact(std::string first_name, std::string last_name,
		std::string nickname, std::string phone_number,
		std::string darkest_secret);
};

#endif