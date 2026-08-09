#include "Serializer.hpp"
#include <string>
#include <iostream>

int main ()
{
	Data d;
	d.id = 1;
	d.name = "Name";

	uintptr_t raw = Serializer::serialize(&d);
	Data* back = Serializer::deserialize(raw);
	if(back != &d)
	{
		std::cout << "KO" << std::endl;
		return 1;
	}
	std::cout << "id: " << back->id << std::endl;
	std::cout << "name: " << back->name << std::endl;
	std::cout << "OK" << std::endl;
	return 0;
}