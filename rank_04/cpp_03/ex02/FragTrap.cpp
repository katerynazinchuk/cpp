#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	_hit_points = 100;
	_energy_points = 100;
	_attack_damage = 30;
	std::cout << GREEN << "FragTrap default constructor called"  << RESET << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	_hit_points = 100;
	_energy_points = 100;
	_attack_damage = 30;
	std::cout << GREEN << "FragTrap " << _name << " parametrized constructor called"  << RESET << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
	std::cout << GREEN << "FragTrap " << _name << " copy constructor called"  << RESET << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
	if(this != &other)
	{
		_name = other._name;
		_attack_damage = other._attack_damage;
		_hit_points = other._hit_points;
		_energy_points = other._energy_points;
		std::cout << "FragTrap " << _name << " copy assignment operator called" << std::endl;
	}
	return *this;
}

FragTrap::~FragTrap()
{
	std::cout << CYAN << "FragTrap " << _name << " destructor called" << RESET << std::endl;
}

void FragTrap::attack (const std::string& target)
{
	if(_energy_points > 0 && _hit_points > 0)
	{
		_energy_points--;
		std::cout << "FragTrap " << _name << " attacks " << target << ", causing " << _attack_damage << " points of damage!" << std::endl;
	}
	else
		std::cout << RED << "FragTrap " << _name << " has no energy/health to attack!" << RESET << std::endl;
}

void FragTrap::highFivesGuys()
{
	std::cout << MAGENTA << "FragTrap " << _name << " gave a highfive!" << RESET << std::endl;
}