#include "ClapTrap.hpp"

int main()
{
	std::cout << "=== Basic behavior ===" << std::endl;
	ClapTrap ct("Alice");
	ct.attack("Enemy");
	ct.takeDamage(5);
	ct.beRepaired(3);

	std::cout << "\n=== No HP ===" << std::endl;
	ct.takeDamage(100);
	ct.attack("Enemy");
	ct.beRepaired(5);

	std::cout << "\n=== No EP ===" << std::endl;
	ClapTrap ct2("Bob");
	for (int i = 0; i < 10; i++)
		ct2.attack("Enemy");
	ct2.attack("Enemy");
	ct2.beRepaired(5);

	std::cout << "\n=== Copy ===" << std::endl;
	ClapTrap ct3(ct2);
	ct3.attack("Enemy");

	std::cout << "\n=== Destruction order ===" << std::endl;
	return (0);
}