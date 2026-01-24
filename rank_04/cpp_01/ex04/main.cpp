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
        std::ifstream in(filename);
        if(!in)
        {
            std::cout << "can't open a file" << std::endl;
            return (1);
        }
        std::string line;
        while(std::getline(in, line))
        {
            int pos = 0;
            std::cout << line << std::endl;
            int new_pos = line.find(s1, pos);
            pos = new_pos + s1.length();
        }
        

        // for(int i = 0; i < argc; i++)
        // {
        //     std::string arg = argv[i];
        //     std::cout << arg << std::endl;
        // }
    }
    else
        std::cout << "Wrong input" << std::endl;
    return 0;
}