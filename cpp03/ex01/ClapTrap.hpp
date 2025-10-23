#ifndef CLAPTRAP_H
#define CLAPTRAP_H

#include <iostream>
#include <string>

#define PRINT(x) std::cout << x << std::endl;

class ClapTrap
{
protected:
    std::string _name;
    int _hitPoints;
    int _energyPoints;
    int _attackDamage;
public:
    ClapTrap();
    ClapTrap(std::string Name);
    ClapTrap(ClapTrap const &other);
    ClapTrap &operator=(ClapTrap const &other);
    ~ClapTrap();
    //getters
    std::string getName() const;
    int getHitPoints() const;
    int getEnergyPoints() const;
    int getAttackDamage() const;
    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
};

#endif
