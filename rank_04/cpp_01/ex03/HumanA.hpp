#ifndef HUMAN_A_HHP
# define HUMAN_A_HHP

#include <string>
#include <iostream>
#include "Weapon.hpp"

class HumanA
{
    private:
        std::string _name;
        Weapon& _weapon;
    public:
        HumanA(std::string name, Weapon& weapon);
        void attack(void) const;
};

#endif
