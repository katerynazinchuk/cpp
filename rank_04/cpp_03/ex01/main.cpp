#include "ScavTrap.hpp"

int main()
{
	std::cout << "=== ClapTrap ===" << std::endl;
	ClapTrap ct("Alice");
	ct.attack("Enemy");
	ct.takeDamage(5);
	ct.beRepaired(3);

	std::cout << "\n=== ScavTrap basic ===" << std::endl;
	ScavTrap st("Serena");
	st.attack("Alice");
	st.takeDamage(50);
	st.beRepaired(20);
	st.guardGate();

	std::cout << "\n=== ScavTrap no EP ===" << std::endl;
	for (int i = 0; i < 10; i++)
		st.attack("Alice");
	st.attack("Alice");

	std::cout << "\n=== Copy ===" << std::endl;
	ScavTrap st2(st);
	st2.attack("Alice");

	std::cout << "\n=== Destruction order ===" << std::endl;
	return (0);
}