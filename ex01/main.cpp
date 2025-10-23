#include <iostream>

class Contact {
	private:
		std::string Firstname;
		std::string Lastname;
		std::string Phonenumber;
		std::string Darkestsecret;
	public:
		void setinfo(){

			std::cout << "Enter first name : ";
			std::getline(std::cin, Firstname);

			std::cout << "Enter last name : ";
			std::getline(std::cin, Lastname);

			std::cout << "Enter phone number : ";
			std::getline(std::cin, Phonenumber);

			std::cout << "Enter darkest secret : ";
			std::getline(std::cin, Darkestsecret);
		}
		void showinfo(){

			std::cout << Firstname << std::endl;
			std::cout << Lastname << std::endl;
			std::cout << Phonenumber << std::endl;
			std::cout << Darkestsecret << std::endl;
		}
};

int main(int ac, char **av)
{
	Contact c;

	c.setinfo();
	c.showinfo();
	return 0;
}