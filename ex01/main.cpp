/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molamham <molamham@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 23:19:17 by molamham          #+#    #+#             */
/*   Updated: 2025/11/27 19:56:20 by molamham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main()
{
	PhoneBook MyPhoneBook;
	std::string command;

	std::cout << "Welcome to your PhoneBook!";
	while (true){
		std::cout << "Enter a command (ADD, SEARCH or EXIT) : ";
		if (!std::getline(std::cin, command))
		{
			if (std::cin.eof())
			{
				std::cout << "\nInput closed . Exiting program.\n";
				break;
			}
		}
		if (command == "ADD")
			MyPhoneBook.addContact();
		else if (command == "SEARCH"){
			MyPhoneBook.showAllsummaries();
			MyPhoneBook.searchContact();
		}
		else if (command == "EXIT")
			break;
		else
			std::cout << "Unknown command. Try again." << std::endl;
	}
}