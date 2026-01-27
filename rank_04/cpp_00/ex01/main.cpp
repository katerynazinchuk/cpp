#include "PhoneBook.hpp"
#include "Contact.hpp"

int main()
{
	std::string command;

	std::string firstName;
	std::string lastName;
	std::string nickname;
	std::string phoneNumber;
	std::string secret;
	PhoneBook pb;
	while (true)
	{
		std::cout << "Enter a command (ADD, SEARCH, EXIT): " << std::endl;
		std::getline(std::cin, command);
		if (command == "ADD")
		{
			std::cout << "Type your first name:" << std::endl;
			std::getline(std::cin, firstName);
			std::cout << "Type your last name:" << std::endl;
			std::getline(std::cin, lastName);
			std::cout << "Type your nickname:" << std::endl;
			std::getline(std::cin, nickname);
			std::cout << "Type your phone number:" << std::endl;
			std::getline(std::cin, phoneNumber);
			std::cout << "Type your secret:" << std::endl;
			std::getline(std::cin, secret);
			pb.addContact(firstName, lastName, nickname, phoneNumber, secret);
			//newContact.printContact();
		}
		else if (command == "SEARCH")
		{
			std::string index;
			pb.displayContacts();
			std::cout << "Choose an index: ";
			std::getline(std::cin, index);
			if (index.size() != 1 || !std::isdigit(index[0]))
			{
				std::cout << "Incorrect input" << std::endl;
				continue;
			}
			int index_dig = index[0] - '0';
			pb.getContact(index_dig);
		}
		else if (command == "EXIT")
		{
			break;
		}
		else
		{
			std::cout << "Incorrect input" << std::endl;
		}
	}
}