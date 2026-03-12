#include "Character.hpp"

Character::Character(const std::string& name) : _name(name)
{
	for(int i = 0; i < 4; i++)
		_inventory[i] = NULL;
}

Character::Character(const Character& other) : _name(other._name)
{
	for(int i = 0; i < 4; i++)
	{
		if(other._inventory[i])
			_inventory[i] = other._inventory[i]->clone();
		else
			_inventory[i] = NULL;
	}
}

Character& Character::operator=(const Character& other)
{
	if(this != &other)
	{
		_name = other._name;
		for(int i = 0; i < 4; i++)
		{
			delete this->_inventory[i];
			this->_inventory[i] = NULL;
		}
		for(int i = 0; i < 4; i++)
		{
			if(other._inventory[i])
				this->_inventory[i] = other._inventory[i]->clone();
			else
				this->_inventory[i] = NULL;
		}
	}
	return *this;
}

Character::~Character()
{
	std::cout << CYAN << "Character " << _name << " destructor called" << RESET << std::endl;
	for (int i = 0; i < 4; i++)
		delete _inventory[i];
}

std::string const& Character::getName() const
{
	return _name;
}

void Character::equip(AMateria* m)
{
	if(!m)
		return;
	for (int i = 0; i < 4; i++)
	{
		if(_inventory[i] == NULL)
		{
			_inventory[i] = m;
			break;
		}
	}
}

void Character::unequip(int idx)
{
	if(idx >=0 && idx < 4)
		_inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
	if(idx >=0 && idx < 4 && _inventory[idx])
		_inventory[idx]->use(target);
}