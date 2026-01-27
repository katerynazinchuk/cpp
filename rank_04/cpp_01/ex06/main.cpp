#include "Harl.hpp"

int main(int argc, char **argv)
{
    if(argc == 2)
    {
        Harl harl;
        int index = -1;
        int i = 0;
        std::string arg = argv[1];
        std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
        for (i = 0; i < 4; i++)
        {
            if(levels[i] == arg)
            {
                index = i;
                break;
            }
        }
        switch (index)
        {
            case 0:
                std::cout << "[ DEBUG ]" << std::endl;
                harl.complain(levels[0]);
            case 1:
                std::cout << "[ INFO ]" << std::endl;
                harl.complain(levels[1]);
            case 2:
                std::cout << "[ WARNING ]" << std::endl;
                harl.complain(levels[2]);
            case 3:
                std::cout << "[ ERROR ]" << std::endl;
                harl.complain(levels[3]);
                break;
            default:
                std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
        }
        return (0);
    }
    std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
    return (1);
}