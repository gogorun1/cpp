#include "Character.hpp"
#include <algorithm> // std::fill

// OCF

Character::Character(std::string const &name) : _name(name), _floor_count(0)
{
	std::fill(_inventory, _inventory + 4, (AMateria *)NULL);
	std::fill(_floor, _floor + FLOOR_SIZE, (AMateria *)NULL);
	// PRINT("Character " << _name << " constructed.");
}

Character::~Character()
{
	cleanup_inventory();
	cleanup_floor();
	// PRINT( "Character " << _name << " destructed.");
}

// Copy constructor
Character::Character(const Character &other) : _name(other._name), _floor_count(0)
{
	std::fill(_inventory, _inventory + 4, (AMateria *)NULL);
	std::fill(_floor, _floor + FLOOR_SIZE, (AMateria *)NULL);

	for (int i = 0; i < 4; ++i)
	{
		if (other._inventory[i])
		{
			_inventory[i] = other._inventory[i]->clone();
		}
	}
	// PRINT("Character " << _name << " copy constructed (deep copy).");
}

// Assign operator
Character &Character::operator=(const Character &other)
{
	if (this != &other)
	{
		cleanup_inventory();
		this->_name = other._name;
		for (int i = 0; i < 4; ++i)
		{
			if (other._inventory[i])
			{
				this->_inventory[i] = other._inventory[i]->clone();
			}
			else
			{
				this->_inventory[i] = NULL;
			}
		}
	}
	// PRINT("Character " << this->_name << " copy assigned (deep copy).");
	return *this;
}

//  Cleaner
void Character::cleanup_inventory()
{
	for (int i = 0; i < 4; ++i)
	{
		PRINT(i);
		if (_inventory[i])
		{
			PRINT(_inventory[i]->getType());
			delete _inventory[i];
			_inventory[i] = NULL;
		}
	}
}

void Character::cleanup_floor()
{
	for (int i = 0; i < _floor_count; ++i)
	{
		if (_floor[i])
		{
			delete _floor[i];
			_floor[i] = NULL;
		}
	}
	_floor_count = 0;
}

// Interface

std::string const &Character::getName() const
{
	return this->_name;
}

void Character::equip(AMateria *m)
{
	if (!m)
		return;

	for (int i = 0; i < 4; ++i)
	{			
		if (m == _inventory[i])
			return ;
		if (!_inventory[i])
		{
			_inventory[i] = m;

			PRINT(_name << " equipped " << m->getType()<< " at slot " << i);
			return;
		}
	}
	PRINT(_name << "'s inventory is full. Cannot equip " << m->getType() << ".");
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx >= 4 || !_inventory[idx])
	{
		PRINT(_name << " tried to unequip non-existent Materia at slot " << idx << ".");
		return;
	}

	if (_floor_count < FLOOR_SIZE)
	{
		_floor[_floor_count++] = _inventory[idx];
		PRINT(_name << " unequipped " << _inventory[idx]->getType() << " at slot " << idx << ". Materia is on the floor.");
	}
	else
	{
		std::cout << "WARNING: Floor is full! Memory leak risk for unequipped Materia!" << std::endl;
	}

	_inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter &target)
{
	if (idx < 0 || idx >= 4 || !_inventory[idx])
	{
		PRINT(_name << " tried to use non-existent Materia at slot " << idx << ".");
		return;
	}
	_inventory[idx]->use(target);
}