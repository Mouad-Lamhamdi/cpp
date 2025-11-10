#include "header.hpp"

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
	std::cout << "First name : ";
	std::getline(std::cin, firstname);

	std::cout << "Last name  : ";
	std::getline(std::cin, lastname);

	std::cout << "Nickname : ";
	std::getline(std::cin, nickname);

	std::cout << "Phone number : ";
	std::getline(std::cin, phonenumber);

	std::cout << "Darkest secret : ";
	std::getline(std::cin, darkestsecret);
};

std::string truncate(std::string str)
{
	if (str.length() > 10)
		return str.substr(0, 9) + "."; // First 9 chars + .(dot) and the end
	return str;
}

void Contact::showSummary() {
	std::cout << std::setw(10) << truncate(firstname) << "|"
			  << std::setw(10) << truncate(lastname) << "|"
			  << std::setw(10) << truncate(nickname) << "|" << std::endl;
};

PhoneBook::PhoneBook(){
	totalContacts = 0;
	index = 0;
};

void PhoneBook::addContact(){

	list[index].setInfo();            // fill the Contact
    index = (index + 1) % 8;         // move to next slot, wrap around at 8
    if (totalContacts < 8)
        totalContacts++;             // increment total if not full yet
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

// void PhoneBook::searchContact(){
// 	int index = 0;
// 	std::cout << "Enter the index of the contact to display: ";
// 	std::cin >> index;
// 	std::cin.ignore(); // clears the newline left in the input buffer so the next getline() doesn’t break to clarify more later

// 	if (index < 1 || index > totalContacts) {
// 		std::cout << "Invalid index. Please try again." << std::endl;
// 		return;
// 	}
// 	list[index - 1].showDetails(); // Adjust for 0-based index
// }

//better version handling invalid input
void PhoneBook::searchContact(){
	std::string input;
	std::cout << "Enter the index of the contact to display: ";
	if (!std::getline(std::cin, input)) { // handle EOF or stream error
		if (std::cin.eof())
			std::cout << "Input closed. Returning to menu." << std::endl;
		else
			std::cout << "Input error." << std::endl;
		return;
	}

	if (input.empty()) {
		std::cout << "No index entered. Please try again." << std::endl;
		return;
	}

	int idx = 0;
	try {
		idx = std::stoi(input);
	} catch (...) {
		std::cout << "Invalid index. Please enter a number." << std::endl;
		return;
	}

	if (idx < 1 || idx > totalContacts) {
		std::cout << "Invalid index. Please try again." << std::endl;
		return;
	}

	list[idx - 1].showDetails(); // Adjust for 0-based index
}