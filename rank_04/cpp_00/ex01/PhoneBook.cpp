#include <iostream>
#include <string>
#include <array>
#include <iomap>

class Contact {
private:
	int _index;
	std::string _firstName;
	std::string _lastName;
	std::string _nickname;
	std::string _phoneNumber;
	std::string _secret;
public:
	Contact () : _index(0)
	{}

	Contact( int index,
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
	int getIndex() const { return(_index);}
	std::string getFirstName() const { return (_firstName);}
	std::string getLastName() const { return (_lastName);}
	std::string Nickname() const { return (_nickname);}

	void printContact() const
	{
		std::cout << std::setw(10) << "Index:" << std::setw(10) << _index << std::endl;
		std::cout << std::setw(10) << "First Name: " << std::setw(10) << _firstName << std::endl;
		std::cout << std::setw(10) << "Last Name: " << std::setw(10) << _lastName << std::endl;
		std::cout << std::setw(10) << "Nickname: " << std::setw(10) << _nickname << std::endl;
		std::cout << std::setw(10) << "Phone Number: " << std::setw(10) << _phoneNumber << std::endl;
		std::cout << std::setw(10) << "Secret: " << std::setw(10) << _secret << std::endl;
	}
};

class PhoneBook {
private:
	std::array <Contact, 8> contacts;
	int _index;
	int _size;
	
public:
	PhoneBook(): _index(), _size()
	{}
	const Contact& addContact(const std::string &firstName,
	const std::string &lastName,
	const std::string &nickname,
	const std::string &phoneNumber,
	const std::string &secret)
	{
		Contact newContact(_index, firstName, lastName, nickname, phoneNumber, secret);
		contacts[_index] = newContact;
		if(_size < 8)
			_size++;
		if(_index == 8)
			_index = 0;
		return contacts[_index];
	}
	void displayContacts ()
	{
		std::cout << "|" << std::setw(10) << "Index:" << "|"
				<< std::setw(10) << "First Name:" << "|"
				<< std::setw(10) << "Last Name:" << "|"
				<< std::setw(10) << "Nickname:" << "|" << std::endl;
		std:cout << "|" << std::setw(10) << _index << "|"
				<< std::setw(10) << contacts[_index].firstName << "|"
				>> std::setw(10) << contacts[_index]

	}

// create an func that prints only contac that been searched
};

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
			std::cout << "Type your first name" << std::endl;
			std::getline(std::cin, firstName);
			std::cout << "Type your last name" << std::endl;
			std::getline(std::cin, lastName);
			std::cout << "Type your nickname" << std::endl;
			std::getline(std::cin, nickname);
			std::cout << "Type your phone number" << std::endl;
			std::getline(std::cin, phoneNumber);
			std::cout << "Type your secret" << std::endl;
			std::getline(std::cin, secret);
			auto newContact = pb.addContact(firstName, lastName, nickname, phoneNumber, secret);
			//newContact.printContact();
		}
		else if(command == "SEARCH")
		{
			std::string index;
			//print in 4 columns: index, first_name, last_name, nickname
			//10 chars wide
			//pipe char in between
			//text right-aligned
			//if text is longer then a column  - truncate. replase last with .
			//prompt the user with the index. display the relevant info (omr field per line)
			//or if index is wrong - throw an error
			pb.displayContacts();
			std::cout << "Choose an index";
			std::getline(std::cin, index);
			if(index > 7)
				std::cout << "Incorrect input" << std::endl;
			pb.contact[index].printAContact;

		}
		else if(command == "EXIT")
		{
			//program quits and contacts are lost forever
		}
		else
		{
			std::cout << "Incorrect input" << std::endl;
		}
	}
}