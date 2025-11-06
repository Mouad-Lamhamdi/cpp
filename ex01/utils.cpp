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

