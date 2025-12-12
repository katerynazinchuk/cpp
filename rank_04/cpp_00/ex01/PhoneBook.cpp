#include "PhoneBook.hpp"
#include <iostream>
#include <string>
#include <array>
#include <iomanip>

std::string truncate(const std::string &string)
{
	if(string.length() <= 10)
		return string;
	return string.substr(0, 9) + ".";
}

Contact::Contact () : _index(0)
{}

Contact::Contact( int index,
        const std::string &firstName,
        const std::string &lastName,
        const std::string &nickname,
		const std::string &phoneNumber,
		const std::string &secret)
		: _index(index),
		_firstName(firstName),
		_lastName(lastName),
		_nickname(nickname),
		_phoneNumber(phoneNumber),
		_secret(secret)
{}
int Contact::getIndex() const { return (_index);}
const std::string &Contact::getFirstName() const { return (_firstName);}
const std::string &Contact::getLastName() const { return (_lastName);}
const std::string &Contact::getNickname() const { return (_nickname);}

void Contact::printContact() const
{
	std::cout << std::setw(14) << "Index: " << std::setw(4) << _index << std::endl;
	std::cout << std::setw(14) << "First Name: " << std::setw(4) << _firstName << std::endl;
	std::cout << std::setw(14) << "Last Name: " << std::setw(4) << _lastName << std::endl;
	std::cout << std::setw(14) << "Nickname: " << std::setw(4) << _nickname << std::endl;
	std::cout << std::setw(14) << "Phone Number: " << std::setw(4) << _phoneNumber << std::endl;
	std::cout << std::setw(14) << "Secret: " << std::setw(4) << _secret << std::endl;
}

PhoneBook::PhoneBook(): _index(), _size()
{}
void PhoneBook::addContact(const std::string &firstName,
const std::string &lastName,
const std::string &nickname,
const std::string &phoneNumber,
const std::string &secret)
{
	Contact newContact(_index, firstName, lastName, nickname, phoneNumber, secret);
	contacts[_index] = newContact;
	if(_size < 8)
		_size++;
	_index = (_index + 1) % 8;
}
void PhoneBook::getContact(int i) const
{
	if( i < 0 || i >= _size)
	{
		std::cout << "Incorrect input" << std::endl;
		return;
	}
	contacts[i].printContact();
}
void PhoneBook::displayContacts () const
{
	if(_size == 0)
	{
		std::cout << "PhoneBook is empty" <<std::endl;
		return;
	}
	std::cout << "|" << std::setw(10) << "Index" << "|"
			<< std::setw(10) << "First Name" << "|"
			<< std::setw(10) << "Last Name" << "|"
			<< std::setw(10) << "Nickname        " << "|" << std::endl;
	for(int i = 0; i <_size; i++)
	{
		const Contact &c = contacts[i];
		std::cout << "|" << std::setw(10) << c.getIndex() << "|"
			<< std::setw(10) << truncate(c.getFirstName()) << "|"
			<< std::setw(10) << truncate(c.getLastName()) << "|"
			<< std::setw(10) << truncate(c.getNickname()) << "|" << std::endl;
	}
}


int main ()
{
	std::string command;

	std::string firstName;
	std::string lastName;
	std::string nickname;
	std::string phoneNumber;
	std::string secret;
	PhoneBook pb;
	while(true)
	{
		std::cout << "Enter a command (ADD, SEARCH, EXIT): " << std::endl;
		std::getline(std::cin, command);
		if(command == "ADD")
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
		else if(command == "SEARCH")
		{
			std::string index;
			pb.displayContacts();
			std::cout << "Choose an index: ";
			std::getline(std::cin, index);
			if(index.size() != 1 || !std::isdigit(index[0]))
			{
				std::cout << "Incorrect input" << std::endl;
				continue;
			}
			int index_dig = index[0] - '0';
			pb.getContact(index_dig);
		}
		else if(command == "EXIT")
		{
			break;
		}
		else
		{
			std::cout << "Incorrect input" << std::endl;
		}
	}
}