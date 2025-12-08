#include <iostream>
#include <string>
#include <array>
// int _number1 = 902345;
// int _number2 = 123590;
// int _number3 = 456780;
// int _number4 = 567890;
// int _number5 = 678901;
// int _number6 = 234567;
// int _number7 = 789012;
// int _number8 = 890123;

class Contact {
public:
	int _index;
	std::string _first_name;
	std::string _last_name;
	std::string _nickname;
};

class PhoneBook {
public:
	std::array <Contact, 8> contacts;
	Contact addContact(int index,
	const std::string &first_name,
	const std::string &last_name,
	const std::string &nickname)
	{
		Contact a;
		a._index = index;
		a._first_name = first_name;
		a._last_name = last_name;
		a._nickname =  nickname;

	}
};

Contact make_contact(Contact)
{
	
}

int main ()
{
	PhoneBook pb;
	pb.make_contact(0, "K", "Z", "dfgl");
	if(ADD)
	{
		//prompt open to input the new contact
		//add contact to the PhoneBook
	}
	else if(SEARCH)
	{
		//printe in 4 columns: index, first_name, last_name, nickname
		//10 chars wide
		//pipe char in between
		//text right-aligned
		//if text is longer then a column  - truncate. replase last with .
		//prompt the user with the index. display the relevant info (omr field per line)
		//or if index is wrong - throw an error
	}
	else
	{
		//program quits and contacts are lost forever
	}
}

//ADD, SEARCH, EXIT