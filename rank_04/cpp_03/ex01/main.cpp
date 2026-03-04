#include "ScavTrap.hpp"

int main ()
{
	ClapTrap ct("Alice");
	ScavTrap st ("Serena");

	st.attack("Alice");

	st.takeDamage(50);
	st.beRepaired(20);

	st.guardGate();

	for (int i = 0; i < 10; i++)
		st.attack("Alice");
	st.attack("Alice");

	ScavTrap st2(st);
	st2.attack("Alice");
	return (0);
}