/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molamham <molamham@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 23:49:57 by molamham          #+#    #+#             */
/*   Updated: 2025/11/20 00:16:17 by molamham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include "Contact.hpp"
# include <cstdlib>

class PhoneBook
{
	private:
		Contact list[8];
		int totalContacts;
		int index;

	public:
		PhoneBook();
		void addContact();
		void showAllsummaries();
		void searchContact();
};

#endif
