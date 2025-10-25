#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): _name("Default"), _hitPoints(DEFAULT_HIT_POINTS), _energyPoints(DEFAULT_ENERGY_POINTS), _attackDamage(DEFAULT_ATTACK_DAMAGE)
{
    PRINT("ClapTrap: Default constructor is called");
}

ClapTrap::ClapTrap(std::string Name): _name(Name), _hitPoints(DEFAULT_HIT_POINTS), _energyPoints(DEFAULT_ENERGY_POINTS), _attackDamage(DEFAULT_ATTACK_DAMAGE)
{
    PRINT("ClapTrap: Constructor with parameter is called");
}

ClapTrap::ClapTrap(ClapTrap const &other): _name(other._name), _hitPoints(other._hitPoints), _energyPoints(other._energyPoints), _attackDamage(other._attackDamage)
{
    PRINT("ClapTrap: Copy constructor is called");
}

ClapTrap &ClapTrap::operator=(ClapTrap const &other)
{
    PRINT("ClapTrap: Assign operator is called");
    if (this != &other)
	{
		this->_name = other._name;
		this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
	}
	return *this;
}

ClapTrap::~ClapTrap()
{
    PRINT("ClapTrap: Destructor is called");
}

//getters
std::string ClapTrap::getName() const
{
    return(_name);
}
int ClapTrap::getHitPoints() const
{
    return(_hitPoints);
}
int ClapTrap::getEnergyPoints() const
{
    return(_energyPoints);
}
int ClapTrap::getAttackDamage() const
{
    return(_attackDamage);
}

//function requested
void ClapTrap::attack(const std::string& target)
{
    if (_hitPoints <= 0 || _energyPoints <= 0)
    {
        PRINT("ClapTrap " << _name << " can't do anything");
        return;
    }
    --_energyPoints;
    PRINT("ClapTrap " << _name << " attacks " << target<< ", causing " << _attackDamage << " points of damage!");
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (_hitPoints <= 0)
    {
        PRINT("ClapTrap " << _name << " is dead");
        return;
    }
    _hitPoints -= amount;
    PRINT("health is " << _hitPoints);
    PRINT("ClapTrap " << _name << " takes " << amount << " points of damage!");
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (_hitPoints <= 0 || _energyPoints <= 0)
    {
        PRINT("ClapTrap " << _name << " can't do anything");
        return;
    }
    --_energyPoints;
    _hitPoints += amount;
    PRINT("ClapTrap " << _name << " repairs itself. It regains " << amount << " hit points!");
}