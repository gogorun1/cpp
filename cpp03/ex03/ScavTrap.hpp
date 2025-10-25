#ifndef SCAVTRAP_H
#define SCAVTRAP_H

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
protected:
    static const int SCAV_HIT_POINTS = 100;
    static const int SCAV_ENERGY_POINTS = 50;
    static const int SCAV_ATTACK_DAMAGE = 20;

public:
	// OCF
	ScavTrap();
	ScavTrap(std::string Name);
	ScavTrap(ScavTrap const &other);
	ScavTrap &operator=(ScavTrap const &other);
	~ScavTrap();

	// Override messages inherited from parent
	void attack(const std::string &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

	// ScavTrap functions
	void guardGate();
};

#endif