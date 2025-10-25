#ifndef FRAGTRAP_H
#define FRAGTRAP_H

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
protected:
    static const int FRAG_HIT_POINTS = 100;
    static const int FRAG_ENERGY_POINTS = 100;
    static const int FRAG_ATTACK_DAMAGE = 30;

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