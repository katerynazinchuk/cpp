#include "PhoneBook.hpp"
#include "Contact.hpp"

std::string truncate(const std::string &string)
{
	if (string.length() <= 10)
		return string;
	return string.substr(0, 9) + ".";
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
	if (_size < 8)
		_size++;
	_index = (_index + 1) % 8;
}

void PhoneBook::getContact(int i) const
{
	if (i < 0 || i >= _size)
	{
		std::cout << "Incorrect input" << std::endl;
		return;
	}
	contacts[i].printContact();
}

void PhoneBook::displayContacts() const
{
	if (_size == 0)
	{
		std::cout << "PhoneBook is empty" <<std::endl;
		return;
	}
	std::cout << "|" << std::setw(10) << "Index" << "|"
			<< std::setw(10) << "First Name" << "|"
			<< std::setw(10) << "Last Name" << "|"
			<< std::setw(10) << "Nickname        " << "|" << std::endl;
	for (int i = 0; i <_size; i++)
	{
		const Contact &c = contacts[i];
		std::cout << "|" << std::setw(10) << c.getIndex() << "|"
			<< std::setw(10) << truncate(c.getFirstName()) << "|"
			<< std::setw(10) << truncate(c.getLastName()) << "|"
			<< std::setw(10) << truncate(c.getNickname()) << "|" << std::endl;
	}
}