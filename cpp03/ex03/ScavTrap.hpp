#ifndef SCAVTRAP_H
#define SCAVTRAP_H

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{

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