#include <iostream>
#include <string>

int main(int argc, char * argv[])
{
	if(argc < 2)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
		return 1;
	}
	for(int j = 1; j < argc; j++)
	{
		std::string arg = argv[j];
		for(std::size_t i = 0; i < arg.size(); i++)
		{
			std::cout << (char)std::toupper(arg[i]);
		}
		std::cout << " ";
	}
		std::cout << std::endl;
	return 0;
}