#include "ClapTrap.hpp"

int main ()
{
    ClapTrap ct("Alice");
    for (int i = 0; i < 10; i++)
        ct.attack("Enemy");
    ct.attack("Enemy");
    ct.takeDamage(2);
    ct.beRepaired(5);
    return (0);
}