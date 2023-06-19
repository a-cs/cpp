/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarneir <acarneir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 23:56:26 by acarneir          #+#    #+#             */
/*   Updated: 2023/06/18 21:11:53 by acarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

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
		void		display_contact(Contact contact);
		std::string trucate(std::string str);
		std::string	get_input(std::string str);
};

#endif