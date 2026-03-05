#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ScavTrap(), FragTrap()
{
	_hit_points = 100;
	_energy_points = 50;
	_attack_damage = 30;
	std::cout << GREEN << "DiamondTrap default constructor called"  << RESET << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name)
{
	_hit_points = 100;
	_energy_points = 50;
	_attack_damage = 30;
	_name = name;
	std::cout << GREEN << "DiamondTrap " << _name << " parametrized constructor called"  << RESET << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) : ClapTrap(other)
{
	std::cout << GREEN << "DiamondTrap " << _name << " copy constructor called"  << RESET << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
	if(this != &other)
	{
		_name = other._name;
		_attack_damage = other._attack_damage;
		_hit_points = other._hit_points;
		_energy_points = other._energy_points;
		std::cout << "DiamondTrap " << _name << " copy assignment operator called" << std::endl;
	}
	return *this;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << CYAN << "DiamondTrap " << _name << " destructor called" << RESET << std::endl;
}

void DiamondTrap::attack (const std::string& target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
	std::cout << MAGENTA << "I am DiamondTrap " << _name << " and ClapTrap " << ClapTrap::_name << RESET << std::endl;
}