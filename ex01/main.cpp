#include "header.hpp"

int main()
{
	PhoneBook MyPhoneBook;
	std::string command;

	std::cout << "Welcome to your PhoneBook!";
	while (true){
		std::cout << "Enter a command (ADD, SEARCH or EXIT) : ";
		std::getline(std::cin, command);
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