# include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
		_templates[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
	for(int i = 0; i < 4; i++)
	{
		if(other._templates[i])
			_templates[i] = other._templates[i]->clone();
		else
			_templates[i] = NULL;
	}
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
	if(this != &other)
	{
		for(int i = 0; i < 4; i++)
		{
			delete this->_templates[i];
			this->_templates[i] = NULL;
		}
		for(int i = 0; i < 4; i++)
		{
			if(other._templates[i])
				this->_templates[i] = other._templates[i]->clone();
			else
				this->_templates[i] = NULL;
		}
	}
	return *this;
}

MateriaSource::~MateriaSource()
{
	std::cout << CYAN << "MateriaSource destructor called" << RESET << std::endl;
	for (int i = 0; i < 4; i++)
		delete _templates[i];
}

void MateriaSource::learnMateria(AMateria* m)
{
	if(!m)
		return;
	for (int i = 0; i < 4; i++)
	{
		if(_templates[i] == NULL)
		{
			_templates[i] = m;
			break;
		}
	}
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
	{
		if (_templates[i] && _templates[i]->getType() == type)
			return _templates[i]->clone();
	}
	return 0;
}
