
#include <iostream>

#include <vector>

class Person {
private:
	int _age;
	std::string _name;
public:
	Person(std::string name) : _name(name), _age(20)
	{
		std::cout << "Constructor was called " << _name << " " << _age << std::endl; 
	}
	Person(const char* name) : _name(name), _age(20)
	{
		std::cout << "Constructor was called arguments:" << _name << " " << _age << std::endl; 
	}
	Person(const Person &other) {
		std::cout << "Copy Constructor called" << std::endl;
		if (this != &other) {
			*this = other;
		}
	}
	Person& operator=(const Person& toAssign) {
		_name = toAssign._name;
		_age = toAssign._age;
		return (*this);
	}

	~Person()
	{
		std::cout << "Destructor was called " << _name << std::endl;
	}

	inline std::string getName() {
		return _name;
	}
};

int main() {
	Person Tom = "Tom";
	Person Tom("Tom");
	Tom.getName();

	std::vector<std::string> vec;

	// std::string string("hello world");
	// std::string string2 = string;
	// std::string string3(string);
	// std::string string4 = "hello world";


	return (0);
}