#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	ScavTrap A("A");
	FragTrap B("B");
	A.attack("B");
	A.beRepaired(2);
	A.takeDamage(3);
	A.guardGate();
	B.attack("C");
	B.beRepaired(2);
	B.takeDamage(3);
	B.highFivesGuys();
}