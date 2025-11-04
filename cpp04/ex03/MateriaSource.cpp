#include "MateriaSource.hpp"
#include <algorithm>

//  OCF

MateriaSource::MateriaSource()
{
	std::fill(_templates, _templates + 4, (AMateria *)NULL);
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; ++i)
	{
		if (_templates[i])
		{
			delete _templates[i];
			_templates[i] = NULL;
		}
	}
	// std::cout << "MateriaSource destructed." << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource &other)
{
	std::fill(_templates, _templates + 4, (AMateria *)NULL);
	for (int i = 0; i < 4; ++i)
	{
		if (other._templates[i])
		{
			_templates[i] = other._templates[i]->clone();
		}
	}
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
	if (this != &other)
	{
		for (int i = 0; i < 4; ++i)
		{
			if (_templates[i])
			{
				delete _templates[i];
				_templates[i] = NULL;
			}
		}

		for (int i = 0; i < 4; ++i)
		{
			if (other._templates[i])
			{
				_templates[i] = other._templates[i]->clone();
			}
			else
			{
				_templates[i] = NULL;
			}
		}
	}
	return *this;
}

//  Interface

void MateriaSource::learnMateria(AMateria *m)
{
	if (!m)
		return;

	for (int i = 0; i < 4; ++i)
	{
		if (!_templates[i])
		{
			_templates[i] = m->clone();
			return;
		}
	}
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < 4; ++i)
	{
		if (_templates[i] && _templates[i]->getType() == type)
		{
			return _templates[i]->clone();
		}
	}
	return 0;
}