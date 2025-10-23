#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
private:
    std::string _name;
    int _hitPoints;
    int _energyPoints;
    int _attackDamage;
public:
    ScavTrap();
    ScavTrap(std::string Name);
    ScavTrap(ScavTrap const &other);
    ScavTrap &operator=(ScavTrap const &other);
    ~ScavTrap();
    //getters
    std::string getName() const;
    int getHitPoints() const;
    int getEnergyPoints() const;
    int getAttackDamage() const;
    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
}