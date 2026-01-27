#pragma once
#include <iostream>
#include <string>
#include <array>
#include <iomanip>

class PhoneBook {
private:
	std::array <Contact, 8> contacts;
	int _index;
	int _size;
	
public:
	PhoneBook();
	void addContact(const std::string &firstName,
	const std::string &lastName,
	const std::string &nickname,
	const std::string &phoneNumber,
	const std::string &secret);
	void getContact(int i) const;
	void displayContacts () const;
};