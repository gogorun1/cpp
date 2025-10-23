#include "FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap()
{
    PRINT("FragTrap: Default constructor is called");
}

FragTrap::FragTrap(std::string Name): ClapTrap(Name)
{
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
    PRINT("FragTrap: Constructor with parameter is called");
}

FragTrap::FragTrap(FragTrap const &other): ClapTrap(other._name)
{
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
    PRINT("FragTrap: Copy constructor is called");
}

FragTrap &FragTrap::operator=(FragTrap const &other)
{
    PRINT("FragTrap: Assign operator is called");
    if (this != &other)
	{
		ClapTrap::operator=(other);
	}
	return *this;
}

FragTrap::~FragTrap()
{
    PRINT("FragTrap: Destructor is called");
}

//function requested
void FragTrap::attack(const std::string& target)
{
    if (_hitPoints <= 0 || _energyPoints <= 0)
    {
        PRINT("FragTrap " << _name << " can't do anything");
        return;
    }
    --_energyPoints;
    PRINT("FragTrap " << _name << " attacks " << target<< ", causing " << _attackDamage << " points of damage!");
}

void FragTrap::takeDamage(unsigned int amount)
{
    if (_hitPoints <= 0)
    {
        PRINT("FragTrap " << _name << " is dead");
        return;
    }
    _hitPoints -= amount;
    PRINT("FragTrap " << _name << " takes " << amount << " points of damage!");
}

void FragTrap::beRepaired(unsigned int amount)
{
    if (_hitPoints <= 0 || _energyPoints <= 0)
    {
        PRINT("FragTrap " << _name << " can't do anything");
        return;
    }
    --_energyPoints;
    _hitPoints += amount;
    PRINT("FragTrap " << _name << " repairs itself. It regains " << amount << " hit points!");
}

void FragTrap::highFivesGuys(void)
{
    PRINT("FragTrap " << _name << " wants to HIHG FIVE!");
}
