#include "ScavTrap.hpp"

int main()
{
    ScavTrap A("A");
    ScavTrap B("B");
    ScavTrap C(A);
    A.attack("B");
    A.beRepaired(2);
    A.takeDamage(3);
    A.guardGate();
}