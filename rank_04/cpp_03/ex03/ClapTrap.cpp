#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name(""), _hit_points(10), _energy_points(10), _attack_damage(0)
{
	std::cout << GREEN << "ClapTrap " << _name << " default constructor called" << RESET << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hit_points(10), _energy_points(10), _attack_damage(0)
{
	std::cout << GREEN << "ClapTrap " << _name << " parametrized constructor called" << RESET << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) : _name(other._name), _hit_points(other._hit_points), _energy_points(other._energy_points), _attack_damage(other._attack_damage)
{
	std::cout << GREEN << "ClapTrap " << _name << " copy constructor called"  << RESET << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	if(this != &other)
	{
		_name = other._name;
		_attack_damage = other._attack_damage;
		_hit_points = other._hit_points;
		_energy_points = other._energy_points;
		std::cout << "ClapTrap " << _name << " copy assignment operator called" << std::endl;
	}
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << CYAN << "ClapTrap " << _name << " destructor called" << RESET << std::endl;
}

void ClapTrap::attack (const std::string& target)
{
	if(_energy_points > 0 && _hit_points > 0)
	{
		_energy_points--;
		std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attack_damage << " points of damage!" << std::endl;
	}
	else
		std::cout << RED << "ClapTrap " << _name << " has no energy/health to attack!" << RESET << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if(_hit_points >= amount)
	{
		_hit_points -=amount;
	}
	else
	{
		_hit_points = 0;
	}
	std::cout << RED << "ClapTrap " << _name << " took " << amount << " points of damage!" << RESET << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if(_hit_points > 0 && _energy_points > 0)
	{
		_energy_points --;
		_hit_points += amount;
		std::cout << YELLOW << "ClapTrap " << _name << " repaired itself for " << amount << " hit points!" << RESET << std::endl;
	}
	else
		std::cout << RED << "ClapTrap " << _name << " has no energy/health to repair!" << RESET << std::endl;
}
	