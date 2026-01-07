#include "Zombie.hpp"

//return pointer first element in Zombie array 
Zombie* zombieHorde(int N, std::string name)
{
    Zombie* horde;
    int i;

    if( N <= 0)
        return (0);
    horde = new Zombie[N];
    for(i = 0; i < N; i++)
    {
        horde[i].setName(name);
    }
    return (horde);
}