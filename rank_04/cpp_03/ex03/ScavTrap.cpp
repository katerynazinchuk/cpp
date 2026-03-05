#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	_hit_points = 100;
	_energy_points = 50;
	_attack_damage = 20;
	std::cout << GREEN << "ScavTrap default constructor called"  << RESET << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	_hit_points = 100;
	_energy_points = 50;
	_attack_damage = 20;
	std::cout << GREEN << "ScavTrap " << _name << " parametrized constructor called"  << RESET << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
	std::cout << GREEN << "ScavTrap " << _name << " copy constructor called"  << RESET << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
	if(this != &other)
	{
		_name = other._name;
		_attack_damage = other._attack_damage;
		_hit_points = other._hit_points;
		_energy_points = other._energy_points;
		std::cout << "ScavTrap " << _name << " copy assignment operator called" << std::endl;
	}
	return *this;
}

ScavTrap::~ScavTrap()
{
	std::cout << CYAN << "ScavTrap " << _name << " destructor called" << RESET << std::endl;
}

void ScavTrap::attack (const std::string& target)
{
	if(_energy_points > 0 && _hit_points > 0)
	{
		_energy_points--;
		std::cout << "ScavTrap " << _name << " attacks " << target << ", causing " << _attack_damage << " points of damage!" << std::endl;
	}
	else
		std::cout << RED << "ScavTrap " << _name << " has no energy/health to attack!" << RESET << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << MAGENTA << "ScavTrap " << _name << " is now in Gate keeper mode!" << RESET << std::endl;
}