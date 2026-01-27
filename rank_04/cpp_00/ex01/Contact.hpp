#pragma once
#include <iostream>
#include <string>
#include <array>
#include <iomanip>


class Contact {
private:
	int _index;
	std::string _firstName;
	std::string _lastName;
	std::string _nickname;
	std::string _phoneNumber;
	std::string _secret;
public:
	Contact();

	Contact(int index,
	        const std::string &firstName,
	        const std::string &lastName,
	        const std::string &nickname,
			const std::string &phoneNumber,
			const std::string &secret);
	int getIndex() const;
	const std::string &getFirstName() const;
	const std::string &getLastName() const;
	const std::string &getNickname() const;

	void printContact() const;
};