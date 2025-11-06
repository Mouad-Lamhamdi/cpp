/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molamham <molamham@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 12:17:05 by molamham          #+#    #+#             */
/*   Updated: 2025/11/06 11:31:32 by molamham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# include <iostream>
# include <iomanip>

class Contact
{
	private:
		std ::string firstname;
		std ::string lastname;
		std ::string nickname;
		std ::string phonenumber;
		std ::string darkestsecret;

	public:
		void setInfo();
		void showSummary();
		void showDetails();

		//getters
		std::string getFirstname() const;
		std::string getLastname() const;
		std::string getPhonenumber() const;
		std::string getNickname() const;
		std::string getDarkestsecret() const;
};

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
		// void searchContact();
};

#endif