/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarneir <acarneir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 23:56:26 by acarneir          #+#    #+#             */
/*   Updated: 2023/03/21 23:18:01 by acarneir         ###   ########.fr       */
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
		void		add();
		void		search();
		void		display_line(int index, Contact contact);
		std::string trucate(std::string str);
		std::string	get_input(std::string str);
};

#endif