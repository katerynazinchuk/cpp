#include "Weapon.hpp"

int main (void)
{
    Weapon club("crude spiked club");
    std::cout << club.getType() << std::endl;
    club.setType("some other type of club");
    std::cout <<club.getType() << std::endl;
    return (0);
}