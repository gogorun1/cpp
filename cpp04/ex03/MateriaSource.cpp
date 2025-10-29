#include "MateriaSource.hpp"
#include <algorithm>

// ------------------- 构造/析构/OCF -------------------

MateriaSource::MateriaSource()
{
    // 初始化模板数组为 NULL
    std::fill(_templates, _templates + 4, (AMateria*)NULL);
    // std::cout << "MateriaSource constructed." << std::endl;
}

// 析构函数：清理所有学习到的模板 Materia
MateriaSource::~MateriaSource()
{
    for (int i = 0; i < 4; ++i)
    {
        if (_templates[i])
        {
            delete _templates[i];
            _templates[i] = NULL;
        }
    }
    // std::cout << "MateriaSource destructed." << std::endl;
}

// 拷贝构造函数 (深拷贝)
MateriaSource::MateriaSource(const MateriaSource& other)
{
    std::fill(_templates, _templates + 4, (AMateria*)NULL);
    
    // 深拷贝模板
    for (int i = 0; i < 4; ++i)
    {
        if (other._templates[i])
        {
            // 克隆模板
            _templates[i] = other._templates[i]->clone(); 
        }
    }
    // std::cout << "MateriaSource copy constructed." << std::endl;
}

// 拷贝赋值运算符 (深拷贝)
MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
    if (this != &other)
    {
        // 1. 清理自身的旧模板
        for (int i = 0; i < 4; ++i)
        {
            if (_templates[i])
            {
                delete _templates[i];
                _templates[i] = NULL;
            }
        }

        // 2. 深拷贝新模板
        for (int i = 0; i < 4; ++i)
        {
            if (other._templates[i])
            {
                _templates[i] = other._templates[i]->clone();
            }
            else
            {
                _templates[i] = NULL;
            }
        }
    }
    // std::cout << "MateriaSource copy assigned." << std::endl;
    return *this;
}

// ------------------- 接口实现 -------------------

void MateriaSource::learnMateria(AMateria* m)
{
    if (!m)
        return;

    for (int i = 0; i < 4; ++i)
    {
        if (!_templates[i]) // 找到第一个空槽
        {
            // 存储 Materia 的克隆体，而不是传入的指针本身
            _templates[i] = m->clone(); 
            // std::cout << "MateriaSource learned " << m->getType() << " at slot " << i << "." << std::endl;
            return;
        }
    }
    // std::cout << "MateriaSource templates are full. Cannot learn " << m->getType() << "." << std::endl;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    for (int i = 0; i < 4; ++i)
    {
        if (_templates[i] && _templates[i]->getType() == type)
        {
            // 返回该 Materia 模板的克隆体
            // **多态的关键：调用 Ice/Cure 对象的 clone()**
            return _templates[i]->clone(); 
        }
    }
    
    // std::cout << "Materia of type " << type << " not found in source." << std::endl;
    return 0; // 返回 NULL
}