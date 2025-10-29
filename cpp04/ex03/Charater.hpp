#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"
# include "AMateria.hpp"

class Character : public ICharacter
{
private:
    std::string _name;
    AMateria* _inventory[4];
    
    // 用于防止内存泄漏的关键：存储被丢弃的 Materia
    // 注意：C++98 不支持 std::vector<AMateria*>, 只能用固定大小数组
    static const int FLOOR_SIZE = 100;
    AMateria* _floor[FLOOR_SIZE];
    int _floor_count;

    // 清理库存和地面的私有帮助函数 (在 .cpp 中实现)
    void cleanup_inventory();
    void cleanup_floor();

public:
    Character(std::string const & name);
    virtual ~Character();

    // 必须实现深拷贝 (OCF)
    Character(const Character& other);
    Character& operator=(const Character& other);

    // ICharacter 接口实现
    virtual std::string const & getName() const;
    virtual void equip(AMateria* m);
    virtual void unequip(int idx);
    virtual void use(int idx, ICharacter& target);
};

#endif