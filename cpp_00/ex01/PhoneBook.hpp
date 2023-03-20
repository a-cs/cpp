/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarneir <acarneir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 23:56:26 by acarneir          #+#    #+#             */
/*   Updated: 2023/03/20 00:39:20 by acarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

#include <string>
#include "Contact.hpp"

class PhoneBook {
	public:
		Contact contacts[8];
		PhoneBook();
		~PhoneBook();
		void run();
	private:
		int			index = 0;
		void		add_contact();
		std::string	get_input(std::string str);
};

#endif