#include "Contact.hpp"

Contact::Contact () : _index(0)
{}

Contact::Contact(int index,
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

int Contact::getIndex() const
{
    return (_index);
}

const std::string &Contact::getFirstName() const
{ 
    return (_firstName);
}

const std::string &Contact::getLastName() const
{
    return (_lastName);
}

const std::string &Contact::getNickname() const
{
    return (_nickname);
}

void Contact::printContact() const
{
	std::cout << std::setw(14) << "Index: " << std::setw(4) << _index << std::endl;
	std::cout << std::setw(14) << "First Name: " << std::setw(4) << _firstName << std::endl;
	std::cout << std::setw(14) << "Last Name: " << std::setw(4) << _lastName << std::endl;
	std::cout << std::setw(14) << "Nickname: " << std::setw(4) << _nickname << std::endl;
	std::cout << std::setw(14) << "Phone Number: " << std::setw(4) << _phoneNumber << std::endl;
	std::cout << std::setw(14) << "Secret: " << std::setw(4) << _secret << std::endl;
}