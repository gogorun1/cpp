#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"
# include "AMateria.hpp"

class Character : public ICharacter
{
private:
    std::string _name;
    AMateria* _inventory[4];
    
    static const int FLOOR_SIZE = 100;
    AMateria* _floor[FLOOR_SIZE];
    int _floor_count;

    void cleanup_inventory();
    void cleanup_floor();

public:
    Character(std::string const & name);
    virtual ~Character();

    // OCF
    Character(const Character& other);
    Character& operator=(const Character& other);

    // ICharacter
    virtual std::string const & getName() const;
    virtual void equip(AMateria* m);
    virtual void unequip(int idx);
    virtual void use(int idx, ICharacter& target);
};

#endif