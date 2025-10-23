#ifndef FRAGTRAP_H
#define FRAGTRAP_H

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{

public:
	// OCF
	FragTrap();
	FragTrap(std::string Name);
	FragTrap(FragTrap const &other);
	FragTrap &operator=(FragTrap const &other);
	~FragTrap();

	// Override messages inherited from parent
	void attack(const std::string &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

	// FragTrap functions
	void highFivesGuys(void);
};

#endif