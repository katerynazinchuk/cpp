#include <iostream>
#include <string>
#include <fstream>

int main (int argc, char **argv)
{
    if(argc == 4)
    {
        std::string filename = argv[1];
        std::string s1 = argv[2];
        std::string s2 = argv[3];
		if(s1.empty())
		{
			std::cout << "empty string" << std::endl;
			return (1);
		}
		std::ifstream in(filename);
		if(!in)
        {
            std::cout << "can't open a file" << std::endl;
            return (1);
        }
		std::ofstream out(filename + ".replace");
		if(!out)
		{
			std::cout << "can't create output file" << std::endl;
			return 1;
		}
        std::string line;
        while(std::getline(in, line))
        {
			std::string result;
            std::size_t pos = 0;
			std::size_t new_pos = line.find(s1, pos);
			
			while(new_pos != std::string::npos)
			{
				result.append(line, pos, new_pos - pos);
				result.append(s2);

            	pos = new_pos + s1.length();
				new_pos = line.find(s1, pos);
			}
			result.append(line, pos, std::string::npos);
			out << result << std::endl;
        }
    }
    else
        std::cout << "Wrong input" << std::endl;
    return 0;
}