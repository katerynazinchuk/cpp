#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main()
{
	std::cout << "=== ClapTrap ===" << std::endl;
	ClapTrap ct("Alice");
	ct.attack("Enemy");
	ct.takeDamage(5);
	ct.beRepaired(3);

	std::cout << "\n=== ScavTrap ===" << std::endl;
	ScavTrap st("Serena");
	st.attack("Alice");
	st.takeDamage(50);
	st.beRepaired(20);
	st.guardGate();

	std::cout << "\n=== FragTrap ===" << std::endl;
	FragTrap ft("Rex");
	ft.attack("Alice");
	ft.takeDamage(30);
	ft.beRepaired(10);
	ft.highFivesGuys();

	std::cout << "\n=== DiamondTrap ===" << std::endl;
	DiamondTrap dt("Diamond");
	dt.whoAmI();
	dt.attack("Enemy");
	dt.takeDamage(50);
	dt.beRepaired(20);
	dt.guardGate();
	dt.highFivesGuys();

	std::cout << "\n=== Destruction order ===" << std::endl;
	return (0);
}