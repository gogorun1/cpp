#include "ScavTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap()
{
    PRINT("ScavTrap: Default constructor is called");
}

ScavTrap::ScavTrap(std::string Name): ClapTrap(Name)
{
	this->_hitPoints = SCAV_HIT_POINTS;
	this->_energyPoints = SCAV_ENERGY_POINTS;
	this->_attackDamage = SCAV_ATTACK_DAMAGE;
    PRINT("ScavTrap: Constructor with parameter is called");
}

ScavTrap::ScavTrap(ScavTrap const &other): ClapTrap(other._name)
{
	this->_hitPoints = SCAV_HIT_POINTS;
	this->_energyPoints = SCAV_ENERGY_POINTS;
	this->_attackDamage = SCAV_ATTACK_DAMAGE;
    PRINT("ScavTrap: Copy constructor is called");
}

ScavTrap &ScavTrap::operator=(ScavTrap const &other)
{
    PRINT("ScavTrap: Assign operator is called");
    if (this != &other)
	{
		ClapTrap::operator=(other);
	}
	return *this;
}

ScavTrap::~ScavTrap()
{
    PRINT("ScavTrap: Destructor is called");
}

//function requested
void ScavTrap::attack(const std::string& target)
{
    if (_hitPoints <= 0 || _energyPoints <= 0)
    {
        PRINT("ScavTrap " << _name << " can't do anything");
        return;
    }
    --_energyPoints;
    PRINT("ScavTrap " << _name << " attacks " << target<< ", causing " << _attackDamage << " points of damage!");
}

void ScavTrap::takeDamage(unsigned int amount)
{
    if (_hitPoints <= 0)
    {
        PRINT("ScavTrap " << _name << " is dead");
        return;
    }
    _hitPoints -= amount;
    PRINT("ScavTrap " << _name << " takes " << amount << " points of damage!");
}

void ScavTrap::beRepaired(unsigned int amount)
{
    if (_hitPoints <= 0 || _energyPoints <= 0)
    {
        PRINT("ScavTrap " << _name << " can't do anything");
        return;
    }
    --_energyPoints;
    _hitPoints += amount;
    PRINT("ScavTrap " << _name << " repairs itself. It regains " << amount << " hit points!");
}

void ScavTrap::guardGate()
{
    PRINT("ScavTrap " << _name << " is in Gate keeper mode.");
}
