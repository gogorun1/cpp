#include "DiamondTrap.hpp"
#include <iostream>

int main() 
{
    std::cout << "=== Creating DiamondTrap ===" << std::endl;
    DiamondTrap diamond("Sparkle");
    
    std::cout << "\n=== Testing DiamondTrap functionality ===" << std::endl;
    diamond.attack("target");
    diamond.takeDamage(20);
    diamond.beRepaired(10);
    diamond.guardGate();
    diamond.highFivesGuys();
    diamond.whoAmI();
    
    std::cout << "\n=== Testing copy ===" << std::endl;
    DiamondTrap copy(diamond);
    copy.whoAmI();
    
    std::cout << "\n=== End of scope ===" << std::endl;
    return 0;
}