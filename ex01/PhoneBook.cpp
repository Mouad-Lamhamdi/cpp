/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molamham <molamham@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 23:19:37 by molamham          #+#    #+#             */
/*   Updated: 2025/12/01 18:06:02 by molamham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(){
	totalContacts = 0;
	index = 0;
};

void PhoneBook::addContact(){

	list[index].setInfo();
    index = (index + 1) % 8;
    if (totalContacts < 8)
        totalContacts++;
};

void PhoneBook::showAllsummaries(){

	std::cout << std::setw(10) << "Index" << "|"
			  << std::setw(10) << "First Name" << "|"
			  << std::setw(10) << "Last Name" << "|"
			  << std::setw(10) << "Nickname" << "|" << std::endl;
	for (int i = 0; i < totalContacts; i++){
		std::cout << std::setw(10) << i + 1 << "|";
		list[i].showSummary();
	}
};


void PhoneBook::searchContact(){
	std::string input;
	while (true) {
		std::cout << "Enter the index of the contact to display: ";
		if (!std::getline(std::cin, input)) { // handle EOF
			if (std::cin.eof()) {
				std::cout << "\nInput closed. Aborting." << std::endl;
				exit(0);
			}
			else {
				std::cout << "Input error." << std::endl;
				return;
			}
		}
		if (input.empty()) {
			std::cout << "No index entered. Please try again." << std::endl;
		} else {
			break;
		}
	}
	int idx = std::atoi(input.c_str());
	
	if (idx < 1 || idx > totalContacts) {
		std::cout << "Invalid index. Please try again." << std::endl;
		return;
	}
	
	list[idx - 1].showDetails(); // Adjust for 0-based index
}
