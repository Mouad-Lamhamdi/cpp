#include "header.hpp"

int main(int ac, char **av)
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
			while (true){
				int index = 0;
				std::cout << "Enter the index of the contact to display: ";
				std::cin >> index;
				std::cin.ignore(); // clears the newline left in the input buffer so the next getline() doesn’t break to clarify more later
			}
		}
		else if (command == "EXIT")
			break;
		else
			std::cout << "Unknown command. Try again." << std::endl;
	}
}