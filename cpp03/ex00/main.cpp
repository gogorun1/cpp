#include "ClapTrap.hpp"

int main()
{
    ClapTrap A("A");
    ClapTrap B("B");
    ClapTrap C(A);
    A.attack("B");
    A.beRepaired(2);
    A.takeDamage(3);
}