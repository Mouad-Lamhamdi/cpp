/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molamham <molamham@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 23:19:26 by molamham          #+#    #+#             */
/*   Updated: 2025/12/01 18:51:08 by molamham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <cctype>

std::string Contact::getFirstname() const{
	return firstname;
};

std::string Contact::getLastname() const{
	return lastname;
};

std::string Contact::getPhonenumber() const {
	return phonenumber;
};

std::string Contact::getNickname() const{
	return nickname;
};

std::string Contact::getDarkestsecret() const{
	return darkestsecret;
};

void Contact::showDetails()
{
	std::cout << "First name    : " << firstname << std::endl;
	std::cout << "Last name     : " << lastname << std::endl;
	std::cout << "Nickname      : " << nickname << std::endl;
	std::cout << "Phone number  : " << phonenumber << std::endl;
	std::cout << "Darkest secret: " << darkestsecret << std::endl;
};

void Contact::setInfo()
{
	while (true) {
		std::cout << "First name : ";
		if (!std::getline(std::cin, firstname)) {
			std::cout << "\nInput closed. Aborting." << std::endl;
			exit(0);
		}
		if (!firstname.empty())
			break;
		std::cout << "Input cannot be empty. Please try again." << std::endl;
	}

	while (true) {
		std::cout << "Last name  : ";
		if (!std::getline(std::cin, lastname)) {
			std::cout << "\nInput closed. Aborting." << std::endl;
			exit(0);
		}
		if (!lastname.empty())
			break;
		std::cout << "Input cannot be empty. Please try again." << std::endl;
	}

	while (true) {
		std::cout << "Nickname : ";
		if (!std::getline(std::cin, nickname)) {
			std::cout << "\nInput closed. Aborting." << std::endl;
			exit(0);
		}
		if (!nickname.empty())
			break;
		std::cout << "Input cannot be empty. Please try again." << std::endl;
	}

	while (true) {
		std::cout << "Phone number : ";
		if (!std::getline(std::cin, phonenumber)) {
			std::cout << "\nInput closed. Aborting." << std::endl;
			exit(0);
		}
		if (phonenumber.empty()) {
			std::cout << "Input cannot be empty. Please try again." << std::endl;
			continue;
		}
		bool is_digits_only = true;
		for (size_t i = 0; i < phonenumber.length(); i++) {
			if (!std::isdigit(phonenumber[i])) {
				is_digits_only = false;
				break;
			}
		}
		if (is_digits_only)
			break;
		std::cout << "Phone number must contain only digits. Please try again." << std::endl;
	}

	while (true) {
		std::cout << "Darkest secret : ";
		if (!std::getline(std::cin, darkestsecret)) {
			std::cout << "\nInput closed. Aborting." << std::endl;
			exit(0);
		}
		if (!darkestsecret.empty())
			break;
		std::cout << "Input cannot be empty. Please try again." << std::endl;
	}
};

std::string truncate(std::string str)
{
	if (str.length() > 10)
		return str.substr(0, 9) + ".";
	return str;
}

void Contact::showSummary() {
	std::cout << std::setw(10) << truncate(firstname) << "|"
			  << std::setw(10) << truncate(lastname) << "|"
			  << std::setw(10) << truncate(nickname) << "|" << std::endl;
};